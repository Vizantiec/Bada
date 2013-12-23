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
 * @file	FLocIMapServiceListener.h
 * @brief	This is the header file for the %IMapServiceListener interface.
 *
 * This header file contains the declarations of the %IMapServiceListener interface.
 *
 */

#ifndef _FLOC_IMAP_SERVICE_LISTENER_H_
#define _FLOC_IMAP_SERVICE_LISTENER_H_

#include "FLocationConfig.h"

namespace Osp { namespace Locations { namespace Services {

class IMaps;
class IMapServiceProvider;

/**
  *
 * @interface	IMapServiceListener
 * @brief		This interface provides a callback mechanism for the map service providers, to send information about the service request to the applications.
 * @deprecated	This interface is deprecated because the Osp::Locations::Controls::Map class provides the same functionalities in a more effective way.
 *				Instead of using this interface, use the Osp::Locations::Controls::Map class.
 *
 * @deprecated	This interface is deprecated.
 * @since 1.0
 *
 * @remarks		The applications implement this interface and register it in the service request in IMapServiceProvider to obtain information from the 
 *				service provider. The relationship with the %IMapServiceProvider methods is described in the %IMapServiceProvider interface.
 *
 * The %IMapServiceListener interface provides a callback mechanism for the map service providers to send information about the service request to the applications.
 *
 */
class _EXPORT_LOCATION_ IMapServiceListener
{
// Lifecycle
public:
	/**
	 * This is the destructor for this interface.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual ~IMapServiceListener(void);

// Operation
public:
	/** 
	 * Called by the map service when the map request has been aborted by @ref IMaps::Abort().
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @param[in]	map		The map for which the request has been aborted
	 */
	virtual void OnMapRequestAborted(IMaps& map) = 0;

	/** 
	 * Called by the map service when an error occurs in the service provider and the error prevents the completion of the service request. @n
	 * The error could be a loss of network connection or location fix. If this notification is sent after the service provider has already started to execute 
	 * the request, the E_LOCATION_SERVICE exception is thrown before the execution of the service request starts.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @param[in]	map					The map in which the error occurred
	 * @param[in]	r					The operation result
	 * @param[in]	errorCode			The error code from the server
	 * @param[in]	errorMsg			The error message from the server
	 * @exception	E_LOCATION_SERVICE	An error at the service provider prevented it from servicing the request.
	 * @exception	E_SERVER 			An error has occurred on the server side.
	 * @remarks     An error may occur when a higher priority task such as an incoming call or message interrupts the map service.
	 */
	virtual void OnMapRequestErrorOccurred(IMaps& map,
		result r, const Osp::Base::String& errorCode,	const Osp::Base::String& errorMsg) = 0;

	/**
	 * Called when the base map data changes.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @param[in]	map			The updated IMaps instance @n
	 *							This is the same instance that is already retrieved by the IMapServiceProvider::GetMapN() method.
	 * @remarks					An application should refresh its screen after this callback method is called, and call the IMaps::RenderMap() method again 
	 *							to get a more complete map image rendered. @n
	 *							This method is called only to notify that the map content has changed. The application does not need to do a screen 
	 *							coordinate refresh to any of the items it is rendering itself.
	 */    
	virtual void OnMapContentUpdated(IMaps& map) = 0;

};	// class IMapServiceListener

}; }; };	// Osp::Locations::Services

#endif // _FLOC_IMAP_SERVICE_LISTENER_H_
