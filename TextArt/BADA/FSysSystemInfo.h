/* $Change: 1235223 $ */
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
 * @file		FSysSystemInfo.h
 * @brief		This is the header file for the %SystemInfo class.
 *
 * This header file contains the declarations of the %SystemInfo class.
 */

#ifndef _FSYS_SYSTEM_INFO_H_
#define _FSYS_SYSTEM_INFO_H_

// includes
#include "FBaseString.h"
#include "FBaseUuId.h"
#include "FSysConfig.h"
#include "FBaseColIList.h"

namespace Osp { namespace System {


/**
* @enum SystemInfoValueType
* Defines the data type for the %SystemInfo class.
*
* @since 1.0
*/
typedef enum {
	VALUE_TYPE_STRING, /**< The Osp::Base::String type */
	VALUE_TYPE_INTEGER, /**< The Osp::Base::Integer type */
	VALUE_TYPE_DOUBLE, /**< The Osp::Base::Double type */
	VALUE_TYPE_UUID, /**< The Osp::Base::UuId type */
}SystemInfoValueType;

/**
 * @class		SystemInfo
 * @brief		This class provides methods for getting system information.
 * @since 	1.0
 *
 * The %SystemInfo class provides system information, such as the API and platform versions, supported device features, 
 * and screen dimensions. 
 * To get the information, you must provide the <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/sysinfo.htm">SystemInfo key</a>. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/sysinfo.htm">System Information</a>.
 *
 * The following example demonstrates how to use the %SystemInfo class.
 *
 *
 * @code
 * #include <FBase.h>
 * #include <FSystem.h>
 *
 * using namespace Osp::Base;
 * using namespace Osp::System;
 *
 * result
 * MyClass::GetSystemInfomation(void)
 * {
 *	 result r = E_SUCCESS;
 *
 *	 String key(L"PlatformVersion");
 *	 String platformVersion;
 *
 *	 r = SystemInfo::GetValue(key, platformVersion);
 *	 TryCatch(r == E_SUCCESS, , "MySystemInfo: To get a value is failed");
 *
 *	 return E_SUCCESS;
 *
 *	CATCH:
 *	 return r;
 * }
 * @endcode
 *
 */
class _EXPORT_SYSTEM_ SystemInfo :
	public Osp::Base::Object
{
private:
	/**
	 * This is the default constructor for this class.
	 */
	SystemInfo(void);

	/**
	 * This is the destructor for this class.
	 */
	virtual ~SystemInfo(void);

public:
	/**
	 * Gets the specific String type system information based on the specified designators (key).
	 *
	 * @since     1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/sysinfo.htm">key name</a> of the system information @n
	 *										The following key values are updated: @n
	 *										- @b Since: @b 2.0 @xmlonly <pcheck kind="value" since="2.0"> @endxmlonly WACVersion @xmlonly </pcheck> @endxmlonly. @n
	 *										- @b Deprecated @xmlonly <pcheck kind="value" since="1.0" deprecated="yes"> @endxmlonly PhoneNumber, <a href="../com.osp.cppappprogramming.help/html/tutorials/app_tutorial/launching_samsungapps_application.htm">SamsungAppsAppId</a> @xmlonly </pcheck> @endxmlonly.
	 * @param[out]	value		The system information of type String
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks 	If the output value corresponding to the specified key does not exist (based on the device model), the output value is set to an empty string. @n
	              The PhoneNumber key is deprecated. Use Osp::Telephony::SimInfo::GetPhoneNumber() instead. 
     */
	static result GetValue(const Osp::Base::String& key,	Osp::Base::String& value) ;

	/**
	 * Gets the specific integer type system information based on the specified designators (key).
	 *
	 * @since     1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/sysinfo.htm">key name</a> of the system information @n
	 *										The following key values are updated: @n
	 *										- @b Since: @b 2.0 @xmlonly <pcheck kind="value" since="2.0"> @endxmlonly MaxSystemSoundVolume, MaxMediaSoundVolume, MaxRingtoneSoundVolume, MaxNotificationSoundVolume, MultiPointTouchCount @xmlonly </pcheck> @endxmlonly. @n
	 *										- @b Deprecated @xmlonly <pcheck kind="value" since="1.0" deprecated="yes"> @endxmlonly RSSI @xmlonly </pcheck> @endxmlonly.
	 * @param[out]	value		The integer type system information
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
 	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks The RSSI key is deprecated. Use Osp::Telephony::NetworkInfo::GetRssi() instead. 
     */
	static result GetValue(const Osp::Base::String& key, int& value) ;

	/**
	 * Gets the specific double type system information based on the specified designators (key).
	 *
	 * @since     1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/sysinfo.htm">key name</a> of the system information
	 * @param[out]	value		The @c double type system information
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_SYSTEM	A system error has occurred.
     */
	static result GetValue(const Osp::Base::String& key, double& value) ;

  /**
	 * Gets the specific UuId type system information based on the specified designators (key).
	 *
	 * @since     1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/sysinfo.htm">key name</a> of the system information
	 * @param[out]	value		The UuId type system information
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
  	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_SYSTEM	A system error has occurred.
     */
	static result GetValue(const Osp::Base::String& key, Osp::Base::UuId& value) ;

	/**
	 * Gets the specific system information based on the specified key and data type of the information.
	 *
	 * @since     1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		A system information list
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/sysinfo.htm">key name</a> of the system information @n
	 *										The following key values are updated @n
	 *										- @b Deprecated @xmlonly <pcheck kind="value" since="1.0" deprecated="yes"> @endxmlonly VideoRecordingCodecs @xmlonly </pcheck> @endxmlonly.
	 * @param[in]	type		The data type of the information
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
  	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks The VideoRecordingCodecs key is deprecated. Use Osp::Media::VideoRecorder::GetSupportedVideoCodecListN() instead. 
     */
	static Osp::Base::Collection::IList* GetValuesN(const Osp::Base::String& key, const SystemInfoValueType type) ;

  /**
	 * Gets the specific boolean type system information based on the specified designators (key).
	 *
	 * @since	    1.1
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/sysinfo.htm">key name</a> of the system information @n
	 *										The following key values are updated: @n
	 *										- @b Since: @b 1.1 @xmlonly <pcheck kind="value" since="1.1"> @endxmlonly FmRadioSupported, TvOutSupported @xmlonly </pcheck> @endxmlonly. @n
	 *										- @b Since: @b 2.0 @xmlonly <pcheck kind="value" since="2.0"> @endxmlonly NFCSupported, WiFiDirectSupported @xmlonly </pcheck> @endxmlonly. @n
	 *										- @b Deprecated @xmlonly <pcheck kind="value" since="1.0" deprecated="yes"> @endxmlonly WPSSupported @xmlonly </pcheck> @endxmlonly.
	 * @param[out]	value		The @c bool type system information
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks The WPSSupported key is deprecated. Use Osp::Locations::LocationProvider::IsLocationMethodSupported() instead.  
     */
	static result GetValue(const Osp::Base::String& key, bool& value) ;
		
	/**
	 * @if PRIVCORE 
	 * Gets the International Mobile Equipment Identity (IMEI) of the device.
	 *
	 * @since        2.0
	 * @privlevel    CORE
	 * @privgroup    USER_IDENTITY
	 * @return          An error code
	 * @param[out]      imei                  The IMEI of the device
	 * @exception  E_SUCCESS                  The method is successful.
	 * @exception 	E_PRIVILEGE_DENIED         The application does not have the privilege to call this method.
	 * @exception  E_SYSTEM                   A system error has occurred.
	 * @endif
	 */

	static result GetImei(Osp::Base::String& imei);


private:
	friend class SystemInfoEx;
	class SystemInfoEx* __pSystemInfoEx;
};



};	};
#endif
