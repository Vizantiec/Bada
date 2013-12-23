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
 * @file	FLocLocationProvider.h 
 * @brief	This is the header file for the %LocationProvider class.
 *
 * This header file contains the declarations of the %LocationProvider class.
 */

#ifndef _FLOC_LOCATION_PROVIDER_H_
#define _FLOC_LOCATION_PROVIDER_H_

#include "FLocationConfig.h"
#include "FBaseObject.h"
#include "FBaseColArrayList.h"
#include "FLocLocation.h"

struct _ILocationProvider;
struct _ILocationListener;
struct _IAreaListener;

namespace Osp { namespace Locations { 

class ILocationListener;
class IAreaListener;
class GeographicArea;

/**
* @enum     LocProviderState 
* Defines the state of the location provider.
*
* @deprecated	This enumerated type is deprecated.
* @since	1.0
*/
typedef enum{
	/** The location provider is available */
	LOC_PROVIDER_AVAILABLE  = 1,

	/** The location provider is out of service @n 
	* The state of being out of service means that the method is unavailable and the implementation does not expect this situation to change in the near 
	* future. @n
	* In case of the GPS location provider, when the GPS receiver is detached from the device, the state is defined as OUT_OF_SERVICE.
	*/
	LOC_PROVIDER_OUT_OF_SERVICE = 3,

	/** The location provider is temporarily unavailable @n 
	* The temporary unavailable status is due to reasons that can change in the future if the provider becomes available. @n 
	* In the case of the GPS location provider, fix data is not obtained when the signal is being obstructed for being out of range. This state of the 
	* location provider is defined as TEMPORARILY_UNAVAILABLE.
	*/
	LOC_PROVIDER_TEMPORARILY_UNAVAILABLE = 2
	
}LocProviderState;

/**
* @class	LocationProvider
* @brief	This class is used by the applications using location information.
* @deprecated	This class is deprecated.
* @since	1.0
*
* 	The %LocationProvider class represents a module that is able to determine the location of the terminal. This can be implemented using any one of 
* the location methods, such as GPS. By using %LocationProvider, the application can get Location instances representing the location of the terminal at the 
* time of the measurement. The application can be periodically updated with new Location instances through the ILocationListener interface.
*
* 
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/location_provider.htm">Location Provider</a>.
*
*/
class _EXPORT_LOCATION_ LocationProvider :
public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	* This is the default constructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
    * @see		Construct()
	*/
	LocationProvider(void);								
	/** 
	* This is the destructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual ~LocationProvider(void);
private:
	// no implementation. force to private
	LocationProvider(const LocationProvider& value);
	LocationProvider& operator=(const LocationProvider& rhs);
	
// Operation
public:
	/**
	* Initializes this instance of %LocationProvider with the specified location method. @n
	* Gets an actual location using the specified location method. @n
	* The location methods are defined in the %Location class.
    *
    * @compatibility	This class has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
    *					For more information, see @ref CompLocationProviderPage "here".
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return 		An error code
	* @param[in] 	locationMethod		The desired location method
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_LOCATION			The %LocationProvider is currently out of service or the platform does not have the resources to construct the 	
	*									%LocationProvider.
	* @exception	E_INVALID_ARG 		The specified @c locationMethod is invalid.
    * @exception	E_INVALID_STATE 	This instance is in an invalid state.
	* @remarks 		The application must delete the returned %LocationProvider instance.
	* @see 			LocationMethod()
	*/
	result Construct(LocationMethod locationMethod);

    /**
    * @page		CompLocationProviderPage	Compatibility for Construct()
	*
    * @section	CompLocationProviderPageIssueSection Issues
    * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
    * The WPS locating method and the corresponding callback, ILocationListener::OnLocationUpdate(), may not work in case this method is called while the GPS 
	* is turned on and being used.
    *
    * @section        CompLocationProviderPageResolutionSection Resolutions
    * The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. 
    * Instead of WPS location method, use of HYBRID locating is recommended. @n
    */
	
