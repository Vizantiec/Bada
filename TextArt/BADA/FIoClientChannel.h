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
 * @file		FIoClientChannel.h 
 * @brief		This is the header file for the %ClientChannel class.
 *
 * This header file contains the declarations of the %ClientChannel class. 
 */
#ifndef _FIO_CLIENT_CHANNEL_H_
#define _FIO_CLIENT_CHANNEL_H_

#include "FIoConfig.h"
#include "FBaseResult.h"
#include "FBaseObject.h"
#include "FBaseDataType.h"

#include "FIoIChannelResponseEventListener.h"

#include "FAppTypes.h"

namespace Osp { namespace Io {

/**
* @class    ClientChannel
* @brief    This class provides the methods for sending a request to another application.
*
* @deprecated  This class is deprecated.
* @since    2.0
*
* The %ClientChannel class provides methods for sending a request to another application's ServerChannel. To receive a response
* for the request, set the ChannelResponseEventListener interface. The instance of %ClientChannel can be retrieved
* using ClientChannel::GetInstance().
* 
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/io/io_namespace.htm">Io Guide</a>.
*
* The following example demonstrates how to use the %ClientChannel class.
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
* 	public Osp::Io::IChannelResponseEventListener
* {
* public:
* 	result Initialize(void);
* 	void virtual OnChannelResponseReceivedN(RequestId reqId, Osp::Io::ClientChannel& clientChannel, const Osp::App::AppId& serverAppId, Osp::Base::Collection::IList* pArgs);
* 	void GetOnlineFriends(void);
* };
* 
* result
* MyAppClass::Initialize(void)
* {
* 	result r = E_SUCCESS;
* 
* 	// Sets the channel response event listener.
* 	ClientChannel::GetInstance()->SetChannelResponseEventListener(this);
* 
* 	return r;
* }
* 
* void
* MyAppClass::OnChannelResponseReceivedN(RequestId reqId, Osp::Io::ClientChannel& clientChannel, const Osp::App::AppId& serverAppId, Osp::Base::Collection::IList* pArgs)
* {
*	// Handles the channel response. 
*	for(int i = 0; i < pArgs->GetCount(); i++)
*		AppLog("pData[%d]=%S", i, ((String*)(pArgs->GetAt(i)))->GetPointer());
*  
* 	// Clean up the arguments	
*	pArgs->RemoveAll(true);
* 	delete pArgs;
* }
*
* void
* MyAppClass::GetOnlineFriends(void)
* {
*	RequestId reqId = 0;
*
*	ArrayList* pDataList = new ArrayList();
* 	String* pData = new String(L"GetList");
* 	String* pData2 = new String(L"Friend");
*
* 	pDataList->Construct();
* 	pDataList->Add(*pData);
* 	pDataList->Add(*pData2);
*
*	ClientChannel::GetInstance()->SendRequest(L"1234567890", pDataList, reqId);
*
*	pDataList->RemoveAll(true);
*	delete pDataList;
* 
* }
* 
* @endcode
*/

class _EXPORT_IO_ ClientChannel :
       public Osp::Base::Object
{
// Lifecycle
protected:
       /**
       * This is the default constructor for this class.
       *
       * @deprecated  This method is deprecated since this class is not intended for subclassing.
       *
       * @since    2.0
       */
       ClientChannel(void);

       /**
       * Initializes this instance of ClientChannel.
       *
       * @deprecated  This method is deprecated since this class is not intended for subclassing.
       *
       * @since	2.0
       *
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
       virtual ~ClientChannel(void);

public:
       /**
	* Gets the default client channel of the application.
       *
  *
  * @deprecated  This method is deprecated.
  *
	* @since 2.0
	*/
       static ClientChannel* GetInstance(void);

       /** 
	* Sets the response event listener. @n
	* The listener is called when a response is received. To reset the event listener, @c null must be passed.
	*
	* @deprecated  This method is deprecated.
	*
	* @since 2.0
	*
	* @param[in] pResponseListener    The response event listener
	*/
       void SetChannelResponseEventListener (const IChannelResponseEventListener* pResponseListener);

       /**
       * Sends a request to the specified server application. 
       *
       * @deprecated  This method is deprecated.
       *
       * @since 2.0
       *
       * @return   	An error code
       * @param[in]     serverAppId         The server application ID
       * @param[in]     pArgs               A pointer to an argument list of type String
       * @param[out]    reqId               The request ID
       * @exception     E_SUCCESS           The method is successful.
       * @exception     E_INVALID_STATE     The channel has not been initialized.
       * @exception     E_OBJ_NOT_FOUND     The server channel is not found. 
       * @exception     E_OUT_OF_MEMORY     The memory is insufficient.
       * @exception     E_ILLEGAL_ACCESS    The specified server channel has denied the request from the 
	   *                                    application calling this method.
       */
       result SendRequest(const Osp::App::AppId& serverAppId, const Osp::Base::Collection::IList* pArgs, RequestId& reqId);

private:
        friend class ClientChannelEx;
        class ClientChannelEx* __pClientChannelEx;
       
};// ClientChannel

}; }; // Osp::Io

#endif//_FIO_CLIENT_CHANNEL_H_

