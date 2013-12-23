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
 * @file		FSecCryptoTypes.h
 * @brief		This is the header file that defines the different enumerations.
 *
 * This is the header file that defines the different enumerations that can be used for cryptography.
 */
#ifndef _FSEC_CRYPTO_TYPES_H_
#define _FSEC_CRYPTO_TYPES_H_


namespace Osp{ namespace Security { namespace Crypto
{


/** 
 * @enum CipherOperation
 * @since 		1.0
 *
 * Defines the cipher operation.
 *
 */
enum CipherOperation
{
		CIPHER_ENCRYPT = 0,		/**<	The encrypt mode */
		CIPHER_DECRYPT,			/**<	The decrypt mode */
		CIPHER_WRAP,			/**<	The wrap mode */
		CIPHER_UNWRAP			/**<	The unwrap mode */
};  // CipherOperation

/**
 * @internal
 * @enum CipherMode
 * @since 1.0
 *
 * Defines the cipher mode.
 */
enum CipherMode
{
	ECB = 0,		
	CBC				
};	// CipherMode;


/**
 * @internal
 * @enum PaddingOption
 * @since 1.0
 *
 * Defines the padding option.
 */
enum PaddingOption
{
	NOPADDING = 0,	
	RFC2630			
};	// PaddingOption;

}; }; }; // Osp::Security::Crypto

namespace Osp{ namespace Security {

/** 
 * @enum 	KeyParameterType
 * @since 	2.0
 *
 * Defines the type of key parameters for asymmetric algorithms.
 */
enum KeyParameterType
{
	KEY_PARAMETER_DH_P, 				/**< The DH param P	*/
	KEY_PARAMETER_DH_G,  				/**< The DH param G	*/
	KEY_PARAMETER_DH_PRIVATE_KEY_SIZE,  /**< The DH private key size */
	KEY_PARAMETER_KEA_P, 				/**< The KEA param P */
	KEY_PARAMETER_KEA_G,  				/**< The KEA param G */
	KEY_PARAMETER_KEA_PRIVATE_KEY_SIZE  /**< The KEA private key size */
};

}; }; //Osp::Security

#endif // _FSEC_CRYPTO_TYPES_H_
