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
 * @file		FNetHttpHttpSession.h
 * @brief		This is the header file for the %HttpSession class.
 *
 * This header file contains the declarations of the %HttpSession class.
 */

#ifndef _FNET_HTTP_HTTP_SESSION_H_
#define _FNET_HTTP_HTTP_SESSION_H_

// Includes
#include "FNetConfig.h"
#include "FBaseString.h"
#include "FBaseUtilUri.h"
#include "FBaseByteBuffer.h"
#include "FBaseColArrayList.h"
#include "FBaseRtThreadMutex.h"
#include "FNetNetConnection.h"
#include "FNetHttpHttpTypes.h"
#include "FNetHttpHttpTransaction.h"
#include "FNetHttpHttpHeader.h"
#include "FNetHttpHttpCookieStorageManager.h"
#include "FNetHttpHttpAuthentication.h"

namespace Osp { namespace Net {
	class _DefaultNetConnection;
}};

namespace Osp { namespace Net { namespace Http {
class __HttpDefaultNetConnectionEventListenerImpl;
class __HttpSessionEvent;
class IHttpTransactionPi;
class IHttpSessionPi;
class HttpCookieStorageManager;
/**
 * @class	HttpSession
 * @brief	This class represents an HTTP session.
 * @since	1.0
 *
 * 	The %HttpSession class represents an HTTP session. The session encapsulates the client's HTTP activity over the duration of the client's execution. It is a set of transactions using the same 
 *			connection settings (such as proxy). The client may use several sessions concurrently if desired.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/http_session.htm">HTTP Session</a>. 
 
 * The following example demonstrates how to use the %HttpSession class.
 *
 * @code
 *
 *	#include <FBase.h>
 *	#include <FNet.h>
 *
 *	using namespace Osp::Base;
 *	using namespace Osp::Net;
 *	using namespace Osp::Net::Http;
 *
 *	void
 *	Test(void)
 *	{
 *
 *		result r = E_SUCCESS;
 *		String* pProxyAddr = null;
 *		String hostAddr = L"http://www.bada.com";
 *		HttpTransaction* pHttpTransaction = null;
 *
 *		// HttpSession instance allocation.
 *		HttpSession* pHttpSession = new HttpSession;
 * 		if (pHttpSession == null)
 *		{
 *			AppLog("HttpSession instance allocation failed. \n");
 *		}
 *
 *		// HttpSession construction.
 *		r = pHttpSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, pProxyAddr ,hostAddr, null);
 *		if (IsFailed(r))
 *		{
 *			AppLog("HttpSession construction failed. (%s)\n", GetErrorMessage(r));
 *		}
 *
 *		// Open a new HTTP Transaction.
 *		pHttpTransaction = pHttpSession->OpenTransactionN();
 *		if (null == pHttpTransaction)
 *		{
 *			r = GetLastResult();
 *			AppLog("OpenTransactionN failed. (%s)\n", GetErrorMessage(r));
 *		}
 *	}
 *
 * @endcode
 */

class _EXPORT_NET_ HttpSession :
	public Osp::Base::Object
{

// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 		1.0
	 * @remarks		After creating an instance of this class, one of the Construct() methods must be called explicitly to initialize the instance.
	 * @see			Construct()
	 */
	HttpSession(void);

	/**
	 * Initializes this instance of %HttpSession with the specified parameters.
	 * Opens a session using the default netConnection.
	 *
	 * @since 			1.0
	 * @compatibility 	This method has compatibility issues with different bada API versions. @n
	 *                	For more information, see issues in version @ref HttpSessionConstructPage1 "1.2" and @ref HttpSessionConstructPage2 "2.0".
	 *
	 * @return			An error code
	 * @param[in]		sessionMode				The session mode to open the session
	 * @param[in]		pProxyAddr				A proxy address @n
	 *											The specified @c proxyAddr must be a valid URL. If @c pProxyAddr is @c null, %HttpSession uses the system 
	 *											default proxy address.
	 * @param[in]		hostAddr				A host address @n
	 *											The specified @c hostAddr must be a valid URL.
	 * @param[in]		pCommonHeader			An instance of HttpHeader @n
	 *											This is a common header used in all the transactions included in this session.
	 * @param[in]		flag					Set to @c true if the cookies should be handled automatically, @n
	 *											else @c false if the cookies should be handled manually
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception		E_INVALID_CONNECTION	The net connection is invalid.
	 * @exception		E_MAX_EXCEEDED			The number of currently opened sessions has exceeded the maximum limit.
	 * @exception   	E_INVALID_STATE			The method invoked is invalid. @n
	 *											Invoke this method either before constructing the %HTTP session or after closing it.
	 * @exception		E_INVALID_PROXY			The specified proxy address is invalid.
	 * @exception		E_UNKNOWN				An unknown error has occurred.
	 * @exception		E_SYSTEM				An internal error has occurred.
	 * @exception		E_INVALID_ADDRESS		The host address is invalid.
	 *
	 * @remarks			In the NORMAL and PIPELINING session modes, all the transactions within this sessions are submitted through the same connection. While 
	 *					only one transaction is processed at a time in the Normal mode, multiple transactions can be pipelined in the Pipelining mode. In the 
	 *					normal mode, in order to submit the next transaction, the previous transaction should be complete.
	 */
	result Construct(NetHttpSessionMode sessionMode, const Osp::Base::String* pProxyAddr, const Osp::Base::String& hostAddr, const HttpHeader* pCommonHeader, NetHttpCookieFlag flag = NET_HTTP_COOKIE_FLAG_ALWAYS_MANUAL);

	/**
	 * Initializes this instance of %HttpSession with the specified parameters. @n
	 * Opens a session using the specified protocol.
	 *
	 * @since 			1.0
	 * @compatibility 	This method has compatibility issues with different bada API versions. @n
	 *                	For more information, see issues in version @ref HttpSessionConstructPage1 "1.2" and @ref HttpSessionConstructPage2 "2.0".
	 *
	 * @return			An error code
	 * @param[in]		netConnection			A NetConnection
	 * @param[in]		sessionMode				The session mode to open the session
	 * @param[in]		pProxyAddr				A proxy address @n
	 *											The specified @c proxyAddr must be a valid URL. If @c pProxyAddr is @c null, %HttpSession uses the system
	 *											default proxy address.
	 * @param[in]		hostAddr				A host address @n
	 *											The specified @c hostAddr must be a valid URL
	 * @param[in]		pCommonHeader			An instance of HttpHeader @n
	 *											This is a common header used in all the transactions included in this session.
	 * @param[in]		flag					Set to @c true if the cookies should be handled automatically, @n
	 *											else @c false if the cookies should be handled manually
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception		E_INVALID_CONNECTION	The specified @c netConnection is invalid.
	 * @exception		E_MAX_EXCEEDED			Unable to setup new connection due to too many existing connections.
	 * @exception   	E_INVALID_STATE			The method invoked is invalid. @n
	 *											Invoke this method either before constructing the %HTTP session or after closing it.
	 * @exception		E_INVALID_PROXY			The specified proxy address is invalid.
	 * @exception		E_UNKNOWN				An unknown error has occurred.
	 * @exception		E_SYSTEM				An internal error has occurred.
	 * @exception		E_INVALID_ADDRESS		The host address is invalid.
	 *
	 * @remarks			In the NORMAL and PIPELINING session mode, all the transactions within this session will be submitted through the same connection. 
	 *					While only one transaction is processed at a time in the Normal mode, multiple transactions can be pipelined in the Pipelining mode.
	 *					In the normal mode, in order to submit the next transaction, the previous transaction should be complete.
	 */
	result Construct(const NetConnection& netConnection, NetHttpSessionMode sessionMode, const Osp::Base::String* pProxyAddr, const Osp::Base::String& hostAddr, const HttpHeader* pCommonHeader, NetHttpCookieFlag flag = NET_HTTP_COOKIE_FLAG_ALWAYS_MANUAL);

	/**
	 * @page	HttpSessionConstructPage1	Compatibility for Construct()
	 *
	 * @section	HttpSessionConstructPageIssueSection	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# If the protocol prefix of @c pProxyAddr or @c hostAddr includes uppercase letters, HttpTransaction::Submit() fails.
	 * @section	HttpSessionConstructPageSolutionSection	Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above.
	 */

	/**
	 * @page	HttpSessionConstructPage2	Compatibility for Construct()
	 *
	 * @section	HttpSessionConstructPageIssueSection	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# In bada API versions prior to 2.0, the maximum number of HttpSessions that can be constructed per application is six (6). @n
	 * But from bada API version 2.0 or above, the maximum number of HttpSessions that can be constructed per application is ten (10).
	 */

	/**
	 * This is the destructor for this class.
	 *
	 * @since 1.0
	 */
	virtual ~HttpSession(void);


// Operation
public:
	/**
	 * Opens a transaction.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	HTTP
	 *
	 * @return		A pointer to a new HttpTransaction, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_MAX_EXCEEDED			The maximum number of transactions has been reached.
 	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_STATE			The method invoked is invalid. @n
	 *										Invoke this method either before constructing the %HTTP session or after closing it.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		This method should be called in the same thread as the HttpSession::Construct() method. The corresponding event listener should also be 
	 *				added in the same thread. A single transaction can be opened in a session at a time. After closing an open transaction, another 
	 *				transaction can be opened.
	 * @see			Construct()
	 */
	HttpTransaction* OpenTransactionN(void);

	/**
	* Opens a transaction with authentication information.
	*
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	HTTP
	*
	* @return		The pointer to a new HttpTransaction, @n
	*				else @c null if an error occurs
	* @param[in]	auth 					The authentication information
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_MAX_EXCEEDED			The maximum number of transactions has been reached.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_INVALID_STATE			The method invoked is invalid. @n
	*										Invoke this method either before constructing the %HTTP session or after closing it.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		This method should be called in the same thread as the HttpSession::Construct() method. The corresponding event listener should also be 
	*				added in the same thread. A single transaction at a time can be opened in a session. After closing an open transaction, another 
	*				transaction can be opened.
	* @see			Construct()
	*/
	HttpTransaction* OpenTransactionN(const HttpAuthentication& auth);
	/**
	 * Cancels the specified transaction. @n
	 * This method is followed by the CloseTransaction() method.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	HTTP
	 *
	 * @return		An error code
	 * @param[in]	httpTransaction 			The HttpTransaction to be cancelled
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OPERATION_CANCELED		The specified transaction has already been canceled.
	 * @exception	E_INVALID_STATE				The method invoked is invalid. @n
	 *											Invoke this method either before constructing the %HTTP session or after closing it.
	 * @exception	E_INVALID_TRANSACTION		The specified transaction is invalid.
	 * @exception	E_UNKNOWN					An unknown error has occurred.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	 * @remarks		The canceled transaction is no longer considered active. Also, re-opening the transaction is not allowed.
	 * @see			CloseTransaction(), Close()
	 */
	result CancelTransaction(HttpTransaction& httpTransaction);


	/**
	 * Closes the specified transaction.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	HTTP
	 *
	 * @return		An error code
	 * @param[in]	httpTransaction			The HttpTransaction to be closed
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_NOT_FOUND			The specified transaction is not found within the indicated range, or @n
	 *										The specified transaction is already deleted.
	 * @exception	E_INVALID_STATE			The method invoked is invalid. @n
	 *										Invoke this method either before constructing an %HTTP session or after closing it.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_INVALID_SESSION		The session is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	result CloseTransaction(HttpTransaction& httpTransaction);

	/**
	 * Closes all the transactions.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	HTTP
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_NOT_FOUND			The specified transaction is not found within the indicated range. @n
	 *										The specified transaction is already deleted.
	 * @exception	E_INVALID_STATE			The method invoked is invalid. @n
	 *										Invoke this method either before constructing an %HTTP session or after closing the session.
	 * @exception	E_INVALID_SESSION		The session is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	result CloseAllTransactions(void);

	 /**
	 * Sets the value to redirect the HTTP request automatically (the value is false by default).
	 *
	 * @since		2.0
	 *
	 * @return    	An error code
	 * @param[in]	enable					Set to @c true to redirect the HTTP request automatically, @n
	 *                               		else @c false
	 * @exception 	E_SUCCESS         		The method is successful.
	 * @exception 	E_INVALID_STATE			The method invoked is invalid.
	 * @exception 	E_SYSTEM           		A system error has occurred.
	 */
	 result SetAutoRedirectionEnabled(bool enable);

	 /**
	 * Checks whether the HTTP redirection is automatic.
	 *
	 * @since		2.0
	 *
	 * @return    	@c true if the HTTP redirection is automatic, @n
	 *				else @c false
	 * @exception 	E_SUCCESS           The method is successful.
	 * @exception 	E_INVALID_STATE		The method invoked is invalid.
	 * @exception 	E_SYSTEM            A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	 bool IsAutoRedirectionEnabled(void) const;

// Accessor
public:
	/**
	 * Gets the number of active transactions in the current instance of %HttpSession.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	HTTP
	 *
	 * @return 		An integer value indicating the number of currently active transactions, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		The transactions in the state between Submitted and Cancelled (or Closed) are considered to be active transactions.
	 *				The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetActiveTransactionCount(void) const;


	/**
	 * Gets the maximum number of transactions, the current instance of %HttpSession can have.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	HTTP
	 *
	 * @return 		An integer value indicating the maximum number of transactions allowed
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	int GetMaxTransactionCount(void) const;

	/**
	 * Gets the pointer to CookieStorageManager.
	 *
	 * @since 		1.0	
	 * @return		The pointer to CookieStorageManager, @n
	 *              else @c null if an error occurs
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The method invoked is invalid.
 	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	HttpCookieStorageManager* GetCookieStorageManager(void);

// Lifecycle
private:
	/**
	 * Frees all the resources.
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The method invoked is invalid. @n
	 *										Invoke this method either before constructing an %HTTP session or after closing the session.
	 */
 	virtual result Dispose(void);

	/**
	 * Closes the session. @n
	 * All transactions within the session are stopped and closed. The Dispose() method is invoked internally.
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The method invoked is invalid. @n
	 *										Invoke this method either before constructing an %HTTP session or after closing the session.
	 * @exception	E_INVALID_SESSION		The session is invalid.
	 * @exception	E_UNKNOWN				An unknown error has occurred.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @see			Dispose()
	 */
	result Close(void);
	/**
	 * Opens a new transaction with authentication information. @n
	 * The current transaction is closed by this method.
	 *
	 * @return		The pointer to the HttpTransaction instance, @n
	 *				else @c null if an error occurs
	 * @param[in]	transaction				The transaction details
	 * @exception	E_SUCCESS				The method is successful.
 	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_OBJ_NOT_FOUND			The specified transaction is not found within the indicated range, or @n
	 *										The specified transaction is already deleted.
	 * @exception	E_INVALID_STATE			The method invoked is invalid. @n
	 *										Invoke this method either before constructing an %HTTP session or after closing the session.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_INVALID_SESSION		The session is invalid.
	 * @exception	E_SYSTEM				Interface creation has failed.
	 * @exception	E_MAX_EXCEEDED			The number of active transactions exceeded the maximum limit.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			OpenTransactionN()
	 */
	HttpTransaction* ReopenTransactionWithAuthN(Net::Http::HttpTransaction& transaction);

// Operation
private:
	/**
	 * Deletes the specified transaction from the collection of active transactions.
	 *
	 * @return		An error code
	 * @param[in]	httpTransaction			An HttpTransaction to be deleted
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_NOT_FOUND			The specified instance is not found within the indicated range.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_INVALID_SESSION		The session is invalid.
	 */
	result DeleteTransaction(const HttpTransaction& httpTransaction);


	/**
	* Adapts a framework-level Http header instance (HttpHeader) to a ByteBuffer instance which represents a raw header used in the subsystem.
	*
	* @return		A raw bytebuffer representing @c pHeader, @n
	*				else @c null if an error occurs
	* @param[in]	pHeader					A HttpHeader instance
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified @c pHeader is null.
	* @exception  	E_INVALID_HEADER		This header instance does not contain any header field.
	* @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	static Osp::Base::ByteBuffer*  HttpHeaderToByteBuffer(const HttpHeader* pHeader);

	/**
	 *	Gets the low-level %Http session handle.
	 *
	 *	@return		A low-level handle representing the HTTP session, @n
	 *				else @c -1 if the session is not valid
	 */
	Handle GetHandle(void) const;
// Lifecycle
private:
	/*
	 * This is the copy constructor for the %HttpSession class. 
	 *
	 * @param[in]	value		An instance of %HttpSession
	 */
	HttpSession(const HttpSession& value);


// Operation
private:
	/*
	 * This is the assignment operator. 
	 * Do @b not use directly.
	 *
	 * @param[in]	rhs			An instance of %HttpSession
	 */
	HttpSession& operator =(const HttpSession& rhs);

	/**
	  * Checks whether the NetConnection is valid.
	  *
	  * @return  @c true if the NetConnection is valid, @n
	  *			 else @c false
	  */
	bool IsValidConnection(void);

// Attribute
private:
	IHttpSessionPi* __pHttpSessionInterface;

	Net::Http::HHttpSession __hSession;
	NetHttpSessionMode __sessionMode;

	Osp::Base::Collection::ArrayList __activeTransactions;
	HttpHeader* __pCommonHeader;

	int __numOfTxn;

	bool __isSecure;
	bool __isConstructed;
	bool __isClosed;
	HttpCookieStorageManager __cookieStorageMgr;
	NetHttpCookieFlag __cookieFlag;
	Osp::Base::Utility::Uri* __pHost;
	Osp::Net::_DefaultNetConnection* __pDefaultNetConnection;
	Osp::Net::Http::__HttpDefaultNetConnectionEventListenerImpl*	__pHttpDefaultNetConnectionEventListenerImpl;

	// Friend class declaration.
	friend class HttpTransaction;	// __numOfTxn
	friend class __HttpSessionEvent;
	friend class __HttpTransactionEvent;
	friend class HttpAuthentication;
	friend class HttpRequest;
	friend class HttpResponse;
	friend class HttpCookieStorageManager;
	friend class __HttpDefaultNetConnectionEventListenerImpl;

	friend class HttpSessionEx;
	class HttpSessionEx* __pHttpSessionEx;
};

}; }; }; // Osp::Net::Http
#endif // _FNET_HTTP_HTTP_TRANSACTION_H_

