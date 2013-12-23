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
 * @file		FWebCtrlILoadingListener.h
 * @brief		This is the header file for the %ILoadingListener interface.
 *
 * This header file contains the declarations of the %ILoadingListener interface.
 */


#ifndef _FWEB_ILOADINGLISTENER_H_
#define _FWEB_ILOADINGLISTENER_H_

#include "FBase.h"
#include "FWebConfig.h"

namespace Osp { namespace Web { namespace Controls {
	class AuthenticationChallenge;
};};};

namespace Osp { namespace Net { namespace Http {
	class HttpHeader;
};};};

namespace Osp { namespace Web { namespace Controls {


/**
 * @interface	ILoadingListener
 * @brief		This is an interface for receiving the events that occur during the loading of data.
 * @since	1.0
 *
 * The %ILoadingListener interface receives the events that occur during the loading of data.
 * To listen to the events occurred during a data loading operation, implement this listener. If there is no 
 * registered load event listener, the browser engine handles these events according to its own settings. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/controls_namespace.htm">Web Controls Guide</a>.
 */


 /**
  * @enum WebNavigationType
  * Defines the type of %Web navigation.
  *
  * @since	1.0
  */
enum WebNavigationType
{
    WEB_NAVIGATION_LINK_CLICKED,			/**< The clicking of a link on the page */
    WEB_NAVIGATION_FORM_SUBMITTED,			/**< The submission of a form */
    WEB_NAVIGATION_BACKFORWARD,				/**< The back and forward navigation*/
    WEB_NAVIGATION_RELOAD,					/**< The reloading of the page */
    WEB_NAVIGATION_FORM_RESUBMITTED,		/**< The resubmission of the form  */
    WEB_NAVIGATION_OTHER					/**< A navigation other than any of the above */
};


/** 
 * @enum LoadingErrorType
 * Defines the types of loading errors.
 *
 * @since	1.0
 */
enum LoadingErrorType
{
	WEB_ERROR_UNKNOWN,							/**< An unknown error*/
	WEB_REQUEST_TIMEOUT,					/**< The request timeout */
	WEB_NO_CONNECTION,							/**< The network is not in service */
	WEB_MIME_NOT_SUPPORTED,						/**< The content type is not supported */
	WEB_BAD_URL,								/**< The URL is invalid */
	WEB_HTTP_RESPONSE,						/**< The hypertext transfer protocol (HTTP) response */
	WEB_OUT_OF_MEMORY,						/**< The memory is not enough to load the page @b since: @b 2.0 */
    WEB_FILE_ACCESS_FAILED,					/**< The file access failed @b since: @b 2.0 */
	WEB_REQUEST_MAX_EXCEEDED,				/**< The request has failed because the total number of requests have exceeded the maximum limit @b since: @b 2.0 */
	WEB_INVALID_CERTIFICATE					/**< The hypertext transfer protocol secure (HTTPS) request has failed due to an invalid certificate or CA @b since: @b 2.0 */ 
		
};


/** 
 * @enum DecisionPolicy
 * Defines the decision policy.
 *
 * @since	1.0
 */
enum DecisionPolicy
{
	WEB_DECISION_DOWNLOAD,							/**< The download policy*/
	WEB_DECISION_CONTINUE,							/**< The usage policy*/
	WEB_DECISION_IGNORE,								/**< The ignore policy*/
};


class _EXPORT_WEB_ ILoadingListener :
	public Osp::Base::Runtime::IEventListener
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~ILoadingListener(void) {}

	/**
	 * Called when an authentication is requested.
	 *
	 * @since			1.0
	 * @return		@c true if the ownership is taken by the application, @n
	 *				else @c false, and a default dialog for the ID and password is displayed @n
	 *				If this method returns @c true, the application should delete the AuthenticationChallenge instance.
	 * @param[in]	host			The host requiring the authentication
	 * @param[in]	realm			The description to help save the user credentials for future visits
	 * @param[in]		authentication	The handler to send a user response to the server that requested the authentication
	 */	
	virtual bool	OnHttpAuthenticationRequestedN(const Osp::Base::String& host, const Osp::Base::String& realm, const Osp::Web::Controls::AuthenticationChallenge& authentication) = 0;

	/**
	 * Called when the authentication request is cancelled.
	 *
	 * @since	1.0
	 */	
	virtual void	OnHttpAuthenticationCanceled(void) = 0;

	/**
	 * Called when the loading operation starts.
	 *
	 * @since	1.0
	 */	
	virtual void	OnLoadingStarted(void) = 0;

	/**
	 * Called when the loading operation is cancelled.
	 *
	 * @since	1.0
	 */	
	virtual void	OnLoadingCanceled(void) = 0;

