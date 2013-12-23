/* $Change: 1145044 $ */
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
 * @file	FLocServiceInfo.h 
 * @brief	This is the header file for the %ServiceInfo and %TraceServiceInfo classes.
 *
 * This header file contains the declarations of the %ServiceInfo and %TraceServiceInfo classes.
 * 
 */


#ifndef _FLOC_SERVICE_INFO_H_
#define _FLOC_SERVICE_INFO_H_

#include "FLocationConfig.h"
#include "FBaseObject.h"
#include "FBaseColArrayList.h"
#include "FBaseColArrayListT.h"
#include "FBaseDateTime.h"
#include "FLocLocation.h"

struct MTargetInfo;
struct MServiceInfo;
struct MTraceServiceInfo;

namespace Osp { namespace Locations { 

class RemoteLocationProvider;
class RectangleGeographicArea;

/**
* @class	TargetInfo
* @brief	This class is used for the target information, and includes the user ID and the optional device ID.
* @deprecated   This class is deprecated due to the operation policy of the bada Server.
* @since 	1.0
*
* The %TargetInfo class represents the target device information as the user ID and the optional device ID.
*
*/
class _EXPORT_LOCATION_ TargetInfo : 
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
	TargetInfo(void);
	/**
	* Initializes this instance of %TargetInfo with the user ID.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]  	userId	The user ID
	*/
	TargetInfo(const UserId& userId);
	/**
	* This is the copy constructor for the %TargetInfo class.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	*/
	TargetInfo(const TargetInfo& value);
	/**
	* This operator assigns the value of the %TargetInfo object to the current instance.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	*/
	TargetInfo& operator=(const TargetInfo& rhs);
	/** 
	 * This is the destructor for this class.
	 *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	 * @since 	1.0
	 */
	virtual ~TargetInfo(void);
private:
	TargetInfo(MTargetInfo* pMTargetInfo);
	const MTargetInfo* GetMTargetInfo(void) const;
// Operations
public:	
	/**
	* Gets the user ID.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return   The user ID
	*/
	const UserId GetUserId(void) const;
	/**
	* Gets the device ID.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return   The device ID, @n
	*			else an empty string if the device ID does not exist
	*/
	const Osp::Base::String GetDeviceId(void) const;
	/**
	* Sets the device ID.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in] 	deviceId	The device ID
	* @see 			GetDeviceId()
	*/
	void SetDeviceId(Osp::Base::String deviceId);
	/**
	* Sets the user ID.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in] 	userId		The user ID
	* @see 			GetUserId()
	*/
  	void SetUserId(UserId userId);
	/**
	*
	* Overrides the equals() method in the Object class to compare the equality of values in the two %TargetInfo objects. 
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return       @c true if all the fields in the objects are equal, @n
	*				else @c false
	* @param[in] 	obj 	The Object with which the comparison is made 
	*/
	virtual bool Equals(const Osp::Base::Object& obj) const;

