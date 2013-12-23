/* $Change: 1203928 $ */
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
 * @file		FCntRemoteCategory.h
 * @brief		This is the header file for the %RemoteCategory class.
 *
 * This header file contains the declarations of the %RemoteCategory class.
 */

#ifndef _FCNT_REMOTE_CATEGORY_H_
#define _FCNT_REMOTE_CATEGORY_H_

#include <FCntConstants.h>

namespace Osp { namespace Content {
	
class RemoteCategoryEx;

/**
 * @class	RemoteCategory
 * @brief	This class provides methods to access the remote category.
 * @deprecated	This class is deprecated due to the operation policy of the bada Server. An alternate class will be introduced in the near future.
 * @since	1.0
 *
 * The %RemoteCategory class provides methods to access the remote category.
 * The category is a logical classification concept for contents on bada Server. It is different from the content type.
 * To use the category for server contents, define categories through the 'content component setup' menu of the developer site(DS).
 * The category is an optional feature. @n
 * The %RemoteCategory class provides the category ID, the category name, and its hierarchy from the bada Server. 
 * It gives the parent category ID and informs if it has child categories or not. If there are child categories, 
 * the current category can get its child categories by itself. 
 * 
 * The following example demonstrates how to use the %IRemoteContentSearchListener interface.
 * @code
 *
 * /////////////////////////////////////
 * //MyClass.h
 *
 * #include <FContent.h>
 *
 * class RemoteContentSearchListenerImpl : public Osp::Content::IRemoteContentSearchListener
 * {
 * public:
 * RemoteContentSearchListenerImpl(void);
 * ~RemoteContentSearchListenerImpl(void);
 * 
 * void OnContentTypesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pContentTypeList,
 * result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
 * 
 * void OnCategoriesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pCategoryList,
 * result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
 * 
 * void OnRemoteContentSearchResultReceivedN(RequestId reqId,
 * Osp::Base::Collection::IList* pRemoteContentInfoList,
 * int currentPage, int countPerPage, int totalPageCount, int totalCount, result r,
 * const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
 * };
 *
 * class MyClass
 * {
 *	public:
 *		MyClass(void){};
 *		~MyClass(void){};
 *		void Test(void);
 *
 * };
 *
 * /////////////////////////////////////
 * //MyClass.cpp
 *
 * #include "MyClass.h"
 *
 * using namespace Osp::Base;
 * using namespace Osp::Base::Collection;
 * using namespace Osp::Content;
 *
 * 
 * RemoteContentSearchListenerImpl::RemoteContentSearchListenerImpl() {}
 * RemoteContentSearchListenerImpl::~RemoteContentSearchListenerImpl() {}
 *  
 * void
 * RemoteContentSearchListenerImpl::OnContentTypesReceivedN(RequestId reqId, IList* pContentTypeList,
 * result r, const String& errorCode, const String& errorMessage)
 * {
 * 	//Checks the result
 * 	if(IsFailed(r)){
 * 		//Checks errorCode
 * 		//Checks errorMessage
 * 	}
 * 
 *  //Gets the content type
 *  String* pContentType = (String*)pContentTypeList->GetAt(0);
 * 
 * 	//Do something
 * 
 * }
 * 
 * void
 * RemoteContentSearchListenerImpl::OnCategoriesReceivedN(RequestId reqId, IList* pCategoryList,
 * 	result r, const String& errorCode, const String& errorMessage)
 * {
 * 	//Checks the result
 * 	if(IsFailed(r)){
 * 		//Checks errorCode
 * 		//Checks errorMessage
 * 	}
 * 
 * 	//Gets the first category from the list
 * 	RemoteCategory* pCategory = null;
 * 	pCategory = (RemoteCategory*)pCategoryList->GetAt(0);
 * 
 * 	//Gets the id, name
 * 	String categoryID = pCategory->GetId();
 * 	String categoryName = pCategory->GetName();
 * 
 * }
 * 
 *  void
 *  RemoteContentSearchListenerImpl::OnRemoteContentSearchResultReceivedN(RequestId reqId,
 *   		IList* pRemoteContentInfoList,
 *   		int currentPage, int countPerPage, int totalPageCount, int totalCount, result r,
 *   		const String& errorCode, const String& errorMessage)
 *    {
 *   	//Checks the result
 *   	if(IsFailed(r)){
 *   		//Checks errorCode
 *   		//Checks errorMessage
 *   	}
 * 
 *   	//Do something;
 * 
 * }
 *
 * void
 * MyClass::Test(void)
 * {
 *	RemoteContentSearchListenerImpl* pListener = new RemoteContentSearchListenerImpl();
 *
 * 	//construct ContentSearch
 * 	RemoteContentSearch* pSearch = new RemoteContentSearch;
 * 	result r = pSearch->Construct(*pListener);
 * 	if(IsFailed(r)){
 * 		//Do something for an error
 * 	}
 *
 * 	//Gets the root category list
 * 	RequestId reqId;
 * 	r = pSearch->GetCategoryList(reqId);
 * 	if(IsFailed(r)){
 * 		//Do something for an error
 * 	}
 *
 * 	//Checks its listener
 *
 *	delete pSearch;
 * }
 *
 * @endcode
 *
 */
 class _EXPORT_CONTENT_ RemoteCategory :
	public Osp::Base::Object
{

public:
// Lifecycle
	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	 * 			 and security-related issues that might arise after using this method.
	 *
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 * @remarks		After creating an instance of %RemoteCategory class, one of the Construct() method must be called explicitly to initialize this instance.
	 * @see			Construct()
	 */
	RemoteCategory(void);

	/**
	 * This is the copy constructor for the %RemoteCategory class.
	 *
	 * @since			1.0
	 * @param[in]	category			A reference to the %RemoteCategory class
	 *
	 */
	RemoteCategory(RemoteCategory& category);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~RemoteCategory(void);

public:
// Access
	/**
	 * Gets the category ID.
	 *
	 * @since			1.0
	 * @return		The category ID
	 *
	 */
	Osp::Base::String GetId(void) const;

	/**
	 * Gets the category name.
	 *
	 * @since			1.0
	 * @return		The category name
	 *
	 */
	Osp::Base::String GetName(void) const;

	/**
	 * Gets the category's parent ID.
	 *
	 * @since			1.0
	 * @return		The category's parent ID
	 * @remarks		If the parent ID is the root category, it is an empty string.
	 *
	 */
	Osp::Base::String GetParentId(void) const;

	/**
	 * Checks whether the category has any subcategories.
	 *
	 * @since			1.0
	 * @return		@c true if the category has subcategories, @n
	 *				else @c false
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *
	 */
	bool HasChildCategory(void) const;

	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	 * 			 and security-related issues that might arise after using this method.
	 *
	 * Sets the category ID.
	 *
	 * @since		1.0
	 * @param[in]	categoryId			The category ID
	 * @see			RemoteCategory()
	 */
	void SetId(const void* categoryId);

	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	 * 			 and security-related issues that might arise after using this method.
	 *
	 * Sets the category name.
	 *
	 * @since		1.0
	 * @param[in]	categoryName		The category name
	 * @see			RemoteCategory()
	 */
	void SetName(const void* categoryName);

	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	 * 			 and security-related issues that might arise after using this method.
	 *
	 * Sets the parent category's ID.
	 *
	 * @since		1.0
	 * @param[in]	parentId			The parent category's ID
	 * @see			RemoteCategory()
	 */
	void SetParentId(const void* parentId);

	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	 * 			 and security-related issues that might arise after using this method.
	 *
	 * Sets the flag that indicates if the category has the child categories.
	 *
	 * @since		1.0
	 * @param[in]	hasSubCategory		Set to @c true to indicate that this category has subcategories @n
										@c false, otherwise
	 * @see			RemoteCategory()
	 */
	void SetChildCategoryFalg(bool hasSubCategory);

//attributes
private:
	Osp::Base::String __categoryId;
	Osp::Base::String __categoryName;
	Osp::Base::String __parentId;
	bool __hasChildCategory;

	friend class RemoteContentSearch;
	friend class RemoteCategoryEx;
	class RemoteCategoryEx* __pRemoteCategoryEx;

};

}; }; // Osp::Content

#endif// _FCNT_REMOTE_CATEGORY_H_

