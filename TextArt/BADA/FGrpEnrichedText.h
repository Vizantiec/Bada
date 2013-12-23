/* $Change: 1030567 $ */
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
 * @file		FGrpEnrichedText.h
 * @brief		This is the header file for the %EnrichedText class.
 
 * This header file contains the definition of %EnrichedText class.
 *
 */

#ifndef _FGRP_ENRICHED_TEXT_H_
#define _FGRP_ENRICHED_TEXT_H_

#include "FBase.h"
#include "FBaseObject.h"
#include "FBaseUtilLinkInfo.h"
#include "FGrpConfig.h"
#include "FGrpRectangle.h"
#include "FGrpTextElement.h"

namespace Osp { namespace Graphics { class Rectangle; }; };
namespace Osp { namespace Graphics { class TextElement; };};
namespace Osp { namespace Graphics { class EnrichedTextEx; }; };
namespace Osp { namespace Graphics { class IEnrichedTextPi; }; };

namespace Osp { namespace Graphics {
	/**
	 * @enum TextHorizontalAlignment
	 *
	 * Defines the horizontal alignment of the text.
	 * @since		1.0
	 */
	typedef enum
	{
		TEXT_ALIGNMENT_HORIZONTAL_MIN,		/**< @internal Not used, min number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
		TEXT_ALIGNMENT_LEFT,				/**< The position of the text is towards the left of the object */
		TEXT_ALIGNMENT_CENTER,				/**< The position of the text is towards the center of the object */
		TEXT_ALIGNMENT_RIGHT,				/**< The position of the text is towards the right of the object */
		TEXT_ALIGNMENT_HORIZONTAL_MAX,		/**< @internal Not used, counts the number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
	} TextHorizontalAlignment;

	/**
	 * @enum TextVerticalAlignment
	 *
	 * Defines the vertical alignment of the text.
	 * @since		1.0
	 */
	typedef enum
	{
		TEXT_ALIGNMENT_VERTICAL_MIN,    /**< @internal Not used, min number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
		TEXT_ALIGNMENT_TOP,				/**< The position of the text is towards the top of the object */
		TEXT_ALIGNMENT_MIDDLE,			/**< The position of the text is towards the middle of the object */
		TEXT_ALIGNMENT_BOTTOM,			/**< The position of the text is towards the bottom of the object */
		TEXT_ALIGNMENT_VERTICAL_MAX     /**< @internal Not used, counts the number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
	} TextVerticalAlignment;

	/**
	 * @enum TextWrap
	 *
	 * Defines the style of wrapping of the text in %EnrichedText.
	 * @since		1.0
	 */
	typedef enum
	{
		TEXT_WRAP_MIN,                  /**< @internal Not used, min number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
		TEXT_WRAP_NONE,				    /**< The wrapping of text is not applied */
		TEXT_WRAP_CHARACTER_WRAP,		/**< The wrapping of text is applied at the character unit */
		TEXT_WRAP_WORD_WRAP,			/**< The wrapping of text is applied at the word unit */
		TEXT_WRAP_MAX,                  /**< @internal Not used, counts the number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */ 
	} TextWrap;
	
/**
 * @class	EnrichedText
 * @brief	This class provides enriched text content.
 * @since	1.0
 *
 *
 * The %EnrichedText class provides methods that enable your application to support texts with various styles, such 
 * as font, color, and layout. An %EnrichedText instance can be drawn to a %Canvas.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/graphics/enriched_text.htm">EnrichedText</a>.
 *
 * The following example demonstrates how to use the %EnrichedText class.
 *
 * @code
#include <FApp.h>
#include <FBase.h>
#include <FGraphics.h>

using namespace Osp::App;
using namespace Osp::Graphics;

bool
MyClass::EnrichedTextSample(void)
{
    result r = E_SUCCESS;
    EnrichedText* pEnrichedText = null;
    TextElement* pTextElement1 = null;
    TextElement* pTextElement2 = null;
    Bitmap* pBitmap = null;

    // Creates an EnrichedText instance and sets the attributes
    pEnrichedText = new EnrichedText();
    r = pEnrichedText->Construct(Dimension(200, 200));
    if (IsFailed(r))
    {
        goto CATCH;
    }
    pEnrichedText->SetHorizontalAlignment(TEXT_ALIGNMENT_RIGHT);
    pEnrichedText->SetVerticalAlignment(TEXT_ALIGNMENT_BOTTOM);
    pEnrichedText->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
    pEnrichedText->SetTextAbbreviationEnabled(true);

    // Create a TextElement and set attributes.
    pTextElement1 = new TextElement();
    r = pTextElement1->Construct(L"0123456789");
    if (IsFailed(r))
    {
        goto CATCH;
    }
    pTextElement1->SetTextColor(Color::COLOR_BLUE);
    {
        Font font;
        font.Construct(FONT_STYLE_BOLD, 40);
        pTextElement1->SetFont(font);
    }

    // Creates another TextElement and sets the attributes
    pTextElement2 = new TextElement();
    r = pTextElement2->Construct(L"abcdefghijklmn\nABCDEFGHIJKLMN");
    if (IsFailed(r))
    {
        goto CATCH;
    }
    pTextElement2->SetTextColor(Color::COLOR_VIOLET);

    // Creates a bitmap and scales the size
    pBitmap = Application::GetInstance()->GetAppResource()->GetBitmapN(L"example.bmp");
    pBitmap->Scale(Dimension(40, 40));

    // Adds the TextElement and the bitmap to the EnrichedText
    pEnrichedText->Add(*pTextElement1);
    pEnrichedText->Add(*pTextElement2);
    pEnrichedText->Add(*pBitmap);

    // Draw
    {
        Canvas canvas;
        r = canvas.Construct();
        if (IsFailed(r))
        {
            goto CATCH;
        }
        canvas.SetBackgroundColor(Color::COLOR_BLACK);
        canvas.Clear();
        canvas.FillRectangle(Color::COLOR_WHITE, Rectangle(50, 50, 380, 380));

        // Draws the covered area of the EnrichedText in the Canvas coordinate
        int width, height;
        pEnrichedText->GetSize(width, height);
        canvas.FillRectangle(Color::COLOR_GREY, Rectangle(60, 60, width, height));

        // Draws the EnrichedText at the specified Point
        canvas.DrawText(Point(60, 60), *pEnrichedText);
        canvas.Show();
    }

    // Cleans up
    pEnrichedText->RemoveAll(true);
    delete pEnrichedText;

    return true;

CATCH:
    if (pEnrichedText)
    {
        pEnrichedText->RemoveAll(true);
        delete pEnrichedText;
    }

    return false;
}
 *	@endcode
 * 
 * 
 * 
 *
 */
 
class _EXPORT_GRP_ EnrichedText
	: public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 * @remarks		After creating an instance of this class, one of the Construct() methods must be called explicitly   
	 *				to initialize this instance.
	 */
	EnrichedText(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~EnrichedText(void);

	/**
	 * Initializes this instance of %EnrichedText with the specified parameter.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	dim					The dimension to set for %EnrichedText @n
	 *									The width and height must be greater than @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 */
	result Construct(const Osp::Graphics::Dimension& dim);

	/**
	 * Inserts the %TextElement instance in the %EnrichedText instance at the specified index.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	elementIndex		The index at which the text element is to add
	 * @param[in]	element		    	The %TextElement to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *
	 */	
	result InsertAt(int elementIndex, TextElement& element);
	
	/**
	 * Removes the %TextElement instance at the specified index of the %EnrichedText instance.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	elementIndex		The index of %TextElement
	 * @param[in]	deallocate			Set to @c true to deallocate the %TextElement instance, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *
	 */
	 result RemoveAt(int elementIndex, bool deallocate);

	/**
	 * Removes the %TextElement instance from %EnrichedText instance.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	element		    	The %TextElement to remove
	 * @param[in]	deallocate			Set to @c true to deallocate the %TextElement instance, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 *
	 */
	result Remove(TextElement& element, bool deallocate);
	
	/**
	 * Appends the specified %TextElement to the %EnrichedText instance.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	element		    	The %TextElement to append
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 *
	 */	
	result Add(TextElement& element);
	
	/**
	 * Removes all the %TextElement instances from the %EnrichedText instance.
	 *
	 * @deprecated	This method is deprecated. Instead of this method, use the RemoveAll().
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	deallocate			Set to @c true to deallocate the %TextElement instance, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @see         RemoveAll()
	 *
	 */
	result RemoveAllTextElements(bool deallocate);

	/**
	 * Removes all the text and image elements from the %EnrichedText instance.
	 *
	 * @since          2.0
	 * @return         An error code
	 * @param[in]      deallocate			Set to @c true to deallocate the elements to be removed, @n
	 *										else @c false
	 * @exception      E_SUCCESS            The method is successful.
	 * @exception  	   E_SYSTEM             An unknown operating system error has occurred.
	 * @exception      E_INVALID_STATE      This instance is in an invalid state.	 
	 *
	 */
	result RemoveAll(bool deallocate);

	/**
	 * Gets the %TextElement instance at the specified index from the %EnrichedText instance.
	 *
	 * @since		1.0
	 * @return		The %TextElement instance at the specified index, @n
	 *				else @c null if the method fails
	 * @param[in]	elementIndex		The index of the %TextElement
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_STATE    	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. 
	 */		
	TextElement* GetTextElementAt(int elementIndex) const;
	
	/**
	 * Gets the count of the %TextElement instances.
	 *
	 * @since		1.0
	 * @return		The count of the %TextElement instances
	 */		
	int	GetTextElementCount(void) const;

	/**
	 * Sets the text size.
	 *
	 * @since		1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *                For more information, see @ref EnrichedTextSetSize "here".
	 *
	 * @return      An error code
	 * @param[in]   size                The new size of the %EnrichedText @n
	 *                                  The width and height must be greater than @c 0.
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_OUT_OF_RANGE      The value of the parameter is outside the valid range defined by the method.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 */
	result SetSize(const Osp::Graphics::Dimension& size);

	/**
	 * Sets the text size.
	 *
	 * @since		1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *                For more information, see @ref EnrichedTextSetSize "here".
	 *
	 * @return      An error code
	 * @param[in]   width     			The new width of %EnrichedText @n
	 *                                  It must be greater than @c 0.
	 * @param[in]   height              The new height of %EnrichedText @n
	 *                                  It must be greater than @c 0.
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_OUT_OF_RANGE      The value of the argument is outside the valid range defined by the method.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.	 
	 */
	result SetSize(int width, int height);

	/**
	 * @page  	EnrichedTextSetSize 	Compatibility for SetSize()
	 * @section CompEnrichedTextSetSizeIssues 	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 *
 	 * -# The invalid value @c 0 is considered as valid for the width and height of size.
 	 *   Therefore, this method does not work as expected.
 	 *
 	 * @section CompEnrichedTextSetSizeResolutions Resolutions
 	 *
 	 * The issue mentioned above is resolved in bada API version 1.2. @n
 	 *
 	 * -# This method throws the E_OUT_OF_RANGE exception when the width and height of size is @c 0.
	 */

	/**
	 * Gets the size.
	 *
	 * @since		1.0
	 * @return		An instance of %Dimension containing the width and the height of the %EnrichedText instance
	 *
	 */
	Osp::Graphics::Dimension GetSize(void) const;

	/**
	 * Gets the size of the %EnrichedText instance.
	 *
	 * @since		1.0
	 * @param[out]	width		The width of the control
	 * @param[out]	height		The height of the control
	 */
	void GetSize (int &width, int &height) const;

	/**
	 * Gets the width of the %EnrichedText instance.
	 *
	 * @since		1.0
	 * @return		The width
	 *
	 */
	int	GetWidth(void) const;

	/**
	 * Gets the height of the %EnrichedText instance.
	 *
	 * @since		1.0
	 * @return		The height
	 *
	 */	
	int	GetHeight(void) const;


	/**
	 * Sets the vertical alignment.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	alignment   		The vertical alignment of the text
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 *
	 */	
	result SetVerticalAlignment(TextVerticalAlignment alignment);
	
	/**
	 * Sets the horizontal alignment.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	alignment     		The horizontal alignment of the text
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 *
	 */	
	result SetHorizontalAlignment(TextHorizontalAlignment alignment);
	
	/**
	 * Gets the vertical alignment.
	 *
	 * @since		1.0
	 * @return		alignment			The vertical alignment of the text
	 *
	 */	
	TextVerticalAlignment GetVerticalAlignment(void) const;
	
	/**
	 * Gets the horizontal alignment. 
	 *
	 * @since		1.0
	 * @return		alignment  	 		The horizontal alignment of the text
	 *
	 */	
	TextHorizontalAlignment GetHorizontalAlignment(void) const;

	/**
	 * Sets the text wrap style.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	wrap				The text wrapping style
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */	
	 result SetTextWrapStyle(TextWrap  wrap);
	
	/**
	 * Gets the text wrap style.
	 *
	 * @since		1.0
	 * @return		wrap		The text wrapping style in the %EnrichedText bounds
	 */	
	TextWrap GetTextWrapStyle(void) const;

	/**
	 * Sets the text abbreviation status.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	enable				Set to @c true to enable text abbreviation, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */	
	result SetTextAbbreviationEnabled(bool enable);
	
	/**
	 * Checks whether the text abbreviation is enabled.
	 *
	 * @since		1.0
	 * @return		@c true if the text abbreviation is enabled, @n
	 *				else @c false
	 */	
  	bool IsTextAbbreviationEnabled(void) const;
	
	/**
	 * Sets the line spacing.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	lineSpace			The space between lines
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 *
	 */	
	result SetLineSpace(int lineSpace);
	
	/**
	 * Gets the line spacing.
	 *
	 * @since		1.0
	 * @return		space		The space between lines
	 *
	 */	
	int	GetLineSpace (void) const;

	/**
	 * Relocates the texts of the %TextElement instances according to the %EnrichedText instance's attributes. @n
	 * If some attributes are changed (such as changes using @ref SetRect(rect)), you can get the exact 
	 * information of the text position or the number of lines after this method is called.
	 *
	 * @since		1.0
	 */
	void Refresh(void);    

	/**
	 * Gets the total line count of the text in the %EnrichedText instance.
	 *
	 * @since		1.0
	 * @return		The total line count
	 *
	 */	
	int GetTotalLineCount(void) const; 
	
	/**
	 * Gets the height of the text in the %EnrichedText instance.
	 *
	 * @since		1.0
	 * @return		The line height
	 *
	 */	
	int	GetTotalLineHeight(void) const;
	
	/**
	 * Gets the displayed line count of the text in the %EnrichedText instance. @n
	 * When this method is called before Draw(), it returns @c 0.
	 *
	 * @since		1.0
	 * @return		The displayed line count
	 *
	 */
	int	GetDisplayLineCount(void) const;
	
	/**
	 * Gets the length of the specified line.
	 *
	 * @since		1.0
	 * @return		The line length, @n
	 *				else @c -1 if the method fails
	 * @param[in]	lineIndex 			The index of the specified line
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */	
	int	GetLineLength(int lineIndex) const;
	
	/**
	 * Gets the first character index of the specified line.
	 *
	 * @since		1.0
	 * @return		The first text offset, @n
	 *				else @c -1 if the method fails
	 * @param[in]	lineIndex 			The line index of the %EnrichedText object
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */	
	int	GetFirstTextIndex(int lineIndex) const;
	

	/**
	 * Gets the line index of the specified character.
	 *
	 * @since		1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                For more information, see @ref EnrichedTextGetLineIndex "here".
	 * @return		The line index, @n
	 *				else @c -1 if the method fails
	 * @param[in]	textIndex 			The text index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetLineIndex(int textIndex) const;

	/**
	 * @page  EnrichedTextGetLineIndex Compatibility for GetLineIndex()
	 * @section CompEnrichedTextGetLineIndexIssues Issues
	 * Implementation of this method in API versions prior to 2.0 has the following issue: @n
	 *
	 * - The method returns @c -1 and generates E_INVALI_ARG if the specified @c textIndex is greater than or equal to the total line count.
	 *
	 * @section CompEnrichedTextGetLineIndexResolutions Resolutions
	 *
	 * The issue mentioned above is resolved in API version 2.0. @n
	 */
	
	/**
	 * Gets the line height of the specified line.
	 *
	 * @since		1.0
	 * @return		The line height, @n
	 *				else @c -1 if the method fails
	 * @param[in]	lineIndex 			The line index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int	GetLineHeight(int lineIndex) const;
	
	/**
	 * Gets the text length of the %EnrichedText object.
	 *
	 * @since		1.0
	 * @return		The text length
	 */	
	int	GetTextLength(void) const;	

	/**
	 * This method calculates the extent of the %EnrichedText instance on the assumption that all %TextElements are 
	 * expanded to one line.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	startTextIndex		The starting text index of the EnrichedText
	 * @param[in]	textLength			The length of the specified text @n
	 *									It must be greater than or equal to @c 0.
	 * @param[out]  width				The width of the specified text
	 * @param[out]  height				The height of the specified text
	 * @param[out]  actualLength		The actual text length measured
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result GetTextExtent (int startTextIndex, int textLength, int &width, int &height, int& actualLength) const;

	/**
	 * Appends the specified bitmap image to the %EnrichedText instance.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	bitmap					The bitmap to draw @n
     *                               		The bitmap must be constructed before being passed to this method.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception  	E_SYSTEM                An unknown operating system error has occurred.
	 * @exception   E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 */
	result Add(const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Inserts the specified bitmap image to the %EnrichedText instance at the specified index.
	 *
	 * @since 2.0
	 * @return		An error code
	 * @param[in]	bitmap					The @c bitmap to draw @n
     *                              		The bitmap must be constructed before being passed to this method.
     * @param[in]	elementIndex		    The index at which the @c bitmap image is to add
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_SYSTEM                An unknown operating system error has occurred. 
	 * @exception   E_OUT_OF_RANGE			The value of the argument is outside the valid range defined by the method.
	 * @exception   E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 */
	result InsertAt(int elementIndex, const Osp::Graphics::Bitmap& bitmap);
	
	/**
	 * Gets information about the link at the specified position.
	 *
	 * @since      2.0
	 * @return     An error code
	 * @param[in]  point              A point that is within the %EnrichedText object
	 * @param[out] linkInfo           The LinkInfo object that represents the link at the specified position
	 * @exception  E_SUCCESS          The method is successful.
	 * @exception  E_INVALID_ARG      A specified input parameter is invalid.
	 * @exception  E_OBJ_NOT_FOUND    The required instance is not found.
	 * @exception  E_INVALID_STATE    This instance is in an invalid state.
	 * @remarks    The method throws @c E_OBJ_NOT_FOUND if there is no linked text at the specified position.
	 * @see        Osp::Base::Utility::LinkInfo
	 */
	 result GetLinkInfoFromPosition(const Point& point, Osp::Base::Utility::LinkInfo& linkInfo) const;


	/**
	 * Gets information about the link at the specified position.
	 *
	 * @since      2.0
	 * @return     An error code
	 * @param[in]  x                  The x-coordinate of a point that is within the %EnrichedText object
	 * @param[in]  y                  The y-coordinate of a point that is within the %EnrichedText object
	 * @param[out] linkInfo           The LinkInfo object that represents the link at the specified position
	 * @exception  E_SUCCESS          The method is successful.
	 * @exception  E_INVALID_ARG      A specified input parameter is invalid.
	 * @exception  E_OBJ_NOT_FOUND    The required instance is not found.
	 * @exception  E_INVALID_STATE    This instance is in an invalid state.
	 * @remarks    The method throws @c E_OBJ_NOT_FOUND if there is no linked text at the specified position.
	 * @see        Osp::Base::Utility::LinkInfo
	 */
	 result GetLinkInfoFromPosition(int x, int y, Osp::Base::Utility::LinkInfo& linkInfo) const;

	/**
	 * Gets the vertical alignment among text and bitmap element.
	 *
	 * @since		2.0
	 * @return		The vertical alignment among the text and the bitmap element
	 *
	 */
	TextVerticalAlignment GetElementVerticalAlignment(void) const;

	/**
	 * Sets the vertical alignment among text and bitmap element.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	alignment   		The vertical alignment among the text and the bitmap element
	 * @exception	E_SUCCESS			The method was successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		This method sets how one element is positioned relative to the other elements. @n
	 *				The vertical alignment of text and bitmap elements are decided based on the maximum height among elements.
	 * @remarks		The default alignment TEXT_ALIGNMENT_BOTTOM.
	 */
	result SetElementVerticalAlignment(TextVerticalAlignment alignment);

private:
	Osp::Graphics::IEnrichedTextPi*  __pEnrichedTextPi;

	Osp::Base::Collection::LinkedList* __pLinkedListTextElementList;

	friend class Canvas;
	friend class CanvasEx;
	friend class Dimension;
	friend class TextElement;

	int __width;
	int __height;
	TextVerticalAlignment __vertcalAlignment;
	TextHorizontalAlignment __horizontalAlignment;
	int __lineSpace;

private:
	friend class EnrichedTextEx;
	class EnrichedTextEx* __pEnrichedTextEx;

};// EnrichedText

}; }; // Osp::Graphics

#endif /* _FGRP_ENRICHED_TEXT_H_ */
