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
 * @file		FCntRemoteContentSearch.h 
 * @brief		This is the header file for the %RemoteContentSearch class.
 *
 * This header file contains the declarations and descriptions of the %RemoteContentSearch class.
 */

#ifndef _FCNT_REMOTE_CONTENT_SEARCH_H_
#define _FCNT_REMOTE_CONTENT_SEARCH_H_

#include <FCntIRemoteContentSearchListener.h>

struct MRemoteContentSearchRestClient;
struct MOspRestClient;
struct MXmlDocument;

namespace Osp { namespace Content {

class RemoteContentSearchEx;

/**
 * @class	RemoteContentSearch
 * @brief	This class provides methods to access the remote content search. 
 * @deprecated	This class is deprecated due to the operation policy of the bada Server. An alternate class will be introduced in the near future.
 * @since	1.0
 *
 * @pre		User should be authenticated. @n 
 *
 *			For more information, see the sign in Application control (Osp::App::APPCONTROL_SIGNIN).
 *
 * The %RemoteContentSearch class gets content types that are registered in the bada Server by the 
 * service provider. The content type is a mandatory parameter to search the server's contents. 
 *
 * The columns of search and sort are given below. 
 * Some of columns are basic attribute column and have to be defined to use in server component. @n
 * 
 * @image html RemoteContentSearch_ColumnTable.png
 *
 * A condition of the condition list in the search request is similar to the 'where expression' of an SQL query.
 * All possible operators are listed below. The 'BETWEEN' operator is not allowed.
 *
 * @code
 *	=  : equal
 *	>  : more than
 *	>= : more than or equal
 *	<  : less than
 *	<= : less than or equal
 *	!= : not equal
 *	LIKE
 * @endcode
 *
 * And if there are multiple conditions, the logical relation of conditions is "AND". The following 
 * example's conditions mean "KEYWORD='sample' AND LANGUAGE='en'". 
 *
 * @code
 *
 *	IList* pContentTypeList = null;
 *	String* pContentType = null;
 *	//it is supposed to get the content type list
 *
 *	//Sets condition list
 *	ArrayList conditionList;
 *	String condition1(L"KEYWORD='sample'");
 *	String condition2(L"LANGUAGE='en'");
 *
 *	conditionList.Add(condition1);
 *	conditionList.Add(condition2);
 *
 *	//Calls Search
 *	RequestId reqId;
 *	result r = Search(*pContentType, 1, 5, reqId, &conditionList);
 *	if(IsFailed(r)){
 *		//do something for an error
 *	}
 *	
 * @endcode
 *
 * All RemoteContentSearch() methods work asynchronously. To get the result of a request, 
 *  its listener should be implemented. 
 *
 *
 * The following example demonstrates how to use the %IRemoteContentSearchListener interface.
 *
 * @code
 *
 * /////////////////////////////////////
 * //MyClass.h
 *
 * #include <FContent.h>
 *
 * class RemoteContentSearchListenerImpl : public Osp::Content::IRemoteContentSearchListener
 * {
 *	public:
 *		RemoteContentSearchListenerImpl(void);
 *		~RemoteContentSearchListenerImpl(void);
 *
 *		void OnContentTypesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pContentTypeList, 
 *		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
 *
 *		void OnCategoriesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pCategoryList, 
 *		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
 *
 *		void OnRemoteContentSearchResultReceivedN(RequestId reqId, 
 *		Osp::Base::Collection::IList* pRemoteContentInfoList, 
 *		int currentPage, int countPerPage, int totalPageCount, int totalCount, result r, 
 *		const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
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
 * RemoteContentSearchListenerImpl::RemoteContentSearchListenerImpl() {}
 * RemoteContentSearchListenerImpl::~RemoteContentSearchListenerImpl() {}
 *
 * void
 * RemoteContentSearchListenerImpl::OnContentTypesReceivedN(RequestId reqId, IList* pContentTypeList, 
 *		result r, const String& errorCode, const String& errorMessage)
 * {
 *	//Checks result
 *	if(IsFailed(r)){
 *		//Checks errorCode
 *		//Checks errorMessage
 *	}
 *
 *	//Gets content type
 *	String* pContentType = (String*)pContentTypeList->GetAt(0);
 *
 *	//do something
 *
 * }
 * 
 * void
 * RemoteContentSearchListenerImpl::OnCategoriesReceivedN(RequestId reqId, IList* pCategoryList, 
 *		result r, const String& errorCode, const String& errorMessage)
 * {
 *	//check result
 *	if(IsFailed(r)){
 *		//Checks errorCode
 *		//Checks errorMessage
 *	}
 *	
 *	//do something;
 *
 * }
 * 
 * void
 * RemoteContentSearchListenerImpl::OnRemoteContentSearchResultReceivedN(RequestId reqId, 
 *		IList* pRemoteContentInfoList, 
 *		int currentPage, int countPerPage, int totalPageCount, int totalCount, result r, 
 *		const String& errorCode, const String& errorMessage)
 * {
 *	//Checks result
 *	if(IsFailed(r)){
 *		//Checks errorCode
 *		//Checks errorMessage
 *	}
 *	
 *	//do something;
 *
 * }
 * 
 * void
 * MyClass::Test(void)
 * {
 *	RemoteContentSearchListenerImpl* pListener = new RemoteContentSearchListenerImpl;
 *
 *	//construct ContentSearch
 *	RemoteContentSearch* pRemoteContentSearch = new RemoteContentSearch;
 *	result r = pRemoteContentSearch->Construct(*pListener);
 *	if(IsFailed(r)){
 *		//do something for an error
 *	}
 *
 *	//Gets the content type list
 *	RequestId reqId;
 *	r = pRemoteContentSearch->GetContentTypeList(reqId);
 *	if(IsFailed(r)){
 *		//Do something for an error
 *	}
 *
 *	//Checks its listener
 *
 *	//Deletes resources
 *	delete pRemoteContentSearch;
 *	delete pListener;
 *
 * }
 *
 * @endcode
 *
 */
class _EXPORT_CONTENT_ RemoteContentSearch :
	public Osp::Base::Object
{

public:
// Lifecycle
	/**
	 * This is the default constructor for this class.
	 *
	 * @since			1.0
	 * @remarks		After creating an instance of %RemoteContentSearch class, the Construct() method must be called explicitly to initialize this instance.
	 * @see Construct()
	 */
	RemoteContentSearch(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~RemoteContentSearch(void);

	/**
	 * Initializes this instance of %RemoteContentSearch with the specified IRemoteContentSearchListener.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	listener		A reference to IRemoteContentSearchListener
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 */
	result Construct(const IRemoteContentSearchListener& listener);

public:
// Access
	/**
	 *
	 * Gets a content type list.
	 *
	 * @since			1.0
	 * @privlevel	SYSTEM
	 * @privgroup REMOTE_CONTENT
	 *
	 * @pre			User should be authenticated. @n 
     *				For more information, see the sign in Application control (Osp::App::APPCONTROL_SIGNIN).
	 *
	 * @return		An error code
	 * @param[out]	reqId				The request ID @n
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			A system error has occurred. 
	 * @remarks		After calling this method, the result can be checked using the IRemoteContentSearchListener::OnContentTypesReceivedN() method. 
	 *
	 */
	result GetContentTypeList(RequestId& reqId);

	/**
	 *
	 * Gets a category list.
	 *
	 * @since			1.0
	 * @privlevel	SYSTEM
	 * @privgroup REMOTE_CONTENT
	 *
	 * @pre			User should be authenticated. @n 
     *				For more information, see the sign in Application control (Osp::App::APPCONTROL_SIGNIN).
	 *
	 * @return		An error code
	 * @param[out]	reqId			The request ID
	 * @param[in]	pParentCategory		A pointer to the parent category @n
	 * 									Set @c pParentCategory to get the sub-category of some category.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance has not been constructed as yet.
	 * @exception	E_OUT_OF_MEMORY	    The memory is insufficient.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		A system error has occurred. 
	 * @remarks		After calling this method, the result can be checked using the IRemoteContentSearchListener::OnCategoriesReceivedN() method. 
	 *
	 */
	result GetCategoryList(RequestId& reqId, const RemoteCategory* pParentCategory = null);

	/**
	 *
	 * Searches content for the condition list. 
	 *
	 * @since			1.0
	 * @privlevel	SYSTEM
	 * @privgroup REMOTE_CONTENT
	 *
	 * @pre			User should be authenticated. @n 
     *				For more information, see the sign in Application control (Osp::App::APPCONTROL_SIGNIN).
	 *
	 * @return		An error code
	 * @param[in]	contentType		The content type @n
	 *								It can be obtained by calling the GetContentTypeList() method.
	 * @param[out]	reqId			The request ID
	 * @param[in]	pageNo			The page number @n
	 *								It should be greater than or equal to @c 1.
	 * @param[in]	countPerPage	The count per each page of the search result @n
	 *								It should be greater than or equal to @c 1.
	 * @param[in]	pConditionList	A pointer to the condition list @n
	 *						If CREATE_DATE or UPDATE_DATE column is used to search condition, the format is 'mm/dd/yyyy hh:mm:ss'.  
	 * @param[in]	sortColumn		The sort column @n
	 *								The default value is @c L"". 
	 * @param[in]	sortOrder		The sort order @n
	 *								If the @c sortColumn is @c L"", this value is ignored.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY	  The memory is insufficient.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		A system error has occurred. 
	 * @remarks		After calling this method, the result can be checked using the IRemoteContentSearchListener::OnRemoteContentSearchResultReceivedN() method. 
	 *
	 */
	result Search(const Osp::Base::String& contentType, 
		RequestId& reqId, int pageNo = 1, int countPerPage = REMOTE_COUNT_PER_PAGE, 
		const Osp::Base::Collection::IList* pConditionList = null, 
		const Osp::Base::String& sortColumn = L"", Osp::Base::SortOrder sortOrder = Osp::Base::SORT_ORDER_NONE);

//operation
private:
	/*
	 * Creates an XML document to search contents.
	 *
	 * @return		The XML document
	 * @param[in]	contentType		The content type @n
	 *								The content type can be gained by GetContentTypeList()
	 * @param[in]	pageNo			The page number 
	 * @param[in]	countPerPage	The count per each page of the search result
	 * @param[in]	pConditionList	The pointer of condition list
	 * @param[in]	sortColumn		The sort column @n
									The default value is @c L"". 
	 * @param[in]	sortOrder		The sort order @n
	 *								If the @c sortColumn is @c L"", this value is ignored
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG A specified input parameter is invalid.
	 * @remark		After calling this method, the result can be checked using the IRemoteContentSearchListener::OnRemoteContentSearchResultReceivedN() method. 
	 *
	 */
	MXmlDocument* _CreateSearchXmlDocument(const Osp::Base::String& contentType, 
		int pageNo, int countPerPage, 
		const Osp::Base::Collection::IList* pConditionList, 
		const Osp::Base::String& sortColumn, Osp::Base::SortOrder sortOrder);

	/*
	 * Tokenizes the condition.
	 *
	 * @return		The XML document
	 * @param[in]	condition		The condition
	 * @param[out]	column			The column
	 * @param[out]	oper			The operation
	 * @param[out]	value			The value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG A specified input parameter is invalid.
	 *
	 */
	result _TokenizeCodition(const Osp::Base::String& condition, Osp::Base::String& column, 
		Osp::Base::String& oper, Osp::Base::String& value);

	/*
	 * Gets an operator from a condition.
	 *
	 * @return		The XML document
	 * @param[in]	condition		The condition
	 * @param[out]	oper			The value of operation
	 * @param[out]	indexOf			The index of the operator
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG A specified input parameter is invalid.
	 *
	 */
	result _GetOperator(const Osp::Base::String& condition, Osp::Base::String& oper, int& indexOf);

private:
	MOspRestClient* __pRestClient;
	MRemoteContentSearchRestClient* __pRemoteContentSearchRestClient;
	
	friend class RemoteContentSearchEx;
	class RemoteContentSearchEx* __pRemoteContentSearchEx;

};


}; }; // Osp::Content

#endif// _FCNT_REMOTE_CONTENT_SEARCH_H_

