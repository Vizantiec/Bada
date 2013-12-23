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
 * @file	FNetHttpIHttpTransactionEventListener.h 
 * @brief	This is the header file for the %IHttpTransactionEventListener interface.
 *
 * This header file contains the declarations of the %IHttpTransactionEventListener interface.
 */

#ifndef _FNET_HTTP_IHTTP_TRANSACTION_EVENT_LISTENER_H_
#define _FNET_HTTP_IHTTP_TRANSACTION_EVENT_LISTENER_H_

// Includes
#include "FBaseTypes.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Net { namespace Http {
class HttpSession;
class HttpTransaction;
/**
 * @interface	IHttpTransactionEventListener
 * @brief		This interface provides listeners for the HTTP transaction events.
 * @since 		1.0
 *
 * @remarks	If a user-defined class is derived from multiple classes including this interface, a compile error for using an ambiguous base class can occur. @n
 * 			In this case, type casting is required to declare an explicit base class for the user-defined class. 
 *
 * 	The %IHttpTransactionEventListener interface provides listeners for the %HTTP transaction events. To use this listener, you must add it to the HttpTransaction instance 
 *				through the AddListener() method. If an %HTTP transaction event is generated, a method of this class is called. 
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/http_transaction.htm">HTTP Transaction</a>. @n
 *
 * The following example demonstrates how to use the %IHttpTransactionEventListener interface.
 * @code
 *
 *	class MyEventListener :
 *		public IHttpTransactionEventListener
 *	{
 *		public:
 *		MyEventListener() {}
 *		~MyEventListener() {}
 *
 *		void OnTransactionReadyToRead(HttpSession& httpSession, HttpTransaction& httpTransaction, int availableBodyLen)
 *		{
 *			AppLog("OnTransactionReadyToRead\n");
 *		}
 *
 *		void OnTransactionAborted(HttpSession& httpSession, HttpTransaction& httpTransaction, result r)
 *		{
 *			AppLog("OnTransactionAborted\n");
 *		}
 *
 *		void OnTransactionReadyToWrite(HttpSession& httpSession, HttpTransaction& httpTransaction, int recommendedChunkSize)
 *		{
 *			AppLog("OnTransactionReadyToWrite\n");
 *		}
 *		
 *		void OnTransactionHeaderCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction, int headerLen, bool bAuthRequired)
 *		{
 *			AppLog("OnTransactionHeaderCompleted\n");
 *		}
 *		
 *		void OnTransactionCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction)
 *		{
 *			AppLog("OnTransactionCompleted\n");
 *		}
 *
 *		void OnTransactionCertVerificationRequiredN(HttpSession& httpSession, HttpTransaction& httpTransaction, String* pCert)
 *		{
 *			AppLog("OnTransactionCertVerificationRequiredN\n");
 *		}
 *	};
 *
 *
 * @endcode
 */

