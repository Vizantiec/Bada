/* $Change: 1256637 $ */
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
 * @file		FWebCtrlWeb.h
 * @brief	This is the header file for the %Web class.
 *
 * This header file contains the declarations of the %Web class.
 */


#ifndef _FUICTRL_WEB_H_
#define _FUICTRL_WEB_H_

#include "FBase.h"
#include "FWebConfig.h"
#include "FUiIKeyEventListener.h"
#include "FUiITouchEventListener.h"
#include "FUiControl.h"
#include "FWebCtrlHitElementResult.h"

namespace Osp { namespace Ui {
	class ITextSelectionEventListener;
};};

namespace Osp { namespace Web { namespace Controls {
	class __WebService;	
	class ILoadingListener;
	class IWebDownloadListener;
	class IWebUiListener;
	class IWebKeypadEventListener;
	class PageNavigationList;
	class WebSetting;	
	class IWebUiEventListener;
	class IJavaScriptBridge;
}; };};

namespace Osp { namespace Web { namespace Controls {

/**
 * @class	Web
 * @brief	This class provides the methods for embedding a browser in an application.
 * @since	1.0
 *
 * The %Web class provides the methods for embedding a browser in an application to load and render various types of %Web content. Similar to adding UI controls, the %Web content can be added to the application by adding a %Web control.
 *
 
 * For more information on the class features and %Web browser feature limitations, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/controls_namespace.htm">Web Controls Guide</a> and <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/supported_web_features.htm">Supported Features in the Web Control</a>.
 
 * The following example demonstrates how to use the %Web class.
 *	@code

// Sample Code for WebSample.h
#include <FUi.h>
#include <FWeb.h>

class WebSample :
	public Osp::Ui::Controls::Form
{
public:
	WebSample(void) {};
	virtual ~WebSample(void) {};

protected:
	void LoadUrl(void);

private:
	Osp::Web::Controls::Web *__pWeb;

public:
	virtual result OnInitializing(void);
};

// Sample Code for WebSample.cpp
#include "WebSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Web::Controls;

result
WebSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	__pWeb = new Web();
	__pWeb->Construct(GetClientAreaBounds());
	AddControl(*__pWeb);
	LoadUrl();

	return r;
}

// Calls LoadUrl() with the URL of the %Web content to display it on the %Web control.
void
WebSample::LoadUrl(void)
{
	Osp::Base::String url(L"http://www.bada.com");

	__pWeb->LoadUrl(url);
}

 *	@endcode
 *
 */

class __WebWindowEventAdaptor;

class _EXPORT_WEB_ Web :
	public Osp::Ui::Control
{
	DECL_CLASSTYPE(Web);
public:
	 
	/**
	 * This is the default constructor for this class.  
	 *
	 * @since	1.0
	 */
	Web(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	~Web(void);
	
	/**
	 * Initializes the instance of the %Web control with the specified parameters.
	 *
	 * @since				1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlConstruct20 "here".
	 * @privlevel		NORMAL
	 * @privgroup		WEB_SERVICE	 
	 * @return			An error code
	 * @param[in]		rect							The rectangle size of the control
 	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_SYSTEM				The method has failed. 	 
	 * @exception		E_OUT_OF_MEMORY	    		The internal objects are not created due to insufficient memory.
	 * @exception		E_INVALID_OPERATION     The control has not been constructed as yet.
	 * @exception		E_INVALID_STATE			This instance is in an invalid state @b since: @b 2.0.
	 * @exception		E_INVALID_ARG		The @c rect is invalid.	 
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	result Construct(const Osp::Graphics::Rectangle& rect);

	/**
	 * Initializes the instance of the %Web control as a child window. This instance is used as the return value when OnWebWindowCreateRequested() is called.
	 *
	 * @deprecated	This method is deprecated because a %Web control will maintain its parent %Web control information internally from the next API version.
	 * @since			2.0
	 * @privlevel		NORMAL
	 * @privgroup		WEB_SERVICE	 
	 * @return		An error code
	 * @param[in]		rect					The rectangle size of the control
	 * @param[in]		parent				The Web instance of the parent window
 	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_SYSTEM				The method has failed. 	 
	 * @exception		E_OUT_OF_MEMORY	The internal objects are not created due to insufficient memory.
	 * @exception		E_INVALID_STATE			This instance is in an invalid state @b since: @b 2.0.	 
	 * @exception		E_INVALID_ARG		The @c rect is invalid.	 
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @see			Osp::Web::Controls::IWebUiEventListener::OnWebWindowCreateRequested()
	 * @see			Osp::Web::Controls::IWebUiEventListener::OnWebWindowCloseRequested()
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, Osp::Web::Controls::Web&  parent);
	
	/**
	 * Loads the resource specified by the URL. 
	 *
	 * @since				1.0
	 * @param[in]		url					The resource to be loaded
	 */
	void	LoadUrl(const Osp::Base::String& url) const;

	/**
	 * Loads the content of the specified buffer. 
	 *
	 * @since				1.0
	 * @param[in]	baseUrl		The uniform resource locator (URL) of the content
	 * @param[in]		content				The content
	 * @param[in]		mime				The MIME type of the content
	 * @param[in]		encoding			The <a href= "../com.osp.cppappprogramming.help/html/dev_guide/web/supported_web_features.htm">text encoding</a> of the content
	 
	 */
	void	LoadData(const Osp::Base::String& baseUrl, const Osp::Base::ByteBuffer& content, const Osp::Base::String& mime, const Osp::Base::String& encoding = "UTF-8" ) const;

	/**
	 * Stops the current loading operation.
	 *
	 * @since	1.0
	 */
	void	StopLoading(void) const;

	/**
	 * Reloads the current page. 
	 *
	 * @since	1.0
	 */
	void	Reload(void) const;

	/**
	 * Checks whether the page is loading.
	 *
	 * @since			1.0
	 * @return		@c true if a page is loading, @n
	 *				else @c false
	 */
	bool		IsLoading(void) const;

	/**
	 * Checks whether the current Web control has a back history item.
	 *
	 * @since			1.0
	 * @return		@c true if a back history item exists, @n
	 *				else @c false
	 */
	bool	CanGoBack(void) const;

	/**
	 * Checks whether the current Web control has a forward history item.
	 *
	 * @since			1.0
	 * @return		@c true if a forward history item exists, @n
	 *				else @c false
	 */
	bool	CanGoForward(void) const;

	/**
	 * Goes to the back history of the current Web control. 
	 *
	 * @since	1.0
	 */
	void	GoBack(void) const;

	/**
	 * Goes to the forward history of the current Web control. 
	 *
	 * @since	1.0
	 */
	void	GoForward(void) const;

	/**
	 * Gets the backward and forward navigation list of the Web control.
	 *
	 * @since			1.0
	 * @return		A pointer to %PageNavigationList containing the history items of the Web control
 	 * @exception	E_SUCCESS			The method is successful.
 	 * @exception	E_OUT_OF_MEMORY	    The memory is insufficient.
 	 * @exception	E_DATA_NOT_FOUND	There is no history data.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 */
	Osp::Web::Controls::PageNavigationList*	GetBackForwardListN(void);
	
	/**
	 * Searches for a word on the current page. @n
	 * When called again, it searches for the next instance of the word on the page. Set @c searchForward to @c false to search for the word in the backward 
	 * direction.
	 *
	 * @since			1.0
	 * @return		@c true if the specified word is found, @n
	 *				else @c false
	 * @param[in]	word				The string to search for
	 * @param[in]	searchForward		Set to @c true to search for the word in the forward direction from the current position, @n
	 *									else @c false to search for the word in the backward direction from the current position
	 */
	bool	SearchText(const Osp::Base::String &word, bool searchForward = true);

	/**
	 * Sets the new values for the default setting. @n
	 * It fails to change the setting during data load.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		setting				The setting to be updated
 	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_FAILURE			The method has failed.
	 * @exception		E_INVALID_STATE		This instance has not been constructed as yet.
	 */		
	result	SetSetting(const Osp::Web::Controls::WebSetting& setting);

	/**
	 * Gets the setting of the %Web control.
	 *
	 * @since			1.0
	 * @return		An instance of WebSetting
	 */		
	Osp::Web::Controls::WebSetting GetSetting(void) const;


	/**
	 * Gets the information of the element pointed by the specified coordinates.
	 *
	 * @since			1.0
	 * @return		A %HitElementResult of the pointed element
	 * @param[in]	point			 	 The x and y coordinates
	 * @exception	E_SUCCESS			 The method is successful.
	 * @exception	E_INVALID_STATE		 This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG		 The specified @c point is invalid. 
	 * @exception	E_OUT_OF_MEMORY	     The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND		 The specified element is not found.
	 * @exception	E_INVALID_OPERATION	 The current state of the instance prohibits the execution of the specified operation. 
	 */		
	Osp::Web::Controls::HitElementResult*	GetElementByPointN(const Osp::Graphics::Point &point);

	/**
	* Evaluates the JavaScript string and returns the result.
	*
	* @since			1.0
	* @return		The result of the evaluated JavaScript, @n
	*				else an empty string if an error occurs
	* @param[in]	scriptCode			The JavaScript code as string
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	*/		
	Osp::Base::String* EvaluateJavascriptN(const Osp::Base::String &scriptCode) const;


	/**
	* @page		ZoomLevelPage Compatibility for result SetZoomLevel(float level) and float GetZoomLevel()
	* 
	* @section	ZoomLevelPageIssueSection		Issues
	*			Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	*			-# The minimum viewport width could be 240 pixels so that some PC-based %Web page's layout was displayed improperly due to the small viewport width.			
	*			-# Zoom canvas with 240 pixels was used to calculate the zoom level instead of device width. 
	* 			For example, WVGA device also have 240 pixels zoom canvas and that caused users to be confused.             
	*
	* @section	ZoomLevelPageSolutionSection	Resolutions
	*			
	*			-# The minimum viewport width is changed into 800 pixels in bada API 2.0, so some layout issues in PC-based %Web pages are resolved.
	*			-# The device width is used to calculate the zoom level instead of zoom canvas. When the viewport width is decided as 800 pixels, the initial zoom level is 0.3 in WQVGA device.
	*			According to the rules, the initial zoom level is 0.4 in HVGA device and 0.6 in WVGA device.	
	*
	*/

	/**
	 * Sets the zoom-out level as a percentage.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *				For more information, see @ref ZoomLevelPage "here".
	 * @return	 	An error code
	 * @param[in]	level		  	The zoom-out level @n
	 *							  	The value ranges between @c 0.3 and @c 2.0. When the page view is at its original size, the level is @c 1.0. @n If the 
	 *								specified level is less than @c 1.0, the page view is reduced. @n If the specified level is greater than @c 1.0, the page view is 
	 *								magnified.
 	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c level is less than @c 0.3 or greater than @c 2.0.
	 */		
	 result	 SetZoomLevel(float level) const;

	/**
	* Gets the zoom level of a page as a percentage.
	*
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*				For more information, see @ref ZoomLevelPage "here".	
	* @return			The value ranges between @c 0.3 and @c 2.0
	*/		
	float GetZoomLevel(void) const;

	/**
	 * Gets the title of the current page.
	 *
	 * @since		1.0
	 * @return		The title of the current page
	 */		
	Osp::Base::String GetTitle(void) const;

	/**
	 * Gets the URL of the current page.
	 *
	 * @since		1.0
	 * @return	The URL of the current page
	 */		
	Osp::Base::String GetUrl(void) const;	
	
	/**
	 * Checks whether the specified multipurpose internet mail extensions (MIME) type is supported by bada.
	 *
	 * @since			1.0
	 * @return			@c true if the specified MIME type is supported, @n
	 *					else @c false
	 * @param[in]		mime			The MIME type
	 */		
	bool IsMimeSupported(const Osp::Base::String& mime) const;	
	
	/**
	 * Sets a load event listener. 
	 *
	 * @since				1.0
	 * @param[in]		pLoadingListener		The listener receives the events that occurs while loading the data
	 */
	void	SetLoadingListener(const Osp::Web::Controls::ILoadingListener *pLoadingListener) const;

	/**
	 * Sets a download event listener.
	 *
	 * @since				1.0
	 * @param[in]		pDownLoadListener		The listener to receive the data from a network incrementally
	 */
	void	SetDownloadListener(const Osp::Web::Controls::IWebDownloadListener *pDownLoadListener) const;
	
	/**
	 * Called to inform the browser engine to stop the screen operations such as updating a screen until %Web calls the Resume() method. @n
	 * It is useful when a Web control is not visible and does not need to update its screen.
	 *
 	 * @deprecated  	This method is deprecated because it does not work properly.   
 	 * @since					1.0
	 */
	void Pause(void);

	/**
	 * Called to inform the browser engine to resume the handling of screen operations. 
	 *
 	 * @deprecated  	This method is deprecated because it does not work properly. 
 	 * @since				1.0 
	 */
	void	Resume(void);

	/**
	 * Sets the starting point for the text selection block. @n
  	 * It sets the selection block around the nearest word bound.
  	 *
  	 * @since         2.0
  	 * @return        An error code
  	 * @param[in]	startPoint			The starting point for the text selection block
  	 * @exception	E_SUCCESS			The method is successful.
  	 * @exception	E_INVALID_ARG		There is nothing to select from the starting point specified.
  	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
  	 */
	result SetBlockSelectionPosition (const Osp::Graphics::Point& startPoint);

	/**
	 * Releases the currently selected block.
	 *
	 * @since         2.0
	 * @return        An error code
	 * @exception    E_SUCCESS			The method is successful.
	 * @exception    E_INVALID_STATE	This instance has not been constructed as yet.
	 *
	 */
	result ReleaseBlock (void);

	/**
	 * Gets the starting point and the ending point of the selected text block. @n
	 * When this method is called without the selection block, the startPoint and endPoint have (0,0) values for the x and y coordinates.
	 *
	 * @since         2.0
	 * @return        An error code
	 * @param[out]		startPoint			The starting point of the selected text block
	 * @param[out]      endPoint			The ending point of the selected text block                            
	 * @exception    	E_SUCCESS           The method is successful.
	 * @exception    	E_INVALID_STATE     This instance has not been constructed as yet.
	 */
	result GetBlockRange (Osp::Graphics::Point& startPoint, Osp::Graphics::Point& endPoint);
           
	/**
	 * Gets the text of the selected text block.
	 *
	 * @since                    2.0
	 * @return			The selected text, @n
	 *                  else an empty string if there is no selection block
	 */
	 Osp::Base::String GetTextFromBlock (void);
		
	/**
	 * Enables or disables the vertical and horizontal scrolls.
	 *
	 * @since      	2.0
	 * @param[in]	enable				Set to @c true to enable the scrolling of the %Web page, @n
	 *                                  else @c false         
 	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 */
	result SetScrollEnabled(bool enable);
 

	/**
	 * Checks whether the %Web page scroll is enabled.
	 *
	 * @since      2.0
	 * @return     	@c true if the %Web page scroll is enabled, @n
	 *				else @c false
	 */
	bool IsScrollEnabled(void) const;
	
         /**
	 * Registers a user interface (UI) event listener.
	 *
	 * @since				2.0	 
	 * @param[in]	pUiEventListener	The listener to receive the user interface (UI) related events
	 */
	void SetWebUiEventListener(const Osp::Web::Controls::IWebUiEventListener* pUiEventListener);

	/**
	* Checks whether the Web control uses private browsing.
	*
	* @since     	 2.0
	* @return		@c true if private browsing is enabled, @n
    	*      			else @c false
	*/     
	bool IsPrivateBrowsingEnabled(void) const;
 
	/**
	* Sets the private browsing and returns the result.
	*
	* @since			2.0
	* @return		The result of setting the private browsing
	* @param[in] 	enable				Set to	@c true to enable private browsing, @n
	*                               	else @c false
	* @exception 	E_SUCCESS			The method is successful.
	* @exception 	E_SYSTEM            The method has failed.
	* @exception 	E_INVALID_STATE     This instance has not been constructed as yet.
	*/                  
	result SetPrivateBrowsingEnabled(bool enable) ;
 
	/**
	 * Clears the application's cache. 
	 *
	 * @since			2.0
	 * @return		An error code
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM            The method has failed.
	 * @exception   E_INVALID_STATE		This instance has not been constructed as yet.
	 */          
	result ClearCache(void); 

	/**
	 * Clears the application's cookie. 
	 *
	 * @since			2.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM            The method has failed.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 */    
	result ClearCookie(void);

	/**
	* Checks whether the Web control allows cookie. Returns true if cookie is enabled.
	*
	* @since		2.0
	* @return		@c true if cookie is allowed, @n
	*            	else @c false
	*/     
	bool IsCookieEnabled(void) const;
	 
	/**
	* Enables or disables a cookie.
	*
	* @since		 2.0
	* @return		The result of enabling or disabling cookie
	* @param[in]	enable				Set to	@c true if the Web control allows a cookie, @n
	*                           	else @c false
	* @exception 	E_SUCCESS           The method is successful.
	* @exception 	E_SYSTEM            The method has failed.
	* @exception 	E_INVALID_STATE     This instance has not been constructed as yet.
	*/           
	result SetCookieEnabled(bool enable); 

	/**
	 * Adds a JavaScript bridge instance.
	 *
	 * @since			2.0
	 * @return      An error code
	 * @param[in] 	jsBridge				The JavaScript bridge to be added
	 * @exception E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST		A JavaScript bridge with the same name already exists.
	 * @exception E_INVALID_STATE        		This instance has not been constructed as yet.
	 */                  
	result AddJavaScriptBridge (const IJavaScriptBridge& jsBridge);

	/**
	 * Removes a JavaScript bridge instance.
	 *
	 * @since			2.0
	 * @return		An error code
	 * @param[in]	jsBridge			The JavaScript bridge to be removed
	 * @exception E_SUCCESS			The method is successful.
	 * @exception E_INVALID_STATE        	This instance has not been constructed yet.
	 */                  
	result RemoveJavaScriptBridge(const IJavaScriptBridge& jsBridge);				 
	
	/** 
	 * Registers a keypad event listener. @n
	 * The registered listener is notified when the keypad associated with @c <input> tag or with @c <textarea> tag is opened or closed.
	 *
	 * @since       2.0
	 * @param[in]   pKeypadEventListener		The event listener to be set
	 * @remarks		The interfaces of IWebKeypadEventListener are called only when the input style of the keypad is @c INPUT_STYLE_OVERLAY.
	 * @see         WebSetting::SetInputStyle() 
	 */
	void SetWebKeypadEventListener(const IWebKeypadEventListener* pKeypadEventListener );
	
	/** 
	 * Called when the control is successfully added to a container. @n
	 * This method is overridden to provide user-specific initialization code.
	 *
	 * @since                              1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                For more information, see @ref CompOnInitializing "here".
	 *
	 * @return                  An error code
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_FAILURE		The method has failed.
	 * @remarks                OnInitializing() is called when the control is successfully added to a container.
	 * @see         OnTerminating()
	 */
	virtual result OnInitializing(void);

	/**
	 * @page    CompOnInitializing Compatibility for OnInitializing()
	 * @section CompOnInitializingIssues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# OnInitializing() for the Web control is called before the initialization of the Web control is completed, so when an application calls the methods 
	 * of the Web control within OnInitializing(), the method calls result in failure.
	 *
	 * @section CompOnInitializingResolutions Resolutions
	 * -# The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0. 
	 *
	 */

	/** 
	 * Called before the control is removed successfully from the container. @n
	 * This method is overridden to provide user-specific termination code.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_FAILURE		The method has failed.
	 * @remarks     OnTerminating() is called before the control is removed successfully from the container.
	 * @see         OnInitializing()
 	 */	
	virtual result OnTerminating(void);
	
	
	
protected:

	/** 
	 * @internal
	 * Frees the resources allocated by this control and destroys its native window (if it is present).
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_FAILURE Failed to free the resource possessed by this instance.
	 */
	virtual result Dispose(void);	

	/** 
	 * @internal
	 * Notifies the control that it is now added to a control containment hierarchy.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_INVALID_OPERATION	This control is currently assigned to a native peer window.
	 * @remarks		When this method is called, the method creates a native peer window and connects it to this control. @n
	 *				This method should only be invoked by the framework.
	 */
	result AddNotify(void);
	

private:
	Osp::Web::Controls::__WebService	*__pWebService;
	__WebWindowEventAdaptor			*__pWindowEventAdaptor;	
	bool								isPaused;

	friend class WebEx;
	class WebEx* __pWebEx;

protected :
	friend class WebImpl;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Gets the implementation instance of this control
	 *
	 * @since         2.0
	 */
	class WebImpl* GetImpl(void) const;
					

};

};};};
#endif


