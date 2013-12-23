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
 * @file		FNetHttpHttpTypes.h
 * @brief		This is the header file for defining the primitive types for the %HTTP operations.
 *
 * This header file contains the definition of the primitive types for the %HTTP operations.
 */

#ifndef _FNET_HTTP_HTTP_TYPES_H_
#define _FNET_HTTP_HTTP_TYPES_H_

#include "FBaseObject.h"
#include "FBaseColIComparer.h"
#include "FBaseString.h"
#include "FBaseErrorDefine.h"
#include "FBaseColIHashCodeProvider.h"

namespace Osp { namespace Net { namespace Http {

/**
 * @enum 	NetHttpMethod
 * Defines the %HTTP method types. For the detailed description of each method, refer to HttpRequest::SetMethod().
 *
 * @since 1.0
 */
enum NetHttpMethod
{
	NET_HTTP_METHOD_GET		= 0x40,		/**< The HTTP GET Method */
	NET_HTTP_METHOD_OPTIONS	= 0x41,		/**< The HTTP OPTIONS Method */
	NET_HTTP_METHOD_HEAD	= 0x42,		/**< The HTTP HEAD Method */
	NET_HTTP_METHOD_DELETE	= 0x43,		/**< The HTTP DELETE Method */
	NET_HTTP_METHOD_TRACE	= 0x44,		/**< The HTTP TRACE Method */
	NET_HTTP_METHOD_POST	= 0x60,		/**< The HTTP POST Method */
	NET_HTTP_METHOD_PUT		= 0x61,		/**< The HTTP PUT Method */
	NET_HTTP_METHOD_CONNECT	= 0x70,		/**< The HTTP CONNECT Method */
};

/**
 * @enum	NetHttpSessionMode
 * Defines the %HTTP session mode.
 *
 * @since 1.0
 */
enum NetHttpSessionMode
{
	NET_HTTP_SESSION_MODE_NORMAL,		/**< The Normal Mode */
	NET_HTTP_SESSION_MODE_PIPELINING	/**< The Pipelining mode */
};

/**
 * @enum 	NetHttpStatusCode
 * Defines the HTTP status code.
 *
 * @deprecated This enum is deprecated. Instead of using this enum, it is recommended to use the HTTP_STATUS_XXX constants.
 *
 * @since 1.0
 */
enum NetHttpStatusCode
{
	NET_HTTP_STATUS_UNDEFINED						=	0,					/**< The undefined status */
	NET_HTTP_STATUS_CONTINUE						=	100,				/**< The status code: 100 Continue */
	NET_HTTP_STATUS_SWITCHING_PROTOCOLS				=	101,				/**< The status code: 101 Switching Protocols */
	NET_HTTP_STATUS_OK								=	200,				/**< The status code: 200 OK */
	NET_HTTP_STATUS_CREATED							=	201,				/**< The status code: 201 Created */
	NET_HTTP_STATUS_ACCEPTED						=	202,				/**< The status code: 202 Accepted */
	NET_HTTP_STATUS_NON_AUTHORITATIVE_INFORMATION	=	203,				/**< The status code: 203 Non-Authoritative Information */
	NET_HTTP_STATUS_NO_CONTENT						=	204,				/**< The status code: 204 No %Content */
	NET_HTTP_STATUS_RESET_CONTENT					=	205,				/**< The status code: 205 Reset %Content */
	NET_HTTP_STATUS_PARTIAL_CONTENT 				=	206,				/**< The status code: 206 Partial %Content */

	NET_HTTP_STATUS_MULTIPLE_CHOICE					=	300,				/**< The status code: 300 Multiple Choices */
	NET_HTTP_STATUS_MOVED_PERMANENTLY				=	301,				/**< The status code: 301 Moved Permanently */
	NET_HTTP_STATUS_MOVED_TEMPORARILY				=	302,				/**< The status code: 302 Found */
	NET_HTTP_STATUS_SEE_OTHER						=	303,				/**< The status code: 303 See Other */
	NET_HTTP_STATUS_NOT_MODIFIED					=	304,				/**< The status code: 304 Not Modified */
	NET_HTTP_STATUS_USE_PROXY						=	305,				/**< The status code: 305 Use Proxy */

