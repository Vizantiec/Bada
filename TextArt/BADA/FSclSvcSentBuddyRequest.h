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
* @file		FSclSvcSentBuddyRequest.h
* @brief	This is the header file for the %SentBuddyRequest class.
*
* This header file contains the declarations of the %SentBuddyRequest class.
*/
#ifndef _FSCL_SVC_SENT_BUDDY_REQUEST_H_
#define _FSCL_SVC_SENT_BUDDY_REQUEST_H_

#include "FBaseTypes.h" // for using UserId and RequestId
#include "FBaseObject.h"
#include "FBaseDateTime.h"
#include "FSclConfig.h"

namespace Osp { namespace Social { namespace Services {
// To create a friendship.
class __BuddyUtil;

/**
* @class	SentBuddyRequest 
* @brief	This class represents an outgoing buddy request.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0
*
* The %SentBuddyRequest class represents an outgoing buddy request. @n
* This class includes the following data:
* @li User ID of the receiver
* @li User name of the receiver
* @li Requested time @n
*
*/
class  _EXPORT_SOCIAL_ SentBuddyRequest:
	public Osp::Base::Object
{
	// Friend class
	friend class __BuddyUtil;

	// Construct Operations
private:
	/*
	* This is the constructor for this class.
	*
	* @param[in]	receiverId		The user ID of the receiver
	* @param[in]	requestTime		The request time
	*/
	SentBuddyRequest(const UserId& receiverId, const Osp::Base::DateTime& requestTime);

protected:
	/**
	* Initializes this instance of %SentBuddyRequest with the specified parameters.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	receiverId		The user ID of the receiver
	* @param[in]	receiverName	The user name of the receiver
	* @param[in]	requestTime		The requested time
	*/
	SentBuddyRequest(const UserId& receiverId, const Osp::Base::String& receiverName, const Osp::Base::DateTime& requestTime);		

public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*/
	SentBuddyRequest(void);

	/**
	* This is the copy constructor for the %SentBuddyRequest class. @n
	* It creates an instance of %SentBuddyRequest with the values of the specified instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	value	An instance of %SentBuddyRequest
	*/
	SentBuddyRequest(const SentBuddyRequest& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*/
	virtual ~SentBuddyRequest(void);

public:
	/**
	* Copies the data contained in the specified %SentBuddyRequest to this instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	value 		The source instance of %SentBuddyRequest
	*/
	SentBuddyRequest& operator =(const SentBuddyRequest& value);

//Operations
public:
	/**
	* Gets the user ID of the receiver.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	* @return	The user ID of the receiver
	*/
	UserId GetReceiverId(void) const;

	/**
	* Gets the user name of the receiver.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	* @return	The user name of the receiver
	*/
	Osp::Base::String GetReceiverName(void) const;

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
	* Gets the string representation of the requested time. (mm/dd/yyyy hh:mm:ss)
	*
	* @return	The requested time as a string
	*/
	Osp::Base::String GetRequestTimeString(void) const;

private:	
	UserId __receiverId;
	Osp::Base::String __receiverName;
	Osp::Base::DateTime __requestTime;

	friend class SentBuddyRequestEx;
	class SentBuddyRequestEx* __pSentBuddyRequestEx;
}; // class SentBuddyRequest


};};};// Osp::Social::Services

#endif// _FSCL_SVC_SENT_BUDDY_REQUEST_H_
