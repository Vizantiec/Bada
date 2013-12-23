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
 * @file	FSecCryptoSkipJackCipher.h
 * @brief	This is the header file for the %SkipJackCipher class.
 *
 * This header file contains the declarations of the %SkipJackCipher class.
 */
#ifndef _FSEC_CRYPTO_SKIPJACK_CIPHER_H
#define _FSEC_CRYPTO_SKIPJACK_CIPHER_H

// Includes
#include "FSecCryptoISymmetricCipher.h"


namespace Osp { namespace Security { namespace Crypto {

class ISymmetricCipherPi;
/**
 * @class	SkipJackCipher
 * @brief	This class provides methods for encryption and decryption using the SKIPJACK algorithm.
 * @since 	2.0
 *
 * The %SkipJackCipher class provides a symmetric cipher using the SKIPJACK algorithm. Appropriate values have to be set for the requested mode or key bit or 
 * padding scheme and the cipher operation (CIPHER_ENCRYPT or CIPHER_DECRYPT) parameters.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/ciphers.htm">Ciphers</a>.
 * @see		ISymmetricCipher, DesCipher, DesEdeCipher
 */
class _EXPORT_SECURITY_ SkipJackCipher :
	public virtual ISymmetricCipher, 
	public Osp::Base::Object
{

// Lifecycle
public:
	/** 
	 * This is the default constructor for this class.
	 *
	 * @since 	2.0
	 */	
	SkipJackCipher(void);


	/** 
	 * This is the destructor for this class.
	 *
	 * @since 	2.0
	 */	
	~SkipJackCipher(void);

// Operation
public:
	/** 
	 * Initializes this instance of SkipJackCipher with the specified parameters.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	transformation			The name of the requested mode or padding scheme @n
	 *										As the default key size of the Skipjack cipher is 80 bits, there is no need to mention it explicitly. For 
	 *										example, "CBC/PKCS7PADDING" or "ECB/NOPADDING".
	 * @param[in]	opMode					The cipher operation mode @n
	 *										The only valid values for SkipJackCipher are CIPHER_ENCRYPT and CIPHER_DECRYPT.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c opMode contains invalid value for the cipher operation.
	 * @exception	E_UNSUPPORTED_ALGORITHM	The algorithm is not supported.
	 * @exception	E_SYSTEM				A system error has occurred.
	 *  @remarks If @c opMode is not matching the actual operation, the result of the operation is @c null and an exception is thrown. @n
	 *			 For example, if @c opMode is set to CIPHER_ENCRYPT, CIPHER_WRAP, or CIPHER_UNWRAP and the DecryptN() method is used, then the result obtained is @c null and an exception is thrown.
	 */

	virtual result	Construct(const Osp::Base::String& transformation, enum CipherOperation opMode);


	/** 
	 * Sets a symmetric key for encryption or decryption.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	key					An instance of %ISecretKey
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified key is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual result	SetKey(const Osp::Security::ISecretKey& key);


	/** 
	 * Sets the initial vector.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	initialVector		The initial vector
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual result	SetInitialVector(const Osp::Base::ByteBuffer& initialVector);


	/** 
	 * Encrypts the data (single-part).
	 *	
	 * @since 		2.0 
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @param[in]	input					An instance of %ByteBuffer
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_KEY_NOT_FOUND			The specified key is not found.
	 * @exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 * @exception	E_OVERFLOW				This operation has caused the memory to overflow.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 *            A secret key and an initial vector are set before calling this method. 
	 */
	virtual Osp::Base::ByteBuffer*	EncryptN(const Osp::Base::ByteBuffer& input);


	/** 
	 * Decrypts the data (single-part).
	 *
	 * @since 		2.0  
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @param[in]	input					An instance of %ByteBuffer
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_KEY_NOT_FOUND			The specified key is not found.
	 * @exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 * @exception	E_OVERFLOW				This operation has caused the memory to overflow
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 *            A secret key and an initial vector are set before calling this method.
	 */
	virtual Osp::Base::ByteBuffer*	DecryptN(const Osp::Base::ByteBuffer& input);

	
	/** 
	 * Initializes the multiple-part encryption or decryption operation.
	 *
	 * @since 		2.0 
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_KEY_NOT_FOUND			The specified key is not found.
	 * @exception	E_INVALID_OPERATION		The specified cipher operation mode for this method is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks A secret key and an initial vector are set before calling this method.
	 */
	virtual result Initialize(void);


	/** 
	 * Updates the multiple-part encryption or decryption operation.
	 *
	 * @since 		2.0
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @param[in]	input				An instance of %ByteBuffer
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OVERFLOW			This operation has caused the memory to overflow.
	 * @exception	E_INVALID_ARG		The specified instance of %ByteBuffer is invalid or empty.
	 * @exception	E_INVALID_STATE		The state is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer*	UpdateN(const Osp::Base::ByteBuffer& input);


	/** 
	 * Finalizes the multiple-part encryption or decryption operation.
	 *
	 * @since 		2.0 
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OVERFLOW			This operation has caused the memory to overflow.
	 * @exception	E_INVALID_STATE		The state is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer*	FinalizeN(void);


	/** 
	 * Wraps the specified key.
	 *
	 * @since		2.0  
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @param[in]	secretKey		The secret key to be wrapped
	 *
	 * @remarks		This operation is not supported in SkipJackCipher. Therefore, this method always returns @c null. @n
	 *				The E_UNSUPPORTED_ALGORITHM exception is thrown using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer*	WrapN(const Osp::Base::ByteBuffer& secretKey);


	/** 
	 * Unwraps the specified wrapped key.
     *	 
	 * @since 		2.0 
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @param[in]	wrappedKey			The wrapped key to unwrap
	 *
	 * @remarks		This operation is not supported in SkipJackCipher. Therefore, this method always returns @c null. @n
	 *				The E_UNSUPPORTED_ALGORITHM exception is thrown using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer*	UnwrapN(const Osp::Base::ByteBuffer& wrappedKey);


// Attribute
private:
	ISymmetricCipherPi *m_pISymmPi;
	friend class 	   SkipJackCipherEx;
	class SkipJackCipherEx*   __pSkipJackCipherEx;
};
};}; };// Osp::Security::Crypto

#endif //_FSEC_CRYPTO_SKIPJACK_CIPHER_H

