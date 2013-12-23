/* $Change: 530918 $ */
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
 * @file		FSecCryptoRc4Cipher.h
 * @brief		This is the header file for the %Rc4Cipher class.
 *
 * This header file contains the declarations of the %Rc4Cipher class.
 */
#ifndef _FSEC_CRYPTO_RC4_CIPHER_H
#define _FSEC_CRYPTO_RC4_CIPHER_H

// Includes
#include "FSecCryptoISymmetricCipher.h"


namespace Osp { namespace Security { namespace Crypto {

class ISymmetricCipherPi;
/**
 *	@class		Rc4Cipher
 *	@brief		This class provides methods for encryption and decryption operations using the RC4 algorithm.
 * 	@since 		2.0
 *
 *	The %Rc4Cipher class provides a symmetric cipher using the RC4 algorithm.
 *	Set appropriate values for the requested mode/key bit/padding scheme and cipher operation (CIPHER_ENCRYPT or CIPHER_DECRYPT) parameters.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/ciphers.htm">Ciphers</a>.
 *	@see	ISymmetricCipher, DesCipher, DesEdeCipher
 */
class _EXPORT_SECURITY_ Rc4Cipher :
	public virtual ISymmetricCipher, 
	public Osp::Base::Object
{

// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class.
	 *	@since 		2.0
	 */	
	Rc4Cipher(void);


	/** 
	 *	This is the destructor for this class.
	 *	@since 		2.0
	 */	
	~Rc4Cipher(void);

// Operation
public:
	/** 
	 *	Initializes this instance of Rc4Cipher with the specified parameters.
	 * 	@since 		2.0
	 *	@return		An error code
	 *	@param[in]	transformation			The only valid value for Rc4Cipher for transformation is "NONE"
	 *	@param[in]	opMode					The cipher operation mode @n
	 *										The valid values for Rc4Cipher are CIPHER_ENCRYPT and CIPHER_DECRYPT.
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			A specified input parameter is invalid.
     *
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The algorithm is not supported.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *  @remarks If @c opMode is not matching the actual operation, the result of the operation is @c null and an exception is thrown. @n
	 *			 For example, if @c opMode is set to CIPHER_ENCRYPT, CIPHER_WRAP, or CIPHER_UNWRAP and the DecryptN() method is used, then the result obtained is @c null and an exception is thrown.
	 */
	virtual result	Construct(const Osp::Base::String& transformation, enum CipherOperation opMode);


	/** 
	 *	Sets a symmetric key for encryption or decryption operation. @n
	 *  The variable length key ranges from 40 bits to 256 bits, in steps of 8 bits.
	 * 	@since 		2.0
	 *	@return		An error code
	 *	@param[in]	key						An instance of %ISecretKey
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c key is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result	SetKey(const Osp::Security::ISecretKey& key);


	/** 
	 *	Sets the initial vector.
	 * 	@since 		2.0
	 *	@return		An error code
	 *	@param[in]	initialVector			The initial vector
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified input parameter is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result	SetInitialVector(const Osp::Base::ByteBuffer& initialVector);


	/** 
	 *	Encrypts the data (single-part).  
	 * 	@since 		2.0  
	 *	@return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *  @param[in]	input					An instance of %ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified instance of %ByteBuffer is invalid or empty.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 *	@exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *  @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 *            A secret key and an initial vector are set before calling this method.
	 */
	virtual Osp::Base::ByteBuffer*	EncryptN(const Osp::Base::ByteBuffer& input);


	/** 
	 *	Decrypts the data (single-part).
	 * 	@since 		2.0  
	 *	@return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *  @param[in]	input					An instance of %ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified instance of %ByteBuffer is invalid or empty.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 *	@exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *  @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 *            A secret key and an initial vector are set before calling this method.
	 */
	virtual Osp::Base::ByteBuffer*	DecryptN(const Osp::Base::ByteBuffer& input);

	
	/** 
	 *	Initializes a multiple-part encryption or decryption operation.
	 * 	@since 		2.0 
	 *	@return		An error code
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 * 	@remarks A secret key and an initial vector are set before calling this method.
	 */
	virtual result Initialize(void);


	/** 
	 *	Updates a multiple-part encryption or decryption operation.
	 * 	@since 		2.0
	 *	@return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *  @param[in]	input					An instance of %ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 *	@exception	E_INVALID_ARG			The specified instance of %ByteBuffer is invalid or empty.
	 *	@exception	E_INVALID_STATE			The state is invalid.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *  @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer*	UpdateN(const Osp::Base::ByteBuffer& input);


	/** 
	 *	Finalizes a multiple-part encryption or decryption operation.
	 * 	@since 		2.0 
	 *	@return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 *	@exception	E_INVALID_STATE			The state is invalid.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *  @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer*	FinalizeN(void);


	/** 
	 *	Wraps a key.
	 * 	@since 		2.0  
	 *	@return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *  @param[in]	secretKey				The secret key to wrap
	 *
	 *	@remarks	This operation is not supported in the %Rc4Cipher class.
	 *  	 		Therefore, this method always returns @c null.
	 *				The E_UNSUPPORTED_ALGORITHM is returned using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer*	WrapN(const Osp::Base::ByteBuffer& secretKey);


	/** 
	 *	Unwraps a previously wrapped key. 
	 * 	@since 		2.0  
	  *	@return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *  @param[in]	wrappedKey				The wrapped key to unwrap
	 *
	 *	@remarks	This operation is not supported in the %Rc4Cipher class.
	 *  	 		Therefore, this method always returns @c null.
	 *				The E_UNSUPPORTED_ALGORITHM is returned using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer*	UnwrapN(const Osp::Base::ByteBuffer& wrappedKey);


// Attribute
private:
	ISymmetricCipherPi *m_pISymmPi;
	friend class 	   Rc4CipherEx;
	class Rc4CipherEx*   __pRc4CipherEx;
};
};}; };// Osp::Security::Crypto

#endif //_FSEC_CRYPTO_RC4_CIPHER_H

