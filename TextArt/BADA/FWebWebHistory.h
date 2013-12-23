/* $Change: 1234573 $ */
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
 * @file		FWebWebHistory.h
 * @brief		This is the header file for the %WebHistory class.
 * @since		1.0
 *
 * This header file contains the declarations of the %WebHistory class.
 */


#ifndef _FWEB_WEBHISTORY_H_
#define _FWEB_WEBHISTORY_H_

#include "FBase.h"
#include "FWebConfig.h"

namespace Osp { namespace Web {
	class HistoryItem;
	class IHistoryPi;
};};


namespace Osp { namespace Web {


/**
 * @class		WebHistory
 * @brief		This class contains the pages visited by users in a browser.
 * @since		1.0
 *
 * The %WebHistory class is used to retrieve the pages visited by users in a browser. The visited pages are represented by the HistoryItem class.
 * The WEB_PRIVACY privilege is required to use this class.
 * 
 */


class _EXPORT_WEB_ WebHistory 
	:public Osp::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	WebHistory(void);
	
	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	~WebHistory(void);

	/**
	 * Initializes this instance of %WebHistory.
	 *
	 * @since				1.0
   * @privlevel		NORMAL
	 *
	 * @privgroup		WEB_PRIVACY		 
   *
	 * @return 		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	result Construct(void);
	
	
	/**
	 * Gets the history item pointed to by the specified index.
	 *
	 * @since			1.0
	 * @return		The history item at the specified index
	 * @param[in]	index			The index of an element @n
										The value of the index must be greater than or equal to @c 0.
	 * @exception	E_OUT_OF_RANGE		The specified index is out of range.
	 */	
	const HistoryItem* GetItemAt(int index);

	/**
	 * Gets the total number of items.
	 *
	 * @since			1.0
	 * @return		The total number of items
	 */	
	int GetItemCount(void);

	/**
	 * Removes the history item at the specified index.
	 *
	 * @deprecated	This method is deprecated because of privacy policy.
	 *
	 * @since			1.0
	 * @return 		An error code
	 * @param[in]		index		The index of an element @n
									The value of the index must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 */	
	result RemoveItem(int index);


private:
	
	/*
	 * Copy constructor
	 */	 
	WebHistory(const WebHistory& item);	

	/*
	 * Assign operator
	 */	 
	WebHistory& operator =(const WebHistory& item);
	
	

private:
	Osp::Base::Collection::ArrayList __historyList;
	IHistoryPi		*__pHistoryPi;
	
	friend class __WebService;

	friend class WebHistoryEx;
	class WebHistoryEx* __pWebHistoryEx;
	
			
};

};};
#endif


