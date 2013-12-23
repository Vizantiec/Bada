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
* @file			FCntRemoteContentInfo.h
* @brief		This is the header file for the %RemoteContentInfo class.
*
* This header file contains the declarations of the %RemoteContentInfo class.
*/

#ifndef _FCNT_REMOTE_CONTENT_INFO_H_
#define _FCNT_REMOTE_CONTENT_INFO_H_

#include <FCntConstants.h>
#include <FBaseColIEnumerator.h>

struct MRemoteContentVO;
struct _IAsyncContentManagerListener;

namespace Osp { namespace Content {

class ContentInfo;
class RemoteContentInfoEx;

/**
* @class		RemoteContentInfo
* @brief		This class provides methods to access the remote content information.
* @deprecated	This class is deprecated due to the operation policy of the bada Server. An alternate class will be introduced in the near future.
* @since		1.0
*
* The %RemoteContentInfo class provides methods to access the remote content information.
* It is similar to the ContentInfo class. As the information schema can be dynamically configured by a service developer, the %RemoteContentInfo schema is more flexible than the schema of the device content.
* The service application developer already knows the server contents information schema and gets additional information from %RemoteContentInfo through the map object.
*
* The following example demonstrates how to use the %RemoteContentInfo class.
*
* @code
* /////////////////////////////////////
* // TestApp.h
*
* class UtsContentManagerListener : public IRemoteContentManagerListener
* {
*  public:
*		UtsContentManagerListener() {}
*		~UtsContentManagerListener() {}
*
*		virtual void OnContentInfoReceivedN(RequestId reqId, RemoteContentInfo* pRemoteContentInfo, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
*		virtual void OnContentCreated(RequestId reqId, const Osp::Base::String& contentId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
*		virtual void OnContentDeleted(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
*		virtual void OnContentStatusReceived(RequestId reqId, RemoteContentStatus contentStatus, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
*		virtual void OnContentUpdated(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
* };
*
*
* /////////////////////////////////////
* // TestApp.cpp
*
* void
* UtsContentManagerListener::OnContentInfoReceivedN(RequestId reqId, RemoteContentInfo* pRemoteContentInfo, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage)
* {
*		// Do something
* }
*
* void
* UtsContentManagerListener::OnContentCreated(RequestId reqId, const Osp::Base::String& contentId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage)
* {
*		// Do something
* }
*
* void
* UtsContentManagerListener::OnContentDeleted(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage)
* {
*		// Do something
* }
*
* void
* UtsContentManagerListener::OnContentStatusReceived(RequestId reqId, RemoteContentStatus contentStatus, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage)
* {
*		// Do something
* }
*
* void
* UtsContentManagerListener::OnContentUpdated(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage)
* {
*		// Do something
* }
*
* result
* MyClass::TestRemoteContentInfo(void)
* {
*		result r = E_SUCCESS;
*		UtsContentManagerListener managerListener;
*
*		RemoteContentManager remoteContentManager;
*		r = remoteContentManager.Construct(managerListener);
*		TryReturn(!IsFailed(r), r, "Construct failed.");
*
*		Osp::Base::Utility::Uri uri;
*		r = uri.SetPath(L"Image.jpg");
*		TryReturn(!IsFailed(r), r, "SetPath failed.");
*
*		RemoteContentInfo remoteContentInfo;
*		r = remoteContentInfo.Construct(L"Image", uri, 12345);
*		TryReturn(!IsFailed(r), r, "Construct failed.");
*
*		r = remoteContentInfo.SetContentName(L"sample code");
*		TryReturn(!IsFailed(r), r, "SetContentName failed.");
*
*		r = remoteContentInfo.SetProvider(L"KyeongWoo");
*		TryReturn(!IsFailed(r), r, "SetProvider failed.");
*
*		return r;
* }
* @endcode
*/
extern "C"
class _EXPORT_CONTENT_ RemoteContentInfo :	public Osp::Base::Object
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	* @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	*/
	RemoteContentInfo(void);

	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~RemoteContentInfo(void);

	/**
	* Initializes this instance of %RemoteContentInfo with the specified content type, path, and size.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	contentType			The content type
	* @param[in]	contentPath			The content path
	* @param[in]	contentSize			The content size
	* @param[in]	thumbnailPath		The thumbnail path
	* @param[in]	thumbnailSize		The thumbnail size
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	*/
	result Construct(const Osp::Base::String& contentType, const Osp::Base::Utility::Uri& contentPath, int contentSize, const Osp::Base::Utility::Uri* thumbnailPath = null, int thumbnailSize = 0);

	/**
	* This is the copy constructor for the %RemoteContentInfo class.
	*
	* @since		1.0
	* @param[in]	remoteContentInfo	An instance of %RemoteContentInfo to initialize the calling instance
	*/
	RemoteContentInfo(const RemoteContentInfo& remoteContentInfo);

