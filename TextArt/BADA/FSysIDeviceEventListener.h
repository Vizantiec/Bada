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
 * @file			FSysIDeviceEventListener.h
 * @brief			This is the header file for the %IDeviceEventListener interface.
 * 
 * This header file contains the declarations of the %IDeviceEventListener interface.
 */

#ifndef _FSYS_DEVICE_EVENT_LISTENER_H
#define _FSYS_DEVICE_EVENT_LISTENER_H

#include "FBaseResult.h"
#include "FBaseRtIEventListener.h"
#include "FSysDeviceManager.h"

namespace Osp { namespace System {


/**
 * @interface	IDeviceEventListener
 * @brief	This interface is the listener of the device state changes.
 * @since	1.1
 *
 * The %IDeviceEventListener interface must be registered and implemented by an application to receive device events from the system.
 *
 * @see DeviceManager
 */
class _EXPORT_SYSTEM_ IDeviceEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.1
	 */
	virtual ~IDeviceEventListener(void);
	
	/**
	* Called when a device state is changed. 
	*
	* @since			1.1
	* @param[in]	deviceType The types of a device
	* @param[in]	state		The device <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/device_management.htm">state</a> of type String
	*/
	virtual void OnDeviceStateChanged(DeviceType deviceType, const Osp::Base::String &state) = 0;
};


}; }; // Osp::System

#endif // _FSYS_DEVICE_EVENT_LISTENER_H
