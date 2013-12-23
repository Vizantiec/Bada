/* $Change: 530918 $ */
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
 * @file		FSecIKeyParameters.h
 * @brief		This is the header file for the %IKeyParameters interface.
 *
 * This header file contains the declarations of the %IKeyParameters interface.
 */
#ifndef _FSEC_CRYPTO_IKEY_PARAMETERS_H
#define _FSEC_CRYPTO_IKEY_PARAMETERS_H

// includes
#include "FSecConfig.h"
#include "FBaseByteBuffer.h"
#include "FSecCryptoTypes.h"

namespace Osp { namespace Security {

/**
 * @interface	IKeyParameters
 * @brief		This interface provides the abstract methods for retrieving the parameters of the key exchange algorithms.
 * @since 		2.0
 *
 * The %IKeyParameters interface provides the abstract methods for retrieving the parameters of the key exchange algorithms.
 * @see			Osp::Security::KeyPair
 */

class _EXPORT_SECURITY_ IKeyParameters
{

// Operation
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since 	2.0
	 */
	virtual ~IKeyParameters(void) {};
	/**
	 * Gets the value of the parameter for a specified key parameter type.
	 *
	 * @since 		2.0
	 * @return		A pointer to the %ByteBuffer class that contains the parameter values, @n
	 *				else @c null if an error occurs
	 * @param[in]	paramType				The type of the parameter @n
	 *                                      For example, KEY_PARAMETER_DH_G.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_UNSUPPORTED_TYPE		The specified @c paramType is not supported.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer* GetParameterValueN(KeyParameterType paramType) = 0;

	/**
	 * Gets the size of the key parameter in bits for the specified key parameter type.
	 *
	 * @since 		2.0
	 * @return		The size of the parameter, @n
	 *				else @c 0 if an error occurs
	 * @param[in]	keyParameterType		The type of the parameter @n
	 *                                      For example, PRIVATE_KEY_SIZE.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_UNSUPPORTED_TYPE		The specified @c paramType is not supported
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual int GetParameterSize(KeyParameterType keyParameterType) = 0;

protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void IKeyParameters_Reserved1(void) {};

      /**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void IKeyParameters_Reserved2(void) {};

};

};};// Osp::Security

#endif //_FSEC_CRYPTO_IKEY_PAIR_PARAMETERS_H
