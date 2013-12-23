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
 * @file		FWebCtrlIJavaScriptBridge.h
 * @brief		This is the header file for the %IJavaScriptBridge interface.
 *
 * This header file contains the declarations of the %IJavaScriptBridge interface.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/controls_namespace.htm">Web Controls Guide</a>.
 *  
 */

#ifndef _FWEB_IJAVASCRIPTBRIDGE_H_
#define _FWEB_IJAVASCRIPTBRIDGE_H_

#include "FBase.h"
#include "FWebConfig.h"

namespace Osp { namespace Web { namespace Json {

	class IJsonValue;
	
};};};

namespace Osp { namespace Web { namespace Controls {


/**
 * @interface	IJavaScriptBridge
 * @brief	 This interface provides a communication channel between JavaScript and native object.
 * @since	2.0
 *
 * The %IJavaScriptBridge interface provides a communication channel between JavaScript and native object.
 */

class _EXPORT_WEB_ IJavaScriptBridge 
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	~IJavaScriptBridge(void) {};

	/**
	 * Called asynchronously on invocation request from JavaScript side through the requestToNative() method.
	 *
	 *
	 *
	 * @since			2.0
	 *
 	 * @param[in] pArg        The parameters delivered by JavaScript
 	 */
	virtual void HandleJavaScriptRequestN(Osp::Web::Json::IJsonValue* pArg) = 0;

	/**
	 * Provides the name of %IJavaScriptBridge to identify each %IJavaScriptBridge
	 *
	 * @since		2.0
	 * @return	The name of %IJavaScriptBridge
	 */
	virtual Osp::Base::String GetName(void) = 0;

protected:	
	
	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/
	virtual void IJavaScriptBridge_Reserved1 (void) {}
	
	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/
	virtual void IJavaScriptBridge_Reserved2 (void) {}

	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/
	virtual void IJavaScriptBridge_Reserved3 (void) {}

	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/
	virtual void IJavaScriptBridge_Reserved4 (void) {}

	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/
	virtual void IJavaScriptBridge_Reserved5 (void) {}

	
};

}; };};
#endif