	/**
	* Gets the content ID.
	*
	* @since		1.0
	* @return		The content ID
	*/
	Osp::Base::String GetContentId(void) const;

	/**
	* Gets the content type.
	*
	* @since		1.0
	* @return		The content type
	*/
	Osp::Base::String GetContentType(void) const;

	/**
	* Sets the category.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	category			The new category
	* @exception	E_SUCCESS  			The method is successful.
	* @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of the total length of 300 characters, @n
    *                                  or it exceeds the individual category length of 10 characters.
	* @remarks		An application can set multiple categories (that is, "category01, category02, category03"). 
	*				The maximum length of one individual category is 10 characters. 
	*				The total length of all categories cannot exceed 300 characters. 
	*				The category must exist on the server.
	*/
	result SetCategory(const Osp::Base::String& category);

	/**
	* Gets the category.
	*
	* @since		1.0
	* @return		The category
	*/
	Osp::Base::String GetCategory(void) const;

	/**
	* Gets the user ID.
	*
	* @since		1.0
	* @return		The user ID
	*/
	Osp::Base::String GetUserId(void) const;

	/**
	* Gets the creation date and time.
	*
	* @since		1.0
	* @return		The creation time
	*/
	Osp::Base::DateTime GetDateTime(void) const;

	/**
	* Gets the status.
	*
	* @since		1.0
	* @return		The content status
	*/
	RemoteContentStatus GetStatus(void) const;

	/**
	* Sets the content name.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	contentName			The new content name
	* @exception	E_SUCCESS  			The method is successful.
	* @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 300 characters.
	* @remarks		The specified @c contentName is a mandatory attribute on the server.
	*/
	result SetContentName(const Osp::Base::String& contentName);

	/**
	* Gets the content name.
	*
	* @since		1.0
	* @return		The content name
	*/
	Osp::Base::String GetContentName(void) const;

	/**
	* Sets the keyword.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	keyword				The new keyword
	* @exception	E_SUCCESS  			The method is successful.
	* @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 300 characters.
	*/
	result SetKeyword(const Osp::Base::String& keyword);

	/**
	* Gets the keyword.
	*
	* @since		1.0
	* @return		The keyword
	*/
	Osp::Base::String GetKeyword(void) const;

	/**
	* Sets the description.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	description			The new description
	* @exception	E_SUCCESS  			The method is successful.
	* @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 4000 characters.
	*/
	result SetDescription(const Osp::Base::String& description);

	/**
	* Gets the description.
	*
	* @since		1.0
	* @return		The description
	*/
	Osp::Base::String GetDescription(void) const;

	/**
	* Sets the short description.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	shortDescription	The new @c short description
	* @exception	E_SUCCESS  			The method is successful.
	* @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 1000 characters.
	*/
	result SetShortDescription(const Osp::Base::String& shortDescription);

	/**
	* Gets the short description.
	*
	* @since		1.0
	* @return		The @c short description
	*/
	Osp::Base::String GetShortDescription(void) const;

	/**
	* Sets the language.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	language			The new language
	* @exception	E_SUCCESS  			The method is successful.
	* @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 3 characters.
	*/
	result SetLanguage(const Osp::Base::String& language);

	/**
	* Gets the language.
	*
	* @since		1.0
	* @return		The language name
	*/
	Osp::Base::String GetLanguage(void) const;

	/**
	* Sets the rating.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	rating				The new rating
	* @exception	E_SUCCESS  			The method is successful.
	* @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 10 characters.
	*/
	result SetRating(const Osp::Base::String& rating);

	/**
	* Gets the rating.
	*
	* @since		1.0
	* @return		The rating
	*/
	Osp::Base::String GetRating(void) const;

	/**
	* Gets the thumbnail path.
	*
	* @since		1.0
	* @return		The thumbnail path
	*/
	Osp::Base::Utility::Uri GetThumbnailPath(void) const;

	/**
	* Gets the thumbnail size.
	*
	* @since		1.0
	* @return		The thumbnail size
	*/
	int GetThumbnailSize(void) const;

	/**
	* Sets the Digital Rights Management(DRM) information.
	*
	* @since		1.0
	* @param[in]	drmProtected		Set to @c true to indicate that this content has DRM protection, @n
    *									else @c false
	*/
	void SetDrmProtected(bool drmProtected);

	/**
	* Checks whether the content has the DRM information.
	*
	* @since		1.0
	* @return		@c true if this contents has DRM, @n
    *				else @c false
	*/
	bool IsDrmProtected(void) const;

	/**
	* Gets the content path.
	*
	* @since		1.0
	* @return		The content path
	*/
	Osp::Base::Utility::Uri GetContentPath(void) const;

	/**
	* Gets the size of the content.
	*
	* @since		1.0
	* @return		The content size
	*/
	int GetContentSize(void) const;

	/**
	* Sets the provider name.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	provider			The new content provider
	* @exception	E_SUCCESS  			The method is successful.
	* @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 10 characters.
	*/
	result SetProvider(const Osp::Base::String& provider);

