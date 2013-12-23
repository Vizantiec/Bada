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
 * @file		FUiCtrlITokenFilter.h
 * @brief		This is the header file for the %ITokenFilter interface.
 *
 * This header file contains the declarations of the %ITokenFilter interface.
 */
#ifndef _FUICTRL_ITOKEN_FILTER_H_
#define _FUICTRL_ITOKEN_FILTER_H_

// includes
#include "FBaseRtIEventListener.h"

// namespace declaration
namespace Osp { namespace Ui { namespace Controls {
 /**
  * @interface	ITokenFilter
  * @brief		This interface defines the token filter.
  * @since  	2.0
  *
  * The %ITokenFilter interface is the listener interface for replacing tokenized input in the ExpandableEditArea.
  *
  * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_exp_editarea.htm">ExpandableEditArea</a>.
  *
  */
class _EXPORT_CONTROLS_ ITokenFilter
{
// Lifecycle
public:
    /**
     * This is the destructor for this class.
     * @since  2.0
     */
    virtual ~ITokenFilter(void) {}

// Operation
public:
    /**
     * Checks whether the text tokenized by the ExpandableEditArea instance should be replaced.
     *
     * @since       2.0
     * @return      @c true if the text of the current token needs to be replaced, @n
     *              else @c false
     * @param[in]	token      	The text of the current token
     * @param[out]	replacement	The user-defined replacement text
     */
    virtual bool ReplaceToken(const Osp::Base::String& token, Osp::Base::String& replacement) = 0;


// Reserves
protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void ITokenFilter_Reserved1 (void) { }

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void ITokenFilter_Reserved2 (void) { }

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void ITokenFilter_Reserved3 (void) { }
};//ITokenFilter
}; }; };//Osp::Ui::Controls
#endif //_FUICTRL_ITOKEN_FILTER_H_

