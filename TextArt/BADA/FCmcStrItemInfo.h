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
 * @file	FCmcStrItemInfo.h
 * @brief	This is the header file for the %ItemInfo class.
 *
 * This header file contains the declarations of the %ItemInfo class.
 */


#ifndef _FCMC_STORE_ITEM_INFO_H_
#define _FCMC_STORE_ITEM_INFO_H_

#include "FCmcStrConstants.h"

namespace Osp { namespace Commerce { namespace Store{

class ItemInfoEx;

/**
 * @class	ItemInfo
 * @brief	This class provides the methods for accessing the item information from within an application.
 * @since	1.0
 *
 * The %ItemInfo class provides the methods for accessing the item information from within an application.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/commerce/iteminfo.htm">ItemInfo</a>.
 *
 */
class _EXPORT_COMMERCE_ ItemInfo  : public Osp::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	ItemInfo();
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~ItemInfo (void);

public:
	//getters
	/**
	 * Gets the item ID.
	 *
	 * @since			1.0
	 * @return		The item ID
	 */
	ItemId GetId(void) const;

	/**
	 * Gets the item name.
	 *
	 * @since			1.0
	 * @return		The name of the item
	 */
	Osp::Base::String GetName(void) const;

	/**
	 * Gets the item description.
	 *
	 * @since			1.0
	 * @return		The description of the item
	 */
	Osp::Base::String GetDesc(void) const;

	/**
	 * Gets the item price.
	 *
	 * @since			1.0
	 * @return		The price of the item
	 */
	double GetPrice(void) const;

	/**
	 * Gets the currency of the item price.
	 *
	 * @since			1.0
	 * @return		The currency of the item price
	 */
	Osp::Base::String GetCurrency(void) const;

	/**
	 * Gets the Uniform Resource Identifier (URI) of the image of the item.
	 *
	 * @since			1.0
	 * @return		The image URI of the item
	 */
	Osp::Base::Utility::Uri GetImageUri(void) const;

	/**
	 * Gets item download URI.
	 *
	 * @since			1.0
	 * @return		The download URI of the item
	 */
	Osp::Base::Utility::Uri GetDownloadUri(void) const;

	/**
	 * Gets the data of the reserved field 1.
	 *
	 * @since			1.0
	 * @return		The data of the reserved field 1
	 */
	Osp::Base::String GetReserved1(void) const;

	/**
	 * Gets the data of the reserved field 2.
	 *
	 * @since			1.0
	 * @return		The data of the reserved field 2
	 */
	Osp::Base::String GetReserved2(void) const;

private:
	//setters
	/**
	 * Sets the item id
	 *
	 * @param[in]	id			The item id
	 */
	void SetId(const ItemId& id);

	/**
	 * Sets the item name
	 *
	 * @param[in]	name		The name of the item
	 */
	void SetName(const Osp::Base::String& name);

	/**
	 * Sets the item description
	 *
	 * @param[in]	desc		The description of the item
	 */
	void SetDesc(const Osp::Base::String& desc);

	/**
	 * Sets the item price
	 *
	 * @param[in]	price		The price of the item
	 */
	void SetPrice(double amount);

	/**
	 * Sets currency of the item price
	 *
	 * @param[in]	currency		The currency of the item
	 */
	void SetCurrency(const Osp::Base::String& currency);

	/**
	 * Sets item image URI
	 *
	 * @param[in]	imageUri		An image URI of the item
	 */
	void SetImageUri(const Osp::Base::Utility::Uri& imageUri);

	/**
	 * Sets item download URI
	 *
	 * @param[in]	downloadUri		The download URI of the item
	 */
	void SetDownloadUri(const Osp::Base::Utility::Uri& downloadUri);

	/**
	 * Sets reserved field 1
	 *
	 * @param[in]	data		The data for reserved field 1
	 */
	void SetReserved1(const Osp::Base::String& data);

	/**
	 * Sets reserved field 2
	 *
	 * @param[in]	data		The data for reserved field 2
	 */
	void SetReserved2(const Osp::Base::String& data);

private:
	ItemId					__id;
	Osp::Base::String		__name;
	Osp::Base::String		__desc;
	double					__price;
	Osp::Base::String		__currency;
	Osp::Base::Utility::Uri	__imageUri;
	Osp::Base::Utility::Uri	__downloadUri;

	Osp::Base::String		__reserved1;
	Osp::Base::String		__reserved2;

	friend class __XmlProcessor;

private:
	friend class ItemInfoEx;
	class ItemInfoEx* __pItemInfoEx;
};	// class ItemInfo

}; }; };// Osp::Commerce::Store

#endif// _FCMC_STORE_ITEM_INFO_H_
