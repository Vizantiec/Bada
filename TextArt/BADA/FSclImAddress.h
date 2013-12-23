/* $Change: 1142016 $ */
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
* @file		FSclImAddress.h
* @brief	This is the header file for the %ImAddress class.
*
* This header file contains the declarations of the %ImAddress class.
*/
#ifndef _FSCL_IM_ADDRESS_H_
#define _FSCL_IM_ADDRESS_H_

// Includes
#include "FBaseResult.h"
#include "FBaseString.h"
#include "FSclConfig.h"

namespace Osp { namespace Social {

// Constants
/** The maximum length of the IM address property. 
*
* @since 	1.0
*/
static const int MAX_IM_ADDRESS_LENGTH					= 100;

/** The IM service provider name for MSN.
*
* @since 	1.0
*/
static const Osp::Base::String IM_MSN					= L"MSN";
/** The IM service provider name for ICQ.
*
* @since 	1.0
*/
static const Osp::Base::String IM_ICQ					= L"ICQ";
/** The IM service provider name for AIM.
*
* @since 	1.0
*/
static const Osp::Base::String IM_AIM					= L"AIM";
/** The IM service provider name for Yahoo.
*
* @since 	1.0
*/
static const Osp::Base::String IM_YAHOO					= L"Yahoo";
/** The IM service provider name for Jabber. 
*
* @since 	1.0
*/
static const Osp::Base::String IM_JABBER				= L"Jabber";
/** The IM service provider name for Google talk.
*
* @since 	1.0
*/
static const Osp::Base::String IM_GTALK					= L"Google Talk";
/** The IM service provider name for Skype.
*
* @since 	1.0
*/
static const Osp::Base::String IM_SKYPE					= L"Skype";
/** The IM service provider name for QQ.
*
* @since 	1.0
*/
static const Osp::Base::String IM_QQ					= L"QQ";



/**
* @class	ImAddress
* @brief	This class represents the Instant Messenger (IM) addresses.
* @since	1.0
*
* 	The %ImAddress class represents the Instant Messenger (IM) addresses. It consists of an IM service provider name and an account.
*/
class  _EXPORT_SOCIAL_ ImAddress:
	public Osp::Base::Object
{
// Construct Operation
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 	1.0
	 */
	ImAddress(void);

	/**
	 * Initializes this instance of %ImAddress with the specified parameters. @n
	 * This constructs an instance of %ImAddress with the specified service provider name.
	 *
	 * @since 		1.0
	 * @param[in]	serviceProviderName		The service provider name of the %ImAddress
	 * @param[in]	imAddress				The IM address
	 * @see			#IM_MSN, #IM_ICQ, #IM_AIM, #IM_YAHOO, #IM_JABBER, #IM_GTALK, #IM_SKYPE, #IM_QQ
	 */
	ImAddress(const Osp::Base::String& serviceProviderName, const Osp::Base::String& imAddress);

	/**
	 * This is the copy constructor for the %ImAddress class. @n
	 * This constructs an instance of %ImAddress with the values of the specified instance.
	 *
	 * @since 		1.0	
	 * @param[in]	value	An instance of %ImAddress
	 */
	ImAddress(const ImAddress& value);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 	1.0
	 */
	virtual ~ ImAddress(void);

public:
	/**
	 * Copies the data contained in the specified instance of %ImAddress to the current instance.
	 *
	 * @since 		1.0
	 * @param[in]	value	An instance of %ImAddress
	 */
	ImAddress& operator =(const ImAddress& value);

	/**
	 * Checks whether the value of the specified instance of %ImAddress is equal to the value of the current instance.
	 *
	 * @since 		1.0
	 * @return		@c true if the value of the specified instance of %ImAddress is equal to the value of the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %ImAddress
	 */
	bool operator ==(const ImAddress& rhs) const;

	/**
	 * Checks whether the value of the specified instance of %ImAddress does not match the value of the current instance.
	 *
	 * @since 		1.0
	 * @return		@c true if the value of the specified instance of %ImAddress is not equal to the value of the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %ImAddress
	 */
	bool operator !=(const ImAddress& rhs) const;

	// Operations
public:
	/**
	 * Gets the service provider name of the IM address.
	 *
	 * @since 		1.0
	 * @return		The service provider name of the IM address
	 */
	Osp::Base::String GetServiceProviderName(void) const;

	/**
	 * Gets the IM address of the current instance of %ImAddress.
	 *
	 * @since 		1.0
	 * @return		The IM address
	 */
	Osp::Base::String GetImAddress(void) const;

	/**
	 * Sets the service provider name of the IM address.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	serviceProviderName		The service provider name of the IM address
	 * @see			#IM_MSN, #IM_ICQ, #IM_AIM, #IM_YAHOO, #IM_JABBER, #IM_GTALK, #IM_SKYPE, #IM_QQ
	 */
	void SetServiceProviderName(const Osp::Base::String& serviceProviderName);

	/**
	 * Sets the IM address of the current instance of %ImAddress.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	imAddress			The IM address
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c imAddress is an empty string, or @n
	 *									the length of the specified @c imAddress string exceeds #MAX_IM_ADDRESS_LENGTH.
	 */
	result SetImAddress(const Osp::Base::String& imAddress);

private:
	Osp::Base::String __serviceProviderName;
	Osp::Base::String __imAddress;
       
	friend class ImAddressEx;
	class ImAddressEx * __pImAddressEx;

}; // ImAddress


};};// Osp::Social

#endif//_FSCL_IM_ADDRESS_H_


