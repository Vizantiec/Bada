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
* @file		FLocIAreaListener.h 
* @brief	This is the header file for the %IAreaListener interface.
*
* This header file contains the declarations of the IAreaListener interface. @n 
* The interface represents a listener to the events associated with crossing the boundary of the given geographical area.
*
*/

#ifndef _FLOC_IAREA_LISTENER_H_
#define _FLOC_IAREA_LISTENER_H_

#include "FLocationConfig.h"

namespace Osp { namespace Locations { 

class GeographicArea;

/**
* @interface	IAreaListener
* @brief		This interface provides a listener to the events associated with crossing the boundary of the given geographical area. 
* @deprecated	This interface is deprecated.
* @since 		1.0
*
* The %IAreaListener interface provides a listener to the events associated with crossing the boundary of the given geographical area. It is called only when the device crosses the boundary of the registered geographical area. The listener is also used to notify the 
* application about the changes in the monitoring state. The registration is canceled when the listener is called. If the application wants to be 
* notified again, it must re-register the area. Applications must implement this interface and register it with the 
* LocationProvider::AddAreaListener method.
* 
*  
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/location_provider.htm">Location Provider</a>.
*/
class _EXPORT_LOCATION_ IAreaListener 
{
// Lifecycle
public:
    /**
     * This is the destructor for this class.
     *
	 * @deprecated	This method is deprecated.
     * @since	1.0
     */
	virtual ~IAreaListener(void) {}


// Operations
public:
	/**
	* Called to notify that the state of the area monitoring has changed. @n
	* When the location provider state changes to LOC_PROVIDER_TEMPORARILY_UNAVAILABLE or LOC_PROVIDER_OUT_OF_SERVICE,
	* it sends a notification with @c isMonitoringActive set to @c false. @n 
	* When the location provider's state changes to LOC_PROVIDER_AVAILABLE, this notification is sent with @c isMonitoringActive set to @c true.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in] 	isMonitoringActive		Set to @c true to make the area monitoring active,  @n
	*								 		else @c false
	*/
	virtual void OnMonitoringStateChanged(bool isMonitoringActive) = 0;
	/**
	* Called to notify when the device has crossed the boundary of the registered geographical area.
	* 
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	area			The geographical area whose boundary is crossed
	* @param[in]	location		The current location of the device
	*
	*/
	virtual void OnBoundaryCrossed(const GeographicArea& area, Location& location) = 0;

};		// class IAreaListener

};};	// Osp::Locations


#endif // _FLOC_IAREA_LISTENER_H_
