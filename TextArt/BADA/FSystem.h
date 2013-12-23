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
 * @file		FSystem.h
 * @brief		This is the header file for the %System namespace.
 * @since 1.0
 *
 * This header file contains the declarations of the %System namespace.
 *
 */
#ifndef _FSYSTEM_H_
#define _FSYSTEM_H_

// Alarm
#include "FSysAlarm.h"
#include "FSysIAlarmEventListener.h"

// SystemTime
#include "FSysSystemTime.h"

// Vibrator
#include "FSysVibrator.h"

// Devices
#include "FSysBattery.h"
#include "FSysPower.h"

// System Information
#include "FSysSystemInfo.h"

// Runtime Information
#include "FSysRuntimeInfo.h"

// Setting Information
#include "FSysSettingInfo.h"

// Power Manager 
#include "FSysIScreenEventListener.h"
#include "FSysIChargingEventListener.h"
#include "FSysPowerManager.h"

// Feature List
#include "FSysFeatureList.h"

// Device State
#include "FSysDeviceManager.h"
#include "FSysIDeviceEventListener.h"

namespace Osp {
/**
 *	@namespace	Osp::System
 *	@brief		This namespace contains classes and interfaces for %System.
 *	@since		1.0
 *
 *  @remarks    @b Header @b %file: @b \#include @b <FSystem.h> @n
 *				@b Library : @b FOsp
 *
 *	The %System namespace provides system management features, such as system time, alarm, vibrator, power, and device management. 
 * It also provides the system, setting, and runtime information.
 *
 * For more information on the %System namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/system_namespace.htm">System Guide</a>.
 *
 *
 */
namespace System {}; // System

}; // Osp

#endif

