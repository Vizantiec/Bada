/* $Change:  $ */
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
* @file		FSclSvcSnsPostInfo.h
* @brief	This is the header file for the %SnsPostInfo class.
*
* This header file contains the declarations of the %SnsPostInfo class.
*/
#ifndef _FSCL_SVC_SNS_POST_INFO_H_
#define _FSCL_SVC_SNS_POST_INFO_H_

#include "FBaseObject.h"
#include "FBaseString.h"
#include "FBaseColHashMap.h"
#include "FSclConfig.h"
#include "FSclSvcTypes.h"
#include "FSclSvcSnsTypes.h"

namespace Osp { namespace Social { namespace Services {

class __SnsUtil;

/**
* @class	SnsPostInfo
* @brief	This class represents the information of an SNS post which could be published to a service provider.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.2
*
* The %SnsPostInfo class represents the information of an SNS post which could be published to a service provider.
* The post contains contents that would be published by logged-in user with some social object.
* The contents of the post are different for each service provider. @n
* The following table represents the properties supported by each service provider:
<table>
<tr><td> Property			</td>	<td> Facebook </td></tr>
<tr><td> Target				</td>	<td> O (ID of the user, Page, group, or event)</td>	</tr>
<tr><td> Message			</td>	<td> O (The message entered by user when publishing a post)</td></tr>
<tr><td> Title				</td>	<td> O </td>	</tr>
<tr><td> Summary 			</td>	<td> O </td>	</tr>
<tr><td> Detail				</td>	<td> O </td>	</tr>
<tr><td> Privacy level		</td>	<td> O </td>	</tr>
<tr><td> Link				</td>	<td> O (action_links)</td>	</tr>
<tr><td> Additional property</td>	<td> O </td>	</tr>
<tr><td> Image attachment	</td>	<td> O </td>	</tr>
<tr><td> Flash attachment	</td>	<td> O </td>	</tr>
<tr><td> MP3 attachment		</td>	<td> O </td>	</tr>
</table>
*
* <b>Remarks</b>: @n
* 1. The default value of privacy is @c SNS_PRIVACY_LEVEL_PUBLIC. @n
* 2. For Facebook, SNS_PRIVACY_LEVEL_CUSTOM is not supported. @n 
* 3. Only one media file can be attached. @n
* 4. For Facebook, the post is published on the Wall of the current or the specified user, or on the Wall of a friend or a Facebook Page, group, or event connected to the logged-in user. @n
*
* This is a sample code.
* @code
		#include <FSocialServices.h>

		using namespace Osp::Base;
		using namespace Osp::Social::Services;

		void
		MyPostInfo::CreatePostInformation(void)
		{
			SnsPostInfo		postInfo;

			postInfo.SetTarget(null);
			postInfo.SetMessage(L"This is a message.");
			postInfo.SetTitle(L"Publishing the post.", L"www.mypage.com");
			postInfo.SetSummary(L"This example shows how to create a post information.");
			postInfo.AdditionalProperty(L"More info", L"Publishing the post", L"www.mypage.com/publish_post");
			postInfo.SetLink(L"Get sample", L"www.mypage.com/get_sample");
			postInfo.AttachImage(L"http://mypage.com/publish_post/image.jpg", L"www.mypage.com/publish_post");
		}
*
* @endcode
*/
class  _EXPORT_SOCIAL_ SnsPostInfo:
	public Osp::Base::Object
{
	friend class __SnsUtil;

public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.2
	*/
	SnsPostInfo(void);

	/**
	* This is the copy constructor for this class.
	*
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.2
	* @param[in]	value		An instance of %SnsPostInfo
	*/
	SnsPostInfo(const SnsPostInfo& value);

	/**
	* This assignment operator copies the data contained in the specified instance of %SnsPostInfo to the current instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.2
	* @param[in]	value	An instance of %SnsPostInfo
	*/
	SnsPostInfo& operator =(const SnsPostInfo& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.2
	*/
	virtual ~SnsPostInfo(void);

	// Operations
public:
	/**
	* Sets the ID of the target where the post is published. @n
	* For Facebook, it could be the ID of the user, Page, group, or event. @n
	* Sets @c null, if you want to publish the post to the logged-in user's Wall.
	* The default value is @c null.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.2
	* @return			An error code
	* @param[in]	pTargetId			The ID of the target
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified @c pTargetId is an empty string.
	*/
	result	SetTarget(const Osp::Base::String* pTargetId=null);

	/**
	* Sets the message of the post. @n
	* For Facebook, it is the message entered by the user when publishing the post.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.2
	* @param[in]	message		The message of the post
	*/
	void	SetMessage(const Osp::Base::String& message);

	/**
	* Sets the privacy level indicating which users can see this post. @n
	* The privacy setting only applies to the logged-in user's post. Therefore, the privacy setting is ignored if the target of the post is not the logged-in user.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.2
	* @param[in]	level		The privacy level
	* @remarks		For Facebook, SNS_PRIVACY_LEVEL_CUSTOM is not supported. @n
	* If you publish a post with privacy as SNS_PRIVACY_LEVEL_CUSTOM, you will receive a server error.
	* If you set the invalid level, the privacy will be set to SNS_PRIVACY_LEVEL_PRIVATE.
	*/
	void	SetPrivacyLevel(SnsPrivacyLevel level);

	/**
	* Sets the title of the post. @n
	* If you set a title, the hyperlink is mandatory.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.2
	* @return			An error code
	* @param[in]	title		The title of the post
	* @param[in]	hyperlink	The hyperlink that links to the title
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified @c title or @c hyperlink is an empty string.
	*										
	*/
	result	SetTitle(const Osp::Base::String& title, const Osp::Base::String& hyperlink);

	/**
	* Sets the summary of the post.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.2
	* @param[in]	summary		The summary of the post
	*/
	void	SetSummary(const Osp::Base::String& summary);

	/**
	* Sets the detail of the post.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.2
	* @param[in]	detail		The detail of the post
	*/
	void	SetDetail(const Osp::Base::String& detail);

	/**
	* Sets the link object.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.2
	* @return			An error code
	* @param[in]	linkText		The text to appear in the post
	* @param[in]	hyperlink		The hyperlink that links to the text
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The @c linkText or @c hyperlink is an empty string.
	*/
	result	SetLink(const Osp::Base::String& linkText, const Osp::Base::String& hyperlink);

	/**
	* Adds the additional key-value pair property that provides more information. @n
	* Multiple properties are available but the key must be unique. The hyperlink is optional.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.2
	* @return			An error code.
	* @param[in]	key			The label of the property
	* @param[in]	value		The value of the key
	* @param[in]	pHyperlink	The hyperlink that links to the value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified @c key, @c value, or @c pHyerLink is an empty string.
				 
	* @exception	E_KEY_ALREADY_EXIST		The specified key already exists.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	*/
	result	AddAdditionalProperty(const Osp::Base::String& key, const Osp::Base::String& value, const Osp::Base::String* pHyperlink);

	/**
	* Attaches the image file to the post. @n
	* Make sure only one media file is attached. If a media is already attached, an exception occurs.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.2
	* @return			An error code
	* @param[in]	source		The URL of the source image
	* @param[in]	pHyperlink	The hyperlink that links to the image
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified @c source is an empty string.
	* @exception	E_MAX_EXCEEDED		The media is already attached.
	*/
	result	AttachImage(const Osp::Base::String& source, const Osp::Base::String* pHyperlink);

	/**
	* Attaches the flash file to the post. @n
	* Make sure only one media file is attached. If a media is already attached, an exception occurs.
	* You can set @c width, @c height, @c expandedWidth, and @c expandedHeight.	If the values are not specified, the service provider defined default values are set.
	* Verify the document of the service provider.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.2
	* @return			An error code
	* @param[in]	source		The URL of the Flash source file
	* @param[in]	imageSource	The URL of the image that represents the flash
	* @param[in]	width		The width of the image or flash to display
	* @param[in]	height		The height of the image or flash to display
	* @param[in]	expandedWidth		The width of the flash when the media plays after user clicks this media
	* @param[in]	expandedHeight		The height of the flash when the media plays after user clicks this media
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified @c source or @c imageSource is an empty string.
	*										
	* @exception	E_MAX_EXCEEDED		The media is already attached.
	*/
	result	AttachFlash(const Osp::Base::String& source, const Osp::Base::String& imageSource, int width=0, int height=0, int expandedWidth=0, int expandedHeight=0);

	/**
	* Attaches the MP3 file to the post. @n
	* Make sure only one media file is attached. If a media is already attached, an exception occurs.
	* The values of @c pTitle, @c pArtist, and @c pAlbum are optional.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.2
	* @return			An error code.
	* @param[in]	source		The URL of the source MP3
	* @param[in]	pTitle		The title
	* @param[in]	pArtist		The artist
	* @param[in]	pAlbum		The album
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified @c source, @c pTitle, @c pArtist, or @c pAlbum is an empty string.
	* @exception	E_MAX_EXCEEDED		The media is already attached.
	*/
	result	AttachMp3(const Osp::Base::String& source, const Osp::Base::String* pTitle, const Osp::Base::String* pArtist, const Osp::Base::String* pAlbum);

private:
	Osp::Base::String*		__pTargetId;
	Osp::Base::String		__message;
	Osp::Base::String		__title;
	Osp::Base::String		__titleHyperlink;
	Osp::Base::String		__summary;
	Osp::Base::String		__detail;
	Osp::Base::String		__mediaType;
	Osp::Base::String		__imageSource;
	Osp::Base::String		__imageHyperlink;
	Osp::Base::String		__flashSource;
	Osp::Base::String		__flashImageSource;
	int						__flashWidth;
	int						__flashHeight;
	int						__flashExpandedWidth;
	int						__flashExpandedHeight;
	Osp::Base::String		__mp3Source;
	Osp::Base::String		__mp3Title;
	Osp::Base::String		__mp3Artist;
	Osp::Base::String		__mp3Album;

	Osp::Base::String		__linkText;
	Osp::Base::String		__linkTextHyperlink;

	Osp::Base::Collection::ArrayList		__additionalPropertyList;
	SnsPrivacyLevel			__privacyLevel;

	friend class SnsPostInfoEx;
	class SnsPostInfoEx* __pSnsPostInfoEx;
};

};};};// Osp::Social::Services

#endif //_FSCL_SVC_SNS_POST_INFO_H_
