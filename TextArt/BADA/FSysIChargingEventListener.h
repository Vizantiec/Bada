/* $Change: 1035663 $ */
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
 * @file			FSysIChargingEventListener.h
 * @brief			This is the header file for the %IChargingEventListener interface.
 * 
 * This header file contains the declarations of the %IChargingEventListener interface.
 */

#ifndef _FSYS_ICHARGING_EVENT_LISTENER_H
#define _FSYS_ICHARGING_EVENT_LISTENER_H

#include "FBaseResult.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace System {

/**
 * @interface	IChargingEventListener
 * @brief	This interface is the listener of the charging event.
 * @since 1.0
 *
 * The %IChargingEventListener interface must be registered and implemented by an application to 
 * receive events from the system when the device charging state changes.
 *
 */
class _EXPORT_SYSTEM_ IChargingEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:

	/**
	 *	Called when the charging state is changed.
	 *
	 *  @since 1.0
	 *	@param[in]	charging		The charging state
	 */
	virtual void OnChargingStateChanged(bool charging) = 0;
};


}; }; // Osp::System

#endif // _FSYS_ICHARGING_EVENT_LISTENER_H
