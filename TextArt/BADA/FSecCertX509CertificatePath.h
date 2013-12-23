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
 * @file		FSecCertX509CertificatePath.h
 * @brief		This is the header file for the %X509CertificatePath class.
 *
 * This header file contains the declarations of the %X509CertificatePath class.
 */
#ifndef _FSEC_CERT_X509_CERTIFICATE_PATH_H_
#define _FSEC_CERT_X509_CERTIFICATE_PATH_H_


// Includes
#include "FBaseObject.h"
#include "FSecCertICertificatePath.h"


namespace Osp { namespace Security { namespace Cert {

class ICertificatePathPi;
/**
 *  @class		X509CertificatePath 
 *  @brief		This class provides the certificate path.
 *	@since		1.0
 *
 * The %X509CertificatePath class provides the certificate path.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/certificate_namespace.htm">Certificates</a>.
 */
class _EXPORT_SECURITY_ X509CertificatePath :
	public virtual ICertificatePath,
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class.
	 *
	 *	@since		1.0
	 */	
	X509CertificatePath(void);


	/** 
	 *	This is the destructor for this class. 
	 *
	 *	@since		1.0
	 */	
	~X509CertificatePath(void);


// Operation
public:
	/** 
	 *  Gets the format name for the certificate path.
	 *
	 *	@since		1.0
	 *	@return		The format of the certificate
	 */
	virtual Osp::Base::String GetFormat(void) const;


	/** 
	 *  Adds a certificate to the certificate chain.
	 *
	 *	@since		1.0
	 *	@return		An error code
	 *  @param[in]	certificate				A reference to a certificate
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c certificate or the certificate data is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
 	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result AddCertificate(const Osp::Security::Cert::ICertificate& certificate);


	/** 
	 *  Validates the specified certificate path.
	 *
	 *	@since		1.0
	 *	@return		The result of the certificate path validation
	 */	
	virtual Osp::Security::Cert::ValidationResult		Validate(void);


	/** 
	 *  Validates the specified certificate path.
	 *
	 *	@since		1.0
	 *	@return		The result of the certificate path validation
	 *  @param[in]	trustAnchor				The most trusted Certificate Authority (CA) 
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified input parameter is invalid.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */	
	virtual Osp::Security::Cert::ValidationResult		Validate(const Osp::Security::Cert::ICertificate& trustAnchor);

	/** 
	 *  Gets the length of the certificate path.
	 *
	 *	@since		1.0
	 *	@return		The length of the certificate path, @n
	 *				else @c -1 if an error occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual int GetLength(void);

	/**
	 *	Gets the list of the certificates in this certificate path.
	 *
	 *	@since		1.0
	 *	@return		A pointer to the %ICertificate class, @n
	 *				else @c null if an error occurs
	 *  @param[in]	nth						The nth certificate in the certificate path (starts from @c 0)
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The value of the specified @c nth is out of the valid range,
	 *										or it must be less than GetLength().
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual Osp::Security::Cert::ICertificate*	GetCertificateN(int nth);

	/**
	 *	Gets the trust anchor for the certificate path.
	 *
	 *	@since		1.0
	 *	@return		The root certificate, @n
	 *				else @c null if an error occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual Osp::Security::Cert::ICertificate*	GetTrustAnchorN(void);


private:
	ICertificatePathPi	*m_pCertPathPi;
	friend class		X509CertificatePathEx;
	class X509CertificatePathEx* __pX509CertificatePathEx;


};
}; }; }; // Osp::Security::Cert


#endif//_FSEC_CERT_X509_CERTIFICATE_PATH_H_
