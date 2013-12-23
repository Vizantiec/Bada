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
 * @file		FSysPowerManager.h
 * @brief		This is the header file for the %PowerManager class.
 *
 * This header file contains the declarations of the %PowerManager class.
 *
 */


#ifndef _FSYS_SYSTEM_POWERMANAGER_H_
#define _FSYS_SYSTEM_POWERMANAGER_H_

// include
#include "FSysConfig.h"
#include "FBaseObject.h"
#include "FSysIBatteryEventListener.h"

namespace Osp { namespace System {


class IPowerManagerPi;
class IScreenEventListener;
class IChargingEventListener;

/**
 * @class	PowerManager
 * @brief	This class provides methods for power management.
 * @since	1.0
 *
 * The %PowerManager class provides methods for managing the screen state and screen brightness. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/screen_power_mgmt.htm">Screen Power Management</a>.

 */
 

 class _EXPORT_SYSTEM_ PowerManager :
	public Osp::Base::Object
{
public:
// Life-cycle
	/**
	 * @internal
	 * This is the default constructor for this class.
	 * @since 1.0
	 */
	 PowerManager(void);
	/**
	 * @internal
	 * This is the destructor for this class.
	 * @since 1.0
	 */
   virtual ~PowerManager(void);

public:
	/**
	 * Changes the policy of the screen power management.
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	keepOn	Set to @c true if the screen remains in the 'ON' state until the application goes to the background, @n
     *                      else @c false if the state of the screen is controlled by the default power control policy of the system
	 * @param[in]   dimming Set to @c true if the screen is dimmed when there is no user input for a certain amount of time, @n
     *                      else @c false if the screen is not dimmed
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks		The application should explicitly call this method again, if the screen is to be kept 'ON' after coming back from the background state.
	 */
	static result KeepScreenOnState(bool keepOn, bool dimming = true);
	
	/**
	 * Sets the screen brightness level for an application.
	 *
	 * @since			2.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return An error code
	 * @param[in] brightness The brightness level to be set @n
	 *						The parameter value can range between @c 1 (minimum) and @c 10 (maximum).
	 * @exception E_SUCCESS The method is successful.
	 * @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception E_OUT_OF_RANGE  The specified @c brightness is out of range.
	 * @exception	E_SYSTEM						A system error has occurred.	 
	 * @remarks This brightness level is only available when an application is running on the foreground. Even if the brightness is set to level 1, a black screen is not displayed. Level 1 is the minimum brightness level that can be set for an application.
	 */
	static result SetScreenBrightness(int brightness);
	/**
	 * Gets the screen brightness level of an application.
	 *
	 * @since 		2.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return                           The brightness level of the current application
	 * @exception E_SUCCESS              The method is successful.
	 * @exception E_PRIVILEGE_DENIED     The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			 A system error has occurred.	 
	 * @remarks  This method returns the screen brightness level set for an application. If the brightness level is not set, it will return the default system brightness level.
	 *					In case of error, this method returns @c -1. The specific error code can be accessed using the GetLastResult() method.
	 */
	static int GetScreenBrightness(void);
	
	/**
	 * Checks whether the screen is on.
	 * 
	 * @since 		2.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return                        @c true if the screen is on, @n
    *        	                     else @c false
	 * @exception E_SUCCESS          The method is successful.
	 * @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM						A system error has occurred.
	 * @remarks This method returns @c true when the screen is in the dimming state, and @c false in case of an error. The specific error code can be accessed using the GetLastResult() method.
	 */
	static bool IsScreenOn (void);


	/**
	 * @if PRIVCORE 
	 * Turns on the screen.
	 *
	 * @since									2.0
	 * @privlevel							CORE
	 * @privgroup 						POWER_MANAGEMENT
	 * @return								An error code
	 * @exception E_SUCCESS 	The method is successful.
	 * @exception E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		A system error has occurred.	 
	 * @endif
	 */
	static result TurnScreenOn(void);
	
	/**
	 * @if PRIVCORE 
	 * Turns off the screen.
	 *
	 * @since									2.0
	 * @privlevel							CORE
	 * @privgroup 						POWER_MANAGEMENT
	 * @return								An error code
	 * @exception E_SUCCESS 	The method is successful.
	 * @exception E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	static result TurnScreenOff(void);
	
private:
	/**
	 * Returns the instance of the porting interface.
	 */
	static IPowerManagerPi* GetInstance(void);

public:
	/**
   * @if PRIVCORE 
	 * Changes the policy of the CPU (Central Processing Unit) power management.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup POWER_MANAGEMENT
	 *
	 * @return		An error code
	 * @param[in]	enable		Set to @c true to prevent the CPU from going into sleep mode, @n
	 *                      	else @c false to let the state of the CPU follow the system default power management policy
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception  E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @endif
	 */
	static result KeepCpuAwake(bool enable);

	/**
	 * Sets the screen event listener.
	 *
	 * @since			1.0
	 * @param[in]	listener				The screen event listener
	 * @see				IScreenEventListener
	 */
	static void SetScreenEventListener(const IScreenEventListener& listener);

	/**
	 * Sets the charging event listener.
	 *
	 * @since			1.0
	 * @param[in]	listener				The charging event listener
	 * @see				IChargingEventListener
	 */
	static void SetChargingEventListener(const IChargingEventListener& listener);	
	
		/**
	 * Sets the battery event listener.
	 *
	 * @since 		2.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return 		An error code
	 * @param[in]	pListener 	The battery event listener
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception E_SYSTEM	A system error has occurred.
	 * @see				IBatteryEventListener
	 * @remarks		If @c pListener is set to @c null, the pre-registered listener is unregistered.
	 */
	static result SetBatteryEventListener(const IBatteryEventListener* pListener);

private:
	static IPowerManagerPi* __pIPowerManagerPi;

private:
	friend class PowerManagerEx;
	class PowerManagerEx* __pPowerManagerEx;
};
};	};
#endif

