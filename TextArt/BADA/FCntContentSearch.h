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
 * @file		FCntContentSearch.h
 * @brief		This is the header file for the %ContentSearch class.
 *
 * This header file contains the declarations of the %ContentSearch class.
 */

#ifndef _FCNT_CONTENT_SEARCH_H_
#define _FCNT_CONTENT_SEARCH_H_

#include <FCntConstants.h>

struct IContentSearch;

namespace Osp { namespace Content {

class ContentSearchEx;

/**
 * @class	ContentSearch
 * @brief	This class provides the methods for the content search. 
 * @since	1.0
 *
 * The %ContentSearch class provides methods to search content based on conditions and to retrieve the results for a specific
 * column. It also enables searching for content stored on the bada device. The local content is stored in the form of database columns. 
 *
 * For more information on the database columns and their corresponding content types, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/content/content_search_device.htm">Content Search on the Device</a>.
 *
 * The following example demonstrates how to use the %ContentSearch class.
 *
 * @code
 *
 * /////////////////////////////////////
 * //MyClass.cpp
 *
 * #include <FContent.h>
 *
 * using namespace Osp::Base;
 * using namespace Osp::Base::Collection;
 * using namespace Osp::Content;
 *
 * void
 * MyClass::Test(void)
 * {
 *	//Call Construct() of ContentSearch
 *	ContentSearch search;
 *	result r = search.Construct(CONTENT_TYPE_AUDIO);
 *	if(IsFailed(r)){
 *		//Do something for an error
 *	}
 *
 *	//Call SearchN() of ContentSearch as the first page
 *	int pageNo = 1;
 *	int countPerPage = 5;
 *	int totalPage = 0;
 *	int totalCount = 0;
 *	IList* pContentInfoList = search.SearchN(pageNo, countPerPage, totalPage, totalCount, 
 *				L"Artist='rain'", L"Title", SORT_ORDER_ASCENDING);
 *	if(IsFailed(GetLastResult())){
 *		//Do something for an error
 *	}
 *
 *	//Delete resource
 *	pContentInfoList->RemoveAll(true);
 *	delete pContentInfoList;
 * }
 *
 * @endcode
 *
 */
class _EXPORT_CONTENT_ ContentSearch :
	public Osp::Base::Object
{

public:
// Lifecycle
	/**
	 * This is the default constructor for this class.
	 *
	 * @since			1.0
	* @remarks	After creating an instance of this class, one of the Construct() methods must be called explicitly to
	*			initialize this instance.
	 * @see Construct()
	 */
	ContentSearch(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~ContentSearch(void);

	/**
	 * Initializes this instance of %ContentSearch with the specified parameter.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	type			The content type
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_SYSTEM	A system error has occurred.
	 *
	 * @remarks 	To search a specific type, use the content type as CONTENT_TYPE_OTHER, CONTENT_TYPE_IMAGE, CONTENT_TYPE_AUDIO or CONTENT_TYPE_VIDEO.
	 *
	 * The following example demonstrates how to use the Construct() method.
	 *
	 * @code
	 *
	 *	//Call Construct() of ContentSearch
	 *	ContentSearch search;
	 *	result r = search.Construct(CONTENT_TYPE_IMAGE);
	 *	if(IsFailed(r)){
	 *		//Do something for an error
	 *	}
	 *
	 * @endcode
	 */
	result Construct(ContentType type);

//Operator
public:
	/**
	 * Gets the list consisting of values of a specified column in the specified order.
	 *
	 * @deprecated	This method is deprecated. Instead of using this method, it is recommended to use the
	 *   GetValueListN(int, int, int&, int&, const Osp::Base::String&, Osp::Base::SortOrder) 
	 *   method, that gets the value list of the specified column.
	 * @since				1.0
	 * @privlevel		NORMAL
	 * @privgroup		LOCAL_CONTENT
	 *	
	 * @return		A pointer to a list containing the values of the @c column @n
	 *				The type of value can be Osp::Base::Integer, Osp::Base::Double, Osp::Base::LongLong, Osp::Base::DateTime or Osp::Base::String. @n
	 *				An empty list is returned if the specified @c column has no value and there is no error, @n 
	 * 				else @c null if an exception occurs.
	 * @param[in]	column			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/content/content_search_device.htm">column</a> name
	 * @param[in]	sortOrder		The sort order
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified @c column is invalid or empty, or
	 *	                                the content is searched with @c type set as CONTENT_TYPE_UNKNOWN.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	 *				The return value must be deleted. The result of GetValueListN() returns a distinct value. @n
	 *				ContentType supports CONTENT_TYPE_OTHER, CONTENT_TYPE_IMAGE, CONTENT_TYPE_AUDIO, and CONTENT_TYPE_VIDEO.
	 *				If %ContentType in Construct() uses CONTENT_TYPE_UNKNOWN or an invalid value, E_INVALID_ARG occurs. 
	 *
	 * The following example demonstrates how to use the %Construct() method.
	 *
	 * @code
	 *
	 *	//Call Construct() of ContentSearch
	 *	ContentSearch search;
	 *	result r = search.Construct(CONTENT_TYPE_AUDIO);
	 *	if(IsFailed(r)){
	 *		//Do something for an error
	 *	}
	 *
	 *	//Call GetValueListN() of ContentSearch
	 *	IList* pValueList = search.GetValueListN(L"Artist");
	 *
	 *	if(IsFailed(GetLastResult())){
	 *		//Do something for an error
	 *	}		
	 *
	 *	//Do something
	 *
	 *	//Delete resource
	 *	pValueList->RemoveAll(true);
	 *	delete pValueList;
	 *
	 * @endcode
	 */
	Osp::Base::Collection::IList* GetValueListN(const Osp::Base::String& column, Osp::Base::SortOrder sortOrder = Osp::Base::SORT_ORDER_NONE);

	/**
	 *
	 * Searches the content and returns the search result list according to the query.
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup LOCAL_CONTENT
	 *
	 * @return		A pointer to a list containing the ContentSearchResult instances @n
	 *				An empty list is returned if there is no result and there is no error, @n 
	 *				else @c null if an exception occurs.
	 * @param[in]	pageNo			The page number @n
									It should be equal to or greater than @c 1.
	 * @param[in]	countPerPage	The count of the search results per page  @n
									It should be equal to or greater than @c 1.
	 * @param[out]	totalPageCount	The total page count of the search result
	 * @param[out]	totalCount		The total count of the search result
	 * @param[in]	whereExpr		The search condition like an sql "where" expression style @n
	 *								If it uses the default value, L"", it searches for all the content of the content type set in the constructor. @n
	 *								In case of the "DateTime" condition, the range starts from '01/01/1970 00:00:00'. @n
	 *								Every type of value has to be covered with single quotation marks, even if it is a decimal type.
	 * @param[in]	sortColumn		The sort <a href="../com.osp.cppappprogramming.help/html/dev_guide/content/content_search_device.htm">column</a> @n
									The default value is @c L"". 
	 * @param[in]	sortOrder		The sort order
	 * @exception	E_SUCCESS			The method was successful.
	 * @exception	E_INVALID_STATE	This instance has not been constructed yet.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_INVALID_ARG		 Either of the following conditions has occurred: @n
	 *	                                 	- The specified @c column is either invalid or empty. @n
	 *	                                 	- The content is searched with @c type set as CONTENT_TYPE_UNKNOWN.  @n
	 *	                                 	- The length of the specified @c whereExpr parameter exceeds 512 characters.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		A system error has occurred.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The return value must be deleted. @n
	 *				ContentType supports CONTENT_TYPE_OTHER, CONTENT_TYPE_IMAGE, CONTENT_TYPE_AUDIO, and CONTENT_TYPE_VIDEO.
	 *				If %ContentType in Construct() uses @c type as CONTENT_TYPE_UNKNOWN or an invalid value, E_INVALID_ARG occurs.
	 *
	 * The following example demonstrates how to use the %Construct() method.
	 *
	 * @code
	 *
	 *	//Call Construct() of ContentSearch
	 *	ContentSearch search;
	 *	result r = search.Construct(CONTENT_TYPE_AUDIO);
	 *	if(IsFailed(r)){
	 *		//Do something for an error
	 *	}
	 *
	 *	//Call SearchN() of ContentSearch as the first page
	 *	int pageNo = 1;
	 *	int countPerPage = 5;
	 *	int totalPage = 0;
	 *	int totalCount = 0;
	 *	IList* pContentInfoList = search.SearchN(pageNo, countPerPage, totalPage, totalCount, 
	 *				L"Artist='rain'", L"Title", SORT_ORDER_ASCENDING);
	 *	if(IsFailed(GetLastResult())){
	 *		//Do something for an error
	 *	}
	 *
	 *	//Do something
	 *
	 *	//Delete resource
	 *	pContentInfoList->RemoveAll(true);
	 *	delete pContentInfoList;
	 *
	 * @endcode
	 */
	Osp::Base::Collection::IList* SearchN(int pageNo, int countPerPage, int& totalPageCount, int& totalCount,
		const Osp::Base::String& whereExpr = L"",
		const Osp::Base::String& sortColumn = L"", Osp::Base::SortOrder sortOrder = Osp::Base::SORT_ORDER_NONE);

	/**
	 * Gets the value list of the specified column within a specified range.
	 *
	 * @since 		2.0
	 * @privlevel	NORMAL
	 * @privgroup	LOCAL_CONTENT
	 *
	 * @return		A pointer to a list containing the values of a column @n
	 *			The type of value can be Osp::Base::Float, Osp::Base::Double, Osp::Base::LongLong, Osp::Base::DateTime or Osp::Base::String. @n
	 *			An empty list is returned if the specified column has no value and there is no error, @n
	 * 			else @c null if an exception occurs.
	 * @param[in]	pageNo			The page number @n
	 *					It should be equal to or greater than @c 1.
	 * @param[in]	countPerPage		The count of the value list per page  @n
	 *					It should be equal to or greater than @c 1.
	 * @param[out]	totalPageCount		The total page count of the value list
	 * @param[out]	totalCount		The total count of the value list
	 * @param[in]	column			The <a href="../com.osp.cppappprogramming.help/html/dev_guide/content/content_search_device.htm">column</a> name
	 * @param[in]	sortOrder		The sort order
	 *
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified @c column is invalid or empty, or
	 *	                                 the content is searched with @c type set as CONTENT_TYPE_UNKNOWN.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		A system error has occurred.
	 *
	 * @remarks	The return value must be deleted.
	 *			The result of GetValueListN() returns a distinct value. @n
	 *			ContentType supports CONTENT_TYPE_OTHER, CONTENT_TYPE_IMAGE, CONTENT_TYPE_AUDIO, and CONTENT_TYPE_VIDEO.
	 *			If %ContentType in Construct() uses CONTENT_TYPE_UNKNOWN or an invalid value, E_INVALID_ARG occurs.
	 *
	 * The following example demonstrates how to get the value list of the specific @c column.
	 *
	 * @code
	 *
	 *	//Call Construct() of ContentSearch
	 *	ContentSearch search;
	 *	result r = search.Construct(CONTENT_TYPE_AUDIO);
	 *	if(IsFailed(r)){
	 *		//Do something for an error
	 *	}
	 *
	 *	//Call GetValueListN() of ContentSearch
	 *	int pageNo = 1;
	 *	int countPerPage = 10;
	 *	int totalPage = 0;
	 *	int totalCount = 0;
	 *	IList* pValueList = search.GetValueListN(pageNo, countPerPage, totalPage, totalCount, L"Genre");
	 *
	 *	if(IsFailed(GetLastResult())){
	 *		//Do something for an error
	 *	}
	 *
	 *	//Do something
	 *
	 *	//Delete resource
	 *	pValueList->RemoveAll(true);
	 *	delete pValueList;
	 *
	 * @endcode
	 */
	Osp::Base::Collection::IList* GetValueListN(int pageNo, int countPerPage, int& totalPageCount, int& totalCount, const Osp::Base::String& column, Osp::Base::SortOrder sortOrder = Osp::Base::SORT_ORDER_NONE);
	
private:
	IContentSearch* __pIContentSearch;
	
	friend class ContentSearchEx;
	class ContentSearchEx* __pContentSearchEx;

};


}; }; // Osp::Content

#endif// _FCNT_CONTENT_SEARCH_H_

