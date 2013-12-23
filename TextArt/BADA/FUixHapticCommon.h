/* $Change: 1232335 $ */
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
* @file			FUixHapticCommon.h 
* @brief		This is the header file for the type declarations of the HapticMagSweepEffect and the HapticPeriodicEffect class.
*
* This header file contains the type declarations of the HapticMagSweepEffect and the HapticPeriodicEffect class.
*/

#ifndef _FUIX_HAPTIC_COMMON_H_
#define _FUIX_HAPTIC_COMMON_H_

//Include
#include "FUixConfig.h"

namespace Osp{ namespace Uix{ 

	static const int VIB_MIN_MAGNITUDE = 0;				/**< The minimum magnitude value @since 1.0 @n
															 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_MAX_MAGNITUDE = 10000;			/**< The maximum magnitude value @since 1.0 @n
															 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_MIN_DEV_PRIORITY = 0;			/**< The minimum device priority @since 1.0 @n
															 @deprecated This variable is deprecated because it is not supported by the platform.*/
	static const int VIB_MAX_DEV_PRIORITY = 7;			/**< The maximum device priority @since 1.0 @n
															 @deprecated This variable is deprecated because it is not supported by the platform.*/
	const int VIB_REPEAT_COUNT_INFINITE = 255;			/**< An infinite repeat Count @since 1.0 @n
															 @deprecated This variable is deprecated because it is not supported by the platform.*/
	const int VIB_MAX_EFFECT_NAME_LENGTH = 128;			/**< The maximum length of an effect name stored in an IVT file @since 1.0 @n
															 @deprecated This variable is deprecated because it is not supported by the platform.*/
	const int VIB_MAX_DEVICE_NAME_LENGTH = 64;			/**< The maximum device name length @since 1.0 @n
															 @deprecated This variable is deprecated because it is not supported by the platform.*/
	const int VIB_MAX_CAPABILITY_STRING_LENGTH = 64;	/**< The maximum string length used by GetDeviceCapability() @since 1.0 @n
															 @deprecated This variable is deprecated because it is not supported by the platform.*/
	const int VIB_MAX_PROPERTY_STRING_LENGTH = 64;		/**< The maximum string length used by GetDeviceProperty(), SetDeviceProperty() @since 1.0 @n 
															 @deprecated This variable is deprecated because it is not supported by the platform.*/
	const int VIB_MAX_STREAMING_SAMPLE_SIZE = 256;		/**< The maximum size for a streaming sample @since 1.0 @n
															 @deprecated This variable is deprecated because it is not supported by the platform.*/
	const int VIB_DEVPRIORITY_DEFAULT = 0;				/**< The device default priority value @since 1.0 @n
															 @deprecated This variable is deprecated because it is not supported by the platform.*/
	
	/**
	* @enum  HapticDeviceState
	* Defines the current haptic device states.
	* @deprecated	This enum is deprecated because it is not supported by the platform.
	* @since 1.0
      *
	* @see	 Haptic::GetDeviceState()
	*/
	enum HapticDeviceState
	{
		VIB_DEVICESTATUS_ATTACHED = (1<<0),		/**< The device is physically connected	*/
		VIB_DEVICESTATUS_BUSY = (1<<1)			/**< The device is currently playing effects */
	};


	/**
	* @enum  HapticEffectState
	* Defines the current haptic effect states.
	* @deprecated	This enum is deprecated because it is not supported by the platform.
	* @since 1.0
      *
	* @see  Haptic::GetEffectState()
	*/
	enum HapticEffectState
	{
		VIB_EFFECTSTATE_NOT_PLAYING = 0,	/**< The not playing/not paused effect state */
		VIB_EFFECTSTATE_PLAYING,			/**< The playing effect state */
		VIB_EFFECTSTATE_PAUSED				/**< The paused effect state */
	};
 
