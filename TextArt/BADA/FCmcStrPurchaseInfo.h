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
 * @file	FCmcStrPurchaseInfo.h
 * @brief	This is the header file for the %PurchaseInfo class.
 *
 * This header file contains the declarations of the %PurchaseInfo class.
 */


#ifndef _FCMC_STORE_PURCHASE_INFO_H_
#define _FCMC_STORE_PURCHASE_INFO_H_

#include "FCmcStrConstants.h"

namespace Osp { namespace Commerce { namespace Store{

class PurchaseInfoEx;

/**
 * @class	PurchaseInfo
 * @brief	This class represents the purchase information in an application.
 * @since	1.0
 *
 * The %PurchaseInfo class provides methods for accessing the purchase information from within an application.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/commerce/purchaseinfo.htm">PurchaseInfo</a>.
 *
 */
class _EXPORT_COMMERCE_ PurchaseInfo  : public Osp::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	PurchaseInfo();
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~PurchaseInfo (void);

public:
	//getters
	/**
	 * Gets the item ID.
	 *
	 * @since			1.0
	 * @return		The item ID
	 */
	ItemId GetItemId(void) const;

	/**
	 * Gets the item name.
	 *
	 * @since			1.0
	 * @return		The name of the item
	 */
	Osp::Base::String GetItemName(void) const;

	/**
	 * Gets the purchase date.
	 *
	 * @since			1.0
	 * @return		The date of the purchase
	 */
	Osp::Base::DateTime GetPurchaseDate(void) const;

	/**
	 * Gets the price of purchase.
	 *
	 * @since			1.0
	 * @return		The price of purchase
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
	 * Gets the item description.
	 *
	 * @since			1.0
	 * @return		The description of the item
	 */
	Osp::Base::String GetItemDesc(void) const;

	/**
	 * Gets the Uniform Resource Identifier (URI) of the image of the item
	 *
	 * @since			1.0
	 * @return		The image URI of the item
	 */
	Osp::Base::Utility::Uri GetItemImageUri(void) const;

	/**
	 * Gets item download URI.
	 *
	 * @since			1.0
	 * @return		The download URI of the item
	 */
	Osp::Base::Utility::Uri GetItemDownloadUri(void) const;

	/**
	 * Gets the payment ID of the purchase.
	 *
	 * @since			1.0
	 * @return		The payment ID of the purchase
	 */
	PaymentId GetPaymentId(void) const;

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
	 * @param[in]	itemId			The item id
	 */
	void SetItemId(const ItemId& itemId);

	/**
	 * Sets the item name
	 *
	 * @param[in]	name		The name of the item
	 */
	void SetItemName(const Osp::Base::String& name);

	/**
	 * Sets the purchase date
	 *
	 * @param[in]	puchaseDate		The date of the purchase
	 */
	void SetPurchaseDate(const Osp::Base::DateTime& purchaseDate);

	/**
	 * Sets the price
	 *
	 * @param[in]	price			The price of the purchase
	 */
	void SetPrice(double price);

	/**
	 * Sets currency of the item price
	 *
	 * @param[in]	currency		The currency of the item price
	 */
	void SetCurrency(const Osp::Base::String& currency);

	/**
	 * Sets the item description
	 *
	 * @param[in]	desc		The description of the item
	 */
	void SetItemDesc(const Osp::Base::String& desc);

	/**
	 * Sets item image URI
	 *
	 * @param[in]	imageUri		An image URI of the item
	 */
	void SetItemImageUri(const Osp::Base::Utility::Uri& imageUri);

	/**
	 * Sets item download URI
	 *
	 * @param[in]	downloadUri		The download URI of the item
	 */
	void SetItemDownloadUri(const Osp::Base::Utility::Uri& downloadUri);

	/**
	 * Sets payment id of the purchase
	 *
	 * @param[in]	paymentId		The payment Id of the purchase
	 */
	void SetPaymentId(const PaymentId& paymentId);

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
	ItemId					__itemId;
	Osp::Base::String		__itemName;
	Osp::Base::DateTime		__purchaseDate;
	double					__price;
	Osp::Base::String		__currency;
	Osp::Base::String		__itemDesc;
	Osp::Base::Utility::Uri	__itemImageUri;
	Osp::Base::Utility::Uri	__itemDownloadUri;
	PaymentId				__paymentId;

	Osp::Base::String		__reserved1;
	Osp::Base::String		__reserved2;

	friend class __XmlProcessor;

private:
	friend class PurchaseInfoEx;
	class PurchaseInfoEx* __pPurchaseInfoEx;
};	// class PurchaseInfo

}; }; };// Osp::Commerce::Store

#endif// _FCMC_STORE_PURCHASE_INFO_H_
