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
 * @file		FSecCrypto.h
 * @brief		This is the header file for the %Crypto namespace.
 *
 * This header file contains the declarations of the %Crypto namespace.
*/
#ifndef _FSEC_CRYPTO_H_
#define _FSEC_CRYPTO_H_


// Includes
#include "FSecCryptoTypes.h"
#include "FSecCryptoAesCipher.h"
#include "FSecCryptoDesCipher.h"
#include "FSecCryptoDesEdeCipher.h"
#include "FSecCryptoRc2Cipher.h"
#include "FSecCryptoRc4Cipher.h"
#include "FSecCryptoRc5Cipher.h"
#include "FSecCryptoCastCipher.h"
#include "FSecCryptoSkipJackCipher.h"
#include "FSecCryptoIAsymmetricCipher.h"
#include "FSecCryptoIHash.h"
#include "FSecCryptoIHmac.h"
#include "FSecCryptoISignature.h"
#include "FSecCryptoISymmetricCipher.h"
#include "FSecCryptoMd5Hash.h"
#include "FSecCryptoMd5Hmac.h"
#include "FSecCryptoRsaCipher.h"
#include "FSecCryptoRsaSignature.h"
#include "FSecCryptoSha1Hash.h"
#include "FSecCryptoSha1Hmac.h"
#include "FSecCryptoSha2Hash.h"
#include "FSecCryptoSha2Hmac.h"
#include "FSecCryptoIKeyExchange.h"
#include "FSecCryptoDhKeyExchange.h"
#include "FSecCryptoKeaKeyExchange.h"


/**
 * @namespace	Osp::Security::Crypto
 * @brief		This namespace contains the classes and interfaces for the cryptographic primitives.
 * @since 1.0
 *
 * @remarks @b Header @b %file: @b \#include @b <FSecurity.h> @n
 *			@b Library : @b FOsp
 *
 * The %Crypto namespace provides classes and methods to handle encryption and decryption using hashing, symmetric and asymmetric ciphers. It also provides a mechanism for sending messages over an insecure channel using a key pair (public and private keys).
 *
 *  For more information on the %Crypto namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/cryptography.htm">Crypto Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Crypto namespace.
 * @image html security_cryptography_classes.png



 *
*/
namespace Osp{ namespace Security { namespace Crypto
{

}; }; }; // Osp::Security::Crypto

#endif // _FSEC_CRYPTO_H_
