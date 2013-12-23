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
 * @file		FSecDhKeyParameters.h
 * @brief		This is the header file for the %DhKeyParameters class.
 *
 * This header file contains the declarations of the %DhKeyParameters class.
 */
#ifndef _FSEC_DH_KEY_PARAMETERS_H
#define _FSEC_DH_KEY_PARAMETERS_H

// Includes
#include "FSecIKeyParameters.h"


namespace Osp { namespace Security { 

/**
 * @class		DhKeyParameters
 * @brief		This class provides methods for retrieving the parameters for the Diffie-Hellman (DH) algorithm.
 * @since 		2.0
 * 
 * The %DhKeyParameters class provides a subset of the domain parameters for the DH algorithm. For example, a prime number and a generator value are used to 
 * exchange keys between two parties.
 *
 * @see	IKeyParameters
 *
 * The following example demonstrates how to use the %DhKeyParameters class.
 *	
 *  @code
 *	void GetParameterExample()
 *	{
 *	  result r = E_SUCCESS;
 *	  KeyPairGenerator *pKeyPairGen = null;
 *	  IKeyParameters *pKeyParams = null;
 *
 *	  int size = 1024;
 *	  int nResult = 0;
 *    ByteBuffer* pResult = null;
 *
 *	  // Key Generation
 *	  pKeyPairGen = new KeyPairGenerator();
 *	  if (null == pKeyPairGen)
 *	 	goto CATCH;
 *	 
 *	  r = pKeyPairGen->Construct(size, L"DH");
 *	  if (IsFailed(r))
 *	 	goto CATCH;
 *
 *	  pKeyParams = pKeyPairGen->GenerateKeyParametersN();
 *	  if (null == pKeyParams)
 *	 	goto CATCH;
 *
 *	  // Calling the API.
 *	  pResult  = pKeyParams->GetParameterValueN(KEY_PARAMETER_DH_P);
 *	  if (null == pResult)
 *	 	goto CATCH;
 *
 *	  // Calling the API.
 *	  nResult  = pKeyParams->GetParameterSize(KEY_PARAMETER_DH_PRIVATE_KEY_SIZE);
 *
 * 	  CATCH:
 *	  delete pKeyPairGen;
 *	  delete pResult;
 *	  delete pKeyParams;
 *
 *	}
 * @endcode
 */

class _EXPORT_SECURITY_ DhKeyParameters : 
	public IKeyParameters,
	public Osp::Base::Object
{


// Operation
public:
	/** 
	 * This is the default constructor for this class.
	 *
	 * @since 		2.0
	 */	
	DhKeyParameters(void);
	/** 
	 * This is the destructor for this class.
	 *
	 * @since 		2.0
	 */	
	~DhKeyParameters(void);

public:
	/**
	 * Initializes this instance of IKeyParameters with the specified key parameters.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	p						The prime number 'p' that needs to be instantiated
	 * @param[in]	g						The generator value 'g' that needs to be instantiated
	 * @param[in]	privateKeySize			The size of the private key that needs to be instantiated
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	virtual result Construct(Osp::Base::ByteBuffer& p, Osp::Base::ByteBuffer& g, int privateKeySize);
	
	/**
	 * Gets the value of domain parameters (in ByteBuffer format) for the specified key parameter type.
	 *
	 * @since 		2.0
	 * @return		A pointer to the %ByteBuffer class that contains the parameter values, @n
	 *				else @c null if an error occurs
	 * @param[in]	paramType				The type of the parameter @n
	 *										For example, KEY_PARAMETER_DH_P.
	 * @exception	E_SUCCESS				The method is successful.
 	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_UNSUPPORTED_TYPE		The specified @c paramType is not supported.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer*	GetParameterValueN(KeyParameterType paramType);

	/**
	 * Gets the size of the private key component.
	 *
	 * @since 		2.0
	 * @return		The size of the private key component
	 * @param[in]	paramType				The type of the parameter @n
	 *										For example, KEY_PARAMETER_PRIVATE_KEY_SIZE.
	 * @exception	E_SUCCESS				The method is successful.
 	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_UNSUPPORTED_TYPE		The specified @c paramType is not supported.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual int GetParameterSize(KeyParameterType paramType);
	
private:

	Osp::Base::ByteBuffer __p;
	Osp::Base::ByteBuffer  __g;
	int __privateKeySize;
	friend class 	DhKeyParametersEx;
	class DhKeyParametersEx*   __pDhKeyParametersEx;

};
};};// Osp::Security

#endif //_FSEC_DH_KEY_PARAMETERS_H