 	/**
 	* @enum  HapticDevicePropertyTypes
	* Defines the haptic device property types.
	* @deprecated	This enum is deprecated because it is not supported by the platform.
	* @since 1.0
      *
 	* @see   Haptic::SetDeviceProperty(), Haptic::GetDeviceProperty()
 	*/
 	enum HapticDevicePropertyTypes
 	{ 
 		/**
 		* The property used to set/get the priority for the effects to be played @n
 		* Use the @c int overloaded version of the SetDeviceProperty() and GetDeviceProperty() methods to use this property. @n
 		* Different haptics instances can use different priorities on the same physical device. 
		* The priority determines which haptics instance's effects are played when multiple haptics instances are attempting to play effects at the same time. @n
 		* The default priority is VIB_DEVPRIORITY_DEFAULT.  
		* The priority value can range from VIB_MIN_DEV_PRIORITY to VIB_MAX_DEV_PRIORITY.
		* The GetDeviceProperty() method returns a value inside @c devicePropertyValue that ranges between VIB_MIN_DEV_PRIORITY to VIB_MAX_DEV_PRIORITY. 
		* If the VIB_DEVPROPTYPE_PRIORITY property is not set, the GetDeviceProperty() method returns a value of VIB_DEVPRIORITY_DEFAULT.
 		*/
		VIB_DEVPROPTYPE_PRIORITY = 1, 
 
 		/**
 		* The property used to disable the effects for the client's haptics instance @n
 		* Use the @c bool overloaded version of the SetDeviceProperty() and GetDeviceProperty() methods to use this property. @n
 		* When this property is set to @c true, any currently playing effects are immediately stopped and subsequent requests to play the effects are ignored. 
		* This is only applicable to the calling client's haptics instance. When this property is set to @c false, subsequent requests to play the effects are honored.
 		* The default value for this property is @c false.
 		*/
 		VIB_DEVPROPTYPE_DISABLE_EFFECTS, 
 
 		/**
 		* A property that reduces/increases the magnitude of all effects for a particular haptics instance @n
 		* Use the @c int overloaded version of the SetDeviceProperty() and GetDeviceProperty() methods to use this property. @n
 		* The VIB_DEVPROPTYPE_STRENGTH property ranges from @c 0 to @c 10,000, where @c 0 is "silent" (equivalent to "mute"), and @c 10,000 is "full strength". 
		* The default value for VIB_DEVPROPTYPE_STRENGTH is @c 10,000. @n
 		* If the VIB_DEVPROPTYPE_STRENGTH property is not set, the default value is used.
 		* When reducing/increasing the magnitude of the effects by setting the VIB_DEVPROPTYPE_STRENGTH property, it only applies to the haptics instance of the client that called the method. 
		* If there is a second haptics instance held by the same or a different client, it is not affected by the setting of the VIB_DEVPROPTYPE_STRENGTH property of the first client's haptics instance. @n
 		* Modifying the VIB_DEVPROPTYPE_STRENGTH property of the haptics instance does not affect the effects currently being played. 
		* The effects played or modified after calling the SetDeviceProperty() method using the new VIB_DEVPROPTYPE_STRENGTH value are affected.
 		*/
 		VIB_DEVPROPTYPE_STRENGTH, 
 
 		/**
 		* A property that reduces/increases the magnitude of all the effects for all haptics instances, for example, the whole device. @n
 		* Use the @c int overloaded version of the SetDeviceProperty() and GetDeviceProperty() methods to use this property. @n
 		* The VIB_DEVPROPTYPE_MASTERSTRENGTH property ranges from @c 0 to @c 10,000, where @c 0 is "silent" (equivalent to "mute"), and @c 10,000 is "full strength".
 		* The default value for MasterStrength is @c 10,000. @n
 		* If the VIB_DEVPROPTYPE_MASTERSTRENGTH property of the haptics instance is not set, the default value is used. @n
 		* When reducing/increasing the magnitude of the effects, VIB_DEVPROPTYPE_MASTERSTRENGTH property affects all playing effects on all haptics instances on the device.
 		* This means that all the haptics instances held by other clients are affected by the setting of the VIB_DEVPROPTYPE_MASTERSTRENGTH property of the first client's haptics instance.
		*
		* @remarks From bada API version 1.2, if SetDeviceProperty() is called with VIB_DEVPROPTYPE_MASTERSTRENGTH, it changes the strength of the instance instead of returning VIB_E_INSUFFICIENT_PRIORITY.
 		*/
 		VIB_DEVPROPTYPE_MASTERSTRENGTH
 	};
 

	/**
	* @enum 	HapticDeviceCapabilityTypes
	* Defines the haptic device's capability types.
	* @deprecated	This enum is deprecated because it is not supported by the platform.
	* @since 	1.0
      *
	* @see 		Haptic::GetDeviceCapability()
	*/
 	enum HapticDeviceCapabilityTypes
 	{
 		/**
		* Gets the device category types.
 		*/
		VIB_DEVCAPABILITY_CATEGORY = 0,
 		 
