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
 * @file		FSysBattery.h 
 * @brief		This is the header file for the %Battery class.
 * @since 1.0
 *
 * This header file contains the declarations of the %Battery class.
 *
 */

 
#ifndef _FSYS_SYSTEM_BATTERY_H_
#define _FSYS_SYSTEM_BATTERY_H_

// Include
#include "FSysConfig.h"
#include "FBaseObject.h"

namespace Osp { namespace System {


/**
 * @enum	BatteryLevel
 * Defines the representation of the remaining charge in the battery.
 *
 * @since 1.0
 */
enum BatteryLevel
{
	BATTERY_FULL,		/**< The battery is fully charged */
	BATTERY_HIGH,		/**< The battery has plenty of charge */
	BATTERY_LOW,		/**< The battery has little charge */
	BATTERY_CRITICAL,	/**< The battery charge is at a critical state @n
							 It is strongly recommended to stop using all multimedia features because they are not guaranteed to work correctly at this level. */
	BATTERY_EMPTY,		/**< The battery is empty @n
							 It is strongly recommended to prepare for the safe termination of the application because the device will start a shutdown process soon after entering this level.  */
};

class IBatteryPi;

/**
 * @class		Battery
 * @brief		This class provides methods to get information related to the battery charge.
 * @since 	1.0
 *
 * The %Battery class provides methods to get the status related to battery levels and 
 * determine whether the battery is currently being charged. 
 * You cannot create an instance of this class directly.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/battery_status.htm">Battery Status</a>.
 *
 */
 class _EXPORT_SYSTEM_ Battery :
	public Osp::Base::Object
{
private:
// Lifecycle
	/**
	 * This is the default constructor for this class.
	 */
	 Battery(void);


	 /**
	  * This is the destructor for this class. @n
	  */
	  virtual ~Battery(void);

public:
// Accessor


	/**
	 * Gets the current charge remaining in the battery as a percentage.
	 *
	 * @since 		1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
   *                   For more information, see @ref CompGetCurrentLevelInPercentagePage "here".
   *
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return			An error code
	 * @param[out]  level  The percentage of the charge remaining in the battery 
	 * @exception		E_SUCCESS	The method is successful. 
	 * @exception   E_INVALID_STATE The battery service is not available.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM    A system error has occurred.

	 * @remarks 	The resolution of the level is 1% since 2.0. The range of the level is 0(Minimum) to 100(Maximum).
	 */
	static result GetCurrentLevelInPercentage(int& level);
	

	/**
	 * Gets the current charging level of the battery.
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[out]  level           A value from the enumerator BatteryLevel indicating the current charging level 
	 * @exception	E_SUCCESS	    The method is successful. 
	 * @exception   E_INVALID_STATE The battery service is not available.

	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM    A system error has occurred.
	 */
	static result GetCurrentLevel(BatteryLevel& level);


	/**
	 * Checks whether the battery is currently charging.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[out] charging		 Set to @c true if the charging cable is connected to the phone, @n
     *                       	 else @c false
	 * @exception	E_SUCCESS	The method is successful. 
	 * @exception   E_INVALID_STATE The battery service is not available.

	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM    A system error has occurred.
	 */
	static result IsCharging(bool& charging);
	
	/**
	 * @page			CompGetCurrentLevelInPercentagePage				Compatibility for GetCurrentLevelInPercentage()
	 * @section		CompGetCurrentLevelInPercentagePageIssue 	Issues
	 *						Implementation of this method in bada API versions prior to 2.0 has the following issue:
	 *
	 *						-# This method returns a discrete value and the value ranges between 0 (Minimum)and 80 (Maximum).
	 * @section		CompGetCurrentLevelInPercentagePageResolution	Resolution
	 *						The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. 
	 */

private:
	friend class BatteryEx;
	class BatteryEx* __pBatteryEx;
};
};	};
#endif 

