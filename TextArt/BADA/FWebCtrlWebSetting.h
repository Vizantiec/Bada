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
 * @file		FWebCtrlWebSetting.h
 * @brief		This is the header file for the %WebSetting class.
 *
 * This header file contains the declarations of the %WebSetting class for a %Web control.
 */


#ifndef _FWEB_WEBSETTING_H_
#define _FWEB_WEBSETTING_H_

#include "FBase.h"
#include "FWebConfig.h"
#include "FUiCtrlInputEnum.h"

namespace Osp { namespace Web { namespace Controls {


/**
 * @class		WebSetting
 * @brief		This class holds the setting values for a %Web control.
 * @since		1.0
 *
 * The %WebSetting class holds the setting values, which configure the behavior of a %Web control. An application can, for example, enable or disable JavaScript and image auto loading.  
 */


 /**
 * @enum CacheMode
 * Defines the cache mode.
 *
 * @since	1.0
 */
enum CacheMode
{
	WEB_CACHE_VALIDATED,		/**< The use of cache data only when the cache data is valid */
	WEB_CACHE_IGNORE			/**< The retrieval of data from a network resource without using cache data */
};

/** 
 * @enum CertificateErrorHandlingMode
* Defines the types of certification error handling mode.
*
* @since         2.0
*/
enum CertificateErrorHandlingMode
{
 	WEB_CERTIFICATE_ERROR_HANDLING_MODE_USER_CONFIRM,         	 /**< The %Web certificate error handling mode: The confirm popup is displayed to get the user confirmation*/
	WEB_CERTIFICATE_ERROR_HANDLING_MODE_CANCEL,			     	/**< The %Web certificate error handling mode: The confirm popup is not displayed and the request is canceled */
	WEB_CERTIFICATE_ERROR_HANDLING_MODE_CONTINUE			     	/**< The %Web certificate error handling mode: The confirm popup is not displayed and the request proceeds*/		
};



class _EXPORT_WEB_ WebSetting :
	public Osp::Base::Object
{

public:

	/**
	 * This is the default constructor for the %WebSetting class.
	 *
	 * @since	1.0
	 */
	WebSetting(void);

	/**
	 * This is the destructor for the %WebSetting class.
	 *
	 * @since	1.0
	 */
	~WebSetting(void);

	/**
	 * This is the copy constructor for the %WebSetting class. @n
	 * It creates an instance of %WebSetting with the values of the specified instance.
	 *
	 * @since	1.0
	 */
	WebSetting(WebSetting& setting);

	/**
	* Sets a cache control strategy for a %Web control.
	*
	* @since				1.0
	* @param[in]		mode		A cache mode
	*/
	void SetCacheControl(CacheMode mode);

	/**
	 * Sets the font size of the content.
	 *
	 * @since					1.0
	 * @param[in] 		fontSize 			The font size
	 */
	 void SetFontSize(int  fontSize);

	/**
	 * Sets the text encoding for the content of a %Web control.
	 *
	 * @since					1.0
	 * @param[in] 		encoding		The text encoding
	 */
	 void SetDefaultTextEncoding(const Osp::Base::String  &encoding);
	
	/**
	* Enables or disables the use of %Web controls in JavaScript.
	*
	* @since			1.0
	* @param[in]	enable 		Set to @c true if the %Web control uses JavaScript, @n
	*							else @c false 
	*/	
	 void SetJavascriptEnabled(bool enable);
	
	/**
	* Decides if a %Web control loads images included in the content.
	*
	* @since			1.0
	* @param[in]	enable 		Set to @c true if the %Web control should load images included in the content, @n
	*							else @c false
	*/	
	 void SetAutoImageLoadEnabled(bool enable);

	/**
	 * Sets the input style of the keypad, which is displayed for the <input> or <textarea> tag.
	 *
	 * @since					2.0
	 * @param[in] 		inputStyle 			The input style of keypad
	 * @remarks                	If an application sets the input style to INPUT_STYLE_OVERLAY, the application must implement IWebKeypadEventListener to rearrange the layout of the current form.
	 *
	 */
	 void SetInputStyle(Osp::Ui::Controls::InputStyle inputStyle);
	

	/**
	 * Gets the value of the cache control strategy for a %Web control.
	 *
	 * @since			1.0
	 * @return		A cache mode
	 */
	 CacheMode GetCacheControl(void) const;

	/**
	 * Gets the font size of the content.
	 *
	 * @since			1.0
	 * @return		The size of the font
	 */
	 int GetFontSize(void) const;

	/**
	 * Gets the text encoding of the content of a %Web control.
	 *
	 * @since			1.0
	 * @return		The text encoding
	 */
	 Osp::Base::String GetDefaultTextEncoding(void) const;

	/**
	* Checks whether the %Web control uses JavaScript. Returns true if JavaScript is enabled.
	*
	* @since	1.0
	* @return	@c true if JavaScript is enabled and used by a %Web control, @n
				else @c false
	*/	
	 bool IsJavascriptEnabled(void) const;
	
	/**
	* Checks whether the %Web control loads images included in the content automatically. Returns true if auto image loading is enabled.
	*
	* @since	1.0
	* @return	@c true if auto image loading is enabled, @n
				else @c false
	*/	
	 bool IsAutoImageLoadEnabled(void) const;
	 
	/**
	 * Gets the input style of the keypad, which is displayed for the <input> or <textarea> tag.
	 *
	 * @since					2.0
	 * @return		The input style of keypad @n
	 *				The default value of the input style is INPUT_STYLE_FULLSCREEN.
	 */
	 Osp::Ui::Controls::InputStyle GetInputStyle(void) const;

	/**
	* Sets a certificate error handling mode for a %Web control.
	*
	* @since                    2.0
	* @param[in]              mode              Certificate error handling mode
	*/
	void SetCertificateErrorHandlingMode(CertificateErrorHandlingMode mode);

	/**
	* Gets the value of the certificate error handling mode for a %Web control.
	*
	* @since                    2.0
	* @return                  Certificate error handling mode
	*/
	CertificateErrorHandlingMode GetCertificateErrorHandlingMode(void) const;	
	
private:
	CacheMode	__cacheMode;
	Osp::Base::String	__encoding;
	int		__fontSize;
	bool		__javascriptEnabled;
	bool		__autoImageEnabled;	
	
	friend class WebSettingEx;
	class WebSettingEx* __pWebSettingEx;

};

}; };};
#endif