 		/**
 		* Gets the maximum number of nested repeat bars supported for Timeline effects. @n
 		* Any repeat bars nested beyond this level are played only once.
 		*/
		VIB_DEVCAPABILITY_MAX_NESTED_REPEATS,
 		 
 		/**
 		* Gets the number of haptic actuators present in the device.
 		*/
		VIB_DEVCAPABILITY_NUM_ACTUATORS,
 
 		/**
 		* Gets the actuator types.
 		*/
		VIB_DEVCAPABILITY_ACTUATOR_TYPE,
 
 		/**
 		* Gets the number of effect slots. @n
 		* The number of effect slots represent the maximum number of simple effects that can be played simultaneously. @n
 		* If an attempt is made to play more than the specified number of effects at the same time, some of the simple effects do not play.
 		*/
		VIB_DEVCAPABILITY_NUM_EFFECTSLOTS,
 
 		/**
 		* Gets the combination of the supported effect styles. @n
		* They are stored as a bit field.
 		*/
		VIB_DEVCAPABILITY_SUPPORTEDSTYLES,
 
 		/**
 		* Gets the minimum period required for the Periodic effects.
 		*/
 		VIB_DEVCAPABILITY_MIN_PERIOD,
		 
 		/**
 		* Gets the maximum period required for the Periodic effects.
 		*/
 		VIB_DEVCAPABILITY_MAX_PERIOD,
 
 		/**
 		* Gets the maximum duration required for the MagSweep and Periodic effects in milliseconds.
 		*/
		VIB_DEVCAPABILITY_MAX_EFFECT_DURATION,
 
 		/**
 		* Gets the supported effect types. @n
		* They are stored as a bit field.
 		*/
		VIB_DEVCAPABILITY_SUPPORTED_EFFECTS,

 		/**
 		* Gets the device name.
 		*/
		VIB_DEVCAPABILITY_DEVICE_NAME,
 	 
 		/**
 		* Gets the maximum start time or fade time in milliseconds for the effect envelopes of the MagSweep or Periodic effects.
 		*/
		VIB_DEVCAPABILITY_ENVELOPTIME,
 		 
 		/**
 		* Gets the TouchSense Mobile Player version number from the hexadecimal format. @n
 		* The format is OxMMNNSSBB, where MM is the major version number, NN is the minor version number, SS is a special build number, and BB is the VTMP build number.
 		* For example, for the hexadecimal format 0x02000053, the version number is 2.0.53.
 		*/
		VIB_DEVCAPABILITY_API_VER_NUMBER,
 		 
 		/**
 		* Gets the maximum size in bytes of the IVT file that can be played on a non-tethered device.
 		*/
		VIB_DEVCAPABILITY_MAX_IVT_SIZE = 14

 	};
 
 	/**
 	* @enum 	HapticDeviceCategoryTypes
	* Defines the haptic device category types.
	* @deprecated	This enum is deprecated because it is not supported by the platform.
	* @since 	1.0
      *
	* @see 		HapticDeviceCapabilityTypes::VIB_DEVCAPABILITY_CATEGORY Haptic::GetDeviceCapability()
 	*/
 	enum HapticDeviceCategoryTypes
 	{
		VIB_DEVCATEGORY_VIRTUAL = 2,	/**< Only one generic virtual device is available */
		VIB_DEVCATEGORY_EMBEDDED = 3	/**< No restrictions @n Generally, mobile devices only have one haptic actuator */
  	};
 
 	/**
 	* @enum  	HapticSupportedEffectTypes
	* Defines the bitmask for the device's supported effects. @n
 	* To be used to analyze the value returned by GetDeviceCapability().
	* @deprecated	This enum is deprecated because it is not supported by the platform.
	* @since 	1.0
      *
	* @see 		HapticDeviceCapabilityTypes::VIB_DEVCAPABILITY_SUPPORTED_EFFECTS Haptic::GetDeviceCapability()
 	*/
 	enum HapticSupportedEffectTypes
 	{
		VIB_SUPPORT_PERIODIC = 1,	/**< The bitmask for Periodic effect support */
		VIB_SUPPORT_MAGSWEEP = 2,	/**< The bitmask for Magsweep effect support */
		VIB_SUPPORT_TIMELINE = 3,	/**< The bitmask for Timeline effect support */
		VIB_SUPPORT_STREAMING = 4	/**< The bitmask for Streaming effect support */
 	};
 