class _EXPORT_NET_ IHttpTransactionEventListener :
	public /*virtual*/ Osp::Base::Runtime::IEventListener,
	public Osp::Base::Object
{
// Lifecycle
public:
   /** 
    * This is the destructor for this class.
	*
	* @since 	1.0
	*/
	virtual ~IHttpTransactionEventListener(void) {}


// Operation
public:
	/**
	 * Called to notify when the content body of the response has been received. @n
	 * Listens to the HTTP_EVENT_READ_BODY event.
	 * 
	 * @since 		1.0
	 * @param[in]	httpSession					The session information of the %Http transaction event
	 * @param[in]	httpTransaction				The transaction information of the %Http transaction event
	 * @param[in]	availableBodyLen			The length of the available body of the %Http transaction
	 * @see			HttpResponse::ReadBodyN()
	 */
	virtual void OnTransactionReadyToRead(HttpSession& httpSession, HttpTransaction& httpTransaction, int availableBodyLen) = 0;


	/**
	 * Called to notify when the process of transaction has been aborted. @n
	 * Listens to the HTTP_EVENT_ABORT_REQUEST event.
	 * 
	 * @since 		1.0
	 * @param[in]	httpSession					The session information of the %Http transaction event
	 * @param[in]	httpTransaction				The transaction information of the %Http transaction event
	 * @param[in]	r							The cause of the error
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_IO						The method has failed to read the data.
	 * @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
	 * @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	 * @exception	E_HOST_UNREACHABLE			The network cannot be reached from this host at this time.
	 * @exception	E_SYSTEM					An internal error has occurred.
	 * @exception	E_UNKNOWN					An unknown error has occurred.
	 * @exception	E_NOT_RESPONDING			There is no response.
	 * @exception	E_INVALID_CONTENT			The content is invalid.
	 * @exception	E_CONNECTION_RESET			The network connection has been reset.
	 * @exception	E_HTTP_USER					The HTTP user is canceled.
	 * @exception	E_NO_CERTIFICATE			The client certificate is required to connect to the server @b since: @b 2.0.
	 * @exception	E_UNSUPPORTED_SERVICE		The service is not allowed.
	 * @exception	E_USER_AGENT_NOT_ALLOWED	The user agent is not allowed.
	 * @exception	E_RESOURCE_UNAVAILABLE		The network resource is unavailable.
	 * @remarks 	If the E_NO_CERTIFICATE exception is thrown, start the AppControl(APPCONTROL_PROVIDER_CERTIFICATE_MANAGER) for getting the selected client certificate. @n
	 *          	For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_certmgr.htm">Certificate Manager Application Control</a>. (Osp::App::APPCONTROL_PROVIDER_CERTIFICATE_MANAGER)
	 */
	virtual void OnTransactionAborted(HttpSession& httpSession, HttpTransaction& httpTransaction, result r) = 0;


	/**
	 * Called to add chunks to the request. @n
	 * Listens to the HTTP_EVENT_WRITE_REQ event.
	 *
	 * @since 		1.0
	 * @param[in]	httpSession					The session information of the %Http transaction event
	 * @param[in]	httpTransaction				The transaction information of the %Http transaction event
	 * @param[in]	recommendedChunkSize		The length of the chunked %Http transaction
	 * @remarks 		To enable this listener, HttpTransaction::EnableTransactionReadyToWrite() must be called.
	 * @see			HttpRequest::WriteBody()
	 */
	virtual void OnTransactionReadyToWrite(HttpSession& httpSession, HttpTransaction& httpTransaction, int recommendedChunkSize) = 0;


	/**
	 * Called to notify when the header of response has been received. @N
	 * Listens to the HTTP_EVENT_READ_HEADER event.
	 *
	 * @since 		1.0
	 * @param[in]	httpSession					The session information of the %Http transaction event
	 * @param[in]	httpTransaction				The transaction information of the %Http transaction event
	 * @param[in]	headerLen					The length of the %Http transaction's header
	 * @param[in]	bAuthRequired				Set to @c true if the transaction requires authentication, @n
	 *											else @c false
	 * @see			HttpResponse::GetHeader()
	 */
	virtual void OnTransactionHeaderCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction, int headerLen, bool bAuthRequired) = 0;


	/**
	 * Called to notify when the process of transaction has been completed. @n
	 * Listens to the HTTP_EVENT_READ_COMPLETE event.
	 * 
	 * @since 		1.0
	 * @param[in]	httpSession					The session information of the %Http transaction event
	 * @param[in]	httpTransaction				The transaction information of the %Http transaction event
	 * @see			HttpResponse::GetHeader(), HttpResponse::ReadBodyN()
	 */
	virtual void OnTransactionCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction) = 0;

	/**
	 * Called to accept input from the user on whether to resume or pause the transaction in case the certificate is not verified. @n 
	 * Listens to the NET_HTTP_EVENT_CERT event.
	 * 
	 * @since 			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                	For more information, see @ref IHttpTransactionEventListenerOnTransactionCertVerificationRequiredNPage "here".
	 *
	 * @param[in]		httpSession				The session information of the %Http transaction event
	 * @param[in]		httpTransaction			The transaction information of the %Http transaction event
	 * @param[in]		pCert					The certificate information
	 * @see				HttpTransaction::Resume(), HttpTransaction::Pause()
	 */
	virtual void OnTransactionCertVerificationRequiredN(HttpSession& httpSession, HttpTransaction& httpTransaction, Osp::Base::String* pCert) = 0;

	/**
	 * @page	IHttpTransactionEventListenerOnTransactionCertVerificationRequiredNPage	Compatibility for OnTransactionCertVerificationRequiredN()
	 *
	 * @section	IHttpTransactionEventListenerOnTransactionCertVerificationRequiredNPageIssueSection	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# If the Resume() method is not called in OnTransactionCertVerificationRequiredN(), the Pause() method is called internally.
	 *
	 * @section	IHttpTransactionEventListenerOnTransactionCertVerificationRequiredNPageSolutionSection	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * -# The Pause() method is not called internally.
	 */

	};

}; }; }; // Osp::Net::Http
#endif // _FNET_HTTP_IHTTP_TRANSACTION_EVENT_LISTENER_H_

