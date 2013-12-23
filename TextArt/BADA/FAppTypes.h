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
 * @file		FAppTypes.h 
 * @brief		This is the header file for the AppState enumerator.
 *
 *	This header file contains the declarations for the %AppState enumerator.
 * @see			Application	
 */
 
#ifndef _FAPP_TYPES_H_
#define _FAPP_TYPES_H_


#include "FBaseString.h"


namespace Osp { namespace App {


typedef Osp::Base::String AppId;


typedef Osp::Base::String AppSecret;


/**
 * @enum	AppState
 * Defines the various states of an application's life cycle.
 *
 * @since		1.0 
 */
enum AppState
{
	INITIALIZING,	/**< The application has been launched */
	RUNNING,		/**< The application has been initialized and is currently being executed */
	TERMINATING,	/**< The application is about to exit and releases its resources and saves its preferences */
	TERMINATED	/**< The application has been destroyed */
};

/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 * @enum	AppAttributeType
 * This shows whether the application is a main application or a sub application.
 *
 * @since		1.0
 */
enum AppAttributeType
{
	AAT_MAIN_APP = 0x01,
	AAT_SUB_APP = 0x02
};

/**
 * @enum	AppUiState
 * Defines the UI state of an application.
 *
 * @since		2.0 
 */
typedef enum
{
	APP_UI_STATE_FOREGROUND = 0x01,				/**< The application is completely visible on foreground */
	APP_UI_STATE_PARTIAL_BACKGROUND = 0x02,		/**< The application is partially hidden by another window such as a system pop-up */
	APP_UI_STATE_BACKGROUND = 0x04				/**< The application is completely hidden by a full-screen window, usually by another application or an application control */
}AppUiState;

/**
 * Application launch request ID @n
 * Represents the application launch arguments in Application::OnUserEventReceivedN().
 *
 * @since 1.1
 * @see 	Application::OnUserEventReceivedN()
 */
const long AppLaunchRequestId	= (-0xFFFF);

/**
 * Defines the launch type - normal launch
 *
 * @since 1.1
 */
static const Osp::Base::String APP_LAUNCH_NORMAL= L"LAUNCH_NORMAL";

/**
 * Defines the launch type - conditional launch
 *
 * @since 1.2
 */
static const Osp::Base::String APP_LAUNCH_CONDITIONAL= L"LAUNCH_CONDITIONAL";

}; }; // Osp::App


#endif // _FAPP_TYPES_H_
