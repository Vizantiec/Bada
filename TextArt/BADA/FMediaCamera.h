/* $Change: 1198808 $ */
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
 * @file			FMediaCamera.h
 * @brief			This is the header file for the %Camera class.
 *
 * This header file contains the declarations of the %Camera class.
 */

#ifndef _FMEDIA_CAMERA_H_
#define _FMEDIA_CAMERA_H_

//include
#include <FBase.h>
#include <FGraphics.h>
#include "FMediaConfig.h"
#include "FMediaCameraCommon.h"
#include "FMediaICameraEventListener.h"

namespace Osp{ namespace Media{

class __CameraEvent;
class ICameraPi;
class ICameraCapabilityPi;
class __CameraConfiguration;

/**
 * @class	Camera
 * @brief	This class controls the camera device.
 * @since	1.0
 *
 *
 * The %Camera class controls the camera device.
 * 
 * The supported properties are device-dependent. The list of the properties available can be retrieved using the methods of %Camera and %MediaCapability classes.
 * All the other methods, except SetAutoFocus(), StartPreview(), and Capture() work synchronously.
 * The previewed or captured data are passed through ICameraEventListener. 
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/capturing_still_images.htm">Capturing Still Images</a>.
 *
 * The following example demonstrates how to use the %Camera class.
 *
 *
 * @code
 * #include <FBase.h>
 * #include <FMedia.h>
 * #include <FUi.h>
 *
 * using namespace Osp::Media;
 *
 * class MyCameraListener
 * 	: public ICameraEventListener
 * {
 *
 * 	public:
 * 		void OnCameraAutoFocused(bool completeCondition);
 * 		void OnCameraPreviewed( Osp::Base::ByteBuffer& previewedData, result r) ;
 * 		void OnCameraCaptured( Osp::Base::ByteBuffer& capturedData, result r);
 * 		void OnCameraErrorOccurred(CameraErrorReason r );
 * };
 *
 * static 	MyCameraListener* pListener = null;
 *
 * void MyCameraListener::OnCameraAutoFocused(bool completeCondition)
 * {
 * 	//Insert your code to operate after the auto focusing is completed.
 * }
 *
 * void MyCameraListener::OnCameraPreviewed( Osp::Base::ByteBuffer& previewedData, result r)
 * {
 * 	//Insert your code to operate while the previewed data is retrieved periodically.
 * }
 *
 * void MyCameraListener::OnCameraCaptured( Osp::Base::ByteBuffer& capturedData, result r)
 * {
 * 	//Insert your code to operate after the captured data is delivered.
 * }
 *
 * void MyCameraListener::OnCameraErrorOccurred(CameraErrorReason r )
 * {
 * 	//Insert your code to operate after the error occurred.
 * }
 *
 * result TestPreviewing(void)
 * {
 * 	result 	r 		= E_SUCCESS;
 *
 *	Camera* pPrimaryCamera = null;
 *	Osp::Ui::Controls::OverlayRegion * pOverlayRegion = null;
 *	Osp::Ui::Controls::Form* pCameraForm = null;
 *	Osp::Graphics::BufferInfo bufferInfo;
 *	Osp::Graphics::Rectangle rect(0, 0, 320, 240);
 *	bool modified = false;
 *	bool suitable = false;
 *
 *  // Initialize pCameraForm
 *  // ...
 *
 * 	pPrimaryCamera = new Camera();
 * 	pListener = new MyCameraListener;
 *
 * 	r = pPrimaryCamera->Construct(*pListener, CAMERA_PRIMARY);
 * 	if (IsFailed(r)) { goto CATCH; }
 *
 * 	r = pPrimaryCamera->PowerOn();
 * 	if (IsFailed(r)) { goto CATCH; }
 *
 *	suitable = Osp::Ui::Controls::OverlayRegion::EvaluateBounds(Osp::Ui::Controls::OVERLAY_REGION_EVALUATION_OPTION_LESS_THAN, rect, modified );
 *	if (!suitable)
 *	{
 *		r = GetLastResult();
 *		goto CATCH;	
 *	}
 *
 *	pOverlayRegion = pCameraForm->GetOverlayRegionN(rect, Osp::Ui::Controls::OVERLAY_REGION_TYPE_PRIMARY_CAMERA);
 *    	if (!pOverlayRegion)
 *	{
 *		r = GetLastResult();
 *		goto CATCH;	
 *	}
 *
 *	r = pOverlayRegion->GetBackgroundBufferInfo(bufferInfo);
 * 	if (IsFailed(r)) { goto CATCH; }
 *
 * 	r = pPrimaryCamera->StartPreview(&bufferInfo, true);
 * 	if (IsFailed(r)) { goto CATCH; }
 *
 * 	return r;
 *
 * 	CATCH:
 * 		if ( pPrimaryCamera )
 * 			delete pPrimaryCamera;
 *		if ( pListener )
 * 			delete pListener;
 *		if ( pOverlayRegion )
 * 			delete pOverlayRegion;
 *
 * 		return r;
 * }
 * @endcode
 *
 *
 */
 class _EXPORT_MEDIA_ Camera :
	public Osp::Base::Object
{

// Lifecycle

public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 * @remarks	 	After creating an instance of this class, the Construct() method must be called explicitly to 
	 * initialize this instance.
	 * @see			Construct()
	 */
	Camera(void);

	/**
	 * This is the destructor for this class. @n
	 * All allocated resources are deallocated by this method. This method should be called in the same thread 
	 * where the Construct() method is called.
	 *
	 * @since		1.0
	 * @see			Construct()
	 */
	virtual ~Camera(void);


// Operation
public:

	/**
	* Initializes this instance of Camera with the specified parameters. @n
	* This method creates an instance of Camera in the subsystem. Only one instance is created at a given time.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	listener				An event listener instance
	* @param[in]	camSel					The Camera to be powered on
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_DEVICE_BUSY			The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE	The device is unavailable.
	*/
	result Construct( const ICameraEventListener& listener, CameraSelection camSel = CAMERA_PRIMARY);

	/**
	* Powers the camera on.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_DEVICE_BUSY			The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE	The device is unavailable.
	* @exception	E_DEVICE_FAILED			The device operation has failed.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The reserved configurations are set in this method.
	* @see			PowerOff()
	*/
	result PowerOn(void);

	/**
	* Powers the camera off.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_DEVICE_BUSY			The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE	The device is unavailable.
	* @exception	E_DEVICE_FAILED			The device operation has failed.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @see			PowerOn()
	*/
	result PowerOff(void);

	/**
	* Checks whether the camera is powered on.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	CAMERA
	* @return		@c true if the camera is powered on, @n
	*				else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			PowerOn(), PowerOff()
	*/
	bool IsPoweredOn(void) const;

	/**
	* Starts displaying the preview image on the camera device. @n
	* If the value of @c pBufferInfo is @c null, no preview image is displayed. In this case, the application can 
	* draw the preview image with the data passed on by the ICameraEventListener::OnCameraPreviewed() method.
	*
	* If the value of @c previewedData is @c true, the previewed image data is passed to the 
	* ICameraEventListener::OnCameraPreviewed() method periodically based on the frame-rate, otherwise the 
	* callback is not invoked. The default value of @c previewedData is @c false.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		An error code
	* @param[in]	pBufferInfo				The buffer information for the camera preview display
	* @param[in]	previewedData			Set to @c true if the previewed data is delivered to the callback method, @n
	*										else @false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_DEVICE_BUSY			The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE	The device is unavailable.
	* @exception	E_DEVICE_FAILED			The device operation has failed.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The overlay region retrieved by the buffer information should be the topmost window when this method is 
	*				called.
	* @remarks		The ICameraEventListener::OnCameraPreviewed() method can be delayed or dropped depending on 
	*				the system's performance. For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>. 

	* @see			StopPreview(), ICameraEventListener::OnCameraPreviewed()
	*/
	result StartPreview(const Osp::Graphics::BufferInfo* pBufferInfo, bool previewedData=false );

	/**
	* Stops displaying the preview image on the camera device.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_DEVICE_BUSY			The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE	The device is unavailable.
	* @exception	E_DEVICE_FAILED			The device operation has failed.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks 		For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>. 
	* @see			StartPreview()
	*/
	result StopPreview(void);

	/**
	* Captures the current image data from the camera sensor. @n
	* After capturing the image, the camera's state changes to ::CAMERA_STATE_CAPTURED. @n 
	* The camera's preview should be restarted by calling the StartPreview() method. @n
	* The captured image is passed through ICameraEventListener::OnCameraCaptured().
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		An error code
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION     This operation is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks 		For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>.
	* @see			ICameraEventListener::OnCameraCaptured()
	*/
	result Capture(void);

	/**
	* Gets the state of the camera in CameraState.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return	  	The current state of the camera
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			StartPreview(), StopPreview(), SetAutoFocus(), Capture()
	*/
	CameraState GetState(void) const;

	/**
	* Sets the brightness level of the camera input data.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		An error code
	* @param[in]	brightness					The brightness level to set @n
	*											The range of this parameter is from @c 0 to @c 9.
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_RANGE				The specified @c brightness is out of range.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION     This operation is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		The default brightness level is @c 5. @n
	*				The device's supported range for the brightness level is from @c 0 to @c 9. @n
	*				This method works correctly when PowerOn() is executed.
	*				For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>. 
	* @see			GetBrightness()
	*/
	result SetBrightness(int brightness);

	/**
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this method.
	*
	* 	Gets the brightness level of a camera input data.
	*
	* @since			1.0
	*	@privlevel	NORMAL
	*	@privgroup  CAMERA
	*	@return		  The current brightness level @n
	*				      The returned value ranges from @c 0 to @c 9
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of the camera.	
	*	@exception	E_OUT_OF_MEMORY					The memory is insufficient.
	*	@exception	E_PRIVILEGE_DENIED				The application does not have the privilege to call this method.
	*	@remarks		The specific error code can be accessed using the GetLastResult() method. @n
	*				The device's supported range for the brightness level is from @c 0 to @c 9. @n		
	*	@see		SetBrightness()
	*/
	int GetBrightenss(void) const;

	/**
	* Gets the brightness level of the camera input data.
	*
	* @since		1.2
	* @privlevel	NORMAL
	* @privgroup 	CAMERA
	* @return		The current brightness level @n
	*				The returned value ranges from @c 0 to @c 9.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.	
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	*				The device's supported range for the brightness level is from @c 0 to @c 9. @n
	* @see			SetBrightness()
	*/
	int GetBrightness(void) const;

	/**
	* Sets the contrast level of the Camera input data.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return	  	An error code
	* @param[in]	contrast					The contrast level to set @n
	*											The range of this parameter is from @c 0 to @c 9.
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_RANGE				The specified contrast is out of range.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION     This operation is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		The default contrast level is @c 5. @n
	*				The device's supported range for the contrast level is from @c 0 to @c 9. @n
	*				This method works correctly when PowerOn() is executed.
	*				For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>. 
	* @see			GetContrast()
	*/
	result SetContrast(int contrast);

	/**
	* Gets the contrast level of the camera input data.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		The current contrast level @n
	*				The returned value ranges from @c 0 to @c 9.	
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	*				The device's supported range for the contrast level is from @c 0 to @c 9.
	* @see			SetContrast()
	*/
	int GetContrast(void) const;

	/**
	* Increases the zoom level of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup 	CAMERA
	* @return		An error code
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION     This operation is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		This method returns E_UNSUPPORTED_OPERATION in the Emulator. 
	*				If CameraZoomType supports only ::CAMERA_ZOOM_TYPE_SMART, the zoom ratio can differ according 
	*				to the preview, capture, and recording resolutions.
	*				The supported zoom types can be obtained by using the 
	*				MediaCapability::GetValueN(CAMERA_PRIMARY_ZOOM_TYPE) method.
    *  				For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>.	
	* @see			ZoomOut(),GetZoomLevel(),GetMaxZoomLevel()
	*/
	result ZoomIn(void);

	/**
	* Decreases the zoom level of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup 	CAMERA
	* @return		An error code
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION     This operation is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		This method returns E_UNSUPPORTED_OPERATION in the Emulator.
	*				If CameraZoomType supports only ::CAMERA_ZOOM_TYPE_SMART, zoom ratio can differ according to
	*				the preview, capture, and recording resolutions.
	*				The supported zoom types can be obtained by using the 
	*				MediaCapability::GetValueN(CAMERA_PRIMARY_ZOOM_TYPE) method.
	* 				For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>.
	* @see			ZoomIn(),GetZoomLevel(),GetMaxZoomLevel()
	*/
	result ZoomOut(void);

	/**
	* Gets the zoom level of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup 	CAMERA
	* @return		The current zoom level
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @remarks		The zoom level is different for each camera device.
	* @remarks		This method throws E_UNSUPPORTED_OPERATION in the Emulator.
	* @see			ZoomIn(), ZoomOut(),GetMaxZoomLevel()
	*/
	int GetZoomLevel(void) const;

	/**
	* Gets the maximum zoom level supported by this Camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup 	CAMERA
	* @return		The maximum zoom level
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @remarks		The zoom level is different for each camera device.
	* @remarks		This method returns E_UNSUPPORTED_OPERATION in the Emulator. @n
	*				This method works correctly when PowerOn() is executed.
	* @see			ZoomIn(), ZoomOut(), GetZoomLevel()
	*/
	int GetMaxZoomLevel (void) const;

	/**
	* Changes the current resolution of the preview.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup 	CAMERA
	* @return		An error code
	* @param[in]	resolution     				The preview resolution @n
	*							   				It should be one of the listed dimensions that are extracted using GetSupportedPreviewResolutionListN().
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_RANGE				The position or size is out of range.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		This method works in the ::CAMERA_STATE_INITIALIZED state.
	*				For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>. 
	* @see			GetPreviewResolution()
	*/
      result SetPreviewResolution(const Osp::Graphics::Dimension& resolution);

	/**
	* Retrieves the current resolution of the preview.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup 	CAMERA
	* @return		The current preview resolution
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetPreviewResolution()
	*/
	Osp::Graphics::Dimension GetPreviewResolution(void) const;

	/**
	* Retrieves the supported preview resolution list of the Camera class. @n
	* Each item in the returned list contains a pointer of Osp::Graphics::Dimension value.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	CAMERA
	* @return       A list of dimensions that represent the preview resolutions supported by the Camera class,  @n
    *				else @c null if no preview resolution is supported or an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remark		The specific error code can be accessed using the GetLastResult() method. @n
	*				The return value and each item in the list must be deleted by the caller. @n
	*				This method works correctly when Camera::PowerOn() is executed.
	* @see			SetPreviewResolution(), GetPreviewResolution()
	*/
	Osp::Base::Collection::IList* GetSupportedPreviewResolutionListN(void) const;


	/**
	* Sets the capturing resolution of the camera. @n
	* Initially, the default resolution is set using the internal configuration.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup 	CAMERA
	* @return		An error code
	* @param[in]	resolution					The display resolution @n
	*							    			The display resolution should be one of the values extracted using GetSupportedCaptureResolutionListN().
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception	E_OUT_OF_RANGE				The specified resolution is out of range.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION     This operation is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks			For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>. 
	* @see			GetCaptureResolution(), GetSupportedCaptureResolutionListN()
	*/
	result SetCaptureResolution(const Osp::Graphics::Dimension& resolution);

	/**
	* Gets the resolution for capturing the data of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		The current resolution for capturing the data of the camera
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetCaptureResolution(),GetSupportedCaptureResolutionListN()
	*/
	Osp::Graphics::Dimension GetCaptureResolution(void) const;

	/**
	* Gets a list of the capturing resolutions supported by the Camera class. @n
	* Each item of the list has a pointer of the Osp::Graphics::Dimension value.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		A list of the capture resolutions supported by the Camera class @n
	*				else @c null if no capture resolution is supported or an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remark		The specific error code can be accessed using the GetLastResult() method. @n
	*				The return value and each item in the list must be deleted by the caller. @n
	*				This method works correctly when PowerOn() is executed.
	* @see			SetCaptureResolution(), GetCaptureResolution()
	*/
	Osp::Base::Collection::IList* GetSupportedCaptureResolutionListN(void) const;

	/**
	* Sets the effect for the input data of the camera.
	*
	* @since		1.0
	* @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	*				 For more information, see @ref CompMediaCameraSetEffect "here". 	
	* @privlevel	NORMAL
	* @privgroup 	CAMERA
	* @return		An error code
	* @param[in]	effect						The effect for the input data of the camera
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_INVALID_ARG				The specified input parameter is invalid.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION     This operation is not supported.
	* @exception	E_UNSUPPORTED_TYPE 			The effect type is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		The default effect is ::CAMERA_EFFECT_NONE. 
	*				This method returns E_UNSUPPORTED_OPERATION in the Emulator.
	*				This method works correctly when PowerOn() is executed.
	*				For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>. 
	* @see			GetEffect()
	*/
	result SetEffect(CameraEffect effect);

	/**
	* @page  	CompMediaCameraSetEffect Compatibility for SetEffect()
	* @section 	CompMediaCameraSetEffectPageIssueSection Issues
	*           Implementation of this method in bada API versions prior to 1.1 has the following issue: @n 
	* -# If a specific effect type is not supported, E_UNSUPPORTED_TYPE must be thrown. But E_UNSUPPORTED_OPERATION is thrown instead.
	*       
	*
	* @section 	CompMediaCameraSetEffectPageResolutionSection Resolutions
	*  The issue mentioned above is resolved in bada API version 1.1.
	*/

	/**
	* Gets the effect for the input data of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		The effect for the input data of the camera
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetEffect()
	*/
	CameraEffect GetEffect(void) const;

	/**
	* Enables or disables the camera's flash.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		An error code
	* @param[in]	flashOn						Set to @c true to switch on the flash light, @n
	*											else @c false
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_UNSUPPORTED_OPERATION     This operation is not supported.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		The flash is switched on when the camera captures a picture. If the value of @c flashOn is
	*				set to @c true,	this method returns E_UNSUPPORTED_OPERATION in the Emulator.
	*				For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>. 
	* @see			IsFlashOn()
	*/
	result SetFlash(bool flashOn);

	/**
	* Checks whether the camera's flash is switched on.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup 	CAMERA
	* @return		@c true if the flash light is on, @n
	*				else @c false
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetFlash()
	*/
	bool IsFlashOn(void) const;

	/**
	* Sets the exposure level of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		An error code
	* @param[in]	exposure					The camera exposure level @n
	*											The range of this parameter is from @c 0 to @c 9.
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_RANGE				The specified exposure level is out of range.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION     This operation is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		The default exposure level is @c 5.
	*				The supported range for exposure level is from @c 0 to @c 9. 
	*				This method returns E_UNSUPPORTED_OPERATION in the Emulator. 
	*				This method works correctly when PowerOn() is executed.
	*				For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>. 
	* @see			GetExposure()
	*/
	result SetExposure(int exposure);

	/**
	* Gets the exposure level of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		An integer value representing the exposure level of the camera @n
	*				The returned value ranges from @c 0 to @c 9.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	*				The supported range for exposure level is from @c 0 to @c 9.
	* @see			SetExposure()
	*/
	int GetExposure(void) const;

	/**
	* Sets the white balance level of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		An error code
	* @param[in]	whiteBalance				The camera white balance level
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_INVALID_ARG				The specified input parameter is invalid.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION     This operation is not supported.
	* @exception	E_UNSUPPORTED_TYPE 			The @c whiteBalance type is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		The default white balance is ::CAMERA_WHITE_BALANCE_AUTO.
	*				This method returns E_UNSUPPORTED_OPERATION in the Emulator.
	*				This method works correctly when PowerOn() is executed.
	*				For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>. 
	* @see			GetWhiteBalance()
	*/
	result SetWhiteBalance(CameraWhiteBalance whiteBalance);

	/**
	* Gets the white balance level of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		The white balance level of the camera
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetWhiteBalance()
	*/
	CameraWhiteBalance GetWhiteBalance(void) const;

	/**
	* Sets the capturing quality of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		An error code
	* @param[in]	quality						The camera's quality level
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_INVALID_ARG				The specified @c quality is not supported.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		The default quality is ::CAMERA_QUALITY_NORMAL.
	*				This method works correctly when PowerOn() is executed.
	*				For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>.
	* @see			GetQuality()
	*/
	result SetQuality(CameraQuality quality);

	/**
	* Gets the capturing quality of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		The Camera quality level
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetQuality()
	*/
	CameraQuality GetQuality(void) const;

	/**
	* Enables or disables the auto focus mode of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		An error code
	* @param[in]	autoFocus					Set to @c true to enable auto focus callback, @n
	*											else @c false
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION     This operation is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		If @c autoFocus is set to @c false, the ICameraEventListener::OnCameraAutoFocused() method is not called.
	*				This method throws E_UNSUPPORTED_OPERATION in the Emulator.
	* 		 		For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>.
	* @see			ICameraEventListener::OnCameraAutoFocused()
	*/
	result SetAutoFocus(bool autoFocus);

	/**
	* Sets the capturing format of the camera. @n
	* Initially, the default format is set using the internal configuration.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	CAMERA
	* @return		An error code
	* @param[in]	format						The camera's capture format @n
	*											It should be one of the pixel formats extracted using GetSupportedCaptureFormatListN().
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception	E_UNSUPPORTED_FORMAT		The specified format is not supported.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION     This operation is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		This method works correctly when PowerOn() is executed.
	* @see			GetCaptureFormat(), GetSupportedCaptureFormatListN()
	*/
	result SetCaptureFormat(const Osp::Graphics::PixelFormat format );

	/**
	* Gets the capturing format of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		The capturing format of the camera
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetCaptureFormat(), GetSupportedCaptureFormatListN()
	*/
	Osp::Graphics::PixelFormat GetCaptureFormat(void) const;

	/**
	* Gets the supported capturing format list for the Camera class. @n
	* Each list item has a Osp::Graphics::PixelFormat value.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	CAMERA
	* @return		A list of the formats supported by the Camera class, @n
	*				else @c null if no capture format is supported or an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remark		The specific error code can be accessed using the GetLastResult() method. @n
	*				The return value must be deleted. @n
	*				This method works correctly when PowerOn() is executed.
	* @see			SetCaptureFormat(), GetCaptureFormat()
	*/
	Osp::Base::Collection::IListT<Osp::Graphics::PixelFormat>* GetSupportedCaptureFormatListN(void) const;

	/**
	* Sets the preview format of the camera. @n
	* Initially, the default format is set using the internal configuration.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		An error code
	* @param[in]	format						The camera's preview format @n
	*											It should be one of the pixel formats extracted using GetSupportedPreviewFormatListN().
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception	E_UNSUPPORTED_FORMAT		The specified format is not supported.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION     This operation is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		This method works in ::CAMERA_STATE_INITIALIZED state.
	*				For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>.
	* @see			GetPreviewFormat(), GetSupportedPreviewFormatListN()
	*/
	result SetPreviewFormat(const Osp::Graphics::PixelFormat format );

	/**
	* Gets the preview format of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	CAMERA
	* @return		The preview format of the camera
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetPreviewFormat(), GetSupportedPreviewFormatListN()
	*/
	Osp::Graphics::PixelFormat GetPreviewFormat(void) const;

	/**
	* Gets the supported preview format list for the Camera class. @n
	* Each list item has a Osp::Graphics::PixelFormat value.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	CAMERA
	* @return		A list of the preview format supported by the Camera class, @n
	*				else @c null if no preview format is supported or an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remark		The specific error code can be accessed using the GetLastResult() method. @n
	*				The return value must be deleted. @n
	*				This method works correctly when PowerOn() is executed.
	* @see			SetPreviewFormat(), GetPreviewFormat()
	*/
	Osp::Base::Collection::IListT<Osp::Graphics::PixelFormat>* GetSupportedPreviewFormatListN(void) const;


	/**
	* Sets the ISO level of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup 	CAMERA
	* @return		An error code
	* @param[in]	isoLevel					The camera's ISO level @n
	*											The default ISO level is set from the internal configuration.
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_RANGE				The specified ISO level is out of range.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	* @exception	E_UNSUPPORTED_TYPE 			The specified @c isoLevel is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		In some devices this method works in the ::CAMERA_STATE_PREVIEW state.
	*				This method throws E_UNSUPPORTED_OPERATION in the Emulator.
	*				For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>. 
	* @see			GetIsoLevel()
	*/
	result SetIsoLevel(CameraIsoLevel isoLevel);

	/**
	* Gets the ISO level of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		The ISO level of the camera
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetIsoLevel()
	*/
	CameraIsoLevel GetIsoLevel(void) const;

	/**
	* Sets the preview frame rate of the camera. @n
	* Initially, the default frame rate is set using the internal configuration.
	*
	* @since		1.0
	* @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*				 For more information, see @ref CompMediaCameraSetPreviewFrameRate "here". 	
	* @privlevel	NORMAL
	* @privgroup	CAMERA
	* @return		An error code
	* @param[in]	fps							The frame rate per second
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_RANGE				The specified @c fps is out of range on this device.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_DEVICE_UNAVAILABLE		The device is unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		This method works in ::CAMERA_STATE_INITIALIZED state.
	*				For more information on the relationship between this method and the PowerOn() method, and the
	* 				state transition caused by this method, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/launching_camera.htm
">Launching the Camera</a>. 
	* @see			GetPreviewFrameRate(), GetSupportedPreviewFrameRateListN(), FRAME_RATE_AUTO
	*/
	result SetPreviewFrameRate(int fps);

	/**
	* @page  	CompMediaCameraSetPreviewFrameRate Compatibility for SetPreviewFrameRate()
	* @section 	CompMediaCameraSetPreviewFrameRatePageIssueSection Issues
	* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* 
	* -# Even though the application sets the Frames Per Second (FPS) value to @c 5 FPS or @c 15 FPS, for some models
	*	 the secondary camera works with @c 7 FPS.
	*
	* @section CompMediaCameraSetPreviewFrameRatePageResolutionSection Resolutions
	* The issue mentioned above is resolved in bada API version 2.0.
	*/

	/**
	* Retrieves the frame rate of the camera.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		The frame rate of the camera @n
	* 				If the frame rate is not set using SetPreviewFrameRate(), the system-dependent default frame rate is returned.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of the camera.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetPreviewFrameRate(), GetSupportedPreviewFrameRateListN()
	*/
	int GetPreviewFrameRate(void) const;

	/**
	* Gets the supported preview frame rate list for the Camera class. @n
	* Each list item has an integer value.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		A list of the preview frame rate supported by the Camera class, @n
	*				else @c null if no frame rate is supported or an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remark		The specific error code can be accessed using the GetLastResult() method. @n
	*				The return value must be deleted by the caller. @n
	*				This method works correctly when PowerOn() is executed. @n
	*				This method returns fps list that can be supported by all resolutions.
	* @see			SetPreviewFrameRate(), GetPreviewFrameRate(), FRAME_RATE_AUTO
	* @see			GetSupportedPreviewFrameRateListN(const Osp::Graphics::Dimension& dim) const
	*/
	Osp::Base::Collection::IListT<int>* GetSupportedPreviewFrameRateListN(void) const;

	/**
	* Gets the supported preview frame rate list of the input resolution of the Camera class. @n
	* Each item of the list has an integer value.
	*
	* @since		2.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		A list of the preview frame rate of the input preview resolution, @n
	*				else @c null if no frame rate is supported or an exception occurs 
	* @param[in]	dim						The preview resolution of the camera 
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_INVALID_ARG			The specified input resolution is invalid.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remark		The specific error code can be accessed using the GetLastResult() method. @n
	*				The return value must be deleted by the caller. @n
	*				This method works correctly when PowerOn() is executed.
	* @see			SetPreviewFrameRate(), GetPreviewFrameRate()
	* @see			GetSupportedPreviewFrameRateListN(void) const
	*/
	Osp::Base::Collection::IListT<int>* GetSupportedPreviewFrameRateListN(const Osp::Graphics::Dimension& dim) const;

	/**
	* Sets the orientation value in the Exchangeable Image File Format (EXIF) field of the captured data.
	*
	* @since		1.2
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		The E_SUCCESS exception, @n
	*				else the appropriate exception code if the value is not successfully set
	* @param[in]  	orientation					The orientation value to set in EXIF
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_RANGE				The input value is out of range.
	* @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	* @exception	E_SYSTEM					A system error has occurred.
	* @remarks		The default value of orientation is CAMERA_EXIF_ORIENTATION_TOP_LEFT. @n
	*				This method works correctly when PowerOn() is executed. The orientation value set by this method can be obtained using the
	*				Osp::Content::ImageData::GetOrientation() method after writing the captured data to a file.
	*/
	result SetExifOrientation(CameraExifOrientation orientation);

	/**
	* Sets the GPS coordinates in the Exchangeable Image File Format (EXIF) field for the captured data.
	*
	* @since 		1.2
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		The E_SUCCESS exception, @n
	*				else the appropriate exception code if the value is not successfully set
	* @param[in]	latitude					The latitude value to be set in EXIF @n
	*											The valid range is [-90.0, 90.0].
	* @param[in]	longitude					The longitude value to be set in EXIF @n
	*											The valid range is [-180.0, 180.0]
	* @param[in]	altitude					The altitude value to be set in EXIF
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_RANGE				The input value is out of range.
	* @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	* @exception	E_SYSTEM					A system error has occurred.
	* @remarks		This method sets the GPS coordinates and enables entering the coordinates into the Exchangeable Image File Format (EXIF).
	* @remarks		By default, the GPS coordinates are not entered in JPEG's EXIF.
	* @remarks		The GPS coordinates that are set using this method are entered in every call to the
	*				Capture() method, until DisableExifGpsCoordinates() is called or this instance is destroyed. @n
	*				This method works correctly when PowerOn() is executed. @n
	*				The values set by this method can result in an error as compared to the values stored in the Exchangeable Image File Format (EXIF) field.
	* @see			DisableExifGpsCoordinates()
	*/
	result SetExifGpsCoordinates(double latitude, double longitude, float altitude);

	/**
	* Disables the insertion of the GPS coordinates in the Exchangeable Image File Format (EXIF) field for the captured data.
	*
	* @since 		1.2
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		The E_SUCCESS exception, @n
	*				else the appropriate exception code if the value is not successfully set
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_RANGE				The input value is out of range.
	* @exception	E_UNSUPPORTED_OPERATION     This operation is not supported.
	* @exception	E_SYSTEM					A system error has occurred.
	* @see 			SetExifGpsCoordinates()
	*/
	result DisableExifGpsCoordinates(void);
	
	/**
	* Sets the flip type for the previewed and captured data.
	*
	* @since 		2.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		An error code
	* @param[in]	flip						The camera flip type
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of this instance.
	* @exception	E_INVALID_ARG				The input value is out of range.
	* @exception	E_UNSUPPORTED_OPERATION     This operation is not supported.
	* @exception	E_UNSUPPORTED_TYPE 			The specified flip type is not supported.
	* @exception	E_SYSTEM					A system error has occurred.
	* @remarks		This method works in the ::CAMERA_STATE_INITIALIZED state.
	* @remarks		Finally the last specified type is applied even with the several types applicable.
	* @see 			GetFlip()
	*/
	result SetFlip(CameraFlipType flip);
	
	/**
	* Gets the flip type for the previewed and captured data.
	*
	* @since 		2.0
	* @privlevel	NORMAL
	* @privgroup  	CAMERA
	* @return		The Camera flip type
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @see 		SetFlip()
	*/
	CameraFlipType GetFlip(void) const;
	
	/**
	 * This value can be used to set the preview frame rate by using the SetPreviewFrameRate() method. @n
	 * If the preview frame rate is set using this value, the frame rate during the preview is automatically adjusted as per the light condition.
	 * 
	 * @since 1.0
	 */
	static const int FRAME_RATE_AUTO = 0xFFFFFFFF;

private:
	/**
	* Returns the runtime Camera handle.
	*
	* @return  The runtime Camera handle
	*/
	Handle _GetCameraHandle(void) const;

	/**
	* 	Retrieves the number of camera devices.
	*
	*	@return		The number of camera devices @n
	*				If 0 (zero), it has no camera. @n
	*				If 1 (one), the Camera class is able to construct using CAMERA_PRIMARY. @n
	*				If 2 (two), the Camera class is able to construct using CAMERA_PRIMARY or CAMERA_SECONDARY. @n
	*	@exception	E_SUCCESS					   	The method is successful.
	*	@exception	E_SYSTEM						A system error has occurred.
	*/
	int _GetCameraCount (void ) const;

	/**
	* 	Retrieves a specific system information string value
	*
	* 	@return      An error code
	*	@param[in]	key 							The keyword to find
	*	@param[in]	value 							The string value
	*	@exception	E_SUCCESS					   	The method is successful.
	*	@exception	E_SYSTEM						A system error has occurred.
	*/
	result __GetSystemInfoStringValue ( Osp::Base::String& key, Osp::Base::String& value ) const;

	Camera(const Camera& camera);
	Camera& operator =(const Camera& camera);

	ICameraPi* 			__pCameraInterface;
	ICameraCapabilityPi* 			__pCameraCapabilityInterface;
	__CameraEvent*		__pCameraEvent;
	ICameraEventListener*   __pCameraEventListener;
	ICameraEventListener*   __pCameraCallback;
	static bool			__isConstructed;
	bool			__isPoweredOn;
	__CameraConfiguration*		__pConfiguration;

	friend class __VideoRecorderSourceManager;
	friend class VideoRecorder;
	friend class CameraEx;
	class CameraEx* __pCameraEx;


};



};}; // Osp::Media

#endif
