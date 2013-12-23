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
/*
* @file			FCntRemoteContentItemInfo.h
* @brief		This is the header file for the %RemoteContentItemInfo  class.
*
* This header file contains the declarations of the %RemoteContentItemInfo class.
*/

#ifndef _FCNT_REMOTE_CONTENT_ITEM_INFO_H_
#define _FCNT_REMOTE_CONTENT_ITEM_INFO_H_

#include <FCntConstants.h>
#include <FBaseColIEnumerator.h>

typedef Osp::Base::String ServerContentItemId;
struct MRemoteContentItemVO;
struct _IAsyncContentManagerListener;

namespace Osp { namespace Content {

class RemoteContentItemInfoEx;

/**
* @internal		This class is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
* 				and security-related issues that might arise after using this method.
* @class		RemoteContentItemInfo
* @brief		This class represents remote content item information.
* @since		1.0
*
* This class represents remote content item information. The service application developer should be aware of the server content item information schema.
*
* The following example demonstrates how to use the %RemoteContentItemInfo class.
* @code
* result
* MyClass::TestRemoteContentItemInfo(void)
* {
* 		result r = E_SUCCESS;
* 		RequestId reqId;
* 		Osp::Base::String contentId;
* 		Osp::Base::String contentItemId;
*
* 		UtsContentManagerListener managerListener;
*
*		RemoteContentManager remoteContentManager;
*		r = remoteContentManager.Construct(managerListener);
*		TryReturn(!IsFailed(r), r, "Construct failed.");
*
*		// Gets the content id with RemoteContentManager::CreateContent()
*		// Gets the content item id with RemoteContentInfo::GetItemIDList()
*
*		r = remoteContentManager.GetContentItemInfo(contentId, contentItemId, reqId);
*		TryReturn(!IsFailed(r), r, "GetContentItemInfo failed.");
*
*		return r;
* }
* @endcode
*/
extern "C"
class RemoteContentItemInfo : public Osp::Base::Object
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	*/
	RemoteContentItemInfo(void);

	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~RemoteContentItemInfo(void);

	/**
	* Sets the item name.
	*
	* @since		1.0
	* @param[in]	itemName			The new item name
	* @exception	E_SUCCESS  			The method is successful.
	* @exception	E_INVALID_ARG		The length of the input data exceeds system limitations (300).
	*/
	result SetItemName(const Osp::Base::String& itemName);

	/**
	* Gets the item name.
	*
	* @since		1.0
	* @return		The item name
	*/
	Osp::Base::String GetItemName(void) const;

	/**
	* Sets the item keyword.
	*
	* @since		1.0
	* @param[in]	itemKeyword			The new item keyword
	* @exception	E_SUCCESS  			The method is successful.
	* @exception	E_INVALID_ARG		The length of the input data exceeds system limitations (300).
	*/
	result SetItemKeyword(const Osp::Base::String& itemKeyword);

	/**
	* Gets the item keyword.
	*
	* @since		1.0
	* @return		The keyword
	*/
	Osp::Base::String GetItemKeyword(void) const;

	/**
	* Sets the item description.
	*
	* @since		1.0
	* @param[in]	itemDescription		The new item description
	* @exception	E_SUCCESS  			The method is successful.
	* @exception  	E_INVALID_ARG		The length of the input data exceeds system limitations (4000).
	*/
	result SetItemDescription(const Osp::Base::String& itemDescription);

	/**
	* Gets the item description.
	*
	* @since		1.0
	* @return		The item description
	*/
	Osp::Base::String GetItemDescription(void) const;

	/**
	* Sets the item's target device.
	*
	* @since		1.0
	* @param[in]	targetDevice		The new target device
	* @exception	E_SUCCESS  			The method is successful.
	* @exception	E_INVALID_ARG		The length of the input data exceeds system limitations (1333).
	*/
	result SetItemTargetDevice(const Osp::Base::String& targetDevice);

	/**
	* Gets the item's target device.
	*
	* @since		1.0
	* @return		The item target device
	*/
	Osp::Base::String GetItemTargetDevice(void) const;

	/**
	* Sets the default file of the item.
	*
	* @since		1.0
	* @param[in]	itemDefaultFile		The default file
	* @exception	E_SUCCESS  			The method is successful.
	* @exception	E_INVALID_ARG		The length of the input data exceeds system limitations (500).
	*/
	result SetItemDefaultFile(const Osp::Base::String& itemDefaultFile);

	/**
	* Gets the default file of the item.
	*
	* @since		1.0
	* @return		The default file
	*/
	Osp::Base::String GetItemDefaultFile(void) const;

	/**
	* Sets the size of the item's default file.
	*
	* @since		1.0
	* @param[in]	itemDefaultFileSize	The size of the default file
	* @exception	E_SUCCESS  			The method is successful.
	* @exception	E_INVALID_ARG		The length of the input data exceeds system limitations (500).
	*/
	result SetItemDefaultFileSize(const Osp::Base::String& itemDefaultFileSize);

	/**
	* Gets the size of the item's default file.
	*
	* @since		1.0
	* @return		The size of the default file
	*/
	Osp::Base::String GetItemDefaultFileSize(void) const;

	/**
	* Adds the specified item attribute.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	key				The key
	* @param[in]	value			The value
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	A specified input parameter is invalid.
	*/
	result AddItemAttribute(const Osp::Base::String& key, const Osp::Base::String& value);

	/**
	* Removes the item attribute.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	key				The key
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified input parameter is invalid.
	*/
	result RemoveItemAttribute(Osp::Base::String& key);

	/**
	* Gets the enumerator for the item attribute.
	*
	* @since		1.0
	* @return		An IMapEnumerator pointer to the item
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
	*/
	const Osp::Base::Collection::IMapEnumerator* GetItemAttributeEnumeratorN(void);

private:
	MRemoteContentItemVO* __pRemoteContentItemVO;
	result AssignValue(MRemoteContentItemVO* __pRemoteContentVO);

	// content item vo
	Osp::Base::String __itemID;
	Osp::Base::String __itemName;
	Osp::Base::String __itemKeyword;
	Osp::Base::String __itemDescription;
	Osp::Base::String __itemTargetDevice;
	Osp::Base::String __itemDefaultFile;
	Osp::Base::String __itemDefaultFileSize;

	// map
	Osp::Base::Collection::HashMap* __pItemAttribute;		// for item attribute
	Osp::Base::Collection::IMapEnumerator* __pItemAttributeEnum;

	RemoteContentItemInfo(const MRemoteContentItemVO* pRemoteContentVO);

	friend class __RemoteContentData;
	friend void __ContentManagerSCListener_onGetContentItemInfo(const _IAsyncContentManagerListener* pI, long reqId, void* pUserData, void* pContentItemVO, int eResult, int errorCode, void* errorMessage);

	friend class RemoteContentItemInfoEx;
	class RemoteContentItemInfoEx* __pRemoteContentItemInfoEx;

};	// class RemoteContentItemInfo

}; };	// Osp::Content

#endif	// _FCNT_REMOTE_CONTENT_ITEM_INFO_H_
