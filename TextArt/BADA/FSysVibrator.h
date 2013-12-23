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
 * @file		FSysVibrator.h 
 * @brief		This is the header file for the %Vibrator class.
 *
 * This header file contains the declarations of the %Vibrator class.
 *
 */

 
#ifndef _FSYS_SYSTEM_VIBRATOR_H_
#define _FSYS_SYSTEM_VIBRATOR_H_

// include
#include "FSysConfig.h"
#include "FBaseObject.h"

namespace Osp { namespace System {

class IVibratorPi;

/**
 * @class		Vibrator 
 * @brief		This class handles the vibration functionality of the device.
 * @since		1.0
 *
 * The %Vibrator class handles the vibration functionality of a device. It allows you to manage the device's vibrator parameters, such as vibration count and level. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/vibrator_mgmt.htm">Vibrator Management</a>.
 *
 * The following example demonstrates how to use the %Vibrator class.
 *
 * @code
 *
 * #include <FBase.h>
 * #include <FSystem.h>
 *
 * using namespace Osp::System;
 *
 * class MyVibratorClass
 * {
 * public:
 * 	result VibratorExample(void);
 * private:
 * 	Vibrator vibrator;
 * };
 * 
 * result
 * MyVibratorClass::VibratorExample(void)
 * {
 * 	result r = vibrator.Construct();
 * 	if (IsFailed(r))
 * 	{
 * 		goto CATCH;
 * 	}
 * 
 * 	// Vibrate with a given pattern and level
 * 	vibrator.Start(2000, 1000, 1, 50);
 * 
 * CATCH:
 * 	// Do some exception handling
 * 	return r;
 * }
 * @endcode
 */

class _EXPORT_SYSTEM_ Vibrator :
	public Osp::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since   1.0
	 * @remarks	     After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 * @see Construct()
	 */
	Vibrator(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since    1.0
	 * @remarks	 If the instance is destroyed before the vibration stops, the vibration is stopped forcefully.
	 */
	virtual ~Vibrator(void);

	/**
	 * Initializes this instance of %Vibrator.
	 * 
	 * @since 			1.0
	 * @return			An error code
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_SYSTEM			An unknown operating system error has occurred.
	 * @exception		E_INVALID_STATE		This instance has already been constructed.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 *							
	 */
	result Construct(void);

public:
	/**
	 * Vibrates the device with the specified pattern and level. @n
     * This method returns the result immediately so that the vibration occurs simultaneously as the device runs.  
     * If this method is called again before the previous vibration stops, the previous vibration is canceled and the new vibration starts immediately.
	 *
     * @since 1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *                For more information, see @ref CompVibratorStartPage2 "here".
	 *
	 * @privlevel	NORMAL
	 * @privgroup	SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	onPeriod	The period in milliseconds when the vibrator is on @n
	 *							It should be greater than @c 0.
	 * @param[in]	offPeriod	The period in milliseconds when the vibrator is off @n
	 *							It should be equal to or greater than @c 0.
	 * @param[in]	count		The number of times to execute the given pattern @n
	 *							It should be greater than @c 0.
	 * @param[in]	level		The vibration level @n
	 *							Ranges from @c [0~100], where ' @c 0' is a special case indicating the system default level.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance has not been constructed as yet.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_DEVICE_BUSY	The device cannot be approached because of other operations.
	 * @exception	E_DEVICE_FAILED	The device operation has failed.
	 * @remarks		           Various devices may have different vibration capabilities.
	 * If the device supports only one level of vibration, then a level value between @c [0~100] results in the default vibration.
	 * If the device supports many levels of vibration, then a level value @c 0 results in the system default vibration, value @c 1 results in the lowest frequency vibration, value @c 100 results in the highest frequency vibration, and intermediate values result in intermediate vibration levels. @n
	 * Devices have implementation-specific limits for the total duration of the vibration, and vibration cuts off at that limit even if the duration parameter is greater than the limit.
	 *
	 */	
	result Start(long onPeriod, long offPeriod, int count, int level = 0);

	/**
	 * Vibrates the device for the specified duration at the specified level. @n
	 * This method returns the result immediately so that the vibration occurs simultaneously as the device runs. 
	 * If this method is called again before the previous vibration stops, the previous vibration is canceled and the new vibration starts immediately.
	 *
	 * @since 1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	 *                For more information, see @ref CompVibratorStartPage "here".
   *
 	 * @privlevel	NORMAL
	 * @privgroup	SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	milliseconds	The duration for the vibration in milliseconds @n
	 *								It should be greater than @c 0.
	 * @param[in]	level			The vibration level @n
	 *								Ranges from @c [0~100], where ' @c 0' is a special case indicating the system default level.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance has not been constructed as yet.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_DEVICE_BUSY	The device cannot be approached because of other operations.
	 * @exception	E_DEVICE_FAILED	The device operation has failed.
	 * @remarks		Various devices have different vibration capabilities. @n
	 * If the device supports only one level of vibration, then a level value between @c [0~100] results in the default vibration.
	 * If the device supports many levels of vibration, then a level value @c 0 results in the system default vibration, value @c 1 results in the lowest frequency vibration, value @c 100 results in the highest frequency vibration, and intermediate values result in intermediate vibration levels. @n
	 * Devices have implementation-specific limits for the total duration of the vibration, and vibration cuts off at that limit even if the duration parameter is greater than the limit.
	 *	
	 */	
	result Start(long milliseconds, int level = 0);

	/**
	* @page		CompVibratorStartPage Compatibility for Start()
	*
	* @section	CompVibratorStartPageIssueSection Issues
	*			Implementation of this method in bada API versions prior to 1.1 has the following issue: @n
	* 			-# If the level is greater than 100, the E_SUCCESS exception is returned instead of E_INVALID_ARG.
	*
	* @section	CompVibratorStartPageSolutionSection Resolutions
	*			The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1 or above.
	*
	*/

	/**
	* @page     CompVibratorStartPage2 Compatibility for Start()
	*
	* @section  CompVibratorStartPage2IssueSection Issues
	*           Implementation of this method in bada API version prior to 1.2 has following issues: @n
	*           -# If @c onPeriod, @c offPeriod, and @c count values are large, the application does not work properly. @n
	*           -# The combination of the above values, (onPeriod + offPeriod) * count, should be less than 2147483647.
	*
	* @section  CompVibratorStartPage2SolutionSection Resolutions
	*           The issues mentioned above are resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. 
	*
	*/
	
	/**
	 * Turns the vibrator off.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE													
	 * 
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance has not been constructed as yet.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception	E_DEVICE_FAILED	The device operation has failed.
	 *
	 */
	result Stop(void);
	
private:
	IVibratorPi* __pIVibratorPi;

private:
	friend class VibratorEx;
	class VibratorEx* __pVibratorEx;
};
};	};
#endif 

