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
 * @file			FAppIAppControlEventListener.h 
 * @brief			This is the header file for the %IAppControlEventListener interface.
 *
 * This header file contains the declarations of the %IAppControlEventListener interface.
 */

#ifndef _FAPP_IAPPCONTROL_EVENT_LISTENER_H
#define _FAPP_IAPPCONTROL_EVENT_LISTENER_H

#include "FAppConfig.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Base { class String; }; };
namespace Osp { namespace Base { namespace Collection { class IList; }; }; };

namespace Osp { namespace App {

/**
* @interface	IAppControlEventListener
* @brief		This interface defines a listener for the AppControl result events. 
* @since		1.0
*
* The %IAppControlEventListener interface defines a listener for the AppControl result events.
*/
class _EXPORT_APP_ IAppControlEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:

	/**
	* Called when the application control is completed. @n
	* The client can get callback result for some application controls by implementing this listener. @n
	* OnAppControlCompleted() is called after AppControl::Start() with listener for some application controls.
	*
	* @since			1.0
	*
	* @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
 	*				For more information, see @ref CompOnAppControlCompletedPage "here".
 	*
	* @param[in]	providerId	The provider ID
	* @param[in]	operationId		The operation ID used in application control invocation
	* @param[in]	pResultList		The list of callback strings of application control
	*
	* @remarks	The specified @c pResultList provides the result code for the first array element.
	* @remarks	When the invoked application control is terminated without sending a result,
	* 			then this method is invoked with @c pResultList and it contains Osp::App::APPCONTROL_RESULT_TERMINATED.
	* @remarks	Switching forms using Osp::Ui::Controls::Frame::SetCurrentForm() in this listener disables the upcoming form
	* 			(Application::OnForeground()). If Application::OnForeground() is being used in the application logic, 
	*			it is recommended to avoid switching forms in this listener.
	* @see		Osp::App::AppControl
	*/
	virtual void OnAppControlCompleted(const Osp::Base::String& providerId, const Osp::Base::String& operationId, const Osp::Base::Collection::IList* pResultList) = 0;
	
	/**
	 * @page	CompOnAppControlCompletedPage Compatibility for OnAppControlCompleted()
	 * @section	CompOnAppControlCompletedPageIssue Issues
	 *			Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 *
	 *	-# The caller application does not receive any information if the invoked application control is terminated without sending a result.
	 *
	 * @section          CompOnAppControlCompletedPageResolution Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use API version 2.0 or above. @n
	 *
	 *      -# The @c pResultList parameter contains Osp::App::APPCONTROL_RESULT_TERMINATED in the first array element if the invoked application control is terminated without sending a result.
	 */
};

}; }; // Osp::App

#endif // _FAPP_APPCONTROL_IEVENT_LISTENER_H
