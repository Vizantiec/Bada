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
 * @file		FSecSecretKeyGenerator.h
 * @brief		This is the header file for the %SecretKeyGenerator class.
 *
 * This header file contains the declarations of the %SecretKeyGenerator class.
 */
#ifndef _FSEC_SECRET_KEY_GENERATOR_H_
#define _FSEC_SECRET_KEY_GENERATOR_H_

// Includes
#include "FSecISecretKeyGenerator.h"
#include "FSecISecureRandom.h"


namespace Osp {namespace Security {

class ISecureRandom;
/**
 *	@class		SecretKeyGenerator 
 *	@brief		This class is used for generating a secret (symmetric) key.
 *  @since 		1.0
 *
 *  The %SecretKeyGenerator class generates a secret key, which is used in symmetric ciphers. The generated secret key is based on an encryption algorithm.
 *
 *	@see ISecretKeyGenerator
 */
class _EXPORT_SECURITY_ SecretKeyGenerator:
	public virtual ISecretKeyGenerator, 
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class.
	 *
	 * 	@since 		1.0
	 */	
	SecretKeyGenerator(void);


	/** 
	 *	This is the destructor for this class. 
	 *
	 * 	@since 		1.0
	 */	
	~SecretKeyGenerator(void);


// Operation
public:
	/** 
	 *	Initializes this instance of SecretKeyGenerator with the specified key.
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@param[in]	keyBytes				The key of type %ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c keyBytes is invalid or an empty ByteBuffer.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result	Construct(const Osp::Base::ByteBuffer& keyBytes);


	/** 
	 *	Initializes this instance of SecretKeyGenerator for the specified algorithm.
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@param[in]  algorithm				The name of the secure random generator algorithm @n
	 *										For example, "AES","DES" or "3DES".
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c algorithm is invalid or an empty String.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Construct(const Osp::Base::String& algorithm);


	/** 
	 *	Initializes this instance of SecretKeyGenerator with the specified key size. @n
	 *	The default algorithm is Advanced Encryption Standard (AES).
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@param[in]	keySize					The key size
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c keySize is @c 0 or negative.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Construct(int keySize);


	/** 
	 *	Gets the newly generated secret key.
	 *
	 * 	@since 		1.0
	 *	@return		A pointer to %ISecretKey, @n
	 *				else @c null if it fails to generate a secret key
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM  				A system error has occurred.
	 */
	virtual Osp::Security::ISecretKey* GenerateKeyN(void);


// Attribute
private:
	Osp::Base::String m_algorithm;
	static const int _DEFAULT_KEY_SIZE = 16;
	int	__keyGenSize;
	Osp::Security::ISecureRandom	*__pRandom;
	Osp::Base::ByteBuffer			m_keyBytes;
	
	int								m_keySize;
	friend class 	SecretKeyGeneratorEx;
	class SecretKeyGeneratorEx*	__pSecretKeyGeneratorEx;
};
}; }; // Osp::Security
#endif// _FSEC_SECRET_KEY_GENERATOR_H_
