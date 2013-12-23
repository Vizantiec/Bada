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
 * @file		FSysSettingInfo.h
 * @brief		This is the header file for the %SettingInfo class.
 *
 * This header file contains the declarations of the %SettingInfo class.
 */

#ifndef _FSYS_SETTING_INFO_H_
#define _FSYS_SETTING_INFO_H_

// includes
#include "FBaseString.h"
#include "FBaseUuId.h"
#include "FSysConfig.h"
#include "FBaseColIList.h"
#include "FSysISettingEventListener.h"
namespace Osp { namespace System {

/**
 * @if PRIVCORE 
 * @enum StorageType
 * Defines the storage types.
 
 * @since		2.0 
 */
 enum StorageType{
 	STORAGE_TYPE_INTERNAL, /**<  @if PRIVCORE  internal storage @endif */
 	STORAGE_TYPE_EXTERNAL /**< @if PRIVCORE external storage @endif */
 };
/*
 * @endif
 */

/**
 * @class		SettingInfo
 * @brief		This class provides methods for getting setting information.
 * @since		1.0
 *
 * The %SettingInfo class provides information about the current system. To get this information, you must provide the <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/settings_info.htm">SettingInfo key</a>. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/settings_info.htm">Settings Information</a>.
 *
 * The following example demonstrates how to use the %SettingInfo class.

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
 * MyClass::GetSettingInfomation(void)
 * {
 *	 result r = E_SUCCESS;
 *
 *	 String key(L"GPSEnabled");
 *	 bool gpsEnabled = false;
 *
 *	 r = SettingInfo::GetValue(key, gpsEnabled);
 *	 TryCatch(r == E_SUCCESS, , "MySettingInfo: To get a value is failed");
 *
 *	 return E_SUCCESS;
 *
 *	CATCH:
 *	 return r;
 * }
 * @endcode
 *
 */
class _EXPORT_SYSTEM_ SettingInfo :
	public Osp::Base::Object
{
private:
	/**
	 * This is the default constructor for this class.
	 */
	SettingInfo(void);

	/**
	 * This is the destructor for this class.
	 */
	virtual ~SettingInfo(void);

public:
	/**
	 * Gets the specific String type setting information based on the specified
	 * designators (key).
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/settings_info.htm">key name</a> of the setting information @n
	 *							The following key values are updated: @n
	 *							- @b Since: @b 2.0 @xmlonly <pcheck kind="value" since="2.0"> @endxmlonly FontType, FontSize, Theme @if PRIVCORE , UsbMode @endif @xmlonly </pcheck> @endxmlonly @if PRIVCORE(Indicates the name of the current USB connection mode.)@endif
	 * @param[out]	value		The setting information of type String
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_SYSTEM	A system error has occurred.
     */
	static result GetValue(const Osp::Base::String& key,	Osp::Base::String& value) ;

	/**
	 * Gets the specific integer type setting information based on the specified
	 * designators (keys).
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/settings_info.htm">key name</a> of the setting information
	 * @param[out]	value		The setting information of type integer
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
 	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_SYSTEM	A system error has occurred.
     */
	static result GetValue(const Osp::Base::String& key, int& value) ;

	/**
	 * Gets the specific long long type setting information based on the specified
	 * designators (key).
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/settings_info.htm">key name</a> of the setting information
	 * @param[out]	value		The setting information of type long long
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
 	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_SYSTEM	A system error has occurred.
     */
	static result GetValue(const Osp::Base::String& key, long long& value) ;


	/**
	 * Gets the specific double type setting information based on the specified
	 * designators (key).
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/settings_info.htm">key name</a> of the setting information
	 * @param[out]	value		The setting information of type double
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
  	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_SYSTEM	A system error has occurred.
     */
	static result GetValue(const Osp::Base::String& key, double& value) ;

	/**
	 * Gets the specific bool type setting information based on the specified
	 * designators (key).
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/settings_info.htm">key name</a> of the setting information @n
	 *							The following key value is updated: @n
	 *							- @b Since: @b 1.1 @xmlonly <pcheck kind="value" since="1.1"> @endxmlonly FlightModeEnabled @xmlonly </pcheck> @endxmlonly.
	 * @param[out]	value		The setting information of type bool
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_SYSTEM	A system error has occurred.
     */
	static result GetValue(const Osp::Base::String& key, bool& value) ;

	/**
	 * Gets the specific UuId type setting information based on the specified
	 * designators (key).
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/settings_info.htm">key name</a> of the setting information
	 * @param[out]	value		The setting information of type UuId
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
   * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_SYSTEM	A system error has occurred.
     */
	static result GetValue(const Osp::Base::String& key, Osp::Base::UuId& value) ;

	/**
	 * @if PRIVCORE 
	 * Sets the system wallpaper.
	 *
	 * @since			2.0
	 * @privlevel CORE
	 * @privgroup SYSTEM_SETTING
	 * 
	 * @return        An error code
	 * @param[in]     filePath             The file path of the wallpaper
	 * @exception     E_SUCCESS                The method is successful.
	 * @exception			E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception     E_FILE_NOT_FOUND   The entry for the specified wallpaper file or the file path cannot be found.
	 * @exception     E_SYSTEM A system error has occurred.
	 * @remarks      	The specified wallpaper file is copied to the managed folder by the system, while the previously set wallpaper is removed. <br> This parameter is compatible with "Wallpaper".           
	 * @endif
	 */

	static result SetWallpaper(const Osp::Base::String& filePath); 

	/**
	 * @if PRIVCORE 
	 * Sets the system ringtone.
	 *
	 * @since			2.0
	 * @privlevel CORE
	 * @privgroup SYSTEM_SETTING
	 * 
	 * @return                 An error code
	 * @param[in]     filePath             The file path of the ringtone
	 * @exception     E_SUCCESS                  The method is successful.
	 * @exception     E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception     E_FILE_NOT_FOUND   The entry for the specified ringtone file or the file path cannot be found.
	 * @exception     E_SYSTEM A system error has occurred.
	 * @remarks     	The specified ringtone file has to exist in the media directory.
	 * @endif
	 */
	static result SetRingtone(const Osp::Base::String& filePath);
		
	/**
	 * @if PRIVCORE 
	 * Sets the sound volume level.
	 *
	 * @since			2.0
	 * @privlevel CORE
	 * @privgroup SYSTEM_SETTING
	 * 
	 * @return        An error code
	 * @param[in]     soundCategory        	    The sound volume category
	 * @param[in]     level	 					The sound volume level of the designated category
	 * @exception     E_SUCCESS                 The method is successful.
	 * @exception     E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception			E_INVALID_ARG    			The specified @c soundCategory is invalid.
	 * @exception     E_OUT_OF_RANGE   			The specified @c level is outside the bounds of @c soundCategory.
	 * @exception     E_SYSTEM 							A system error has occurred.
	 * @endif
	 */
	static result SetVolume(const Osp::Base::String& soundCategory, int level);

		

	/**
	 * @if PRIVCORE 
	 * Sets the location of the application
	 *
	 * @since			2.0
	 * @privlevel CORE
	 * @privgroup INSTALLATION
	 * 
	 * @return                  An error code
	 * @param[in]    type      The storage type
	 * @exception    E_SUCCESS                   The method is successful.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception     E_INVALID_ARG    The specified @c type is invalid.
	 * @exception    E_SYSTEM         A system error has occurred.
	 * @endif
	 */
		static result SetAppInstallLocation(StorageType type);


		
	/**
	 * Sets the setting event listener.
	 *
	 * @since			2.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in] pListener The setting event listener
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks		If the value of the listener object (pListener) is @c null, the setting event listener is not called.
	 * @see				ISettingEventListener
	 *
	 */
	 static result SetSettingEventListener(const ISettingEventListener* pListener);
private:
	friend class SettingInfoEx;
	class SettingInfoEx* __pSettingInfoEx;
};

};	};
#endif
