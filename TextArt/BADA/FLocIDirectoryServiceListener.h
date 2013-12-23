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
 * @file	FLocIDirectoryServiceListener.h
 * @brief	This is the header file for the IDirectoryServiceListener interface.
 *
 * This header file contains declaration of the IDirectoryServiceListener interface.
 */

#ifndef _FLOC_IDIRECTORY_SERVICE_LISTENER_H_
#define _FLOC_IDIRECTORY_SERVICE_LISTENER_H_

// include
#include "FLocationConfig.h"
#include "FBaseTypes.h"

// forward declaration
namespace Osp { namespace Base { namespace Collection { class IList; }; }; };
namespace Osp { namespace Base { class String; }; };


namespace Osp { namespace Locations { namespace Services {

// forward declaration
class IDirectoryServiceProvider;

/**
 * @interface	IDirectoryServiceListener
 * @brief		This interface provides a callback mechanism for the directory service providers to send information,
 * about the service request to applications.
 * @deprecated	This interface is deprecated.
 * @since		1.0
 *
 * The %IDirectoryServiceListener interface provides a callback mechanism for the directory service providers to send information,
 * about the service request to applications. Applications implement this interface and register it in the service request in IDirectoryServiceProvider,
 * to obtain search results from the service provider.
 */
class _EXPORT_LOCATION_ IDirectoryServiceListener 
{
// Lifecycle
public:
	/**
	 * This is the destructor for this interface.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual ~IDirectoryServiceListener(void);

// Operation
public:

	/** 
	* Called by the directory service provider when the result of a search request has been received.
	*
	* @deprecated	This method is deprecated.
	* @since			1.0
	* @param[in]	requestId	The request ID whose result has been received
	* @param[in]	provider	The provider of the result
	* @param[in]	pLandmarks	The list of Landmark objects as the result; @n 
	*							@c null, if an error occurred
	* @param[in]	r			The result
	* @param[in]	errorCode	The error code from the service provider; @n
	*							Empty string if successful
	* @param[in]	errorMsg	The error message from the service provider; @n
	*							Empty string if successful
	* @exception	E_SUCCESS The method was successful.
	* @exception	E_LOCATION_SERVICE An error in the service provider prevented it from servicing the request.
	* @exception	E_OPERATION_CANCELED The service request has been canceled by @ref Osp::Locations::Services::IDirectoryServiceProvider::CancelRequest() method.
	* @exception	E_SERVER An error occurred on the server side.
	*/
	virtual void OnDirectoryRequestResultReceivedN(RequestId requestId, const IDirectoryServiceProvider& provider, Osp::Base::Collection::IList* pLandmarks,
		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

};	// class IDirectoryServiceListener

}; }; };	// Osp::Locations::Services

#endif // _FLOC_IDIRECTORY_SERVICE_LISTENER_H_
