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
 * @file			FAppAppRegistry.h 
 * @brief			This is the header file for the %AppRegistry class.
 * 
 * This header file contains the declarations of the %AppRegistry class.
 */

#ifndef _FAPP_APP_REGISTRY_H_
#define _FAPP_APP_REGISTRY_H_


#include "FBaseObject.h"
#include "FAppConfig.h"
#include "FAppTypes.h"


namespace Osp { namespace Io { class Registry; }; };


namespace Osp { namespace App {


/**
 * @class		AppRegistry
 * @brief		This class manages an application's preferences.
 * @since		1.0
 *
 * The %AppRegistry class lets an application to save or restore its preferences.
 * An instance of this class can be obtained through the Application class. 
 * Also, since an application's state is generally restored in the Application::OnAppInitializing() method and saved in the Application::OnAppTerminating() method, an instance of this class is passed as an argument when these methods are invoked.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/app_namespace.htm">App Guide</a>.
 *
 * The following example demonstrates how to use the %AppRegistry class.
 *
 * @code
 *
 *	void
 *	MyAppClass::AppRegistryCallSample(void)
 *	{
 *		AppRegistry* pAppRegistry = GetAppRegistry();
 *		String countKey("BasicAppRunCount");
 *		String nameKey("BasicAppUserName");
 *		String temperatureKey("BasicAppTemperature");
 *		String name("BasicApp");
 *		double temperature = 32.5;
 *		result r = E_SUCCESS;
 *		int	count = 0;
 *
 *		r = pAppRegistry->Get(nameKey, name);
 *		if ( r == E_KEY_NOT_FOUND)
 *		{
 *			pAppRegistry->Add(nameKey, name);
 *		}
 *
 *		r = pAppRegistry->Get(countKey, count);
 *		if ( r == E_KEY_NOT_FOUND)
 *		{
 *			pAppRegistry->Add(countKey, count);
 *		}
 *
 *		r = pAppRegistry->Get(temperatureKey, temperature);
 *		if ( r == E_KEY_NOT_FOUND)
 *		{
 *			pAppRegistry->Add(temperatureKey, temperature);
 *		}
 *
 *		r = pAppRegistry->Save();
 *		if( IsFailed(r))
 *		{
 *			//Failed to save data to registry
 *		}
 *
 *		//Displays the retrieved data
 *
 *		AppLog("AppRegistry Name value [%ls]", name.GetPointer());
 *		AppLog("AppRegistry count [%d]", count);
 *		AppLog("AppRegistry temperature value [%f]", temperature);
 *
 *
 *		//Updates the state of the application variables
 *
 *		count++;
 *		name.Append(count);
 *		temperature++;
 *
 *		//Saves the app registry
 *		r = pAppRegistry->Set(nameKey, name);
 *		if ( IsFailed(r))
 *		{
 *			//Error condition
 *		}
 *
 *		r = pAppRegistry->Set(countKey, count);
 *		if ( IsFailed(r))
 *		{
 *			//Error condition
 *		}
 *
 *		r = pAppRegistry->Set(temperatureKey, temperature);
 *		if ( IsFailed(r))
 *		{
 *			//Error condition
 *		}
 *
 *		r = pAppRegistry->Save();
 *		if( IsFailed(r))
 *		{
 *			//Failed to save data to registry
 *		}
 *
 *
 *		//Retrieves the saved content
 *
 *		pAppRegistry->Get(nameKey, name);
 *
 *		pAppRegistry->Get(countKey, count);
 *
 *		pAppRegistry->Get(temperatureKey, temperature);
 *
 *		AppLog("AppRegistry Name value [%ls]", name.GetPointer());
 *		AppLog("AppRegistry count [%d]", count);
 *		AppLog("AppRegistry temperature value [%f]", temperature);
 *
 *
 *		return;
 *	}
 * @endcode
 *
 **/
class _EXPORT_APP_ AppRegistry :
	public Osp::Base::Object
{
// Lifecycle
private:
	/*
	 * This is the default constructor for this class.
	 */
	AppRegistry(void);


	/*
	 * This is the copy constructor for the %AppRegistry class.
	 */
	AppRegistry(const AppRegistry& source);


	/*
	 * Allocates memory for an AppRegistry object.
	 *
	 * @return	An error code
	 * @exception	E_SUCCESS	The method is successful.
	 */
	result Construct(const AppId& appId);


// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	~AppRegistry(void);


// Operator
private:
	/**
	 * This is the assignment operator for this class.
	 */
	AppRegistry& operator=(const AppRegistry& source);


// Operation
public:
	/**
	 * Adds a string value along with the specified key.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @param[in]	key		A key corresponding to the value
	 * @param[in]	value	A string value
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The length of the specified string for a section or entry is smaller than or equal to @c 0, or the specified string is a @c null value or string with '\0' and '\n'.
	 * @exception	E_KEY_ALREADY_EXIST		The key has already been used in the application preferences.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks	In order to save the value in the persistent storage, the AppRegistry::Save() method must be called.
	 */
	result Add(const Osp::Base::String& key, const Osp::Base::String& value);


	/**
	 * Adds an integer value along with the specified key.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @param[in]	key		A key corresponding to the value
	 * @param[in]	value	An integer value
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The length of the specified string for a section or entry is smaller than or equal to @c 0, or the specified string is a @c null value or string with '\0' and '\n'.
	 * @exception	E_KEY_ALREADY_EXIST		The key has already been used in the application preferences.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks	In order to save the value in the persistent storage, the AppRegistry::Save() method must be called.
	 */
	result Add(const Osp::Base::String& key, int value);


	/**
	 * Adds a floating point value along with the specified key.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @param[in]	key		A key corresponding to the value
	 * @param[in]	value	A floating point value
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The length of the specified string for a section or entry is smaller than or equal to @c 0, or the specified string is a @c null value or string with '\0' and '\n'.
	 * @exception	E_KEY_ALREADY_EXIST		The key has already been used in the application preferences.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks	In order to save the value in the persistent storage, the AppRegistry::Save() method must be called.
	 */
	result Add(const Osp::Base::String& key, double value);


	/**
	 * Updates a string value associated with the specified key.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @param[in]	key		A key corresponding to the value
	 * @param[in]	value	A string value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The length of the specified string for a section or entry is smaller than or equal to @c 0, or the specified string is a @c null value or string with '\0' and '\n'.
	 * @exception	E_KEY_NOT_FOUND		The specified key is not used in the application preferences.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks	In order to save the value in the persistent storage, the AppRegistry::Save() method must be called.
	 */
	result Set(const Osp::Base::String& key, const Osp::Base::String& value);


	/**
	 * Updates an integer value associated with the specified key.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @param[in]	key	A key corresponding to the value
	 * @param[in]	value	An integer value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The length of the specified string for a section or entry is smaller than or equal to @c 0, or the specified string is a @c null value or string with '\0' and '\n'.
	 * @exception	E_KEY_NOT_FOUND		The specified key is not used in the application preferences.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks	In order to save the value in the persistent storage, the AppRegistry::Save() method must be called.
	 */
	result Set(const Osp::Base::String& key, int value);


	/**
	 * Updates a floating point value associated with the specified key.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @param[in]	key	A key corresponding to the value
	 * @param[in]	value	A floating point value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The length of the specified string for a section or entry is smaller than or equal to @c 0, or the specified string is a @c null value or string with '\0' and '\n'.
	 * @exception	E_KEY_NOT_FOUND		The specified key is not used in the application preferences.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks	In order to save the value in the persistent storage, the AppRegistry::Save() method must be called.
	 */
	result Set(const Osp::Base::String& key, double value);


	/**
	 * Saves the values temporarily in the persistent storage. @n
	 * This method is invoked internally when the instance of this class is deleted.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */
	result Save(void);


	/**
	 * Removes a preference associated with the specified key.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @param[in]	key		The key of the value to be removed
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_KEY_NOT_FOUND		The specified key is not used in the application preferences.
	 */
	result Remove(const Osp::Base::String& key);


	/**
	 * Gets a string value associated with the specified key.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @param[in]	key		The key of the value to retrieve
	 * @param[out]	value	A string value to be retrieved
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The length of the specified string for a section or entry is smaller than or equal to @c 0, or the specified string is a @c null value or string with '\0' and '\n'.
	 * @exception	E_KEY_NOT_FOUND		The specified key is not used in the application preferences.
	 */
	result Get(const Osp::Base::String& key, Osp::Base::String& value) const;


	/**
	 * Gets an integer value associated with the specified key.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @param[in]	key		The key of the value to retrieve
	 * @param[out]	value	An integer value to be retrieved
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The length of the specified string for a section or entry is smaller than or equal to @c 0, or the specified string is a @c null value or string with '\0' and '\n'.
	 * @exception	E_KEY_NOT_FOUND		The specified key is not used in the application preferences.
	 */
	result Get(const Osp::Base::String& key, int& value) const;


	/**
	 * Gets a floating point value associated with the specified key.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @param[in]	key		The key of the value to retrieve
	 * @param[out]	value	A floating point value to be retrieved
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The length of the specified string for a section or entry is smaller than or equal to @c 0, or the specified string is a @c null value or string with '\0' and '\n'.
	 * @exception	E_KEY_NOT_FOUND		The specified key is not used in the application preferences.
	 */
	result Get(const Osp::Base::String& key, double& value) const;

	/**
	 * Gets the %AppRegistry instance pointer.
	 *
	 * @since  2.0
	 * @return A pointer to the %AppRegistry instance, @n
	 *		  else @c null if it fails
	 */
	static AppRegistry* GetInstance(void);

// Attribute
private:
	Osp::Io::Registry* __pRegistry;
	Osp::Base::String __sectionName;
	friend class __BaseApplication;

private:
	friend class AppRegistryEx;
	class AppRegistryEx* __pAppRegistryEx;
};


}; }; // Osp::App


#endif // _FAPP_APP_REGISTRY_H_