	/**
	* Gets the last known location that is recorded. @n
	*
	* The applications can use this method to obtain the last known location regardless of the location method used. The applications must check the 
	* timestamp and other fields to determine if this is recent enough for the application to use without creating a new request for obtaining the current 
	* location.
	* 
	 * @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility    This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
    *                   For more information, @ref LocationProviderLocationAPIsPage "here".
	* @privlevel		NORMAL
	* @privgroup 		LOCATION
	*
	* @return			The last known location that is recorded, @n
	*					else @c null if there is no record of any previous location information
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method, or @n
	*										The user blocks an application from using the location information.
	* @remarks		Delete the instance of the location provided once it is used.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	static Location* GetLastKnownLocationN(void);

    /**
    * @page		LocationProviderLocationAPIsPage	Compatibility for GetLastKnownLocationN() and AddAreaListener()
	*
    * @section	LocationProviderLocationAPIsPageSectionIssues	Issues
    * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n 
    * -# If the privilege for using the location information is blocked by user consent, the methods do not work as per expectations. 
    * In that case, it still gives E_SUCCESS result and not E_PRIVILEGE_DENIED.
    *
    * @section	LocationProviderLocationAPIsPageSectionResolutions	Resolutions 
    * The issue mentioned above is resolved in bada API version 2.0 as follows. @n
    *  -# If the privilege for using the location information is blocked by user consent, the E_PRIVILEGE_DENIED exception is thrown.
    *
    * @par When working with API versions prior to 2.0:
    * If the application uses the RequestLocationUpdates() method, it can check whether the privilege for using the location is granted using this method. 
	* When E_PRIVILEGE_DENIED is thrown, the application should take proper action to be allowed to access this information.
    */

	/**
	*
	* Gets the last known location recorded using the specified location method.
	*
	* Applications can use this method to obtain the last known location, and check the timestamps and other fields to determine if this is recent enough for 
	* the application to use without creating a new request for obtaining the current location.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility    This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
    *                   For more information, @ref LocationProviderLocationAPIsPage "here".
	* @privlevel		NORMAL
	* @privgroup 		LOCATION
	*
	* @return			The last known location recorded using the specified location method, @n
	*					else @c null if there is no previous record
	* @param[in] 		locationMethod		The location method
	* @exception 		E_SUCCESS			The method is successful.
	* @exception 		E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method, or @n
	*										the user blocks an application from using the location information.
	* @remarks			Delete the instance of the location once it is used.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.
	*/
	static Location* GetLastKnownLocationN(LocationMethod locationMethod);

	/**
	*
	* Adds an AreaListener that sends notifications and updates when the boundary of the specified geographical area is crossed. @n
	* The application registering this listener is responsible for checking whether the current location is inside or outside the predefined area. This 
	* listener is responsible only for monitoring whether the boundary of the specified area has been crossed. @n
	*
	* If this method is called with an %AreaListener that is already registered, the registration to the specified geographical area is 
	* added to the list of geographical areas it has been previously registered for. A single listener can handle events for multiple geographical areas. @n
	*
	* This method checks whether the area boundary is crossed for each time interval. 
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
    *                   For more information, @ref LocationProviderLocationAPIsPage "here".
	* @privlevel		NORMAL
	* @privgroup		LOCATION
	*
	* @return		An error code
	* @param[in] 	listener			The listener to be registered
	* @param[in] 	area				The geographical area whose proximity is registered
	* @param[in] 	interval 			The required boundary check interval in seconds
	* @exception 	E_SUCCESS			The method is successful.
	* @exception 	E_INVALID_ARG		The specified interval is equal to @c 0 or less than @c 0. 
	* @exception 	E_LOCATION 			The platform does not have the resources to add a new listener and the geographical area to be monitored.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception 	E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception 	E_SYSTEM  			A system error has occurred.  
	* @exception 	E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method, or the user blocks an application from using the 
	*									location information.
	* @remarks		LocationProvider::RequestLocationUpdates() should be called before the application calls this method.
	* @see			RemoveAreaListener()
	*
	*/
	result AddAreaListener(const IAreaListener& listener, const GeographicArea& area, int interval);

