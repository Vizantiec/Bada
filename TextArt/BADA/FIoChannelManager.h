/* $Change: 855320 $ */
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
 * @file		FIoChannelManager.h
 * @brief		This is the header file for the %ChannelManager class.
 *
 * This header file contains the declarations of the %ChannelManager class.
 */
#ifndef _FIO_CHANNEL_MANAGER_H_
#define _FIO_CHANNEL_MANAGER_H_

#include "FIoConfig.h"
#include "FBaseResult.h"
#include "FBaseObject.h"
#include "FBaseDataType.h"

#include "FIoIChannelEventListener.h"

#include "FAppTypes.h"

namespace Osp { namespace Io {

/**
* @class    ChannelManager
* @brief    This class provides methods to manage a channel for inter-application communication.
*
* @deprecated  This class is deprecated.
* @since    2.0
* 
* The %ChannelManager class provides methods to manage a channel for inter-application communication.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/io/channels.htm">Channel Communication</a>.

*
* The following example demonstrates how to use the %ChannelManager class.
* @code
*
* #include <FIo.h>
*
* using namespace Osp::Io;
* using namespace Osp::App;
*
* class MyAppClass :
* 	public Osp::Io::IChannelEventListener
* {
* public:
* 	void Initialize(void);
* 	virtual void OnChannelCreated(const AppId& appId, ChannelType type);
* 	virtual void OnChannelDeleted(const AppId& appId, ChannelType type);
* };
*
* void
* MyAppClass::Initialize(void)
* {
* 	// Sets the channel event listener
* 	ChannelManager::SetChannelEventListener(this);
* }
* 
* void
* MyAppClass::OnChannelCreated(const AppId& appId, ChannelType type)
* {
*	// Handles the channel event 
*	AppLog("%ls has created a channel : type(%d)", appId.GetPointer(), type);
* }
*
* void
* MyAppClass::OnChannelDeleted(const AppId& appId, ChannelType type)
* {
*	// Handles the channel event 
*	AppLog("%ls has deleted a channel : type(%d)", appId.GetPointer(), type);
* }
* 
* @endcode
*/

class _EXPORT_IO_ ChannelManager :
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
       ChannelManager (void);

/**
       * This is the destructor for this class. @n
       * This destructor removes the entry related to this channel.
       *
       * @deprecated  This method is deprecated since this class is not intended for subclassing.
       *
       * @since    2.0
       */
       virtual ~ChannelManager(void);

public:
/** 
	* Sets the channel event listener. @n
	* The listener is called when the state of the channel changes. To remove the listener, pass a @c null value to the listener parameter.
	*
	* @deprecated  This method is deprecated.
	*
	* @since 2.0
	*
	* @param[in] pChannelListener   The channel event listener
	*
	*/
       static void SetChannelEventListener(const IChannelEventListener* pChannelListener);

private:
        friend class ChannelManagerEx;
        class ChannelManagerEx* __pChannelManagerEx;
};// ChannelManager



};// Osp::Io
};// Osp
#endif//_FIO_CHANNEL_MANAGER_H_
