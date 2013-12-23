/* $Change: 1219497 $ */
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
 * @file		FWebCtrlPageNavigationList.h
 * @brief		This is the header file for the %PageNavigationList class.
 *
 * This header file contains the declarations of the %PageNavigationList class.
 */


#ifndef _FWEB_NAVIGATIONLIST_H_
#define _FWEB_NAVIGATIONLIST_H_

#include "FBase.h"
#include "FWebConfig.h"

namespace Osp { namespace Web {
	class HistoryItem;
};};

namespace Osp { namespace Web { namespace Controls {


/**
 * @class	PageNavigationList
 * @brief		This class contains the back and forward list for a %Web control.
 * @since	1.0
 *
 * The %PageNavigationList class provides the back and forward list for a Web control.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/controls_namespace.htm">Web Controls Guide</a>.
 */

class __WebService;

class _EXPORT_WEB_ PageNavigationList :
	public Osp::Base::Object
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @deprecated	This method is deprecated because this class is not user data class but the one made by system.	 	 
	 * @since	1.0
	 */
	PageNavigationList(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	~PageNavigationList(void);
	

	/**
	 * Gets the current history item.
	 *
	 * @since			1.0
	 * @return		The current history item, @n
					else @c null if no history item exists
	 */
	const Osp::Web::HistoryItem* GetCurrentItem(void) const;

	/**
	 * Gets the index of the current history item.
	 *
	 * @since			1.0
	 * @return		The index of the currently viewed page in the %Web page navigation list, @n 
	 *					else @c -1 if no history item exists
	 */
	int GetCurrentIndex(void) const;

	/**
	 * Gets the history item pointed to by the specified @c index.
	 *
	 * @since			1.0
	 * @return		                A pointer to the history item at the specified @c index
	 * @param[in]		index		The index of an element @n
									The value of the index must be greater than or equal to @c 0.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is out of range.
	 */	
	const Osp::Web::HistoryItem* GetItemAt(int	index) const;

	/**
	 * Gets the total number of the history items.
	 *
	 * @since			1.0
	 * @return		The total number of items
	 */	
	int GetItemCount(void) const;
	
private:
	
	/**
	 * Sets the current index
	 *
	 * @param[in]		current		The index of a current element
	 */	
	void SetCurrentIndex(int current);

	/**
	 * Gets the history item pointed by index.
	 *
	 * @return		An error code
	 * @param[in]		index				The index of a element[ index >=0]
	 * @exception  	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY	    The memory is insufficient.
	 */	
	result AddItem(Osp::Web::HistoryItem& item);		

private:
	int __current;
	Osp::Base::Collection::ArrayList	 __navigationList;
	
	friend class __WebService;

	friend class PageNavigationListEx;
	class PageNavigationListEx* __pPageNavigationListEx;
	
			
};

};};};
#endif


