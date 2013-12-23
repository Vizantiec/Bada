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
 * @file	FUiIClipboard.h
 * @brief	This is the header file for the %IClipboard interface.
 *
 * This header file contains the declarations of the %IClipboard class and its helper classes.
 */
#ifndef _FUI_ICLIPBOARD_H_
#define _FUI_ICLIPBOARD_H_
// include
#include "FUiClipboardItem.h"

namespace Osp { namespace Ui {
/**
 * @internal
 * @interface	IClipboard
 * @brief 	    This interface defines the operations of IClipboard.
 * @since	    2.0
 *
 * The IClipboard interface defines the operations of clipboard. This is internal. 

 */
class _EXPORT_UI_ IClipboard 
{
// Lifecycle
public:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the destructor for this class.
     * @since   2.0
	 */
	virtual ~IClipboard(void) {};

    
// Operation
public:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Copies the specified item to the system Clipboard.
     *
     * @since       2.0
     * @return      An error code
     * @param[in]   item            The item to be saved in the system clipboard
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_ARG   A specified input parameter is invalid.
     * @exception   E_INVALID_STATE This instance is in an invalid state.
     * @exception   E_SYSTEM        A system error occurred.
     * @remarks    The method returns E_INVALID_ARG if the specified item is
     *              not constructed. @n
     *              For the text and image data type, the data itself is copied 
     *              by the method and kept by the system clipboard. 
     */
    virtual result CopyItem(const ClipboardItem& item) = 0;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Gets a collection of items that matches the specified data types from the 
     * system clipboard.
     *
     * @since       2.0
     * @return      The pointer to an IList which contains a collection of ClipboardItem. @n
     *              @c null, if an error occurs.
     * @param[in]   dataTypes       The types of items. Multiple data types can be 
     *                              combined using bitwise OR (Osp::Ui::ClipboardDataType).
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_OBJ_NOT_FOUND The items of the specified data are not found. 
     * @exception   E_OUT_OF_MEMORY Insufficient memory.
     * @exception   E_INVALID_STATE This instance is in an invalid state.
     * @exception   E_SYSTEM        A system error occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method. @n
     *              This method returns the pointer to an IList which contains  
     *              a collection of ClipboardItem. The returned pointer to IList  
     *              and all elements in IList must be deleted by applications. @n
     *              The items in IList are sorted in the reverse order in which
     *              they are copied to the system clipboard. So, the first
     *              item in IList is the latest one among them. @n
     *              @c dataType can be a combination of ClipboardDataType.
     */
    virtual Osp::Base::Collection::IList* RetrieveItemsN(unsigned long dataTypes) = 0;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
     *
     * Gets the latest item for the specified data types from the system clipboard.
     *
     * @since       2.0
     * @return      The pointer to a ClipboardItem @n
     *              @c null, if an error occurs.
     * @param[in]   dataTypes       The types of items. Multiple data types can be 
     *                              combined using bitwise OR (Osp::Ui::ClipboardDataType).
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_OBJ_NOT_FOUND The item of the specified data types is not found. 
     * @exception   E_OUT_OF_MEMORY Insufficient memory.
     * @exception   E_INVALID_STATE This instance is in an invalid state.
     * @exception   E_SYSTEM        A system error occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method. @n
     *              This method returns the pointer to a ClipboardItem. The
     *              returned ClipboardItem must be deleted by applications. @n 
     *              If there is no matched item in the system clipboard, this method 
     *              returns @c null. @n
     *              @c dataType can be a combination of ClipboardDataType.
     */
    virtual Osp::Ui::ClipboardItem* RetrieveLatestItemN(unsigned long dataTypes) = 0;

  
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
	virtual void Clipboard_Reserved1 (void) { }

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
	virtual void Clipboard_Reserved2 (void) { }

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
	virtual void Clipboard_Reserved3 (void) { }

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
	virtual void Clipboard_Reserved4 (void) { }

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
	virtual void Clipboard_Reserved5 (void) { }
};
};};//Osp::Ui
#endif //_FUI_ICLIPBOARD_H_
