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
 * @file		FSecKeyPair.h
 * @brief		This is the header file for the %KeyPair class.
 *
 * This header file contains the declarations of the %KeyPair class.
 */
#ifndef _FSEC_KEY_PAIR_H_
#define _FSEC_KEY_PAIR_H_

// Includes
#include "FSecIKey.h"
#include "FSecIPublicKey.h"
#include "FSecIPrivateKey.h"
#include "FBaseObject.h"


namespace Osp {namespace Security {

class IPublicKeyPi;
class IPrivateKeyPi;
/**
 *  @class		KeyPair 
 *  @brief		This class is a simple holder for a key pair (a public key and a private key).
 *  @since 		1.0
 *
 *  The %KeyPair class manages a pair of keys comprising of a public and a private key, which are used in asymmetric ciphers. The key pairs are mainly used to encrypt messages and provide digital signatures.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/key_mgmt_and_csprng.htm">Key Management and CSPRNG</a>.
 *
 *  @see	IKeyPairGenerator, Osp::Security::IPublicKey, Osp::Security::IPrivateKey
 */

class _EXPORT_SECURITY_ KeyPair:
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class.
	 *
	 * 	@since 		1.0
	 */	
	KeyPair(void);


	/** 
	 *	This is the destructor for this class. 
	 *
	 * 	@since 		1.0
	 */	
	~KeyPair(void);


// Operation
public:
	/** 
	 *	Initializes the current instance of %KeyPair with the specified public and private keys.
	 *
	 * 	@since 			1.0
	 *	@return			An error code
	 *	@param[in]	publicKey				An instance of %IPublicKey
	 * 	@param[in]	privateKey				An instance of %IPrivateKey
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified @c publicKey or @c privateKey is invalid.
	 */
	result Construct(Osp::Security::IPublicKey& publicKey, Osp::Security::IPrivateKey& privateKey);


	/** 
	 *	Gets the public key component of the current instance of %KeyPair. 
	 *
	 * 	@since 		1.0
	 *	@return		A pointer to %IPublicKey
	 */
	Osp::Security::IPublicKey*	GetPublicKey(void) const;


	/** 
	 *	Gets the private key component of the current instance of %KeyPair.
	 *
	 * 	@since 		1.0
	 *	@return		A pointer to %IPrivateKey
	 */
	Osp::Security::IPrivateKey*	GetPrivateKey(void) const;


	/** 
	 *	Sets the public key.
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@param[in]	pubKey					An instance of %ByteBuffer that contains the public key
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified @c pubKey is invalid.
	 */
	result SetPublicKey(const Osp::Base::ByteBuffer& pubKey);
	

	/** 
	 *	Sets the private key. 
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 * 	@param[in]	privKey					An instance of %ByteBuffer that contains the private key
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified @c privKey is invalid.
	 */
	result SetPrivateKey(const Osp::Base::ByteBuffer& privKey);


// Attribute
private:
	Osp::Security::IPublicKey		*m_pPubKey;
	Osp::Security::IPrivateKey	*m_pPriKey;
	Osp::Security::IPublicKeyPi	*m_pPubKeyPi;
	Osp::Security::IPrivateKeyPi	*m_pPriKeyPi;
	friend class			KeyPairEx;
	class KeyPairEx*		__pKeyPairEx;
};
}; }; // Osp::Security


#endif// _FSEC_KEY_PAIR_H_
