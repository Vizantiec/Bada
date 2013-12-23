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
 * @file		FWebHistoryItem.h
 * @brief		This is the header file for the %HistoryItem class.
 *
 * This header file contains the declarations of the %HistoryItem class.
 */



#ifndef _FWEB_HISTORYITEM_H_
#define _FWEB_HISTORYITEM_H_

#include "FBase.h"
#include "FGrpBitmap.h"
#include "FWebConfig.h"

namespace Osp { namespace Web { namespace Controls {
	class PageNavigationList;
	class __WebService;
};};};

namespace Osp { namespace Web {


/**
 * @class		HistoryItem
 * @brief		This class is used for accessing a history item stored in the PageNavigationList class or the WebHistory class.
 * @since		1.0
 *
 * The %HistoryItem class provides access to the Controls::PageNavigationList class item and the WebHistory class.
 * Each item contains the title and the URL of the page visited.
 */

class WebHistory;

class _EXPORT_WEB_ HistoryItem:
	public Osp::Base::Object
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	~HistoryItem(void);

	/**
	 * Gets the page title of the current history item.
	 *
	 * @since			1.0
	 * @return		The title of the current history item
	 */
	Osp::Base::String	GetTitle(void) const;

	/**
	 * Gets the URL of the current history item.
	 *
	 * @since			1.0
	 * @return		The URL of the current history item
	 */
	Osp::Base::String	GetUrl(void) const;

private:

	/*
	 * Constructor
	 */	 
	HistoryItem(void);	

	/*
  	 * Sets the information of an element.
  	 *
	 * @return			An error code
  	 */
	result Construct(void);
	
	/*
	 * Sets the title of a visited page to create a history item.
	 *
	 * @param[in]		title			The title of a visited page
	 */
 	void 	SetTitle(const Osp::Base::String&	title);
 	
	/*
	 * Sets the URL of a visited page to create a history item.
	 *
	 * @param[in]		url			The URL of a visited page
	 */	
	void 	SetUrl(const Osp::Base::String&		url);

	/*
	 * Sets the visited time of a visited page to create a history item.
	 *
	 * @param[in]		visitTime			The visited time of a visited page
	 */	
	void 	SetVisitedTime(unsigned long visitTime);

	/*
	 * Gets the visited time of a visited page to create a history item.
	 *
	 * @return		The visited time of a visited page
	 */	
	unsigned long 	GetVisitedTime(void);
	
	
	/*
	 * Copy constructor
	 */	 
	HistoryItem(const HistoryItem& item);	

	HistoryItem& operator =(const HistoryItem& item);
	
private:
	Osp::Base::String		__title;
	Osp::Base::String		__url;

	friend class Osp::Web::Controls::PageNavigationList;
	friend class Osp::Web::WebHistory;
	friend class Osp::Web::Controls::__WebService;

	friend class HistoryItemEx;
	class HistoryItemEx* __pHistoryItemEx;
	

};

};};
#endif



