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
 * @file		FUixSensorData.h
 * @brief		This is the header file for the %SensorData class.
 *
 * This header file contains the declarations of the %SensorData class.
 */
#ifndef _FUIX_SENSOR_DATA_H_
#define _FUIX_SENSOR_DATA_H_

// Include
#include "FUixConfig.h"
#include "FBase.h"
#include "FUixSensorTypes.h"

struct __SensorEventListenerAdapter;

namespace Osp { namespace Uix {

/**
* @class SensorData
* @brief This class stores sensor data, including a time stamp.
* @since 1.0
*
* The %SensorData class stores sensor data, including a time stamp.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/uix/sensor_manager.htm">Sensor Manager</a>.
*
*/
class _EXPORT_UIX_ SensorData :
	public Osp::Base::Object
{
public:
// Lifecycle
	/**
	* This is the default constructor for this class.
	*
	* @since 1.0
	*/
	SensorData(void);

	/**
	* This is the destructor for this class.
	*
	* @since 1.0
	*/
	virtual ~SensorData(void);

	/**
	* Gets sensor data with key input as a long value.
	*
	* @since 			1.0
	* @return			An error code
	* @param[in]	dataKey		The key to access the sensor data
	* @param[out]	value			The @c long value representing the sensor data requested by the user
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	A data matching the specified key and data type cannot be found.
	*/
	virtual result GetValue (SensorDataKey dataKey, long& value);

	/**
	* Gets the sensor data with key input as a float value.
	*
	* @since 			1.0
	* @return			An error code
	* @param[in]	dataKey		The key to access the sensor data
	* @param[out]	value			The @c float value representing the sensor data requested by the user
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	A data matching the specified key and data type cannot be found.
	*/
	virtual result GetValue (SensorDataKey dataKey, float& value);

	/**
	* Gets the sensor data with key input as a bool value.
	*
	* @since 			1.0
	* @return			An error code
	* @param[in]	dataKey		The key to access the sensor data
	* @param[out]	value			The @c bool value representing the sensor data requested by the user
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	A data matching the specified key and data type cannot be found.
	*/
	virtual result GetValue (SensorDataKey dataKey, bool& value);

protected:
	/**
	 * @internal
	 * This variable is for internal use only.
	 * The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	 * that might arise after using this variable.
	 *
	 * The value of time stamp of sensor data.
	 *
	 * @since	1.0
	 */
	long __timeStamp;
	/**
	 * @internal
	 * This variable is for internal use only.
	 * The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	 * that might arise after using this variable.
	 *
	 * The list of sensor data.
	 *
	 * @since	1.0
	 */
	Osp::Base::Collection::ArrayList* __pDataList;

	friend class SensorManager;

public:
	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this method.
	*
	* Sets sensor data with key input.
	*
	* @since 			1.0
	*/
	virtual result SetValue(SensorDataKey dataKey, long value);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this method.
	*
	* Sets sensor data with key input.
	*
	* @since 			1.0
	*/
	virtual result SetValue(SensorDataKey dataKey, float value);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this method.
	*
	* Sets sensor data with key input.
	*
	* @since 			1.0
	*/
	virtual result SetValue(SensorDataKey dataKey, bool value);

private:
	friend class SensorDataEx;
	class SensorDataEx* __pSensorDataEx;
};// Osp::Uix::SensorData

}; };	// Osp::Uix
#endif // _FUIX_SENSOR_DATA_H_
