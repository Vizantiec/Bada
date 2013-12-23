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
 * @file		FSecCryptoMd5Hmac.h
 * @brief		This is the header file for the %Md5Hmac class.
 * 
 * This header file contains the declarations of the %Md5Hmac class.
 */
#ifndef _FSEC_CRYPTO_MD5_HMAC_H
#define _FSEC_CRYPTO_MD5_HMAC_H

// Includes
#include "FSecCryptoIHmac.h"


namespace Osp { namespace Security { namespace Crypto {

class IHmacPi;

/**
 *	@class		Md5Hmac 
 *	@brief		This class implements the MD5 HMAC algorithm.
 *	@since		1.0
 *
 *  The %Md5Hmac class implements the basic hash procedure to encrypt messages using the Hash Message Authentication Code (HMAC) algorithm, which provides a hash with a secret key.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/hashing.htm">Hashing</a>.

 *	@see	IHmac, Sha1Hmac, Sha2Hmac
 */
class _EXPORT_SECURITY_ Md5Hmac :
	public virtual IHmac,
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class.
	 *
	 * 	@since 		1.0
	 */
	Md5Hmac(void);


	/** 
	 *	This is the destructor for this class. 
	 *
	 * 	@since 		1.0
	 */	
	~Md5Hmac(void);


// Operation
public:
	/** 
	 *	Sets the HMAC algorithm. @n
	 *  This method is not supported by this class. Do not call this method.
	 *  If this method is called, it returns E_UNSUPPORTED_ALGORITHM.
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@param[in]	algorithm				The name of the HMAC algorithm @n
	 *										For example, "HMACSHA2/224", "HMACSHA2/256", "HMACSHA2/386", or "HMACSHA2/512".
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The algorithm is not supported.
	 *
	 *  @remarks 		Do not call this method. It is not supported.
	 */	
	virtual result	SetAlgorithm(const Osp::Base::String& algorithm);


	/** 
	 *	Sets the secret key.
	 *  
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@param[in]	key						An instance of %ISecretKey
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified key is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result SetKey(const Osp::Security::ISecretKey& key);


	/** 
	 *	Gets the HMAC with the specified input.
	 *  
	 * 	@since 		1.0
	 *	@return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *  @param[in]	input					An instance of %ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 */
	virtual Osp::Base::ByteBuffer*	GetHmacN(const Osp::Base::ByteBuffer& input);


	/** 
	 *	Initializes a multiple-part HMAC operation.
	 *  
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@exception	E_SUCCESS				The method is successful.
 	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 */
	virtual result	Initialize(void);


	/** 
	 *	Continues a multiple-part HMAC operation, processing another data part.
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *  @param[in]	input					An instance of %ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE			The state is invalid.
	 *	@exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	virtual result	Update(const Osp::Base::ByteBuffer& input);


	/** 
	 *	Finishes a multiple-part HMAC operation.
	 *  
	 * 	@since 		1.0
	 *	@return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE			The state is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	virtual Osp::Base::ByteBuffer*	FinalizeN(void);


// Attribute
private:
	IHmacPi			*m_pIHmacPi;
	friend class		Md5HmacEx;
	class Md5HmacEx*	__pMd5HmacEx;	
};
};}; };// Osp::Security::Crypto

#endif //_FSEC_CRYPTO_MD5_HMAC_H