	/**
	* Called when the loading operation fails.
	* 
	* @since                  1.0
	* @compatibility     This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*                                 For more information, see @ref CompLoadingErrorType "here".
	* @param[in]          error                                            The error that occurred during loading
	* @param[in]          reason                                        The reason for the loading failure, @n
	*									- WEB_HTTP_RESPONSE: The HTTP state code such as "404" @n
	*									- WEB_MIME_NOT_SUPPORTED: The Multipurpose Internet Mail Extensions (MIME) type such as "application/rdf+xml" is not supported @n        
	*									- WEB_BAD_URL: The URL is incorrect
	*/
	virtual void	OnLoadingErrorOccurred(LoadingErrorType error, const Osp::Base::String& reason) = 0;

	/**
	* @page                   CompLoadingErrorType Compatibility for LoadingErrorType
	* @section               CompLoadingErrorTypeIssues Issues
	* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* -# Only WEB_ERROR_UNKNOWN error is returned in cases related to memory, file operation and resource exhaustion.
	*
	* @section               CompLoadingErrorTypeResolutions Resolutions
	* The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	* -# WEB_OUT_OF_MEMORY is returned in the case of insufficient memory. @n 
	* -# WEB_FILE_ACCESS_FAILED is returned in the case of generic file operation failure. @n 
	* -# WEB_REQUEST_MAX_EXCEEDED is returned in the case of resource exhaustion due to excessive requests. 
	*/

	/**
	 * Called when the loading operation is completed.
	 *
	 * @since	1.0
	 */	
	virtual void	OnLoadingCompleted(void) = 0;

	/**
	 * Called when the loading progress for the current page is requested. @n 
	 * The progress rate is displayed as a percentage.
	 *
	 * @since				1.0
	 * @param[in]		progress			The progress rate ranging from [0~100]
	 */
	virtual void	OnEstimatedProgress(int progress) = 0;
	
	/**
	 * Called when the title of the new page has been received.
	 *
	 * @since	1.0
	 */	
	virtual void	OnPageTitleReceived(const Osp::Base::String& title) = 0;

	/**
	 * Called to notify an application of the URL to be requested. @n
	 * If an application wants to handle the URL, it should return @c true. If an application returns @c false, the request of the URL continues with the 
	 * browser engine.
	 *
	 * @since					1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	 *					For more information, see @ref CompLoadingRequest "here".
	 * @return			@c true if the application handles the URL after the request is canceled in the browser engine, @n
	 * 					else @c false if the browser engine proceeds with the requested URL
	 * @param[in]		url			The URL to be requested
	 * @param[in]		type		The type indicating how the URL is triggered
	 */	
	virtual bool	OnLoadingRequested(const Osp::Base::String& url, WebNavigationType type) = 0;

	/**
	 * @page   CompLoadingRequest	Compatibility for OnLoadingRequested()
	 * @section CompLoadingRequestIssues Issues
	 * Implementation of this method in bada API versions prior to 1.1 has the following issues: @n
	 * -# Requests for other scheme URLs except HTTP and HTTPS result in OnLoadingErrorOccurred() with WEB_BAD_URL. @n	 
	 * -# Accessing a site with an invalid certificate is allowed without any user confirmation. @n
	 * -# Accessing a secure site fails because there is no way to select a client certificate to use.
	 *
	 * @section CompLoadingRequestResolutions Resolutions 
	 * The issues mentioned above are resolved in bada API version 1.1, and it is recommended to use bada API version 1.1. or above. @n	
	 * -# The schemes mentioned below are supported from bada API version 1.1 by the Web control: @n
	 * 	  tel, rtsp, mailto, mms, mmsto, sms, smsto, samsungapps @n
	 * 	  They are only available when the value for WebNavigationType is WEB_NAVIGATION_LINK_CLICKED. @n
	 * -# If an application that is compiled with the above schemes in bada API versions prior to 1.1 needs to be launched, AppControls should be used. @n
	 * -# When an application accesses a site with an invalid certificate, a pop-up window to get the user confirmation for accessing the site is displayed from bada API version 1.1. @n
	 * -# When an application accesses a secure site that requires a client certificate, a window that displays a list of selectable certificates is displayed for the SSL client authentication.
	 */
	
	/**
	 * Called to notify an application of the content type of the data to be downloaded. @n
	 * - To handle data by itself, the application should return WEB_DECISION_DOWNLOAD. The data is routed to IWebDownloadListener to be downloaded incrementally. @n
	 * - If an application returns WEB_DECISION_CONTINUE, the browser engine continues the downloading and tries to parse the data. @n
	 * - If an application returns WEB_DECISION_IGNORE, the browser engine cancels the downloading of the data.
	 *
	 * @since				1.0
	 * @return			DecisionPolicy			A value of the enumerator DecisionPolicy
	 * @param[in]		mime				The content type of the data to be downloaded
	 * @param[in]		httpHeader			The HTTP header string
	 */	
	virtual DecisionPolicy OnWebDataReceived(const Osp::Base::String& mime, const Osp::Net::Http::HttpHeader& httpHeader) = 0;
	
};

}; };};
#endif

