/* $Change: 1225207 $ */
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
 * @file		FUixSensorManager.h
 * @brief		This is the header file for the %SensorManager class.
 *
 * This header file contains the declarations of the %SensorManager class.
 */
#ifndef _FUIX_SENSOR_MANAGER_H_
#define _FUIX_SENSOR_MANAGER_H_

// Include
#include "FUixConfig.h"
#include "FBase.h"
#include "FUixISensorEventListener.h"
#include "FUixSensorTypes.h"
#include "FUixSensorData.h"


// Forward declaration - SC layer
struct IMSensorManager;
struct TagBoolExp;
typedef struct TagBoolExp BoolExp;
typedef unsigned int	ThreadID;

namespace Osp { namespace Uix {
/**
* @class SensorManager
* @brief This class is used to receive sensor data from the device.
* @since 1.0
*
* The %SensorManager class is used to receive and manage sensor data from the device, including adding or removing the sensor
* listeners, checking sensor availability, setting intervals, and getting the maximum or minimum interval.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/uix/sensor_manager.htm">Sensor Manager</a>.
*
* The following example demonstrates how to use the %SensorManager class with the acceleration sensor.
*
* @code
*  //Sample Code for SensorSample.h
*  #include <FUix.h>
*
*  using namespace Osp::Uix;
*
*  	class SensorSample : public ISensorEventListener
*  	{
*  		public:
*  			SensorSample(void);
*  			virtual ~SensorSample(void);
*  			bool CreateSensor(void);
*
*  			virtual void OnDataReceived(SensorType sensorType, SensorData& sensorData, result r);
*
*  		private:
*  			SensorManager __sensorMgr;
*  	};
*
*	//Sample Code for SensorSample.cpp
*	#include "SensorSample.h"
*
*	SensorSample::SensorSample(void)
*	{
*		// Initialize __sensorMgr
*		__sensorMgr.Construct();
*	}
*
*	SensorSample::~SensorSample(void)
*	{
*		// Finalize __sensorMgr
*	}
*
*  	void SensorSample::OnDataReceived(SensorType sensorType, SensorData& sensorData, result r)
*  	{
*		// Add your code
*		//  Refer to API Reference to ISensorEventListener::OnDataReceived()
*		// Application APIs including SensorManager APIs should not be called inside this event handler.
*		// Override OnDataReceived() for just receiving the sensor data and copying it to the main application context.
*
*  	}
*
*  	bool SensorSample::CreateSensor(void)
*  	{
*  		result r = E_SUCCESS;
*
*		if (__sensorMgr.IsAvailable(SENSOR_TYPE_ACCELERATION))
*		{
*  			r = __sensorMgr.AddSensorListener(*this, SENSOR_TYPE_ACCELERATION, 50, true);
*  			if (IsFailed(r))
*  				return false;
*  		}
*  		else
*  		{
*  			AppLogException("Acceleration sensor is not available.");
*  			return false;
*  		}
*
*  		return true;
*  	}
* @endcode
* 
*/
class _EXPORT_UIX_ SensorManager :
	public Osp::Base::Object
{

public:

// Lifecycle
public:
	/**
	*	This is the default constructor for this class.
	*
	* @since 		1.0
	*	@remarks	After creating an instance of this class, the Construct() method
	*				must be called explicitly to initialize this instance.
	*/
	SensorManager(void);

	/**
	* This is the destructor for this class.
	*
	* @since 			1.0
	* @remarks		All listeners are removed
	* 						and the internally allocated memory block is deleted when the instance is destroyed.
	*/
	virtual ~SensorManager(void);


// Operation
public:
	/**
	* Initializes this instance of %SensorManager.
	* It includes initializing the sub-component of the sensor manager.
	*
	* @since 			1.0
	* @return			An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	*/
	result Construct(void);

	/**
	* Adds a sensor listener. Sensor powers up for the first time and adds a sensor listener.
	*
	* @since 					1.0
	* @compatibility  This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*									For more information, see @ref CompSensorManagerAddSensorListenerPage "here".
	*
	* @return			An error code
	* @param[in]	listener		The listener to add
	* @param[in]	sensorType		The sensor type
	* @param[in]	interval		The interval (in milliseconds) at which the sensor data is received
	* @param[in]	dataChanged		Set to @c true if the sensor data is received only when the sensor data is changed, @n
	*							    else @c false if the sensor data is received every interval
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE	This instance has not been constructed as yet.
	* @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	* @exception	E_INVALID_ARG	An interval must be greater than the maximum interval or less than the minimum interval.
	* @exception	E_ILLEGAL_ACCESS Not permitted to add the listener in ISensorEventListener::OnDataReceived(). @n
	*                                @b Deprecated: This exception is deprecated.
	* @exception	E_DEVICE_UNAVAILABLE The specified type of sensor is not available.
	* @exception	E_USER_ALREADY_REGISTERED The specified listener is already registered for the specified sensor type.
	
	* @see SensorType
	*/
	result AddSensorListener(const ISensorEventListener& listener, SensorType sensorType, long interval, bool dataChanged);

	/**
	* @page   CompSensorManagerAddSensorListenerPage Compatibility for AddSensorListener()
	* @section CompSensorManagerAddSensorListenerPageIssueSection Issues
	*                   Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	*
	* -# If an exception occurs while executing AddSensorListener(), all the pre-registered listeners do not work.
	* -# If AddSensorListener() is called inside ISensorEventListener::OnDataReceived(), with a pre-registered listener, it returns E_USER_ALREADY_REGISTERED instead of E_ILLEGAL_ACCESS.
	*
	* @section CompSensorManagerAddSensorListenerIllegalAccessPageResolutionSection Resolutions
	* The issues mentioned above are resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	*/

	/**
	* Removes a sensor listener from all the types of sensor. Sensor powers down when every listener added to the type of sensor is removed.
	*
	* @since 					1.0
	* @compatibility  This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	* 								For more information, see @ref CompSensorManagerRemoveSensorListenerPage "here".
	*
	* @return			An error code
	* @param[in]	listener		The listener to add
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE	This instance has not been constructed as yet.
	* @exception	E_ILLEGAL_ACCESS Not permitted to remove the listener in ISensorEventListener::OnDataReceived(). @n
	*                                @b Deprecated: This exception is deprecated.
	* @exception	E_INVALID_ARG	 The specified listener is not registered for any sensor type.
	
	*/
	result RemoveSensorListener(const ISensorEventListener& listener);

	/**
	* @page   CompSensorManagerRemoveSensorListenerPage Compatibility for RemoveSensorListener(const ISensorEventListener& listener)
	* @section CompSensorManagerRemoveSensorListenerPageIssueSection Issues
	*                   Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	*
	* -# If multiple listeners are registered, calling RemoveSensorListener(const ISensorEventListener& listener) with one of the registered listeners as the input argument makes all the other listeners inoperable. @n
	*
	* @section CompSensorManagerCallbackManagementPageResolutionSection Resolutions
	* The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	*/

	/**
	* Removes a sensor listener from the type of sensor. Sensor powers down when every listener to the type of sensor is removed.
	*
	* @since 			1.0
	* @return			An error code
	* @param[in]	listener		The listener to add
	* @param[in]	sensorType		The sensor type
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE	This instance has not been constructed as yet.
	* @exception	E_ILLEGAL_ACCESS Not permitted to remove the listener in ISensorEventListener::OnDataReceived(). @n
	*                                @b Deprecated: This exception is deprecated.
	* @exception	E_INVALID_ARG	 The specified listener is not registered for the specified sensor type.
	
	*/
	result RemoveSensorListener(const ISensorEventListener& listener, SensorType sensorType);

	/**
	* Sets an interval of a sensor.
	*
	* @deprecated   This method is deprecated because it changes only the first listener's interval; the other listeners do not have an option to change their intervals.
	* To resolve this, a new method has been added. Instead of using this method, use the SetInterval(const ISensorEventListener& listener, SensorType sensorType, long interval) method.
	*
	* @since 			1.0
	* @return			An error code
	* @param[in]	sensorType		The sensor type
	* @param[in]	interval		The interval (in milliseconds) at which the sensor data is received
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE	This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG	An interval must be greater than the maximum interval or less than the minimum interval.
	* @exception	E_DEVICE_UNAVAILABLE The specified type of sensor is not available.
	* @see			SensorManager::GetMaxInterval() and SensorManager::GetMinInterval() for getting the maximum and minimum intervals, respectively.
	*/
	result SetInterval(SensorType sensorType, long interval);

	/**
	* Sets an interval of a sensor using the specified listener.
	*
	* @since			2.0
	* @return			An error code
	* @param[in]	listener		The added listener
	* @param[in]	sensorType		The sensor type
	* @param[in]	interval		The interval (in milliseconds) at which the sensor data is received
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE	This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG	An interval must be greater than the maximum interval or less than the minimum interval, or
	* 								the listener is not registered for this type of sensor.
	* @exception	E_DEVICE_UNAVAILABLE The specified type of sensor is not available.
	* @exception	E_ILLEGAL_ACCESS Not permitted to call this method in ISensorEventListener::OnDataReceived(). @n
	*                                @b Deprecated: This exception is deprecated.
	* @see			SensorManager::GetMaxInterval() and SensorManager::GetMinInterval() for getting the maximum and minimum intervals respectively.
	*/
	result SetInterval(const ISensorEventListener& listener, SensorType sensorType, long interval);

	/**
	* Checks whether the type of sensor is available on this device.
	*
	* @since 			1.0
	* @return			@c true if the sensor type is available, @n
	*					else @c false
	* @param[in]	sensorType		The sensor type
	*/
	bool IsAvailable(SensorType sensorType);

	/**
	* Returns the minimum interval of the sensor type.
	*
	* @since 			1.0
	* @return			An error code
	* @param[in]	sensorType		The sensor type
	* @param[out]	interval		The minimum interval (in milliseconds)
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_DEVICE_UNAVAILABLE The specified type of sensor is not available.
	*/
	result GetMinInterval(SensorType sensorType, long& interval);

	/**
	* Returns the maximum interval of the sensor type.
	*
	* @since 			1.0
	* @return			An error code
	* @param[in]	sensorType		The sensor type
	* @param[out]	interval		The maximum interval in milliseconds
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_DEVICE_UNAVAILABLE The specified type of sensor is not available.
	*/
	result GetMaxInterval(SensorType sensorType, long& interval);

	/**
	* Gets a brief description on this sensor.
	*
	* @since 			1.0
	* @return			An error code
	* @param[in]	sensorType		The sensor type
	* @param[out]	description		The sensor description
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_DEVICE_UNAVAILABLE The specified type of sensor is not available.
	*/
	result GetDescription(SensorType sensorType, Osp::Base::String& description);

	/**
	* Gets the sensor's vendor information.
	*
	* @since 			1.0
	* @return			An error code
	* @param[in]	sensorType		The sensor type
	* @param[out]	vendor			The vendor information
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_DEVICE_UNAVAILABLE The specified type of sensor is not available.
	*/
	result GetVendor(SensorType sensorType, Osp::Base::String& vendor);

	/**
	* Gets the sensor's model ID.
	*
	* @since 			1.0
	* @return			An error code
	* @param[in]	sensorType		The sensor type
	* @param[out]	modelId			The model ID of the sensor hardware
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_DEVICE_UNAVAILABLE The specified type of sensor is not available.
	*/
	result GetModelId(SensorType sensorType, Osp::Base::String& modelId);

	/**
	* Gets the measurement range of the sensor.
	*
	* @since 			1.0
	* @return			An error code
	* @param[in]	sensorType		The sensor type
	* @param[out]	min			The minimum value of the measurement range
	* @param[out]	max			The maximum value of the measurement range
	* @param[out]	resolution	The resolution of the sensor measurement, that is, Measurement/bit @n
	*							This is a device specific characteristic.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_DEVICE_UNAVAILABLE The specified type of sensor is not available.
	*/
	result GetMeasurementRange(SensorType sensorType, float& min, float& max, float& resolution);

	/**
	* Checks whether the wake up feature is supported for the specified sensor type. The return value can vary depending on a specific device model.
	*
	* @since            2.0
	* @return           @c true if the sensor type supports the wake up feature while the device is in the sleep mode, @n
	*                   else @c false if the wake up feature is not supported by the sensor or if the instance is not initialized properly
	* @param[in] sensorType                 The sensor type
	* @exception E_SUCCESS                  The method is successful.
	* @exception E_INVALID_STATE            This instance has not been constructed as yet.
	* @exception E_DEVICE_UNAVAILABLE       The specified type of sensor is not available.
	* @remarks   The specific error code can be accessed using the GetLastResult() method.
	*/
	bool IsWakeupSupported(SensorType sensorType);

	/**
	* Sets the application-wise wake up feature as enabled or disabled for the specified sensor type.
	*
	* @since            2.0
	* @return           An error code
	* @param[in] sensorType                 The sensor type
	* @param[in] enable                     Set to @c true to enable the wake up feature, @n
											else @c false to disable the wake up feature
	* @exception E_SUCCESS                  The method is successful.
	* @exception E_OPERATION_FAILED         The method has failed to set the wake up option.
	* @exception E_INVALID_STATE            This instance has not been constructed as yet, or
                                          	there is no sensor listener registered for this type.
	* @exception E_INVALID_ARG              The wake up feature is not supported by the specified sensor type.
	* @exception E_DEVICE_UNAVAILABLE       The specified type of sensor is not available.
	* @remarks   The wake up feature is automatically disabled by the system as soon as the calling application is terminated.
	*/
	result SetWakeupEnabled(SensorType sensorType, bool enable);

	/**
	* Checks whether the wake up feature is enabled for the specified sensor type.
	*
	* @since            2.0
	* @return           @c true if the wakeup feature is enabled for the specified sensor type for the calling application, @n
	*					else @c false
	* @param[in] sensorType                 The sensor type
	* @exception E_SUCCESS                  The method is successful.
	* @exception E_INVALID_STATE            This instance has not been constructed as yet.
	* @exception E_DEVICE_UNAVAILABLE       The specified type of sensor is not available.
	* @remarks   The specific error code can be accessed using the GetLastResult() method.
	*/
	bool IsWakeupEnabled(SensorType sensorType);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this method.
	*
    * @since   1.0
	*/
    static void HandleCallback(bool enable);
private:
	void SetThreadFlag(bool bFlag);
	bool GetThreadFlag(void);
	void SetThreadID(ThreadID threadID);
	ThreadID GetThreadID(void);

private:
	Osp::Base::Collection::LinkedList*	__pListeners;
	IMSensorManager*						__pIMSensorManager;

private:
	friend class SensorManagerEx;
	class SensorManagerEx* __pSensorManagerEx;
};
};}; // Osp::Uix::SensorManager
#endif // _FUIX_SENSOR_MANAGER_H_
