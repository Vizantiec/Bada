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
 * @file	FSecDesEdeSecureRandom.h
 * @brief	This is the header file for the %DesEdeSecureRandom class.
 *
 * This header file contains the declarations of the %DesEdeSecureRandom class.
 */
#ifndef _FSEC_DESEDE_SECURE_RANDOM_H_
#define _FSEC_DESEDE_SECURE_RANDOM_H_

// Includes
#include "FSecISecureRandom.h"
		  

namespace Osp {namespace Security {

class ISecureRandomPi;
/**
 * @class	DesEdeSecureRandom 
 * @brief	This class provides a secure random object with the Data Encryption Standard in the Encrypt-Decrypt-Encrypt (DES-EDE) mode.
 * @since	1.0
 *
 * The %DesEdeSecureRandom class generates a secure random object to deterministically seed cryptographic algorithms. The Data Encryption Standard (DES) 
 * method generates user-defined number of random bytes in the Encrypt-Decrypt-Encrypt mode.
 *
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/key_mgmt_and_csprng.htm">Key Management and CSPRNG</a>.
 *
 * @see		ISecureRandom, AesSecureRandom, DesSecureRandom
 */
class _EXPORT_SECURITY_ DesEdeSecureRandom:
		public virtual ISecureRandom,
		public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class.
	 *
	 * 	@since 		1.0
	 */	
	DesEdeSecureRandom(void);


	/** 
	 *	This is the destructor for this class. 
	 *
	 * 	@since 		1.0
	 */	
	~DesEdeSecureRandom(void);


// Operation
public:
	/** 
	 * Generates a user-defined number of random bytes.
	 *
	 * @since 		1.0
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @param[in]  	numBytes			The number of random bytes to be generated
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified @c numBytes is @c 0 or negative.
	 */
	virtual Osp::Base::ByteBuffer*	GenerateRandomBytesN(const int numBytes);


// Attribute
private:
	ISecureRandomPi	*m_pIRandomPi;
	friend	class 		DesEdeSecureRandomEx;
	class DesEdeSecureRandomEx*	__pDesEdeSecureRandomEx;

};
}; }; // Osp::Security

#endif// _FSEC_DESEDE_SECURE_RANDOM_H_

