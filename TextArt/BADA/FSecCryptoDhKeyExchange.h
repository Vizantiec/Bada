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
 * @file		FSecCryptoDhKeyExchange.h
 * @brief		This is the header file for the %DhKeyExchange class.
 *
 * This header file contains the declarations of the %DhKeyExchange class.
 */
#ifndef _FSEC_CRYPTO_DH_KEYEXCHANGE_H
#define _FSEC_CRYPTO_DH_KEYEXCHANGE_H

// Includes
#include "FSecCryptoIKeyExchange.h"

namespace Osp { namespace Security { namespace Crypto {

class IDhKeyExchangePi;
/**
 *	@class		DhKeyExchange
 *	@brief		This class provides methods for a key exchange mechanism using the Diffie-Hellman (DH) algorithm.
 * 	@since 		2.0
 * 
 *	The %DhKeyExchange class provides a DH key exchange between two communicating users.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/ciphers.htm">Ciphers</a>.
 *	@see	IKeyExchange, KeyPairGenerator
 *
 * The following example demonstrates how to use the %DhKeyExchange class.
 *  @code
 *
 *	void DhGenerateSecretExample(void)
 *	{
 *	  result r = E_SUCCESS;
 *	  KeyPair *pKeyPair = null;
 *	  KeyPair *pKeyPair1 = null;
 *	  IPrivateKey *pPriKey = null;
 *	  IPublicKey *pPubKey = null;
 *	  IPrivateKey *pPriKey1 = null;
 *	  IPublicKey *pPubKey1 = null;
 *	  KeyPairGenerator *pKeyPairGen = null;
 *	  IKeyParameters *pKeyParams = null;
 *	  int size = 1024;
 *	  DhKeyExchange  *pDhKeyExchangeAlice = null;
 *	  DhKeyExchange  *pDhKeyExchangeBob = null;
 *	  ByteBuffer *pBuffer = null;
 *	  ByteBuffer *pBuffer1 = null;
 *
 *	  SetLastResult(E_SUCCESS);
 *	  // Generates the key.
 *	  pKeyPairGen = new KeyPairGenerator();
 *	  if(pKeyPairGen == null)
 *		goto CATCH;
 *
 *
 *	  r = pKeyPairGen->Construct(size, "DH");
 *	  if(IsFailed(r))
 *		goto CATCH;
 *
 *	  pKeyParams = pKeyPairGen->GenerateKeyParametersN();
 *	  if(pKeyParams == null)
 *		goto CATCH;
 *
 *
 *	  pKeyPair = pKeyPairGen->GenerateKeyPairN(pKeyParams);
 *	  if(pKeyPair == null)
 *		goto CATCH;
 *
 *	  pKeyPair1 = pKeyPairGen->GenerateKeyPairN(pKeyParams);
 *	  if(pKeyPair1 == null)
 *		goto CATCH;
 *
 *
 *	  pPubKey = pKeyPair->GetPublicKey();
 *	  if(pPubKey == null)
 *		goto CATCH;
 *
 *
 *	  pPriKey = pKeyPair->GetPrivateKey();
 *	  if(pPriKey == null)
 *		goto CATCH;
 *
 *
 *	  pPubKey1 = pKeyPair1->GetPublicKey();
 *	  if(pPubKey1 == null)
 *		goto CATCH;
 *
 *
 *	  pPriKey1 = pKeyPair1->GetPrivateKey();
 *	  if(pPriKey1 == null)
 *		goto CATCH;
 *
 *
 *	  pDhKeyExchangeAlice  = new DhKeyExchange ();
 *	  if(pDhKeyExchangeAlice == null)
 *		goto CATCH;
 *
 *	  pDhKeyExchangeBob  = new DhKeyExchange ();
 *	  if(pDhKeyExchangeBob == null)
 *		goto CATCH;
 *
 *	  // Calling Construct API.
 *	  r = pDhKeyExchangeAlice->Construct(*pKeyParams);
 *	  if(IsFailed(r))
 *		goto CATCH;
 *
 *	  r = pDhKeyExchangeBob->Construct(*pKeyParams);
 *	  if(IsFailed(r))
 *		goto CATCH;
 *
 *	  pBuffer =  pDhKeyExchangeAlice->GenerateSecretN(*pPriKey, *pPubKey1);
 *	  if(pBuffer == null)
 *		goto CATCH;
 *
 *	  pBuffer1 =  pDhKeyExchangeBob->GenerateSecretN(*pPriKey1, *pPubKey);
 *	  if(pBuffer1 == null)
 *		goto CATCH;
 *
 *	  if(*pBuffer == *pBuffer1)
 *		AppLog("The secret is generated SuccessFully");
 *	  else
 *		goto CATCH;
 *
 *	CATCH:
 *	  delete pKeyPairGen;
 *	  delete pKeyPair;
 *	  delete pKeyPair1;
 *	  delete pBuffer;
 *	  delete pBuffer1;
 *	  delete pDhKeyExchangeAlice;
 *	  delete pDhKeyExchangeBob;
 *	  delete pKeyParams;
 *
 *	}
 *
 *	@endcode
 *
 */
class _EXPORT_SECURITY_ DhKeyExchange:
	public virtual IKeyExchange,
	public Osp::Base::Object
{

// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class.
	 *	@since 		2.0
	 */	
	DhKeyExchange(void);
	/** 
	 *	This is the destructor for this class.
	 *	@since 		2.0
	 */	
	~DhKeyExchange(void);

// Operation
public:

	/**
	 *	Initializes this instance of DhKeyExchange with the specified key parameters.
	 * 	@since 		2.0
	 *	@return		An error code
	 *	@param[in]	keyParameters			The domain parameters ('p' prime number and 'g' generator) of DH
	 *										algorithm that needs to be instantiated
	 *	@exception	E_SUCCESS				The method is successful.
	 */
	virtual result Construct(const Osp::Security::IKeyParameters& keyParameters);

	/** 
	 *	Generates the final shared secret between two parties.
	 * 	@since 		2.0
	 *	@return		A pointer to the %ByteBuffer class that contains the generated secret key, @n
	 *				else @c null if the method fails to generate the secret key
	 *  @param[in]  privateKey				The private key component of the first party that needs to be instantiated
	 *	@param[in]	publicKey				The public key component of the second party that needs to be instantiated
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			A specified input parameter is invalid.
	 *	@exception	E_INVALID_STATE			The specified state is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_UNSUPPORTED_OPERATION	The operation is not supported.
	 *  @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer*	GenerateSecretN(Osp::Security::IPrivateKey& privateKey, Osp::Security::IPublicKey& publicKey);

// Attribute
private:
	IDhKeyExchangePi *__pDhKeyExchangePi;
	friend class 	   DhKeyExchangeEx;
	class DhKeyExchangeEx*   __pDhKeyExchangeEx;
};
};}; };// Osp::Security::Crypto

#endif //_FSEC_CRYPTO_DH_KEYEXCHANGE_H

