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
 * @file		FSecCryptoKeaKeyExchange.h
 * @brief		This is the header file for the %KeaKeyExchange class.
 *
 * This header file contains the declarations of the %KeaKeyExchange class.
 */
#ifndef _FSEC_CRYPTO_KEA_KEY_EXCHANGE_H
#define _FSEC_CRYPTO_KEA_KEY_EXCHANGE_H

// Includes
#include "FSecCryptoIKeyExchange.h"


namespace Osp { namespace Security { namespace Crypto {

class IKeaKeyExchangePi;
/**
 *	@class		KeaKeyExchange
 *	@brief		This class provides methods for performing the key exchange mechanism using Key Exchange Algorithm (KEA).
 * 	@since 		2.0
 *  

 *	The %KeaKeyExchange class provides a KEA key exchange between two communicating users.
 *
 *  For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/ciphers.htm">Ciphers</a>.
 *
 *  @see	IKeyExchange, KeyPairGenerator
 *	
 * The following example demonstrates how to use the %KeaKeyExchange class.
 *  @code
 *
 *	void KeaGenerateSecretExample(void)
 *	{
 *
 *	  result r = E_SUCCESS;
 *	  KeyPair *pKeyPairAlice1 = null;
 *	  IPrivateKey *pPriKeyAlice1 = null;
 *	  IPrivateKey *pPriKeyAlice2 = null;
 *	  KeyPair *pKeyPairAlice2 = null;
 *	  IPublicKey *pPubKeyAlice1 = null;
 *	  IPublicKey *pPubKeyAlice2 = null;
 *
 *	  KeyPair *pKeyPairBob1 = null;
 *	  IPrivateKey *pPriKeyBob1 = null;
 *	  IPrivateKey *pPriKeyBob2 = null;
 *	  KeyPair *pKeyPairBob2 = null;
 *	  IPublicKey *pPubKeyBob1 = null;
 *	  IPublicKey *pPubKeyBob2 = null;
 *
 *
 *	  KeyPairGenerator *pKeyPairGen = null;
 *	  IKeyParameters *pKeyParams = null;
 *
 *	  int size = 1024;
 *	  KeaKeyExchange *pKeaKeyExchangeAlice = null;
 *	  KeaKeyExchange *pKeaKeyExchangeBob = null;
 *	  ByteBuffer *pBuffer = null;
 *	  ByteBuffer *pBuffer1 = null;
 *
 *
 *	  // Key Generation
 *	  pKeyPairGen = new KeyPairGenerator();
 *	  if(pKeyPairGen == null)
 *		goto CATCH;
 *
 *
 *	  r = pKeyPairGen->Construct(size, L"KEA");
 *	  if (IsFailed(r))
 *		goto CATCH;
 *
 *
 *	  pKeyParams = pKeyPairGen->GenerateKeyParametersN();
 *	  if(pKeyParams == null)
 *		goto CATCH;
 *
 *
 *	  pKeyPairAlice1 = pKeyPairGen->GenerateKeyPairN(pKeyParams);
 *	  if(pKeyPairAlice1 == null)
 *		goto CATCH;
 *
 *	  pKeyPairAlice2 = pKeyPairGen->GenerateKeyPairN(pKeyParams);
 *	  if(pKeyPairAlice2 == null)
 *		goto CATCH;
 *
 *	  pPriKeyAlice1 = pKeyPairAlice1->GetPrivateKey();
 *	  if(pPriKeyAlice1 == null)
 *		goto CATCH;
 *
 *	  pPubKeyAlice1 = pKeyPairAlice1->GetPublicKey();
 *	  if(pPubKeyAlice1 == null)
 *		goto CATCH;
 *
 *	  pPriKeyAlice2 = pKeyPairAlice2->GetPrivateKey();
 *	  if(pPriKeyAlice2 == null)
 *		goto CATCH;
 *
 *	  pPubKeyAlice2 = pKeyPairAlice2->GetPublicKey();
 *	  if(pPubKeyAlice2 == null)
 *		goto CATCH;
 *
 *	  pKeyPairBob1 = pKeyPairGen->GenerateKeyPairN(pKeyParams);
 *	  if(pKeyPairBob1 == null)
 *		goto CATCH;
 *
 *	  pKeyPairBob2 = pKeyPairGen->GenerateKeyPairN(pKeyParams);
 *	  if(pKeyPairBob2 == null)
 *		goto CATCH;
 *
 *	  pPriKeyBob1 = pKeyPairBob1->GetPrivateKey();
 *	  if(pPriKeyBob1 == null)
 *		goto CATCH;
 *
 *	  pPubKeyBob1 = pKeyPairBob1->GetPublicKey();
 *	  if(pPubKeyBob1 == null)
 *		goto CATCH;
 *
 *	  pPriKeyBob2 = pKeyPairBob2->GetPrivateKey();
 *	  if(pPriKeyBob2 == null)
 *		goto CATCH;
 *
 *	  pPubKeyBob2 = pKeyPairBob2->GetPublicKey();
 *	  if(pPubKeyBob2 == null)
 *		goto CATCH;
 *
 *
 *	  pKeaKeyExchangeAlice = new KeaKeyExchange();
 *	  if(pKeaKeyExchangeAlice == null)
 *		goto CATCH;
 *
 *	  pKeaKeyExchangeBob = new KeaKeyExchange();
 *	  if(pKeaKeyExchangeBob == null)
 *		goto CATCH;
 *
 *	  r = pKeaKeyExchangeAlice->Construct(*pKeyParams);
 *	  if(IsFailed(r))
 *		goto CATCH;
 *
 *	  r =  pKeaKeyExchangeAlice->DoPhase(*pPriKeyAlice1, *pPubKeyBob1);
 *	  if(IsFailed(r))
 *		goto CATCH;
 *
 *	  r = pKeaKeyExchangeBob->Construct(*pKeyParams);
 *	  if(IsFailed(r))
 *		goto CATCH;
 *
 *	  r =  pKeaKeyExchangeBob->DoPhase(*pPriKeyBob1, *pPubKeyAlice1);
 *	  if(IsFailed(r))
 *		goto CATCH;
 *
 *	  pBuffer =  pKeaKeyExchangeAlice->GenerateSecretN(*pPriKeyAlice2, *pPubKeyBob2);
 *	  if(pBuffer == null)
 *		goto CATCH;
 *
 *	  pBuffer1 =  pKeaKeyExchangeBob->GenerateSecretN(*pPriKeyBob2, *pPubKeyAlice2);
 *	  if(pBuffer1 == null)
 *		goto CATCH;
 *
 *	  if(*pBuffer == *pBuffer1)
 *		AppLog("Secret is Generated Successfully");
 *	  else
 *		goto CATCH;
 *
 *	CATCH:
 *
 *	  delete pKeyPairGen;
 *	  delete pKeyPairAlice1;
 *	  delete pKeyPairAlice2;
 *	  delete pKeyPairBob1;
 *	  delete pKeyPairBob2;
 *	  delete pBuffer;
 *	  delete pBuffer1;
 *	  delete pKeaKeyExchangeAlice;
 *	  delete pKeaKeyExchangeBob;
 *	  delete pKeyParams;
 *	}
 *	@endcode
 *
 */
 
class _EXPORT_SECURITY_ KeaKeyExchange:
 	public virtual IKeyExchange,
	public Osp::Base::Object
{
 
 
// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class.
	 *	@since 		2.0
	 */	
	KeaKeyExchange(void);
	/** 
	 *	This is the destructor for this class.
	 *	@since 		2.0
	 */	
	~KeaKeyExchange(void);

// Operation
public:

	/**
	 *  Computes the shared secret in a phase-wise manner. @n
	 *  The DoPhase() method requires the first party's private key(s) and the second party's public key(s) 
	 *  to generate the shared secret.
	 *  This method is used in algorithms such as the KEA algorithm and also for a multi-party key exchange.
	 * 	@since 		2.0
	 *	@return		An error code
	 *	@param[in]	privateKey		The private key component of the first party to instantiate
	 *	@param[in]	publicKey		The public key component of the second party to instantiate
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			A specified input parameter is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *
	 */
	virtual result DoPhase(Osp::Security::IPrivateKey& privateKey, Osp::Security::IPublicKey& publicKey);
	/**
	 *	Initializes this instance of IKeyExchange with the specified key parameters.
	 * 	@since 		2.0
	 *	@return		An error code
	 *	@param[in]	keyParameters			The domain parameters of the key exchange algorithm @n 
	 *                                      This parameter needs to be instantiated.
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified input parameter is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	virtual result	Construct(const Osp::Security::IKeyParameters& keyParameters);


	/** 
	 *	Generates the final shared secret among two parties.
	 * 	@since 		2.0
	 *	@return		A pointer to the %ByteBuffer class that contains the generated secret key, @n
	 *				else @c null if the method fails to generate the secret key
	 *  @param[in]  privateKey			The private key component of the first party to instantiate
	 *	@param[in]	publicKey			The public key component of the second party to instantiate
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			A specified input parameter is invalid.
	 *	@exception	E_INVALID_STATE			The specified state is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_UNSUPPORTED_OPERATION	The operation is not supported.
	 *  @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer*	GenerateSecretN(Osp::Security::IPrivateKey& privateKey,  Osp::Security::IPublicKey& publicKey);

// Attribute
private:
	IKeaKeyExchangePi *__pKeaKeyExchangePi;
	friend class 	   KeaKeyExchangeEx;
	class KeaKeyExchangeEx*   __pKeaKeyExchangeEx;
};
};}; };// Osp::Security::Crypto

#endif //_FSEC_CRYPTO_KEA_KEY_EXCHANGE_H