	/**
	*
	* Removes an AreaListener from the list of recipients for updates. @n
	* If the specified listener is not registered, it returns with no action.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	listener	The event listener to be removed
	* @see 			AddAreaListener()
	*
	*/
	void RemoveAreaListener(const IAreaListener& listener);
	/**
	*
	* Requests periodic location updates by registering a LocationListener. @n
	* The listener is called with the updated location at the defined interval. The listener also gets updates when the availability state of the 
	* LocationProvider changes. @n
	*
	* Only one listener can be registered with each %LocationProvider instance. Setting the listener replaces any previously set listener. @n
	*
	* The initial location is recorded as soon as the listener is registered and provided to the listener. Subsequent location updates happen at the defined 
	* interval after the first one. (The update interval cannot be guaranteed for the WPS/HYBRID location methods.)
    *
	* When the location information updates are not required, it is recommended to stop these updates by using the CancelLocationUpdates() method as it 
	* conserves power. For example, Osp::App::Application::OnBackground() is called when an application moves to the background. To stop the location 
	* updates, use the CancelLocationUpdates() method.
    *
	* For conserving power in background applications that are time-consuming and lengthy, it is recommended that they either call GetLastKnownLocationN() 
    * instead of RequestLocationUpdates() or call CancelLocationUpdates() after acquiring a valid location by using the RequestLocationUpdates() method.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup 	LOCATION
	*
	* @return 		An error code
	* @param[in] 	listener					The listener to be registered
	* @param[in] 	interval					The interval in seconds @n
	* @param[in] 	isSatelliteInfoIncluded		Set to @c true if the updated location should include the satellite information, @n
	*											else @c false	
	* @exception 	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_ARG				The specified interval is less than @c 1.
	* @exception 	E_INVALID_STATE 			This instance has not been constructed as yet.
	* @exception 	E_OUT_OF_MEMORY  			The memory is insufficient.  
	* @exception 	E_SYSTEM  					A system error has occurred.  
	* @exception 	E_PRIVILEGE_DENIED 			The application does not have the privilege to call this method, or the user blocks an application from using 
	*											the location information.
	* @see CancelLocationUpdates()
	*/
	result RequestLocationUpdates(const ILocationListener& listener, int interval, bool isSatelliteInfoIncluded);
	/**
	*
	* Requests distance-based location updates with a given interval by registering a LocationListener. @n
	* The initial location is updated as soon as the listener is registered and provided to the listener. Then the distance between the new location to the 
	* latest valid location is checked periodically with the specified checking interval. The listener is called with the updated location when the distance 
	* exceeds the specified distance threshold. The listener can also be called periodically with the checking interval if the distance threshold is chosen 
	* to be @c 0.0. 
	*
	* The listener also gets updates when the availability state of the location provider changes. @n
	*
	* Only one listener can be registered with each %LocationProvider instance. Setting the listener replaces any previously set listener. @n
	*
	* When the location information updates are not required, it is recommended to stop these updates by using the CancelLocationUpdates() method, 
	* as it conserves power. For example, Osp::App::Application::OnBackground() is called when an application moves to the background.
	* To stop the location updates, use the CancelLocationUpdates() method.
	*
	* For conserving power in background applications that are time-consuming and lengthy, it is recommended that they either call GetLastKnownLocationN() 
	* instead of RequestLocationUpdates() or call CancelLocationUpdates() after acquiring a valid location by using the RequestLocationUpdates() method.
	*
	 * @deprecated	This method is deprecated.
	* @since 		1.2
	* @privlevel 	NORMAL
	* @privgroup 	LOCATION
	*
	* @return    	An error code
	* @param[in] 	listener					The	listener to be registered
	* @param[in] 	checkingInterval    		The interval in seconds
	* @param[in] 	distanceThreshold   		The distance threshold to generate location updates (in meters)
	* @param[in] 	isSatelliteInfoIncluded		Set to @c true if the updated location should include the satellite information, @n
	*											else @c false	
	* @exception 	E_SUCCESS     				The method is successful.
	* @exception 	E_INVALID_ARG 				The specified checking interval is less than @c 1, or the defined distance threshold is less than @c 0.0.
	* @exception 	E_INVALID_STATE				This instance has not been constructed as yet.
	* @exception 	E_OUT_OF_MEMORY				The memory is insufficient.  
	* @exception 	E_SYSTEM  					A system error has occurred.  
	* @exception 	E_PRIVILEGE_DENIED 			The application does not have the privilege to call this method, or the user blocks an application from using 
	*											the location information.
	* @see 			CancelLocationUpdates()
	*/
	result RequestLocationUpdates(const ILocationListener &listener, int checkingInterval, float distanceThreshold, bool isSatelliteInfoIncluded);
	/**
	*
	* Cancels the registration of the %LocationListener that is registered.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @see 		RequestLocationUpdates()
	*/
	void CancelLocationUpdates(void);
	/**
	*
	* Gets the current state of this %LocationProvider.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	LOCATION
	*
	* @return  		The availability state of the %LocationProvider
	* @exception 	E_SUCCESS			The method is successful.
	* @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception 	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @see 			LocProviderState
	* @remarks 		The specific error code can be accessed using the GetLastResult() method.
	*/
	LocProviderState GetState(void) const;

