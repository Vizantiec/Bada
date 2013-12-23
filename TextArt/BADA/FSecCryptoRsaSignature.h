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
 * @file		FSecCryptoRsaSignature.h 
 * @brief		This is the header file for the %RsaSignature class.
 *
 * This header file contains the declarations of the %RsaSignature class.
 */
#ifndef _FSEC_CRYPTO_RSA_SIGNATURE_H
#define _FSEC_CRYPTO_RSA_SIGNATURE_H

// Includes
#include "FSecCryptoISignature.h"


namespace Osp { namespace Security { namespace Crypto {

class IAsymmetricCipherPi;
/**
 *	@class		RsaSignature 
 *	@brief		This class implements the Rivest Shamir Adleman (RSA) signatures.
 *	@since		1.0
 *
 * The %RsaSignature class implements the Rivest Shamir Adleman (RSA) signatures.
 *	@see ISignature, IKeyPairGenerator, KeyPair, IPublicKey, IPrivateKey, PublicKey, PrivateKey
 */
class _EXPORT_SECURITY_ RsaSignature :
	public virtual ISignature,
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class.
	 *
	 * 	@since 		1.0
	 */	
	RsaSignature(void);


	/** 
	 *	This is the destructor for this class.
	 *
	 * 	@since 		1.0
	 */	
	~RsaSignature(void);


// Operation
public:
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
	virtual result SetPrivateKey(const Osp::Security::IKey& key);


	/** 
	 *	Sets an asymmetric public key for verification.
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@param[in]	key						An instance of %IKey
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified key is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result SetPublicKey(const Osp::Security::IKey& key);


	/**
	 *	Signs the data.
	 *
	 * 	@since 		1.0
	 *	@return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				 else @c null if an error occurs
	 *  @param[in]	input					An instance of %ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_INVALID_STATE			The initial vector is not set.
	 *	@exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual Osp::Base::ByteBuffer*	SignN(const Osp::Base::ByteBuffer& input);


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
	virtual bool	Verify(const Osp::Base::ByteBuffer& data, const Osp::Base::ByteBuffer& signedData);


// Attribute
private:
	IAsymmetricCipherPi	*m_pIAsymmPi;
	friend class		RsaSignatureEx;
	class RsaSignatureEx*	__RsaSignatureEx;


};
};}; };// Osp::Security::Crypto

#endif //_FSEC_CRYPTO_RSA_SIGNATURE_H
