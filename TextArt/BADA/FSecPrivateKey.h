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
 * @file		FSecPrivateKey.h
 * @brief		This is the header file for the %PrivateKey class.
 *
 * This header file contains the declarations of the %PrivateKey class.
 */
#ifndef _FSEC_PRIVATE_KEY_H_
#define _FSEC_PRIVATE_KEY_H_

// Includes
#include "FSecIKey.h"
#include "FSecIPrivateKey.h"


namespace Osp { namespace Security {

class IPrivateKeyPi;
/**
 *	@class		PrivateKey 
 *	@brief		This class specifies the RSA private key.
 *  @since 		1.0
 *
 *  The %PrivateKey class manages a private key, which is used in asymmetric ciphers. The RSA algorithm decrypts the data using the private key.
 *
 *  For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/cryptography.htm">Cryptography</a>.

 *
 *	@see	IKey, IPrivateKey, IKeyPairGenerator
 */

class _EXPORT_SECURITY_ PrivateKey :
	public virtual IPrivateKey,
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class.
	 *
	 * 	@since 		1.0
	 */
	PrivateKey(void);


	/** 
	 *	This is the destructor for this class.
	 *
	 * 	@since 		1.0
	 */
	virtual ~PrivateKey(void);


// Operation
public:
	/** 
	 *	Gets the name of the primary encoding format of the current instance of %PrivateKey.
	 *
	 * 	@since 		1.0
	 *	@return		The primary encoding format of the key
	 */
	virtual Osp::Base::String	GetFormat(void) const;


	/** 
	 *	Gets the private key in its primary encoding format.
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
	 *	Sets the private key buffer.
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@param[in]	keyBuffer				An instance of %ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG  			The specified @c keyBuffer is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result SetKey(const Osp::Base::ByteBuffer& keyBuffer);


// Attribute
private:
	Osp::Base::String	m_algorithm;
	Osp::Base::String	m_encodedFormat;
	IPrivateKeyPi		*m_pPriKeyPi;
	friend class 		PrivateKeyEx;
	class PrivateKeyEx*	__pPrivateKeyEx;
};
}; }; // Osp::Security


#endif//_FSEC_PRIVATE_KEY_H_

