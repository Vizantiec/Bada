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
 * @file		FSecCryptoSha2Hmac.h
 * @brief		This is the header file for the %Sha2Hmac class.
 *
 * This header file contains the declarations of the %Sha2Hmac class.
 */
#ifndef _FSEC_CRYPTO_SHA2_HMAC_H
#define _FSEC_CRYPTO_SHA2_HMAC_H

// Includes
#include "FSecCryptoIHmac.h"


namespace Osp { namespace Security { namespace Crypto {

class IHmacPi;
/**
 * @class	Sha2Hmac 
 * @brief	This class implements the SHA-2 HMAC algorithm.
 * @since	1.0
 * 
 * The %Sha2Hmac class implements the SHA-2 HMAC algorithm.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/hashing.htm">Hashing</a>.
 *			
 * @see		Osp::Security::Crypto::IHmac, Osp::Security::Crypto::Md5Hmac, Osp::Security::Crypto::Sha1Hmac
 */
class _EXPORT_SECURITY_ Sha2Hmac :
	public virtual IHmac,
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	Sha2Hmac(void);


	/** 
	 * This is the destructor for this class.
	 *
	 * @since 	1.0
	 */	
	~Sha2Hmac(void);


// Operation
public:
	/** 
	 * Sets the HMAC algorithm.
	 *  
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	algorithm				The name of the HMAC algorithm @n
	 *										For example, "HMACSHA2/224", "HMACSHA2/256", "HMACSHA2/386", or "HMACSHA2/512".
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_ALGORITHM	The algorithm is not supported.
	 */	
	virtual result	SetAlgorithm(const Osp::Base::String& algorithm);


	/** 
	 * Sets the secret key.
	 *  
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	key					An instance of %ISecretKey
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified key is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual result SetKey(const Osp::Security::ISecretKey& key);


	/** 
	 * Gets the HMAC with the given input.
	 *  
	 * @since 		1.0
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @param[in]	input				An instance of %ByteBuffer
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The input %ByteBuffer is empty or contains invalid data.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_KEY_NOT_FOUND		The specified key is not found.
	 */
	virtual Osp::Base::ByteBuffer*	GetHmacN(const Osp::Base::ByteBuffer& input);


	/** 
	 * Initializes the multiple-part HMAC operation.
	 *  
	 * @since 		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
 	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_KEY_NOT_FOUND		The specified key is not found.
	 */
	virtual result	Initialize(void);


	/** 
	 * Updates the multiple-part HMAC operation whilst processing another part of the data.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	input				An instance of %ByteBuffer
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		The state is invalid.
	 * @exception	E_INVALID_ARG		The input %ByteBuffer is empty or contains invalid data.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	virtual result	Update(const Osp::Base::ByteBuffer& input);


	/** 
	 * Finalizes the multiple-part HMAC operation.
	 *  
	 * @since 		1.0
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		The state is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	virtual Osp::Base::ByteBuffer*	FinalizeN(void);


// Attribute
private:
	IHmacPi			*m_pIHmacPi;
	friend class 		Sha2HmacEx;
	class	Sha2HmacEx*	__pSha2HmacEx;

};
};}; };// Osp::Security::Crypto

#endif //_FSEC_CRYPTO_SHA2_HMAC_H

