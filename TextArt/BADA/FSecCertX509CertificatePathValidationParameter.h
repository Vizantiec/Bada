/* $Change: 1265123 $ */
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
 * @file		FSecCertX509CertificatePathValidationParameter.h
 * @brief		This is the header file for the %X509CertificatePathValidationParameter class.
 *
 * This header file contains the declarations of the %X509CertificatePathValidationParameter class.
 */
#ifndef _FSEC_CERT_X509_CERTIFICATE_PATH_VALIDATION_PARAMETER_H_
#define _FSEC_CERT_X509_CERTIFICATE_PATH_VALIDATION_PARAMETER_H_


// Includes
#include "FSecCertICertificatePathValidationParameter.h"
#include "FBaseObject.h"
#include "FBase.h"


namespace Osp { namespace Security { namespace Cert {
/**
 *  @class		X509CertificatePathValidationParameter 
 *  @brief		This class is used for certificate path validation.
 *  @deprecated This class is deprecated because the platform does not support certificate path validation parameter. Do not use this class in your application.
 *	@since		1.0
 *
 * The %X509CertificatePathValidationParameter class is used for certificate path validation.
 */
class _EXPORT_SECURITY_ X509CertificatePathValidationParameter :
	public virtual ICertificatePathValidationParameter,
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class. 
	 *
	 * 	@deprecated    This method is deprecated.
	 *	@since		1.0
	 */	
	X509CertificatePathValidationParameter(void);


	/** 
	 *	This is the destructor for this class. 
	 *
	 * 	@deprecated    This method is deprecated.
	 *	@since		1.0
	 */	
	~X509CertificatePathValidationParameter(void);


// Operation
public:
	/** 
	 *  Checks the value of the RevocationEnabled flag. @n
	 *	If this flag is set to @c true, the default revocation checking mechanism is used.
	 *	If this flag is set to @c false, the default revocation checking mechanism is disabled (not used). 
	 *
	 * 	@deprecated    This method is deprecated.
	 *	@since		1.0
	 *	@return		The current value of the RevocationEnabled flag
	 *	@see		Osp::Security::Cert::ICertificatePathValidationParameter::SetRevocationEnabled(bool value)
	 */
	virtual bool IsRevocationEnabled(void);


	/** 
	 *  Sets the value of the RevocationEnabled flag to the specified value. @n
	 *	If this flag is set to @c true, the default revocation checking mechanism is used.
	 *	If this flag is set to @c false, the default revocation checking mechanism is disabled (not used).
	 *  When a %ICertificatePathValidationParameter type object is created, this flag is set to @c false. 
	 *
	 * 	@deprecated    This method is deprecated.
	 *	@since			1.0
	 *	@param[in]	value	The new value of the RevocationEnabled flag
	 */
	virtual void SetRevocationEnabled(bool value);


	/** 
	 *  Sets the RevocationType flag. @n
	 *	It specifies the scheme that is to be used when checking the revocation status of the certificate.
	 *
	 * 	@deprecated    This method is deprecated.
	 *	@since		1.0
	 *	@return		An error code
	 *  @param[in]	revocationType			The revocation type
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The specified @c revocationType is not supported.
	 *  @remarks   	Currently "OCSP" is only supported
	 */
	virtual result SetRevocationType(Osp::Base::String revocationType);


	/**
	 *  Gets the name of the RevocationType flag. @n
	 *	It specifies the scheme that is to be used when checking the revocation status of the certificate.
 	 *
	 * 	@deprecated    This method is deprecated.
	 *	@since		1.0
	 *	@return		The name of the RevocationType flag
	 */
	virtual Osp::Base::String GetRevocationType(void);


	/** 
	 *  Sets the String ArrayList of initial policy identifiers (OID strings), 
	 *  indicating that any one of these policies would be acceptable to the certificate user 
	 *  for the purposes of certification path processing. By default, any policy is acceptable; 
	 *  so a user that wants to allow any policy as acceptable does not need to call this method, 
	 *  or the user can call it with an empty Set (or @c null).
	 *
	 * 	@deprecated    This method is deprecated.
	 *	@since		1.0
	 *	@return		An error code
	 *  @param[in]	pPolicies				The initial policy OIDs in String format (or @c null) 
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c pPolicies is invalid or an empty string.
	 */
	result SetInitialPolicies(Osp::Base::Collection::ArrayListT<Osp::Base::String> *pPolicies);


	/** 
	 *  Gets an immutable ArrayList of initial policy identifiers (OID strings), 
	 *  indicating that any one of these policies would be acceptable to the certificate user 
	 *  for the purposes of certification path processing. The default return value is an empty ArrayList, 
	 *  which is assumed to mean that any policy would be acceptable. 
	 *
	 * 	@deprecated    This method is deprecated.
	 *	@since		1.0
	 *	@return		The initial policy OIDs
	 */
	Osp::Base::Collection::ArrayListT<Osp::Base::String>*	GetInitialPolicies(void) const;


