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
 * @file		FSecCryptoSha1Hash.h
 * @brief		This is the header file for the %Sha1Hash class.
 * 
 * This header file contains the declarations of the %Sha1Hash class.
 */
#ifndef _FSEC_CRYPTO_SHA1_HASH_H
#define _FSEC_CRYPTO_SHA1_HASH_H

// Includes
#include "FSecCryptoIHash.h"


namespace Osp { namespace Security { namespace Crypto {

class IHashPi;
/**
 *	@class		Sha1Hash 
 *	@brief		This class implements the SHA-1 hash algorithm.
 *	@since		1.0
 *
 *  The %Sha1Hash class implements the SHA-1 hash algorithm.
 *
 *  For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/hashing.htm">Hashing</a>.
 *	@see	IHash, Md5Hash, and Sha2Hash
 */
class _EXPORT_SECURITY_ Sha1Hash :
	public virtual IHash,
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class.
	 *
	 * 	@since 		1.0
	 */	
	Sha1Hash(void);


	/** 
	 *	This is the destructor for this class. 
	 *
	 * 	@since 		1.0
	 */	
	~Sha1Hash(void);


// Operation
public:
	/** 
	 *	Sets the hash algorithm. @n
	 *  This method is not supported by this class. Please do not call this method. @n
	 *  If this method is called, it returns E_UNSUPPORTED_ALGORITHM.
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@param[in]	algorithm				The name of the hash algorithm @n
	 *										For example "SHA2/224", "SHA2/256", "SHA2/386", or "SHA2/512".
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The algorithm is not supported.
	 *
	 *  @remarks 		Do not call this method. It is not supported.
	 */	
	virtual result	SetAlgorithm(const Osp::Base::String& algorithm);


	/** 
	 *	Gets the hashes of the data (single-part).
	 *  
	 * 	@since 		1.0
	 *	@return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				 else @c null if an error occurs
	 *  @param[in]	input					An instance of %ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual Osp::Base::ByteBuffer*	GetHashN(const Osp::Base::ByteBuffer& input);


	/** 
	 *	Initializes a multiple-part hash operation.
	 *  
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	virtual result	Initialize(void);


	/** 
	 *	Updates a multiple-part hash operation while processing another data part.
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *  @param[in]	input					An instance of %ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE			The state is invalid.
	 *	@exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	virtual result	Update(const Osp::Base::ByteBuffer& input);


	/** 
	 *	Finalizes a multiple-part hash operation. 
	 *  
	 * 	@since 		1.0
	 *	@return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE			The state is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	virtual Osp::Base::ByteBuffer*	FinalizeN(void);


// Attribute
private:
	IHashPi	*m_pIHashPi;
	friend class 	Sha1HashEx;
	class Sha1HashEx*	__pSha1HashEx;
};
};}; };// Osp::Security::Crypto

#endif //_FSEC_CRYPTO_SHA1_HASH_H

