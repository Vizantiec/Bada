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
 * @file		FIoIChannelEventListener.h
 * @brief		This is the header file for the %IChannelEventListener interface.
 *
 * This header file contains the declarations of the %IChannelEventListener interface. @n
 * If the channel event is generated, a method of this interface is called.
 * So, if the application performs jobs related to the channel event, use methods that belong to this interface.
 *
 */
#ifndef _FIO_ICHANNEL_EVENT_LISTENER_H_
#define _FIO_ICHANNEL_EVENT_LISTENER_H_

// Includes
#include "FBase.h"
#include "FBaseRtIEventListener.h"

#include "FIoChannelTypes.h"

#include "FAppTypes.h"

namespace Osp { namespace Io {
	
/**
* @interface IChannelEventListener
* @brief    This interface provides event handlers for the channel creation and deletion.
*
* @deprecated  This class is deprecated.
* @since    2.0
*
* The %IChannelEventListener interface provides event handlers for receiving the channel events.
*
*/
class _EXPORT_IO_ IChannelEventListener
       : public Osp::Base::Runtime::IEventListener
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since   2.0
	 */
	virtual ~IChannelEventListener(void); 


// Operation
public:
	/**
	 * Called when an application creates the channel.
	 *
	 * @deprecated	This method is deprecated. Instead of using this, it is recommend to use App::IsRunning().
	 *
	 * @since 2.0
	 *
	 * @param[in] appId  The application ID that creates the channel 
	 * @param[in] type   The type of the channel
	 *
	 */
	 virtual void OnChannelCreated(const Osp::App::AppId& appId, ChannelType type) = 0;

	/**
	* Called when an application deletes the channel.
	*
	* @deprecated	This method is deprecated. Instead of using this, it is recommend to use App::IsRunning().
	*
	* @since 2.0
	*
	* @param[in] appId  The application ID that deletes the channel
	* @param[in] type   The type of the channel
	*
	*/
	virtual void OnChannelDeleted(const Osp::App::AppId& appId, ChannelType type) = 0;

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
       virtual void IChannelEventListener_Reserved1 (void) {}

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
       virtual void IChannelEventListener_Reserved2 (void) {}

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
       virtual void IChannelEventListener_Reserved3 (void) {}

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
       virtual void IChannelEventListener_Reserved4 (void) {}

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
       virtual void IChannelEventListener_Reserved5 (void) {}

};


}; }; // Osp::Io

#endif // _FIO_ICHANNEL_EVENT_LISTENER_H_

