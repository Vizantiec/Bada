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
 * @file		FSecCertX509CertificateStore.h
 * @brief		This is the header file for the %X509CertificateStore class. 
 *
 * This header file contains the declarations of the %X509CertificateStore class.
 */
#ifndef _FSEC_CERT_X509_CERTIFICATE_STORE_H_
#define _FSEC_CERT_X509_CERTIFICATE_STORE_H_


// Includes
#include "FBaseString.h"
#include "FBaseByteBuffer.h"
#include "FSecIPrivateKey.h"
#include "FSecCertICertificateStore.h"
#include "FSecCertICertificateSelector.h"
#include "FSecConfig.h"


namespace Osp { namespace Security { namespace Cert {

class ICertificateStorePi;
/**
 *  @if PRIVCORE
 *
 *  @class	X509CertificateStore 
 *  @brief	This class is used for retrieving and managing certificates from a repository.
 *	@since	1.0
 *
 * The %X509CertificateStore class is used for retrieving and managing certificates from a repository.
 *  @endif
 */
class _EXPORT_SECURITY_ X509CertificateStore:
	public virtual ICertificateStore,
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class. 
	 *
	 *	@since		1.0
	 */	
	X509CertificateStore();


	/** 
	 *	This is the destructor for this class. 
	 *
	 *	@since		1.0
	 */	
	virtual ~X509CertificateStore(void);


// Operation
public:
	/** 
	 *  @if PRIVCORE
	 *  Gets the name of the current certificate store.
	 *
	 *	@since		1.0
	 *	@privlevel	CORE
	 *
	 *  @privgroup  CERTIFICATE_STORE
	 *	@return     An error code
	 *  @param[out]	name                    The name of the certificate store
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception  E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 *  @endif
	 */
	virtual result GetName(Osp::Base::String& name);


	/**
	 *	@if PRIVCORE
	 *	Sets a list of certificates that match the specified selector.
	 *
	 *	@since		1.0
	 *	@privlevel	CORE
	 *
	 *  @privgroup  CERTIFICATE_STORE
	 *	@return		An error code
	 *  @param[in]  selector				A selector that defines a set of criterion for selecting certificates
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *  @exception	E_INVALID_ARG			The specified @c selector is invalid.
	 *  @exception 	E_UNSUPPORTED_OPERATION The type of selector is invalid.
	 *	@exception  E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 *  @endif
	 */
	virtual result	SetCertificateSelector(Osp::Security::Cert::ICertificateSelector &selector);


	/**
	 *	@if PRIVCORE
	 *	Gets a count of certificates that match the specified selector.
	 *
	 *	@since		1.0
	 *	@privlevel	CORE
	 *
	 *  @privgroup  CERTIFICATE_STORE
	 *	@return		An error code
	 *  @param[out] count                   The count of certificates
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception  E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 *  @endif
	 */
	virtual result	GetCertificateCount(int& count);


	/**
	 *	@if PRIVCORE
	 *	Gets each certificate that matches the specified selector.
	 *
	 *	@since		1.0
	 *	@privlevel	CORE
	 *
	 *  @privgroup  CERTIFICATE_STORE
	 *	@return		The certificates that matches the specified selector
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
	 *	@exception	E_SYSTEM				A system error has occurred.	
	 *	@exception  E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 *  @endif
	 */
	virtual Osp::Security::Cert::ICertificate*	GetNextCertificateN(void);


	/** 
	 *	@if PRIVCORE
	 *  Inserts the certificate into the certificate store.
	 *
	 *	@since		1.0
	 *	@privlevel	CORE
	 *
	 *  @privgroup  CERTIFICATE_STORE
	 *	@return		An error code
	 *  @param[in]	certificateType			The type of the Certificate (ROOT_CA, OPERATOR_DOMAIN, or TRUSTED_THIRD_PARTY_DOMAIN)
	 *  @param[in]	certificate				A reference to the certificate to insert
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
	 *	@exception	E_INVALID_ARG			The specified @c certificate or the certificate data is invalid,
	 *										or the specified @c certificateType is invalid.
	 *	@exception	E_IO					The method has failed to operate the certificate store.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@exception  E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 *  @endif
	 */
	virtual result Insert(CertificateType certificateType, const Osp::Security::Cert::ICertificate &certificate);


	/** 
	 *	@if PRIVCORE
	 *  Updates the certificate in the certificate store.
	 *
	 *	@since		1.0
	 *	@privlevel	CORE
	 *
	 *  @privgroup  CERTIFICATE_STORE
	 *	@return		An error code
	 *  @param[in]	certificateType			The type of the Certificate (ROOT_CA, OPERATOR_DOMAIN, or TRUSTED_THIRD_PARTY_DOMAIN)
	 *  @param[in]	oldCert					A reference to the old certificate
	 *  @param[in]	newCert					A reference to the new certificate
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified @c certificate or the certificate data is invalid,
	 *											or the specified @c certificateType is invalid.
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
	 *	@exception	E_IO					The method has failed to operate the certificate store.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@exception  E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 *  @endif
	 */
	virtual result Update(CertificateType certificateType, const Osp::Security::Cert::ICertificate& oldCert, const Osp::Security::Cert::ICertificate& newCert);


	/** 
	 *	@if PRIVCORE
	 *  Removes the certificate from the certificate store.
	 *
	 *	@since		1.0
	 *	@privlevel	CORE
	 *
	 *  @privgroup  CERTIFICATE_STORE
	 *	@return		An error code
	 *  @param[in]	certificateType			The type of the Certificate (ROOT_CA, OPERATOR_DOMAIN, TRUSTED_THIRD_PARTY_DOMAIN)
	 *  @param[in]	certificate				A reference to the certificate to remove
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified @c certificate or the certificate data is invalid,
	 *											or the specified @c certificateType is invalid.
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
	 *	@exception	E_IO					The method has failed to operate the certificate store.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@exception  E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 *  @endif
	 */
	virtual result Remove(CertificateType certificateType, const Osp::Security::Cert::ICertificate &certificate);


private:
	ICertificateStorePi	*m_pCertStorePi;
	friend class 		X509CertificateStoreEx;
	class X509CertificateStoreEx* __pX509CertificateStoreEx;
	
};
}; }; }; // Osp::Security::Cert


#endif//_FSEC_CERT_X509_CERTIFICATE_STORE_H_
