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
 * @file		FSecIPublicKey.h
 * @brief		This is the header file for the %IPublicKey interface.
 *
 * This header file contains the declarations of the %IPublicKey interface. 
 */
#ifndef _FSEC_IPUBLIC_KEY_H_
#define _FSEC_IPUBLIC_KEY_H_

// Includes
#include "FSecIKey.h"


namespace Osp { namespace Security {
/**
 * @interface	IPublicKey 
 * @brief		This interface provides the functionality shared by all the public key instances.
 * @since 		1.0
 *
 * The %IPublicKey interface provides the functionality shared by all the public key instances.
 */
class _EXPORT_SECURITY_ IPublicKey :
	public virtual IKey
{
public:
	/** 
	 *	This is the destructor for this class.
	 *
	 * 	@since 		1.0
	 */
	virtual ~IPublicKey(void){};


	/** 
	 * Gets the name of the primary encoding format of this key.
	 *
	 * @since 		1.0
	 * @return		The primary encoding format of the key
	 */
	 virtual Osp::Base::String	GetFormat(void) const = 0;


	/** 
	 * Gets the public key in its primary encoding format.
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
	 * Sets the public key buffer.
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


#endif//_FSEC_IPUBLIC_KEY_H_
