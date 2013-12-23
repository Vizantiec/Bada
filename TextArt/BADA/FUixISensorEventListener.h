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
* @file		FUixISensorEventListener.h
* @brief	This is the header file for the %ISensorEventListener interface.
*
* This header file contains the declarations of the %ISensorEventListener interface.
*
*/

#ifndef _FUIX_ISENSOR_EVENTLISTENER_H_
#define _FUIX_ISENSOR_EVENTLISTENER_H_

// Includes
#include "FUixConfig.h"
#include "FBase.h"
#include "FUixSensorTypes.h"
#include "FUixSensorData.h"


namespace Osp { namespace Uix {

/**
* @interface 	ISensorEventListener
* @brief 		This interface is an event listener used to receive sensor data asynchronously.
* @since 		1.0
*
* The %ISensorEventListener interface is an event listener used to receive sensor data asynchronously.
* It provides methods that are invoked when the sensor data is received from the device.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/uix/sensor_manager.htm">Sensor Manager</a>.
*/
class _EXPORT_UIX_ ISensorEventListener
{
// Lifecycle
//public:
//	virtual ~ISensorEventListener(void);

// Operation
public:
	/**
	* Called when the sensor data is sensed after every sensor interval or when the sensor data is changed from the previous interval.
	*
	* @since 			1.0
	* @param[in]	sensorType		The sensor type
	* @param[in]	sensorData		The array of the sensor data
	* @param[in]	r				The error code
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_DATA	The sensor data is invalid.
	* @remarks	Calling the application methods including the UI, should be handled in the main application thread, that is, outside the sensor event handler OnDataReceived().
	* @see	AccelerationDataKey, MagneticDataKey, ProximityDataKey, TiltDataKey
	*
	* The following example demonstrates how to use this method.
	* 
	* @code
	*
	*  //Sample Code for SensorSample.h
	*  #include <FUix.h>
	*
	*  class SensorSample :
	*	public Osp::Ui::Controls::Form,
	*	public Osp::Uix::ISensorEventListener
	*  {
	*  	public:
	*		virtual result OnDraw();
	*		void OnDataReceived(SensorType sensorType, SensorData& sensorData , result r);
	*		...
	*  }
	*
	*  //Sample Code for SensorSample.cpp
	*  #include "SensorSample.h"
	*
	*  using namespace Osp::Uix;
	*
	*  void
	*  SensorSample::OnDataReceived(SensorType sensorType, SensorData& sensorData , result r)
	*  {
	*	    // ...
	*  }
	*
	*  result
	*  SensorSample::OnDraw()
	*  {
	*		// ...
	*  }
	*
	* @endcode
	*
	*/
	virtual void OnDataReceived(SensorType sensorType, SensorData& sensorData , result r) = 0;

private:
	friend class ISensorEventListenerEx;
	class ISensorEventListenerEx* __pISensorEventListenerEx;

};	// class ISensorEventListener

}; }; // Osp::Uix

#endif // _FUIX_ISENSOR_EVENTLISTENER_H_
