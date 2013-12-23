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
 * @file		FNetIPHostEntry.h 
 * @brief		This is the header file for the %IpHostEntry class.
 *
 * This header file contains the declarations of the %IpHostEntry class.
 */
#ifndef _FNET_IP_HOST_ENTRY_H_
#define _FNET_IP_HOST_ENTRY_H_

// Includes
#include "FBaseObject.h"
#include "FBaseResult.h"
#include "FBaseString.h"
#include "FBaseColIList.h"
#include "FNetSockSocketTypes.h"


namespace Osp { namespace Net {
// Forward declaration
typedef struct __NetIpHostInfo NetIpHostInfo;

/**
 * @class	IpHostEntry 
 * @brief	This class encapsulates the Internet host address information.
 * @since	1.0
 *
 * 	The %IpHostEntry class associates a Domain Name System (DNS) host name with a list of aliases and matching IP addresses. If the specified host has 
 * 			multiple entries in the DNS database, %IpHostEntry contains multiple IP addresses and aliases. The %IpHostEntry class is used as a helper class 
 *			with the Dns class. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/domain_name_system_access.htm">Domain Name System Access</a>.
 *
 * The following example demonstrates how to use the %IpHostEntry class.
 *
 * @code
// Dns event handler.
class MyDnsListener
	:public IDnsEventListener
{
public:
	void OnDnsResolutionCompletedN(IpHostEntry* ipHostEntry, result r);
};


void MyDnsListener::OnDnsResolutionCompletedN(IpHostEntry* ipHostEntry, result r)
{
	if (ipHostEntry == null)
	{
		AppLog("error case no.%d \n", r);
	}
	else
	{
		Osp::Base::Collection::IList* addressList = ipHostEntry->GetAddressList();

		if (addressList != null)
		{
			int count = addressList->GetCount();

			for (int i=0; i < count; i++)
			{
				IpAddress* pIpAddress = (IpAddress*)(addressList->GetAt(i));
				Osp::Base::ByteBuffer*_pbb = Osp::Base::Utility::StringUtil::StringToUtf8N(pIpAddress->ToString());

				AppLog("IpAddress no.%d : %s\n", i, (char*)(_pbb->GetPointer()));
				delete _pbb;
			}
		}

		Osp::Base::Collection::IList* aliasList = ipHostEntry->GetAliasList();

		if (aliasList != null)
		{
			int count = aliasList->GetCount();

			for (int i=0; i < count; i++)
			{
				String* alias = (String*)(aliasList->GetAt(i));
				Osp::Base::ByteBuffer*_pbb = Osp::Base::Utility::StringUtil::StringToUtf8N(*alias);

				AppLog("alias no.%d : %s\n", i, (char*)(_pbb->GetPointer()));
				delete _pbb;
			}
		}
		delete ipHostEntry;
	}
}
 * @endcode
 */
class _EXPORT_NET_ IpHostEntry :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during the certification process.
	 *
	 * Initializes the calling instance with the specified NetIpHostInfo data.
	 *
	 * @since	  	1.0
	 * @param[in]	netIpHostInfo 		The raw IP address and the alias list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		Insufficient memory.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * 
	 * @remarks 	  The GetLastResult() method is used to check whether the IpHostEntry instance is created successfully. 
	 */
	IpHostEntry(const Osp::Net::NetIpHostInfo& netIpHostInfo);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~IpHostEntry(void);


// Accessor
public:	
	/**
	 * Gets the IP address list of a domain name.
	 *
	 * @since		1.0
	 * @return		An IEnumerator whose element is of the type IpAddress*, @n
	 *				else @c null if the object is not constructed or addressList is not set
	 */
	Osp::Base::Collection::IList* GetAddressList(void) const;

	/**
	 * Gets the alias list of a domain name.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                	For more information, see @ref GetAliasListPage1 "here".
	 *
	 * @return			An IEnumerator whose element is of the type String*, @n
	 *					else @c null if the object is not constructed or aliasList is not set
	 */
	Osp::Base::Collection::IList* GetAliasList(void) const;

    /**
     * @page		GetAliasListPage1	Compatibility for GetAliasList()
     *
     * @section		GetAliasListPage1IssueSection	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# This method does not work properly.
     *
     * @section		GetAliasListPage1ResolutionSection	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
    */

// Lifecycle
private:
	IpHostEntry(void);

// Operation
private:
	/*
	 * Sets the IP address list of a domain name.
	 *
	 * @return		An error code
	 * @param[in]	addressList				A list of IP addresses associated with a domain name
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c pAddressList is @c null.	
	 */
	result  SetAddressList(const Osp::Base::Collection::IList& addressList);

	/*
	 * Sets the alias list of a domain name.
	 *
	 * @return		An error code
	 * @param[in]	aliaseList				A list of aliases associated with a domain name
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c pAliaseList is @c null.	
	 */
	result  SetAliasList(const Osp::Base::Collection::IList& aliasList);


// Lifecycle
private:
	/*
	 * This is the copy constructor for the IpHostEntry class. @n
	 * Do @b not use directly.
	 *
	 * @param[in]	value		An instance of %IpHostEntry
	 */	
	IpHostEntry(const IpHostEntry& value);


// Operation
private:
	/* 
	 * This is the assignment operator. 
	 * Do @b not use directly.
	 *
	 * @param[in]	rhs			An instance of %IpHostEntry
	 */
	IpHostEntry& operator =(const IpHostEntry& rhs);


// Attribute
private:
	Osp::Base::Collection::IList* __pAddressList;
	Osp::Base::Collection::IList* __pAliasList;
	bool __isConstructed;


// Friend class
	friend class Dns;
	friend class __DnsEvent;

	friend class IpHostEntryEx;
	class IpHostEntryEx* __pIpHostEntryEx;
};

}; }; // Osp::Net
#endif // _FNET_IP_HOST_ENTRY_H_

