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
 * @file		FSecIKey.h
 * @brief		This is the header file for the %IKey interface.
 *
 * This header file contains the declarations of the %IKey interface. 
 */
#ifndef _FSEC_IKEY_H_
#define _FSEC_IKEY_H_

// Includes
#include "FBaseString.h"
#include "FBaseByteBuffer.h"
#include "FSecConfig.h"


namespace Osp {namespace Security {
/**
 * @interface	IKey 
 * @brief		 This interface provides methods that help in setting the buffer for the key. These methods also extract the encoding format of the key.
 * @since		1.0
 *
 * The %IKey interface provides methods that help in setting the buffer for the key. These methods also extract the encoding format of the key.
 *
 * @see	Osp::Security::IPrivateKey, Osp::Security::IPublicKey, Osp::Security::ISecretKey, Osp::Security::PrivateKey, Osp::Security::PublicKey, Osp::Security::SecretKey
 */

class _EXPORT_SECURITY_ IKey
{
// Operation
public:
	/** 
	 *	This is the destructor for this class.
	 *
	 * 	@since 		1.0
	 */
	virtual ~IKey(void){};


	/** 
	 * Gets the name of the primary encoding format of the key.
	 *
	 * @since 		1.0
	 * @return		The primary encoding format of the key
	 */
	virtual Osp::Base::String	GetFormat(void) const = 0;


	/** 
	 * Gets the key in its primary encoding format.
	 *
	 * @since 		1.0
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM  			A system error has occurred.
	 */
	virtual Osp::Base::ByteBuffer*	GetEncodedN(void) const = 0;


	/** 
	 * Sets the key buffer.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	keyBuffer			An instance of %ByteBuffer
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG  		The specified @c keyBuffer is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM  			A system error has occurred.
	 */
	virtual result SetKey(const Osp::Base::ByteBuffer& keyBuffer) = 0;


};
}; }; // Osp::Security
#endif// _FSEC_IKEY_H_
