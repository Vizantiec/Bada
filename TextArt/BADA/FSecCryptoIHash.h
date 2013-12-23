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
 * @file		FSecCryptoIHash.h
 * @brief		This is the header file for the %IHash interface.
 *
 * This header file contains the declarations of the %IHash interface. 
 */
#ifndef _FSEC_CRYPTO_IHASH_H
#define _FSEC_CRYPTO_IHASH_H

// Includes
#include "FBaseString.h"
#include "FBaseByteBuffer.h"
#include "FSecConfig.h"


namespace Osp { namespace Security { namespace Crypto {

/**
 *	@interface	IHash 
 *	@brief		This interface provides the functionality of a hash algorithm.
 * 	@since 		1.0
 *
 * The %IHash interface provides the functionality of a hash algorithm.
 *
 *  The following example demonstrates how to use the %IHash interface.
 *  @code
 *
 *	result 
 *	MyClass::TestHashSample(void)
 *	{
 *		// Message
 *		const int messageLen	= 49;
 *		static const byte message[messageLen] = {
 *			0xF4,  0xA4,  0xA2,  0x40,  0xB0,  0xAB,  0x73,  0x1B,  0xC8,  0x10,  0xEA,  0x08,  0x9C,  0xD0,  0x78,  0x0D,
 *			0x40,  0xB9,  0x94,  0x02,  0x21,  0x79,  0xFD,  0x5A,  0xA3,  0xC9,  0x17,  0x64,  0x9B,  0x27,  0xC5,  0x20,
 *			0x03,  0x7B,  0x4D,  0x7C,  0x4D,  0xE6,  0xEE,  0x64,  0x78,  0xA2,  0xBE,  0x2C,  0x22,  0x0A,  0x8E,  0x37,
 *			0xB4,
 *		};
 *		
 *		// Sample Output
 *		const int sampleOutputLen	= 20;
 *		static const byte sampleOutput[sampleOutputLen] = {
 *			0xC4,  0x10,  0xB8,  0x6E,  0xDA,  0x00,  0xE3,  0x2C,  0x8A,  0xC4,
 *			0xE5,  0xDC,  0xB0,  0xE0,  0xE8,  0x2C,  0x21,  0xB6,  0x4E,  0x73
 *		};
 *
 *		const int Sha1Len	= 20;
 *
 *		result r = E_FAILURE;
 *		IHash * pHash	= null;
 *
 *		ByteBuffer input;
 *		ByteBuffer *pOutput = null;
 *
 *		input.Construct(messageLen);
 *		input.SetArray(message, 0, messageLen);
 *		input.Flip();
 *
 *		pHash = new Sha1Hash();
 *		if (pHash == null)
 *			goto CATCH;
 *
 *		pOutput	= pHash->GetHashN(input);
 *		if (pOutput == null)
 *		{
 *			r = GetLastResult();
 *			goto CATCH;
 *		}
 *
 *		if (memcmp(pOutput->GetPointer(), sampleOutput, Sha1Len) != 0)
 *			goto CATCH;
 *
 *		r = E_SUCCESS;
 *
 *	CATCH:
 *		delete pHash;
 *		delete pOutput;
 *
 *		return r;
 *	}
 *
 *
 *	result 
 *	MyClass::TestHashSample_Multipart(void)
 *	{
 *		// Message
 *		const int messageLen	= 49;
 *		static const byte message[messageLen] = {
 *			0xF4,  0xA4,  0xA2,  0x40,  0xB0,  0xAB,  0x73,  0x1B,  0xC8,  0x10,  0xEA,  0x08,  0x9C,  0xD0,  0x78,  0x0D,  
 *			0x40,  0xB9,  0x94,  0x02,  0x21,  0x79,  0xFD,  0x5A,  0xA3,  0xC9,  0x17,  0x64,  0x9B,  0x27,  0xC5,  0x20,  
 *			0x03,  0x7B,  0x4D,  0x7C,  0x4D,  0xE6,  0xEE,  0x64,  0x78,  0xA2,  0xBE,  0x2C,  0x22,  0x0A,  0x8E,  0x37,  
 *			0xB4,  
 *		};
 *	
 *		// Sample Output
 *		const int sampleOutputLen	= 20;
 *		static const byte sampleOutput[sampleOutputLen] = {
 *			0xC4,  0x10,  0xB8,  0x6E,  0xDA,  0x00,  0xE3,  0x2C,  0x8A,  0xC4,  
 *			0xE5,  0xDC,  0xB0,  0xE0,  0xE8,  0x2C,  0x21,  0xB6,  0x4E,  0x73
 *		};
 *	
 *		const int Sha1Len	= 20;
 *		int	unitLen	= messageLen / 5;
 *		int dataLen = 0;
 *	
 *		result r = E_FAILURE;
 *		IHash * pHash	= null;
 *	
 *		ByteBuffer input;
 *		ByteBuffer *pOutput = null;
 *	
 *		input.Construct(messageLen);
 *		input.SetArray(message, 0, messageLen);
 *		input.Flip();
 *	
 *		pHash = new Sha1Hash();
 *		if (pHash == null)
 *			goto CATCH;
 *	
 *		r = pHash->Initialize();
 *		if (r != E_SUCCESS)
 *			goto CATCH;
 *	
 *		for (int i = 0; i * unitLen < messageLen; i++)
 *		{
 *			if (messageLen - (i * unitLen) < unitLen)
 *			{
 *				dataLen = messageLen - (i * unitLen);
 *			}
 *			else
 *			{
 *				dataLen = unitLen;
 *			}
 *	
 *			// messageLen == 98
 *			input.Construct(dataLen);
 *			input.SetArray(message + (i * unitLen), 0, dataLen);
 *			input.Flip();
 *	
 *			r = pHash->Update(input);
 *			if (r != E_SUCCESS)
 *				goto CATCH;
 *	
 *			input.Clear();
 *		}
 *	
 *		pOutput	= pHash->FinalizeN();
 *		if (pOutput == null)
 *		{
 *			r = GetLastResult();
 *			goto CATCH;
 *		}
 *	
 *		if (memcmp(pOutput->GetPointer(), sampleOutput, Sha1Len) != 0)
 *			goto CATCH;
 *	
 *		r = E_SUCCESS;
 *	
 *	CATCH:
 *		delete pHash;
 *		delete pOutput;
 *	
 *		return r;
 *	}
 *
 *  @endcode
 */
class _EXPORT_SECURITY_ IHash 
{

// Lifecycle
public:

	/** 
	 *	This is the destructor for this class.
	 *
	 * 	@since 		1.0
	 */	
	virtual ~IHash(void) {}

// Operation
public:
	/** 
	 *	Sets the hash algorithm. @n 
	 * Only supported in Secure Hash Algorithm-2 (SHA-2).  

	 *  
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@param[in]	algorithm				The name of the hash algorithm @n
	 *										For example, "SHA2/224", "SHA2/256", "SHA2/386", or "SHA2/512".
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The algorithm is not supported.
	 */
	virtual result	SetAlgorithm(const Osp::Base::String& algorithm)	= 0;


	/** 
	 *	Gets the hashes of the data (single-part).
	 *  
	 * 	@since 		1.0
	 *	@return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *  @param[in]	input					The input %ByteBuffer instance
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual Osp::Base::ByteBuffer*	GetHashN(const Osp::Base::ByteBuffer& input) = 0;


	/** 
	 *	Initializes a multiple-part hash operation.
	 *  
	 * 	@since 		1.0
	 *	@return		An error code
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	virtual result	Initialize(void) = 0;


	/** 
	 *	Updates a multiple-part hash operation while processing another data part.
	 *
	 * 	@since 		1.0
	 *	@return		An error code
	 *  @param[in]	input					The input %ByteBuffer instance
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE			The state is invalid.
	 *	@exception	E_INVALID_ARG			The input %ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	virtual result	Update(const Osp::Base::ByteBuffer& input) = 0;


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
	virtual Osp::Base::ByteBuffer*	FinalizeN(void) = 0;


};
};}; };// Osp::Security::Crypto

#endif //_FSEC_CRYPTO_IHASH_H

