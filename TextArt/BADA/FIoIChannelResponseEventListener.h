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
 * @file		FIoIChannelResponseEventListener.h
 * @brief		This is the header file for the %IChannelResponseEventListener interface.
 *
 * This header file contains the declarations of the %IChannelResponseEventListener interface.
 *
 */
#ifndef _FIO_ICHANNEL_RESPONSEEVENT_LISTENER_H_
#define _FIO_ICHANNEL_RESPONSEEVENT_LISTENER_H_

// Includes
#include "FBaseTypes.h"
#include "FBaseDataType.h"
#include "FBaseRtIEventListener.h"
#include "FBase.h"

#include "FAppTypes.h"

namespace Osp { namespace Io {

class ClientChannel;
/**
* @interface IChannelResponseEventListener
* @brief    This interface provides event handlers for any response events received through a channel.
*
* @deprecated  This class is deprecated.
* @since    2.0
*
*  The %IChannelResponseEventListener interface provides event handlers for receiving the channel response events.
*/
class _EXPORT_IO_ IChannelResponseEventListener :
       public Osp::Base::Runtime::IEventListener
{
 public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since   2.0
	 */
	virtual ~IChannelResponseEventListener(void); 
      
// Operation
public:
       /**
       * Called when a response is received from a server channel.
       *
       * @deprecated  This method is deprecated.
       *
       * @since 		2.0
       *
       * @param[in] reqId               The request ID
       * @param[in] clientChannel       The reference to the client channel
       * @param[in] serverAppId     The server channel ID
       * @param[in] pArgs                A pointer to an argument list of type String
       *
       */
       virtual void OnChannelResponseReceivedN(RequestId reqId, ClientChannel& clientChannel, const Osp::App::AppId& serverAppId, Osp::Base::Collection::IList* pArgs) = 0;
protected:
       // Reserved virtual methods for later extension.
      /**
       * @internal
       *
       * This method is for internal use only. The bada platform team is not responsible 
       * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
       *
       * Following method is reserved and may change its name at any time without prior notice.
       * 
       * @since           2.0
       */
       virtual void IChannelResponseEventListener_Reserved1 (void) {}

      /**
       * @internal
       *
       * This method is for internal use only. The bada platform team is not responsible 
       * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
       *
       * Following method is reserved and may change its name at any time without prior notice.
       * 
       * @since           2.0
       */
       virtual void IChannelResponseEventListener_Reserved2 (void) {}

      /**
       * @internal
       *
       * This method is for internal use only. The bada platform team is not responsible 
       * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
       *
       * Following method is reserved and may change its name at any time without prior notice.
       * 
       * @since           2.0
       */
       virtual void IChannelResponseEventListener_Reserved3 (void) {}
};


}; }; // Osp::Io

#endif // _FIO_ICHANNEL_EVENT_LISTENER_H_