	NET_HTTP_STATUS_BAD_REQUEST						=	400,				/**< The status code: 400 Bad Request */
	NET_HTTP_STATUS_UNAUTHORIZED					=	401,				/**< The status code: 401 Unauthorized */
	NET_HTTP_STATUS_PAYMENT_REQUIRED				=	402,				/**< The status code: 402 Payment Required */
	NET_HTTP_STATUS_FORBIDDEN						=	403,				/**< The status code: 403 Forbidden */
	NET_HTTP_STATUS_NOT_FOUND						=	404,				/**< The status code: 404 Not Found */
	NET_HTTP_STATUS_METHOD_NOT_ALLOWED				=	405,				/**< The status code: 405 Method Not Allowed */
	NET_HTTP_STATUS_NOT_ACCEPTABLE					=	406,				/**< The status code: 406 Not Acceptable */
	NET_HTTP_STATUS_PROXY_AUTHENTICATION_REQUIRED	=	407,				/**< The status code: 407 Proxy Authentication Required */
	NET_HTTP_STATUS_REQUEST_TIME_OUT				=	408,				/**< The status code: 408 Request Timeout (not used) */
	NET_HTTP_STATUS_CONFLICT						=	409,				/**< The status code: 409 Conflict */
	NET_HTTP_STATUS_GONE							=	410,				/**< The status code: 410 Gone */
	NET_HTTP_STATUS_LENGTH_REQUIRED					=	411,				/**< The status code: 411 Length Required */
	NET_HTTP_STATUS_PRECONDITION_FAILED				=	412,				/**< The status code: 412 Precondition Failed */
	NET_HTTP_STATUS_REQUEST_ENTITY_TOO_LARGE		=	413,				/**< The status code: 413 Request Entity Too Large (not used) */
	NET_HTTP_STATUS_REQUEST_URI_TOO_LARGE			=	414,				/**< The status code: 414 Request-URI Too Long (not used) */
	NET_HTTP_STATUS_UNSUPPORTED_MEDIA_TYPE			=	415,				/**< The status code: 415 Unsupported %Media Type */

