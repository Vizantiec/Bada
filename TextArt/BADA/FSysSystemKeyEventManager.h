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
 * @file		FSysSystemKeyEventManager.h 
 * @brief		This is the header file for the %SystemKeyEventManager class.
 *
 * This header file contains the declarations of the %SystemKeyEventManager class.
 *
 */

 
#ifndef _FSYS_SYSTEMKEY_EVENT_MANAGER_H_
#define _FSYS_SYSTEMKEY_EVENT_MANAGER_H_

#include "FSysConfig.h"
#include "FBaseObject.h"

namespace Osp { namespace System {

class ISystemKeyEventListener;

/**
 * @internal
 * @enum SystemKeyCode
 * Defines the type of supported system key types.
 * 
 * @since 1.0
 */
typedef enum {
	SYSKEY_SIDE_UP,	  	/**< @internal Side Up Key */
	SYSKEY_SIDE_DOWN,	/**< @internal Side Down Key */
}SystemKeyCode;

/**
 * @internal
 * @class		SystemKeyEventManager
 * @brief		This class provides methods for receiving system key event.
 * @since		1.0
 *
 * @see ISystemKeyEventListener
 */
class _EXPORT_SYSTEM_ SystemKeyEventManager :
	public Osp::Base::Object
{
private:
	/**
	 * This is the default constructor for this class.
	 */
	 SystemKeyEventManager(void);

	 /**
	  * This is the destructor for this class.
	  */
	  virtual ~SystemKeyEventManager(void);

public:
	
	/**
	 * Sets the system key event listener
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *	 
	 * @param[in]	pListener The system key event listener	
	 * @param[in]	foregroundOnly Set to @c true to receive system key event only in foreground, @n
	 *                             else @c false to receive system key event both in foreground and background.
	 *
	 * @return	An error code
	 * @exception	E_SUCCESS	The method is successful.	 
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @exception 	E_UNSUPPORTED_OPERATION   Unsupported mode.
 	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.	 
	 *
	 * @remarks 	If foregroundOnly is true, E_UNSUPPORTED_OPERATION is returned on 1.0
     	*/
	static result SetSystemKeyEventListener(ISystemKeyEventListener* pListener, bool foregroundOnly = true);

private:	
	friend class SystemKeyEventManagerEx;
	class SystemKeyEventManagerEx* __pSystemKeyEventManagerEx;
};
};	};
#endif 

