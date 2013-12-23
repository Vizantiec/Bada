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
 * @file		FSysPower.h 
 * @brief		This is the header file for the %Battery class.
 *
 * This header file contains the declarations of the %Battery class.
 *
 */

 
#ifndef _FSYS_SYSTEM_POWER_H_
#define _FSYS_SYSTEM_POWER_H_

// include
#include "FSysConfig.h"
#include "FBaseObject.h"

namespace Osp { namespace System {


/**
 * @enum	PowerMode
 * Defines the representation of the charge remaining in the battery.
 *
 * @since 1.0
 */
enum PowerMode
{
	POWER_STANDBY,		/**< The battery is fully charged */
	POWER_SLEEP,		/**< The battery has plenty of charge */	
};
};};

#endif