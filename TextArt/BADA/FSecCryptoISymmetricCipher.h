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
 * @file		FSecCryptoISymmetricCipher.h
 * @brief		This is the header file for the %ISymmetricCipher interface.
 *
 * This header file contains the declarations of the %ISymmetricCipher interface.
 */
#ifndef _FSEC_CRYPTO_ISYMMETRIC_CIPHER_H
#define _FSEC_CRYPTO_ISYMMETRIC_CIPHER_H

// Includes
#include "FBaseString.h"
#include "FBaseByteBuffer.h"
#include "FSecISecretKey.h"
#include "FSecCryptoTypes.h"


namespace Osp { namespace Security { namespace Crypto {
/**
 * @interface	ISymmetricCipher
 * @brief		This interface provides the functionalities of a symmetric cryptographic cipher for encryption and decryption.
 * @since 		1.0
 *
 * The %ISymmetricCipher interface provides the functionalities of a symmetric cryptographic cipher for encryption and decryption.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/ciphers.htm">Ciphers</a>.
 *
 * The following example demonstrates how to use the %ISymmetricCipher interface.
 * @code
 *
 *	void
 *	MyClass::TestSymmetricCipherSample(void)
 *	{
 *		// #####AES CBC Test Vector(128-bits key)#####
 *	// PlainText: 48 Bytes
 *	const int messageLen	= 48;
 *	static const byte message[messageLen] = {
 *		0x87, 0x3C, 0x66, 0x1D, 0x2C, 0x0D, 0x49, 0x2D,
 *		0x6C, 0x76, 0xBE, 0x44, 0x57, 0x39, 0xB8, 0x28,
 *		0x84, 0x5E, 0x2A, 0x15, 0x18, 0x3B, 0x1D, 0x00,
 *		0xA7, 0x6E, 0x80, 0x4D, 0x22, 0xF1, 0x2A, 0x6B,
 *		0xBA, 0xFE, 0xA8, 0x02, 0x2B, 0xC2, 0x97, 0x01,
 *		0x59, 0x0F, 0x3C, 0x2A, 0x67, 0x8B, 0x98, 0x69
 *	};
 *
 *	// CipherText: 48 Bytes
 *	const int cipherLen	= 48;
 *	static const byte cipher[cipherLen] = {
 *		0x10, 0x84, 0x9D, 0x24, 0xEB, 0x22, 0xE0, 0x7F,
 *		0xA8, 0x57, 0xE9, 0xA0, 0x4F, 0xE2, 0x3D, 0xE5,
 *		0xC1, 0x51, 0x7E, 0xEB, 0xF8, 0xB3, 0x3A, 0xA2,
 *		0xDC, 0xF4, 0x8B, 0xDC, 0x14, 0x0A, 0xC7, 0x58,
 *		0x85, 0x6B, 0x0D, 0xE9, 0x30, 0x8B, 0xA1, 0x71,
 *		0xD5, 0x0B, 0x14, 0x97, 0xEF, 0xAD, 0x22, 0x8D
 *	};
 *
 *	// KEY: 16Bytes
 *	const int secretKeyLen	= 16;
 *	static const byte secretKey[secretKeyLen] = {
 *		0x62, 0x5C, 0xC7, 0x7E, 0xEA, 0x7B, 0xA5, 0x4D,
 *		0x47, 0xCE, 0xAF, 0x26, 0x9E, 0xB1, 0x6C, 0x2D
 *	};
 *
 *	// IV: 16Bytes
 *	const int ivectorLen	= 16;
 *	static const byte ivector[ivectorLen] = {
 *		0x3E, 0xB5, 0x01, 0x45, 0xE4, 0xF8, 0x75, 0x3F,
 *		0x08, 0x9D, 0x9F, 0x57, 0x3B, 0x63, 0xEF, 0x4B
 *	};
 *
 *		result r = E_FAILURE;
 *		String transformation;
 *		ISymmetricCipher	*pCipherEnc	= null;
 *		ISymmetricCipher	*pCipherDec	= null;
 *		SecretKeyGenerator	*pKeyGen	= null;
 *		ISecretKey			*pKey		= null;
 *		ByteBuffer			input;
 *		ByteBuffer			*pOutput	= null;
 *		ByteBuffer			*pOutput2	= null;
 *		ByteBuffer			keyBytes;
 *		ByteBuffer			iv;
 *
 *		// input
 *		input.Construct(messageLen);
 *		input.SetArray(message, 0, messageLen);
 *		input.Flip();
 *
 *		// key
 *		keyBytes.Construct(secretKeyLen);
 *		keyBytes.SetArray(secretKey, 0, secretKeyLen);
 *		keyBytes.Flip();
 *
 *		// IV setting
 *		iv.Construct(ivectorLen);
 *		iv.SetArray(ivector, 0, ivectorLen);
 *		iv.Flip();
 *
 *		pCipherEnc = new AesCipher();
 *		if(pCipherEnc == null)
 *			goto CATCH;
 *
 *		transformation  = "CBC/128/NOPADDING";
 *
 *		r = pCipherEnc->Construct(transformation, CIPHER_ENCRYPT);
 *		if (IsFailed(r))
 *			goto CATCH;
 *
 *		// Generates the key.
 *		pKeyGen = new SecretKeyGenerator();
 *		if (pKeyGen == null)
 *			goto CATCH;
 *
 *		r = pKeyGen->Construct(keyBytes);
 *		if (IsFailed(r))
 *			goto CATCH;
 *
 *		pKey = pKeyGen->GenerateKeyN();
 *		if (pKey == null)
 *			goto CATCH;
 *
 *		r = pCipherEnc->SetKey(*pKey);
 *		if (IsFailed(r))
 *			goto CATCH;
 *
 *		r = pCipherEnc->SetInitialVector(iv);
 *		if (IsFailed(r))
 *			goto CATCH;
 *
 *		pOutput = pCipherEnc->EncryptN(input);
 *		if (pOutput == null)
 *		{
 *			r = GetLastResult();
 *			goto CATCH;
 *		}
 *
 *		pCipherDec = new AesCipher();
 *		if(pCipherDec == null)
 *			goto CATCH;
 *
 *		r = pCipherDec->Construct(transformation, CIPHER_DECRYPT);
 *		if (IsFailed(r))
 *			goto CATCH;
 *
 *		r = pCipherDec->SetKey(*pKey);
 *		if (IsFailed(r))
 *			goto CATCH;
 *
 *		r = pCipherDec->SetInitialVector(iv);
 *		if (IsFailed(r))
 *			goto CATCH;
 *
 *		pOutput2 = pCipherDec->DecryptN(*pOutput);
 *		if (pOutput2 == null)
 *		{
 *			r = GetLastResult();
 *			goto CATCH;
 *		}
 *
 *		if (memcmp(pOutput->GetPointer(), cipher, cipherLen) != 0)
 *			goto CATCH;
 *
 *		if (memcmp(pOutput2->GetPointer(), input.GetPointer(), input.GetRemaining()) != 0)
 *			goto CATCH;
 *
 *		r = E_SUCCESS;
 *
 *	CATCH:
 *		delete pCipherEnc;
 *		delete pCipherDec;
 *		delete pKeyGen;
 *		delete pOutput;
 *		delete pOutput2;
 *		delete pKey;
 *	}
 *
 *  @endcode
 *
 *
 */
class _EXPORT_SECURITY_ ISymmetricCipher {


// Operation
public:
	/** 
	 *	This is the destructor for this class.
	 *
	 * 	@since 		1.0
	 */
	virtual ~ISymmetricCipher(void) {}


