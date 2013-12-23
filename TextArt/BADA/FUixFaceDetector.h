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
 * @file			FUixFaceDetector.h
 * @brief			This is the header file for the %FaceDetector class.
 *
 * This header file contains the declarations of the %FaceDetector class.
 */


#ifndef _FUIX_FACEDETECTOR_H_
#define _FUIX_FACEDETECTOR_H_

// Includes
#include "FBaseObject.h"
#include "FUixConfig.h"
#include "FUixFaceCommon.h"
#include "FUixFaceBuffer.h"
#include "FUixFaceComponentsPosition.h"


namespace Osp { namespace Uix { class IFaceDetectorPi; };};

namespace Osp { namespace Uix {

/**
 * @class	FaceDetector
 * @brief	This class is used to trace faces in an image or a video.
 * @since	1.0
 *
 * The %FaceDetector class provides the ability to automatically detect and trace faces in a still image or a video stream.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/uix/face_detector_recognizer.htm">Face Detector and Recognizer</a>.
 *
 * The following example demonstrates how to use the %FaceDetector class.
 *
 * @code
 * #include <FBase.h>
 * #include <FUix.h>
 * #include <FGraphics.h>
 * #include <FIo.h>
 * #include <FMedia.h>
 *
 * using namespace Osp::Base;
 * using namespace Osp::Media;
 * using namespace Osp::Graphics;
 * using namespace Osp::Io;
 * using namespace Osp::Uix;
 *
 *  result
 *  MyClass::TestFaceDetect(void)
 *  {
 *		ByteBuffer* pByteBuffer = null;
 *		int width = 0, height = 0;
 *		result r = E_SUCCESS;
 *
 *		Image *pImage = new Image();
 *		r = pImage->Construct();
 *
 *		String path(L"test.bmp");
 *
 *		pByteBuffer = pImage->DecodeToBufferN(path,  BITMAP_PIXEL_FORMAT_RGB565,width,height );
 *
 *		//delete the object created
 *		delete pImage;
 *
 *		if (pByteBuffer)
 *		{
 *			//Detect faces
 *			FaceDetector faceDetect;
 *			r = faceDetect.Construct();
 *			const Osp::Base::Collection::IList *pFaceDetectList = faceDetect.DetectFacesFromStillImageN(*pByteBuffer, Dimension(width,height), BITMAP_PIXEL_FORMAT_RGB565);
 *			if(pFaceDetectList == null)
 *			{
 *				delete pByteBuffer;
 *				return GetLastResult();
 *			}
 *
 *			for(int i=0; i < pFaceDetectList->GetCount(); i++)
 *			{
 *				Osp::Graphics::Rectangle*  pRect = (Osp::Graphics::Rectangle*)pFaceDetectList->GetAt(i);
 *			}
 *
 * 			delete pFaceDetectList;
 *		}
 *
 *		return r;
 *  }
 * @endcode
 */


class _EXPORT_UIX_ FaceDetector :
	public Osp::Base::Object
{

// Lifecycle

public:

	/**
	 *	This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	FaceDetector(void);

	/**
	 *	This is the destructor for this class. @n
	 *	The resources are deallocated by this method.
	 *
	 * @since	1.0
	 */
	~FaceDetector(void);


// Operation
public:

	/**
	 * Initializes this instance of %FaceDetector.
	 *
	 *  @since			1.0
	 *  @return			An error code
	 *	@exception	E_SUCCESS					   	The method is successful.
  	 *	@exception	E_OUT_OF_MEMORY					The memory is insufficient.
	 *	@exception	E_INVALID_STATE					This instance has already been constructed.
	 */
	result Construct(void);

	/**
	 *  Retrieves the range and default value of the specified configuration property.
	 *
	 *  @since			1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                For more information, see @ref CompFaceDetectorGetRangePage "here".	 
	 *	@return		  An error code
	 *	@param[in]	configProperty          		The property to query
	 *	@param[out]	min          					The minimum value of the property
	 *	@param[out]	max          					The maximum value of the property
	 *	@param[out]	steppingDelta          			The step size for the property @n
	 *												The step size is the smallest increment by which the property can be changed.
	 *	@param[out]	defaultVal          			The default value of the property
	 *	@exception	E_SUCCESS					   	The method is successful.
   	 *	@exception	E_UNSUPPORTED_OPERATION			The device does not support this property.
	 *  @exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 */
	result GetRange(FaceDetectorConfigProperty  configProperty, long& min, long& max, long& steppingDelta, long& defaultVal) const;
	/**
	* @page		CompFaceDetectorGetRangePage Compatibility for GetRange()
	*
	* @section	CompFaceDetectorGetRangePageIssueSection Issues
	*			Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* 			-# Returns the wrong results for the minimum and maximum values when configProperty is FACEDETECTOR_SCALE_VIDEO or FACEDETECTOR_SCALE_IMAGE. 
	*				The actual minimum and maximum values are @c 1 and @c 3 respectively.
	*
	* @section	CompFaceDetectorGetRangePageSolutionSection Resolutions
	*			The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	*
	* @par		When working with bada API versions prior to 2.0:
	*			-# Ignore the minimum and maximum values that are returned when configProperty is FACEDETECTOR_SCALE_VIDEO or FACEDETECTOR_SCALE_IMAGE.
	*				Assume the minimum value as @c 1 and the maximum value as @c 3. 
	*/


	/**
	 *	Sets the value of the specified property.
	 *
	 *  @since			1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                For more information, see @ref CompFaceDetectorSetPropertyPage "here".	 	 
	 *	@return			An error code
	 *	@param[in]	configProperty          		The property to query
	 *	@param[in]	value          					The new value of the property
	 *	@exception	E_SUCCESS					   	The method is successful.
	 *	@exception	E_UNSUPPORTED_OPERATION			The device does not support this property.
	 *  @exception  E_OUT_OF_RANGE					The specified @c value is out of range.
	 *  @exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 *  @see 	    GetRange()
	 */
	result SetProperty(FaceDetectorConfigProperty  configProperty, long value);
	/**
	* @page		CompFaceDetectorSetPropertyPage Compatibility for GetProperty()
	*
	* @section	CompFaceDetectorSetPropertyPageIssueSection Issues
	*			Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* 			-# Returns E_SUCCESS, even if the value is out of range when configProperty is FACEDETECTOR_SCALE_VIDEO or FACEDETECTOR_SCALE_IMAGE. 
	*				There is an issue that GetRange() returns the wrong results for the minimum and maximum values, where the actual values are @c 1 and @c 3 respectively. @n
	* 			If it is not within the range, E_OUT_OF_RANGE should be returned.
	*
	* @section	CompFaceDetectorSetPropertyPageSolutionSection Resolutions
	*			The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	*
	*/
	

	
	/**
	 *	Retrieves the current setting of the specified configuration property.
	 *
	 *  @since			1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                For more information, see @ref CompFaceDetectorGetPropertyPage "here".	 	 
	 *	@return			The value of the property, @n
	 *					else @c -1 if an exception occurs	
	 *	@param[in]	configProperty          		The property to query
	 *	@exception	E_SUCCESS					   	The method is successful.
   	 *	@exception	E_UNSUPPORTED_OPERATION			The device does not support this property.
 	 *  @exception	E_INVALID_STATE					This instance has not been constructed as yet.
 	 *  @remarks    The specific error code can be accessed using the GetLastResult() method.	 
	 */
	long GetProperty(FaceDetectorConfigProperty  configProperty) const;
	/**
	* @page		CompFaceDetectorGetPropertyPage Compatibility for GetProperty()
	*
	* @section	CompFaceDetectorGetPropertyPageIssueSection Issues
	*			Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* 			-# Returns wrong results when this method is called with FACEDETECTOR_SCALE_VIDEO. The value should be @c 3 unless it has been changed earlier using the SetProperty() method.
	*
	* @section	CompFaceDetectorGetPropertyPageSolutionSection Resolutions
	*			The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	*
	*/

	
	/**
	 * 	Retrieves a list of supported pixel formats.
	 *
	 * @since			1.0
	 * @return		A list of the supported pixel formats that are used in the DetectFacesFromVideoStreamN() method @n
	 				The format is in the form of a string.
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 *
	 * @see 			DetectFacesFromVideoStreamN()	 
	 */
	Osp::Base::Collection::IListT<Osp::Graphics::PixelFormat>* GetSupportedFormatListN(void) const;


	/**
	 * Searches for faces from a video.
	 * 
	 * @since					1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	 *                For more information, see @ref CompFaceDetectorDetectFacesFromVideoStreamNPage "here".
	 *
	 * @return		A list of the detected face positions @n
	 *						Each list's item has a pointer of Osp::Graphics::Rectangle value. @n	 
	 *						An empty list, if there are no detected faces and there is no error. @n
	 *						The faces are not detected when the faces are too small or the video data is not clear. @n
	 *						This is the result of a normal operation. @n	 
	 *						@c null, if an exception occurs. @n				
 	 *	@param[in]	byteBuffer          			The buffer containing the video data
 	 * 	@param[in]  	dim          The width and height of the video data @n
 	 *                               Both the width and height should be greater than @c 0.
 	 *	@param[in]	format           				The format of video data @n
	 *												It should be one of the pixel formats extracted from GetSupportedFormatListN().
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 *	@exception	E_INVALID_ARG					A specified input parameter is invalid.
 	 *	@exception	E_OUT_OF_MEMORY					The memory is insufficient.
	 * 	@exception	E_FAILURE						A system error has occurred.
	 *  @remarks       The specific error code can be accessed using the GetLastResult() method.	 
	 * 
	 * @see 				GetSupportedFormatListN()
	 */
	Osp::Base::Collection::IList* DetectFacesFromVideoStreamN(
		const Osp::Base::ByteBuffer& byteBuffer, const Osp::Graphics::Dimension& dim , const Osp::Graphics::PixelFormat format) ;

	/**
	* @page		CompFaceDetectorDetectFacesFromVideoStreamNPage Compatibility for DetectFacesFromVideoStreamN()
	*
	* @section	CompFaceDetectorDetectFacesFromVideoStreamNPageIssueSection Issues
	*			Implementation of this method in bada API versions prior to 1.1 has the following issue: @n
	* 			-# Returns E_SUCCESS, even if the multiplication of the width, height, and bytes per pixel of the given format does not match with the size of @c byteBuffer. @n
	* 			If they do not match, input arguments are invalid and E_INVALID_ARG should be returned.
	*
	* @section	CompFaceDetectorDetectFacesFromVideoStreamNPageSolutionSection Resolutions
	*			The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1 or above.
	*
	*/

	
	/**
	 * Detects faces from a still image.
	 *
	 *	@deprecated This method is deprecated as it may return an improper result.
	 *        Instead of using this method, use DetectFacesFromStillImageN(Osp::Base::ByteBuffer &, Osp::Graphics::Dimension &,  Osp::Graphics::BitmapPixelFormat). 
     * To optimize the memory usage and processing time, the bitmap scales down an image by decreasing its resolution in some models, 
     * that in turn decreases the accuracy of the face library. Therefore, the usage of API using ByteBuffer is encouraged. 	
	 *
	 * @since			1.0
	 *	@return		A list of the detected face positions @n
	 *				Each list's item has a pointer of Osp::Graphics::Rectangle value. @n	 
	 *				An empty list, if there are no detected faces and there is no error @n
	 *				The faces are not detected when the faces are too small or the image is not clear. @n
	 *				This is the result of a normal operation. @n	 
	 *				@c null, if an exception occurs. @n	
  	 *	@param[in]	bitmap          				The bitmap file containing the input image data
	 *	@exception	E_SUCCESS					   	The method is successful.
	 *  @exception	E_INVALID_STATE					This instance has not been constructed as yet.
 	 *	@exception	E_OUT_OF_MEMORY					The memory is insufficient.
	 * 	@exception	E_FAILURE						A system error has occurred.
	 *  @remarks    The specific error code can be accessed using the GetLastResult() method.	 
	 * 	@remarks 		BitmapPixelFormat::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.
	 */
	Osp::Base::Collection::IList* DetectFacesFromStillImageN(const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Searches for faces from a still image.
	 *
	 *  @since 		1.1  
	 *
	 *	@return		A list of the detected face positions @n
	 *				Each list's item has a pointer of Osp::Graphics::Rectangle value. @n
	 *				An empty list, if there are no detected faces and there is no error @n
	 *				The faces are not detected when the faces are too small or the image is not clear. @n
	 *				This is the result of a normal operation. @n
	 *				@c null, if an exception occurs. @n
 	 *	@param[in]	byteBuffer       The buffer containing the input image data
 	 * 	@param[in]  	dim          The width and height of the input image @n
 	 *                                  		Both the width and height should be greater than @c 0.
 	 *	@param[in]	format           	The color format defined by Osp::Graphics:: BitmapPixelFormat
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 *	@exception	E_INVALID_ARG					A specified input parameter is invalid.
 	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * 	@exception	E_FAILURE						A system error has occurred.
	 *  @remarks    The specific error code can be accessed using the GetLastResult() method.
	 * 	@remarks 		BitmapPixelFormat::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.
	 */
	Osp::Base::Collection::IList* DetectFacesFromStillImageN(const Osp::Base::ByteBuffer& byteBuffer, const Osp::Graphics::Dimension& dim , Osp::Graphics::BitmapPixelFormat format);


	 /**
	 * Converts the input data to a proper data format that can be used in the face related methods. 
	 *
	 *    @since 		2.0 	 
	 *	@return		The preprocessed data, @n
	 *				else @c null if an exception occurs
 	 *	@param[in]	byteBuffer       The buffer containing the input data
 	 * 	@param[in]    dim        The width and height of the input data @n
 	 *                           Both the width and height should be greater than @c 0.
 	 *	@param[in]	format          The format of the input data @n
	 *								It should be one of the pixel formats extracted from GetSupportedFormatListN().
	 *
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 *	@exception	E_INVALID_ARG					A specified input parameter is invalid.
 	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * 	@exception	E_SYSTEM						A system error has occurred. 
	 *
	 *    @remarks      The specific error code can be accessed using the GetLastResult() method.
	 *	@see 		GetSupportedFormatListN(), FaceBuffer 
	 */
	 FaceBuffer * PreprocessDataN(const Osp::Base::ByteBuffer& byteBuffer, const Osp::Graphics::Dimension& dim , Osp::Graphics::PixelFormat format);

	 /**
	 * Searches for faces from the preprocessed data.
	 *
	 *    @since 		2.0 	 
	 *	@return		A list of the detected face positions @n
	 *				Each list's item has a pointer of Osp::Graphics::Rectangle value. @n
	 *				An empty list, if there are no detected faces and there is no error. @n
	 *				The faces are not detected when the faces are too small or the input data is not clear. @n
	 *				This is the result of a normal operation. @n
	 *				@c null, if an exception occurs. @n
 	 *	@param[in]	preprocessedFaceBuffer      The preprocessed data @n
	 *										The @c preprocessedFaceBuffer should be obtained from PreprocessDataN().
 	 *	@param[in]	option           		 	The working option of detecting faces 
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 * 	@exception 	E_UNSUPPORTED_OPERATION		The specified mode is not supported.
 	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * 	@exception	E_SYSTEM						A system error has occurred. 
	 *    @remarks      The specific error code can be accessed using the GetLastResult() method.
	 *	@see 		PreprocessDataN(), FaceDetectorConfigProperty
	 */
	Osp::Base::Collection::IList* DetectFacesN(const FaceBuffer& preprocessedFaceBuffer, FaceDetectionOption option = FACE_DETECTION_OPTION_FAST);
	 
	 /**
	 * Extracts the facial components information.
	 *
	 *    @since 		2.0 	 
	 *	@return		The facial components information, @n	
	 *				else @c null if an exception occurs	 
 	 *	@param[in]	preprocessedFaceBuffer      		The preprocessed data @n
 	 *											The @c preprocessedFaceBuffer should be obtained from PreprocessDataN().
  	 *	@param[in]	faceRect           	The position of the detected face that is from DetectFacesN() @n
 	 * 													The value of x and y positions for the @c faceRect parameter should be greater than or equal to @c 0. @n
  	 * 													The value of width and height for the @c faceRect parameter should be greater than @c 0. @n
	 *													The position of @c faceRect should be within @c preprocessedFaceBuffer.
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 *	@exception	E_INVALID_ARG					A specified input parameter is invalid.
	 * 	@exception	E_SYSTEM						A system error has occurred.
	 * 	@exception 	E_OPERATION_FAILED				The method has failed to extract the facial information,
	 *                                              but there is no error reported.	@n
	 *												This happens when the detected faces are too small or the input data is not clear.
	 *												This is the result of a normal operation.
	 *    @remarks      The specific error code can be accessed using the GetLastResult() method.	 
	 *	@see 		PreprocessDataN(), FaceComponentsPosition
	 */
	FaceComponentsPosition* ExtractFaceComponentsN(const FaceBuffer& preprocessedFaceBuffer, const Osp::Graphics::Rectangle& faceRect);

	
 	/**
	 * Gets the position difference of the face. 
	 *
	 *    @since 		2.0 	 
	 *	@return			An error code	 	 
 	 *	@param[in]	prevData       		The buffer containing the previous video data
  	 *	@param[in]	curData       		The buffer containing the current video data @n
  	 *													The size of @c prevData and @c curData should be the same. @n
  	 *													The @c prevData and @c curData should be gotten from PreprocessDataN().
  	 *	@param[in]	prevFaceRect           	The region of the face inside @c prevData @n
 	 * 													The value of x and y positions for the @c prevFaceRect parameter should be greater than or equal to @c 0. @n
  	 * 													The value of width and height for the @c prevFaceRect parameter should be greater than @c 0. @n
	 *													The specified @c  prevFaceRect should be within @c prevData.
	 * 	@param[out]	xDiff				The x offset that is moved from the previous to current video data 	
	 * 	@param[out]  yDiff				The y offset that is moved from the previous to current video data 	
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.	 
	 *	@exception	E_INVALID_ARG					A specified input parameter is invalid.
 	 * 	@exception 	E_OPERATION_FAILED				The method has failed to get the position difference of the specified region, but there is no error reported. @n
 	 *												In this case, @c xDiff and @c yDiff will be returned with @c 0. @n
 	 *												It can happen when the detected faces are too small or two video data are different even if they 
     *                                              contain the same face.
	 *												This is the result of a normal operation.
	 *    @remarks      The specific error code can be accessed using the GetLastResult() method.	 
	 *	@remarks	This can be used for tracking the face from a sequential video data. 
	 *	@see 		PreprocessDataN(), DetectFacesN() 	 
	 */
	result GetFaceMovement(const FaceBuffer& prevData, const FaceBuffer& curData, const Osp::Graphics::Rectangle& prevFaceRect, int& xDiff, int& yDiff);
	 

private:
	FaceDetector(const FaceDetector& value);
	FaceDetector& operator =(const FaceDetector& value);
	IFaceDetectorPi* __pIFaceDetectorPi;

	friend class FaceDetectorEx;
	class FaceDetectorEx* __pFaceDetectorEx;
};
};	};
#endif

