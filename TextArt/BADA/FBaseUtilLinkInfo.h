/* $Change: $ */
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
 * @file		FBaseUtilLinkInfo.h
 * @brief		This is the header file for the %LinkInfo class.
 *
 * This header file contains the declarations of the %LinkInfo class.
 */
#ifndef _FBASE_UTIL_LINKINFO_H_
#define _FBASE_UTIL_LINKINFO_H_

//Includes
#include "FBaseColIList.h"
#include "FBaseString.h"

#include "FBaseUtilTypes.h"

namespace Osp { namespace Base { namespace Utility {



/**
* @class   LinkInfo
* @brief   This class provides methods for %LinkInfo.
* @since   2.0
*
* The %LinkInfo class provides information regarding a link. It contains methods 
* for accessing the link, its type, and a string that represents the link.
*/
class _EXPORT_BASE_ LinkInfo :
    public Osp::Base::Object
{
// life-cycle
public:
    /**
     * This is the default constructor for this class.
     *
     * @since       2.0
     * @remarks     The link and text are set to empty strings and the link type is
     *              set to @c LINK_TYPE_NONE.
     */
    LinkInfo(void); 


    /**
     * This is the copy constructor for the %LinkInfo class. @n
     * Initializes a new instance of the LinkInfo class to the specified @c value.
     *
     * @since       2.0     
     * @param[in]   value  An instance of %LinkInfo
     */
    LinkInfo(const LinkInfo& value);


    /**
     * Initializes an instance of %LinkInfo with the specified parameters.
     *
     * @since       2.0     
     * @param[in]   linkType    The link type
     * @param[in]   link        The link (For example, http://developer.bada.com)
     * @remarks     The link's @c text is set to the same string as @c link.
     * @see         Osp::Base::Utility::LinkType
     */
    LinkInfo(LinkType linkType, const Osp::Base::String& link);


    /**
     * Initializes an instance of %LinkInfo with the specified parameters.
     *
     * @since       2.0         
     * @param[in]   linkType    The link type
     * @param[in]   link        The link (For example, http://developer.bada.com)
     * @param[in]   text        A string that represents the link (ex: "bada developer site")
     * @see         Osp::Base::Utility::LinkType
     */
    LinkInfo(LinkType linkType, const Osp::Base::String& link, const Osp::Base::String& text);


    /**
     * This is the destructor for this class.
     *
     * @since       2.0              
     */
    virtual ~LinkInfo(void); 


// operator
public:
    /**
     * This operator assigns the value of the specified %LinkInfo instance to the calling instance.
     *
     * @since       2.0                   
     * @return      A reference to the calling instance
     * @param[in]   rhs     An instance of %LinkInfo to assign
     */
    LinkInfo& operator =(const LinkInfo& rhs);


// Accessor 
public:
    /**
     * Gets the link. 
     *
     * @since       2.0              
     * @return      The string that contains the link
     * @see         SetLink()
     */
    Osp::Base::String GetLink(void) const;


    /**
     * Sets the link. 
     *
     * @since       2.0              
     * @param[in]   link   The string that contains the link
     * @see         GetLink()
     */
    void SetLink(const Osp::Base::String& link);


    /**
     * Gets the type of the link. 
     *
     * @since       2.0              
     * @return      The link type
     * @see         SetLinkType()          
     * @see         Osp::Base::Utility::LinkType
     */
    LinkType GetLinkType(void) const;


    /**
     * Sets the type of the link. 
     *
     * @since       2.0              
     * @param[in]   linkType    The link type
     * @see         GetLinkType()
     * @see         Osp::Base::Utility::LinkType
     */
    void SetLinkType(LinkType linkType);


    /**
     * Gets the string that represents the link. 
     *
     * @since       2.0                   
     * @return      The string that represents the link
     * @see         SetText()
     */
    Osp::Base::String GetText(void) const;


    /**
     * Sets the string that represents the link. 
     *
     * @since       2.0                   
     * @return      An error code
     * @param[in]   text            The string that represents the link
     * @see         GetText()
     */
    void SetText(const Osp::Base::String& text);


private:

	LinkType				__linkType;
	Osp::Base::String 		__link;
	Osp::Base::String 		__text;
	
	


private:
    friend class LinkInfoEx;
    class LinkInfoEx* __pLinkInfoEx;
	
};  // LinkInfo
}; };  }; // Osp::Base::Utility
#endif // _FBASE_UTIL_REGEX_H_