	/**
	* @enum  	HapticEffectTypes
	* Defines the bitmask for the device's effect types.
	* @deprecated	This enum is deprecated because it is not supported by the platform.
	* @since 	1.0
      *
	* @see   	Haptic::GetEffectType()
	*/
 	enum HapticEffectTypes
 	{
		VIB_EFFECTTYPE_PERIODIC = 0,	/**< The Periodic effect type constant */
		VIB_EFFECTTYPE_MAGSWEEP,		/**< The Magsweep effect type constant */
		VIB_EFFECTTYPE_TIMELINE,		/**< The Timeline effect type constant */
		VIB_EFFECTTYPE_STREAMING		/**< The Streaming effect type constant */
 	};
 
	/**
	* @enum  	HapticSupportedEffectStyles
	* Defines the bitmask for the device's supported effect styles. @n
	* To be used to analyze the value returned by GetDeviceCapability().
	* @deprecated	This enum is deprecated because it is not supported by the platform.
	* @since 	1.0
      *
	* @see 		HapticDeviceCapabilityTypes::VIB_DEVCAPABILITY_SUPPORTEDSTYLES Haptic::GetDeviceCapability()
	*/
 	enum HapticSupportedEffectStyles
 	{
		VIB_SUPORTEDSTYLE_SMOOTH = 1,	/**< The bitmask for "Smooth" style support */
		VIB_SUPORTEDSTYLE_STRONG = 2,	/**< The bitmask for "Strong" style support */
		VIB_SUPORTEDSTYLE_SHARP = 4		/**< The bitmask for "Sharp" style support  */
 	};
 
 	/**
 	* @enum 	HapticEffectStyles
	* Defines the haptic effect styles. @n
 	* Used to specify the Periodic or MagSweep effect style when calling the following methods.
	* @deprecated	This enum is deprecated because it is not supported by the platform.
 	* @since 	1.0
      *
 	* @see   	Haptic::PlayMagSweepEffect(), Haptic::PlayPeriodicEffect(), Haptic::ModifyPlayingMagSweepEffect(), Haptic::ModifyPlayingPeriodicEffect()
 	*/
 	enum HapticEffectStyles
 	{
		VIB_EFFECTSTYLE_SMOOTH = 0,	/**< The "Smooth" effect style */
 		VIB_EFFECTSTYLE_STRONG,		/**< The "Strong" effect style */
 		VIB_EFFECTSTYLE_SHARP		/**< The "Sharp" effect style  */
 	};
 
 	/**
 	* @enum  	HapticActuatorTypes
	* Defines the haptic actuator types. @n
 	* To be used with GetDeviceCapability().
	* @deprecated	This enum is deprecated because it is not supported by the platform.
 	* @since 	1.0
      *
	* @see 		HapticDeviceCapabilityTypes::VIB_DEVCAPABILITY_ACTUATOR_TYPE Haptic::GetDeviceCapability()
 	*/
 	enum HapticActuatorTypes
 	{
		VIB_ACTUATORTYPE_ERM = 0, /**< The Eccentric Rotating Mass actuator */
		VIB_ACTUATORTYPE_LRA = 2 /**< The Linear Resonant actuator */
  	};
 
	/**
	* @class HapticMagSweepEffect
	* @brief		This class defines the parameters used in a MagSweep effect.
	* @deprecated	This class is deprecated because it is not supported by the platform. 
	* @since		1.0
	*
	* The %HapticMagSweepEffect class has a set of envelope parameters that control the duration and strength of the vibration over a period of time. 
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/uix/haptic_features.htm">Haptic Features</a>.
	*
	* @see    Haptic::PlayMagSweepEffect()
	*/
	class HapticMagSweepEffect
	{
	public:
		/**
		* Gets the overall duration of the effect in milliseconds. @n
		* For a finite duration, the effect duration is clamped to a value from @c 0 to the value returned by the GetDeviceCapability() method 
		* for the VIB_DEVCAPABILITY_MAX_EFFECT_DURATION capability type, inclusive of both the limits.
		*
		* @since 1.0
		*/
		int duration;

		/**
		* Gets the magnitude of the effect. @n
		* The effect magnitude is clamped to a value from VIB_MIN_MAGNITUDE to VIB_MAX_MAGNITUDE, inclusive of both limits.
		*
		* @since 1.0
		*/
		int magnitude;

		/**
		* Gets the style of the effect. @n
		* This is one of the specified HapticEffectStyles.
		*
		* @since 1.0
		*/
		int style;

