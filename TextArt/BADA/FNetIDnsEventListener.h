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
 * @file	FNetIDnsEventListener.h 
 * @brief	This is the header file for the %IDnsEventListener interface.
 *
 * This header file contains the declarations of the %IDnsEventListener interface.
 *
 */
#ifndef _FNET_IDNS_EVENT_LISTENER_H_
#define _FNET_IDNS_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"


namespace Osp { namespace Net {
class IpHostEntry;
/**
 * @interface	IDnsEventListener
 * @brief		This interface implements listeners for DNS events.
 * @since		1.0
 *
 * 		The %IDnsEventListener interface provides methods for creating notifications about different types of DNS events. These events are only sent 
 *				out if a listener is added to the DNS object in the Construct() method. When a DNS event is generated, one of these methods is called. The 
 *				methods of this interface may be overridden and used in any application that uses DNS.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/domain_name_system_access.htm">Domain Name System Access</a>. @n
 *
 * @see	Osp::Net::IpHostEntry
 *
 * The following example demonstrates how to use the %IDnsEventListener interface.
 *
 * @code
 *
 *	using namespace Osp::Net;
 *
 *	// Dns event handler
 *	class MyDnsListener
 *		:public IDnsEventListener
 *	{
 *	public:
 *		void OnDnsResolutionCompletedN(IpHostEntry* ipHostEntry, result r);
 *	};
 *
 *	void MyDnsListener::OnDnsResolutionCompletedN(IpHostEntry* ipHostEntry, result r)
 *	{
 *		if (ipHostEntry == null)
 *		{
 *			AppLog("error case no.%d \n", r);
 *		}
 *		else
 *		{
 *			Osp::Base::Collection::IList* addressList = ipHostEntry->GetAddressList();
 *
 *			if (addressList != null)
 *			{
 *				int count = addressList->GetCount();
 *
 *				for (int i=0; i < count; i++)
 *				{
 *					IpAddress* pIpAddress = (IpAddress*)(addressList->GetAt(i));
 *					Osp::Base::ByteBuffer*_pbb = Osp::Base::Utility::StringUtil::StringToUtf8N(pIpAddress->ToString());
 *
 *					AppLog("IpAddress no.%d : %s\n", i, (char*)(_pbb->GetPointer()));
 *					delete _pbb;
 *				}
 *			}
 *
 *			Osp::Base::Collection::IList* aliasList = ipHostEntry->GetAliasList();
 *
 *			if (aliasList != null)
 *			{
 *				int count = aliasList->GetCount();
 *
 *				for (int i=0; i < count; i++)
 *				{
 *					String* alias = (String*)(aliasList->GetAt(i));
 *					Osp::Base::ByteBuffer*_pbb = Osp::Base::Utility::StringUtil::StringToUtf8N(*alias);
 *
 *					AppLog("alias no.%d : %s\n", i, (char*)(_pbb->GetPointer()));
 *					delete _pbb;
 *				}
 *			}
 *			delete ipHostEntry;
 *		}
 *	}
 *
 * @endcode
 *
 * 
 */
class _EXPORT_NET_ IDnsEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:
   /** 
    * This is the destructor for this class.
	*
	* @since	1.0
	*/
	virtual ~IDnsEventListener(void) {}


// Operation
public:
	/**
	 * Called to notify the result of the %Dns request.
	 *
	 * @since		1.0
	 * @param[in]	pIpHostEntry			The information on the dns event
	 * @param[in]	r						The cause of the error
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_IN_PROGRESS			A previous request is in progress.
	 * @exception	E_INVALID_SERVER		The requested server is invalid.
	 * @exception	E_INVALID_DOMAIN		The requested domain of the server is invalid.
	 * @exception	E_NETWORK_UNAVAILABLE	The network is unavailable.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_TIMEOUT				An attempt to connect to the server has timed out.
	 * @exception	E_NOT_RESPONDING		There is no response.
	 * @exception	E_DNS_NOT_FOUND			The DNS lookup has failed.
	 *				
	 * @remarks		Always check the error code before accessing the result.
	 *				If @c r is not E_SUCCESS, @c ipHostEntry may not exist.
	 * @see			Osp::Net::IpHostEntry
	 */
	virtual void OnDnsResolutionCompletedN(IpHostEntry* pIpHostEntry, result r) = 0;
};

}; }; // Osp::Net

#endif // _FNET_IDNS_EVENT_LISTENER_H_

