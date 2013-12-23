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
 * @file		FSecurity.h
 * @brief		This is the header file for the %Security namespace.
 *
 * This header file contains the declarations of the %Security namespace.
 *
 */

#ifndef _FSECURITY_H_
#define _FSECURITY_H_


// Includes
#include "FSecAesSecureRandom.h"
#include "FSecDesEdeSecureRandom.h"
#include "FSecDesSecureRandom.h"
#include "FSecIKey.h"
#include "FSecIKeyPairGenerator.h"
#include "FSecIPrivateKey.h"
#include "FSecIPublicKey.h"
#include "FSecISecretKey.h"
#include "FSecISecretKeyGenerator.h"
#include "FSecISecureRandom.h"
#include "FSecKeyPair.h"
#include "FSecKeyPairGenerator.h"
#include "FSecPrivateKey.h"
#include "FSecPublicKey.h"
#include "FSecSecretKey.h"
#include "FSecSecretKeyGenerator.h"
#include"FSecIKeyParameters.h"
#include"FSecCryptoIKeyExchange.h"
#include"FSecCryptoKeaKeyExchange.h"
#include"FSecCryptoDhKeyExchange.h"
#include"FSecKeaKeyParameters.h"
#include"FSecDhKeyParameters.h"


#include "FSecCrypto.h"
#include "FSecCert.h"
#include "FSecIdentity.h"

/**
 * @namespace	Osp::Security
 * @brief		This namespace contains classes and interfaces for security services.
 * @since 	1.0
 *
 * @remarks @b Header @b %file: @b \#include @b <FSecurity.h> @n
 *			@b Library: @b FOsp
 *
 * The %Security namespace contains classes for
 * managing certificates, cryptographic keys, signatures, and for generating pseudo-random numbers.
 *
 * For more information on the %Security namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/security_namespace.htm">Security Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes and sub-namespaces belonging to the %Security namespace.
 * @image html security_using_the_apis_classdiagram.png
 * 
 */
namespace Osp
{

namespace Security
{

};
};// Osp::Security

#endif // _FSECURITY_H_
