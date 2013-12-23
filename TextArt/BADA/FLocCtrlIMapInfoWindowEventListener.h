/* $Change: 1267243 $ */
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
* @file		FLocCtrlIMapInfoWindowEventListener.h 
* @brief	This is the header file for the %IMapInfoWindowEventListener interface.
*
* This header file contains the declarations of the %IMapInfoWindowEventListener interface.
*/

#ifndef _FLOC_CTRL_IMAPINFOWINDOW_EVENT_LISTENER_H_
#define _FLOC_CTRL_IMAPINFOWINDOW_EVENT_LISTENER_H_

#include <FUiConfig.h>
#include <FBaseRtIEventListener.h>
#include <FLocCtrlNativeMapInfoWindow.h>

namespace Osp { namespace Locations { namespace Controls { class IMapNativeInfoWindow; }; }; };

namespace Osp { namespace Locations { namespace Controls {

/**
* @internal
* This method is for internal use only. The bada platform team is not responsible for any 
* behavioral correctness, consistency, and security-related issues that might arise after 
* using this method.
*
* @deprecated	This enumerated type is deprecated.
* @since	1.0
*/
enum InfoWindowStatus
{
	INFOWINDOW_CLOSING_END,
	INFOWINDOW_CLICK,
	INFOWINDOW_DOUBLE_PRESS
};

/**
* @interface	IMapInfoWindowEventListener
* @brief		This interface is used as the argument to map the InfoWindow event listener.
* @deprecated	This interface is deprecated.
* @since		1.0
*
* The %IMapInfoWindowEventListener interface provides event notifications about the interaction between an %InfoWindow and an application. Applications must inherit and 
* override the %IMapInfoWindowEventListener interface to interact with an %InfoWindow on the map.
*
* For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/info_windows.htm">Information Windows</a>.
*/
 
class _EXPORT_LOCATION_CONTROL IMapInfoWindowEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:

	/**
	* This is the destructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual ~IMapInfoWindowEventListener(void){}

	/**
	* Called to notify when the close button of the %InfoWindow is clicked.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in] 	source	The source of the event
	*/
	virtual void OnClosingEnded(const Osp::Locations::Controls::IMapInfoWindow& source) = 0;

	/**
	* Called to notify when the %InfoWindow is clicked.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in] 	source	The source of the event
	*/
	virtual void OnInfoWindowClicked(const Osp::Locations::Controls::IMapInfoWindow& source) = 0;

	/**
	* Called to notify when the %InfoWindow is double-clicked.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	source	The source of the event
	* @remarks		The OnInfoWindowDoublePressed() and OnInfoWindowClicked() methods are called when an %InfoWindow is double-clicked.
	*/
	virtual void OnInfoWindowDoublePressed(const Osp::Locations::Controls::IMapInfoWindow& source) = 0;
	
};		// IMapInfoWindowEventListener

};};};// Osp::Locations::Controls;

#endif	// _FLOC_CTRL_IMAPINFOWINDOW_EVENT_LISTENER_H_