	/** 
	* Overrides the GetHashCode() method in the Object class to generate the hash value of the current instance.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		The hash value of the current instance
	*/
	virtual int GetHashCode(void) const;
	
private:
	MTargetInfo* __pMTargetInfo;
	Osp::Base::String __userId;
	Osp::Base::String __deviceId;

friend class _RemoteUtil;
friend class RemoteLocationProvider;

private:
	friend class TargetInfoEx;
	class TargetInfoEx* __pTargetInfoEx;

};

/**
* @class	ServiceInfo
* @brief	This class is used for the service information for trace service.
* @deprecated   This class is deprecated due to the operation policy of the bada Server.
* @since	1.0
*
* The %ServiceInfo class represents the common information of trace service. It also includes the service name, the service ID, the 
* list of location methods, and the list of target and time information.
*
*/
class _EXPORT_LOCATION_ ServiceInfo :
public Osp::Base::Object
{
//Lifecycle
protected:
    /**
	 * @internal
     *
	 * This method is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this method.
     *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
     * @since   1.0
	 */
	ServiceInfo(void);
    
    /**
	 * @internal
     *
	 * This method is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this method.
     *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
     * @since   1.0
	 */
	ServiceInfo(const ServiceInfo& value);
    
    /**
	 * @internal
     *
	 * This method is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this method.
     *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
     * @since   1.0
	 */
	ServiceInfo& operator=(const ServiceInfo& rhs);

public: 
    /**
    * This is the destructor for this class.
    *
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
    * @since 1.0
    */
	virtual ~ServiceInfo(void) = 0;

//Operations
protected:
    /**
	 * @internal
     *
	 * This method is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this method.
     *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
     * @since   1.0
	 */
	virtual const MServiceInfo* GetMServiceInfo(void) const = 0;

    /**
	 * @internal
     *
	 * This method is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this method.
     *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
     * @since   1.0
	 */
	result SetServiceId(const Osp::Base::String& name);

    /**
	 * @internal
     *
	 * This method is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this method.
     *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
     * @since   1.0
	 */
	void SetSubscriptionTime(const Osp::Base::DateTime& time);
public:
	/**
	* Sets the service name.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return 		An error code
	* @param[in] 	name		The service name
	* @exception	E_SUCCESS 	The method is successful.
	* @see          GetServiceName()
	*/
	result SetServiceName(const Osp::Base::String& name);
	/**
	* Gets the service name.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		The service name, @n
	*				else an empty string if the service name does not exist
	* @see 			SetServiceName()
	*/
	const Osp::Base::String GetServiceName(void) const;
	/**
	* Gets the service ID.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return  	The service ID
	*/
	const Osp::Base::String GetServiceId(void) const;
	/**
	* Gets the starting time.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return  	The starting time (UTC)
	*/
	const Osp::Base::DateTime GetStartTime(void) const;
	/**
	* Gets the end time.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return  	The end time (UTC)
	*/
	const Osp::Base::DateTime GetEndTime(void) const;
	/**
	* Gets the subscription time.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return  	The subscription time (UTC)
	*/
	const Osp::Base::DateTime GetSubscriptionTime(void) const;
	/**
	* Gets the maximum age.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return  	The maximum age
	*/
	int GetMaxAge(void) const;
	/**
	* Gets the interval time.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return	The interval time
	*/
	int GetInterval(void) const;
	/**
	* Gets the list of preferred location method. 
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return	The list of preferred location method
	* @see 		LocationMethod()
	*/
	const Osp::Base::Collection::IListT<LocationMethod>& GetLocationMethodPreference(void) const;
	/**
	* Gets the list of the target information.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return	The list of the target information
	* @see 		TargetInfo()	
	*/
	const Osp::Base::Collection::IList& GetTargetInfoList(void) const;
//Attribute
protected:
    
    /**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
     * @since 1.0
	 */
	Osp::Base::String _serviceName;

    /**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	 * @since 1.0
	 */
	Osp::Base::String _serviceId;

    /**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	 * @since 1.0
	 */
	Osp::Base::DateTime _startTime;

    /**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
     * @since 1.0
	 */
	Osp::Base::DateTime _endTime;

    /**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
     *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
     * @since 1.0
	 */
	Osp::Base::DateTime _subscriptionTime;

    /**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
     *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
     * @since 1.0
	 */
	Osp::Base::Collection::ArrayListT<LocationMethod>* _pLocationMethodPreference;

    /**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
     *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
     * @since 1.0
	 */
	Osp::Base::Collection::ArrayList* _pTargetInfoList;

private:
	friend class ServiceInfoEx;
	class ServiceInfoEx* __pServiceInfoEx;
};      

/**
* @class	TraceServiceInfo
* @brief	This class provides the service information for the trace service.
* @deprecated   This class is deprecated due to the operation policy of the bada Server.
* @since	1.0
*
* The %TraceServiceInfo class represents service information for subscribing to the trace service.
* 
* The following example demonstrates how to use the %TraceServiceInfo class:
*
* @code
*
* #include <FLocations.h>
*	
* using namespace Osp::Base;
* using namespace Osp::Base::Collection;
* using namespace Osp::Locations;
*	
* void
* MyClass::TraceServiceInfoSample(void)
* {
*	result r = E_SUCCESS;
*	TraceServiceInfo serviceInfo;
*
*	// Sets the startTime and endTime for the tracing length
*	DateTime startTime, endTime;
*	startTime.SetValue(2010, 2, 14, 8, 0, 0);
*	endTime.SetValue(2010, 2, 14, 20, 0, 0);
*
*	// Sets the preference location method
*	ArrayListT<LocationMethod> preferences;
*	preferences.Construct(1);
*	preferences.Add(LOC_METHOD_HYBRID);
*
*	// Sets the appointed targets
*	ArrayList targetList;
*	targetList.Construct(1);
*	TargetInfo targetInfo(L"userId");
*	targetList.Add(targetInfo);
*
* 	// Sets the tracing period
*	int interval = 10;
*
*	r = serviceInfo.Set(startTime, endTime, interval, preferences, targetList);
*}
*	
* @endcode
*/
class _EXPORT_LOCATION_ TraceServiceInfo:
public ServiceInfo
{
public:
	/** 
	* This is the default constructor for this class.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	* @remarks	After creating an instance of TraceServiceInfo, the Set() method must be called explicitly to initialize this instance. 
	* @see 		Set()
	*/
	TraceServiceInfo(void);

	/**
	* This is the copy constructor for the %TraceServiceInfo class.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	*/
	TraceServiceInfo(const TraceServiceInfo& value);
	
	/**
	* This operator assigns the value of the %TraceServiceInfo object to the current instance.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	*/
	TraceServiceInfo& operator=(const TraceServiceInfo& rhs);

	/**
	* This is the destructor for this class.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	*/
	virtual ~TraceServiceInfo(void);
	
	/**
    * Sets the values of the %TraceServiceInfo.
    *
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 			1.0
	* @compatibility  	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*                 	For more information, see @ref TraceServiceInfoSetPage "here".
	*
	* @return		An error code
	* @param[in]	startTime					The start date and time of the trace service (UTC)
	* @param[in]	endTime						The end date and time of the trace service (UTC)
	* @param[in]	maxAge						The maximum age in minutes, must be greater than @c 0
	* @param[in]	interval					The interval for tracing in minutes, must be greater than @c 0
	* @param[in]	locationMethodPreference	The desired location method @n
	*											The first location method is the most preferred location method.
	* @param[in]	targetInfoList				The target information, must include the user ID
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_ARG 				The @c locationMethodPreference is empty or the list is not made of LocationMethod(), or @n
	*											@c maxAge > @c interval.
	* @remarks  	The maximum size of the @c targetInfoList parameter is @c 20. @n The@c maxAge parameter should be less than or equal to the @c interval 
	*				parameter.
	*/
	result Set(const Osp::Base::DateTime& startTime, const Osp::Base::DateTime& endTime, int maxAge, int interval, 
					const Osp::Base::Collection::IListT<LocationMethod>& locationMethodPreference, const Osp::Base::Collection::IList& targetInfoList);
	/**
	* @page		TraceServiceInfoSetPage		Compatibility for Set()
	*
	* @section	TraceServiceInfoSetPageIssueSection	Issues
	* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* The hybrid location may not be the latest location. Therefore, using this method with the hybrid location method is not recommended.
	*
	* @section	TraceServiceInfoSetPageResolutionSection	Resolutions
	* The issue mentioned above is resolved in bada API version 2.0 as follows: @n
	* Using this method with the hybrid location method is recommended in bada API version 2.0 or above.
	*/

    /**
    * Sets the values of the %TraceServiceInfo.
    *
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
    * @since    	2.0
    *
    * @return   	An error code
    * @param[in] 	startTime					The start date time of the trace service (UTC)
    * @param[in] 	endTime						The end date and time of trace service (UTC)
    * @param[in] 	interval					The interval for tracing in minutes, must be greater than @c 0
    * @param[in] 	locationMethodPreference   	The desired location method @n
    *                                       	The first location method is the most preferred location method.
    * @param[in] 	targetInfoList				The target information, must include user ID
    * @exception 	E_SUCCESS    				The method is successful.
    * @exception 	E_INVALID_ARG 				The @c locationMethodPreference is empty or the list is not made of LocationMethod.
    * @remarks  	The maximum size of targetInfoList is @c 20.
    */
    result Set(const Osp::Base::DateTime& startTime, const Osp::Base::DateTime& endTime, int interval, const Osp::Base::Collection::IListT<LocationMethod>& locationMethodPreference, const Osp::Base::Collection::IList& targetInfoList);

	/**
	 * Compares the equality of values in two %TraceServiceInfo objects.
	 *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @return		@c true if the objects are equal, @n
	 *			    else @c false
	 * @param[in]	obj		The Object with which the comparison is done
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const;

	/**
	 * Overrides the GetHashCode() method in the Object class to generate the hash value of the current instance.
	 *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;
	
private:
	TraceServiceInfo(MTraceServiceInfo* pMTraceServiceInfo);
	virtual const MServiceInfo* GetMServiceInfo(void) const;
private:
	MTraceServiceInfo* __pMTraceServiceInfo;

friend class _RemoteUtil;
friend class RemoteLocationProvider;

private:
	friend class TraceServiceInfoEx;
	class TraceServiceInfoEx* __pTraceServiceInfoEx;
};

}; };     // Osp::Location


#endif // _FLOC_SERVICE_INFO_H_
