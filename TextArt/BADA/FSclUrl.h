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
* @file		FSclUrl.h
* @brief	This is the header file for the %Url class.
*
* This header file contains the declarations of the %Url class.
*/
#ifndef _FSCL_URL_H_
#define _FSCL_URL_H_

// Includes
#include "FBaseResult.h"
#include "FBaseString.h"
#include "FSclConfig.h"

namespace Osp { namespace Social {

// Enums and Constants
/**
* Defines the types of URL.
*
* @since 	1.0
*/
enum UrlType {
	URL_TYPE_PERSONAL,	/**< The URL type is Personal */
	URL_TYPE_WORK,		/**< The URL type is Work */
	URL_TYPE_OTHER		/**< The URL type is Other */
};

/**
 * The maximum length of the URL property.
 *
 * @since 	1.0
 */
static const int MAX_URL_LENGTH					= 100;

/**
* @class	Url 
* @brief	This class stores the information of a URL.
* @since	1.0
*
* @remarks	The %Url class consists of a URL string and a URL type.
*
* The %Url class stores the information of a URL. @n
* The following example demonstrates how to use the %Url class.
*
* @code
using namespace Osp::Base;
using namespace Osp::Social;

void
MyClass::SomeMethod(void)
{	
	result r = E_SUCCESS;
	// Creates an instance of Url.
	Url url = Url();

	// Sets the URL.
	r = url.SetUrl(L"http://developer.bada.com");
	if (IsFailed(r)) {
		return r;
	}

	// Sets the type.
	url.SetType(URL_TYPE_WORK);

	return E_SUCCESS;
}
* @endcode
*/
class  _EXPORT_SOCIAL_ Url:
	public Osp::Base::Object
{
	// Construct Operation
public:
	/**
	* This is the default constructor for this class.
	*
	* @since 			1.0
	*/
	Url(void);

	/**
	* Initializes this instance with the specified URL string and type.
	*
	* @since 		1.0
	* @param[in]	type	The type of the URL
	* @param[in]	url		The URL
	*/
	Url(UrlType type, const Osp::Base::String& url);

	/**
	* This is the copy constructor for the %Url class.
	*
	* @since 		1.0
	* @param[in]	value		An instance of %Url
	*/
	Url(const Url& value);

	/**
	* This is the destructor for this class.
	*
	* @since 		1.0
	*/
	virtual ~Url(void);

public:
	/**
	* Copies the data contained in the specified %Url instance to this instance.
	*
	* @since 		1.0
	* @param[in]	value	The source instance of %Url	
	*/
	Url& operator =(const Url& value);

	/**
	* Checks whether the specified instance is equal to the calling instance.
	*
	* @since 		1.0
	* @return		@c true if the data of the specified instance is equal to the data of the current instance, @n
	*				else @c false
	* @param[in]	rhs		 The source instance of %Url
	*/
	bool operator ==(const Url& rhs) const;

	/** 
	* Compares the specified instance with the calling instance for inequality.
	*
	* @since 		1.0
	* @return		@c true if the data of the specified instance is not equal to the data of the current instance, @n
	*				else @c false
	* @param[in]	rhs		The source instance of %Url
	*/
	bool operator !=(const Url& rhs) const;

	// Operations
public:	
	/** 
	* Gets the type of this %Url instance.
	*
	* @since 	1.0
	* @return	The type of the %Url
	*/
	UrlType GetType(void) const;

	/** 
	* Gets the URL of this %Url instance.
	*
	* @since 	1.0
	* @return	The URL as a string
	*/
	Osp::Base::String GetUrl(void) const;

	/** 
	* Sets the type of this %Url instance.
	*
	* @since 		1.0
	* @param[in]	type	The type of the %Url
	*/
	void SetType(UrlType type);

	/** 
	* Sets the URL of this %Url instance.
	*
	* @since 		1.0
	* @return		An error code
	* @param[in]	url				The URL
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c url is an empty string, or @n
	*								the length of the specified @c url exceeds #MAX_URL_LENGTH.
	*/
	result SetUrl(const Osp::Base::String& url);

private:	
	UrlType __type;
	Osp::Base::String __url;	
	
	friend class UrlEx;
	class UrlEx* __pUrlEx;
}; //Url

};};// Osp::Social

#endif//_FSCL_URL_H_


