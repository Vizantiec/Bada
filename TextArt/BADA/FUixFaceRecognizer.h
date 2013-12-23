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
 * @file			FUixFaceRecognizer.h
 * @brief			This is the header file for the %FaceRecognizer class.
 *
 * This header file contains the declarations of the %FaceRecognizer class.
 */

#ifndef _FUIX_FACERECOGNIZER_H_
#define _FUIX_FACERECOGNIZER_H_

// Includes
#include "FBaseObject.h"
#include "FUixConfig.h"
#include "FUixFaceCommon.h"
#include "FUixFaceRecognitionInfo.h"
#include "FUixFaceBuffer.h"
#include "FUixFaceComponentsPosition.h"

namespace Osp { namespace Uix { class IFaceRecognizerPi; };};

namespace Osp{ namespace Uix{


/**
 * @class	FaceRecognizer
 * @brief	This class provides methods to recognize a face in an image or a video.
 * @since	1.0
 *
 * The %FaceRecognizer class provides the ability to automatically recognize faces in a still image or video stream.
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/uix/face_detector_recognizer.htm">Face Detector and Recognizer</a>.
 *
 * The following example demonstrates how to use the %FaceRecognizer class.
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
 *  MyClass::TestFaceRecognize(void)
 *  {
 * 		ByteBuffer* pByteBuffer1 = null, *pByteBuffer2 = null;
 * 		int width1 = 0, height1 = 0, width2 = 0, height2 = 0;
 * 		result r;
 *
 * 		Image *pImage = new Image();
 * 		r = pImage->Construct();
 *
 *		String path1(L"test1.bmp");
 * 		String path2(L"test2.bmp");
 *
 * 		pByteBuffer1 = pImage->DecodeToBufferN(path1,  BITMAP_PIXEL_FORMAT_RGB565,width1,height1 );
 * 		pByteBuffer2 = pImage->DecodeToBufferN(path2,  BITMAP_PIXEL_FORMAT_RGB565,width2,height2 );
 *
 * 		//Delete the created object
 *		delete pImage;
 *
 * 		if (pByteBuffer1 && pByteBuffer2)
 * 		{
 * 			FaceRecognizer faceRecog;
 * 			r = faceRecog.Construct();
 * 			const Osp::Base::Collection::IList *pFaceDetectList1 = faceRecog.ExtractFaceInfoFromStillImageN(*pByteBuffer1, Dimension(width1,height1), BITMAP_PIXEL_FORMAT_RGB565);
 * 			const Osp::Base::Collection::IList *pFaceDetectList2 = faceRecog.ExtractFaceInfoFromStillImageN(*pByteBuffer2, Dimension(width2,height2), BITMAP_PIXEL_FORMAT_RGB565);
 *			if(pFaceDetectList1 == null || pFaceDetectList2 == null)
 * 			{
 * 				delete pByteBuffer1;
 * 				delete pByteBuffer2;
 * 				return GetLastResult();
 * 			}
 *
 * 			FaceRecognitionInfo *pFInfo1 = null, *pFInfo2 = null;
 * 			for(int i=0; i < pFaceDetectList1->GetCount(); i++)
 * 			{
 * 				pFInfo1 = (Osp::Uix::FaceRecognitionInfo*)pFaceDetectList1->GetAt(i);
 *  			for(int j=0; j < pFaceDetectList2->GetCount(); j++)
 * 				{
 * 					pFInfo2 = (Osp::Uix::FaceRecognitionInfo*)pFaceDetectList2->GetAt(j);
 * 					if(faceRecog.IsMatching(*pFInfo1, *pFInfo2))
 * 					{
 * 						Osp::Graphics::Rectangle  rect1 = (Osp::Graphics::Rectangle)pFInfo1->GetFacePosition();
 * 					}
 * 				}
 * 			}
 *
 * 			delete pByteBuffer1;
 * 			delete pByteBuffer2;
 * 		}
 * 		return r;
 *  }
 * @endcode
 */
//class FaceInfo;

class _EXPORT_UIX_ FaceRecognizer :
	public Osp::Base::Object
{

// Lifecycle

public:

	/**
	 *	This is the default constructor for this class.
	 *
	 *  @since	1.0
	 */
	FaceRecognizer(void);

	/**
	 *	This is the destructor for this class. @n
	 *	The resources are deallocated by this method.
	 *
	 *  @since	1.0
	 */
	~FaceRecognizer(void);


// Operation
public:

	/**
	 * Initializes an instance of %FaceRecognizer.
	 *
	 *  @since			1.0
	 *	@return			An error code
	 *	@exception	E_SUCCESS					   	The method is successful.
   *	@exception	E_OUT_OF_MEMORY					The memory is insufficient.
	 *	@exception	E_INVALID_STATE					This instance has already been constructed.
	 */
	result Construct(	void);

	/**
	 *  Gets the range and default value of the specified configuration property.
	 *
	 *  @since			1.0
       * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
       *                For more information, see @ref CompFaceRecognizerGetRangePage "here".         
	 
	 *	@return			An error code
	 *	@param[in]	configProperty          		The property to query
	 *	@param[out]	min          					The minimum value of the property
	 *	@param[out]	max          					The maximum value of the property
	 *	@param[out]	steppingDelta          			The step size of the property @n
	 *												The step size is the smallest increment by which the property can be changed.
	 *	@param[out]	defaultVal          			The default value of the property
	 *	@exception	E_SUCCESS					   	The method is successful.
   	*	@exception	E_UNSUPPORTED_OPERATION			The device does not support the specified configuration property.
	 *  @exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 */
	result GetRange(FaceRecognizerConfigProperty  configProperty, long& min, long& max, long& steppingDelta, long& defaultVal) const;
       /**
       * @page                     CompFaceRecognizerGetRangePage Compatibility for GetRange()
       *
       * @section        CompFaceRecognizerGetRangePageIssueSection Issues
       *                               Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
       *                               -# Returns the wrong values for the @c min and @c max parameters 
	   * when @c configProperty is set to FACERECOGNIZER_SCALE_VIDEO or FACERECOGNIZER_SCALE_IMAGE. @n
 	 *    					The actual values for @c min and @c max are @c 1 and @c 3, respectively.
       * @section        CompFaceRecognizerGetRangePageSolutionSection Resolutions
       *                               The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	*
  	* @par  When working with bada API versions prior to 2.0:
 	*    Ignore the values of @c min and @c max that are returned when @c configProperty is set to
	*	FACEDETECTOR_SCALE_VIDEO or FACEDETECTOR_SCALE_IMAGE.
 	*   Assume that the values of @c min and @c max are @c 1 and @c 3 respectively. 
       *
       */

	   
	/**
	 *	Sets the value of the specified property.
	 *
	 *  @since			1.0
       * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
       *                For more information, see @ref CompFaceRecognizerSetPropertyPage "here".             
	*	 
	 *	@return			An error code
	 *	@param[in]	configProperty          		The property to query
	 *	@param[in]	value          					The new value of the property
	 *	@exception	E_SUCCESS					   	The method is successful.
	 *	@exception	E_UNSUPPORTED_OPERATION			The device does not support the specified configuration property.
	 *  @exception  E_OUT_OF_RANGE					The specified @c value is out of range.
 	 *  @exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 *  @see 		    GetRange()
	 */
	result SetProperty(FaceRecognizerConfigProperty  configProperty, long value);
       /**
       * @page                     CompFaceRecognizerSetPropertyPage Compatibility for GetProperty()
       *
       * @section        CompFaceRecognizerSetPropertyPageIssueSection Issues
       *                               Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
       *                               -# Returns E_SUCCESS, even if the value of the property is out of range when
	   * @c configProperty is set to FACERECOGNIZER_SCALE_VIDEO or FACERECOGNIZER_SCALE_IMAGE. @n
       *    						If the value of property is not within the range, E_OUT_OF_RANGE should be returned.
       *
       * @section        CompFaceRecognizerSetPropertyPageSolutionSection Resolutions
       *                               The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
       *
       */
       

	/**
	 *	Gets the current setting of the specified configuration property.
	 *
	 *  @since			1.0
       * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
       *                For more information, see @ref CompFaceRecognizerGetPropertyPage "here".     
       *
	 *	@return			The value of the property, @n
	 *							else @c -1 if an exception occurs
	 *	@param[in]	configProperty          		The property to query
	 *	@exception	E_SUCCESS					   	The method is successful.
   	*	@exception	E_UNSUPPORTED_OPERATION			The device does not support the specified configuration property.
 	 *  @exception	E_INVALID_STATE					This instance has not been constructed as yet.
 	 *  @remarks    The specific error code can be accessed using the GetLastResult() method.	 	 
	 */
	long GetProperty(FaceRecognizerConfigProperty  configProperty) const;
       /**
       * @page                     CompFaceRecognizerGetPropertyPage Compatibility for GetProperty()
       *
       * @section        CompFaceRecognizerGetPropertyPageIssueSection Issues
       *                               Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
       *                               -# Returns wrong value when called with FACEDETECTOR_SCALE_VIDEO. The value should be @c 3 in case it has not changed using SetProperty() before.
       *
       * @section        CompFaceRecognizerGetPropertyPageSolutionSection Resolutions
       *                               The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
       *
         */







	/**
	 *	Gets a list of supported pixel formats.
	 *
	 *  @since			1.0
	 *	@return			A list of the supported pixel formats that are used in ExtractFaceInfoFromVideoStreamN() @n
	 *							The format is in the form of a string.
	 *	@exception	E_SUCCESS						The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.	 
 	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 *
 	 * 	@see 			ExtractFaceInfoFromVideoStreamN()	 	 
	 */
	Osp::Base::Collection::IListT<Osp::Graphics::PixelFormat>* GetSupportedFormatListN(void) const;

	/**
	 *	Extracts the facial template that represents the face from a video.
	 *
	 *  @since					1.0
	 *  @compatibility  This method has compatibility issues with different bada API versions. @n
	 *               		For more information, see @ref CompFaceRecognizerExtractFaceInfoFromVideoStreamNPage "1.1" and @ref CompFaceRecognizerExtractFaceInfoFromVideoStreamNPage2 "2.0".
	 *
	 *	@return		A list of the FaceRecognitionInfo instances that contain the extracted facial features, @n
	 *				else @c null if an exception occurs @n 
	 *				Each list's item has a pointer to the Osp::Graphics::FaceRecognitionInfo value. @n
	 *				An empty list, if there are no detected faces and there is no error. @n
	 *				The faces are not detected when the faces are too small, or when the video data is not
	 *				clear.
	 *				This is the result of a normal operation.
   	*	@param[in]	byteBuffer          			A pointer to the buffer containing the video data
   	* 	@param[in]  	dim          The width and height of the video data @n
   	*                                  	Both the width and height should be greater than @c 0.
   	*	@param[in]	format           				The format of the video data @n
	 *												It should be one of the pixel formats extracted from GetSupportedFormatListN().
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 *	@exception	E_INVALID_ARG					A specified input parameter is invalid, or
	 *												the specified @c format is invalid.
 	 *	@exception	E_OUT_OF_MEMORY					The memory is insufficient.
	 * 	@exception	E_FAILURE						A system error has occurred.
	 *  @remarks    The specific error code can be accessed using the GetLastResult() method.	  
	 *	@see		FaceRecognitionInfo, GetSupportedFormatListN()
	 */
	Osp::Base::Collection::IList* ExtractFaceInfoFromVideoStreamN(
		const Osp::Base::ByteBuffer& byteBuffer, const Osp::Graphics::Dimension& dim , const Osp::Graphics::PixelFormat format);


	/**
	* @page			CompFaceRecognizerExtractFaceInfoFromVideoStreamNPage Compatibility for ExtractFaceInfoFromVideoStreamN()
	*
	* @section	CompFaceRecognizerExtractFaceInfoFromVideoStreamNPageIssueSection Issues
	*			Implementation of this method in bada API versions prior to 1.1 has the following issue: @n
	* 			-# Returns E_SUCCESS, even if the multiplication of the width, height, and bytes per pixel of the given format does not match with the size of @c byteBuffer. @n
	* 			If they do not match, input arguments are invalid and E_INVALID_ARG should be returned.
	*
	* @section	CompFaceRecognizerExtractFaceInfoFromVideoStreamNPageSolutionSection Resolutions
	*			The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1 or above.
	*
	*/

   /**
   * @page           CompFaceRecognizerExtractFaceInfoFromVideoStreamNPage2 Compatibility for ExtractFaceInfoFromVideoStreamN()
   *
   * @section        CompFaceRecognizerExtractFaceInfoFromVideoStreamNPage2IssueSection Issues
   *                               Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
   *                               -# Returns only one result, even if FACERECOGNIZER_MAXNUMBER_VIDEO is set to a value larger than the value that is set by calling the SetProperty(FACERECOGNIZER_MAXNUMBER_VIDEO, value) method.
   *
   * @section        CompFaceRecognizerExtractFaceInfoFromVideoStreamNPage2SolutionSection Resolutions
   *                               The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
   *
   */

	

	/**
	 *	Extracts the facial template that represents the face from the still image.
	 *
	  *	@deprecated This method is deprecated as it may return an improper result.
	 *        			Instead of using this method, use ExtractFaceInfoFromStillImageN(Osp::Base::ByteBuffer &, Osp::Graphics::Dimension &,  Osp::Graphics::BitmapPixelFormat). To optimize the memory usage and processing time, the bitmap scales down an image by decreasing its resolution in some models, that in turn decreases the accuracy of
     *        the face library. Therefore, the usage of this method using ByteBuffer is encouraged. 	
	 *	 
	 *  @since		1.0
	 *	@return		A list of the FaceRecognitionInfo instances that contain the extracted facial features, @n
	 *				else @c null if an exception occurs @n
	 *				Each list's item has a pointer to the Osp::Graphics::FaceRecognitionInfo value. @n
	 *				An empty list, if there are no detected faces and there is no error. @n
	 *				The faces are not detected when the faces are too small or the image is not clear.
	 *				This is the result of a normal operation.
	 *				
   *	@param[in]	bitmap          				The bitmap file containing the input image data
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.
 	 *	@exception	E_OUT_OF_MEMORY					The memory is insufficient.
	 * 	@exception	E_FAILURE						A system error has occurred.
	 *    @remarks       The specific error code can be accessed using the GetLastResult() method.	 
	 * 	@remarks 		BitmapPixelFormat::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method. 		 
	 *	@see		FaceRecognitionInfo
	 */
	Osp::Base::Collection::IList* ExtractFaceInfoFromStillImageN(const Osp::Graphics::Bitmap& bitmap);


	/**
	 *  Extracts the facial template that represents the face from the still image.
	 *
	 *  @since 	 1.1  
	 *
	 *	@return	 A list of the FaceRecognitionInfo instances that contain the extracted facial features, @n
	 *			 else @c null if an exception occurs @n
	 *			 Each list's item has a pointer to the Osp::Graphics::FaceRecognitionInfo value. @n
	 *			 An empty list, if there are no detected faces and there is no error. @n
	 *			 The faces are not detected when the faces are too small or the image is not clear. 
	 *			 This is the result of a normal operation. 
	 *				   
 	 *	@param[in]	byteBuffer       The buffer containing the input image data
 	 * 	@param[in]  	dim        The width and height of the input image @n
 	 *                                  		 Both the width and height should be greater than @c 0.
 	 *	@param[in]	format           	 The color format defined by Osp::Graphics:: BitmapPixelFormat
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 *	@exception	E_INVALID_ARG					A specified input parameter is invalid.
 	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * 	@exception	E_FAILURE						A system error has occurred.
	 *  @remarks    The specific error code can be accessed using the GetLastResult() method.	 
	 * 	@remarks 		BitmapPixelFormat::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method. 	 
	 */
	Osp::Base::Collection::IList* ExtractFaceInfoFromStillImageN(const Osp::Base::ByteBuffer& byteBuffer, const Osp::Graphics::Dimension& dim , Osp::Graphics::BitmapPixelFormat format);

	
	/**
	 * Checks whether the two specified faces match.
	 *
	 *  @since		1.0
	 *	@return		@c true if the two faces match, @n
	 *						else @c false
   *	@param[in]	face1  				The face information of the first face
   *	@param[in]	face2  				The face information of the second face
	 *	@exception	E_SUCCESS			The method is successful.
	 * 	@exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 *	@exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									a specified FaceRecognitionInfo is not constructed.
	 * 	@exception	E_FAILURE			A system error has occurred.
 	 *	@exception	E_OUT_OF_MEMORY		The memory is insufficient.
 	 *  @remarks    The specific error code can be accessed using the GetLastResult() method.	 	 
	 */
	bool IsMatching(const FaceRecognitionInfo& face1, const FaceRecognitionInfo& face2);

	/**
	 * Gets the similarity of the two specified faces.
	 *
	 *  @since				1.0
	 *	@return					The degree of similarity in percentage @n 
	 * 								The range is from @c 0 to @c 100. @c 100 means the faces are the same, and @c 0 means there is no similarity at all between the two faces. @n
	 *								else @c -1 if an exception occurs
   *	@param[in]	face1  				The face information of the first face
   *	@param[in]	face2  				The face information of the second face
	 *	@exception	E_SUCCESS			The method is successful.
	 * 	@exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 *	@exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									a specified FaceRecognitionInfo is not constructed.
	 * 	@exception	E_FAILURE			A system error has occurred.	 
 	 *	@exception	E_OUT_OF_MEMORY		The memory is insufficient.
 	 *  @remarks    The specific error code can be accessed using the GetLastResult() method.	 	 
	 */
	int MeasureSimilarity(const FaceRecognitionInfo& face1, const FaceRecognitionInfo& face2);


 	/**
	 * Extracts the facial template that represents a face.
	 *
	 *    @since 		2.0 	 
	 *	@return		The facial features of a recognized face, @n
	 *				else @c null if an exception occurs 
 	 *	@param[in]	preprocessedFaceBuffer      	The preprocessed data
	 *	@param[in]	faceComponentPos          		The facial information that is obtained from the
	 *												ExtractFaceComponentsN() method @n
	 *												The @c faceComponentPos parameter should contain the eye position. 
 	 * 												The position of the eyes should be greater than or equal to @c 0.
	 *												The position of the eyes should be within @c preprocessedFaceBuffer.  								
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 *	@exception	E_INVALID_ARG					A specified input parameter is invalid.											
 	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * 	@exception	E_SYSTEM						A system error has occurred.
	 * 	@exception 	E_OPERATION_FAILED				The method has failed to extract the facial information but there is no error reported. @n
	 *													This can happen when the detected faces are too small or the input data is not clear.
	 *													This is the result of a normal operation.
	 *    @remarks      The specific error code can be accessed using the GetLastResult() method.
	 *    @remarks 	If there are wrong values in the @c faceComponentPos, the result cannot be guaranteed even if it returns E_SUCCESS. Therefore please be sure not to change the value of @c faceComponentPos after getting it from ExtractFaceComponentsN(). 	 
	 *	@see		PreprocessDataN(), ExtractFaceComponentsN()	 	 
	 */
	 Osp::Base::ByteBuffer* ExtractFeatureN(const FaceBuffer& preprocessedFaceBuffer, const FaceComponentsPosition& faceComponentPos);


 	/**
	 * Detects the eye status.
	 *
	 *    @since 		2.0 	 
	 *	@return		The eye status, @n
	 *				else @c EYE_STATE_NONE if an exception occurs
 	 *	@param[in]	preprocessedFaceBuffer      	The preprocessed data
	 *	@param[in]	faceComponentPos          		The facial information that is obtained from the ExtractFaceComponentsN() method @n	
	 *								The @c faceComponentPos parameter should contain the eye position.
	 * 								The position of the eyes should be greater than or equal to @c 0.
	 *								The position of the eyes should be within @c preprocessedFaceBuffer.		 
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 *	@exception	E_INVALID_ARG					A specified input parameter is invalid.	 
 	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * 	@exception	E_SYSTEM						A system error has occurred.
	 * 	@exception 	E_OPERATION_FAILED			The method has failed to detect the eye state but there is no error reported. @n
	 *											This can happen when the detected faces are too small or the input data is not clear.
	 *													This is the result of a normal operation.
	 *    @remarks      The specific error code can be accessed using the GetLastResult() method.	 
	 *    @remarks 	If there are wrong values in the @c faceComponentPos, the result cannot be guaranteed even if it returns E_SUCCESS. Therefore please be sure not to change the value of @c faceComponentPos after getting it from ExtractFaceComponentsN(). 	 	 
	 *	@see		PreprocessDataN(), ExtractFaceComponentsN()	 	 
	 */
	EyeState GetEyeState(const FaceBuffer& preprocessedFaceBuffer, const FaceComponentsPosition& faceComponentPos);          


 	/**
	 * Recognizes the facial expression.
	 *
	 *    @since 		2.0 	 
	 *	@return		The facial expression, @n
	 *				else @c FACIAL_EXPRESSION_NONE if an exception occurs	 	 
 	 *	@param[in]	preprocessedFaceBuffer      	The preprocessed data
	 *	@param[in]	faceComponentPos          		The facial information that is obtained from the ExtractFaceComponentsN() method @n
	 *								The @c faceComponentPos parameter should contain the eye position.  
	 * 								The position of the eyes should be greater than or equal to @c 0.
	 *								The position of the eyes should be within @c preprocessedFaceBuffer. 	 	 
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 *	@exception	E_INVALID_ARG					A specified input parameter is invalid.
 	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * 	@exception	E_SYSTEM						A system error has occurred.
	 * 	@exception 	E_OPERATION_FAILED				The method has failed to extract the facial expression but there is no error reported. @n
	 *												This can happen when the detected faces are too small or the input data is not clear.
	 *													This is the result of a normal operation.
	 *    @remarks      The specific error code can be accessed using the GetLastResult() method.
	 *    @remarks 	If there are wrong values in the @c faceComponentPos, the result cannot be guaranteed even if it returns E_SUCCESS. Therefore please be sure not to change the value of @c faceComponentPos after getting it from ExtractFaceComponentsN(). 	 	 	 
	 *	@see		PreprocessDataN(), ExtractFaceComponentsN()		 
	 */
	FacialExpression RecognizeExpression(const FaceBuffer& preprocessedFaceBuffer, const FaceComponentsPosition& faceComponentPos);

	/**
	 *	Detects the eye states from a video.
	 *
	 *    @since 		2.0 	 
	 *	@return		A list of eye states, @n
	 *					else @c null if an exception occurs @n
	 *				Each list's item has an EyeState value. @n	 
	 *				An empty list, if there are no detected eye states and there is no error. @n
	 *				The eye states are not detected when the faces are too small or the video data is not clear.
	 *				This is the result of a normal operation.
	 *				
  	 *	@param[in]	byteBuffer          			The buffer containing the video data
  	 * 	@param[in]  	dim          				The width and height of the video data @n
  	 *                                  			Both the width and height should be greater than @c 0.
  	 *	@param[in]	format           			The format of the video data @n
	 *												It should be one of the pixel formats extracted from GetSupportedFormatListN().
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 *	@exception	E_INVALID_ARG					A specified input parameter is invalid.
 	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * 	@exception	E_SYSTEM						A system error has occurred.
	 *  	@remarks    	The specific error code can be accessed using the GetLastResult() method.	  
	 *	@see		GetSupportedFormatListN(), EyeState
	 */
	Osp::Base::Collection::IMapT<Osp::Graphics::Rectangle, EyeState>* DetectBlinksFromVideoStreamN(
		const Osp::Base::ByteBuffer& byteBuffer, const Osp::Graphics::Dimension& dim , const Osp::Graphics::PixelFormat format);


	/**
	 *	Detects the eye states from a still image.
	 *
	 *    @since 		2.0 	 
	 *	@return		The list of eye states, @n
	 *					else @c null if an exception occurs @n
	 *				Each list's item has an EyeState value. @n	 
	 *				An empty list, if there are no detected eye states and there is no error. @n
	 *				The eye states are not detected when the faces are too small or the video data is not clear.
	 *				This is the result of a normal operation.
	 *				
  	 *	@param[in]	byteBuffer          			The buffer containing the input image data
  	 * 	@param[in]  	dim          			The width and height of the input image @n
  	 *                                  	Both the width and height should be greater than @c 0.
 	 *	@param[in]	format           	 The color format defined by Osp::Graphics:: BitmapPixelFormat
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 *	@exception	E_INVALID_ARG					A specified input parameter is invalid.
 	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * 	@exception	E_SYSTEM						A system error has occurred.
	 *  	@remarks    	The specific error code can be accessed using the GetLastResult() method.	  
	 *	@see		EyeState	 
	 */
	Osp::Base::Collection::IMapT<Osp::Graphics::Rectangle, EyeState>* DetectBlinksFromStillImageN(
		const Osp::Base::ByteBuffer& byteBuffer, const Osp::Graphics::Dimension& dim , Osp::Graphics::BitmapPixelFormat format);

	/**
	 *	Recognizes the facial expressions from a video.
	 *
	 *    @since 		2.0 	 
	 *	@return		A list of facial expressions, @n
	 *					else @c null if an exception occurs @n
	 *				Each list's item has a FacialExpression value. @n	 
	 *				An empty list, if there are no recognized facial expression and there is no error. @n
	 *				The expressions are not recognized when the faces are too small or the video data is not clear.
	 *				This is the result of a normal operation.
	 *	@param[in]	byteBuffer          			The buffer containing the video data
  	 * 	@param[in]  	dim          			The width and height of the video data @n
  	 *                                  						Both the width and height should be greater than @c 0.
  	 *	@param[in]	format           				The format of the video data @n
	 *												It should be one of the pixel formats extracted from GetSupportedFormatListN().
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 *	@exception	E_INVALID_ARG					A specified input parameter is invalid.
 	 *	@exception	E_OUT_OF_MEMORY					The memory is insufficient.
	 * 	@exception	E_SYSTEM						A system error has occurred.
	 *  	@remarks    	The specific error code can be accessed using the GetLastResult() method.	  
	 *	@see		GetSupportedFormatListN(), FacialExpression
	 */
	Osp::Base::Collection::IMapT<Osp::Graphics::Rectangle, FacialExpression>* RecognizeExpressionsFromVideoStreamN(
		const Osp::Base::ByteBuffer& byteBuffer, const Osp::Graphics::Dimension& dim , const Osp::Graphics::PixelFormat format);


	/**
	 *	Recognizes the facial expressions from the still image.
	 *
	 *    @since 		2.0 	 
	 *	@return		A list of the facial expressions, @n
	 *					else @c null if an exception occurs @n
	 *				Each list's item has a FacialExpression value. @n	 
	 *				An empty list, if there are no recognized facial expression and there is no error @n
	 *				The expressions are not recognized when the faces are too small or the image is not clear.
	 *				This is the result of a normal operation.
	 *				
  	 *	@param[in]	byteBuffer          			The buffer containing the input image data
  	 * 	@param[in]  	dim          			The width and height of the input image @n
  	 *                                  						Both the width and height should be greater than @c 0.
 	 *	@param[in]	format           	 The color format defined by Osp::Graphics:: BitmapPixelFormat
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_STATE					This instance has not been constructed as yet.
	 *	@exception	E_INVALID_ARG					A specified input parameter is invalid.
 	 *	@exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * 	@exception	E_SYSTEM						A system error has occurred.
	 *  	@remarks    	The specific error code can be accessed using the GetLastResult() method.	  
	 *	@see		FacialExpression	 
	 */
	Osp::Base::Collection::IMapT<Osp::Graphics::Rectangle, FacialExpression>* RecognizeExpressionsFromStillImageN(
		const Osp::Base::ByteBuffer& byteBuffer, const Osp::Graphics::Dimension& dim , Osp::Graphics::BitmapPixelFormat format);

	
private:
	FaceRecognizer(const FaceRecognizer& value);
	FaceRecognizer& operator =(const FaceRecognizer& value);	
	IFaceRecognizerPi* __pIFaceRecognizerPi;

	friend class FaceRecognizerEx;
	class FaceRecognizerEx* __pFaceRecognizerEx;
};



};}; // Osp::Uix

#endif




