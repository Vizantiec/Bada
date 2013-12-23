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
 * @file		FSecIKeyPairGenerator.h
 * @brief		This is the header file for the %IKeyPairGenerator interface.
 *
 * This header file contains the declarations of the %IKeyPairGenerator interface.
 */
#ifndef _FSEC_IKEY_PAIR_GENERATOR_H_
#define _FSEC_IKEY_PAIR_GENERATOR_H_

// Includes
#include "FBaseString.h"
#include "FSecKeyPair.h"


namespace Osp {namespace Security {
/**
 * @interface	IKeyPairGenerator 
 * @brief		This interface provides the abstract methods for generating a pair of public and private keys.
 * @since 		1.0
 *
 * The %IKeyPairGenerator interface provides the abstract methods for generating a pair of public and private keys.
 * @see			Osp::Security::KeyPair
 */

class _EXPORT_SECURITY_ IKeyPairGenerator
{
// Operation
public:
	/** 
	 *	This is the destructor for this class.
	 *
	 * 	@since 		1.0
	 */
	virtual ~IKeyPairGenerator(void){};


	/** 
	 * Initializes this instance of IKeyPairGenerator with the specified modulus size.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	modulusBitSize		The modulus size in bits
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c modulusBitSize is invalid. @n
	 *									It should be @c 1024 bits or @c 2048 bits.
	 */
	virtual result	Construct(int modulusBitSize) = 0;


	/** 
	 * Gets the newly generated key pair.
	 *
	 * @since 		1.0
	 * @return		A pointer to the %KeyPair class, @n
	 *				else @c null if the method fails to generate the key pair
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	This operation is not supported.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM  				A system error has occurred.
	 */
	virtual Osp::Security::KeyPair*	GenerateKeyPairN(void) const = 0;


};
}; }; // Osp::Security
#endif// _FSEC_IKEY_PAIR_GENERATOR_H_
