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
 * @file		FSecCertICertificateSelector.h
 * @brief		This is the header file for the %ICertificateSelector interface.
 *
 * This header file contains the declarations of the %ICertificateSelector interface.
 */
#ifndef _FSEC_CERT_ICERTIFICATE_SELECTOR_H_
#define _FSEC_CERT_ICERTIFICATE_SELECTOR_H_


// Includes
#include "FSecCertICertificate.h"


namespace Osp { namespace Security { namespace Cert {
/**
 *  @interface	ICertificateSelector 
 *  @brief		This interface is a selector that defines a set of criterion for selecting certificates.
 *	@since		1.0
 *
 * The %ICertificateSelector interface is a selector that defines a set of criterion for selecting certificates.
 *	The classes that implement this interface are used to specify the certificates, which must be retrieved from a certificate store.  
 *
 */
class _EXPORT_SECURITY_ ICertificateSelector
{
// Lifecycle
public:
	/** 
	 *	This is the destructor for this class. 
	 *
	 *	@since		1.0
	 */	
	virtual ~ICertificateSelector(void) {}


// Operation
public:
	/**
	 *	Gets the certificate type.
	 *	
	 *	@since		1.0
	 *  @return 	The certificate type
	 */
	virtual CertificateType GetType(void)  = 0;


	/** 
	 * Sets the certificate type.
	 *
	 * @since			1.0
	 * @param[in]	certificateType		The certificate type
	 */
	virtual void	SetType(const CertificateType certificateType)  = 0;


};
}; }; }; // Osp::Security::Cert


#endif//_FSEC_CERT_ICERTIFICATE_SELECTOR_H_
