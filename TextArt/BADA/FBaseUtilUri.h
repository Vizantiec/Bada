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
 * @file		FBaseUtilUri.h 
 * @brief		This is the header file for the %Uri class.
 *
 * This header file contains the declarations of the %Uri class.
 */
#ifndef _FBASE_UTIL_URI_H_
#define _FBASE_UTIL_URI_H_

// Includes
#include "FBaseObject.h"
#include "FBaseString.h"
#include "FBaseBuffer.h"


namespace Osp { namespace Base { namespace Utility {

/**
 * @class	Uri
 * @brief	This class provides useful methods for URI.
 * @since	1.0
 *
 * The %Uri class represents a Uniform Resource Identifier (URI) as defined by RFC2396 and provides accessors 
 * which access the URI component.
 * It also provides methods for creating, accessing, normalizing, resolving, and relativizing %Uri instances.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/uri.htm">URI</a>.
 *
 * The following example demonstrates how to use the %Uri class.
 *
 * @code
 *
 * // includes
 * #include <FBase.h>
 *
 * // namespace
 * using namespace Osp::Base;
 * using namespace Osp::Base::Utility;
 *
 * void
 * MyClass::UriSample(void)
 * {
 *		String base(L"http://www.samsung.com");
 *		String against(L"/osp/framework/index.html");
 *		String resolveString(L"http://www.samsung.com/osp/framework/index.html");
 *
 *		Uri baseUri;
 *		baseUri.SetUri(base);
 *
 *		Uri againstUri;
 *		againstUri.SetUri(against);
 *
 *	
 *		// Resolve
 *		Uri resultUri;
 *		baseUri.Resolve(againstUri, resultUri);
 *
 *		String resultString = resultUri.ToString();		
 *		if (resultString.Equals(resolveString))		// true
 *		{
 *			...
 *		}
 *
 * }
 * @endcode
 */
class _EXPORT_BASE_ Uri :
	public Osp::Base::Object
{
// life-cycle
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	Uri(void); 


	/** 
	 *	This is the copy constructor for the %Uri class.
	 *
	 *	@since			1.0
	 *  @param[in]	uri		An instance of %Uri to be copied
	 */
	Uri(const Uri& uri); 


	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Uri(void); 


	/**
	 * Sets the current %Uri instance to the value of the specified instance of %Uri.
	 *
	 * @since			1.0
	 * @param[in]	uri		An instance of %Uri
	 */
	void SetUri(const Uri& uri);


	/**
	 * Sets the current %Uri instance by parsing a given string.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	str		A string to be parsed into a URI
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c str is an empty string.
	 * @exception	E_INVALID_FORMAT		@c str violates the URI syntax (RFC 2396).
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result SetUri(const Osp::Base::String& str);


	/**
	 * Sets an absolute %Uri instance with given components.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	scheme			The scheme
	 * @param[in]	ssp				The scheme-specific-part
	 * @param[in]	fragment		The fragment
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_FORMAT		A component violates the URI syntax(RFC 2396).
	 */
	result SetUri(const Osp::Base::String& scheme, 
		const Osp::Base::String& ssp, const Osp::Base::String& fragment);


	/**
	 * Sets an absolute and hierarchical %Uri instance with the given components. 
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompUriSetUriWithHostPage "here".
	 *
	 * @return		An error code
	 * @param[in]	scheme			The scheme
	 * @param[in]	userInfo		The user name and authorization
	 * @param[in]	host			The host name
	 * @param[in]	port			The port number
	 * @param[in]	path			The path
	 * @param[in]	query			The query
	 * @param[in]	fragment		The fragment
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_FORMAT		A component violates the URI syntax(RFC 2396).
	 */
	result SetUri(const Osp::Base::String& scheme, 
		const Osp::Base::String& userInfo, const Osp::Base::String& host, 
		int port, const Osp::Base::String& path, const Osp::Base::String& query, 
		const Osp::Base::String& fragment);


	/**
	* @page				CompUriSetUriWithHostPage Compatibility for SetUri()
	* @section			CompUriSetUriWithHostPageIssueSection Issues
	*					Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	*
	*	-# When the host parameter contains "--" in it, this method returns E_INVALID_FORMAT exception instead of E_SUCCESS
	*
	* @section			CompUriSetUriWithHostPageSolutionSection Resolutions
	*
	* The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	*/
	

	/**
	 * Sets an absolute and hierarchical %Uri instance with the given components. 
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	scheme			The scheme
	 * @param[in]	host			The host name
	 * @param[in]	path			The path
	 * @param[in]	fragment		The fragment
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_FORMAT		A component violates the URI syntax(RFC 2396).
	 * @remarks	The authority and query component are left empty, and the port is set to @c -1.
	 */
	 result SetUri(const Osp::Base::String& scheme,
		const Osp::Base::String& host, const Osp::Base::String& path, 
		const Osp::Base::String& fragment);


	/**
	 * Sets an absolute and hierarchical %Uri instance with the given components. 
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	scheme			The scheme
	 * @param[in]	authority		The authority
	 * @param[in]	path			The path
	 * @param[in]	query			The query
	 * @param[in]	fragment		The fragment
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_FORMAT		A component violates the URI syntax(RFC 2396).
	 */
	 result SetUri(const Osp::Base::String& scheme, const Osp::Base::String& authority,
		const Osp::Base::String& path, const Osp::Base::String& query, 
		const Osp::Base::String& fragment);


// Operator
public:
	/** 
	 * This operator assigns the value of the specified %Uri instance to the calling instance.
	 *
	 * @since			1.0
	 * @return		A reference to the calling instance
	 * @param[in]	rhs		An instance of %Uri to assign
	 */
	Uri& operator =(const Uri& rhs);


// Accessor	
public:
	/** 
	 * Gets the value of the authority component. 
	 *
	 * @since			1.0
	 * @return		The value of the authority component, @n
	 *				else an empty string if the authority component is undefined
	 * @remarks		The string returned by this method is equal to the string returned by GetEncodedAuthority(),
	 *				except that all sequences of the escaped octets are decoded.
	 */
	Osp::Base::String GetAuthority(void) const;


	/**
	 * Gets the value of the fragment component.
	 *
	 * @since			1.0
	 * @return		The value of the fragment component, @n
	 *				else an empty string if the fragment component is undefined
	 * @remarks		The string returned by this method is equal to the string returned by GetEncodedFragment(),
	 *				except that all sequences of the escaped octets are decoded.
	 */
	Osp::Base::String GetFragment(void) const;


	/**
	 * Gets the value of the host component. 
	 *
	 * @since			1.0
	 * @return		The value of the host component, @n
	 *				else an empty string if the host component is undefined
	 */
	Osp::Base::String GetHost(void) const;


	/**
	 * Gets the value of the path component.
	 *
	 * @since			1.0
	 * @return		The value of the path component, @n
	 *				else an empty string if the path component is undefined
	 * @remarks		The string returned by this method is equal to the string returned by GetEncodedPath(),
	 *				except that all sequences of the escaped octets are decoded.
	 */
	Osp::Base::String GetPath(void) const;


	/**
	 * Gets the value of the port component.
	 *
	 * @since			1.0
	 * @return		The value of the port component, @n
	 *				else @c -1 if the port component is undefined
	 */
	int GetPort(void) const;


	/**
	 * Gets the value of the query component.
	 *
	 * @since			1.0
	 * @return		The value of the query component, @n
	 *				else an empty string if the query component is undefined
	 * @remarks		The string returned by this method is equal to the string returned by GetEncodedQuery(),
	 *				except that all sequences of the escaped octets are decoded.
	 */
	Osp::Base::String GetQuery(void) const;


	/**
	 * Gets the value of the scheme component.
	 *
	 * @since			1.0
	 * @return		The value of the query scheme, @n
	 *				else an empty string if the query scheme is undefined
	 */
	Osp::Base::String GetScheme(void) const;


	/**
	 * Gets the value of the scheme-specific-part component.
	 *
	 * @since			1.0
	 * @return		The value of the scheme-specific-part component, @n
	 *				else an empty string if the scheme-specific-part component is undefined
	 * @remarks		The string returned by this method is equal to the string returned by GetEncodedSchemeSpecificPart(),
	 *				except that all sequences of the escaped octets are decoded.
	 */
	Osp::Base::String GetSchemeSpecificPart(void) const;


	/**
	 * Gets the value of the user-info component.
	 *
	 * @since			1.0
	 * @return		The value of the user-info component, @n
	 *				else an empty string if the user-info component is undefined
	 * @remarks		The string returned by this method is equal to the string returned by GetEncodedUserInfo(),
	 *				except that all sequences of the escaped octets are decoded.
	 */
	Osp::Base::String GetUserInfo(void) const;


	/**
	 * Gets the encoded value of the authority component. @n
	 * The non-US-ASCII characters in the authority component are encoded to escaped octets.
	 *
	 * @since			1.0
	 * @return		The encoded value of the authority component, @n
	 *				else an empty string if the authority component is undefined
	 */
	Osp::Base::String GetEncodedAuthority(void) const;


	/**
	 * Gets the encoded value of the fragment component. @n
	 * The non-US-ASCII characters in the fragment component are encoded to escaped octets.
	 *
	 * @since			1.0
	 * @return		The encoded value of the fragment component, @n
	 *				else an empty string if the fragment component is undefined
	 */
	Osp::Base::String GetEncodedFragment(void) const;


	/**
	 * Gets the encoded value of the path component. @n
	 * The non-US-ASCII characters in the path component are encoded to escaped octets.
	 *
	 * @since			1.0
	 * @return		The encoded value of the path component, @n
	 *				else an empty string if the path component is undefined
	 */
	Osp::Base::String GetEncodedPath(void) const;


	/**
	 * Gets the encoded value of the query component. @n
	 * The non-US-ASCII characters in the query component are encoded to escaped octets.
	 *
	 * @since			1.0
	 * @return		The encoded value of the query component, @n
	 *				else an empty string if the query component is undefined
	 */
	Osp::Base::String GetEncodedQuery(void) const;


	/**
	 * Gets the encoded value of the scheme-specific-part component. @n
	 * The non-US-ASCII characters in the scheme-specific-part component are encoded to escaped octets.
	 *
	 * @since			1.0
	 * @return		The encoded value of the scheme-specific-part component, @n
	 *				else an empty string if the scheme-specific-part component is undefined
	 */
	Osp::Base::String GetEncodedSchemeSpecificPart(void) const;

	/**
	* Returns the encoded value of a user-info component, 
	* or returns an empty string if the user-info component is undefined. @n
	* The non-US-ASCII characters in the user-info component are encoded to escaped octets.
	*
	* @since		1.0
 	* @return		The encoded value of user-info, @n
	*				else an empty string if the user-info component is undefined
	*/
	Osp::Base::String GetEncodedUserInfo(void) const;


	/**
	 * Checks whether the current %Uri instance is an absolute URI.
	 *
	 * @since			1.0
	 * @return		@c true if the current %Uri instance is an absolute URI, @n
	 *				else @c false
	 */
	bool IsAbsolute(void) const;


	/**
	 * Checks whether the calling %Uri instance is an opaque URI.
	 *
	 * @since			1.0
	 * @return		@c true if the current %Uri instance is an opaque URI, @n
	 *				else @c false
	 */
	bool IsOpaque(void) const;


	/**
	 * Gets the encoded US-ASCII string.
	 *
	 * @since			1.0
	 * @return		The encoded US-ASCII string
	 * @remarks		If this URI does not contain any non US_ASCII characters, 
	 *				then the string returned by this method is equal to the string returned by ToString().
	 *
	 * The following example demonstrates how to use this method.
	 * 
	 * @code
	 * String str(L"http://www.sec.com/osp?currency==\u20ac");
	 *
	 *	 Uri uri;
	 *	 uri.SetUri(str);
	 *
	 *	 String encode = uri.GetEncodedString();	// encode == L"http://www.sec.com/osp?currency==%E2%82%AC"
	 *
	 * @endcode
	 */
	Osp::Base::String GetEncodedString(void) const;


// Operation
public:
	/** 
	 * Compares the calling URI instance to the specified %Uri instance. @n
	 * When comparing corresponding components of two URIs, if one component in the current instance is undefined
	 * but the other is defined, then the current instance is considered to be less than the given object.
	 *
	 * @since			1.0
	 * @return		The result of the comparison
	 * @code
	 * < 0	if the current instance is less than the given object
	 * = 0	if the current instance is equal to the given object
	 * > 0	if the current instance is greater than the given object
	 * @endcode
	 * @param[in]	uri			An instance of %Uri
	 *
	 *
	 * @remarks
	 *
	 * Ordering of URIs
	 * 1. Scheme  
	 *    Two URIs are ordered according to the ordering of schemes, without regard to case. 
	 * 2. Hierarchical URI vs. Opaque URI 
	 *    A hierarchical URI is less than an opaque URI if they have an identical scheme.
	 * 3. Scheme-specific-part 
	 *    If two opaque URIs have an identical scheme, they are ordered according to  
	 *    the scheme-specific-part, without regard to %case. 
	 * 4. Fragment 
	 *    If two opaque URIs have identical schemes and scheme-specific-parts, they are ordered according 
	 *    to the ordering of fragments, without regard to case. 
	 * 5. Authority 
	 *    If two hierarchical URIs have identical schemes, they are ordered according to the authority, 
	 *    without regard to the case. 
	 *       5-1. Server-based authority 
	 *             If two URIs are server-based, they are ordered according to their user-information,
	 *             without regard to case. 
	 *             If the hosts are identical, then the URIs are ordered according to the ordering of ports. 
	 * 6. Path 
	 *    If two hierarchical URIs have identical schemas and authority components, they are ordered according to the 
	 *    ordering of paths, without regard to the case. 
	 *    If their paths are identical, their queries are compared. And if the queries are the same, then their fragments 
	 *    are compared.
	 * 
	 */ 
	int CompareTo(const Uri& uri) const;


	/**
	 *	Compares the specified instance to the current instance. 
	 *
	 *  @since		1.0
	 *	@return		@c true if the two instances are equal, @n
	 *				else @c false
	 *	@param[in]	obj	The object to compare with the current instance
	 *	@remarks 	Two equal instances should return the same hash value. The default 
	 *				implementation of this method returns @c true if two instances 
	 *				have the same address.
	 *				@par
	 *				The method can be overridden to support value equality. Furthermore, the Equals()
	 *				method must return the same results as the equality operator.
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const;


	/** 
	 *	Gets the hash value of the current instance.
	 *
	 *  @since		1.0
	 *	@return		The hash value of the current instance
	 *	@remarks 	Two equal instances should return the same hash value. For better performance, 
	 *				the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;


	/**
	 * Normalizes the current URI.
	 *
	 * @since			1.0
	 * @return		The normalized URI, @n
	 *				else the current URI in case any error occurs
	 *
	 * @remarks	Normalization is the process of removing unnecessary "." and ".." segments from the path component of the 
	 *			hierarchical URI. All "." segments are removed and If a ".." segment is preceded by a non-".." segment,  
	 *			both of these segments are removed. If a URI is opaque, the normalization has no effect.
	 *
	 * The following example demonstrates how to use this method.
	 *
	 * @code	
	 *	 Uri uri1;
	 *	 uri1.SetUri(L"http://www.example.com/a/b/../c/./d.html");
	 *
	 *	 Uri uriNormalized = uri1.Normalize();
	 *	 String uriStr = uriNormalized.ToString();		// uriStr == L"http://www.example.com/a/c/d.html"
	 *
	 * @endcode
	 */
	Uri Normalize(void);


	/**
	 * Parses the server-based authority component, if defined. 
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]	uri					The parsed URI
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_FORMAT	The authority component is defined but cannot be parsed as a server-based authority.
	 * @remarks		This method is provided because the generic URI syntax cannot always distinguish a malformed server-based authority from a legitimate registry-based authority. 
	 *				For example, the authority component in the URI string "//foo:bar/" is not a legal 
	 *				server-based authority but it is legal as a registry-based authority.
	 */
	result ParseAuthority(Uri& uri);


	/**
	 * Relativizes the specified %Uri instance against the calling %Uri instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	uri					The %Uri to be relativized against the calling %Uri
	 * @param[out]	resultUri			The relativized URI
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		Relativization is the opposite of Resolution. It is used 
	 *				to divide a URI into the base URI and the relative URI. 
	 */
	result Relativize(const Uri& uri, Uri& resultUri);


	/**
	 * Resolves the specified %Uri instance against the calling %Uri instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	uri					The URI to be resolved against this URI
	 * @param[out]	resultUri			The resolved URI
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		Resolution is the process of resolving a URI against another, base URI. For hierarchical URI, 
	 *				the path of the original is resolved against the path of the base URI and then normalized. @n
	 * 
	 *				For example, To resolve the URI "/osp/framework/index.html" against the base URI "http://www.samsung.com" ,
	 *				the resultant URI is "http://www.samsung.com/osp/framework/index.html". 
	 * 
	 */
	result Resolve(const Uri& uri, Uri& resultUri);


	/**
	 * Sets the authority component to the specified String instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	authority			The authority
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The specified string is invalid.
	 */
	result SetAuthority(const Osp::Base::String& authority);

	
	/**
	 * Sets the fragment component to the specified String instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	fragment			The new fragment 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The specified string is invalid.
	 */
	result SetFragment(const Osp::Base::String& fragment);

	
	/**
	 * Sets the host component to the specified String instance.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompUriSetHostPage "here".
	 *
	 * @return		An error code
	 * @param[in]	host				The new host 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The specified string is invalid.
	 */
	result SetHost(const Osp::Base::String& host);


	/**
	* @page				CompUriSetHostPage Compatibility for SetHost()
	* @section			CompUriSetHostPageIssueSection Issues
	*					Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	*
	*	-# When the host parameter contains "--" in it, this method returns E_INVALID_FORMAT exception instead of E_SUCCESS
	*
	* @section			CompUriSetHostPageSolutionSection Resolutions
	*
	* The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	*/
	
	
	/**
	 * Sets the path component to the specified String instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	path				The new path component
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The specified string is invalid.
	 */
	result SetPath(const Osp::Base::String& path);

	
	/**
	 * Sets the port component to a given integer.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	port				The new port component 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c port is negative.
	 */
	result SetPort(int port);

	
	/**
	 * Sets the query component to the specified String instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	query				The new query string
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The specified string is invalid.
	 */
	result SetQuery(const Osp::Base::String& query);

	
	/**
	 * Sets the scheme component to the specified String instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	scheme				The new scheme 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The specified string is invalid.
	 */
	result SetScheme(const Osp::Base::String& scheme);

	
	/**
	 * Sets the scheme-specific-part component to the specified String instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	ssp					The new scheme-specific-part component
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The specified string is invalid.
	 */
	result SetSchemeSpecificPart(const Osp::Base::String& ssp);

	
	/**
	 * Sets the user-info component to the specified String instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	userInfo			The new user-info string
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The specified string is invalid.
	 */
	result SetUserInfo(const Osp::Base::String& userInfo);


	/**
	 * Gets the content of the calling %Uri instance as a string containing escaped octets.
	 *
	 * @since			1.0
	 * @return		The content of this URI as a string containing escaped octets
	 */
	Osp::Base::String ToString(void) const;


// Operations
private:
	/*
	 * Constructs an Uri instance with the given components.
	 * scheme, ssp(opaquePart), authority, user-info, host, port, path, query, fragment
	 */
	result SetUri(const Osp::Base::String& scheme, const Osp::Base::String& opaque,
		const Osp::Base::String& authority, const Osp::Base::String& userInfo,
		const Osp::Base::String& host, int port, const Osp::Base::String& path,
		const Osp::Base::String& query, const Osp::Base::String& fragment);

	
	/*
	 * Appends a given scheme-specific-part to a String.
	 */
	result AppendSchemeSpecificPart(Osp::Base::String& strbuf, const Osp::Base::String& opaque, 
		const Osp::Base::String& authority, const Osp::Base::String& userInfo, 
		const Osp::Base::String& host, int port, const Osp::Base::String& path,
		const Osp::Base::String& query) const;

	/*
	 * Appends a given fragment to a String.
	 */
	result AppendFragment(Osp::Base::String& strbuf, const Osp::Base::String& fragment) const;


	/*
	 * Appends a given authority component to a String.
	 */
	result AppendAuthority(Osp::Base::String& strbuf, const Osp::Base::String& authority, 
		const Osp::Base::String& userInfo, const Osp::Base::String& host, int port) const;

	/*
	 * Parses a given URI string.
	 */
	result ParseUri(const Osp::Base::String& str);

	/*
	 * Copies a given URI.
	 */
	result CopyUri(const Uri& uri);

	/*
	 * Encodes all components - authority, fragment, path, query, and ssp.
	 */
	void EncodeAllComponent(void);


	/*
	 * Parses a hierarchical URI string.
	 * @return		The start index of the fragment. If the operation fails, @c -1 is returned.
	 * @param[in]	startSsp			The start index of scheme-specific-part
	 * @param[in] lengthOfUri		The length of the URI string
	 * @param[out] authority	A parsed authority component
	 * @param[out] path			A parsed path component
	 * @param[out] query			A parsed query component
	 */
	result ParseHierarchicalUri(const Osp::Base::String& str, int startSsp, Osp::Base::String& authority, 
		Osp::Base::String& path, Osp::Base::String& query, int& index);


	/*
	* Parses a server_based authority component.
	* server_based authority: [user-info@]<host>[:port]
	*/
	result ParseAuthority(const Osp::Base::String& str, int curIndex, Osp::Base::String& newAuth, 
		Osp::Base::String& userInfo, Osp::Base::String& host, int& port);

	void SetAndEncodeAuthority(const Osp::Base::String& authority, 
		const Osp::Base::String& path, const Osp::Base::String& query);

	/*
	 * Parses a server_based authority component.
	 * Assigns user-info, host and port to their member variable.
	 */
	result ParseServerAuthority(const Osp::Base::String& str, Osp::Base::String& user, Osp::Base::String& host, int& port);


	/*
	 * Parses an IPv4 address.
	 */
	result ParseIPv4(const Osp::Base::String& str, int index, int& count);

	/*
	 * Parses an IPv6 address.
	 * It will be implemented.
	 */
	result ParseIPv6(const Osp::Base::String& ip6, Osp::Base::String& outIpv6);

	/*
	 * Parses a host name and returns a host name as an out-param.
	 */
	result ParseHostName(const Osp::Base::String& str, int index, Osp::Base::String& host);
	

	/*
	 * These methods verify components. 
	 * If a given component is valid, return @c true, else, @c false.
	 * @param[in]	str		A component
	 */
	bool VerifyScheme(const Osp::Base::String& str) const;
	bool VerifyAuthority(const Osp::Base::String& str) const;
	bool VerifyHost(const Osp::Base::String& str) const;
	bool VerifyPath(const Osp::Base::String& str) const;
	bool VerifyUserInfo(const Osp::Base::String& str) const;
	bool VerifyUriChar(const Osp::Base::String& str) const;


	/*
	 * Checks that a given string only consists of server_based characters.
	 * @return		@c true if a string consists of only server_based characters, @n
					else @c false
	 */
	bool VerifyServerAuthority(const Osp::Base::String& str) const;

	/*
	 * Checks that a given string only consists of registry_based characters.
	 * @return		@c true if a string consists of only registry_based characters, @n
					else @c false
	 */
	bool VerifyRegistryAuthority(const Osp::Base::String& str) const;

	/*
	 * Checks whether a given char is a user-info character or not.
	 * user-info char: alphabet, digit, -_.!~*'(), ;:&=+$,
	 */
	bool IsUserInfo(mchar mch) const;

	/*
	 * Returns true if a given mchar is a mark character.
	 * mark char: -_.!~*'()
	 */
	bool IsMark(mchar mch) const;

	/*
	 * Returns true if two given mchars are hexadecimals.
	 */
	bool IsEscapedChar(mchar ch1, mchar ch2) const;

	/*
	 * Returns true if a given string is already encoded.
	 */
	bool IsEncoded(const Osp::Base::String& str) const;

	/*
	 * Returns true if a given mchar is an ISO control character.
	 */
	bool IsControlChar(mchar ch) const;

	/*
	 * Compares @c pStr1 with @c pStr2. @n
	 * If @c pStr1 is greater than @c pStr2, returns @c 1.
	 * If two strings are the same, return @c 0.
	 * If @c pStr1 is less than @c pStr2, returns @c -1.
	 */
	int Compare(const Osp::Base::String& pStr1, const Osp::Base::String& pStr2) const;


	/*
	 * Adds leading dots.
	 * If the normalized path is relative, and if the first segment could be parsed as a scheme name,
	 * then prepend a '.' segment
	 */
	void AddLeadingDot(Osp::Base::McharBuffer& path, int* segments, int numSegments);

	/*
	 * Finds the first character in stopString.
	 * If there is not a character in stopString, the last index is returned.  
	 */
	int Scan(const Osp::Base::String& str, int start, const Osp::Base::String& stopString);


// Normalization
	/*
	 * Normalizes a given string and removes unnecessary dots.
	 */
	Osp::Base::String InternalNormalize(const Osp::Base::String& path);

	/*
	 * Returns the number of segments from a given path.
	 */
	int GetNumberOfSegments(const Osp::Base::String& path);

	
	/* Join the segments in the given path according to the given segment-index array, 
	 * ignoring those segments whose index entries have been set to @c -1, and inserting slashes as needed.  
     * Return the length of the resulting path.
	 *  
	 * Preconditions:
	 *   segs[i] == @c -1 implies segment i is to be ignored
	 *   path computed by split, as above, with '\0' having replaced '/'
	 *
	 * Postconditions:
	 *   path[0] .. path[return value] == Resulting path
	 */
	int Join(Osp::Base::McharBuffer& path, int* segments, int numSegment);


	/*
	 * Removes unnecessary dots and segment pairs consisting of a non-".." segment 
	 * followed by a ".." segment
	 */
	void RemoveDots(const Osp::Base::McharBuffer& mb, int* segments, int numSegments, int length);


	/*
	 * Splits a path component into segments.
	 */
	void SplitIntoSegments(Osp::Base::McharBuffer& mb, int* segments, int numSegments);


// Resolution
	/*
	 * Implements Uri resolution in RFC2396 5.2
	 */
	result Resolve(const Uri& baseUri, const Uri& childUri, Uri& resultUri);

	/*
	 * Resolves the path of the base and child URI.
	 */
	Osp::Base::String ResolvePath(const Osp::Base::String& path, 
		const Osp::Base::String& resolve, bool isAbsolute);


// Relativize

	bool EqualsComponent(const Osp::Base::String &comp1, const Osp::Base::String &comp2);
	result Relativize(const Uri& baseUri, const Uri& childUri, Uri& resultUri);

	/*
	 * Converts a component represented by UTF8 to a component represented by Unicode.
 	 */
	Osp::Base::String Decode(const Osp::Base::String& str);


	/*
	 * Converts a component represented by Unicode to a component represented by UTF8.
	 */
	Osp::Base::String Encode(const Osp::Base::String& str) const;

	static result AppendEscape(Osp::Base::String& strbuf, byte b);


	/*
	 * Clears the current instance.
	 */
	void Clear(void);


	// Component
	Osp::Base::String __scheme;
	Osp::Base::String __ssp; // Scheme-specific-part
	Osp::Base::String __authority;
	Osp::Base::String __host;
	Osp::Base::String __fragment;
	Osp::Base::String __path;
	Osp::Base::String __userInfo;	
	Osp::Base::String __query;
	Osp::Base::String __ipv4;
	Osp::Base::String __ipv6;

	// Encoded Component
	Osp::Base::String __encodedAuth;
	Osp::Base::String __encodedFragment;
	Osp::Base::String __encodedPath;
	Osp::Base::String __encodedQuery;
	Osp::Base::String __encodedSsp;
	Osp::Base::String __encodedUserInfo;

	int __port;
	bool __hasScheme;

	int __ipv6ByteCount;


private:
	friend class UriEx;
	class UriEx* __pUriEx;
};	// Uri
}; }; }; // Osp::Base::Utility
#endif //_FBASE_UTIL_URI_H_

