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
 * @file		FSecCryptoIAsymmetricCipher.h 
 * @brief		This is the header file for the %IAsymmetricCipher interface.
 *
 * This header file contains the declarations of the %IAsymmetricCipher interface.
 */
#ifndef _FSEC_CRYPTO_IASYMMETRIC_CIPHER_H
#define _FSEC_CRYPTO_IASYMMETRIC_CIPHER_H

// Includes
#include "FBaseString.h"
#include "FBaseByteBuffer.h"
#include "FSecIKey.h"
#include "FSecIPublicKey.h"
#include "FSecIPrivateKey.h"
#include "FSecCryptoTypes.h"

namespace Osp { namespace Security { namespace Crypto {

/**
 *	@interface	IAsymmetricCipher 
 *	@brief		This interface provides the functionality of an asymmetric cryptographic cipher for encryption and decryption.
 * 	@since 		1.0
 *
 * The %IAsymmetricCipher interface provides the functionality of an asymmetric cryptographic cipher for encryption and decryption.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/ciphers.htm">Ciphers</a>.
 *
 *	 The following example demonstrates how to use the %IAsymmetricCipher interface.
 *
 *  @code
 *
 *	void
 *	MyClass::TestAsymmetricCipherSample(void)
 *	{
 *		result r = E_FAILURE;
 * 		IAsymmetricCipher *pCipher = null;
 *		IKeyPairGenerator *pKeyPairGen = null;
 *		KeyPair *pKeyPair = null;
 *		IPrivateKey *pPriKey = null;
 *		IPublicKey *pPubKey = null;
 *		ByteBuffer input;
 *		ByteBuffer *pOutput = null;
 *		ByteBuffer *pDecOutput = null;
 *		ByteBuffer keyBytes;
 *		ByteBuffer iv;
 *		byte pArray[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
 *		int size = 1024;
 *	
 *		r = input.Construct(16);
 *		r = input.SetArray(pArray, 0, 16);
 *		input.Flip();
 *	
 *		pCipher = new RsaCipher();
 *		if(pCipher == null)
 *			goto CATCH;
 *	
 *		// Generates the key.
 *		pKeyPairGen = new KeyPairGenerator();
 *		if(pKeyPairGen == null)
 *			goto CATCH;
 *	
 *		r = pKeyPairGen->Construct(size);
 *		if (IsFailed(r))
 *			goto CATCH;
 *	
 *		pKeyPair = pKeyPairGen->GenerateKeyPairN();
 *		if(pKeyPair == null)
 *			goto CATCH;
 *	
 *		pPubKey = pKeyPair->GetPublicKey();
 *		if(pPubKey == null)
 *			goto CATCH;
 *	
 *		pPriKey = pKeyPair->GetPrivateKey();
 *		if(pPriKey == null)
 *			goto CATCH;
 *	
 *		r = pCipher->SetPublicKey(*pPubKey);
 *		if (IsFailed(r))
 *			goto CATCH;
 *	
 *		pOutput = pCipher->EncryptN(input);
 *		if (pOutput == null)
 *		{
 *			r = GetLastResult();
 *			goto CATCH;
 *		}
 *	
 *		r = pCipher->SetPrivateKey(*pPriKey);
 *		if (IsFailed(r))
 *			goto CATCH;
 *	
 *		pDecOutput = pCipher->DecryptN(*pOutput);
 *		if (pDecOutput == null)
 *		{
 *			r = GetLastResult();
 *			goto CATCH;
 *		}
 *	
 *		if (memcmp(pDecOutput->GetPointer(), input.GetPointer(), input.GetRemaining()) != 0)
 *			goto CATCH;
 *
 *		r	= E_SUCCESS;
 *
 *	CATCH:
 *		delete pCipher;
 *		delete pOutput;
 *		delete pDecOutput;
 *		delete pKeyPairGen;
 *		delete pKeyPair;
 *	}
 *	
 *  @endcode
 */
class _EXPORT_SECURITY_ IAsymmetricCipher 
{

// Operation
public:

	/** 
	 *	This is the destructor for this class.
	 *
	 * 	@since 		1.0
	 */
	virtual ~IAsymmetricCipher(void) {}


	/** 
	 *	Sets an asymmetric private key for encryption or decryption.
	 *
	 * 	@since 			1.0
	 *	@return			An error code
	 *	@param[in]	key						An instance of %IKey
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified key is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result SetPrivateKey(const Osp::Security::IKey& key) = 0;


	/** 
	 *	Sets an asymmetric public key for encryption or decryption.
	 *
	 * 	@since 			1.0
	 *	@return			An error code
	 *	@param[in]	key						An instance of %IKey
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified key is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result SetPublicKey(const Osp::Security::IKey& key) = 0;


	/** 
	 *	Encrypts the data (single-part).  
	 *  
	 * 	@since 			1.0
	 *	@return			A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *  @param[in]	input					The input %ByteBuffer instance
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The algorithm is not supported.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual Osp::Base::ByteBuffer*	EncryptN(const Osp::Base::ByteBuffer& input) = 0;


	/** 
	 *	Decrypts the data (single-part).   
	 *  
	 * 	@since 			1.0
	 *	@return			A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *  @param[in]	input					The input %ByteBuffer instance
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The algorithm is not supported.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual Osp::Base::ByteBuffer*	DecryptN(const Osp::Base::ByteBuffer& input) = 0;


};
};}; };// Osp::Security::Crypto

#endif //_FSEC_CRYPTO_IASYMMETRIC_CIPHER_H

