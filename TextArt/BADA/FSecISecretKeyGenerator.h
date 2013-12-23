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
 * @file		FSecISecretKeyGenerator.h
 * @brief		This is the header file for the %ISecretKeyGenerator interface.
 *
 * This header file contains the declarations of the %ISecretKeyGenerator interface. 
 */
#ifndef _FSEC_ISECRET_KEY_GENERATOR_H_
#define _FSEC_ISECRET_KEY_GENERATOR_H_

// Includes
#include "FSecISecretKey.h"
#include "FBaseString.h"


namespace Osp {namespace Security {

/**
 * @interface	ISecretKeyGenerator 
 * @brief		This interface provides the abstract methods for generating a secret (symmetric) key.
 * @since 		1.0
 *
*  The %ISecretKeyGenerator interface provides the abstract methods for generating a secret (symmetric) key.
 * @see	Osp::Security::ISecretKey
 */
class _EXPORT_SECURITY_ ISecretKeyGenerator
{
// Operation
public:
	/** 
	 *	This is the destructor for this class.
	 *
	 * 	@since 		1.0
	 */
	virtual ~ISecretKeyGenerator(void) {}


	/** 
	 * Gets the newly generated secret key.
	 *
	 * @since 		1.0
	 * @return		A pointer to the %ISecretKey interface, @n
	 *				else @c null if the secret key generation fails
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM  			A system error has occurred.
	 */
	virtual Osp::Security::ISecretKey*	GenerateKeyN(void) = 0;
};
}; }; // Osp::Security
#endif// _FSEC_ISECRET_KEY_GENERATOR_H_
