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
 * @file		FSecSecretKey.h
 * @brief		This is the header file for the %SecretKey class.
 *
 * This header file contains the declarations of the %SecretKey class.
 */
#ifndef _FSEC_SECRET_KEY_H_
#define _FSEC_SECRET_KEY_H_

// Includes
#include "FSecIKey.h"
#include "FSecISecretKey.h"


namespace Osp {namespace Security {

class ISecretKeyPi;
/**
 *	@class		SecretKey 
 *	@brief		This class specifies a secret key.
 *  @since 		1.0
 *
 *  The %SecretKey class manages a secret key, which is used in symmetric ciphers, such as Advanced Encryption Standard (AES), Data Encryption Standard (DES), and Triple Data Encryption Standard (3DES).
 *
 *  For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/key_mgmt_and_csprng.htm">Key Management and CSPRNG</a>.

 *
 *	@see	    IKey, ISecretKey, SecretKeyGenerator, ISecretKeyGenerator
 */

class _EXPORT_SECURITY_ SecretKey :
	public virtual ISecretKey,
	public Osp::Base::Object
{
public:
	// Friend class SecretKeyGenerator;


// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class.
	 *
	 * 	@since 		1.0
	 */	
	SecretKey(void);


	/** 
	 *	This is the destructor for this class. 
	 *
	 * 	@since 		1.0
	 */	
	~SecretKey(void);


// Operation
public:
	/** 
	 *	Gets the name of the primary encoding format of the current instance of %SecretKey.
	 *
	 * 	@since 		1.0
	 *	@return		The primary encoding format of the key
	 */
	virtual Osp::Base::String GetFormat(void) const;


	/** 
	 *	Gets the secret key in its primary encoding format.
	 *
	 * 	@since 		1.0
	 *	@return		A pointer to the %ByteBuffer class, @n
	 *				else @c null if an error occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual Osp::Base::ByteBuffer*	GetEncodedN(void) const;


	/**
	 *	Sets the secret key buffer.
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *  @param[in]	keyBuffer				An instance of %ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG  			The specified @c keyBuffer is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result	SetKey(const Osp::Base::ByteBuffer& keyBuffer);


// Attribute
private:
	ISecretKeyPi	*m_pSecretKeyPi;
	friend class 	SecretKeyEx;
	class SecretKeyEx*	__pSecretKeyEx;
};
}; }; // Osp::Security

#endif// _FSEC_SECRET_KEY_H_
