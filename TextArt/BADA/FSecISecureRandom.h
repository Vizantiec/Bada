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
 * @file		FSecISecureRandom.h
 * @brief		This is the header file for the %ISecureRandom interface.
 *
 * This header file contains the declarations of the %ISecureRandom interface.
 */
#ifndef _FSEC_ISECURE_RANDOM_H_
#define _FSEC_ISECURE_RANDOM_H_


// Includes
#include "FBaseString.h"
#include "FBaseByteBuffer.h"
#include "FSecConfig.h"


namespace Osp {namespace Security {

/**
 *	@interface	ISecureRandom 
 *	@brief		This interface provides the abstract methods for generating a secure random object.
 *  @since 		1.0
 *
*  The %ISecureRandom interface provides the abstract methods for generating a secure random object.
 *	@see	Osp::Security::AesSecureRandom, Osp::Security::DesSecureRandom, Osp::Security::DesEdeSecureRandom
 */
class _EXPORT_SECURITY_ ISecureRandom
{
// Lifecycle
public:
	/** 
	 *	This is the destructor for this class. 
	 *
	 * 	@since 		1.0
	 */	
	virtual ~ISecureRandom(void) {}


// Operation
public:
	/** 
	 *	Generates a user-specified number of random bytes.
	 *
	 * 	@since 		1.0
	 *	@return		A pointer to the %ByteBuffer class, @n
	 *				else @c null if an error occurs
	 *	@param[in]  numBytes				The number of random bytes to generate
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified @c numBytes is @c 0 or negative.
	 */
	virtual Osp::Base::ByteBuffer*	GenerateRandomBytesN(const int numBytes) = 0;

	
};
}; }; // Osp::Security
#endif// _FSEC_ISECURE_RANDOM_H_
