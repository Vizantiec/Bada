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
 * @file	FUiClipboardItem.h
 * @brief	This is the header file for the %ClipboardItem class.
 *
 * This header file contains the declarations of the %ClipboardItem class and its helper classes.
 */
#ifndef _FUI_CLIPBOARD_ITEM_H_
#define _FUI_CLIPBOARD_ITEM_H_

//Include
#include "FUiClipboardEnum.h"

namespace Osp { namespace Ui {
/**
 * @class	ClipboardItem
 * @brief 	This class defines a common behavior for %ClipboardItem.
 * @since	2.0
 *
 * The %ClipboardItem class represents the items in the system Clipboard. The %ClipboardItem is the unit of data handling between
 * the system clipboard and applications, and it contains both data itself and the type of the data. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/clipboard.htm">Clipboard</a>.
 *
 */
class _EXPORT_UI_ ClipboardItem :
    public Osp::Base::Object
{
// Lifecycle
public:
   	/**
	 * This is the default constructor for this class.
	 *
     * @since   2.0
	 */
	ClipboardItem(void);

	/**
	 * This is the destructor for this class.
	 *
     * @since   2.0
	 */
	virtual ~ClipboardItem(void);

	/**
	 * Initializes this instance of %ClipboardItem with the specified parameters.
	 *
     * @since     	2.0
	 * @return		An error code
	 * @param[in] 	dataType         	The data type
	 * @param[in] 	data             	The data to be copied
	 * @exception 	E_SUCCESS        	The method is successful.
	 * @exception 	E_OUT_OF_MEMORY  	The memory is insufficient.
     * @exception 	E_INVALID_ARG   	A specified input parameter is invalid.
	 * @exception 	E_INVALID_STATE  	This instance has already been constructed.
	 * @exception 	E_SYSTEM         	A system error has occurred.
	 * @remarks   	For the image data type, the bitmap instance should be deleted by the application after the item is copied to the clipboard.
	 */
	result Construct(ClipboardDataType dataType, const Osp::Base::Object& data);

// Operation
public:
    /**
     * Gets the data type of %ClipboardItem.
     *
     * @since   	2.0
     * @return  	The data type of the clipboard item
     */
    ClipboardDataType GetDataType(void) const;
    
    /**
     * Gets the data of %ClipboardItem.
     *
     * @since   	2.0
     * @return  	The pointer to the data 
     * @remarks 	The application needs to type-cast the returned data object according to its data type.
     */
    Osp::Base::Object* GetData(void) const;

private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the copy constructor for this class.
     * @since   2.0
	 */
	ClipboardItem(const ClipboardItem& clipboardItem);
	
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the assignment operator for this class.
     * @since   2.0
	 */
	ClipboardItem& operator=(const ClipboardItem& clipboardItem);

	/**
     * @internal
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Initializes this instance of %ClipboardItem with the specified parameters.
	 *
     * @since     	2.0
	 * @return		An error code
	 * @param[in] 	dataType         	The data type
	 * @param[in] 	data             	The data to be copied
	 * @param[in] 	imageDataType      The data type of the image
	 * @exception 	E_SUCCESS        	The method is successful.
	 * @exception 	E_OUT_OF_MEMORY  	The memory is insufficient.
     * @exception 	E_INVALID_ARG   	A specified input parameter is invalid.
	 * @exception 	E_INVALID_STATE  	This instance has already been constructed.
	 * @exception 	E_SYSTEM         	A system error has occurred.
	 * @remarks   	For the image data type, the bitmap instance should be deleted by the application after the item is copied to the clipboard.
	 */
	result Construct(ClipboardDataType dataType, const Osp::Base::Object& data, unsigned long imageDataType);

protected://
	friend class Clipboard;
	friend class ClipboardEx;
	friend class ClipboardItemEx;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * @since         2.0
	 */
	class ClipboardItemEx* __pClipboardItemEx;
};
}; }; // Osp::Ui
#endif// _FUI_CLIPBOARD_ITEM_H_
