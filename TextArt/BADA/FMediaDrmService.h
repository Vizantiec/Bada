// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 *	@file	FMediaDrmService.h
 *	@brief	This is the header file for the %DrmService class.
 *
 *	This header file contains the declarations of the %DrmService class.
 */
#ifndef FMEDIA_DRMSERVICE_H_
#define FMEDIA_DRMSERVICE_H_

#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaIDrmServiceEventListener.h"
#include "FMediaDrmConstants.h"

namespace Osp { namespace Media {

/**
 *  @if PRIVCORE
 *	@class	DrmService
 *	@brief	This class processes the Digital Rights Management (DRM) related operations.
 *	@since	2.0
 *
 *  The %DrmService class provides the DRM services such as obtaining a license, joining a domain, or leaving a domain.
 *  It also sends the metering information (the count of how many times a file is played) to the DRM server.
 *  Supported DRM type: DRM_PLAYREADY
 *
 
 *
 * The following example demonstrates how to use the %DrmService class.
 * @code
#include <FMedia.h>
#include <FBase.h>

using namespace Osp::Media;
using namespace Osp::Base;

class DrmServiceApp :
	public Osp::Base::Object,
	public IDrmServiceEventListener
{
public:
	DrmServiceApp();
	virtual ~DrmServiceApp();
	result Start(void);
	result SendMeteringInformation(void);
	result Stop(void);

protected:
	void OnDrmServiceLicenseReceived(DrmService &src, RequestId reqId, result r, const Osp::Base::String *pErrorMsg, const Osp::Base::String *pResponse );
	void OnDrmServiceJoinedDomain(DrmService &src, RequestId reqId, result r, const Osp::Base::String *pErrorMsg, const Osp::Base::String *pResponse );
	void OnDrmServiceLeftDomain(DrmService &src, RequestId reqId, result r, const Osp::Base::String *pErrorMsg, const Osp::Base::String *pResponse );
	void OnDrmServiceMeteringInfoSent(DrmService &src, RequestId reqId, result r, const Osp::Base::String *pErrorMsg, const Osp::Base::String *pResponse );

protected:
	DrmService drmSvc;
	RequestId joinReqId, leaveReqId, licenseReqId, meteringReqId;
	String drmFile;
	String joinMsg, leaveMsg, meteringMsg;
};

DrmServiceApp::DrmServiceApp()
{
	joinReqId = 0;
	leaveReqId = 0;
	licenseReqId = 0;
	meteringReqId = 0;
}

DrmServiceApp::~DrmServiceApp()
{
}

void
DrmServiceApp::OnDrmServiceLicenseReceived(DrmService &src, RequestId reqId, result r, const Osp::Base::String *pErrorMsg, const Osp::Base::String *pResponse )
{
	licenseReqId = 0;
	if (IsFailed(r)) {
		// handle exception
	} else {
		// handle license acquired contents for playing with the player
	}
}

void
DrmServiceApp::OnDrmServiceJoinedDomain(DrmService &src, RequestId reqId, result r, const Osp::Base::String *pErrorMsg, const Osp::Base::String *pResponse )
{
	joinReqId = 0;
	if (IsFailed(r)) {
		// handle exception
	} else {
		r = drmSvc.RequestLicense(drmFile, licenseReqId);
		if (IsFailed(r)) {
			// handle exception
		}
	}
}

void
DrmServiceApp::OnDrmServiceLeftDomain(DrmService &src, RequestId reqId, result r, const Osp::Base::String *pErrorMsg, const Osp::Base::String *pResponse )
{
	leaveReqId = 0;
	if (IsFailed(r)) {
		// handle exception
	}
}

void
DrmServiceApp::OnDrmServiceMeteringInfoSent(DrmService &src, RequestId reqId, result r, const Osp::Base::String *pErrorMsg, const Osp::Base::String *pResponse )
{
	meteringReqId = 0;
	if (IsFailed(r)) {
		// handle exception
	}
}

result
DrmServiceApp::Start(void)
{
	result r;

	drmFile = "/Home/test.drm";
	r = drmSvc.Construct(DRM_PLAYREADY, *this);
 	if (IsFailed(r))
 		goto CATCH;

 	// generate the join message
 	// ...
 	// send the join message to the server
 	r = drmSvc.JoinDomain(joinMsg, joinReqId);
 	if (IsFailed(r))
 		goto CATCH;
 	return r;
CATCH:
	AppLog("failed:%s", GetErrorMessage(r));
	return r;
}

result
DrmServiceApp::SendMeteringInformation(void)
{
	result r;

	// generate metering information
	// ...
	// send metering information
 	r = drmSvc.SendMeteringInfo(meteringMsg, meteringReqId);
 	if (IsFailed(r))
 		goto CATCH;
 	return E_SUCCESS;
CATCH:
	return r;
}

result DrmServiceApp::Stop(void)
{
	result r;

	r = drmSvc.LeaveDomain(leaveMsg, leaveReqId);
	if (IsFailed(r))
		goto CATCH;
	return E_SUCCESS;
CATCH:
	return r;
}

 * @endcode
 * @endif
 */
class _EXPORT_MEDIA_ DrmService :
	public Osp::Base::Object
{
public:

	/**
	 * This is the default constructor for this class.
	 * @since		2.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to 
	 *				initialize this instance.
	 * @see 		Construct()
	 */
	DrmService(void);

	/**
	 *	This is the destructor for this class.
	 *	@since	2.0
	 */
	virtual ~DrmService(void);

	/**
	 * Initializes this instance of DrmService with the specified parameters.
	 * @since		2.0
	 * @privlevel   CORE
	 * @privgroup   DRM_SERVICE
	 * @return		An error code
	 * @param[in]	type				The DRM type
	 * @param[in]	listener			An IDrmServiceEventListener instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE 	This method is invalid for the current state of this instance.
	 * @exception	E_UNSUPPORTED_TYPE	The specified DRM type is not supported.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_INVALID_ARG 		A specified input parameter is invalid.
	 * @exception	E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		Only DRM_PLAYREADY is supported as of 2.0. Other DRM types such as OMA-DRM and WM-DRM are not supported.
	 * @see 		DrmType
	 */
	result Construct(DrmType type, const IDrmServiceEventListener &listener);


public:

	/**
	 * Requests the license for the specified file. @n
	 * This method sends the license acquisition challenge to the license server. The result is notified using 
	 * IDrmServiceEventListener::OnDrmServiceLicenseReceived().
	 *
	 * @since	2.0
	 * @privlevel   CORE
	 * @privgroup   DRM_SERVICE
	 * @return		An error code
	 * @param[in]	path				The file path of the content
	 * @param[out]	reqId				The request ID
	 * @param[in]	pCustomData			The user data that is added in the request message
	 * @param[in]	pHeader				The additional SOAP header that is added to the request header
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	 * @exception	E_SERVICE_BUSY		The DRM service is busy.
	 * @exception	E_FILE_NOT_FOUND	The specified file cannot be found.
	 * @exception	E_INVALID_CONTENT	The specified file or the license file is invalid.
	 * @exception	E_INVALID_ARG 		A specified input parameter is invalid.
	 * @exception	E_OPERATION_FAILED	This operation has failed.
	 * @exception	E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM 			A system error has occurred.
	 * @remarks	 	Some service providers may have to call the JoinDomain() method before this method is called. 
	 *				The E_NOT_JOINED exception is passed through IDrmServiceEventListener if the client has not 
	 *				joined the domain controller for those service providers.
	 */
	result RequestLicense(const Osp::Base::String &path, RequestId &reqId, const Osp::Base::String *pCustomData = null, const Osp::Base::String *pHeader = null);


	/**
	 * Joins the DRM domain with the specified message. @n
	 * The result is notified using IDrmServiceEventListener::OnDrmServiceJoinedDomain().
	 *
	 * @since		2.0
	 * @privlevel   CORE
	 * @privgroup   DRM_SERVICE
	 * @return		An error code
	 * @param[in]	message				The join message that is sent to the domain server
	 * @param[out]	reqId				The request ID
	 * @param[in]	pHeader				The additional SOAP header that is added to the request header
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	 * @exception	E_SERVICE_BUSY		The DRM service is busy.
	 * @exception	E_INVALID_ARG 		A specified input parameter is invalid.
	 * @exception	E_INVALID_DATA		The @c message or header has an invalid data.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception	E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM 			A system error has occurred.
	 */
	result JoinDomain(const Osp::Base::String &message, RequestId &reqId, const Osp::Base::String *pHeader=null);

	/**
	 * Leaves the DRM domain with the specified message. @n
	 * The result is notified using IDrmServiceEventListener::OnDrmServiceLeftDomain().
	 *
	 * @since		2.0
	 * @privlevel   CORE
	 * @privgroup   DRM_SERVICE
	 * @return		An error code
	 * @param[in]	message				The leave message that is sent to the domain server
	 * @param[out]	reqId				The request ID
	 * @param[in]	pHeader				The additional SOAP header that is added to the request header
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	 * @exception	E_SERVICE_BUSY		The DRM service is busy.
	 * @exception	E_INVALID_ARG 		A specified input parameter is invalid.
	 * @exception	E_INVALID_DATA		The @c message or header has an invalid data.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception	E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM 			A system error has occurred.
	 */
	result LeaveDomain(const Osp::Base::String &message, RequestId &reqId, const Osp::Base::String *pHeader = null);

	/**
	 * Sends the metering information to the DRM server. @n
	 * The result is notified using IDrmServiceEventListener::OnDrmServiceMeteringInfoSent().
	 *
	 * @since		2.0
	 * @privlevel   CORE
	 * @privgroup   DRM_SERVICE
	 * @return		An error code
	 * @param[in]	message				The metering information that is sent to the domain server
	 * @param[out]	reqId				The request ID
	 * @param[in]	pHeader				The additional SOAP header that is added to the request header
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	 * @exception	E_SERVICE_BUSY		The DRM service is busy.
	 * @exception	E_INVALID_ARG 		A specified input parameter is invalid.
	 * @exception	E_INVALID_DATA		The @c message or header has an invalid data.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception	E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM 			A system error has occurred.
	 */
	result SendMeteringInfo(const Osp::Base::String &message, RequestId &reqId, const Osp::Base::String *pHeader = null);


protected:

private:
	DrmService(const DrmService& ds);
	DrmService& operator =(const DrmService& ds);

	class IDrmServicePi* __pPi;
	class __DrmServiceEvent*   __pEvent;
	
	void* __reserved01;
	void* __reserved02;
	
	class __DrmServiceEx* __pEx;
friend class __DrmServiceEx;
};

}; };


#endif
