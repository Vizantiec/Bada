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
 * @file		FSecCryptoISignature.h 
 * @brief		This is the header file for the %ISignature interface. 
 *
 * This header file contains the declarations of the %ISignature interface.
 */
#ifndef _FSEC_CRYPTO_ISIGNATURE_H
#define _FSEC_CRYPTO_ISIGNATURE_H

// Includes
#include "FBaseString.h"
#include "FBaseByteBuffer.h"
#include "FSecConfig.h"
#include "FSecIKey.h"


namespace Osp { namespace Security { namespace Crypto {

/**
 *	@interface	ISignature 
 *	@brief		This interface provides the functionality of a digital signature algorithm.
 * 	@since 		1.0
 *
 * The %ISignature interface provides the functionality of a digital signature algorithm.
 *
 *  The following example demonstrates how to use the %ISignature interface.
 *  
 *  @code
 *
 *   void
 *   MyClass::TestSignatureSample(void)
 *   {
 * 		result r = E_FAILURE;
 * 		ISignature *pSignature = null;
 * 		IKeyPairGenerator *pKeyPairGen = null;
 * 		KeyPair *pKeyPair = null;
 * 		IPrivateKey *pPriKey = null;
 * 		IPublicKey *pPubKey = null;
 * 		ByteBuffer input;
 * 		ByteBuffer *pOutput = null;
 * 		ByteBuffer keyBytes;
 * 		ByteBuffer iv;
 * 		byte pArray[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
 * 		int size = 1024;
 * 		bool res = false;
 *
 * 		r = input.Construct(16);
 * 		r = input.SetArray(pArray, 0, 16);
 * 		input.Flip();
 *
 * 		pSignature = new RsaSignature();
 * 		if(pSignature == null)
 * 			goto CATCH;
 *
 * 		// Generates the Key.
 * 		pKeyPairGen = new KeyPairGenerator();
 * 		if(pKeyPairGen == null)
 * 			goto CATCH;
 *
 * 		r = pKeyPairGen->Construct(size);
 * 		if (IsFailed(r))
 * 			goto CATCH;
 *
 * 		pKeyPair = pKeyPairGen->GenerateKeyPairN();
 * 		if(pKeyPair == null)
 * 			goto CATCH;
 *
 * 		pPubKey = pKeyPair->GetPublicKey();
 * 		if(pPubKey == null)
 * 			goto CATCH;
 *
 * 		pPriKey = pKeyPair->GetPrivateKey();
 * 		if(pPriKey == null)
 * 			goto CATCH;
 *
 * 		r = pSignature->SetPrivateKey(*pPriKey);
 * 		if (IsFailed(r))
 * 			goto CATCH;
 *
 * 		pOutput = pSignature->SignN(input);
 * 		if (pOutput == null)
 * 		{
 * 			r = GetLastResult();
 * 			goto CATCH;
 * 		}
 *
 * 		r = pSignature->SetPublicKey(*pPubKey);
 * 		if (IsFailed(r))
 * 			goto CATCH;
 *
 * 		res = pSignature->Verify(input, *pOutput);
 * 		if (res == false)
 * 		{
 * 			r = GetLastResult();
 * 			goto CATCH;
 * 		}
 *
 * 		r	= E_SUCCESS;
 *
 * 	CATCH:
 * 		delete pSignature;
 * 		delete pOutput;
 * 		delete pKeyPairGen;
 * 		delete pKeyPair;
 *   }
 *	
 *  @endcode
 */
class _EXPORT_SECURITY_ ISignature
{
// Operation
public:

	/** 
	 *	This is the destructor for this class.
	 *
	 * 	@since 		1.0
	 */
	virtual ~ISignature(void) {}


	/** 
	 *	Sets an asymmetric private key for signature.
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@param[in]	key						An instance of %IKey
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c key is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result SetPrivateKey(const Osp::Security::IKey& key) = 0;


	/** 
	 *	Sets an asymmetric public key for verification.
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@param[in]	key						An instance of %IKey
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c key is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result SetPublicKey(const Osp::Security::IKey& key) = 0;


	/** 
	 *	Signs the data.
	 *
	 * 	@since 		1.0
	 *	@return		A pointer to the %ByteBuffer that contains the output, @n
	 *				else @c null if an error occurs
	 *  @param[in]	input					An instance of %ByteBuffer 
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_INVALID_STATE			The initial vector is not set.
	 *	@exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual Osp::Base::ByteBuffer*	SignN(const Osp::Base::ByteBuffer& input) = 0;


	/** 
	 *	Verifies the data. @n
	 *  The verification is done by comparing the @c signedData to the signature created by the @c data. 
	 *
	 * 	@since 		1.0
	 *	@return		@c true if the signed data is correct, @n
	 *				else @c false
	 *  @param[in]	data					A %ByteBuffer instance that contains the original data
	 *  @param[in]	signedData				A %ByteBuffer instance that contains the signed data
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_INVALID_STATE			The initial vector is not set.
	 *	@exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual bool	Verify(const Osp::Base::ByteBuffer& data, const Osp::Base::ByteBuffer& signedData) = 0;

};
};}; };// Osp::Security::Crypto

#endif //_FSEC_CRYPTO_ISIGNATURE_H

