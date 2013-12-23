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
 * @file		FWebCtrlHitElementResult.h
 * @brief		This is the header file for the %HitElementResult class.
 *
 * This header file contains the declarations of the %HitElementResult class.
 */


#ifndef _FWEB_HITELEMENTRESULT_H_
#define _FWEB_HITELEMENTRESULT_H_

#include "FBase.h"
#include "FBaseColHashMap.h"
#include "FGrpBitmap.h"
#include "FWebConfig.h"


namespace Osp { namespace Web { namespace Controls {


/**
 * @class	HitElementResult
 * @brief		This class provides methods to retrieve information from the HyperText Markup Language (HTML) element, pointed by the x and y coordinates.
 * @since	1.0
 *
 * The %HitElementResult class provides methods to retrieve information from the HTML element, such as tag name, attributes and content.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/controls_namespace.htm">Web Controls Guide</a>.
 * 
 */

class __WebService;

class _EXPORT_WEB_ HitElementResult :
	public Osp::Base::Object
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	~HitElementResult(void);

	/**
	* Gets the tag name of an element.
	*
	* @since		1.0
	* @return		The tag name of the element
	*/
	Osp::Base::String GetTagName(void);

	/**
	* Gets the value of the specified attribute.
	*
	* @since			1.0
	* @return 		The value of the specified attribute
	*
	* @param[in]	attributeName			The name of the attribute 	
	*/
	Osp::Base::String GetAttributeValue(const Osp::Base::String& attributeName);

	/**
	* Gets the content of an element.
	*
	* @since		1.0
	* @return		The content of the element
	*/
	Osp::Base::String GetContent(void);

	/**
	*  Gets the Uniform Resource Locator (URL) linked to the element.
	*
	* @since			1.0
	* @return 		The URL linked to the element
	*/
	Osp::Base::String GetUrl(void);

	/**
	*  Gets the image if the element is an image element.
	*
	* @since					1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*					For more information, see @ref CompGetImage "here".
	* @return 		 The image 
	*/
	const Osp::Graphics::Bitmap* GetImage(void);

	/**
	 * @page   CompGetImage	Compatibility for GetImage()
	 * @section CompGetImageIssues Issues
	 *                   Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * 
	 * -#	Though the original image has alpha channels, the decoded Bitmap object has lost its transparency in versions prior to 1.2.
	 *
	 * @section CompGetImageResolutions Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2 partially, and it is recommended to use bada API version 1.2. or above. @n	
	 *
	 * -#	  In case the original image format is PNG, the Bitmap object is decoded with its alpha channels. However, if the image format is TIFF or BMP, these files are decoded but alpha channels information is ignored due to platform restriction.
	 */
	

	/**
	*  Checks whether the element is an image element.
	*
	* @since			1.0
	* @return 		@c true if the element is an image element, @n
					else @c false
	*/	
	bool HasImage(void);

	/**
	*  Checks whether the element has a URL linked to it.
	*
	* @since			1.0
	* @return 		@c true if there is a URL linked to the element, @n
					else @c false
	*/
	bool HasUrl(void);

private:

	/**
	 * Constructor 
	 */
	HitElementResult(void);

	/**
	 * This is the copy constructor for the %HitElementResult class.
	 */
	HitElementResult(const HitElementResult& element);
	
	/**
	 * This is the assignment operator for this class.
	 */
	HitElementResult& operator=(const HitElementResult& source);

	/**
  	* Initializes this instance of %HitElementResult with the specified parameter. @n
  	* Sets the information of an element.
  	*
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	resultMap			The key-value pair information of the HTML element
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
  	*/
	result Construct(Osp::Base::Collection::IMap &resultMap);

	/*
	 * Clears the objects.
	 *
	 */
	void RemoveAll(void);

private:

	Osp::Base::Collection::IMap	*__pHitResultTable;

	friend class __WebService;

	friend class HitElementResultEx;
	class HitElementResultEx* __pHitElementResultEx;
	
	
};

};};};
#endif

