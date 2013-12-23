/* $Change: 1248480 $ */
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
* @file			FUixHaptic.h
* @brief		This is the header file for the %Haptic class.
*
* This header file contains the declarations of the %Haptic class.
*/

#ifndef _FUIX_HAPTIC_H_
#define _FUIX_HAPTIC_H_

// Includes
#include "FUixConfig.h"
#include "FUixHapticCommon.h"
#include "FBaseObject.h"

namespace Osp{ namespace Uix{ class IHapticPi; } }

namespace Osp{ namespace Uix{

/**
* @class	Haptic
* @brief		This class is used to control the device's haptics feature.
* @deprecated	This class is deprecated because it is not supported by the platform. 
* @since		1.0
*
* The %Haptic class provides the ability to play different kinds of haptic effects. The class also includes methods for receiving
* the current status and effect completion of the haptics.
*
* The following example demonstrates how to use the %Haptic class to play MagSweep and IVT effects.
* 
* @code
*
* // ===================================================================
* // Usage example 1:
* //    - Getting the device capability
* //    - Playing a periodic effect
* //    - Preconditions:
* //        - Haptics feature must be enabled by the system
* // ===================================================================
*
* #include <FBase.h>
* #include <FIo.h>
* #include <FUix.h>
*
* using namespace Osp::Base;
* using namespace Osp::Io;
* ...
* void MyClass::TestHapticEffects()
* {
*		int hEffect(Osp::Uix::Haptic::BAD_HANDLE);
*
*		Osp::Uix::Haptic *pHaptic = new Osp::Uix::Haptic();
*
*		pHaptic->Construct();
*		pHaptic->OpenDevice(0);
*
*		// --> Now playing effects is possible
*		Osp::Uix::HapticPeriodicEffect periodicEffect;
*		periodicEffect.duration = 3000;
*		periodicEffect.period = 100;
*		periodicEffect.style = Osp::Uix::VIB_EFFECTSTYLE_STRONG;
*		periodicEffect.attackTime = 1000;
*		periodicEffect.attackLevel = 10000;
*		periodicEffect.magnitude = 5000;
*		periodicEffect.fadeTime = 1000;
*		periodicEffect.fadeLevel = 0;
*
*		pHaptic->PlayPeriodicEffect(periodicEffect, hEffect);
*
*		// ... something happened in the application and it has lost focus
*		// so stop the effect immediately
*
*		pHaptic->StopPlayingEffect(hEffect);
*
* // ================================================================
* // Usage example 2:
* //    - Loading IVT Data from IVT file and playing effects from the loaded data
* //    - Recommended usage style:
* //		IVT file can contain periodic effects, MagSweep effects or
* //		a combination of these basic types called a
* //        TimeLine effect, which calls basic effects in sequence,
* //        thus forming a more complex new effect
* //        - Load IVT data once in the client application
* //        - Play effects from the loaded data using the effectIndex
* // ================================================================
*
* // Use file system to load the IVT file to a buffer
*
*		...
*		// File construction
*		String ivtFileName(L"/Home/button.ivt");
*		File ivtfile;
*		ByteBuffer ivtArray;
*		FileAttributes attribute;
*
*		ivtfile.Construct (ivtFileName, L"r");
*
*		// Get the file size
*		ivtfile.GetAttributes(ivtFileName, attribute);
*		int filesize = (int)attribute.GetFileSize();
*		ivtArray.Construct(filesize);
*
*		ivtfile.Read(ivtArray);
*
*		pHaptic->PlayEffect(ivtArray, 0, hEffect);
*
*		pHaptic->CloseDevice();
*		delete pHaptic;
* }
* @endcode
*/

class _EXPORT_UIX_ Haptic :
	public Osp::Base::Object
{

public:

	static const int BAD_HANDLE = -1;							/**< Returns an invalid handle @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_S_SUCCESS = 0;							/**< Success @since 1.0 @n 
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_W_NOT_PLAYING = 1;						/**< Effect is not playing @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_W_INSUFFICIENT_PRIORITY = 2;			/**< Effect does not have enough priority to play: a higher priority effect is playing on the device @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_W_EFFECTS_DISABLED = 3;				/**< Effects are disabled on the device @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_E_NOT_INITIALIZED = -2	;				/**< The method is not initialized @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_W_NOT_PAUSED = 4;						/**< The ImmVibeResumePausedEffect() method cannot resume an effect that is not paused @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_E_ALREADY_INITIALIZED	= -1;			/**< The method is already initialized (NOT USED) @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_E_INVALID_ARGUMENT = -3;				/**< Invalid argument is used in an API method call @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_E_FAIL = -4;							/**< Generic error @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_E_INCOMPATIBLE_EFFECT_TYPE = -5;		/**< Incompatible Effect type has been passed into an API method call @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_E_INCOMPATIBLE_CAPABILITY_TYPE	= -6;	/**< Incompatible Capability type is used in one of the following methods @see GetDeviceCapability() @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_E_INCOMPATIBLE_PROPERTY_TYPE = -7	;	/**< Incompatible Property type is used in one of the following methods @see GetDeviceProperty() @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_E_DEVICE_NEEDS_LICENSE = -8;			/**< Access to the device instance is locked until a valid license key is provided. Use SetDeviceProperty() to set the license key @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_E_NOT_ENOUGH_MEMORY = -9  ;			/**< The method cannot allocate memory to complete the process @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_E_SERVICE_NOT_RUNNING = -10 ;			/**< ImmVibeService is not running @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_E_INSUFFICIENT_PRIORITY = -11 ;		/**< Not enough priority to achieve the request (insufficient license key priority) @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_E_SERVICE_BUSY = -12 ;					/**< ImmVibeService is busy and has failed to complete the request @since 1.0 @n
																	 @deprecated This variable is deprecated because it is not supported by the platform.*/

// Lifecycle
public:

	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
	*/
	Haptic(void);

	/**
	*	This is the destructor for this class. @n
	*	The resources are deallocated by this method.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
	*/
	virtual ~Haptic(void);

//Operation
public:

	/**
	* Initializes this instance of %Haptic. @n
	* Every application must call Construct() before calling any other haptic method.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return		An error code
	* @exception	E_SUCCESS				   	The method is successful.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_INVALID_STATE				This instance has already been constructed.
	* @exception	E_UNSUPPORTED_OPERATION 	The haptic operation is not supported in this device. 
	* @exception  	VIB_E_FAIL                 	An error has occurred while initializing the method.
	* @exception	VIB_E_SERVICE_NOT_RUNNING	The vibrator service is not running. Try to re-start the service or re-install the TouchSense Player method to restore the default settings.
	* @exception	VIB_E_SERVICE_BUSY			The vibrator service is busy and cannot complete the requested method call.
	* @exception	VIB_E_NOT_ENOUGH_MEMORY		The method cannot allocate memory to complete the request.
	*/
	result Construct(void);
	
private:
	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this method.
	*
	* Initializes the Haptic API. @n
	* Every application must call Initialize before calling any other Haptic method (this method might be moved to Construct() later).
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
	*/
	result Initialize(void);

public:
	/**
	* Opens and connects to the device. @n
	* Before playing the haptic effects on a device or controlling the device, the application must call this method.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		 1.0
	* @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n 
	*                For more information, see @ref CompHapticOpenDevicePage "here". 
      *
 	* @return		 An error code
	* @param[in]	 deviceIndex          		The index of the device to open @n
	*											The index of the device must be greater than or equal to @c 0 and less than the number of devices returned by the GetDeviceCount() method.
	* @exception 	VIB_S_SUCCESS				The method is successful.
	* @exception 	VIB_E_INVALID_ARGUMENT		The specified @c deviceIndex is negative, or greater than, or equal to the actual number of devices.
	* @exception 	VIB_E_FAIL					An error has occurred while initializing the method.
	* @exception 	VIB_E_NOT_ENOUGH_MEMORY		The method cannot allocate memory to complete the request.
	* @exception 	VIB_E_SERVICE_BUSY			The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE				This instance has not been constructed because haptic is not supported, or this instance is in an invalid state. 
	*
	* @remarks		The device count can be obtained using GetDeviceCount() method.
	*/
	result OpenDevice(int deviceIndex);

 /**
 * @page  CompHapticOpenDevicePage Compatibility for OpenDevice()
 *
 * @section CompHapticOpenDevicePageIssueSection Issues 
 *   Implementation of this method in bada API versions prior to 1.2 has the following issues: @n
 *	-# Returns VIB_E_INVALID_ARGUMENT instead of E_INVALID_STATE, when the following methods are called without calling the OpenDevice() method in an appropriate manner or the OpenDevice() method is not called. @n 
 *		- CloseDevice()
 *		- SetDeviceProperty()
 *		- GetDeviceProperty()
 *		- GetEffectState()
 *		- PlayEffect()
 *		- PlayEffectRepeat()
 *		- PlayMagSweepEffect()
 *		- PlayPeriodicEffect()
 *		- PausePlayingEffect()
 *		- ResumePausedEffect()
 *		- StopPlayingEffect()
 *		- StopAllPlayingEffects()
 *		- ModifyPlayingMagSweepEffect()
 *		- ModifyPlayingPeriodicEffect()
 *		- GetDeviceState()
 *		- GetDeviceCapability()
 *	-# Returns VIB_S_SUCCESS instead of E_INVALID_STATE, when the following methods are called without calling the %OpenDevice() method. @n 
 *		- GetDeviceState()
 *		- GetDeviceCapability()
 *
 * @section CompHapticOpenDevicePageSolutionSection Resolutions
 *   The issues mentioned above are resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above.
 *
 */ 

	/**
	* Frees resources with the device when an application is about to terminate or no longer needs to play haptics on the device.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return		An error code
	* @exception 	VIB_S_SUCCESS			The method is successful.
	* @exception 	VIB_E_FAIL				An error has occurred while initializing the method.
	* @exception 	VIB_E_SERVICE_BUSY		The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.

	*/
	result CloseDevice(void);

	/**
	 * Retrieves the number of embedded haptic devices.
	 *
	 * @deprecated	This method is deprecated because it is not supported by the platform. 
	 * @since		1.0
       *
	 * @return		The number of available devices that are supported by the method, @n
	 *				else @c -1 if the method is unsuccessful
	 */
	int GetDeviceCount(void) const;

	/**
	* Retrieves the current haptic device status.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return 		An error code
	* @param[out]	status						The current haptics device status
	* @exception 	VIB_S_SUCCESS				The method is successful.
	* @exception 	VIB_E_FAIL					An error has occurred while initializing the method.
	* @exception 	VIB_E_SERVICE_BUSY			The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	* @remarks		The device count can be obtained using the GetDeviceCount() method.
	* @see 			Osp::Uix::HapticDeviceState
	*/
	result GetDeviceState(HapticDeviceState& status) const;

	/**
	* Sets the specified property of the haptic device using the specified bool value.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return		An error code
	* @param[in] 	devicePropertyType 					The property type for the property to be set
	* @param[in] 	devicePropertyValue 				The @c boolean type value to be set
	* @exception	VIB_S_SUCCESS						The method is successful.
	* @exception	VIB_E_INVALID_ARGUMENT				A specified input parameter is invalid.
	* @exception	VIB_E_FAIL							An error has occurred while initializing the method.
	* @exception	VIB_E_INCOMPATIBLE_PROPERTY_TYPE	The specified property type cannot be found or is not supported by the current device.
	* @exception	VIB_E_SERVICE_BUSY					The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	* @see 			Osp::Uix::HapticDevicePropertyTypes
	*/
	result SetDeviceProperty(HapticDevicePropertyTypes devicePropertyType, bool devicePropertyValue);

	/**
	* Sets the specified property of the haptic device using the given integer value. 
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*					For more information, see @ref CompHapticSetDevicePropertyPage "here".
	* 
	* @return		An error code
	* @param[in] 	devicePropertyType 					The property type for the property to be set
	* @param[in] 	devicePropertyValue 				The integer type value to be set
	* @exception 	VIB_S_SUCCESS						The method is successful.
	* @exception 	VIB_E_INVALID_ARGUMENT				A specified input parameter is invalid.
	* @exception 	VIB_E_FAIL							An error has occurred while initializing the method.
	* @exception	VIB_E_INCOMPATIBLE_PROPERTY_TYPE	The specified property type cannot be found or is not supported by the current device.
	* @exception	VIB_E_INSUFFICIENT_PRIORITY			The instance does not have sufficient priority to perform the requested operation.
	* @exception 	VIB_E_SERVICE_BUSY					The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
   	* @see 			Osp::Uix::HapticDevicePropertyTypes
	*/
	result SetDeviceProperty(HapticDevicePropertyTypes devicePropertyType, int devicePropertyValue);

	/**
	* @page		CompHapticSetDevicePropertyPage Compatibility for SetDeviceProperty()
	*
	* @section	CompHapticSetDevicePropertyPageIssueSection Issues	
	*			Implementation of this method in bada API versions prior to 1.2 has the following issues: @n
  	* 			-# Returns E_SUCCESS instead of E_INVALID_ARG, if the @c devicePropertyValue is invalid. @n
    * 			-# If this method is called with VIB_DEVPROPTYPE_MASTERSTRENGTH as the argument, it returns VIB_E_INSUFFICIENT_PRIORITY instead of changing the strength of the instance.
	*
	* @section	CompHapticSetDevicePropertyPageSolutionSection Resolutions
	*			The issues mentioned above are resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above.
	*
	*/


	/**
	* Sets the specified property of the haptic device using the given string value.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return		An error code
	* @param[in] 	devicePropertyType 					The property type for the property to be set
	* @param[in] 	devicePropertyValue 				The String type value to be set 
	* @exception 	VIB_S_SUCCESS						The method is successful.
	* @exception 	VIB_E_INVALID_ARGUMENT				A specified input parameter is invalid.
	* @exception 	VIB_E_FAIL							An error has occurred while initializing the method.
	* @exception	VIB_E_INCOMPATIBLE_PROPERTY_TYPE	The specified property type cannot be found or is not supported by the current device.
	* @exception 	VIB_E_SERVICE_BUSY					The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	* @see 			Osp::Uix::HapticDevicePropertyTypes
	*/
	result SetDeviceProperty(HapticDevicePropertyTypes devicePropertyType, const Osp::Base::String& devicePropertyValue);

	/**
	* Gets the bool value of the specified property.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return		An error code
	* @param[in] 	devicePropertyType 					The property type for the property to get
	* @param[out]	devicePropertyValue 				The reference to a @c boolean type variable to receive the value
	* @exception 	VIB_S_SUCCESS						The method is successful.
	* @exception 	VIB_E_INVALID_ARGUMENT				A specified input parameter is invalid.
	* @exception 	VIB_E_FAIL							An error has occurred while initializing the method.
	* @exception	VIB_E_INCOMPATIBLE_PROPERTY_TYPE	The specified property type cannot be found or is not supported by the current device.
	* @exception 	VIB_E_SERVICE_BUSY					The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	* @see 			Osp::Uix::HapticDevicePropertyTypes
	*/
	result GetDeviceProperty(HapticDevicePropertyTypes devicePropertyType, bool& devicePropertyValue) const;

	/**
	* Gets the integer value of the specified property.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return		An error code
	* @param[in]	devicePropertyType					The property type for the property to get
	* @param[out]	devicePropertyValue					The reference to the integer type variable to receive the value
	* @exception 	VIB_S_SUCCESS						The method is successful.
	* @exception 	VIB_E_INVALID_ARGUMENT				A specified input parameter is invalid.
	* @exception 	VIB_E_FAIL							An error has occurred while initializing the method.
	* @exception	VIB_E_INCOMPATIBLE_PROPERTY_TYPE	The specified property type cannot be found or is not supported by the current device.
	* @exception 	VIB_E_SERVICE_BUSY					The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	* @see 			Osp::Uix::HapticDevicePropertyTypes
	*/
	result GetDeviceProperty(HapticDevicePropertyTypes devicePropertyType, int& devicePropertyValue) const;

	/**
	* Gets the string value of the specified property.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return		An error code
	* @param[in] 	devicePropertyType					The property type for the property to get
	* @param[out]	devicePropertyValue					The reference to the String type variable to receive the value
	* @exception 	VIB_S_SUCCESS						The method is successful.
	* @exception 	VIB_E_INVALID_ARGUMENT				A specified input parameter is invalid.
	* @exception 	VIB_E_FAIL							An error has occurred while initializing the method.
	* @exception	VIB_E_INCOMPATIBLE_PROPERTY_TYPE	The specified property type cannot be found or is not supported by the current device.
	* @exception 	VIB_E_SERVICE_BUSY					The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	* @see 			Osp::Uix::HapticDevicePropertyTypes
	*/	
	result GetDeviceProperty(HapticDevicePropertyTypes devicePropertyType, Osp::Base::String& devicePropertyValue) const;

	/**
	* Gets the integer value of the specified capability type.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return 		An error code
	* @param[in] 	deviceCapabilityType				The capability type to get
	* @param[out]	deviceCapabilityValue				The reference to the integer type variable to receive the value
	* @exception 	VIB_S_SUCCESS						The method is successful.
	* @exception 	VIB_E_INVALID_ARGUMENT				A specified input parameter is invalid.
	* @exception	VIB_E_INCOMPATIBLE_PROPERTY_TYPE	The specified property type cannot be found or is not supported by the current device.
	* @exception 	VIB_E_SERVICE_BUSY					The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	* @see 			Osp::Uix::HapticDeviceCapabilityTypes
	*/
	result GetDeviceCapability(HapticDeviceCapabilityTypes deviceCapabilityType, int& deviceCapabilityValue) const;

	/**
	* Gets the string value of the specified capability type.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform.
	* @since		1.0
      *
	* @return 		An error code
	* @param[in] 	deviceCapabilityType				The capability type to get
	* @param[out]	deviceCapabilityValue				The reference to the String type variable to receive the value
	* @exception 	VIB_S_SUCCESS						The method is successful.
	* @exception 	VIB_E_INVALID_ARGUMENT				A specified input parameter is invalid.
	* @exception	VIB_E_INCOMPATIBLE_CAPABILITY_TYPE	The specified capability type cannot be found or is not supported by the current device.
	* @exception 	VIB_E_SERVICE_BUSY					The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	* @see 			Osp::Uix::HapticDeviceCapabilityTypes
	*/
	result GetDeviceCapability(HapticDeviceCapabilityTypes deviceCapabilityType, Osp::Base::String& deviceCapabilityValue) const;

	/**
	* Gets the status of an effect (playing, not playing, or paused).
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return 		An error code
	* @param[in] 	effectHandle 				A handle to the effect @n
	*											The effect can be obtained by calling any one of the following methods: @n
	*											PlayMagSweepEffect(), PlayPeriodicEffect(), PlayEffect(), and PlayEffectRepeat().
	* @param[out]	effectState 				A pointer to the variable that receives the status bits of the effect
	* @exception 	VIB_S_SUCCESS				The method is successful.
	* @exception 	VIB_E_INVALID_ARGUMENT		A specified input parameter is invalid.
	* @exception 	VIB_E_SERVICE_BUSY			The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	* @see 			Osp::Uix::HapticEffectState
	*/
	result GetEffectState(int effectHandle, HapticEffectState& effectState) const;

	/**
	* Plays an effect defined in the IVT data.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return 		An error code
	* @param[in] 	ivtData 					A reference to the IVT data containing the definition of the effect to be played
	* @param[in] 	effectIndex 				The index of the effect to be played @n
	*											The index of the effect must be greater than or equal to @c 0 and less than the number of effects returned by the GetEffectCount() method.
	* @param[out]	effectHandle 				A reference to the variable that will receive a handle to the playing effect
	* @exception 	VIB_S_SUCCESS				The method is successful.
	* @exception 	VIB_W_INSUFFICIENT_PRIORITY	The device priority is lower than that of the currently playing effects that belong to another device instance.
	* @exception 	VIB_W_EFFECTS_DISABLED		The haptic effect is disabled on this device. @n
	*											Set the VIB_DEVPROPTYPE_DISABLE_EFFECTS property to @c false to re-enable the playing effects on this device.
	* @exception 	VIB_E_INVALID_ARGUMENT		A specified input parameter is invalid.
	* @exception 	VIB_E_FAIL					An error has occurred while initializing the method.
	* @exception 	VIB_E_NOT_ENOUGH_MEMORY		The method cannot allocate memory to complete the request.
	* @exception 	VIB_E_SERVICE_BUSY			The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	*/
	result PlayEffect(const Osp::Base::ByteBuffer& ivtData, int effectIndex, int& effectHandle);

	/**
	* Plays a Timeline effect defined in the IVT data repeatedly. @n
	*
	* The current implementation of PlayEffectRepeat() repeats only Timeline effects. @n
	* If the given effect index refers to a simple effect, %PlayEffectRepeat() ignores the repeat parameter and plays the
	* simple effect once. In that case, %PlayEffectRepeat() behaves like PlayEffect(). %PlayEffectRepeat() does not return a warning
	* when requested to repeat a simple effect.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return 		An error code
	* @param[in] 	ivtData 		A reference to the IVT data containing the definition of the effect to be played
	* @param[in] 	effectIndex 	The index of the effect to be played @n
	*								The index of the effect must be greater than or equal to @c 0 and less than the number of effects returned by the GetEffectCount() method.
	* @param[in] 	repeat 			The number of times the effect has to be repeated @n
	*								To play the effect indefinitely, set repeat to VIB_REPEAT_COUNT_INFINITE(). @n
	*								To repeat the effect a finite number of times, set repeat to a value from @c 0 to @c [VIB_REPEAT_COUNT_INFINITE() - 1] @n
	*								The effect can be repeated at the most [VIB_REPEAT_COUNT_INFINITE() - 1] times. @n
	*								Setting repeat to @c 0 plays the effect once (repeats the effect zero times) and is equivalent to calling PlayEffect(). @n
	*								To stop the effect before it has been repeated the requested number of times, or to stop an effect that is playing indefinitely, call StopPlayingEffect() or StopAllPlayingEffects().
	* @param[out]	effectHandle				A reference to the variable that receives a handle to the playing effect
	* @exception 	VIB_S_SUCCESS				The method is successful.
	* @exception 	VIB_W_INSUFFICIENT_PRIORITY	The device priority is lower than that of the currently playing effects that belong to another device instance.
	* @exception 	VIB_W_EFFECTS_DISABLED		The haptic effect is disabled on this device. @n
	*											Set the VIB_DEVPROPTYPE_DISABLE_EFFECTS property to false to re-enable the playing effects on this device.
	* @exception 	VIB_E_INVALID_ARGUMENT		A specified input parameter is invalid.
	* @exception 	VIB_E_FAIL					An error has occurred while initializing the method.
	* @exception 	VIB_E_NOT_ENOUGH_MEMORY		The method cannot allocate memory to complete the request.
	* @exception 	VIB_E_SERVICE_BUSY			The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *                                       - This instance or the device is in an invalid state. @n
    *                                       - The haptic is not supported. @n
    *                                       - The method is called without opening the device.
	*/
	result PlayEffectRepeat( const Osp::Base::ByteBuffer& ivtData, int effectIndex, unsigned char repeat, int& effectHandle);

	/**
	* Plays a MagSweep effect given the parameters defining the effect.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*					For more information, see @ref CompHapticPlayMagSweepEffectPage "here".
	*
	* @return 		An error code
	* @param[in] 	effect 						The reference to the HapticMagSweepEffect instance defining the @c effect parameter
	* @param[out]	effectHandle 				A reference to the variable that receives a handle to the playing effect
	* @exception 	VIB_S_SUCCESS				The method is successful.
	* @exception 	VIB_W_NOT_PLAYING			The effect is not playing.
	* @exception 	VIB_W_INSUFFICIENT_PRIORITY	The device priority is lower than that of the currently playing effects that belong to another device instance.
	* @exception 	VIB_W_EFFECTS_DISABLED		The haptic effect is disabled on this device. @n
	*											Set the VIB_DEVPROPTYPE_DISABLE_EFFECTS property to false to re-enable the playing effects on this device.
	* @exception 	VIB_E_INVALID_ARGUMENT		A specified input parameter is invalid.
	* @exception 	VIB_E_FAIL					An error has occurred while initializing the method.
	* @exception 	VIB_E_SERVICE_BUSY			The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	*
	* @see 			Osp::Uix::HapticDeviceCapabilityTypes
	*/
	result PlayMagSweepEffect(const HapticMagSweepEffect& effect, int& effectHandle);

	/**
	* @page		CompHapticPlayMagSweepEffectPage Compatibility for PlayMagSweepEffect()
	*
	* @section	CompHapticPlayMagSweepEffectPageIssueSection Issues
	*			Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	* 			-# Returns E_SUCCESS instead of E_INVALID_ARG, if the style in @c effect is invalid.
	*
	* @section	CompHapticPlayMagSweepEffectPageSolutionSection Resolutions
	*			The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above.
	*
	*/

	/**
	* Plays a Periodic effect given the parameters defining the effect.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*                	For more information, see @ref CompHapticPlayPeriodicEffectPage "here".
	*
	* @return 		An error code
	* @param[in] 	effect						The reference to the HapticPeriodicEffect instance defining the @c effect parameter
	* @param[out]	effectHandle 				A reference to the variable that receives a handle to the playing effect
	* @exception 	VIB_S_SUCCESS				The method is successful.
	* @exception 	VIB_W_NOT_PLAYING			The effect is not playing.
	* @exception 	VIB_W_INSUFFICIENT_PRIORITY	The device priority is lower than that of the currently playing effects that belong to another device instance.
	* @exception 	VIB_W_EFFECTS_DISABLED		The haptic effect is disabled on this device. @n
	*											Set the VIB_DEVPROPTYPE_DISABLE_EFFECTS property to false to re-enable the playing effects on this device.
	* @exception 	VIB_E_INVALID_ARGUMENT		A specified input parameter is invalid.
	* @exception 	VIB_E_FAIL					An error has occurred while initializing the method.
	* @exception 	VIB_E_SERVICE_BUSY			The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	*
	* @see 			Osp::Uix::HapticPeriodicEffect
	*/
	result PlayPeriodicEffect(const HapticPeriodicEffect& effect, int& effectHandle);

	/**
	* @page		CompHapticPlayPeriodicEffectPage Compatibility for PlayPeriodicEffect()
	*
	* @section	CompHapticPlayPeriodicEffectPageIssueSection Issues
	*			Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	* 			-# Returns E_SUCCESS instead of E_INVALID_ARG, if the style in @c effect is invalid.
	*
	* @section	CompHapticPlayPeriodicEffectPageSolutionSection Resolutions
	*			The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above.
	*
	*/

	/**
	* Pauses a playing effect. @n
	* If this method is called with an effect handler for which the play of the effect has been finished or stopped, VIBE_E_INVALID_ARGUMENT will be returned.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return 		An error code
	* @param[in] 	effectHandle 				The handle to the playing effect to be paused @n
	*                        					The handle to the effect must be obtained by calling any one of the following methods: @n
 	*											PlayMagSweepEffect(), PlayPeriodicEffect(), PlayEffect(), and PlayEffectRepeat().
	* @exception 	VIB_S_SUCCESS				The method is successful.
	* @exception 	VIB_W_NOT_PLAYING			The effect is not playing.
	* @exception 	VIB_E_INVALID_ARGUMENT		The specified input parameter is invalid.
	* @exception 	VIB_E_FAIL					An error has occurred while initializing the method.
	* @exception 	VIB_E_NOT_ENOUGH_MEMORY		The method cannot allocate memory to complete the request.
	* @exception 	VIB_E_SERVICE_BUSY			The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	*/
	result PausePlayingEffect(int effectHandle);

	/**
	* Resumes playback on a paused effect from the point where the effect is paused. @n
	*		
	* Depending on the slots available, it is possible that all the simple effects from a paused IVT cannot be resumed. @n
	* The method returns success when it is able to play one of these simple effects. @n
	* If this method is called with an effect handler for which the play of the effect has been finished or stopped, VIBE_E_INVALID_ARGUMENT will be returned.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	*@since		1.0
      *
	* @return 		An error code
	* @param[in] 	effectHandle 				The handle to the paused effect to be resumed @n
	*											The handle to the effect must be obtained by calling one of the PlayMagSweepEffect(), PlayPeriodicEffect(), PlayEffect(), or PlayEffectRepeat() methods.
	* @exception 	VIB_S_SUCCESS				The method is successful.
	* @exception 	VIB_W_NOT_PLAYING			The effect is not playing.
	* @exception 	VIB_W_INSUFFICIENT_PRIORITY	The device priority is lower than that of the currently playing effects that belong to another device instance.
	* @exception 	VIB_W_NOT_PAUSED			The effect is not paused.
	* @exception 	VIB_E_INVALID_ARGUMENT		The specified input parameter is invalid.
	* @exception 	VIB_E_FAIL					An error has occurred while initializing the method.
	* @exception 	VIB_E_SERVICE_BUSY			The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	*/
	result ResumePausedEffect(int effectHandle);

	/**
	* Stops a playing effect. @n
	* If this method is called with an effect handler for which the play of the effect has been finished or stopped, VIBE_E_INVALID_ARGUMENT will be returned.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return 		An error code
	* @param[in] 	effectHandle 				The handle to the paused effect to be resumed @n
	*                        					The handle to the effect must be obtained by calling any one of the following methods: @n
	*											PlayMagSweepEffect(), PlayPeriodicEffect(), PlayEffect(), and PlayEffectRepeat().
	* @exception 	VIB_S_SUCCESS				The method is successful.
	* @exception 	VIB_W_NOT_PLAYING			The effect is not playing.
	* @exception 	VIB_E_INVALID_ARGUMENT		The specified input parameter is invalid.
	* @exception 	VIB_E_FAIL					An error has occurred while initializing the method.
	* @exception 	VIB_E_SERVICE_BUSY			The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	*/
	result StopPlayingEffect(int effectHandle);

	/**
	* Stops all the playing and paused effects of a haptics instance.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform.
	* @since		1.0
	* 
      * @return 		An error code
	* @exception 	VIB_S_SUCCESS				The method is successful.
	* @exception 	VIB_E_FAIL					An error has occurred while initializing the method.
	* @exception 	VIB_E_SERVICE_BUSY			The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	*/
	result StopAllPlayingEffects(void);

	/**
	* Gets the number of effects from the IVT data.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform.
	* @since		1.0
      *
	* @return		The number of effects in the IVT file, @n
	*				else an error code if an exception occurs
	* @param[in] 	ivtData						A reference to the IVT data containing the definition of the effect to be played
	* @exception 	VIB_S_SUCCESS				The method is successful.
	* @exception 	VIB_E_INVALID_ARGUMENT		The specified input parameter is invalid.
	* @exception 	VIB_E_FAIL					An error has occurred while initializing the method.
	*/
	int GetEffectCount(const Osp::Base::ByteBuffer& ivtData) const;

	/**
	* Gets the duration of an effect defined in the IVT data.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform.
	* @since		1.0
      *
	* @return 		An error code
	* @param[in] 	ivtData 					A reference to the IVT data containing the definition of the effect to be played
	* @param[in] 	effectIndex 				The effect for which the duration is needed
	* @param[out]	effectDuration 				A reference to the variable that receives the requested effect's duration value in milliseconds
	* @exception 	VIB_S_SUCCESS				The method is successful.
	* @exception 	VIB_E_INVALID_ARGUMENT		A specified input parameter is invalid.
	* @exception 	VIB_E_FAIL					An error has occurred while initializing the method.
	* @exception	E_INVALID_STATE				This instance has not been constructed because haptic is not supported, or this instance is in an invalid state. 
	*/
	result GetEffectDuration(const Osp::Base::ByteBuffer& ivtData, int effectIndex, int& effectDuration) const;

	/**
	* Gets the infinite duration. @n
	* Used to get the infinite duration when specifying the duration parameters in calls to the PlayMagSweepEffect(), PlayPeriodicEffect(), ModifyPlayingMagSweepEffect(), ModifyPlayingMagSweepEffect(), and ModifyPlayingPeriodicEffect() methods.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	*
	* @since		1.0
      *
	* @return		The value of the infinite duration
	*/
	int GetInfiniteDuration(void) const;


	/**
	* Gets the index of an effect defined in IVT data.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return 	 	An error code
	* @param[in] 	ivtData						A reference to the IVT data containing the definition of the effect to play
	* @param[in] 	effectName					The name of the effect for which to get the index
	* @param[out]	effectIndex					A reference to the variable that will receive the index of the effect
	* @exception 	VIB_S_SUCCESS				The method is successful.
	* @exception 	VIB_E_INVALID_ARGUMENT		A specified input parameter is invalid.
	* @exception 	VIB_E_FAIL					An error has occurred while initializing the method.
	* @exception	E_INVALID_STATE				This instance has not been constructed because haptic is not supported, or this instance is in an invalid state.
	*/
	result GetEffectIndexFromName(const Osp::Base::ByteBuffer& ivtData, const Osp::Base::String& effectName, int& effectIndex) const;

	/**
	* Gets the name of an effect defined in the IVT data.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return		An error code
	* @param[in]	ivtData						A reference to the IVT data containing the definition of the effect to play
	* @param[in]	effectIndex					The index of the effect for which to get the name @n
	*											The index of the effect must be greater than or equal to @c 0 and less than the number of effects returned by the GetEffectCount() method.
	* @param[out]	effectName					A reference to the variable that will receive the requested effect's type value @n
	*											See Effect Types for a list of the possible effect types.
	* @exception	VIB_S_SUCCESS				The method is successful.
	* @exception	VIB_E_INVALID_ARGUMENT		A specified input parameter is invalid.
	* @exception	VIB_E_FAIL					An error has occurred while initializing the method.
	* @exception	E_INVALID_STATE				This instance has not been constructed because haptic is not supported, or this instance is in an invalid state. 
	*/
	result GetEffectName(const Osp::Base::ByteBuffer& ivtData, int effectIndex, Osp::Base::String& effectName) const;

	/**
	* Gets the type of an effect defined in the IVT data.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return 		An error code
	* @param[in] 	ivtData					A reference to IVT data containing the definition of the effect to play
	* @param[in] 	effectIndex				The index of the effect for which to get the name @n
	*										The index of the effect must be greater than or equal to @c 0 and less than the number of effects returned by the GetEffectCount() method.
	* @param[out]	effectType				A reference to the variable that will receive the requested effect's type value @n
	*										See Effect Types for a list of the possible effect types.
	* @exception 	VIB_S_SUCCESS			The method is successful.
	* @exception 	VIB_E_INVALID_ARGUMENT	A specified input parameter is invalid.
	* @exception 	VIB_E_FAIL				An error has occurred while initializing the method.
	* @exception	E_INVALID_STATE			This instance has not been constructed because haptic is not supported, or this instance is in an invalid state. 
	*/
	result GetEffectType(const Osp::Base::ByteBuffer& ivtData, int effectIndex, HapticEffectTypes& effectType) const;

	/**
	* Gets the parameters of a MagSweep effect defined in the IVT data.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return 		An error code
	* @param[in] 	ivtData							A reference to the IVT data containing the definition of the effect to play
	* @param[in] 	effectIndex						The index of the effect for which to get the name @n
	*												The index of the effect must be greater than or equal to @c 0 and less than the number of effects returned by the GetEffectCount() method.
	* @param[out]	effect							A reference to the variable that will receive the MagSweep effect information
	* @exception	VIB_S_SUCCESS					The method is successful.
	* @exception 	VIB_E_INVALID_ARGUMENT			A specified input parameter is invalid.
	* @exception 	VIB_E_FAIL						An error has occurred while initializing the method.
	* @exception 	VIB_E_INCOMPATIBLE_EFFECT_TYPE	The specified effect type is not supported by the current device.
	* @exception	E_INVALID_STATE					This instance has not been constructed because haptic is not supported, or this instance is in an invalid state. 
	*/
	result GetMagSweepEffectDefinition(const Osp::Base::ByteBuffer& ivtData, int effectIndex,  HapticMagSweepEffect& effect) const;

	/**
	* Gets the parameters of a Periodic effect defined in the IVT data.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since		1.0
      *
	* @return 		An error code
	* @param[in] 	ivtData							A reference to the IVT data containing the definition of the effect to play
	* @param[in] 	effectIndex						The index of the effect for which to get the name @n
	*												The index of the effect must be greater than or equal to @c 0 and less than the number of effects returned by the GetEffectCount() method.
	* @param[out]	effect							A reference to the variable that will receive the periodic effect information
	* @exception 	VIB_S_SUCCESS					The method is successful.
	* @exception 	VIB_E_INVALID_ARGUMENT			A specified input parameter is invalid.
	* @exception 	VIB_E_FAIL						An error has occurred while initializing the method.
	* @exception 	VIB_E_INCOMPATIBLE_EFFECT_TYPE	The specified effect type is not supported by the current device.
	* @exception	E_INVALID_STATE					This instance has not been constructed because haptic is not supported, or this instance is in an invalid state. 
	*/
	result GetPeriodicEffectDefinition(const Osp::Base::ByteBuffer& ivtData, int effectIndex, HapticPeriodicEffect& effect) const;

	/**
	* Modifies a playing MagSweep effect. @n
	* If this method is called with an effect handler for which the play of the effect has been finished or stopped, VIBE_E_INVALID_ARGUMENT will be returned.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. 
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*                	For more information, see @ref CompHapticModifyPlayingMagSweepEffectPage "here".
	*
	* @return 		An error code
	* @param[in] 	effectHandle					A handle to the playing MagSweep effect to modify @n
	*												The handle to the effect must have been obtained by calling the PlayMagSweepEffect(), PlayEffect(), or PlayEffectRepeat() methods.
	* @param[in] 	effect							A reference to the variable that will modify the MagSweep effect information
	* @exception	VIB_S_SUCCESS					The method is successful.
	* @exception 	VIB_W_NOT_PLAYING				The effect is not playing.
	* @exception	VIB_E_INVALID_ARGUMENT			A specified input parameter is invalid.
	* @exception	VIB_E_FAIL						An error has occurred while initializing the method.
	* @exception	VIB_E_INCOMPATIBLE_EFFECT_TYPE	The specified effect type is not supported by the current device.
	* @exception	VIB_E_SERVICE_BUSY				The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	*/
	result ModifyPlayingMagSweepEffect(int effectHandle, const HapticMagSweepEffect& effect);

	/**
	* @page		CompHapticModifyPlayingMagSweepEffectPage Compatibility for ModifyPlayingMagSweepEffect()
	*
	* @section	CompHapticModifyPlayingMagSweepEffectPageIssueSection Issues
	*			Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	* 			-# Returns E_SUCCESS instead of E_INVALID_ARG, if the style in @c effect is invalid.
	*
	* @section	CompHapticModifyPlayingMagSweepEffectPageSolutionSection Resolutions
	*			The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above.
	*
	*/
	

	/**
	* Modifies a playing Periodic effect. @n
	* If this method is called with an effect handler for which the play of the effect has been finished or stopped, VIBE_E_INVALID_ARGUMENT will be returned.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*                	For more information, see @ref CompHapticModifyPlayingPeriodicEffectPage "here".
	*
	* @return 		An error code
	* @param[in] 	effectHandle					A handle to the playing Periodic effect to modify @n
	*												The handle to the effect must have been obtained by calling the PlayMagSweepEffect(), PlayEffect(), or PlayEffectRepeat() methods.
	* @param[in] 	effect							A reference to the variable that will modify the periodic effect information
	* @exception	VIB_S_SUCCESS					The method is successful.
	* @exception 	VIB_W_NOT_PLAYING				The effect is not playing.
	* @exception	VIB_E_INVALID_ARGUMENT			A specified input parameter is invalid.
	* @exception	VIB_E_FAIL						An error has occurred while initializing the method.
	* @exception 	VIB_E_INCOMPATIBLE_EFFECT_TYPE	The specified effect type is not supported by the current device.
	* @exception	VIB_E_SERVICE_BUSY				The vibrator service is busy and cannot complete the requested method call.
	* @exception	E_INVALID_STATE			Either of the following conditions has occurred: @n
    *										- This instance or the device is in an invalid state. @n
    *										- The haptic is not supported. @n
    *										- The method is called without opening the device.
	*/
	result ModifyPlayingPeriodicEffect(int effectHandle, const HapticPeriodicEffect& effect);

	/**
	* @page		CompHapticModifyPlayingPeriodicEffectPage Compatibility for ModifyPlayingPeriodicEffect()
	*
	* @section	CompHapticModifyPlayingPeriodicEffectPageIssueSection Issues
	*			Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	* 			-# Returns E_SUCCESS instead of E_INVALID_ARG, if the style in @c effect is invalid.
	*
	* @section	CompHapticModifyPlayingPeriodicEffectPageSolutionSection Resolutions
	*			The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above.
	*
	*/

	
private:
	Haptic(const Haptic& value);
	Haptic& operator =(const Haptic& value);	
	IHapticPi* __pIHapticPi;

	friend class HapticEx;
	class HapticEx* __pHapticEx;
};

} } //Osp::Uix

#endif
