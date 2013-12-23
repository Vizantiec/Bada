/* $Change: 1144988 $ */
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
* @file		FSclSvcReceivedBuddyRequest.h
* @brief	This is the header file for the %ReceivedBuddyRequest class.
*
* This header file contains the declarations of the %ReceivedBuddyRequest class.
*/
#ifndef _FSCL_SVC_RECEIVED_BUDDY_REQUEST_H_
#define _FSCL_SVC_RECEIVED_BUDDY_REQUEST_H_

#include "FBaseTypes.h"
#include "FBaseObject.h"
#include "FBaseDateTime.h"
#include "FSclConfig.h"

namespace Osp { namespace Social { namespace Services {
// To create friendship.
class __BuddyUtil;

/**
* @class	ReceivedBuddyRequest 
* @brief	This class represents the received buddy request.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0
*
* The %ReceivedBuddyRequest class represents an ingoing buddy request.
* This class includes the following data:
* @li User ID of the requester
* @li User name of the requester
* @li Requested time @n
*
*/
class  _EXPORT_SOCIAL_ ReceivedBuddyRequest:
	public Osp::Base::Object
{
	// Friend class
	friend class __BuddyUtil;

	// Construct Operations
private:
	/*
	* This is the constructor for this class.
	*
	* @param[in] requesterId		The user ID of the requester
	* @param[in] requestTime		The request time
	*/
	ReceivedBuddyRequest(const UserId& requesterId, const Osp::Base::DateTime& requestTime);

protected:
	/**
	* This is the constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	requesterId		The user ID of the requester
	* @param[in]	requesterName	The user name of the requester	
	* @param[in]	requestTime		The requested time
	*/
	ReceivedBuddyRequest(const UserId& requesterId, const Osp::Base::String& requesterName, const Osp::Base::DateTime& requestTime);

	
public:
	/**
	* This is the default constructor for this class.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*/
	ReceivedBuddyRequest(void);

	/**
	* This is the copy constructor for the %ReceivedBuddyRequest class.
	* It creates an instance of %ReceivedBuddyRequest with the values of the specified instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	value 		An instance of %ReceivedBuddyRequest
	*/
	ReceivedBuddyRequest(const ReceivedBuddyRequest& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*/
	virtual ~ReceivedBuddyRequest(void);

public:
	/**
	* Copies the data contained in the specified %ReceivedBuddyRequest to this instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	value 		The source instance of %ReceivedBuddyRequest
	*/
	ReceivedBuddyRequest& operator =(const ReceivedBuddyRequest& value);

// Operations
public:
	/**
	* Gets the user ID of the requester.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	* @return	The user ID of the requester
	*/
	UserId GetRequesterId(void) const;

	/**
	* Gets the user name of the requester.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	* @return	The user name of the requester
	*/
	Osp::Base::String GetRequesterName(void) const;

	/**
	* Gets the requested time. @n
	* The requested time is UTC time.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	* @return	The requested time
	*/
	Osp::Base::DateTime GetRequestTime(void) const;

private:
	/*
	* Gets the string representation of the request time. (mm/dd/yyyy hh:mm:ss)
	*
	* @return	The requested time as a string
	*/
	Osp::Base::String GetRequestTimeString(void) const;


private:	
	UserId __requesterId;
	Osp::Base::String __requesterName;
	Osp::Base::DateTime __requestTime;

	friend class ReceivedBuddyRequestEx;
	class ReceivedBuddyRequestEx* __pReceivedBuddyRequestEx;
}; // class ReceivedBuddyRequest


};};};// Osp::Social::Services

#endif// _FSCL_SVC_RECEIVED_BUDDY_REQUEST_H_
