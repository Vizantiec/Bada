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
 * @file		FWebCtrlIWebUiEventListener.h
 * @brief		This is the header file for the %IWebUiEventListener interface.
 *
 * This header file contains the declarations of the %IWebUiEventListener interface.
 */


#ifndef _FWEBCTRL_UIEVENTLISTENER_H_
#define _FWEBCTRL_UIEVENTLISTENER_H_

#include "FBase.h"
#include "FWebConfig.h"
#include "FWebCtrlWeb.h"



namespace Osp { namespace Web { namespace Controls {


/**
 * @interface	IWebUiEventListener
 * @brief		This interface is used for receiving user interface (UI) related events caused by the layout changes of a control.
 * @since		2.0
 *
 * The %IWebUiEventListener interface is used for receiving user interface (UI) related events caused by the layout changes of a control.
 * The browser engine requests a screen update through this interface when the layout of a page is changed.
 */


class _EXPORT_WEB_ IWebUiEventListener : 
	public Osp::Base::Runtime::IEventListener
{

public:

	/**
	 * This is the destructor for this class. 
	 *
	 * @since	2.0
	 */	
	virtual ~IWebUiEventListener(void) {}

	/**
	 * Called when the layout of a page is updated. @n	 
	 * The application should call Control::Show() if the screen needs to be updated.
	 * 
	 * @since			2.0
	 * @param[in]		source				The source of the event  
	 */	
	virtual void OnWebPageShowRequested(Osp::Web::Controls::Web& source) = 0;
	

	/**
	 * Called when a request for creating a new window is received. @n
	 * The returned %Web control instance should be constructed by using a child window's Construct() method.
	 *
	 * @since				2.0
	 * @return			A pointer to the new WebWindow instance
	 */
	 virtual Osp::Web::Controls::Web* OnWebWindowCreateRequested(void) = 0;


	/**
	 * Called when a request for closing the window is received. @n
	 * This event is called from the parent window's listener that invoked the child window. @n
	 * The application should free the resource allocated for the Web Control. 
	 *
	 * @since			 2.0
	 * @param[in]        source             The source of the closing event 
	 */	
	virtual void OnWebWindowCloseRequested(Osp::Web::Controls::Web& source) = 0;

	/**
	 * Called when the selected block of a page is updated.    
	 * 
	 * @since                    2.0
	 * @param[in]        source             The source of the event  
	 * @param[in]		startPoint		The starting point of the selected block                 
	 * @param[in]		endPoint		The ending point of the selected block        
	 */       
	virtual void OnWebPageBlockSelected (Osp::Web::Controls::Web& source, Osp::Graphics::Point& startPoint, Osp::Graphics::Point& endPoint) = 0;
	
	
protected :
	
	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/
 	virtual void IWebUiEventListener_Reserved1 (void) {};

	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/	
	virtual void IWebUiEventListener_Reserved2 (void) {};

	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/
 	virtual void IWebUiEventListener_Reserved3 (void) {};

	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/		
 	virtual void IWebUiEventListener_Reserved4 (void) {}; 

	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/	
 	virtual void IWebUiEventListener_Reserved5 (void) {};  
	
};

}; };};
#endif

