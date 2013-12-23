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
 * @file		FLocIRemoteLocationListener.h 
 * @brief		This is the header file for the %IRemoteLocationListener interface.
 *
 * This header file contains the declarations of the %IRemoteLocationListener interface.
 */

#ifndef _FLOC_IREMOTE_LOCATION_LISTENER_H_
#define _FLOC_IREMOTE_LOCATION_LISTENER_H_

#include "FLocationConfig.h"
#include "FBaseColIMap.h"

namespace Osp { namespace Locations { 

/**
* @interface	IRemoteLocationListener
* @brief		This interface provides a listener that receives the events associated with the RemoteLocationProvider.
* @deprecated   This interface is deprecated due to the operation policy of the bada Server.
* @deprecated	This interface is deprecated.
* @since		1.0
*
* The %IRemoteLocationListener interface provides a listener that receives the events associated with the %RemoteLocationProvider.
* The applications must implement this interface and register it with the RemoteLocationProvider::RequestLastKnownLocationList(), 
* RemoteLocationProvider::RequestLastKnownLocationListInCircle(), and RemoteLocationProvider::RequestLastKnownLocationListInRectangle() 
* methods.
*
* 
* The following example demonstrates how to use this interface to get TargetInfos and Locations from the server.
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
* MyClass::OnTargetLocationReceivedN(RequestId reqId, Osp::Base::Collection::IMap* pTargetLocation, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg)
* {
*	TargetInfo* pTargetInfo = null;
*	Location* pLocation = null;
*	String userId;
*	const QualifiedCoordinates* pQualCoord = null;
*	int errCode = 0;
*	double latitude = 0, longitude = 0;
*
*	if(r != E_SUCCESS){
*
*		// Gets the error message.
*		AppLog("Error code : %S", errorCode.GetPointer());
*		AppLog("Error Message : %S", errorMsg.GetPointer());
*	}else{
*
*		// Gets the map with the key(TargetInfo) and value(Location).
*		IMapEnumerator* pMapEnum = pTargetLocation->GetMapEnumeratorN();
*		if (pMapEnum) {
*			while(!IsFailed(pMapEnum->MoveNext())) {
*				// Gets the TargetInfo.
*				pTargetInfo = static_cast<TargetInfo*>(pMapEnum->GetKey());
*				userId = pTargetInfo->GetUserId();
*
*				// Gets the Location.
*				pLocation = static_cast<Location*>(pMapEnum->GetValue());
*				if(pLocation->IsValid()){
*					pQualCoord = pLocation->GetQualifiedCoordinates();
*					latitude = pQualCoord->GetLatitude();
*					longitude = pQualCoord->GetLongitude();
*
*				}else{
*					// Invalid location's error code.
*					errCode = pLocation->GetErrorCode();
*				}
*			}
*		}
*
*		// Release
*		if(pMapEnum)
*			delete pMapEnum;
*		if(pTargetLocation){
*			pTargetLocation->RemoveAll(true);
*			delete pTargetLocation;
*		}
*	}
*
*}
*	
* @endcode
*/
class _EXPORT_LOCATION_ IRemoteLocationListener 
{
// Lifecycle
public:
    /**
     * This is the destructor for this class.
     *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	 * @deprecated	This method is deprecated.
     * @since	1.0
     */
	virtual ~IRemoteLocationListener(void) {}

// Operations
public:
	/**
	* Called to notify the receipt a collection of key-value pairs representing the TargetInfo and Location. @n
	* If the user access is not permitted or the designated target is out of the boundary, the application may receive invalid location information. The 
	* application can know the reason for the invalid information by using the Location::GetErrorCode() method.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @compatibility    This class has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
    *                   For more information, see @ref CompRemoteLocationListenerOnTargetLocationReceivedPage "here".
	*
	* @param[in]	reqId					The request ID
	* @param[in]	pTargetLocation			A collection of key-value pairs representing the TargetInfo and Location
	* @param[in]	r						The result of the request @n
	*										The result can be one of the exception codes mentioned below.
	* @param[in]	errorCode				The error code
	* @param[in]	errorMsg				The error message
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_SERVER				The request to the server has failed. @n 
	*										Check @c errorCode and @c errorMsg for details.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 		The network connection has failed.
	* @exception	E_OPERATION_CANCELED 	The service request has been canceled by @ref Osp::Locations::RemoteLocationProvider::CancelRequest() method.
	* @remarks		The returned map of target locations must be deleted by the application.
	*/
	virtual void OnTargetLocationReceivedN(RequestId reqId, Osp::Base::Collection::IMap* pTargetLocation, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;  

/**
* @page CompRemoteLocationListenerOnTargetLocationReceivedPage Compatibility for OnTargetLocationReceivedN()
* @section CompRemoteLocationListenerOnTargetLocationReceivedSectionIssues Issues
* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
*
* If an application requests the last known location of a single user and the device is unable to share the
* location, the cause of failure is informed differently depends upon the method used for requesting the location. 
* For the RemoteLocationProvider::RequestLastKnownLocationList() method with a single user, the cause of failure is
* stored in @c errorCode. 
* Whereas, for the RemoteLocationProvider::RequestLastKnownLocationListInCircle() and
* RemoteLocationProvider::RequestLastKnownLocationListInRectangle() methods, the cause of failure is stored 
* in @c pTargetLocation (%Location instance).
*
* @section CompRemoteLocationListenerOnTargetLocationReceivedSectionResolutions Resolutions 
* The issue mentioned above is resolved in bada API version 2.0 as follows. @n
* If an application requests the last known location of a single user and the device is unable to share the
* location, the cause of failure is stored in @c pTargetLocation (%Location instance).
*/    

};		// class IRemoteLocationListener

};};	// Osp::Locations

#endif // _FLOC_IREMOTE_LOCATION_LISTENER_H_
