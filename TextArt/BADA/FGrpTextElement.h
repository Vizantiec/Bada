/* $Change: 1028567 $ */
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
 * @file    FGrpTextElement.h
 * @brief   This is the header file for the %TextElement class.
 *
 * This header file contains the declarations of the %TextElement class.
 */

#ifndef _FGRP_TEXT_ELEMENT_H_
#define _FGRP_TEXT_ELEMENT_H_

#include "FBase.h"
#include "FBaseObject.h"
#include "FBaseUtilTypes.h"
#include "FGrpConfig.h"
#include "FGrpFont.h"
#include "FGrpCanvas.h"
#include "FGrpColor.h"
#include "FGrpEnrichedText.h"

namespace Osp { namespace Base { class String; }; };
namespace Osp { namespace Graphics { class Color; }; };
namespace Osp { namespace Graphics { class Canvas; }; };
namespace Osp { namespace Graphics { class ITextElementPi; }; };
namespace Osp { namespace Graphics { class EnrichedText; }; };

namespace Osp { namespace Graphics {
/**
 * @class   TextElement
 * @brief   This class provides the methods for the text elements.
 * @since   1.0
 *
 * The %TextElement class encapsulates the characteristics of a text, such as the constant string and font style.
 * A text element draws the text on to a canvas.
 *
 * For more information on the attributes of %TextElement, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/graphics/enriched_text.htm">EnrichedText</a>.
 *
 */
class _EXPORT_GRP_ TextElement
    : public Osp::Base::Object
{
// Lifecycle
public:
    /** 
     * This is the default constructor for this class.
     *
     * @since		1.0
     * @remarks     After creating an instance of this class, one of the
     *              Construct() methods must be called explicitly to initialize this instance.
     */
    TextElement(void);

    /**
     * This is the destructor for this class.
     *
     * @since		1.0
     */
    virtual ~TextElement(void);

    /**
     * Initializes the current instance of TextElement with the specified text. @n
     * If the text is not specified, the default system font is set.
     *
     * @since       1.0
     * @return      An error code
     * @param[in]   text                The text string
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
     * @exception   E_INVALID_ARG       The specified input parameter is invalid.
     */
    result Construct(const Osp::Base::String&  text);

    /**
     * Initializes the current instance of TextElement with the specified text. @n
     * The canvas is used for initializing the font's color attributes, such as the foreground color and the background color.
     *
     * @since       1.0
     * @return      An error code
     * @param[in]   text                The text string
     * @param[in]   canvas              The canvas to initialize the text element @n
     *                                  It sets the foreground and background colors of the text element.
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
     * @exception   E_INVALID_ARG       A specified input parameter is invalid.
     */
    result Construct(const Osp::Base::String& text, const Osp::Graphics::Canvas& canvas);  

    /**
     * Initializes the current instance of TextElement.
     *
     * @since       2.0
     * @return      An error code
     * @exception   E_SUCCESS            The method is successful.
     * @exception 	E_INVALID_STATE	     This instance is in an invalid state.
     * @exception   E_OUT_OF_MEMORY      The memory is insufficient.
     * @exception  	E_SYSTEM             An unknown operating system error has occurred.
     * @remarks     To set the text, use the SetText() method.
     * @see         SetText()
     */
    result Construct(void);

    /**
     * Initializes the current instance of TextElement to represent a linked text with the specified link information. @n
     * If the link information is not specified, the default system font is set.
     *
     * @since     2.0
     * @return    An error code
     * @param[in] text             The linked text string
     * @param[in] linkType         The link type
     * @param[in] link             The string that contains the actual link
     * @exception E_SUCCESS        The method is successful.
     * @exception E_INVALID_STATE  This instance has already been constructed.
     * @exception E_OUT_OF_MEMORY  The memory is insufficient.
     * @exception E_INVALID_ARG    A specified input parameter is invalid.
     * @exception E_SYSTEM         An unknown operating system error has occurred.
     * @remarks   If the specified @c text is an empty string or
     *            @c linkType is LINK_TYPE_NONE, the method returns E_INVALID_ARG.
     * @see       Osp::Base::Utility::LinkInfo
     */
    result Construct(const Osp::Base::String& text, Osp::Base::Utility::LinkType linkType, const Osp::Base::String& link);

    /**
     * Initializes the current instance of TextElement with the specified text and autolink mask. @n
     * If the text and autolink mask are not specified, the default system font is set.
     *
     * @since     2.0
     * @return    An error code
     * @param[in] text             The text string
     * @param[in] autoLink         The autolink mask @n
	 *                             Multiple link types can be combined using the bitwise OR operator (Osp::Base::Utility::LinkType). @n
	 *                             For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/auto_link_detection.htm">AutoLink Detection</a>.
     * @exception E_SUCCESS        The method is successful.
     * @exception E_INVALID_STATE  This instance has already been constructed.
     * @exception E_INVALID_ARG    A specified input parameter is invalid.
     * @exception E_OUT_OF_MEMORY  The memory is insufficient.
     * @exception E_SYSTEM         An unknown operating system error has occurred.
     * @remarks   If @c text contains more than one detectable link, the first link is converted
     *            to a linked text and the rest of the links are ignored.
     * @see       Osp::Base::Utility::LinkType
     */
    result Construct(const Osp::Base::String& text, unsigned long autoLink);

    /**
     * Initializes the current instance of TextElement to represent a linked text with the specified link information. @n
     * If the link information is not specified, the default system font is set.
     *
     * @since     2.0
     * @return    An error code
     * @param[in] text             The linked text string
     * @param[in] linkType         The link type
     * @param[in] link             The string that contains the actual link
     * @param[in] canvas           The canvas to initialize the text element @n
     *                             It sets the foreground and background colors of the text element.
     * @exception E_SUCCESS        The method is successful.
     * @exception E_INVALID_STATE  This instance has already been constructed.
     * @exception E_OUT_OF_MEMORY  The memory is insufficient.
     * @exception E_INVALID_ARG    A specified input parameter is invalid.
     * @exception E_SYSTEM         An unknown operating system error has occurred.
     * @remarks   If the specified @c text is an empty string or
     *            @c linkType is LINK_TYPE_NONE, the method returns E_INVALID_ARG.
     * @see       Osp::Base::Utility::LinkType
     */
    result Construct(const Osp::Base::String& text, Osp::Base::Utility::LinkType linkType, const Osp::Base::String& link, const Osp::Graphics::Canvas& canvas);

    /**
     * Initializes the current instance of TextElement with the specified text, autolink mask, and graphics canvas. @n
     * If the parameters are not specified, the default system font is set.
     *
     * @since     2.0
     * @return    An error code
     * @param[in] text             The text string
     * @param[in] autoLink         The autolink mask @n
	 *                             Multiple link types can be combined using the bitwise OR operator (Osp::Base::Utility::LinkType). @n
	 *                             For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/auto_link_detection.htm">AutoLink Detection</a>.
     * @param[in] canvas           The canvas to initialize the text element @n
     *                             It sets the foreground and background colors of the text element.
     * @exception E_SUCCESS        The method is successful.
     * @exception E_INVALID_STATE  This instance has already been constructed.
     * @exception E_INVALID_ARG    A specified input parameter is invalid.
     * @exception E_OUT_OF_MEMORY  The memory is insufficient.
     * @exception E_SYSTEM         An unknown operating system error has occurred.
     * @remarks   If @c text contains more than one detectable link, the first link is converted
     *            to a linked text and rest of the links are ignored.
     * @see       Osp::Base::Utility::LinkType
     */
    result Construct(const Osp::Base::String& text, unsigned long autoLink, const Osp::Graphics::Canvas& canvas);

    /**
     * Gets the string that contains the actual link.
     *
     * @since      2.0
     * @return     The string that contains the actual link
     * @remarks    If the text element contains no linked text, the method returns an empty string.
     */
    Osp::Base::String GetLink(void) const;

    /**
     * Gets the type of the link of the text element.
     *
     * @since      2.0
     * @return     The string that contains the actual link
     * @remarks    If the text element contains no linked text, the method returns LINK_TYPE_NONE. @n
     *             The link type of the first auto-detected link is returned.
     */
    Osp::Base::Utility::LinkType GetLinkType(void) const;

    /**
     * Sets the text of TextElement with the specified string.
     *
     * @since       1.0
     * @return      An error code
     * @param[in]   text            The string to set
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_STATE This instance is in an invalid state.
     *
     */ 
    result SetText(const Osp::Base::String&  text);
    
    /**
     * Sets the font of TextElement. 
     *
     * @since       1.0
     * @return      An error code
     * @param[in]   font                The font to set
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state.
     * @exception   E_INVALID_ARG       The specified input parameter is invalid.
     *
     */ 
    result SetFont(const Osp::Graphics::Font& font);

    /**
     * Sets the text color of TextElement.
     *
     * @since       1.0
     * @return      An error code
     * @param[in]   color               The color to set
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state.
     *
     */ 
    result SetTextColor(const Osp::Graphics::Color& color);
       
    /**
     * Sets the background color of TextElement. 
     *
     * @since       1.0
     * @compatibility   This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *                  For more information, see @ref CompTextElementSetBackgroundColor "here".
     * @return      An error code
     * @param[in]   color               The color to set
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state.
     *
     */ 
    result SetBackgroundColor(const  Osp::Graphics::Color& color);
            
    /**
     * @page   CompTextElementSetBackgroundColor    Compatibility for SetBackgroundColor()
     * @section CompTextElementSetBackgroundColorIssues Issues
     *                   Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * 
     * -#   This method does not work. 
     *
     * @section CompTextElementSetBackgroundColorResolutions Resolutions 
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
     */
    
    /**
     * Sets the outline color of TextElement. 
     *
     * @since       1.0
     * @return              An error code
     * @param[in]   color   The color to set
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state.
     *
     */ 
    result SetOutlineColor(const Osp::Graphics::Color& color);

    /**
     * Gets the text of TextElement.
     *
     * @since       1.0
     * @return      A string containing the text
     *
     */ 
    Osp::Base::String GetText(void) const;

    /**
     * Gets the text color of TextElement.
     *
     * @since       1.0
     * @return The foreground color
     *
     */ 
    Osp::Graphics::Color GetTextColor(void) const;
    
    /**
     * Gets the background color of TextElement.
     *
     * @since       1.0
     * @return The background color
     *
     */ 
    Osp::Graphics::Color GetBackgroundColor(void) const;
    
    /**
     * Gets the outline color of TextElement. 
     *
     * @since       1.0
     * @return The outline color
     *
     */ 
    Osp::Graphics::Color GetOutlineColor(void) const;
    
private:
    Osp::Graphics::ITextElementPi* __pTextElementPi;
    
    Osp::Base::String __strText;
    
    Osp::Graphics::EnrichedText* __pRegisteringEnrichedText;

    Osp::Graphics::Color m_ForeGroundColor;

    Osp::Graphics::Color m_BackGroundColor;

    Osp::Graphics::Color m_OutLineColor;

    Osp::Graphics::Color m_DisabledFGColor;

    friend class EnrichedText;
    friend class Canvas;
    friend class CanvasEx;

private:
    friend class TextElementEx;
    friend class EnrichedTextEx;
    class TextElementEx* __pTextElementEx;

};// TextElement

}; }; // Osp::Graphics

#endif /* _FGRP_TEXT_ELEMENT_H_ */
