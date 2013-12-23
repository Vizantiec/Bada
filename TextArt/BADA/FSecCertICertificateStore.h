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
 * @file		FSecCertICertificateStore.h
 * @brief		This is the header file for the %ICertificateStore interface. 
 *
 * This header file contains the declarations of the %ICertificateStore interface.
 */
#ifndef _FSEC_CERT_ICERTIFICATE_STORE_H_
#define _FSEC_CERT_ICERTIFICATE_STORE_H_


// Includes
#include "FBaseString.h"
#include "FBaseByteBuffer.h"
#include "FSecIPrivateKey.h"
#include "FSecCertICertificate.h"
#include "FSecCertICertificateSelector.h"


namespace Osp { namespace Security { namespace Cert {
/**
 *	@if PRIVCORE
 *
 *  @interface	ICertificateStore 
 *  @brief		This is the interface for retrieving and managing the certificates from a repository.
 *	@since		1.0
 *
 * The %ICertificateStore interface is used for retrieving and managing the certificates from a repository.
 *  @endif
 */
class _EXPORT_SECURITY_ ICertificateStore
{
// Lifecycle
public:
	/** 
	 *	This is the destructor for this class. 
	 *
	 *	@since		1.0
	 */	
	virtual ~ICertificateStore(void) {}


// Operation
public:
	/** 
	 *  Gets the @c name of the certificate store.
	 *
	 *	@since		1.0
	 *  @return     An error code
	 *  @param[out]	name                    The name of the certificate store
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception  E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 */
	virtual result GetName(Osp::Base::String& name)  = 0;

	

	/**
	 *	Sets a list of certificates that match the specified selector.
	 *
	 *	@since		1.0
	 *	@return		An error code
	 *  @param[in]  selector				A selector that defines a set of criterion for selecting certificates
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *  @exception	E_INVALID_ARG			The specified @c selector is invalid.
	 *  @exception 	E_UNSUPPORTED_OPERATION The type of @c selector is invalid.
	 *	@exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	virtual	result	SetCertificateSelector(Osp::Security::Cert::ICertificateSelector &selector)  = 0;


	/**
	 *	Gets the count of certificates that match the specified selector.
	 *
	 *	@since		1.0
	 *  @return     An error code
	 *  @param[out] count                   The count of certificates
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	virtual result	GetCertificateCount(int& count)  = 0;


	/**
	 *	Gets each certificate that matches the specified selector.
	 *
	 *	@since		1.0
	 *	@return		The certificates that match the specified selector
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
	 *	@exception	E_SYSTEM				A system error has occurred.	
	 *	@exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	virtual Osp::Security::Cert::ICertificate*	GetNextCertificateN(void)  = 0;


	/** 
	 *  Inserts the certificate into the certificate store.
	 *
	 *	@since		1.0
	 *	@return		An error code
	 *  @param[in]	certificateType			The type of the Certificate (that is, ROOT_CA, OPERATOR_DOMAIN, or TRUSTED_THIRD_PARTY_DOMAIN)
	 *  @param[in]	certificate				A reference to the certificate to be inserted
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_OBJ_NOT_FOUND			The @c certificate is not found.
	 *	@exception	E_INVALID_ARG			The specified @c certificate or the certificate data is invalid, @n
	 *										or the specified @c certificateType is invalid.
	 *	@exception	E_IO					The method has failed to operate the certificate store.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	virtual result Insert(CertificateType certificateType, const Osp::Security::Cert::ICertificate &certificate)  = 0;


	/** 
	 *  Updates the certificate in the certificate store.
	 *
	 *	@since		1.0
	 *	@return		An error code
	 *  @param[in]	certificateType			The type of the Certificate (that is, ROOT_CA, OPERATOR_DOMAIN, or TRUSTED_THIRD_PARTY_DOMAIN)
	 *  @param[in]	oldCert					A reference to the old certificate
	 *  @param[in]	newCert					A reference to the new certificate
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified @c certificate or the certificate data is invalid, @n
	 *										or the specified @c certificateType is invalid.
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
	 *	@exception	E_IO					The method has failed to operate the certificate store.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	virtual result Update(CertificateType certificateType, const Osp::Security::Cert::ICertificate& oldCert, const Osp::Security::Cert::ICertificate& newCert)  = 0;


	/** 
	 *  Removes the certificate from the certificate store.
	 *
	 *	@since		1.0
	 *	@return		An error code
	 *  @param[in]	certificateType			The type of the Certificate (that is, ROOT_CA, OPERATOR_DOMAIN, or TRUSTED_THIRD_PARTY_DOMAIN)
	 *  @param[in]	certificate				A reference to the certificate to be removed
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified @c certificate or the certificate data is invalid, @n
	 *										or the specified @c certificateType is invalid.
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
	 *	@exception	E_IO					The method has failed to operate the certificate store.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	virtual result Remove(CertificateType certificateType, const Osp::Security::Cert::ICertificate &certificate)  = 0;
	

};
}; }; }; // Osp::Security::Cert


#endif//_FSEC_CERT_ICERTIFICATE_STORE_H_
