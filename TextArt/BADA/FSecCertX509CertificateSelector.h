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
 * @file		FSecCertX509CertificateSelector.h
 * @brief		This is the header file for the %X509CertificateSelector class.
 *
 * This header file contains declarations of the %X509CertificateSelector class.
 */
#ifndef _FSEC_CERT_X509_CERTIFICATE_SELECTOR_H_
#define _FSEC_CERT_X509_CERTIFICATE_SELECTOR_H_


// Includes
#include "FSecCertICertificateSelector.h"


namespace Osp { namespace Security { namespace Cert {
/**
 *	@class		X509CertificateSelector 
 *	@brief		This class is used for managing a variety of identity certificates.
 *	@since		1.0
 *
 * The %X509CertificateSelector class is used for managing a variety of identity certificates.
 *
 *  @see		ICertificate, Osp::Security::Cert::ICertificateSelector
 */
class _EXPORT_SECURITY_ X509CertificateSelector:
	public virtual ICertificateSelector,
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 *	This is the constructor for this class. 
	 *
	 *	@since		1.0
	 */	
	X509CertificateSelector();


	/** 
	 *	This is the destructor for this class. 
	 *
	 *	@since		1.0
	 */	
	virtual ~X509CertificateSelector(void);


// Operation
public:
	/**
	 *	Gets the certificate type.
	 *	
	 *	@since		1.0
	 *  @return 	The certificate type
	 */
	virtual CertificateType GetType(void);


	/** 
	 * Sets the certificate type.
	 *
	 *	@since			1.0
	 *  @param[in]	certificateType		The certificate type
	 */
	virtual void	SetType(const CertificateType certificateType);


private:
	CertificateType	m_certType;
	friend class X509CertificateSelectorEx;
	class X509CertificateSelectorEx*	__pX509CertificateSelectorEx;


};
}; }; }; // Osp::Security::Cert

#endif//_FSEC_CERT_X509_CERTIFICATE_SELECTOR_H_
