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
 * @file			FUixFaceRecognitionInfo.h 
 * @brief			This is the header file for the %FaceRecognitionInfo class.
 *
 * This header file contains the declarations of the %FaceRecognitionInfo class.
 *
 */
 
#ifndef _FUIX_FACE_RECOGNITION_INFO_H_
#define _FUIX_FACE_RECOGNITION_INFO_H_

// Includes
#include "FBaseObject.h"
#include "FUixConfig.h"
#include "FBase.h"
#include "FGraphics.h"

namespace Osp{ namespace Uix{ 


/**
 * @class	FaceRecognitionInfo
 * @brief	This class encapsulates the information class of a recognized face using FaceRecognizer.
 * @since	1.0
 * 
 * The %FaceRecognitionInfo class encapsulates the information of a face recognized using the FaceRecognizer class by:
 * - Getting the position of a recognized face.
 * - Getting the facial features of a recognized face.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/uix/face_detector_recognizer.htm">Face Detector and Recognizer</a>.
 *
 *
 */


class _EXPORT_UIX_ FaceRecognitionInfo :
	public Osp::Base::Object
{
public:
	/**
	 *	This is the default constructor for this class.
	 *
	 * 	@since	1.0
	 */	 
	FaceRecognitionInfo(void);

	/**
	 *	This is the destructor for this class. @n
	 *	The resources are deallocated by this method.
	 *
	 * 	@since	1.0
	 */
	~FaceRecognitionInfo(void);

// Operation
public:

	/**
	 * Initializes this instance of %FaceRecognitionInfo with the specified parameter.
	 *
	 * 	@since			1.0
	 *	@return			An error code
 	 *	@param[in]  faceFeatures					The face features obtained from the extract methods in the FaceRecognizer class
	 *	@exception	E_SUCCESS					   	The method is successful.
     *	@exception	E_OUT_OF_MEMORY					The memory is insufficient .
	 *	@exception	E_INVALID_STATE					This instance has already been constructed.
	 *  @exception	E_INVALID_ARG					The specified input parameter is invalid, or
	 *							the @c faceFeatures is not constructed.
	 *	@see				ExtractFaceFeaturesFromVideoStreamN(),ExtractFaceFeaturesFromStillImageN()
	 */	  
	result Construct(const Osp::Base::ByteBuffer& faceFeatures);
	
	/**
	 *  Retrieves the position of a recognized face.
	 *
	 * 	@since		1.0
	 *	@return		The position of a recognized face
	 */
	Osp::Graphics::Rectangle GetFacePosition(void) const;


	/**
	 *  Retrieves the facial features of a recognized face.
	 *
	 * 	@since		1.0
	 *	@return		The facial features of a recognized face
	 */
	const Osp::Base::ByteBuffer* GetFaceFeatures(void) const;


private:
	FaceRecognitionInfo(const FaceRecognitionInfo& value);
	FaceRecognitionInfo& operator =(const FaceRecognitionInfo& value);
	
	void SetFacePosition(int x, int y, int width, int height);
	
	Osp::Graphics::Rectangle __faceRect;
	Osp::Base::ByteBuffer* __pfaceFeatures;

	friend class __FaceRecognizerPi;

	friend class FaceRecognitionInfoEx;
	class FaceRecognitionInfoEx* __pFaceRecognitionInfoEx;
};


	
};}; // Osp::Uix

#endif




