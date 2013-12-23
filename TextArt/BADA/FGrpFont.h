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
 * @file		FGrpFont.h 
 * @brief		This is the header file for the %Font class.
 *
 * This header file contains the declarations of the %Font class.
 */
#ifndef _FGRP_FONT_H_
#define _FGRP_FONT_H_


#include "FBase.h"
#include "FBaseObject.h"
#include "FGrpDimension.h"
#include "FGrpConfig.h"
#include "FGrpFontCommon.h"


namespace Osp { namespace Base { class String; }; };
namespace Osp { namespace Graphics { class Dimension; }; };
namespace Osp { namespace Graphics { class Color; }; };
namespace Osp { namespace Graphics { class IFontPi; }; };
namespace Osp { namespace Graphics { class _Canvas; };};
namespace Osp { namespace Graphics { class __Pi; };};
namespace Osp { namespace Graphics { class __Attr; };};
namespace Osp { namespace Graphics { class _EnrichedFont; };};
namespace Osp { namespace Graphics { class __TextElement; };};


namespace Osp { namespace Graphics {
/**
 * @class	Font
 * @brief	This class provides methods to retrieve the font information.
 * @since	1.0
 *
 *
 * The %Font class encapsulates the characteristics, such as the size and style of a specific vector font.
 * Fonts are used to draw text on a Canvas.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/graphics/fonts.htm">Fonts</a>.
 *
 *
 */
class _EXPORT_GRP_ Font
	: public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 * This is the default constructor for this class.
	 *
	 * @since			1.0
	 * @remarks		After creating an instance of this class, one of the
     *              Construct() methods must be called explicitly to initialize this instance.
	 */
	Font(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Font(void);

	/**
	 * Initializes this instance of Font with the specified size and style. @n
	 * If the size and style are not specified, the default system font is set.
	 *	
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	style				The font style @n
										For more information, see Osp::Graphics::FontStyle.
	 * @param[in]	size				The font size in pixels @n
	 * 									The size must be greater than @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result Construct(int style, int size);

	/**
	 * @page  FontConstruct Compatibility for Construct()
	 * @section CompClassNameMethodNamePageIssueSection Issues @n
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 *
 	 * -# The value of @c fontName must be a valid path of a font-resource file or system font name. 
 	 *    If the value is invalid, this method does not work as expected.
 	 *
 	 * @section CompClassNameMethodNamePageSolutionSection Resolutions
 	 *
 	 * The issue mentioned above is resolved in bada API version 1.2. @n
	 * -# This method returns E_UNSUPPORTED_FORMAT if the value of the @c fontName is not a valid path of a font-resource file or system font name.
	 */

	/**
	 *  Initializes this instance of Font with the specified parameters.
	 *	
	 * @since					1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *                For more information, see @ref FontConstruct "here".
	 *
	 * @return		An error code
	 * @param[in]	fontName				The local file path of a font-resource file or system font name @n
	 *                                      The system font name is retrieved using GetSystemFontListN().
	 * @param[in]	style					The font style @n
	 * 										Multiple styles can be combined using the bitwise OR operator.
	 * @param[in]	size					The font size in pixels @n
	 *										The size must be greater than @c 0.
	 * @exception	E_SUCCESS				The method is successful.	 
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_FILE_NOT_FOUND		The specified font cannot be found or accessed.
	 * @exception	E_UNSUPPORTED_FORMAT	The specified font format is not supported.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 *
	 * @remarks Only TrueType font is supported.
	 */
	result Construct(const Osp::Base::String& fontName, int style, int size);

	/**
	 * @page  FontConstruct2 Compatibility for Construct()
	 * @section CompClassNameMethodNamePageIssueSection Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issues: @n
	 *
 	 * -# This method works for FontStyle::FONT_STYLE_PLAIN only. @n
	 * -# The value of @c fontData must have a valid font stream. If the value is an invalid font stream, this method does not work as expected.
 	 *
 	 * @section CompClassNameMethodNamePageSolutionSection Resolutions
 	 *
 	 * The issues mentioned above are resolved in bada API version 1.2. @n
 	 *
 	 * -# This method works for all of the font styles. @n
	 * -# This method returns E_UNSUPPORTED_FORMAT if the value of @c fontData is not a valid font stream.
	 */

	/**
	 * Initializes this instance of Font with the specified parameters.
	 *	
	 * @since					1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *                For more information, see @ref FontConstruct2 "here".
	 * 
	 * @return		An error code
	 * @param[in]	fontData				The font data 
	 * @param[in]	style					The font style @n
	 * 										Multiple styles can be combined using the bitwise OR operator.
	 * @param[in]	size					The font size in pixels @n
	 *										The size must be greater than @c 0.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_FORMAT	The specified font format is not supported.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 */
	result Construct(const Osp::Base::ByteBuffer& fontData, int style, int size);

// Operation
public:
	/** 
	 * Gets the maximum height of the current instance of Font.
	 *
	 * @since			1.0
	 * @return		The maximum height of the current instance of Font, @n
	 *				else @c -1 if the method fails
	 */
	int GetMaxHeight(void) const;

	/** 
	 * Gets the maximum width of the current instance of Font.
	 *
	 * @since			1.0
	 * @return		The maximum width of the current instance of Font, @n
	 *				else @c -1 if the method fails
	 */
	int GetMaxWidth(void) const;

	/**
	 * Gets the ascender of the current instance of Font.
	 *
	 * @since				1.0
	 * @return      The ascender of the current instance of Font, @n
	 *				else @c -1 if the method fails
	 */
	int GetAscender(void) const;

	/**
	 * Gets the descender of the current instance of Font.
	 *
	 * @since				1.0
	 * @return      The descender of the current instance of Font, @n
	 *				else @c -1 if the method fails
	 */
	int GetDescender(void) const;

	/**
	 * Gets the left bear of a character.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	character		     A character for getting left bear
	 * @param[out]	leftBear             The left bear of the specified @c character
	 * @exception E_SUCCESS              The method is successful.
	 * @exception E_INVALID_STATE        This instance is in an invalid state.
	 * @exception E_DATA_NOT_FOUND       The requested data does not exist.
	 */
	result GetLeftBear(mchar character, int& leftBear) const;

	/**
	 * Gets the right bear of a character.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	character		     A character for getting the right bear
	 * @param[out]	rightBear            The right bear of the specified @c character
	 * @exception E_SUCCESS              The method is successful.
	 * @exception E_INVALID_STATE        This instance is in an invalid state.
	 * @exception E_DATA_NOT_FOUND       The requested data does not exist.
	 */
	result GetRightBear(mchar character, int& rightBear) const;

	/**
	 * Gets the width and height of the font used in the specified text. @n
	 * This method retrieves the font dimension of the text.
	 *	
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	text			The string
	 * @param[in]	length			The length of @c text @n
									The length must be greater than or equal to @c 0.
	 * @param[out]	dim				The width and height of the font of the @c text
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of @c length is greater than the actual length of @c text.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */ 
	result GetTextExtent(const Osp::Base::String& text, int length, Dimension& dim) const;	

	/**
	 * Checks whether the font style of the current instance is bold.
	 *	
	 * @since			1.0
	 * @return		@c true if the font style of the current instance is bold, @n
					else @c false
	 */ 
	bool IsBold(void) const;

	/**
	 * Checks whether the font style for the current instance is italics.
	 *	
	 * @since			1.0
	 * @return		@c true if the font style for the current instance is italics, @n
					else @c false
	 */ 
	bool IsItalic(void) const;

	/**
	 * Checks whether the current instance has any style defined.
	 *
	 * @since			1.0
	 * @return		@c true if an extra style is not defined for the current instance, @n
	 * 				else @c false
	 */ 
	bool IsPlain(void) const;

	/**
	 * Checks whether the current instance has the strikeout style set.
	 *	
	 * @since			1.0
	 * @return		@c true if the current instance has the strikeout style set, @n
					else @c false
	 */ 
	bool IsStrikeOut(void) const;

	/**
	 * Checks whether the current instance has the underline style set.
	 *	
	 * @since			1.0
	 * @return		@c true if the current instance has the underline style set, @n
					else @c false
	 */ 
	bool IsUnderlined(void) const;

	/**
	 * Gets the font size of the current instance of Font.
	 *
	 * @since			1.0
	 * @return		The font size, @n
	 *				else @c -1 if the method fails
	 */
	int GetSize(void) const;

	/**
	 * Sets the strikeout style for the current instance of Font.
	 *	
	 * @since			1.0
	 * @param[in]	strikeOut	Set to @c true to use the strikeout style for the current instance of Font, @n
								else @c false
	 */ 
	void SetStrikeOut(bool strikeOut);

	/**
	 * Sets the underline style for the current instance of Font.
	 *	
	 * @since			1.0
	 * @param[in]	underline	Set to @c true to use the underline style for the current instance of Font, @n
								else @c false
	 */ 
	void SetUnderline(bool underline);

	/**
	 * Gets the system font list. 
	 *		
	 * @since			1.0
	 * @return		The list of system fonts @n
	 * 				The font list consists of Osp::Base::String items.
	 *
	 * @remarks After using the system font list, you can call IList::RemoveAll(true) to clean up string items in the list.
	 */ 
	static Osp::Base::Collection::IList* GetSystemFontListN(void);

	/**
	 * Sets the character space. 
	 *
	 * @since	1.0
	 */ 
	void SetCharSpace(int space);

	/**
	 * Gets the character space.
	 *		
	 * @since		1.0
	 * @return	The character space of this font instance, @n
	 *			else @c -1 if the method fails
	 */ 
	int GetCharSpace(void) const;

	/**
	 * Gets the face name.
	 *             
	 * @since		1.0               
	 * @return  The face name of this font instance
	 */ 
	Osp::Base::String GetFaceName(void) const;


private:
	/* 
	 * This is the copy constructor for the Font class.
	 *
	 * @remarks		Do not use this constructor.
	 */
	Font(const Font& font);
	Font& operator=(const Font& rhs);

	/*
	 * Gets the native Font.
	 *
	 * @return		A pointer to the native Font
	 */
	void* GetNativeFont(void) const;

	/*
	 * Gets the Pi interface.
	 *				    
	 * @return		The Pi interface
	 */
	result GetPi(const Osp::Base::String& fontName, int style, int size, __Pi** out);

	/*
	 * Gets pi interface.
	 *				    
	 * @return		The Pi interface
	 */
	result GetPi(const Osp::Base::ByteBuffer& fontData, int style, int size, __Pi** out);

	/*
	 * Removes the Pi interface.
	 *
	 */
	static void RemovePi(__Pi* pPi);

	/*
	 * Gets The attribute.
	 *				    
	 * @return		The attribute
	 */	
	result GetAttr(int style, int size, __Attr** pAttr);

	/*
	 * Removes The attribute.
	 *
	 */
	static void RemoveAttr(__Attr** pAttr);

	/*
	 * Gets the resource list.
	 *				    
	 * @return		The resource list
	 */
	static Osp::Base::Collection::ArrayList& GetPiList();

	/*
	 * Gets the resource list.
	 *				    
	 * @return		The resource list
	 */
	static Osp::Base::Collection::ArrayList& GetAttrList();

	/*
	 * Removes the attribute.
	 *
	 */
	void RemoveAttr(__Attr* pAttr);

	/*
	 * Sets the font attribute.
	 *
	 */
	result ApplyAttr(void);

	/*
	 * Creates and returns a clone of the Font instance.
	 *
  	 * @return		A Font instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Font* CloneN();

	/*
	 * Creates and returns the enriched Font instance.
	 *
  	 * @return		A Font instance
	 *
	 */
	_EnrichedFont* GetEnrichedFontN(void);

// Attribute
private:
	__Pi* __pPi;
	__Attr* __pAttr;

// friend
	friend class _Canvas;
	friend class Canvas;
	friend class CanvasEx;
	friend class TextElement;
	friend class _EnrichedFont;
	friend class __TextElement;

private:
	friend class FontEx;
	class FontEx* __pFontEx;

};// Font

}; }; // Osp::Graphics

#endif //_FGRP_FONT_H_
