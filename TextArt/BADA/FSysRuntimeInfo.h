/* $Change: 1200083 $ */
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
 * @file		FSysRuntimeInfo.h
 * @brief		This is the header file for the %RuntimeInfo class.
 *
 * This header file contains the declarations of the %RuntimeInfo class.
 */

#ifndef _FSYS_RUNTIME_INFO_H_
#define _FSYS_RUNTIME_INFO_H_

// includes
#include "FBaseString.h"
#include "FBaseUuId.h"
#include "FSysConfig.h"
#include "FBaseColIList.h"

namespace Osp { namespace System {

/**
 * @class		RuntimeInfo
 * @brief		This class provides methods for getting runtime information.
 * @since	  1.0
 *
 * The %RuntimeInfo class provides runtime information, such as the allocated memory used by the application. To get the information, you must provide the <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/runtime_info.htm">RuntimeInfo key</a>. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/runtime_info.htm">Runtime Information</a>.
 *
 * The following example demonstrates how to use the %RuntimeInfo class.
 * @code
 * #include <FBase.h>
 * #include <FSystem.h>
 *
 * using namespace Osp::Base;
 * using namespace Osp::System;
 *
 * result
 * MyClass::GetBatteryLevel(void)
 * {
 *
 *	 result r = E_SUCCESS;
 *
 *	 String key(L"BatteryLevel");
 *	 int batteryLevel = 0;
 *
 *	 r = RuntimeInfo::GetValue(key, batteryLevel);
 *	 TryCatch(r == E_SUCCESS, , "MyRuntimeInfo: Failed to get value");
 *
 *	 return E_SUCCESS;
 *
 *	CATCH:
 *	 return r;
 * }
 * @endcode
 *
 * 
 */

class _EXPORT_SYSTEM_ RuntimeInfo :
	public Osp::Base::Object
{
private:
	/**
	 * This is the default constructor for this class.
	 */
	RuntimeInfo(void);

	/**
	 * This is the destructor for this class.
	 */
	virtual ~RuntimeInfo(void);

public:
	/**
	 * Gets the specific String type runtime information based on the specified
	 * designators (key).
	 *
	 * @since	    1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/runtime_info.htm">key name</a> of the runtime information
	 * @param[out]	value		The runtime information of type String
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM    A system error has occurred.
   */
	static result GetValue(const Osp::Base::String& key, Osp::Base::String& value);

	/**
	 * Gets the specific integer type runtime information based on the specified
	 * designators (key).
	 *
	 * @since	    1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/runtime_info.htm">key name</a> of the runtime information
	 * @param[out]	value		The integer type runtime information
	 * @exception	E_SUCCESS		The method is successful.
 	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM    A system error has occurred.
   */
	static result GetValue(const Osp::Base::String& key, int& value);

	/**
	 * Gets the specific long long type runtime information based on the specified
	 * designators (key).
	 *
	 * @since	    1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/runtime_info.htm">key name</a> of the runtime information @n
	 *										The following key values are updated: @n
	 *										- @b Since: @b 1.2 @xmlonly <pcheck kind="value" since="1.2"> @endxmlonly AvailableMediaStorage @xmlonly </pcheck> @endxmlonly. @n
	 *										- @b Deprecated @xmlonly <pcheck kind="value" since="1.0" deprecated="yes"> @endxmlonly MaxAllocatableMemory, AvailableVideoMemory @xmlonly </pcheck> @endxmlonly.
	 * @param[out]	value		The @c long @c long type runtime information
	 * @exception	E_SUCCESS		The method is successful.
 	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM    A system error has occurred.
   */
	static result GetValue(const Osp::Base::String& key, long long& value);

	/**
	 * Gets the specific double type runtime information based on the specified
	 * designators (key).
	 *
	 * @since	    1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/runtime_info.htm">key name</a> of the runtime information
	 * @param[out]	value		The @c double type runtime information
	 * @exception	E_SUCCESS		The method is successful.
   * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM    A system error has occurred.
   */
	static result GetValue(const Osp::Base::String& key, double& value) ;

	/**
	 * Gets the specific bool type runtime information based on the specified
	 * designators (key).
	 *
	 * @since	    1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/runtime_info.htm">key name</a> of the runtime information
	 * @param[out]	value		The @c bool type runtime information
	 * @exception	E_SUCCESS		The method is successful.
   * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM    A system error has occurred.
   */
	static result GetValue(const Osp::Base::String& key, bool& value) ;

	/**
	 * Gets the specific UuId type runtime information based on the specified
	 * designators (key).
	 *
	 * @since	    1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	key			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/runtime_info.htm">key name</a> of the runtime information
	 * @param[out]	value		The UuId type runtime information
	 * @exception	E_SUCCESS		The method is successful.
   * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM    A system error has occurred.
   */
	static result GetValue(const Osp::Base::String& key, Osp::Base::UuId& value) ;

private:
	friend class RuntimeInfoEx;
	class RuntimeInfoEx* __pRuntimeInfoEx;

};

};	};
#endif
