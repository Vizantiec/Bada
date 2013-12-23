/* $Change: 826527 $ */
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
 * @file			FUixFaceComponentsPosition.h 
 * @brief			This is the header file for the %FaceComponentsPosition class.
 *
 * This header file contains the declarations of the %FaceComponentsPosition class.
 *
 */
 
#ifndef _FUIX_FACE_COMPONENT_H_
#define _FUIX_FACE_COMPONENT_H_

// Includes
#include "FBaseObject.h"
#include "FUixConfig.h"
#include "FBase.h"
#include "FGraphics.h"

namespace Osp{ namespace Uix{ 

/**
 * @class	FaceComponentsPosition
 * @brief	This class encapsulates the extracted face component's information that is processed by the
 *			FaceDetector class. 
 * @since	2.0
 *
 * The %FaceComponentsPosition class encapsulates the extracted face component's information that is processed by the FaceDetector class.
 *
 * The %FaceComponentsPosition class provides the following functionalities: @n
 * - Getting/Setting the position of a face.
 * - Getting/Setting the position of the eyes.
 * - Getting/Setting the position of the mouth. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/uix/face_detector_recognizer.htm">Face Detector and Recognizer</a>.
 */

class _EXPORT_UIX_ FaceComponentsPosition :
	public Osp::Base::Object
{
public:
	/** 
	 * This is the default constructor for this class. @n
	 * Initializes this instance of %FaceComponentsPosition with all its attributes set to @c -1.
	 *
	 *    @since 		2.0 	 
	 *
	 * @remarks		The attributes are set to @c -1 when initialized.
	 */
	FaceComponentsPosition(void); 

	/**
	 * Initializes this instance of %FaceComponentsPosition with the specified parameter.
	 *
	 *    @since 		2.0 	 
	 *
  	 *	@param[in]	faceRect	The face position that can be obtained using the DetectFacesN() method present in
	 *							the FaceDetector class
	 *
  	 *	@see		DetectFacesN() 
  	 */
	FaceComponentsPosition(const Osp::Graphics::Rectangle& faceRect);

	/**
	* Initializes this instance of %FaceComponentsPosition with the specified parameters.
	*
	*    @since 		2.0 	 
	*
  	*	@param[in]	faceRect      The face position that can be obtained using the DetectFacesN() method present
	*							  in the FaceDetector class
    *	@param[in]	leftEyePos    The eye position on the left that can be obtained using the
	*							  ExtractFaceComponentsN() method present in the %FaceDetector class     	 
    *	@param[in]	rightEyePos   The eye position on the right that can be obtained using the
	*							  %ExtractFaceComponentsN() method present in the %FaceDetector class	
	*	@see		DetectFacesN(), ExtractFaceComponentsN()    	 
    */
	FaceComponentsPosition(const Osp::Graphics::Rectangle& faceRect, const Osp::Graphics::Point& leftEyePos, const Osp::Graphics::Point& rightEyePos);


	/**
	 * This is the destructor for this class. @n
	 * The resources are deallocated by this method.
	 * @since 		2.0 	 
	 */
	~FaceComponentsPosition(void);

	
	/**
	 * Retrieves the position of the face.
	 *
	 * @since 		2.0 	 
	 * @return		The position of the face
	 * @remarks		The value of all the attributes is set to @c -1 if their value is not set to @c -1 during initialization.
	
	 */
	Osp::Graphics::Rectangle GetFacePosition(void) const;

	/**
	 * Retrieves the position of the eyes.
	 *
	 *    @since 		2.0 	 
	 *
     *	@param[out]	leftEyePos      The eye position on the left	 
     *	@param[out]	rightEyePos     The eye position on the right
	 * 	@remarks	The value of @c leftEyePos and @c rightEyePos is set to @c -1 if it is not set to @c -1
	 *				during initialization.    	 
	 */
	void GetEyePosition(Osp::Graphics::Point& leftEyePos, Osp::Graphics::Point& rightEyePos) const;

	/**
	 * Retrieves the position of the mouth.
	 *
	 *    @since 		2.0 	 
	 *
	 *	@return		The position of the mouth
	 * 	@remarks	The value of all the attributes is set to @c -1 if their value is not set to @c -1 during initialization.
	 
	 */	
	Osp::Graphics::Rectangle  GetMouthPosition(void) const;

	/**
	 * Sets the position of the face.
	 *
	 *    @since 		2.0 	 
	 *
	 *	@return		An error code	 
	 *	@param[in]	faceRect	The face position that can be obtained using the DetectFacesN() method @n
	 *                          The %DetectFacesN() method is present in the FaceDetector class. @n
	 *							The value of the x and y positions for the @c faceRect parameter should be greater
	 *							than or equal to @c 0. @n
	 *							The value of the width and height for the @c faceRect parameter should be greater than
	 *							@c 0.
	 *	@exception	E_SUCCESS	The method is successful.
	 * 	@exception	E_INVALID_ARG	The specified input parameter is invalid.
	 *	@see		ExtractFaceComponentsN()	 
	 */
 	result SetFacePosition(const Osp::Graphics::Rectangle& faceRect);

	/**
	 * Sets the position of the eyes.
	 *
	 *    @since 		2.0 	 
	 *
	 *	@return		An error code	 
     *	@param[in]	leftEyePos   The eye position on the left @n
	 *                           This position can be obtained using the ExtractFaceComponentsN() method present in the FaceDetector class.
     *	@param[in]	rightEyePos  The eye position on the right @n
	 *                           This position can be obtained using the %ExtractFaceComponentsN() method present in the %FaceDetector class. @n
	 *							 The position of the eyes should be greater than or equal to @c 0. @n
	 *							 The position of @c rightEyePos should be greater than the position of
	 *							 @c leftEyePos.				
	 *	@exception	E_SUCCESS					   	The method is successful.
	 * 	@exception	E_INVALID_ARG					A specified input parameter is invalid.
	 *	@see		ExtractFaceComponentsN()	 
	 */
 	result SetEyePosition(const Osp::Graphics::Point& leftEyePos, const Osp::Graphics::Point& rightEyePos);

	/**
	 * Sets the position of the mouth.
	 *
	 *    @since 		2.0 	 
	 *
	 *	@return		An error code	 
   	 *	@param[in]	mouthRect       The position of the mouth that can be obtained using the ExtractFaceComponentsN()
	 *	 							method present in the FaceDetector class
	 *	@exception	E_SUCCESS			The method is successful. @n
	 *									The value of the x and y positions for the @c mouthRect parameter should be
	 *									greater than or equal to @c 0. @n
	 *									The value of the width and height for the @c mouthRect parameter should be
	 *									greater than @c 0. 
	 * 	@exception	E_INVALID_ARG		The specified input parameter is invalid.
	 *	@see		ExtractFaceComponentsN()		 
	 */	
	result SetMouthPosition(const Osp::Graphics::Rectangle& mouthRect);

	/** 
	 *	This is the copy constructor for the %FaceComponentsPosition class. @n
	 *	Initializes this instance of %FaceComponentsPosition with the specified parameter.
	 *
	 *    @since 		2.0 	 
	 *
	 *	@param[in]	value 	An instance of %FaceComponentsPosition
	 */
	FaceComponentsPosition(const FaceComponentsPosition& value);

	/** 
	* This operator assigns the value of the indicated %FaceComponentsPosition object to the current instance.
	*
	*	@since			2.0
	*
	* @param[in]	value	An instance of %FaceComponentsPosition
	*/	 
	FaceComponentsPosition& operator =(const FaceComponentsPosition& value);

private:
	Osp::Graphics::Rectangle __faceRect;
	Osp::Graphics::Point __eyeRight;
	Osp::Graphics::Point __eyeLeft;
	Osp::Graphics::Rectangle __mouthRect;
	
	friend class __FaceComponentsPositionPi;
	friend class FaceComponentsPositionEx;
	class FaceComponentsPositionEx* __pFaceComponentsPositionEx;
};


	
};}; // Osp::Uix

#endif