	/**
	 *	Checks whether the policy OID should be processed if it is included in a certificate. 
	 *	
	 * 	@deprecated    This method is deprecated.
	 *	@since		1.0
	 *	@return		@c true if the policy OID is inhibited, @n
	 *				else @c false
	 */
	bool IsAnyPolicyInhibited(void);


	/**
	 *	Checks the state to determine whether the policy OID should be processed if it is included in a certificate. @n
	 *  By default, the policy OID is not inhibited.
	 *
	 * 	@deprecated    This method is deprecated.
	 *	@since		1.0
	 *  @param[in]	value	Set to @c true if the policy OID is to be inhibited, @n
	 *						else @c false
	 */
	void SetAnyPolicyInhibited(bool value);


	/**
	 *	Checks whether an explicit policy is required. @n
	 *	If this flag is set to @c true, an acceptable policy needs to be 
	 *  explicitly identified in every certificate. By default, the ExplicitPolicyRequired flag is set to @c false. 
	 *	
	 * 	@deprecated    This method is deprecated.
	 *	@since		1.0
	 *	@return		@c true if an explicit policy is required, @n
	 *				else @c false
	 */
	bool IsExplicitPolicyRequired(void);


	/**
	 *	Sets the ExplicitPolicyRequired flag. @n
	 *	If this flag is set to @c true, an acceptable policy 
	 *  needs to be explicitly identified in every certificate. By default, the ExplicitPolicyRequired flag is set to @c false. 
	 *  
	 * 	@deprecated    This method is deprecated.
	 *	@since			1.0
	 *	@param[in]	value	Set to @c true if an explicit policy is required, @n
	 *						else @c false
	 */
	void SetExplicitPolicyRequired(bool value);


	/**
	 *	Checks whether the policy mapping is inhibited. @n
	 *	If this flag is set to @c true, policy mapping is inhibited.
	 *  By default, policy mapping is not inhibited, that is, the flag is set to @c false. 
	 *	
	 * 	@deprecated    This method is deprecated.
	 *	@since		1.0
	 *	@return		@c true if the policy mapping is inhibited, @n
	 *				else @c false
	 */
	bool IsPolicyMappingInhibited(void);


	/**
	 *	Sets the PolicyMappingInhibited flag. @n
	 *	If this flag is set to @c true, policy mapping is inhibited.
	 *  By default, policy mapping is not inhibited, that is, the flag is set to @c false. 
	 *
	 * 	@deprecated    This method is deprecated.
	 *	@since		1.0
	 *  @param[in]	value	Set to @c true if policy mapping is to be inhibited, @n
	 *						else @c false
	 */
	void SetPolicyMappingInhibited(bool value);


	/**
	 *	Gets the PolicyQualifiersRejected flag. @n
	 *	If this flag is set to @c true, certificates that include policy qualifiers 
	 *  in a certificate policies extension that is marked critical, are rejected. 
	 *	If the flag is set to @c false, certificates are not rejected on this basis.
	 * 
	 *  When a X509CertificatePathValidationParameter object is created, this flag is set to @c true.
	 *  This setting reflects the most common (and simplest) strategy for processing policy qualifiers.
	 *  Applications that want to use a more sophisticated policy must set this flag to @c false. 
	 *	
	 * 	@deprecated    This method is deprecated.
	 *	@since		1.0
	 *	@return		The current value of the PolicyQualifiersRejected flag
	 */
	bool GetPolicyQualifiersRejected(void);


	/**
	 *	Sets the PolicyQualifiersRejected flag. @n
	 *	If this flag is set to @c true, certificates that include policy qualifiers 
	 *  in a certificate policies extension that is marked critical are rejected.
	 *	If the flag is set to @c false, certificates are not rejected on this basis.
	 *
	 *  When a X509CertificatePathValidationParameter object is created, this flag is set to @c true.
	 *  This setting reflects the most common (and simplest) strategy for processing policy qualifiers.
	 *  Applications that want to use a more sophisticated policy must set this flag to @c false. 
	 *
	 * 	@deprecated    This method is deprecated.
	 *	@since		1.0
	 *  @param[in]	qualifiersRejected		The new value of the PolicyQualifiersRejected flag
	 */
	void SetPolicyQualifiersRejected(bool qualifiersRejected);


private:
	bool	m_bRevocationEnabled;
	bool	m_bAnyPolicyInhibited;
	bool	m_bExplicitPolicyRequired;
	bool	m_bPolicyMappingInhibited;
	bool	m_bPolicyQualifiersRejected;
	Osp::Base::Collection::ArrayListT<Osp::Base::String> *m_pPolicies;
	friend class	X509CertificatePathValidationParameterEx;
	class X509CertificatePathValidationParameterEx*	__pX509CertificatePathValidationParameterEx;
};
}; }; }; // Osp::Security::Cert


#endif//_FSEC_CERT_X509_CERTIFICATE_PATH_VALIDATION_PARAMETER_H_