	NET_HTTP_STATUS_INTERNAL_SERVER_ERROR			=	500,				/**< The status code: 500 Internal Server Error */
	NET_HTTP_STATUS_NOT_IMPLEMENTED					=	501,				/**< The status code: 501 Not Implemented */
	NET_HTTP_STATUS_BAD_GATEWAY						=	502,				/**< The status code: 502 Bad Gateway */
	NET_HTTP_STATUS_SERVICE_UNAVAILABLE				=	503,				/**< The status code: 503 Service Unavailable */
	NET_HTTP_STATUS_GATEWAY_TIME_OUT				=	504,				/**< The status code: 504 Gateway Timeout */
	NET_HTTP_STATUS_HTTP_VERSION_NOT_SUPPORTED		=	505					/**< The status code: 505 HTTP Version Not Supported */
};

/**
 * Status Code: 100 Continue
 *
 * @since 2.0
 */
static const int HTTP_STATUS_CONTINUE						=	100;
/**
 * Status Code: 101 Switching Protocols
 *
 * @since 2.0
 */
static const int HTTP_STATUS_SWITCHING_PROTOCOLS			=	101;

/**
 * Status Code: 200 OK
 *
 * @since 2.0
 */
static const int HTTP_STATUS_OK								=	200;
/**
 * Status Code: 201 Created
 *
 * @since 2.0
 */
static const int HTTP_STATUS_CREATED						=	201;
/**
 * Status Code: 202 Accepted
 *
 * @since 2.0
 */
static const int HTTP_STATUS_ACCEPTED						=	202;
/**
 * Status Code: 203 Non-Authoritative Information
 *
 * @since 2.0
 */
static const int HTTP_STATUS_NON_AUTHORITATIVE_INFORMATION	=	203;
/**
 * Status Code: 204 No %Content
 *
 * @since 2.0
 */
static const int HTTP_STATUS_NO_CONTENT						=	204;
/**
 * Status Code: 205 Reset %Content
 *
 * @since 2.0
 */
static const int HTTP_STATUS_RESET_CONTENT					=	205;
/**
 * Status Code: 206 Partial %Content
 *
 * @since 2.0
 */
static const int HTTP_STATUS_PARTIAL_CONTENT 				=	206;
/**
 * Status Code: 300 Multiple Choices
 *
 * @since 2.0
 */
static const int HTTP_STATUS_MULTIPLE_CHOICE				=	300;
/**
 * Status Code: 301 Moved Permanently
 *
 * @since 2.0
 */
static const int HTTP_STATUS_MOVED_PERMANENTLY				=	301;
/**
 * Status Code: 302 Found
 *
 * @since 2.0
 */
static const int HTTP_STATUS_FOUND							=	302;
/**
 * Status Code: 303 See Other
 *
 * @since 2.0
 */
static const int HTTP_STATUS_SEE_OTHER						=	303;
/**
 * Status Code: 304 Not Modified
 *
 * @since 2.0
 */
static const int HTTP_STATUS_NOT_MODIFIED					=	304;
/**
 * Status Code: 305 Use Proxy
 *
 * @since 2.0
 */
static const int HTTP_STATUS_USE_PROXY						=	305;
/**
 * Status Code: 306 Switch Proxy
 *
 * @since 2.0
 */
static const int HTTP_STATUS_SWITCH_PROXY					=	306;
/**
 * Status Code: 307 Temporary Redirect
 *
 * @since 2.0
 */
static const int HTTP_STATUS_TEMPORARY_REDIRECT				=	307;

/**
 * Status Code: 400 Bad Request
 *
 * @since 2.0
 */
static const int HTTP_STATUS_BAD_REQUEST					=	400;
/**
 * Status Code: 401 Unauthorized
 *
 * @since 2.0
 */
static const int HTTP_STATUS_UNAUTHORIZED					=	401;
/**
 * Status Code: 402 Payment Required
 *
 * @since 2.0
 */
static const int HTTP_STATUS_PAYMENT_REQUIRED				=	402;
/**
 * Status Code: 403 Forbidden
 *
 * @since 2.0
 */
static const int HTTP_STATUS_FORBIDDEN						=	403;
/**
 * Status Code: 404 Not Found
 *
 * @since 2.0
 */
static const int HTTP_STATUS_NOT_FOUND						=	404;
/**
 * Status Code: 405 Method Not Allowed
 *
 * @since 2.0
 */
static const int HTTP_STATUS_METHOD_NOT_ALLOWED				=	405;
/**
 * Status Code: 406 Not Acceptable
 *
 * @since 2.0
 */
static const int HTTP_STATUS_NOT_ACCEPTABLE					=	406;
/**
 * Status Code: 407 Proxy Authentication Required
 *
 * @since 2.0
 */
static const int HTTP_STATUS_PROXY_AUTHENTICATION_REQUIRED	=	407;
/**
 * Status Code: 408 Request Timeout
 *
 * @since 2.0
 */
static const int HTTP_STATUS_REQUEST_TIMEOUT				=	408;
/**
 * Status Code: 409 Conflict
 *
 * @since 2.0
 */
static const int HTTP_STATUS_CONFLICT						=	409;
/**
 * Status Code: 410 Gone
 *
 * @since 2.0
 */
static const int HTTP_STATUS_GONE							=	410;
/**
 * Status Code: 411 Length Required
 *
 * @since 2.0
 */
static const int HTTP_STATUS_LENGTH_REQUIRED				=	411;
/**
 * Status Code: 412 Precondition Failed
 *
 * @since 2.0
 */
static const int HTTP_STATUS_PRECONDITION_FAILED			=	412;
/**
 * Status Code: 413 Request Entity Too Large
 *
 * @since 2.0
 */
static const int HTTP_STATUS_REQUEST_ENTITY_TOO_LARGE		=	413;
/**
 * Status Code: 414 Request-URI Too Long
 *
 * @since 2.0
 */
static const int HTTP_STATUS_REQUEST_URI_TOO_LONG			=	414;
/**
 * Status Code: 415 Unsupported %Media Type
 *
 * @since 2.0
 */
static const int HTTP_STATUS_UNSUPPORTED_MEDIA_TYPE			=	415;
/**
 * Status Code: 416 Requested Range Not Satisfiable
 *
 * @since 2.0
 */
static const int HTTP_STATUS_REQUESTED_RANGE_NOT_SATISFIABLE=	416;
/**
 * Status Code: 417 Expectation Failed
 *
 * @since 2.0
 */
static const int HTTP_STATUS_EXPECTATION_FAILED				=	417;


/**
 * Status Code: 500 Internal Server Error
 *
 * @since 2.0
 */
static const int HTTP_STATUS_INTERNAL_SERVER_ERROR			=	500;
/**
 * Status Code: 501 Not Implemented
 *
 * @since 2.0
 */
static const int HTTP_STATUS_NOT_IMPLEMENTED				=	501;
/**
 * Status Code: 502 Bad Gateway
 *
 * @since 2.0
 */
static const int HTTP_STATUS_BAD_GATEWAY					=	502;
/**
 * Status Code: 503 Service Unavailable
 *
 * @since 2.0
 */
static const int HTTP_STATUS_SERVICE_UNAVAILABLE			=	503;
/**
 * Status Code: 504 Gateway Timeout
 *
 * @since 2.0
 */
static const int HTTP_STATUS_GATEWAY_TIMEOUT				=	504;
/**
 * Status Code: 505 HTTP Version Not Supported
 *
 * @since 2.0
 */
static const int HTTP_STATUS_HTTP_VERSION_NOT_SUPPORTED		=	505;

/**
 * @enum 	NetHttpAuthScheme
 * Defines the supported authentication schemes.
 *
 * @since 1.0
 */
enum NetHttpAuthScheme
{
	NET_HTTP_AUTH_NONE,					/**< The no authentication type */
	NET_HTTP_AUTH_PROXY_BASIC,			/**< The authentication type is Proxy Basic Authentication */
	NET_HTTP_AUTH_PROXY_MD5,			/**< The authentication type is Proxy Digest Authentication */
	NET_HTTP_AUTH_WWW_BASIC,			/**< The authentication Type is HTTP Basic Authentication */
	NET_HTTP_AUTH_WWW_MD5,				/**< The authentication type is HTTP Digest Authentication */

};

/**
 * @enum 	NetHttpCookieFlag
 * Defines the HTTP cookie mode.
 *
 * @since 1.0
 */
enum  NetHttpCookieFlag{
	NET_HTTP_COOKIE_FLAG_NONE,				/**< The mode is not defined */
	NET_HTTP_COOKIE_FLAG_ALWAYS_AUTOMATIC,  /**< The cookie will be parsed and saved, and also attached to request automatically */
	NET_HTTP_COOKIE_FLAG_ALWAYS_MANUAL 		/**< The cookie will be handled by the user action with HttpRequest::SetCookie() and HttpCookieStorageManager::GetCookies() */
};



#ifndef HTTP_MAX_CERT_SUBJECT_SIZE
#define	HTTP_MAX_CERT_SUBJECT_SIZE						256			/**< @internal This is internal. If used in an application, the application can get rejected during the certification process.*/
#endif

#ifndef NET_HTTP_CONTEXT_MAX_COUNT
#define NET_HTTP_CONTEXT_MAX_COUNT						2			/**< @internal This is internal. If used in an application, the application can get rejected during the certification process.*/
#endif

#ifndef NET_HTTP_MAX_SESSIONS_PER_APPID_PER_PROTOCOL
#define NET_HTTP_MAX_SESSIONS_PER_APPID_PER_PROTOCOL	10				/**< Defines the maximum number of HttpSessions */
#endif

#ifndef NET_HTTP_MAX_TRANSACTIONS_PER_SESSION
#define NET_HTTP_MAX_TRANSACTIONS_PER_SESSION			1				/**< @internal This is internal. If used in an application, the application can get rejected during the certification process.*/
#endif

#ifndef NET_HTTP_MAX_TRANSACTIONS_PER_SESSION_PIPE
#define NET_HTTP_MAX_TRANSACTIONS_PER_SESSION_PIPE		5				/**< @internal This is internal. If used in an application, the application can get rejected during the certification process.*/
#endif

#ifndef NET_HTTP_PROTOCOL_SCHEME
#define	NET_HTTP_PROTOCOL_SCHEME						L"http"			/**< Defines the HTTP Protocol Scheme Name */
#endif

#ifndef NET_HTTPS_PROTOCOL_SCHEME
#define	NET_HTTPS_PROTOCOL_SCHEME						L"https"		/**< Defines the HTTPS Protocol Scheme Name */
#endif

#ifndef NET_HTTP_PROTOCOL_NAME
#define	NET_HTTP_PROTOCOL_NAME							L"http://"		/**< Defines the HTTP Protocol Scheme */
#endif

#ifndef NET_HTTPS_PROTOCOL_NAME
#define	NET_HTTPS_PROTOCOL_NAME							L"https://"		/**< Defines the HTTPS Protocol Scheme */
#endif

#ifndef NET_HTTP_HOST_HEADER_NAME
#define	NET_HTTP_HOST_HEADER_NAME						L"Host"			/**< Defines the Host header name */
#endif

#ifndef NET_HTTP_USERAGENT_HEADER_NAME
#define	NET_HTTP_USERAGENT_HEADER_NAME					L"User-Agent"	/**< Defines the User-Agent header name */
#endif

#ifndef NET_HTTP_USERAGENT_HEADER_VALUE
#define	NET_HTTP_USERAGENT_HEADER_VALUE					L"bada"			/**< @internal This is internal. If used in an application, the application can get rejected during the certification process.*/
#endif

#define INVALID_HOBJ (-1)	/**< @internal This is internal. If used in an application, the application can get rejected during the certification process.*/

#ifndef _HTTP_H_
/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 * HttpSession Handle
 *
 * @since 1.0
 */
typedef Handle	HHttpSession;
/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 * HttpTransaction Handle
 *
 * @since 1.0
 */
typedef Handle	HHttpTxn;
/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 * EventHandler Handle
 *
 * @since 1.0
 */
typedef Handle	HEventHandler;
#endif

/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 *
 * @since 	1.0
 * @struct 	NetHttpAuthData
 * Struct of HTTP Authentication data.
 */
typedef struct{
	char*			pDomain;		/**< The Domain - URL of the site */
	char*			pRealm;			/**< The Realm Value given by the server */
	char*			pNonce;			/**< The Nonce Value given by the server */
	char*			pOpaque;		/**< The Opaque Value given by the server */
	char*			pAlgo;			/**< The Algorithm Value given by the server */
	char*			pQop;			/**< Qop Value given by the server */
	int 			inc;			/**< The Nonce Count generated in the code */
	int				scheme;
	bool 			bStale;			/**< bStale - sent by the server */
} NetHttpAuthData;

/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 * @class	StringComparer
 *
 * @since 1.0
 */
class StringComparer
	: public Osp::Base::Collection::IComparer
{
public:
	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during the certification process.
	 * Compare objects of implementing the IComparer Interface.
	 *
	 * @since 		1.0
	 * @return		The result
	 * @param[in]	obj1 	An instance of Object
	 * @param[in]	obj2 	An instance of Object
	 * @param[out]	cmp 	the result
	 */
	result Compare(const Osp::Base::Object& obj1, const Osp::Base::Object& obj2, int& cmp) const{

		Osp::Base::Object* pObject1 = const_cast<Osp::Base::Object*>(&obj1);
		Osp::Base::Object* pObject2 = const_cast<Osp::Base::Object*>(&obj2);
		Osp::Base::String* pStr1 = static_cast<Osp::Base::String*>(pObject1);
		Osp::Base::String* pStr2 = static_cast<Osp::Base::String*>(pObject2);
		cmp =  (pStr1->CompareTo(*pStr2));
		return E_SUCCESS;
	}
};

/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 * @class	MultiHashMapDefaultProvider
 * @brief	This class is an implementation of IHashCodeProvider for MultiHashMap.
 *
 * @since 1.0
 */
class	MultiHashMapDefaultProvider
	:	public Osp::Base::Collection::IHashCodeProvider,
	public Osp::Base::Object
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since 1.0
	 */
	MultiHashMapDefaultProvider(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 1.0
	 */
	virtual ~MultiHashMapDefaultProvider(void);

	/**
	 * Gets the hash code of the specified Object.
	 *
	 * @since 		1.0
	 * @return		The hash code of the specified instance
	 * @param[in]	obj		An instance of Object
	 * @see			Osp::Base::Object::GetHashCode()
	 */
	int GetHashCode(const Object& obj) const;
};

}; }; }; //Osp::Net::Http
#endif // _FNET_HTTP_HTTP_TYPES_H_

