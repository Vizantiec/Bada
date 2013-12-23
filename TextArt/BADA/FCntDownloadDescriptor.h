/* $Change: 1142016 $ */
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
* @file			FCntDownloadDescriptor.h 
* @brief		This is the header file for the %DownloadDescriptor class.
*
* This header file contains the declarations of the %DownloadDescriptor class. 
*/

#ifndef _FCNT_DOWNLOAD_DESCRIPTOR_H_
#define _FCNT_DOWNLOAD_DESCRIPTOR_H_

// Includes
#include "FCntConstants.h"

struct MDownloadDescriptor;

namespace Osp { namespace Content { 
class DownloadDescriptorEx;
/**
 * @enum DownloadDescriptorField
 * Defines the fields in the download descriptor.
 * @deprecated	This enum is deprecated due to the operation policy of the bada Server.
 * @since	1.0
 */
enum DownloadDescriptorField
{
	DD_TYPE  = 1,	/**< The content/mime type*/
	DD_SIZE,		/**< The content size*/
	DD_OBJECTURI,	/**< The object URI*/
	DD_INSTALLNOTIFYURI,	/**< The installation notification*/
	DD_NEXTURL,		/**< The next request URL*/
	DD_DDVERSION,	/**< The version of the download descriptor*/
	DD_NAME,		/**< The content name*/
	DD_DESCRIPTION,	/**< The content description*/
	DD_VENDOR,		/**< The content provider's name*/
	DD_INFOURL,		/**< The content information's URL*/
	DD_ICONURL,		/**< The content icon's URL*/
	DD_INSTALLPARAM	/**< The installation's parameter*/
};

/**
* @class	DownloadDescriptor
* @brief	This class represents the download descriptor for Open Mobile Alliance Download (OMA DL).
* @deprecated This class is deprecated as OMA download is currently not supported.
* @since	1.0
*
* The %DownloadDescriptor class defines the OMA Download Descriptor.
* It is returned from the IContentTransferListener::OnDownloadDescriptorReceived() listener that is initiated by 
* ContentTransfer::Download(). This class is used for requesting ContentTransfer::OmaDownload().
*
* The following example demonstrates how to use %DownloadDescriptor and perform parsing.
*
* @code

String 
MyClass::GetDDSample01(void)
{
	String xml = L"<media xmlns=\"http://www.openmobilealliance.org/xmlns/dd\">";
	xml += L"<name>Christmas cake</name>";
	xml += L"<size>135230</size>";
	xml += L"<type>image/jpeg</type>";
	xml += L"<objectURI>http://10.254.189.195/image/08Christmas/STP60229.JPG</objectURI>";
	xml += L"<description>Christmas party</description>";
	xml += L"<vendor>SEC</vendor>";
	xml += L"</media>"; 

	return xml;
}

result
MyClass::ParseStringExample(void)
{
	DownloadDescriptor descriptor;
	String xmlDD;
	result r;

	xmlDD = GetDDSample01();

	r = descriptor.ParseString(xmlDD);


	SysTryReturn(!IsFailed(r), r, ("Parsing is failed.\n"));
}
* @endcode
*/

class _EXPORT_CONTENT_ DownloadDescriptor : 	
		public Osp::Base::Object
{
// Lifecycle
public:
	/**
	* This is the default constructor for this class.
	*
	* @since	1.0
	*/
	DownloadDescriptor(void);

	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	~DownloadDescriptor(void);

	/** 
	* This is the copy constructor for the %DownloadDescriptor class.
	*
	* @since			1.0
	* @param[in]	value	An instance of %DownloadDescriptor to initialize the calling instance
	*/	
	DownloadDescriptor(const DownloadDescriptor& value);

// Operation
public:
	/**
	* @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	* 			and security-related issues that might arise after using this method.
	*
	* Sets the MDownloadDescriptor.
	*
	* @since			1.0
	* @param[in]	pDownloadDescriptor	The pointer of MDownloadDescriptor
	*/
	void SetDownloadDescriptor(MDownloadDescriptor* pDownloadDescriptor);

	/** 
	* This assignment operator copies the text from the specified instance of %DownloadDescriptor
	* to the calling instance of %DownloadDescriptor.
	*
	* @since		1.0
	* @return		The reference of the calling instance
	* @param[in]	rhs	A reference to the %DownloadDescriptor instance used to initialize the calling instance
	*/
	DownloadDescriptor& operator =(const DownloadDescriptor& rhs);

// Access
public:

	/**
	* Gets the type of the downloaded content.
	* 
	* @since	1.0
	* @return	The content MIME type
	*/
	Osp::Base::String GetType(void) const;

	/**
	* Gets the size of the downloaded content.
	* 
	* @since			1.0
	* @return			The content size 
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_NUM_FORMAT	The specified string does not contain a number that can be parsed.
	* @remarks		When the size format is not a number, this method returns the value @c -1.
	*/
	int GetSize(void) const;

	/**
	* Gets the name of the downloaded content.
	* 
	* @since	1.0
	* @return	The name of the content
	*/
	Osp::Base::String GetName(void) const;

	/**
	* Gets the description of the downloaded content.
	* 
	* @since	1.0
	* @return	The content description
	*/
	Osp::Base::String GetDescription(void) const;

	/**
	* Gets the data from the download descriptor field.
	* 
	* @since			1.0
	* @return			The data from the specified field
	* @param[in]	field	The field of download descriptor whose data is needed
	*/
	Osp::Base::String GetField(DownloadDescriptorField field) const;

	/**
	* Parses the XML documentation for the download descriptor.
	* 
	* @since			1.0
	* @return			An error code
	* @param[in]	xmlDoc	The XML documentation for the download descriptor
	* @exception	E_SUCCESS		The method is successful.
	* @exception 	E_PARSING_FAILED	The XML doc parsing has failed.
	*/
	result ParseString(const Osp::Base::String& xmlDoc);

	/**
	* @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	* 			and security-related issues that might arise after using this method.
	*
	* Gets the download descriptor
	*
	* @since		1.0
	* @param[out]	descriptor	The value of the descriptor
	*/
	void GetDownloadDescriptor(MDownloadDescriptor& descriptor);

// Attribute
private:
	MDownloadDescriptor* __pDownloadDescriptor;

	friend class DownloadDescriptorEx;
	class DownloadDescriptorEx* __pDownloadDescriptorEx;

};
};};// Osp::Content
#endif // _FCNT_DOWNLOAD_DESCRIPTOR_H_
