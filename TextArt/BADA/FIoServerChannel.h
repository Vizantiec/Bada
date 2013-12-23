/* $Change: 333898 $ */
// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/** 
 * @file		FIoServerChannel.h 
 * @brief		This is the header file for the %ServerChannel class.
 *
 * This header file contains the declarations of the %ServerChannel class. 
 */
#ifndef _FIO_SERVER_CHANNEL_H_
#define _FIO_SERVER_CHANNEL_H_

#include "FIoConfig.h"
#include "FBaseResult.h"
#include "FBaseObject.h"
#include "FBaseDataType.h"

#include "FIoIChannelEventListener.h"
#include "FIoIChannelRequestEventListener.h"

#include "FAppTypes.h"

namespace Osp { namespace Io {


/**
* @class    ServerChannel
* @brief    This class provides the methods to receive a request from a client application.
*
* @deprecated  This class is deprecated.
* @since    2.0
*
* The %ServerChannel class provides the methods to receive a request from a client application. An application can receive a request from another application using the %ServerChannel class. The instance of %ServerChannel is retrieved using ServerChannel::GetInstance().
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/io/io_namespace.htm">Io Guide</a>.
*
* The following example demonstrates how to use the %ServerChannel class.
*
* @code
*
* #include <FBase.h>
* #include <FIo.h>
* 
* using namespace Osp::Base;
* using namespace Osp::Base::Collection;
* using namespace Osp::Io;
* using namespace Osp::App;
*
* class MyAppClass :
* 	public Osp::Io::IChannelRequestEventListener
* {
* public:
* 	result Initialize(void);
* 	ArrayList* GetOnlineFriends(void);
* 	void virtual OnChannelRequestReceivedN(RequestId reqId, Osp::Io::ServerChannel& serverChannel, const Osp::App::AppId& clientAppId, Osp::Base::Collection::IList* pArgs);
* };
* 
* result
* MyAppClass::Initialize(void)
* {
* 	result r = E_SUCCESS;
* 
* 	// Sets the channel request event listener
* 	ServerChannel::GetInstance()->SetChannelRequestEventListener(this);
* 
* 	return r;
* }
*
* ArrayList*
* MyAppClass::GetOnlineFriends(void)
* {
* 	ArrayList* pDataList = new ArrayList();
* 	String* pData = new String(L"Tom");
* 	String* pData2 = new String(L"Jane");
*
* 	pDataList->Construct();
* 	pDataList->Add(*pData);
* 	pDataList->Add(*pData2);
* 	
* 	return pDataList;
* }
* 
* void
* MyAppClass::OnChannelRequestReceivedN(RequestId reqId, Osp::Io::ServerChannel& serverChannel, const Osp::App::AppId& clientAppId, Osp::Base::Collection::IList* pArgs)
* {
*	// Handles the request. 
*	ArrayList* pList = GetOnlineFriends(); 
* 
*	//Sends the response to the client.
*	serverChannel.SendResponse(clientAppId, reqId, pList);
*
* 	// Removes the arguments.	
*	pList->RemoveAll(true);
*	delete pList;
*
*	pArgs->RemoveAll(true);
*	delete pArgs;
* }
* 
* @endcode
*/

class _EXPORT_IO_ ServerChannel :
       public Osp::Base::Object
{

protected:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated  This method is deprecated since this class is not intended for subclassing.
	*
	* @since    2.0
	*/
	ServerChannel(void);

	/**
	* Initializes this instance of the %ServerChannel class with the specified ID and listeners.
	*
	* @deprecated  This method is deprecated since this class is not intended for subclassing.
	*
	* @since	2.0
	*
	* @return  An error code
	* @exception E_SUCCESS             The method is successful.
	* @exception E_OUT_OF_MEMORY       The memory is insufficient.
	* @remarks    To create a unique channel ID, the application ID can be used. It is obtained using Application::GetAppId().
	*/
       result Construct(void);

	/**
	* This is the destructor for this class. @n
	* This destructor removes the entry related to this channel.
	*
	* @deprecated  This method is deprecated since this class is not intended for subclassing.
	*
	* @since    2.0
	*/
	virtual ~ServerChannel(void);

public:
	/** 
	* Sets the request event listener. @n
	* The listener is called when a request arrives. To reset the event listener, @c null should be passed.
	*
	* @deprecated  This method is deprecated.
	*
	* @since 2.0
	*
	* @param[in] pRequestListener    The request event listener
	*/
	void SetChannelRequestEventListener (const IChannelRequestEventListener* pRequestListener);

	/**
	* Gets the default server channel of the application. 
	*
	* @deprecated  This method is deprecated.
	*
	* @since    2.0
	*/
	static ServerChannel* GetInstance(void);


    /**
	* Sends a response to the specified client application.
	*
	* @deprecated  This method is deprecated.
	*
	* @since    	2.0
	*
	* @return   	An error code
	* @param[in] clientAppId         The client application ID
	* @param[in] reqId               The request ID
	* @param[in] pArgs               A pointer to an argument list of type String
	* @exception E_SUCCESS           The method is successful.
	* @exception E_INVALID_STATE     The specified channel has not been initialized.
	* @exception E_OBJ_NOT_FOUND     The specified client channel is not found.
	* @exception E_OUT_OF_MEMORY     The memory is insufficient.
	*/
    result SendResponse(const Osp::App::AppId& clientAppId, RequestId reqId, const Osp::Base::Collection::IList* pArgs);

    /**
	* Sets a list of clients that are allowed to send a request to the server channel for the application calling this method.
	* By default, all clients are allowed.
	*
	* @deprecated	This method is deprecated and will be deleted in a future release. @n
	*				Instead of using this method, the list of allowed clients should be handled by the application itself.
	* @since		2.0
	*
	* @return   An error code
	* @param[in] pClients     A list of clients to allow @n
    * 							To restore the default policy for allowing all the clients, pass @c null 
    * 							as an argument to this method.
	* @exception E_SUCCESS    The method is successful.
	* @exception E_SYSTEM      A system error has occurred. 
	* @remarks                 All the requests from the clients that are not specified in the allowed 
	*                          list are not delivered to the server channel, and ClientChannel::SendRequest() 
	*                          raises an E_ILLEGAL_ACCESS exception. 
	*
	* The following example demonstrates how to use the LimitAllowedClients() method.
	*
	* @code
	*
	*	ArrayList* pAppList = new ArrayList();
	*	pAppList->Construct();
	*
	*	String* pApp1 = new String(L"1234567890");
	*	String* pApp2 = new String(L"abcdefghij");
	*
	*	pAppList->Add(*pApp1);
	*	pAppList->Add(*pApp2);
	*	
	*	// Only 1234567890 and abcdefghij are allowed to send a request
	*	ServerChannel::LimitAllowedClients(pAppList);
	*
	*	pAppList->RemoveAll(true);
	*	delete pAppList;
	* @endcode
	*/
	static result LimitAllowedClients (const Osp::Base::Collection::IList* pClients);

private:
    friend class ServerChannelEx;
    class ServerChannelEx* __pServerChannelEx;
};// ServerChannel

}; }; // Osp::Io

#endif//_FIO_SERVER_CHANNEL_H_

