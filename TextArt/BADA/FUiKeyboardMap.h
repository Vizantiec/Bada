//
// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
// 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/** 
 * @file		FUiKeyboardMap.h
 * @brief		This is the header file for the %KeyboardMap class.
 *
 * This header file contains the declarations of the %KeyboardMap class. @n.
 */
#ifndef _FUI_KEYBOARD_MAP_H_
#define _FUI_KEYBOARD_MAP_H_

// Includes
#include "FBaseObject.h"
#include "FBaseErrors.h"
#include "FBaseString.h"
#include "FUiConfig.h"
#include "FUiIKeyEventListener.h"

namespace Osp {namespace Ui {
/**
 * @enum	KeyboardKeyLabelType
 * Defines the key label types. It defines the types of labels that are printed on the corresponding key of the QWERTY keyboard. Only the printing 
 * keys have one or more text labels.
 * @deprecated 	This enum is deprecated because it is not supported by the platform.
 * @since  1.1 
 */
enum KeyboardKeyLabelType
{
	/**
	 *	The first label to be displayed.
	 */
	KEYBOARD_KEY_LABEL_1	= 0x0000,	

	/**
	 *	The second label to be displayed after KEY_CAPSLOCK or KEY_FN is pressed
	 */
	KEYBOARD_KEY_LABEL_2,	

	/**
	 *	The third label to be displayed when the key is toggled twice (without pressing KEY_CAPSLOCK or KEY_FN)
	 */
	KEYBOARD_KEY_LABEL_3,

	/**
	 *	The fourth label to be displayed when the key is toggled the third time (without pressing KEY_CAPSLOCK or KEY_FN)
	 */
	KEYBOARD_KEY_LABEL_4,

