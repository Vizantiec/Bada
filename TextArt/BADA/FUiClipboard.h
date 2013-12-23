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
 * @file	FUiClipboard.h
 * @brief	This is the header file containing the declaration of the %Clipboard class.
 *
 * This header file contains the declarations of the %Clipboard class and its helper classes.
 */

#ifndef _FUI_CLIPBOARD_H_
#define _FUI_CLIPBOARD_H_
// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FBaseColIList.h"
#include "FUiConfig.h"
#include "FUiClassType.h"
#include "FUiIClipboard.h"
#include "FUiClipboardItem.h"
#include "FUiIClipboardPopupEventListener.h"

namespace Osp { namespace Ui { namespace Controls { class __ClipboardPopupEvent; } } }
namespace Osp { namespace Ui {
/**
 * @class	Clipboard
 * @brief 	This class defines a common behavior for %Clipboard.
 * @since	2.0
 *
 * The %Clipboard class manages the copy and paste operation between and within applications.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/clipboard.htm">Clipboard</a>.
 * 
 * The following example demonstrates how to use the %Clipboard class.
 * 
 * @code
 * using namespace Osp::Base;
 * using namespace Osp::Ui;
 * //...
 * ClipboardItem item;
 * item.Construct(CLIPBOARD_DATA_TYPE_ADUIO, String(L"/Home/Share/myAudio.mp3")); 
 * //...
 * Clipboard* pClipboard = Clipboard::GetInstance();
 * pClipboard->CopyItem(item); 
 * //...
 * ClipboardItem* pItem = pClipboard->RetrieveLatestItemN(CLIPBOARD_DATA_TYPE_TEXT |
 * CLIPBOARD_DATA_TYPE_AUDIO |
 * CLIPBOARD_DATA_TYPE_VIDEO |
 * CLIPBOARD_DATA_TYPE_HTML); 
 * String pastedString = *((String*) pItem->GetData()); // L"/Share/[appid]/myAudio.mp3"
 * delete pItem;
 * @endcode
 */
class _EXPORT_UI_ Clipboard :
	public Osp::Base::Object,
	public Osp::Ui::IClipboard
{
// Operation
public:
    /**
     * Copies the specified item to the system clipboard.
     *
     * @since       2.0
     * @return      An error code
     * @param[in]   item            	The item to be saved in the system clipboard
     * @exception   E_SUCCESS       	The method is successful.
     * @exception   E_INVALID_ARG   	A specified input parameter is invalid.
     * @exception   E_INVALID_STATE 	This instance is in an invalid state.
     * @exception   E_SYSTEM        	A system error has occurred.
     * @remarks     The method returns @c E_INVALID_ARG if the specified item is not constructed. @n
     *              For the text and image data type, the data itself is copied by the method and kept by the system clipboard.
     */
    result CopyItem(const ClipboardItem& item);

    /**
     * Gets a collection of items that matches the specified data types from the system clipboard.
     *
     * @since       2.0
     * @return      The pointer to an IList which contains a collection of ClipboardItem, @n
     *              else @c null if an error occurs
     * @param[in]   dataTypes       	The types of items @n 
	 *									Multiple data types can be combined using bitwise OR (Osp::Ui::ClipboardDataType).
     * @exception   E_SUCCESS       	The method is successful.
     * @exception   E_OBJ_NOT_FOUND 	The item of the specified data types is not found. 
     * @exception   E_OUT_OF_MEMORY 	The memory is insufficient.
     * @exception   E_INVALID_STATE 	This instance is in an invalid state.
     * @exception   E_SYSTEM        	A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method. @n
     *              This method returns the pointer to an IList that contains a collection of ClipboardItem. The returned pointer to IList and all the 
	 *				elements in IList must be deleted by applications. @n
     *              The items in IList are sorted in the reverse order in which they are copied to the system clipboard. So, the first item in IList is the 
	 *				latest one among them. @n
     *              @c dataType can be a combination of ClipboardDataType.
     */
    Osp::Base::Collection::IList* RetrieveItemsN(unsigned long dataTypes);

    /**
     * Gets the latest item for the specified data types from the system clipboard.
     *
     * @since       2.0
     * @return      The pointer to a %ClipboardItem instance, @n
     *              else @c null if an error occurs
     * @param[in]   dataTypes       The types of items @n
	 *								Multiple data types can be combined using bitwise OR (Osp::Ui::ClipboardDataType).
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_OBJ_NOT_FOUND	The item of the specified data types is not found. 
     * @exception   E_OUT_OF_MEMORY	The memory is insufficient.
     * @exception   E_INVALID_STATE This instance is in an invalid state.
     * @exception   E_SYSTEM        A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method. @n
     *              This method returns the pointer to a %ClipboardItem instance. The returned %ClipboardItem must be deleted by applications. @n 
     *              If there is no matched item in the system clipboard, this method returns @c null. @n
     *              @c dataType can be a combination of ClipboardDataType.
     */
    Osp::Ui::ClipboardItem* RetrieveLatestItemN(unsigned long dataTypes);

    /**
     * Gets the system clipboard.
     *
     * @since	2.0
     * @return	The pointer to the system clipboard
     * @remarks	The copy and paste operation is performed through the system clipboard that can be obtained via this method. @n
     *          The method returns @c null if a system error occurs.
	 */
    static Clipboard* GetInstance(void);

    /**
     * Shows the clipboard popup with the specified parameters.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	dataTypes           The types of items @n 
	 *									Multiple data types can be combined using bitwise OR (Osp::Ui::ClipboardDataType).
     * @param[in]	listener            The clipboard popup event listener
     * @exception	E_SUCCESS           The method is successful.
     * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. 
     * @exception	E_SYSTEM            A system error has occurred.
     * @remark		@c dataTypes can be a combination of %ClipboardDataType. @n
     *				The method returns @c E_INVALID_OPERATION if clipboard popup is currently being shown. Furthermore, attempting to show the clipboard 
	 *				popup when the application is in the background will return @c E_INVALID_OPERATION. @n
     *				The clipboard popup shows the current content of the system clipboard. The user can clear the system clipboard or choose a clipboard item 
	 *				for the paste operation.
     */
    static result ShowPopup(unsigned long dataTypes, const IClipboardPopupEventListener &listener);

    /**
     * Hides the clipboard popup.
     *
     * @since          2.0
     * @return         An error code
     * @exception      E_SUCCESS			The method is successful.
     * @exception      E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
     * @exception      E_SYSTEM				A system error has occurred.
     * @remarks        The method returns @c E_INVALID_OPERATION if no clipboard popup is currently being shown.
     */
    static result HidePopup(void);

    /**
     * Checks whether the clipboard popup is currently being shown.
     *
     * @since		2.0
     * @return		@c true if the clipboard popup is being shown, @n
	 *				else @c false
     */
    static bool IsPopupVisible(void);

protected:
    /**
     * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method. 
	 * 
	 * This is the default class constructor
     * @since   2.0
	 */
	Clipboard(void);

    /**
     * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the destructor for this class.
     * @since   2.0
	 */
	virtual ~Clipboard(void);

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
	Clipboard(const Clipboard& clipboard);

    /**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Initializes this instance of Clipboard.
     * @since   2.0
	 */
	result Construct(void);

    /**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the assignment operator for this class.
     * @since   2.0
	 */
	Clipboard& operator=(const Clipboard& clipboard);

    /**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Gets the selected item at the clipboard popup.
     * @since   2.0
	 */
	Osp::Ui::ClipboardItem* RetrieveSelectedItemN(unsigned long dataTypes);

protected:
	friend class ClipboardImpl;
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Gets the implementation instance of this control
     *
     * @since         2.0
     */
	class ClipboardImpl* GetImpl(void) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Replaces the implementation instance of this control
     *
     * @since         2.0
     */
	void SetImpl(class ClipboardImpl* pImpl);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Checks if the implementation instance of this control already exists
     *
     * @since         2.0
     */
	bool HasRefToImpl(void) const;

private:
	friend class __ControlManager;
	friend class ClipboardEx;
	friend class Osp::Ui::Controls::__ClipboardPopupEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * The internal data structure.
	 * @since         2.0
     */
	class ClipboardEx* __pClipboardEx;
};
};};//Osp::Ui
#endif //_FUI_CLIPBOARD_H_
