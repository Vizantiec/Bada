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
 * @file		FSecCert.h
 * @brief		This is the header file for the %Cert namespace.
 *
 * This is the header file for the %Cert namespace.
 */
#ifndef _FSEC_CERT_H_
#define _FSEC_CERT_H_


// Includes
#include "FSecCertICertificate.h"
#include "FSecCertICertificatePath.h"
#include "FSecCertICertificatePathValidationParameter.h"
#include "FSecCertICertificateSelector.h"
#include "FSecCertICertificateStore.h"
#include "FSecCertX509Certificate.h"
#include "FSecCertX509CertificatePath.h"
#include "FSecCertX509CertificatePathValidationParameter.h"
#include "FSecCertX509CertificateSelector.h"
#include "FSecCertX509CertificateStore.h"


/**
 * @namespace	Osp::Security::Cert
 * @brief		This namespace contains classes and interfaces for managing the X.509 digital certificate.
 * @since		1.0
 *
 * @remarks @b Header @b %file: @b \#include @b <FSecurity.h> @n
 *			@b Library: @b FOsp
 *
 *
 * 
 *
 * The %Cert namespace contains classes and interfaces for managing certificates, by getting information from security certificates and validating their paths.
 *
 * For more information on the %Cert namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/certificate_namespace.htm">Cert Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Cert namespace.
 * @image html security_cert_classes.png 
 * 

 */
namespace Osp{ namespace Security { namespace Cert
{

}; }; }; // Osp::Security::Cert

#endif // _FSEC_CERT_H_
