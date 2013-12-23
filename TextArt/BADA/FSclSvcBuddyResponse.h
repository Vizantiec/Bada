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
* @file		FSclSvcBuddyResponse.h
* @brief	This is the header file for the %BuddyResponse class.
*
* This header file contains the declarations of the %BuddyResponse class.
*/
#ifndef _FSCL_SVC_BUDDY_RESPONSE_H_
#define _FSCL_SVC_BUDDY_RESPONSE_H_

// Includes
#include "FBaseTypes.h" // for using UserId
#include "FBaseErrors.h"
#include "FBaseDateTime.h"
#include "FSclConfig.h"
#include "FSclSvcBuddyTypes.h"

namespace Osp { namespace Social { namespace Services {

// To create a friendship.
class __BuddyUtil;

/**
* @class	BuddyResponse 
* @brief	This class represents the response to a buddy request.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0
*
* The %BuddyResponse class represents the response to a buddy request and includes the following data: @n
* @li The user ID of the responder
* @li The user name of the responder
* @li The response value (accept, deny, or ignore)
* @li The response time @n
*
*/
class  _EXPORT_SOCIAL_ BuddyResponse:
	public Osp::Base::Object
{
	// Friend class
	friend class __BuddyUtil;

	// Construct Operations
protected:
	/**
	* This is the constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in] 	responderId		The user ID of the responder
	* @param[in] 	responderName	The user name of the responder
	* @param[in] 	response		The response value
	* @param[in] 	responseTime	The response time
	*/
	BuddyResponse(const UserId& responderId, const Osp::Base::String& responderName, BuddyResponseType response, const Osp::Base::DateTime& responseTime);
	
public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	BuddyResponse(void);

	/**
	* This is the copy constructor for the %BuddyResponse class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	value 	An instance of %BuddyResponse
	*/
	BuddyResponse(const BuddyResponse& value);	

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	virtual ~BuddyResponse(void);

public:
	/**
	* Copies the data contained in the specified %BuddyResponse instance to this instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	value	The source instance of %BuddyResponse
	*/
	BuddyResponse& operator =(const BuddyResponse& value);

	// Operations
public:
	/**
	* Gets the user ID of the responder.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*
	* @return	The user ID of the responder
	*/
	UserId GetResponderId(void) const;

	/**
	* Gets the user name of the responder.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*
	* @return	The user name of the responder
	*/
	Osp::Base::String GetResponderName(void) const;

	/**
	* Gets the response time. @n
	* The response time is UTC time.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*
	* @return	The response time
	*/
	Osp::Base::DateTime GetResponseTime(void) const;

	/**
	* Gets the response value.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*
	* @return	The response value
	*/
	BuddyResponseType GetResponse(void) const;


private:
	/*
	* Gets the string representation of the response time (mm/dd/yyyy hh:mm:ss).
	*
	* @return	A string representing the response time (mm/dd/yyyy hh:mm:ss)
	*/
	Osp::Base::String GetResponseTimeString(void) const;

private:	
	UserId __responderId;
	Osp::Base::String __responderName;	
	BuddyResponseType __response;
	Osp::Base::DateTime __responseTime;

	friend class BuddyResponseEx;
	class BuddyResponseEx* __pBuddyResponseEx;
}; // class BuddyResponse


};};};// Osp::Social::Services

#endif// _FSCL_SVC_BUDDY_RESPONSE_H_