	/**
	* Gets the provider name.
	*
	* @since		1.0
	* @return		The content provider
	*/
	Osp::Base::String GetProvider(void) const;

	/**
	* Sets the author name.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	author				The new author
	* @exception	E_SUCCESS  			The method is successful.
	* @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 100 characters.
	*/
	result SetAuthor(const Osp::Base::String& author);

	/**
	* Gets the author name.
	*
	* @since		1.0
	* @return		The name of the author
	*/
	Osp::Base::String GetAuthor(void) const;

	/**
	* Sets the additional information in a hash map.
	*
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	attributes			The additional information in a hash map
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified input parameter is invalid.
	*
	* @remarks		The only allowed type of key and value is Osp::Base::String.
	*
	* The following example demonstrates how to use the SetAdditionalAttributes() method.
	*
	* @code
	* 
	*		result r = E_SUCCESS;
	*		RemoteContentInfo remoteContentInfo;
	*
	*		Osp::Base::Utility::Uri uri;
	*		uri.SetPath(L"Image.jpg");
	*		r = remoteContentInfo.Construct(L"Image", uri, 12345);
	*		TryReturn(!IsFailed(r), r, "Construct failed.");
	*
	*	 	Osp::Base::Collection::HashMap map;
	*		map.Construct();
	*
	*		Osp::Base::String newKey(L"name");		// you can only use Osp::Base::String.
	*		Osp::Base::String newValue(L"kw1128");	// you can only use Osp::Base::String.
	*
	*		r = map.Add(newKey, newValue);
	*		TryReturn(!IsFailed(r), r, "Add failed.");
	*
	*		remoteContentInfo.SetAdditionalAttributes(map);
	*
	* @endcode
	*/
	result SetAdditionalAttributes(const Osp::Base::Collection::IMap& attributes);

	/**
	* Gets the additional attributes.
	*
	* @since		1.0
	* @return		A pointer to the IMap instance containing the additional information
	*/
	const Osp::Base::Collection::IMap* GetAdditionalAttributes(void) const;

	/**
	* @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	* 			and security-related issues that might arise after using this method.
	*
	* Copies the specified ContentInto to the calling remote content information.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	contentInfo		The pointer to the source ContentInfo
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG	A specified input parameter is invalid.
	*/
	result Copy(const ContentInfo &contentInfo);

private:

	enum {
		UPDATE_ADDITIONALATTRIBUTES,
		UPDATE_AUTHOR,
		UPDATE_CATEGORY,
		UPDATE_CONTENTNAME,
		UPDATE_DESCRIPTION,
		UPDATE_SHORTDESCRIPTION,
		UPDATE_DRMPROTECTED,
		UPDATE_KEYWORD,
		UPDATE_LANGUAGE,
		UPDATE_PROVIDER,
		UPDATE_RATING
	};

	bool __updatedField[11];

	MRemoteContentVO* __pRemoteContentVO;

	// contents vo
	Osp::Base::String	__serverContentId;
	Osp::Base::String	__contentType;
	Osp::Base::String	__createTime;
	RemoteContentStatus	__status;
	Osp::Base::String	__userId;

	// basic attribute
	Osp::Base::String	__contentName;
	Osp::Base::Utility::Uri __contentPath;
	int	__contentSize;
	Osp::Base::String	__keyword;
	Osp::Base::String	__longDesc;
	Osp::Base::String	__shortDesc;
	Osp::Base::String	__language;
	Osp::Base::String	__rating;
	Osp::Base::Utility::Uri __thumbnailPath;		/*__defaultImage*/
	int __thumbnailSize;							/*__defaultImageSize*/
	Osp::Base::String __defaultFile;
	int __defaultFileSize;
	bool __isDrmContent;
	Osp::Base::String	__author;
	Osp::Base::String	__provider;
	Osp::Base::String	__categoryId;
	Osp::Base::String	__categoryName;

	// contents item vo
	Osp::Base::Collection::ArrayList* __itemIdList;

	// map
	Osp::Base::Collection::HashMap* __pExtendedAttribute;

	RemoteContentInfo(const MRemoteContentVO* pRemoteContentVO);
	result AssignValue(MRemoteContentVO* __pRemoteContentVO);
	bool* GetUpdatedField(void) { return __updatedField; }
	void ResetUpdatedField(void);

	friend class __RemoteContentData;
	friend class RemoteContentManager;

	friend void __ContentManagerSCListener_onGetContentInfo(const _IAsyncContentManagerListener* pI, long reqId, void* pUserData, void* pContentVO, int eResult, int errorCode, void* errorMessage);

	friend class RemoteContentInfoEx;
	class RemoteContentInfoEx* __pRemoteContentInfoEx;

};	// class RemoteContentInfo

}; };	// Osp::Content

#endif	// _FCNT_REMOTE_CONTENT_INFO_H_
