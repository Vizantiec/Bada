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
 * @file		FSecCryptoRsaCipher.h
 * @brief		This is the header file for the %RsaCipher class. 
 * 
 * This header file contains the declarations of the %RsaCipher class.
 */
#ifndef _FSEC_CRYPTO_RSA_CIPHER_H
#define _FSEC_CRYPTO_RSA_CIPHER_H

// Includes
#include "FSecCryptoIAsymmetricCipher.h"


namespace Osp { namespace Security { namespace Crypto {

class IAsymmetricCipherPi;
/**
 *  @class		RsaCipher 
 *  @brief		This class provides methods for encryption and decryption using the Rivest Shamir Adleman (RSA).
 *	@since		1.0
 *
 *  The %RsaCipher class provides methods to encrypt and decrypt messages, and is used in the asymmetric cipher
 * operations.
 *
 *  For more information on using the Rivest Shamir Adleman (RSA) algorithm for asymmetric ciphers, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/ciphers.htm">Ciphers</a>.

 *
 *	@see Osp::Security::KeyPair, Osp::Security::IPublicKey, Osp::Security::IPrivateKey
 */
class _EXPORT_SECURITY_ RsaCipher :
	public virtual IAsymmetricCipher,
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class.
	 *
	 * 	@since 		1.0
	 */	
	RsaCipher(void);

	
	/** 
	 *	This is the destructor for this class.
	 *
	 * 	@since 		1.0
	 */	
	~RsaCipher(void);


// Operation
public:
	/** 
	 *	Sets an asymmetric private key for encryption or decryption.
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@param[in]	key						An instance of %IKey
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c key is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result SetPrivateKey(const Osp::Security::IKey& key);


	/** 
	 *	Sets an asymmetric public key for encryption or decryption.
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@param[in]	key						An instance of %IKey
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c key is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result SetPublicKey(const Osp::Security::IKey& key);


	/** 
	 *	Encrypts the data (single-part).  
	 *  
	 * 	@since 		1.0
	 *	@return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *  @param[in]	input					An instance of %ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The algorithm is not supported.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual Osp::Base::ByteBuffer*	EncryptN(const Osp::Base::ByteBuffer& input);


	/** 
	 *	Decrypts the data (single-part).   
	 *  
	 * 	@since 		1.0
	 *	@return		A pointer to the %ByteBuffer class that contains the output, @n
					else @c null if an error occurs
	 *  @param[in]	input				    An instance of %ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The algorithm is not supported.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual Osp::Base::ByteBuffer*	DecryptN(const Osp::Base::ByteBuffer& input);


// Attribute
private:
	IAsymmetricCipherPi	*m_pIAsymmPi;
	friend class		RsaCipherEx;
	class RsaCipherEx*	__pRsaCipherEx;
};
};}; };// Osp::Security::Crypto

#endif //_FSEC_CRYPTO_RSA_CIPHER_H