	/**
	 * Initializes this instance of ISymmetricCipher with the specified operation mode and padding scheme.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	transformation			The name of the requested mode or key bit or padding scheme
	 * @param[in]	opMode					The cipher operation mode @n
	 *										For example, CIPHER_ENCRYPT, CIPHER_DECRYPT, CIPHER_WRAP, or CIPHER_UNWRAP.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c opMode does not contain a valid value for the cipher operation.
	 * @exception	E_UNSUPPORTED_ALGORITHM	The algorithm is not supported.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result	Construct(const Osp::Base::String& transformation, enum CipherOperation opMode = Osp::Security::Crypto::CIPHER_ENCRYPT) = 0;


	/**
	 * Sets a symmetric key for encryption or decryption.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	key					An instance of %ISecretKey
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c key is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual result	SetKey(const Osp::Security::ISecretKey& key) = 0;


	/**
	 * Sets the initial vector.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	initialVector		The initial vector
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual result	SetInitialVector(const Osp::Base::ByteBuffer& initialVector) = 0;


	/**
	 * Encrypts the data (single-part).
	 *
	 * @since 		1.0
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @param[in]	input					An instance of %ByteBuffer
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_KEY_NOT_FOUND			The key is not found.
	 * @exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 * @exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	virtual Osp::Base::ByteBuffer*	EncryptN(const Osp::Base::ByteBuffer& input) = 0;


	/**
	 * Decrypts the data (single-part).
	 *
	 * @since 		1.0
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @param[in]	input					An instance of %ByteBuffer
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_KEY_NOT_FOUND			The key is not found.
	 * @exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 * @exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	virtual Osp::Base::ByteBuffer*	DecryptN(const Osp::Base::ByteBuffer& input) = 0;


	/**
	 * Initializes a multiple-part encryption or decryption operation.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_KEY_NOT_FOUND			The key is not found.
	 * @exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result	Initialize(void) = 0;


	/**
	 * Updates a multiple-part encryption or decryption operation.
	 *
	 * @since 		1.0
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @param[in]	input				An instance of %ByteBuffer
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OVERFLOW			This operation has caused the memory to overflow.
	 * @exception	E_INVALID_ARG		The input %ByteBuffer is empty or contains invalid data.
	 * @exception	E_INVALID_STATE		The state is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer*	UpdateN(const Osp::Base::ByteBuffer& input) = 0;


	/**
	 * Finalizes a multiple-part encryption or decryption operation.
	 *
	 * @since 		1.0
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OVERFLOW			This operation has caused the memory to overflow.
	 * @exception	E_INVALID_STATE		The state is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer*	FinalizeN(void) = 0;


	/**
	 * Wraps the specified key.
	 *
	 * @since 		1.0
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @param[in]	secretKey				The secret key to be wrapped
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_KEY_NOT_FOUND			The key is not found.
	 * @exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		This operation is only supported in AesCipher.
	 */
	virtual Osp::Base::ByteBuffer*	WrapN(const Osp::Base::ByteBuffer& secretKey) = 0;


	/**
	 * Unwraps a previously wrapped key.
	 *
	 * @since 		1.0
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @param[in]	wrappedKey				The wrapped key to unwrap
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c wrappedKey ByteBuffer is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_KEY_NOT_FOUND			The key is not found.
	 * @exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		This operation is only supported in AesCipher.
	 */
	virtual Osp::Base::ByteBuffer*	UnwrapN(const Osp::Base::ByteBuffer& wrappedKey) = 0;


};
};}; };// Osp::Security::Crypto

#endif //_FSEC_CRYPTO_ISYMMETRIC_CIPHER_H

