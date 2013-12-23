/* $Change: 826527 $ */
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
 * @file			FSysISettingEventListener.h
 * @brief			This is the header file of the %ISettingEventListener interface.
 *
 * This header file contains the declarations of the %ISettingEventListener interface.
 */

#ifndef _FSYS_ISETTING_EVENT_LISTENER_H_
#define _FSYS_ISETTING_EVENT_LISTENER_H_

#include "FBaseResult.h"
#include "FBaseRtIEventListener.h"

#include "FSysConfig.h"

namespace Osp { namespace System {

/**
 * @interface	ISettingEventListener
 * @brief	This interface is the listener of the setting event.
 * @since 2.0
 *
 * The %ISettingEventListener interface must be registered and implemented by an application to receive setting events from the system.
 *
 */
class _EXPORT_SYSTEM_ ISettingEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:

	/**
	 *	Called when a certain setting value has been changed.
	 *
	 *  @since 2.0
	 *
	 *	@param[in]	key		The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/settings_info.htm">key name</a> of the changed setting information
	 * 
	 *	@remarks Invokes one of the overloaded getter methods of Osp::System::SettingInfo to get the changed value corresponding to the given key.
	 */
	virtual void OnSettingChanged (Osp::Base::String& key) = 0;

protected:
	/*
	 The following methods are reserved, and the name of methods can be changed at any time without prior notice.
	*/
	/** 
	 * @internal    This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 * @since 2.0
	 */
	virtual void OnSetting_Reserved1(void){}
		
	/** 
	 * @internal    This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 * @since 2.0
	 */
	virtual void OnSetting_Reserved2(void){}
	/** 
	 * @internal    This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 * @since 2.0
	 */
	virtual void OnSetting_Reserved3(void){}
	

};


}; }; // Osp::System

#endif // _FSYS_ISETTING_EVENT_LISTENER_H
