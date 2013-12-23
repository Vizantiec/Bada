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
 * @file		FSecKeyPairGenerator.h
 * @brief		This is the header file for the %KeyPairGenerator class.
 *
 * This header file contains the declarations of the %KeyPairGenerator class.
 */
#ifndef _FSEC_KEY_PAIR_GENERATOR_H_
#define _FSEC_KEY_PAIR_GENERATOR_H_

// Includes
#include "FSecIKeyPairGenerator.h"
#include "FSecISecureRandom.h"
#include "FSecIKeyParameters.h"


namespace Osp {namespace Security {

class IKeyPairGeneratorPi;
/**
 *  @class		KeyPairGenerator 
 *  @brief		This class provides a pair of public and private keys for the Public key algorithm.
 *  @since 		1.0
 *
 *  The %KeyPairGenerator class generates a key pair and its parameters that consists of a public and private key. These are used in asymmetric ciphers. The generated key pair and parameters are based on the underlying key pair encryption algorithm.
 *	
 *  @see Osp::Security::IKeyPairGenerator, Osp::Security::KeyPair
 */
class _EXPORT_SECURITY_ KeyPairGenerator:
	public virtual IKeyPairGenerator, 
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class.
	 *
	 * 	@since 		1.0
	 */	
	KeyPairGenerator(void);
	

	/** 
	 *	This is the destructor for this class. 
	 *
	 * 	@since 		1.0
	 */	
	~KeyPairGenerator(void);


// Operation
public:
	/** 
	 *	Initializes this instance of KeyPairGenerator with the specified parameter.
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@param[in]	size			The modulus size in bits
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c size is invalid. @n
	 *                                      The modulus size must be @c 1024 bits or @c 2048 bits.
	 */
	virtual result Construct(int size);

	/**
	 *	Initializes this instance of KeyPairGenerator with the specified parameters.
	 * 	@since 		2.0
	 *	@return		An error code
	 *	@param[in]	modulusBitSize			The modulus size in bits @n
	 *                                      This is used for key generation.
	 *  @param[in]  algorithm				The algorithm used to generate the key parameters @n
  	 *        								 The supported algorithms are RSA, DH, and KEA. The default value is RSA.
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c size is invalid. @n
	 *                                      The modulus size must be @c 1024 bits or @c 2048 bits.
	 */
	 result Construct(int modulusBitSize, const Osp::Base::String algorithm);

	 /**
	 *	Generates the key parameters based on the underlying key pair algorithm. @n
	 *  For example, in case of the DH or KEA algorithm, this method generates key parameters based on the DSA
	 *	algorithm (X186.3 specification).
	 *  The supported algorithms are RSA, DH, and KEA.
	 *  The generated key parameters may be required to create a key pair. The RSA algorithm
	 *  does not call this method to generate a key pair.
	 *  @since 		2.0
	 *
	 *	@return		A pointer to the %IKeyParameters class that contains a subset of the domain parameters ('p' prime
	 *				number, 'g' generator) that are used to generate a key pair, @n
	 *				else @c null if the method fails to create the key parameters
	 *	@param[in]	lInBits		The size of 'p', a prime number in bits @n
	 *							The size must be @c 1024 bits, @c 2048 bits, or @c 3072 bits.
	 *	@param[in]	nInBits		The size of 'g', a generator value in bits @n
	 *							The size must be:
	 *                          - 160 bits, when @c lInBits is @c 1024 bits.
	 *                          - 254 or 256 bits, when @c lInBits is @c 2048 bits.
	 *                          - 256 bits, when @c lInBits is @c 3072 bits.
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_UNSUPPORTED_OPERATION	This operation is not supported.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM  				A system error has occurred.
	 *  @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Security::IKeyParameters* 	GenerateKeyParametersN(int lInBits = 1024, int nInBits = 160) const;

	/**
	 *	Gets the newly generated key pair.
	 * 	@since 		2.0
	 *	@return		A pointer to %KeyPair, @n
	 *				else @c null if the method fails to create the key pair
	 *  @param[in]  pKeyParams				The domain parameters of the key exchange algorithm @n
	 *                                      These parameters are instantiated.
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_UNSUPPORTED_OPERATION	This operation is not supported.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM  				A system error has occurred.
	 *  @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Security::KeyPair* GenerateKeyPairN(Osp::Security::IKeyParameters* pKeyParams) const;


	/** 
	 *	Gets the newly generated key pair.
	 * 	@since 		1.0
	 *	@return		A pointer to %KeyPair, @n
					else @c null if the method fails to create the key pair
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_UNSUPPORTED_OPERATION	This operation is not supported.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM  				A system error has occurred.
	 */
	virtual Osp::Security::KeyPair* GenerateKeyPairN(void) const;


// Attribute
private:
	Osp::Base::String m_algorithm;		
	Osp::Security::IKeyPairGeneratorPi	*m_pIKeyPairGenPi;
	int	 m_modulusBitSize;	
	friend class		KeyPairGeneratorEx;
	class KeyPairGeneratorEx*	__pKeyPairGeneratorEx;
};
}; }; // Osp::Security
#endif// _FSEC_RSA_KEY_PAIR_GENERATOR_H_
