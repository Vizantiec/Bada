/* $Change: 1202329 $ */
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
* @file		FSclSvcSnsStatusText.h
* @brief	This is the header file for the %SnsStatusText class.
*
* This header file contains the declarations of the %SnsStatusText class.
*/
#ifndef _FSCL_SVC_SNS_STATUSTEXT_H_
#define _FSCL_SVC_SNS_STATUSTEXT_H_

#include "FBaseObject.h"
#include "FBaseString.h"
#include "FBaseDateTime.h"
#include "FSclConfig.h"

namespace Osp { namespace Social { namespace Services {

	class __SnsUtil;

/**
* @class		SnsStatusText 
* @brief		This class provides the methods to manage the information of a SNS status text.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since		1.0 
*
* @remarks	In Twitter, the status text means the tweet that a specific user updated recently.
*
* The %SnsStatusText class provides the methods to manage the information of a SNS status text.
*/
class  _EXPORT_SOCIAL_ SnsStatusText :
	public Osp::Base::Object
{
	friend class __SnsUtil;
	
private:
	/**
	* Initializes this instance of %SnsStatusText with the specified parameters.
	*
	* @param[in]	serviceProvider			The service provider
	* @param[in]	snsUserId				The user ID
	* @param[in]	statusText				The status text
	* @param[in]	updateTime				The time when the status updated
	*/
	SnsStatusText(const Osp::Base::String& serviceProvider, const Osp::Base::String& snsUserId, const Osp::Base::String& statusText, const Osp::Base::DateTime& updateTime);

public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	SnsStatusText(void);

	/**
	* This is the copy constructor for the %SnsStatusText class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	value	An instance of %SnsStatusText
	*/
	SnsStatusText(const SnsStatusText& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	virtual ~SnsStatusText(void);

public:
	/**
	* Gets the service provider.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		The service provider
	*/
	Osp::Base::String GetServiceProvider(void) const;

	/**
	* Gets the SNS user ID of this status text.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		The snsUserId
	*/
	Osp::Base::String GetSnsUserId(void) const;

	/**
	* Gets the status text.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		The status text
	*/
	Osp::Base::String GetStatusText(void) const;

	/**
	* Gets the last update time. @n
	* If a specific service provider does not provide the update time of the status text, the returned value has the minimum value of the DateTime, which can 
	* be retrieved by DateTime::GetMinValue() (i.e "January 1 1 00:00:00").
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		The time
	*/
	Osp::Base::DateTime GetUpdateTime(void) const;

private:
	Osp::Base::String		__serviceProvider;
	Osp::Base::String		__snsUserId;
	Osp::Base::String		__statusMessage;
	Osp::Base::DateTime	__updateTime;

	friend class SnsStatusTextEx;
	class SnsStatusTextEx* __pSnsStatusTextEx;
}; 

};};};// Osp::Social::Services

#endif //_FSCL_SVC_SNS_STATUSTEXT_H_
