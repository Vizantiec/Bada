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
* @file		FLocILocationListener.h 
* @brief	This is the header file for the %LocationListener interface.
*
* This header file contains the declarations of the %LocationListener interface. @n 
* The class represents a listener that receives the events associated with a particular LocationProvider.
*
*/

#ifndef _FLOC_ILOCATION_LISTENER_H_
#define _FLOC_ILOCATION_LISTENER_H_

#include "FLocationConfig.h"
#include "FLocLocationProvider.h"

namespace Osp { namespace Locations {

class Location;

/**
* @interface	ILocationListener
* @brief		This interface provides a listener that receives events associated with a particular LocationProvider.
* @deprecated	This interface is deprecated.
* @since 		1.0
*
* The %ILocationListener interface provides a listener that receives events associated with a particular LocationProvider.
* Applications implement this interface and register it with a %LocationProvider to obtain regular position updates.
* When the listener is registered with a %LocationProvider with a given update period, the system attempts to provide the updates at the defined 
* intervals. If it is not possible to determine the location, the system sends an update to the listener that contains an 'invalid' Location 
* instance. The system makes the best effort to post the location updates at the specified interval, but this timing is not guaranteed to be 
* exact. The application is responsible for any possible synchronization needed in the listener methods.
* The listener method must return quickly and should not perform any extensive processing. The method calls are intended as triggers to the 
* application. The applications should perform any necessary extensive processing in a separate thread and only use these methods to initiate 
* the processing.
*
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/location_provider.htm">Location Provider</a>.
*/
class _EXPORT_LOCATION_ ILocationListener 
{
// Lifecycle
public:
    /**
     * This is the destructor for this class.
     *
	 * @deprecated	This method is deprecated.
     * @since   1.0
     */
	virtual ~ILocationListener(void)  {}


// Operations
public:
	/**
	 * Called periodically based on the interval defined when registering the listener to provide updates of the current location. @n
	 * This is called by the %LocationProvider to which the listener is registered.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @param[in] 	location		The received %Location
	 * @param[in] location		The received %Location
	 */
	virtual void	OnLocationUpdated(Location& location) = 0;

	/**
	 * Called to notify if the state of the %LocationProvider has changed, by the %LocationProvider to which the listener is registered.
	 *
	 * These location provider state changes are delivered to the application as soon as possible after the state has changed. The timing of these events
	 * is not related to the period of the location updates.
	 *
	 * If the application subscribes to receive periodic location updates, it continues to receive these regardless of the state of the %LocationProvider. If 
	 * the application wishes to stop receiving the location updates for an unavailable provider, it should unregister itself from the provider.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @param[in]	newState	The new state of the %LocationProvider @n
	 *							This value is one of the constants representing the LocProviderState.
	 */
	virtual void	OnProviderStateChanged(LocProviderState newState) = 0;


};		// class ILocationListener

};};	// Osp::Locations


#endif // _FLOC_ILOCATION_LISTENER_H_
