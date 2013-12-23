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
 * @file			FUixFaceBuffer.h 
 * @brief			This is the header file for the %FaceBuffer class.
 *
 * This header file contains the declarations of the %FaceBuffer class.
 *
 */
 
#ifndef _FUIX_FACE_DATA_H_
#define _FUIX_FACE_DATA_H_

// Includes
#include "FBaseObject.h"
#include "FUixConfig.h"
#include "FBase.h"
#include "FGraphics.h"

namespace Osp{ namespace Uix{ 

/**
 * @class	FaceBuffer
 * @brief	This class encapsulates the information processed by the FaceDetector and FaceRecognizer classes.
 * @since	2.0
 *
 * The %FaceBuffer class encapsulates the information processed by the FaceDetector and FaceRecognizer classes.
 * It contains proper data format that can be used in the face related methods. The user can get the face buffer from
 * PreprocessDataN() in the %FaceDetector class. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/uix/face_detector_recognizer.htm">Face Detector and Recognizer</a>.
 *
 */

class _EXPORT_UIX_ FaceBuffer :
	public Osp::Base::Object
{

public:
	/**
	 * This is the destructor for this class. @n
	 * The resources are deallocated by this method.
	 *
	 * @since	2.0
	 */
	~FaceBuffer(void);

// Operation

public:
	/**
	 * Retrieves the width and height of the face data.
	 *
	 * @since		2.0
	 * @return		The dimension of the face data
	 */
	Osp::Graphics::Dimension GetDimension(void) const;


	/**
	 * Retrieves the buffer that contains the face data. 
	 *
	 * @since		2.0
	 * @return		A pointer to the buffer containing the face data
	 */
	const Osp::Base::ByteBuffer* GetBuffer(void) const;	

private:
	/**
	 *	This is the default constructor for this class.
	 */	 
	FaceBuffer(void);

	FaceBuffer(const Osp::Base::ByteBuffer& buffer, const Osp::Graphics::Dimension& dim);

	result SetDimension(const Osp::Graphics::Dimension& dim);	

	result SetBuffer(const Osp::Base::ByteBuffer& buffer);

	FaceBuffer(const FaceBuffer& value);
	FaceBuffer& operator =(const FaceBuffer& value);	
	
private:
	Osp::Base::ByteBuffer* __pBuffer;
	Osp::Graphics::Dimension __resolution;

	friend class FaceDetector;
	
	friend class __FaceBufferPi;
	friend class FaceBufferEx;
	class FaceBufferEx* __pFaceBufferEx;
};


	
};}; // Osp::Uix

#endif