    /**
    * @if PRIVCORE
    * Sends an additional command to the location provider. @n
    *
    * Only the authorized applications are permitted to use this method. @n
    * If the command is unknown, E_SYSTEM is returned. @n
    * 
    * An empty string clears all the commands sent to the location provider.
    *
	 * @deprecated	This method is deprecated.
    * @since        2.0
    * @privlevel    CORE
    * @privgroup    PRIVILEGED_LOCATION
    *
    * @return       An error code
    * @param[in]    locationMethod    	The location method
    * @param[in]    command           	The command handled by the location provider
    * @exception    E_SUCCESS         	The method is successful.
    * @exception    E_INVALID_ARG     	The specified @c locationMethod parameter is invalid.
    * @exception    E_SYSTEM          	A system error has occurred.
    * @exception    E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
    * @endif
    */
    static result SendAdditionalCommand(LocationMethod locationMethod, const Osp::Base::String& command);

    /**
    * Checks whether the given location method is supported.
    *
	 * @deprecated	This method is deprecated.
    * @since    	2.0
    *
    * @return       @c true if the specified location method is supported, @n
    *               else @c false
    * @param[in]    locationMethod  	The location method to be checked
    * @exception    E_SUCCESS       	The method is successful.
    * @exception    E_INVALID_ARG   	The location method is invalid.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
    * @remarks      For bada API versions prior to 2.0, @ref Osp::System::SystemInfo::GetValue() can be used with the key strings, "GPSSupported" and 
	*				"WPSSupported".
    *				For @ref LOC_METHOD_GPS, use "GPSSupported", and for @ref LOC_METHOD_WPS, use "WPSSupported". 
    */
    static bool IsLocationMethodSupported(LocationMethod locationMethod);
	
// Attribute
private:
	_ILocationProvider* __pMILocationProvider;	// matrix class
	void* __pLocationListener;	// location listener
	void* __pAreaListenerImplList;

private:
	friend class LocationProviderEx;
	class LocationProviderEx* __pLocationProviderEx;


};		// class LocationProvider
/*
* @}
*/

};};	// Osp::Locations

#endif // _FLOC_LOCATION_PROVIDER_H_