		/**
		* Gets the attack time of the effect in milliseconds. @n
		* The attack time is clamped to a value from @c 0 to the value returned by the GetDeviceCapability() method, for the VIB_DEVCAPABILITY_ENVELOPTIME capability type, inclusive of both limits.
		*
		* @since 1.0
		*/
		int attackTime;

		/**
		* Gets the attack level of the effect. @n
		* The attack level is clamped to a value from VIB_MIN_MAGNITUDE to VIB_MAX_MAGNITUDE, inclusive of both limits.
		*
		* @since 1.0
		*/
		int attackLevel;

		/**
		* Gets the fade time of the effect in milliseconds. @n
		* The fade time is clamped to a value from @c 0 to the value returned by the GetDeviceCapability() method for the VIB_DEVCAPABILITY_ENVELOPTIME capability type, inclusive of both limits.
		*
		* @since 1.0
		*/
		int fadeTime;

		/**
		* Gets the fade level of the effect. @n
		* The fade level is clamped to a value from VIB_MIN_MAGNITUDE to VIB_MAX_MAGNITUDE, inclusive of both limits.
		*
		* @since 1.0
		*/
		int fadeLevel;

		private:
		friend class HapticMagSweepEffectEx;
		class HapticMagSweepEffectEx* __pHapticMagSweepEffectEx;
	};

	/**
	* @class HapticPeriodicEffect
	* @brief		This class defines the parameters used in a periodic effect.
	* @deprecated	This class is deprecated because it is not supported by the platform. 
	* @since		1.0
	*
	* The %HapticPeriodicEffect class has a set of envelope parameters that control the duration and strength of the vibration over a period of time.
	* It allows the period or speed of the vibration to be controlled explicitly, independent of the magnitude.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/uix/haptic_features.htm">Haptic Features</a>.
	*
	* @see		Haptic::PlayPeriodicEffect()
	*/
	class HapticPeriodicEffect
	{
	public:
		/**
		* Gets the duration of the effect in milliseconds. @n
		* To specify an infinite duration, the effect duration must be set to GetInfiniteDuration(). @n
		* For a finite duration, the effect duration is clamped to a value from @c 0 to the value returned by the GetDeviceCapability() method 
		* for the VIB_DEVCAPABILITY_MAX_EFFECT_DURATION capability type, inclusive of both the limits.
		*
		* @since 1.0
		*/
		int duration;

		/**
		* Gets the magnitude of the effect. @n
		* The effect magnitude is clamped to a value from VIB_MIN_MAGNITUDE to VIB_MAX_MAGNITUDE, inclusive of both limits.
		*
		* @since 1.0
		*/
		int magnitude;

		/**
		* Gets the period of the effect in milliseconds. @n
		* The period is clamped to a value returned by the GetDeviceCapability() method for the VIB_DEVCAPABILITY_MIN_PERIOD capability type to the value returned by the GetDeviceCapability() method 
		* for the VIB_DEVCAPABILITY_MAX_PERIOD capability type, inclusive of both the limits.
		*
		* @since 1.0
		*/
		int period;

		/**
		* Gets the style of the effect. @n
		* Can be one of HapticEffectStyles.
		*
		* @since 1.0
		*/
		int style;

		/**
		* Gets the attack time of the effect in milliseconds. @n
		* The attack time is clamped to a value from @c 0 to the value returned by the GetDeviceCapability() method for the VIB_DEVCAPABILITY_ENVELOPTIME capability type, inclusive of both limits.
		*
		* @since 1.0
		*/
		int attackTime;

		/**
		* Gets the attack level of the effect. @n
		* The attack level is clamped to a value from VIB_MIN_MAGNITUDE to VIB_MAX_MAGNITUDE, inclusive of both limits.
		*
		* @since 1.0
		*/
		int attackLevel;

		/**
		* Gets the fade time of the effect in milliseconds. @n
		* The fade time is clamped to a value from @c 0 to the value returned by the GetDeviceCapability() method for the VIB_DEVCAPABILITY_ENVELOPTIME capability type, inclusive of both limits.
		*
		* @since 1.0
		*/
		int fadeTime;

		/**
		* Gets the fade level of the effect. @n
		* The fade level is clamped to a value from VIB_MIN_MAGNITUDE to  VIB_MAX_MAGNITUDE, inclusive of both limits.
		*
		* @since 1.0
		*/
		int fadeLevel;

		private:
		friend class HapticPeriodicEffectEx;
		class HapticPeriodicEffectEx* __pHapticPeriodicEffectEx;
	};

} } //Osp::Uix

#endif
