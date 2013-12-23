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
 * @file	FLocRemoteLocationProvider.h
 * @brief	This is the header file for the %RemoteLocationProvider class.
 *
 * This header file contains the declarations of the %RemoteLocationProvider class.
 */

#ifndef _FLOC_REMOTE_LOCATION_PROVIDER_H_
#define _FLOC_REMOTE_LOCATION_PROVIDER_H_

#include "FBaseObject.h"
#include "FBaseColArrayList.h"
#include "FBaseColHashMap.h"
#include "FLocServiceInfo.h"

//Forward decl
struct _IRemoteLocationProvider;
struct __RemoteLocProviderMessageListener;

namespace Osp { namespace Locations {

class IRemoteLocationListener;
class ILocationReportListener;
class ITraceServiceListener;
class CircleGeographicArea;
class RectangleGeographicArea;

/**
* @class	RemoteLocationProvider
* @brief	This class provides remote location services to report the device location to the server, retrieve the locations of other devices from the 
*			server, and the subscribe to trace-service.
* @deprecated   This class is deprecated due to the operation policy of the bada Server.
* @since 	1.0
*
* The %RemoteLocationProvider class provides remote location services to report the device location to the server, retrieve the locations of other 
* devices from the server, and the subscribe to trace-service.
*	
* The following diagram illustrates the relationships between %RemoteLocationProvider and related classes.
* @image html location_locations_using_the_apis_remotelocationproviderclassdiagram.png
*
* 
*/
class _EXPORT_LOCATION_ RemoteLocationProvider :
public Osp::Base::Object
{
// Lifecycle
public:
	/**
	* This is the default constructor for this class.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	*/
	RemoteLocationProvider(void);
	/**
	* This is the destructor for this class.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	*/
	virtual ~RemoteLocationProvider(void);

private:
	// no implementation. force to private
	RemoteLocationProvider(const RemoteLocationProvider& value);
	RemoteLocationProvider& operator=(const RemoteLocationProvider& rhs);

// Operation
public:
	/**
	* Reports the last known location to the bada Server periodically. @n
	*
	* The %Location reporter reports the basic location information and extended location information to the bada Server. The basic location information 
	* includes the latitude, longitude, location method, and time stamp. The extended location information includes the altitude, speed, course, horizontal 
	* accuracy, and vertical accuracy. @n
	*
	* When the reporting fails due to an unstable network or a not updated last known location, it notifies with ILocationReportListener::OnReportingStateChanged() and sets it to @c false. @n
	*
	* The reporting interval is not guaranteed for the WPS/HYBRID location methods. 
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 			1.0
    * @compatibility    This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
    *                   For more information, @ref RemoteLocationProviderLocationAPIsPage "here".
	* @privlevel		NORMAL
	* @privgroup		LOCATION_UPLOAD
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in] 	listener					The listener to register
	* @param[in] 	locationMethod				The location method
	* @param[in] 	isExtendedLocationIncluded	Set to @c true if the extended location data is reported, @n
	*											else @c false
	* @param[in] 	reportingInterval			The interval time in seconds @n
	*                               			The interval is used for reporting the location data to the bada Server.
	*
	* @exception 	E_SUCCESS   			The method is successful.
	* @exception 	E_PRIVILEGE_DENIED 		The application does not have the privilege to call this method, or the user blocks an application from using the 
	*										location information.
	* @exception 	E_INVALID_ARG 			The specified @c reportingInterval is invalid, or @n
	*										the location method is invalid. @n
	*										The @reportingInterval should not be less than @c 1.
	* @exception 	E_SYSTEM  				A system error has occurred.  
	* @exception 	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @remarks		If the application reports the current location to the bada Server, LocationProvider::RequestLocationUpdates() should be called to keep 
	*				the location information up-to-date. @n
	*				After using this method, the application should call StopLocationReport().
	* @remarks   	If the returned location data is collected using the WPS method, the location data may not contain the last known location. This defect 
	*				is caused due to an internal error of the timestamp of the location data.
	* @see 			ILocationReportListener::OnReportingStateChanged()
	*/
	static result StartLocationReport(const ILocationReportListener& listener, LocationMethod locationMethod, bool isExtendedLocationIncluded ,int reportingInterval);

    /**
    * @page      RemoteLocationProviderLocationAPIsPage		Compatibility for StartLocationReport()
	*
    * @section   RemoteLocationProviderLocationAPIsPageSectionIssues	Issues
    * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
    * -# If the privilege for using the location information is blocked by user consent, the methods do not work as per expectations. 
    * In that case, the result is E_SUCCESS and not E_PRIVILEGE_DENIED.
    * -# The privilege group in bada API versions prior to 2.0 is mentioned below: @n
    * @b Privilege @b group: @b REMOTE_LOCATION @n@n
    *
    * @section	RemoteLocationProviderLocationAPIsPageSectionResolutions	Resolutions 
    * The issues mentioned above are resolved in bada API version 2.0 as follows: @n
    * -# If the privilege for using the location information is blocked by user consent, the E_PRIVILEGE_DENIED exception is thrown.
    * -# The privilege group in bada API version 2.0 or above is mentioned below: @n
    *     @b Privilege @b group: @b LOCATION_UPLOAD @n
    *
    * @par When working with bada API versions prior to 2.0:
    * If an application uses the RequestLocationUpdates() method, it can check whether the privilege for using the location is granted using this method. When 
	* E_PRIVILEGE_DENIED is thrown, the application should take proper action to access information.
    */

	/**
	* Reports the last known location to the bada Server in a distance-based manner. @n
	* The distance between the last known location and the lastly reported location is checked periodically with the specified checking interval.
	* The location reporter sends the location when the distance exceeds the specified distance threshold. It can also send the location information 
	* periodically with the checking interval if the distance threshold is 0.0. @n
	*
	* The %Location reporter reports the basic location information and the extended location information to the bada Server. The basic location information 
	* includes the latitude, longitude, location method, and time stamp. The extended location information includes the altitude, speed, course, horizontal 
	* accuracy, and vertical accuracy. @n
	*
	* This method notifies ILocationReportListener::OnReportingStateChanged() with the @c false value when the reporting fails due to an unstable network or 
	* the last known location is not updated. @n
	*
	* The reporting can be stopped by using the StopLocationReport() method when location reporting is not required. It is recommended when an application 
	* moves to the background (Osp::App::Application::OnBackground() is called). @n
	*
	* In order to conserve power, the interval check may not be done. 
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		2.0
    * @privlevel    NORMAL
	* @privgroup    LOCATION_UPLOAD
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in] 	listener					The listener to register
	* @param[in] 	locationMethod				The location method
	* @param[in] 	isExtendedLocationIncluded	Set to @c true if the extended location data is reported, @n
	*											else @c false
	* @param[in] 	checkingInterval          	The interval time in seconds @n
	*                                       	The interval time is used for checking the distance between the last known location and the reported location.
	* @param[in] 	distanceThreshold       	The distance threshold to report the location information to the bada Server (in meters)
	*
	* @exception 	E_SUCCESS   				The method is successful.
	* @exception 	E_PRIVILEGE_DENIED 			The application does not have the privilege to call this method, or the user blocks an application from using 
	*											the location information.
	* @exception 	E_INVALID_ARG				Either of the following conditions has occurred: @n
	*											- The specified @c checkingInterval is invalid. It should not be less than @c 1. @n
	*											- The specified @c distanceThreshold is invalid. It should not be less than @c 0. @n
	*											- The location method is invalid.
	* @exception 	E_SYSTEM  					A system error has occurred.  
	* @exception 	E_OUT_OF_MEMORY 			The memory is insufficient.
	* @remarks   	If the application reports the current location to the bada Server, LocationProvider::RequestLocationUpdates() should be called to keep 
	*				the location information up-to-date. @n
	*				After using this method, the application should call StopLocationReport().
	* @remarks		If the returned location data is collected using the WPS method, the location data may not contain the last known location. This defect 
	*				is caused due to an internal error of the timestamp of the location data.
	* @see 			ILocationReportListener::OnReportingStateChanged()
	*/
	static result StartLocationReport(const ILocationReportListener& listener, LocationMethod locationMethod, bool isExtendedLocationIncluded, int checkingInterval, float distanceThreshold);

	/**
	*
	* Cancels the location reporting.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	listener	The listener to register
	*/
	static void StopLocationReport(const ILocationReportListener& listener);

	/**
	* Requests the list of the last known locations of targets from the bada Server. @n
	*
	* The application can decide whether to include the extended location information (altitude, speed, course, and accuracies). The location information is 
	* based on the @c maxAge parameter. The smaller the value of the parameter, the more recent location information is received. 
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	REMOTE_LOCATION
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return 		An error code
	* @param[in] 	isExtendedLocationIncluded	Set to @c true if the extended location information is included, @n
	*											else @c false
	* @param[in] 	maxAge						The maximum age of the returned location in minutes, @n
	*                                   		The specified value must be greater than @c 0.
	* @param[in] 	locationMethodPreference	A list of the preferred location method 
	* @param[in] 	targetInfoList				A list of the TargetInfo @n
	*											TargetInfo must include the user ID.
	* @param[in] 	listener					The listener to register
	* @param[out] 	reqId						The requested ID
	* @exception	E_SUCCESS 					The method is successful.
	* @exception	E_INVALID_ARG				A specified input parameter is invalid, or either @c LocationMethodPreference or @c targetInfoList is empty 
	*											and @c maxAge is less than @c 0.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_SYSTEM					A system error has occurred.  
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @remarks  	The maximum list of TargetInfo is @c 20.
	* @remarks		If the returned location data is collected using the WPS method, the location data may not contain the last known location. This defect 
	*				is caused due to an internal error of the timestamp of the location data.
	*
	* @see 			IRemoteLocationListener::OnTargetLocationReceivedN()
	*/
	result RequestLastKnownLocationList(bool isExtendedLocationIncluded, int maxAge,
										const Osp::Base::Collection::IListT<LocationMethod>& locationMethodPreference,
										const Osp::Base::Collection::IList& targetInfoList,
										const IRemoteLocationListener& listener,
										RequestId& reqId) const;
	/**
	* Requests the list of last known locations of the targets in a circular area from the bada Server.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	REMOTE_LOCATION
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in] 	circle						The circular geographical area
	* @param[in] 	isExtendedLocationIncluded	Set to @c true if the extended location information is included, @n
	*											else @c false
	* @param[in] 	maxAge						The maximum age of the returned location in minutes @n
	*                               			The specified value must be greater than @c 0.
	* @param[in] 	locationMethodPreference	A list of the preferred location method
	* @param[in] 	targetInfoList				A list of the TargetInfo @n
	*											TargetInfo must include user ID.
	* @param[in] 	listener					The listener to register
	* @param[out] 	reqId						The requested ID
	*
	* @exception	E_SUCCESS 					The method is successful.
	* @exception	E_INVALID_ARG				A specified input parameter is invalid, or either @c LocationMethodPreference or @c targetInfoList is empty 
	*											and @c maxAge is less than @c 0.
	* @exception	E_PRIVILEGE_DENIED  		The application does not have the privilege to call this method.
	* @exception	E_SYSTEM  					A system error has occurred.  
	* @exception	E_OUT_OF_MEMORY 			The memory is insufficient.
	* @remarks  	The maximum list of TargetInfo is @c 20.
	* @remarks		If the returned location data is collected using the WPS method, the location data may not contain the last known location. This defect 
	*				is caused due to an internal error of the timestamp of the location data.
	*
	* @see 			IRemoteLocationListener::OnTargetLocationReceivedN()
	*/
	result RequestLastKnownLocationListInCircle(const CircleGeographicArea& circle, bool isExtendedLocationIncluded, int maxAge,
												const Osp::Base::Collection::IListT<LocationMethod>& locationMethodPreference,
												const Osp::Base::Collection::IList& targetInfoList,
												const IRemoteLocationListener& listener,
												RequestId& reqId) const;
	/**
	* Requests the list of last known locations of the targets in a rectangular area from the bada Server.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	REMOTE_LOCATION
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in]	rectangle					The rectangular geographical area 
	* @param[in]	isExtendedLocationIncluded	Set to @c true if the extended location information is included, @n
	*											else @c false
	* @param[in]	maxAge						The maximum age of the returned location in minutes @n
	*                               			The specified value must be greater than @c 0.
	* @param[in]	locationMethodPreference	List of the preferred location method
	* @param[in]	targetInfoList				List of the TargetInfo @n
	*											TargetInfo must include the user ID.
	* @param[in]	listener					The listener to register
	* @param[out]	reqId						The requested ID
	* @exception	E_SUCCESS 					The method is successful.
	* @exception	E_INVALID_ARG				A specified input parameter is invalid, or either @c LocationMethodPreference or @c targetInfoList is empty 
	*											and @c maxAge is less than @c 0.
	* @exception	E_PRIVILEGE_DENIED  		The application does not have the privilege to call this method.
	* @exception	E_SYSTEM					A system error has occurred.  
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @remarks		The maximum list of TargetInfo is @c 20.
	* @remarks		If the returned location data is collected using the WPS method, the location data may not contain the last known location. This defect 
	* 				is caused due to an internal error of the timestamp of the location data.
	*
	* @see			IRemoteLocationListener::OnTargetLocationReceivedN()
	*/
	result RequestLastKnownLocationListInRectangle(const RectangleGeographicArea& rectangle, bool isExtendedLocationIncluded, int maxAge,
													const Osp::Base::Collection::IListT<LocationMethod>& locationMethodPreference,
													const Osp::Base::Collection::IList& targetInfoList,
													const IRemoteLocationListener& listener,
													RequestId& reqId) const;
	
	/**
	* Cancels the registration of any set requester.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	reqId	The request ID
	*/
	void CancelRequest(RequestId reqId) const;

	/**
	* Subscribes to the trace service.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_TRACE
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref TraceServicePage "here".
	*
	* @return		An error code
	* @param[in]	traceServiceInfo	The service information to be subscribed to
	* @param[in]	listener			The event listener
	* @param[out] 	reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @exception	E_SYSTEM  			A system error has occurred.  
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @see			ITraceServiceListener::OnTraceServiceSubscribed()
	*/
	result SubscribeToTraceService(const TraceServiceInfo &traceServiceInfo, const ITraceServiceListener& listener, RequestId& reqId) const;
	/**
	* Requests the subscribed service information of the trace service ID.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_TRACE
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref TraceServicePage "here".
	*
	* @return		An error code
	* @param[in]	traceServiceId		The ID of the subscribed trace service
	* @param[in]	listener			The event listener
	* @param[out] 	reqId				The requested ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified @c traceServiceId is empty.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @exception	E_SYSTEM			A system error has occurred.  
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remark		If the @c traceServiceId contains whitespace, this method uses trimmed result.
	* @see 			ITraceServiceListener::OnTraceServiceReceived()
	*/
	result GetTraceServiceSubscription (const Osp::Base::String &traceServiceId, const ITraceServiceListener& listener, RequestId& reqId) const;
	/**
	* Requests the subscribed service information of the specified target.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_TRACE
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref TraceServicePage "here".
	*
	* @return		An error code
	* @param[in]	targetInfo			The target information @n
	*                           		The target information must include the user ID.
	* @param[in]	listener			The event listener
	* @param[out] 	reqId				The requested ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG 		The user ID of the specified @c targetInfo is an empty string.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @see 			ITraceServiceListener::OnTraceServiceListReceivedN()
	*/
	result GetTraceServiceSubscriptionList(const TargetInfo &targetInfo, const ITraceServiceListener& listener, RequestId& reqId) const;
	/**
	* Terminates the subscribed trace service.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_TRACE
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref TraceServicePage "here".
	*
	* @return		An error code
	* @param[in]	traceServiceId			The ID of the subscribed trace service
	* @param[in]	listener				The event listener
	* @param[out] 	reqId					The requested ID
	* @exception	E_SUCCESS 				The method is successful.
	* @exception	E_INVALID_ARG 			The specified @c traceServiceId is empty.
	* @exception	E_PRIVILEGE_DENIED  	The application does not have the privilege to call this method.
	* @exception	E_SYSTEM  				A system error has occurred.  
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @remark		If the @c traceServiceId contains whitespace, this method uses the trimmed result.
	* @see			ITraceServiceListener::OnTraceServiceUnsubscribed()
	*/
	result UnsubscribeFromTraceService (const Osp::Base::String &traceServiceId, const ITraceServiceListener& listener, RequestId& reqId) const;
	/**
	* Deactivates the subscribed trace service until it is reactivated.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_TRACE
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref TraceServicePage "here".
	*
	* @return		An error code
	* @param[in]	traceServiceId		The ID of the subscribed trace service
	* @param[in]	listener			The event listener
	* @param[out]   reqId			    The requested ID
	* @exception	E_SUCCESS 			The method is successful.
	* @exception	E_INVALID_ARG 		The specified @c traceServiceId is empty.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @exception	E_SYSTEM  			A system error has occurred.  
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remark		If the @c traceServiceId contains whitespace, this method uses trimmed result.
	* @see 			ITraceServiceListener::OnTracingStoped()
	*/
	result StopTracing(const Osp::Base::String &traceServiceId, const ITraceServiceListener& listener, RequestId& reqId) const;
	/**
	* Reactivates the subscribed trace service that has been deactivated.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_TRACE
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref TraceServicePage "here".
	*
	* @return		An error code
	* @param[in]	traceServiceId		The ID of the subscribed trace service
	* @param[in]	listener			The event listener
	* @param[out] 	reqId				The requested ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified @c traceServiceId is empty.
	* @exception	E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
	* @exception	E_SYSTEM			A system error has occurred.  
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remark		If the @c traceServiceId contains whitespace, this method uses trimmed result.
	* @see 			ITraceServiceListener::OnTracingResumed()
	*/
	result ResumeTracing(const Osp::Base::String &traceServiceId, const ITraceServiceListener& listener, RequestId& reqId) const;
	/**
	* Requests the accumulated location data of the specified target.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_TRACE
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref TraceServicePage "here".
	*
	* @return		An error code
	* @param[in]	traceServiceId		The ID of the subscribed trace service
	* @param[in]	targetInfo			The target information @n
	*                               	The target information must include the user ID.
	* @param[in]	pStartTime			The start time for the trace data, @n
	*									else @c null to get the data from the start time of this trace service
	* @param[in]	pEndTime			The end time for the trace data, @n
	*									else @c null to get data accumulated up to now, or the end time of this trace service
	* @param[in]	listener			The event listener
	* @param[out] 	reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified @c traceServiceId is empty.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception	E_SYSTEM			A system error has occurred.  
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remark		If the @c traceServiceId contains whitespace, this method uses trimmed result.
	* @see 			ITraceServiceListener::OnTraceDataReceivedN()
	*/
	result GetTraceData(const Osp::Base::String &traceServiceId, const TargetInfo& targetInfo,
								const Osp::Base::DateTime* pStartTime, const Osp::Base::DateTime* pEndTime,
								const ITraceServiceListener& listener, RequestId& reqId) const;
	/**
	* Deletes the accumulated location data of the specified target from the bada Server.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_TRACE
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref TraceServicePage "here".
	*
	* @return		An error code
	* @param[in]	traceServiceId		The ID of the subscribed trace service
	* @param[in]	targetInfo			The target information @n
	*                               	The target information must include the user ID.
	* @param[in]	pStartTime			The start time for the trace data, @n
	*									else @c null to delete the data from the start time of this trace service
	* @param[in]	pEndTime			The end time for the trace data, @n
	*									else @c null to delete the data accumulated up to now, or the end time of this trace service
	* @param[in]	listener			The event listener
	* @param[out] 	reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG 		The specified @c traceServiceId is empty.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @exception	E_SYSTEM			A system error has occurred.  
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remark		If the @c traceServiceId contains whitespace, this method uses trimmed result.
	* @see			ITraceServiceListener::OnTraceDataDeleted()
	*/
	result DeleteTraceData(const Osp::Base::String &traceServiceId, const TargetInfo &targetInfo,
									const Osp::Base::DateTime* pStartTime, const Osp::Base::DateTime* pEndTime,
									const ITraceServiceListener& listener, RequestId& reqId) const ;
	/**
	* Deletes the accumulated device location of all targets.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_TRACE
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref TraceServicePage "here".
	*
	* @return		An error code
	* @param[in]	traceServiceId		The ID of the subscribed trace service
	* @param[in]	pStartTime			The start time for the trace data, @n
	*									else @c null to delete the data from the start time of this trace service
	* @param[in]	pEndTime			The end time for the trace data, @n
	*									else @c null to delete the data accumulated up to now, or the end time of this trace service.
	* @param[in]	listener			The event listener
	* @param[out] 	reqId				The request ID
	* @exception	E_SUCCESS 			The method is successful.
	* @exception	E_INVALID_ARG 		The specified @c traceServiceId is empty.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @exception	E_SYSTEM  			A system error has occurred.  
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remark		If the @c traceServiceId contains whitespace, this method uses trimmed result.
	* @see 			ITraceServiceListener::OnTraceDataDeleted()
	*/
	result DeleteAllTraceData(const Osp::Base::String &traceServiceId, const Osp::Base::DateTime* pStartTime, const Osp::Base::DateTime* pEndTime,
									const ITraceServiceListener& listener, RequestId& reqId) const;
	/**
	* @page		TraceServicePage Compatibility for SubscribeToTraceService(), GetTraceServiceSubscription(), GetTraceServiceSubscriptionList(), 
	* UnsubscribeFromTraceService(), StopTracing(), ResumeTracing(), GetTraceData(), DeleteTraceData(), DeleteAllTraceData()
	*
	* @section	TraceServicePageIssueSection	Issues
	* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* Platform-assigned request ID is not properly assigned to the @c reqId parameter.
	*
	* @section	TraceServicePageResolutionSection	Resolutions
	* The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. 
	*/

// Attribute
private:
	_IRemoteLocationProvider* __pMIRemoteLocationProvider;
	void* pZoneEventListener;	
	void* pLocationRequestListener;
	static void* pLocationReportListenerList;
	static int refCount;

private:
	friend class RemoteLocationProviderEx;
	class RemoteLocationProviderEx* __pRemoteLocationProvider;
};		// class RemoteLocationProvider

};};	// Osp::Locations

#endif // _FLOC_REMOTE_LOCATION_PROVIDER_H_