	/*
	 *	The max value
	 */
	KEYBOARD_KEY_LABEL_MAX  = 255
};    

    
/**
 * @class	KeyboardMap 
 * @brief	This class manages the hardware keyboard key mapping.
 * @deprecated 	This class is deprecated because it is not supported by the platform.
 * @since	1.1
 *
 * The %KeyboardMap class maintains a map of hardware keys. You can query the current 
 * hardware keyboard type of the device and check the availability of a 
 * specific key. Furthermore, you can query the labels that are printed on the  
 * hardware keyboard of a specific key.
 *
 *
 * The following example demonstrates how to get the type of the keyboard and the property of each key:
 *
 * @code
 * KeyboardMap* pKeyboardMap = KeyboardMap::GetInstance();
 * if (pKeyboardMap != null)
 * {
 *     // Gets keyboard type
 *     String type = pKeyboardMap->GetKeyboardType();
 *     AppLog("The current hardware keyboard type = %S", type.GetPointer());
 * 
 *     // Checks HW key properties
 *     bool available = pKeyboardMap->IsKeyAvailable(KEY_A);
 *     bool printing  = pKeyboardMap->IsPrintingKey(KEY_A);
 *     String l1 = pKeyboardMap->GetDisplayableLabel(KEY_A);
 *     String l2 = pKeyboardMap->GetDisplayableLabel(KEY_A, KEYBOARD_KEY_LABEL_2);
 *     String l3 = pKeyboardMap->GetDisplayableLabel(KEY_A, KEYBOARD_KEY_LABEL_3);
 *     String l4 = pKeyboardMap->GetDisplayableLabel(KEY_A, KEYBOARD_KEY_LABEL_4);
 * }
 * @endcode
 */
class _EXPORT_UI_ KeyboardMap :
	public Osp::Base::Object
{
// Life-cycle
protected:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.1
	 */
	KeyboardMap(void);


	/**
	 * Initializes this instance.
	 *
	 * @since		1.1
 	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY The memory is insufficient.
	 * @exception	E_IO            An IO error has occurred.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result Construct(void);
	
	
public:		    
	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.1
	 */
	virtual ~KeyboardMap(void);


    /**
     * Gets the pointer to the %KeyboardMap instance.
     *
     * @deprecated    This method is deprecated.
     * @since	1.1
     * @return  The current %KeyboardMap instance
     */
    static KeyboardMap* GetInstance(void);


// Operation
public:
    /**
     * Checks whether the specified key is a printing key (the key has one or more labels printed on the corresponding key).
     *
     * @deprecated    This method is deprecated.
     * @since		1.1
     * @return    	@c true if the specified key is a printing key, @n
 	 *				else @c false
     * @param[in]	keyCode 	The key	 
     */
    bool IsPrintingKey(KeyCode keyCode) const;
    
    
    /**
     * Checks whether the specified key is available on the current keyboard.
     *
     * @deprecated    This method is deprecated.
     * @since		1.1
     * @return      @c true if the specified key is available on the current keyboard, @n 
	 *				else @c false
     * @param[in]	keyCode 	The key	 
     */
    bool IsKeyAvailable(KeyCode keyCode) const;


    /**
	 * Gets the name of the keyboard type.
	 *
	 * @deprecated    This method is deprecated.
	 * @since		1.1
	 * @return		The name of the keyboard type 
	 * @remarks		The name of the keyboard type follows the following naming convention: @n
	 *          	GENERAL-TYPE_KEY-LAYOUT_LANGUAGE/COUNTRY/REGION (for example, QWERTY_11x4_EUROPE, 
	 *          	NUMERIC_3x4_EUROPE). @n If the device does not have a keyboard, the method returns "NONE". @n
	 * @remarks
	 * Supported keyboard types
	 * <table>
	 * <tr> <td> Keyboard Type              </td> <td> Languages                        </td> </tr>
	 * <tr> <td> QWERTY_11x4_GLOBAL         </td> <td> English                          </td> </tr>
	 * <tr> <td> QWERTY_11x4_EUROPE         </td> <td> English                          </td> </tr>
	 * <tr> <td> QWERTY_11x4_UK     	    </td> <td> English                          </td> </tr>
	 * <tr> <td> QWERTY_11x4_FRANCE	        </td> <td> French, English                  </td> </tr>
 	 * <tr> <td> QWERTY_11x4_GERMAN         </td> <td> German, English                  </td> </tr>
	 * <tr> <td> QWERTY_11x4_GREECE         </td> <td> Greek, English                   </td> </tr>
	 * <tr> <td> QWERTY_11x4_ITALY          </td> <td> Italian, English                 </td> </tr>
	 * <tr> <td> QWERTY_11x4_NORDIC	        </td> <td> North Germanic                   </td> </tr>
	 * <tr> <td> QWERTY_11x4_RUSSIA         </td> <td> Russian, English                 </td> </tr>
	 * <tr> <td> QWERTY_11x4_SPAIN          </td> <td> Spanish, English                 </td> </tr>
	 * <tr> <td> QWERTY_11x4_TURKEY         </td> <td> English                          </td> </tr>
	 * <tr> <td> QWERTY_11x4_NORTH-AFRICA   </td> <td> English, English                 </td> </tr>
	 * <tr> <td> QWERTY_11x4_ARAB	        </td> <td> Arabic, English                  </td> </tr>
	 * <tr> <td> QWERTY_11x4_IRAN	        </td> <td> Farsi, English                   </td> </tr>
	 * <tr> <td> QWERTY_11x4_PARKISTAN	    </td> <td> Urdu, English                    </td> </tr>
	 * <tr> <td> QWERTY_11x4_ISRAEL	        </td> <td> Hebrew, English                  </td> </tr>
	 * <tr> <td> QWERTY_11x4_CHINA	        </td> <td> English                          </td> </tr>
	 * <tr> <td> QWERTY_11x4_HONGKONG	    </td> <td> Chinese Traditional, English     </td> </tr>
	 * <tr> <td> QWERTY_11x4_SINGAPORE	    </td> <td> English                          </td> </tr>
	 * <tr> <td> QWERTY_11x4_THAILAND	    </td> <td> Thai, English                    </td> </tr>
	 * <tr> <td> QWERTY_11x4_TAIWAN	        </td> <td> Chinese Traditional, English     </td> </tr>
	 * <tr> <td> QWERTY_11x4_VIETNAM	    </td> <td> Vietnamese, English              </td> </tr>
	 * <tr> <td> QWERTY_11x4_JAPAN	        </td> <td> Japanese, English                </td> </tr>
	 * <tr> <td> QWERTY_11x4_KOREA	        </td> <td> Korean, English                  </td> </tr>
	 * <tr> <td> QWERTY_11x4_NORTH-AMERICA	</td> <td> English                          </td> </tr>
	 * </table>     
   */
    Osp::Base::String GetKeyboardType(void) const;
    

    /**
     * Gets the label of the specified key.
     *
     * @deprecated    This method is deprecated.
     * @since		1.1
     * @return    	The text of the label, @n
	 *				else an empty string if the specified key is not a printing key or the secondary/tertiary character label is not defined
     * @param[in]	keyCode 	The key	 
     * @param[in]	type 	    The keyboard key label type
     */
    Osp::Base::String GetDisplayableLabel(KeyCode keyCode, KeyboardKeyLabelType type = KEYBOARD_KEY_LABEL_1) const;


 // Operation
protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Gets KeyCode of the specified system key.
     *
     * @since		1.1
 	 * @return		The key code
	 * @param[in] 	systemKeyCode   The system key
     */    
    KeyCode GetKeyCode(int systemKeyCode) const;
    
    
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Loads keyboard map table from file.
     *
     * @since		1.1
 	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_IO            An unexpected IO error occurred.
	 * @exception	E_SYSTEM		A system error has occurred.
     */     
    result LoadKeyboarMapFromFile(void);
    

    
// Attributes
protected:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The extension.
	 *
	 * @since	1.1
	 */	
    void* pEx;
    
    
    friend class __KeyEventAdaptor;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_KEYBOARD_MAP_H_
