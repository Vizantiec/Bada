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
 * @file		FSecCryptoIKeyExchange.h
 * @brief		This is the header file for the %IKeyExchange interface.
 *
 * This header file contains the declarations of the %IKeyExchange interface.
 */
#ifndef _FSEC_CRYPTO_IKEY_EXCHANGE_H
#define _FSEC_CRYPTO_IKEY_EXCHANGE_H

// Includes
#include "FSecConfig.h"
#include "FBaseByteBuffer.h"
#include "FSecCryptoTypes.h"
#include "FSecKeyPair.h"
#include "FSecIKeyParameters.h"

namespace Osp { namespace Security { namespace Crypto {
/**
 *	@interface	IKeyExchange
 *	@brief		This interface provides methods for the Key Exchange algorithm.
 * 	@since 		2.0
 *
 * The %IKeyExchange interface provides methods to exchange secure keys between two communicating users.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/ciphers.htm">Ciphers</a>.
 *	@see	KeyPairGenerator
 */

class _EXPORT_SECURITY_ IKeyExchange
{

// Operation
public:
	/**
	 *	This is the destructor for this class.
	 *	@since 		2.0
	 */
	virtual ~IKeyExchange(void) {};

	/**
	 *	Initializes this instance of IKeyExchange with the specified key parameters.
	 * 	@since 		2.0
	 *	@return		An error code
	 *	@param[in]	keyParameters			The domain parameters of the key exchange algorithm that needs to be instantiated
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified input parameter is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *  @remarks 	The key parameters can be @c null depending on the underlying key exchange algorithm.
	 */
	virtual result	Construct(const Osp::Security::IKeyParameters& keyParameters) = 0;

	/**
	 *	Generates the final version of the shared secret amongst the two parties.
	 * 	@since 		2.0
	 *	@return		A pointer to the %ByteBuffer class that contains the generated the secret key, @n
	 *				else @c null if the method fails to generate secret key
	 *  @param[in]  privateKey			The private key component of the first party to be instantiated
	 *	@param[in]	publicKey			The public key component of the second party to be instantiated
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			A specified input parameter is invalid.
	 *	@exception	E_INVALID_STATE			The specified state is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_UNSUPPORTED_OPERATION	This operation is not supported.
	 *  @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer*	GenerateSecretN(Osp::Security::IPrivateKey& privateKey, Osp::Security::IPublicKey& publicKey) = 0;


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
	virtual void IKeyExchange_Reserved1(void) {};

      /**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void IKeyExchange_Reserved2(void) {};

       /**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void IKeyExchange_Reserved3(void) {};

};
};}; };// Osp::Security::Crypto

#endif //_FSEC_CRYPTO_IKEY_EXCHANGE_H

