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
 * @file			FSysIBatteryEventListener.h
 * @brief			This is the header file for the %IBatteryEventListener interface.
 * 
 * This header file contains the declarations of the %IBatteryEventListener interface.
 */

#ifndef _FSYS_IBATTERY_EVENT_LISTENER_H_
#define _FSYS_IBATTERY_EVENT_LISTENER_H_

#include "FBaseResult.h"
#include "FBaseRtIEventListener.h"


namespace Osp { namespace System {

/**
 * @interface	IBatteryEventListener
 * @brief	This interface is the listener of the battery event.
 * @since 2.0
 *
 * The %IBatteryEventListener interface must be registered and implemented by an application to receive Battery events from the system.
 */

class _EXPORT_SYSTEM_ IBatteryEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:

	/**
	 *	Called when the battery level is changed.
	 *  @param[in] percentage   The changed battery level
	 *  @remarks The resolution of the level is 5%. The range of the level is @c 0 (Minimum) to @c 100 (Maximum).
	 *	@since 2.0
	 */
	virtual void OnBatteryLevelChangedInPercentage(int percentage) = 0;
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
	virtual void OnBattery_Reserved1(void){};
	
	/** 
	 * @internal    This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 * @since 2.0
	 */
	virtual void OnBattery_Reserved2(void){};
	
	/** 
	 * @internal    This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 * @since 2.0
	 */
	virtual void OnBattery_Reserved3(void){};
};
};	}; // Osp::System

#endif // _FSYS_IALARM_EVENT_LISTENER_H_



