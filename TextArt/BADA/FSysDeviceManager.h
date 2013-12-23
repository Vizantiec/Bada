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
 * @file			FSysDeviceManager.h 
 * @brief		This is the header file for the %DeviceManager class.
 *
 * This header file contains the declarations of the %DeviceManager class.
 *
 * 
 */

 
#ifndef _FSYS_DEVICE_H_
#define _FSYS_DEVICE_H_

#include "FSysConfig.h"
#include "FBaseObject.h"

namespace Osp { namespace System {

class IDeviceEventListener;

/**
* @enum DeviceType
* Defines the type of the supported devices.
*
* @since 1.1 
* 
*/
typedef enum {
	BluetoothHeadset,	  /**< Bluetooth headset */
	Charger, /**< Charger*/
	UsbClient, /**< USB client */
	TvOut, /**< TV out */
	WiredHeadset, /**< Wired headset */
	WiredHeadphone, /**< Wired headphone */
	StorageCard, /**< Storage card */
	Keyboard /**< Hardware keyboard */
}DeviceType;

/**
 * @class		DeviceManager
 * @brief		This class provides methods for device management.
 * @since		1.1
 *
 * The %DeviceManager class provides listener to handle events for various device accessories, 
 * such as a Bluetooth headset, TV-out, and headphone. 
 * This class also gets the current state of the device. You cannot create an instance of this class directly.
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/device_management.htm">Device Accessory Management</a>.
 *
 * @see IDeviceEventListener
 */
class _EXPORT_SYSTEM_ DeviceManager :
	public Osp::Base::Object
{
private:
	/**
	 * This is the default constructor for this class.
	 */
	 DeviceManager(void);

	 /**
	  * This is the destructor for this class. @n
	  */
	  virtual ~DeviceManager(void);

public:
	
	/**
	 * Gets the specific device state.
	 *
	 * @since			1.1
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *	 
	 * @param[in]	deviceType		The value from the enumerator DeviceType indicating the device
	 * @param[out]	state		The device <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/device_management.htm">state</a> of type String
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.	 
	 * @exception	E_SYSTEM	A system error has occurred.
 	 * @exception	E_INVALID_ARG	 The specified @c deviceType is not valid.
 	 * @exception  E_DEVICE_UNAVAILABLE The specified @c deviceType is not available on this model.
 	 * @exception  E_PRIVILEGE_DENIED The application does not have the privilege to call this method.	 
     */
	static result GetState(DeviceType deviceType, Osp::Base::String &state);
	/**
	 * Adds a device event listener.
	 *	 
	 * @since			1.1
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	deviceType			The types of a device
	 * @param[in]	listener				The device event listener	 
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @exception	E_INVALID_ARG	 The specified @c deviceType is not valid.
	 * @exception   E_DEVICE_UNAVAILABLE The specified @c deviceType is not available on this model.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.	 
 	 */	
	static result AddDeviceEventListener(DeviceType deviceType, const IDeviceEventListener& listener);
	/**
	 * Removes all the device event listeners.
	 *	 
	 * @since			1.1
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	deviceType			The types of a device
	 * @param[in]	listener				The device event listener	 
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred. 	 
	 * @exception	E_INVALID_ARG	 The specified @c deviceType is not valid.
	 * @exception   E_DEVICE_UNAVAILABLE The specified @c deviceType is not available on this model.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method. 	 
    */	
	static result RemoveDeviceEventListener(DeviceType deviceType, const IDeviceEventListener& listener);
	/**
	 * Removes a device event listener from all types of devices.
	 *	 
	 * @since			1.1
	 * @privlevel	NORMAL	 
	 * @privgroup SYSTEM_SERVICE	 
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful. 
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @exception  E_PRIVILEGE_DENIED The application does not have the privilege to call this method. 	 
 	 */	
	static result RemoveAllDeviceEventListeners(void);
		
private:	
	friend class DeviceManagerEx;
	class DeviceManagerEx* __pDeviceManagerEx;
};
};	};
#endif 

