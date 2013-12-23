/* $Change: 1142016 $ */
//
// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/** 
 * @file			FMediaICameraEventListener.h 
 * @brief			This is the header file for the %ICameraEventListener interface.
 *
 * This header file contains the declarations of the %ICameraEventListener interface.
 */
 
#ifndef _FMEDIA_CAMERAEVENTLISTENER_H_
#define _FMEDIA_CAMERAEVENTLISTENER_H_

// Include
#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaCameraCommon.h"

namespace Osp{ namespace Media{ 

/**
 * @interface	ICameraEventListener
 * @brief		This interface provides a listener that receives events associated with the Camera class.
 * @since	  1.0
 *
 * The %ICameraEventListener interface specifies the methods used to notify the status of the camera and camera events.
 * The camera engine works asynchronously. Therefore, it is important to implement this listener
 * to ensure smooth performance of the camera. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/capturing_still_images.htm">Capturing Still Images</a>.
 */ 
class _EXPORT_MEDIA_ ICameraEventListener :
	public Osp::Base::Runtime::IEventListener
{

public:

	/**
	*       Called when the Camera::SetAutoFocus() method is completed.
	*
	* @since	    	 1.0
	* @param[in]     completeCondition   The condition of auto focus completion @n
	*                                          Set to @c true if it succeeds, @n
	*                                          else @c false.
	* @see           Camera::SetAutoFocus()
	*/
	virtual void OnCameraAutoFocused( bool completeCondition  ) = 0;

	/**
	* Called when the Camera::StartPreview() method is completed. @n
	* Notifies to the application periodically, at the speed of the camera's frame rate, 
	*   once the Camera::StartPreview() method is called, so as to receive the preview data.
	*	
	* @since	    1.0
	*	@param[in]	previewedData			The displayed image data in the viewfinder @n
	*										The previewed data format is same as the format 
	*                                       set by Camera::SetPreviewFormat().
	* @param[in]	r	The cause of the error
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_INVALID_DATA	 ByteBuffer contains invalid data.
	*	@remarks	This method is called only if the @c previewedData flag of
    *	            Camera::StartPreview() is @c true.           
	*	        	This method can be delayed or dropped depending on system performance.
	*	@see		Camera::StartPreview(), Camera::SetPreviewFormat(), Camera::GetPreviewFormat()
	* 
	* The camera rotation can be different according to the physical design.
	* For keeping the compatibility between targets, the application must check the H/W camera rotation.
	* Based on this information, the application can rotate the preview data.
	*
	* The following example demonstrates how to rotate the preview data in the portrait mode.
	*
	* @code 
	// Rotate the preview data to use it.
	int rotation = (int)CAMERA_ROTATION_NONE;
	MediaCapability::GetValue(CAMERA_SECONDARY_ROTATION, rotation);

	ByteBuffer rotatedData;
	rotatedData.Construct(previewedData.GetLimit());
	
	switch((CameraRotation) rotation)
	{
			case CAMERA_ROTATION_90:
					ImageUtil::Rotate(previewedData, rotatedData,
								Dimension(__previewWidth, __previewHeight), IMAGE_ROTATION_90, MEDIA_PIXEL_FORMAT_YUV420P);
					break;

			case CAMERA_ROTATION_180:
					ImageUtil::Rotate(previewedData, rotatedData,
								Dimension(__previewWidth, __previewHeight), IMAGE_ROTATION_180, MEDIA_PIXEL_FORMAT_YUV420P);
					break;
					
			case CAMERA_ROTATION_270:
					ImageUtil::Rotate(previewedData, rotatedData,
								Dimension(__previewWidth, __previewHeight), IMAGE_ROTATION_270, MEDIA_PIXEL_FORMAT_YUV420P);
					break;

			default:
					break;       
	}
	// Normally Camera::SetFlip(CAMERA_FLIP_VERTICAL) is used when using the front camera.
	// Remember that the OverlayRegion(since 2.0) method rotates the visible region internally corresponding to the form's orientation.
	// An application does not need to rotate the visible region explicitly.
	// However, the preview data itself is not rotated. If an application wants to rotate the preview data, the data should be rotated like above.
	// The width and height changes according to the degree of rotation.
	* @endcode 
	*/
	virtual void OnCameraPreviewed ( Osp::Base::ByteBuffer& previewedData, result r ) = 0;

	/**
	*	Called when the Camera::Capture() method is completed.
	*
	* @since	     1.0
	*	@param[in]	 capturedData			The image data captured by the camera @n
	*										The captured data format is the same as the format 
	*                                       set by Camera::SetCaptureFormat().
	* @param[in]	 r	The cause of the error	
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_INVALID_DATA	 ByteBuffer contains invalid data.
	*	@see		Camera::Capture(), Camera::SetCaptureFormat(), Camera::GetCaptureFormat()
	*/
	virtual void OnCameraCaptured ( Osp::Base::ByteBuffer& capturedData, result r ) = 0;

	/**
	*	Called when an error occurs in %Camera.
	*	
	* @since	    	 1.0
	* @compatibility This method has compatibility issues with bada API versions 
	* @b prior @b to @b 2.0. @n 
	*   						 For more information, see @ref CompMediaICameraEventListenerOnCameraErrorOccurred "here". 	
	*	@param[in]	r		A camera error @n
	*						This is one of the ::CameraErrorReason values. 
	*	@remarks			The ::CAMERA_ERROR_DEVICE_FAILED error occurs when the camera device 
	*                       has a problem, such as damaged shape or hardware malfunction.
	*						The ::CAMERA_ERROR_DEVICE_INTERRUPTED error occurs when the camera 
	*                       device has been interrupted by other request, such as an incoming 
	*                       video telephony call.
	*						In this method, the application calls the Camera::PowerOff() 
	*                     method to reset the camera device. 
	*	@see		CameraErrorReason
	*/
	virtual void OnCameraErrorOccurred( CameraErrorReason r ) = 0;

	/**
	* @page  		CompMediaICameraEventListenerOnCameraErrorOccurred Compatibility 
	*         	for OnCameraErrorOccurred()
	* @section 	CompMediaICameraEventListenerOnCameraErrorOccurredPageIssueSection Issues
	*           Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* 
	* 		-# The camera device is not preempted when a higher priority application such 
	*          as video telephony requests it. 
	*       
	* @section CompMediaICameraEventListenerOnCameraErrorOccurredPageResolutionSection Resolutions
	* 		 The issue mentioned above is resolved in bada API version 2.0 as follows: @n
	* 		-# The camera device is immediately preempted by higher priority application's request,
    *   	and ::CAMERA_ERROR_DEVICE_INTERRUPTED is given as an input to this method.
	*/
	

};

};}; // Osp::Media

#endif

