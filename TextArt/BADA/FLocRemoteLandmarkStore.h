/* $Change: 1145044 $ */
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
 * @file		FLocRemoteLandmarkStore.h
 * @brief		This is the header file for the %RemoteLandmarkStore interface.
 *
 * This header file contains the declarations of the %RemoteLandmarkStore interface.
 */

#ifndef	_FLOC_REMOTE_LANDMARK_STORE_H_
#define _FLOC_REMOTE_LANDMARK_STORE_H_

#include "FLocationConfig.h"
#include "FBaseString.h"
#include "FBaseTypes.h"
#include "FBaseDateTime.h"
#include "FLocLandmarkStore.h"

// Forward declaration
struct MOspRestClient;
struct _IRemoteLandmarkStore;
struct _IRemoteLandmarkStoreListener;
struct MRemoteLandmarkStoreInfo;

namespace Osp { namespace Locations {

//Forward declaration
class IRemoteLandmarkStoreListener;

/**
* The maximum count of the result items in the page returned by a search operation.
*
* @deprecated   This constant is deprecated due to the operation policy of the bada Server.
* @since 1.0
*/
static const int	LOC_MAX_COUNT_PER_PAGE = 100;
/**
* The minimum count of the result items in the page returned by a search operation.
*
* @deprecated   This constant is deprecated due to the operation policy of the bada Server.
* @since 1.0
*/
static const int	LOC_MIN_COUNT_PER_PAGE = 20;
/**
* The default count of the result items in the page returned by a search operation.
*
* @deprecated   This constant is deprecated due to the operation policy of the bada Server.
* @since 1.0
*/
static const int	LOC_DEFAULT_COUNT_PER_PAGE = 20;

/**
* @class		RemoteLandmarkStoreInfo
* @brief		This class represents the information about a remote landmark store.
* @deprecated   This class is deprecated due to the operation policy of the bada Server.
* @since		1.0
*
* The %RemoteLandmarkStoreInfo class represents the information about a remote landmark store, including the name, type, creator, timestamp, and ability of the store. 
*				It is obtained by the RemoteLandmarkStore::GetInfo() method.
*
* @{
*/
class _EXPORT_LOCATION_ RemoteLandmarkStoreInfo:
	public Osp::Base::Object{
// Life-cycle
private:
	/**
	* This is the default constructor for this class.
    *
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
    * @since		1.0
	*/
	RemoteLandmarkStoreInfo(void);

public:
	/**
	* This is the copy constructor for the %RemoteLandmarkStoreInfo class.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	*/
	RemoteLandmarkStoreInfo(const RemoteLandmarkStoreInfo& value);

	/**
	* This operator assigns the value of the %RemoteLandmarkStoreInfo object to the current instance.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	*/
	RemoteLandmarkStoreInfo& operator=(const RemoteLandmarkStoreInfo& rhs);

	/**
	* This is the destructor for this class.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	*/
	virtual	~RemoteLandmarkStoreInfo(void);

// Operations - Osp::Locations::RemoteLandmarkStoreInfo
public:

	/**
	* Gets the name of the landmark store.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return	The name of the landmark store
	*/
	Osp::Base::String	GetName(void)	const;

	/**
	* Gets the creator of the landmark store.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return	The creator of the landmark store
	*/
	UserId	GetCreator(void)	const;

	/**
	* Gets the provider of the landmark store.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return	The provider of the landmark store
	*/
	Osp::Base::String	GetProvider(void)	const;

	/**
	* Gets the extra information of the landmark store.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return	The extra information of the landmark store
	*/
	Osp::Base::String	GetExtraInfo(void)	const;

	/**
	* Gets the time of creation of the landmark store.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return	The time of creation of the landmark store
	*/
	Osp::Base::DateTime	GetCreatedTime(void)	const;

	/**
	* Gets the latest updated time of the landmark store.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return	The latest updated time of the landmark store
	*/
	Osp::Base::DateTime	GetLatestUpdatedTime(void)	const;

	/**
	* Checks whether this landmark store supports only read operations.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return	@c true if this landmark store supports only read operations, @n
	*			else @c false
	*/
	bool	IsReadOnly(void)	const;

// internal
private:
	//NOTE: Ownership for pObject is transferred to the RemoteLandmarkStoreInfo instance.
	RemoteLandmarkStoreInfo(MRemoteLandmarkStoreInfo* pObject);

// Data members
private:
    MRemoteLandmarkStoreInfo*   __pMInfo;

friend class _LocationUtil;

private:
	friend class RemoteLandmarkStoreInfoEx;
	class RemoteLandmarkStoreInfoEx* __pRemoteLandmarkStoreInfoEx;
};	// class RemoteLandmarkStoreInfo
/**
* @}
*/


/**
* @class	RemoteLandmarkStore
* @brief	This class provides the methods to store, delete, and retrieve landmarks to/from the landmark store on the server side.
* @deprecated   This class is deprecated due to the operation policy of the bada Server.
* @since	1.0
*
* @remarks  The remote landmark store supports Unicode characters for the store name and textual fields of the
* landmarks @b since: @b 2.0. In the bada API versions prior to 2.0, some Unicode characters are not supported.
* See the remarks of CreateLandmarkStore() and the compatibility of AddLandmark() for more details.
*
* The %RemoteLandmarkStore class provides the methods to store, delete, and retrieve landmarks to/from the landmark store on the server side.
* The server side includes two types of remote landmark stores, those created by users and those published by a content provider.
* The remote landmark stores can be created and deleted using the CreateLandmarkStore() and DeleteLandmarkStore() methods respectively.
*
* The following example demonstrates how to use the %RemoteLandmarkStore class.
*
* @code
*
*   #include <FBase.h>
*   #include <FLocations.h>
*
*   using namespace Osp::Base;
*   using namespace Osp::Base::Collection;
*   using namespace Osp::Locations;
*
*   class MyClass: public IRemoteLandmarkStoreListener
*   {
*   public:
*   	MyClass(void);
*   	~MyClass(void);
*
* 	    void CreateRemoteLandmarkStore(void);
* 	    void AddLandmarkToRemoteLandmarkStore(void);
*   	void SearchLandmarksFromRemoteLandmarkStore(void);
* 	    void DeleteRemoteLandmarkStore(void);	
*
*        // IRemoteLandmarkStoreListener
*       public:
*       void OnLandmarkStoreCreated(RequestId requestId, result r, const String& errorCode, const String& errorMsg) {
*		    if (IsFailed(r)) {
*			    AppLog("Failed to CreateLandmarkStore(ErrorCode: %S-%S)", errorCode.GetPointer(), errorMsg.GetPointer());
*		    }
*   	}
*
*	    void OnLandmarkStoreDeleted(RequestId requestId, result r, const String& errorCode, const String& errorMsg) {
*		    if (IsFailed(r)) {
*			    AppLog("Failed to DeleteLandmarkStore(ErrorCode: %S-%S)", errorCode.GetPointer(), errorMsg.GetPointer());
*		    }
*	    }
*
*	    void OnLandmarkAdded(RequestId reqId, Landmark* pLandmark, result r, const String& errorCode, const String& errorMsg) {
*		    if (IsFailed(r)) {
*			    AppLog("Failed to AddLandmark(ErrorCode: %S-%S)", errorCode.GetPointer(), errorMsg.GetPointer());
*		    } else {
*			    AppLog("Landmark is added. Id(%d) is assigned to the landmark", pLandmark->GetLandmarkId());
*		    }
*	    }
*
*	    void OnLandmarksReceivedN(RequestId reqId, IList* pResults, int pageNo, int countPerPage, int totalPageCount, int totalCount, result r, const String& errorCode, const String& errorMsg) {
*		    if (IsFailed(r)) {
*			    AppLog("Failed to SearchLandmarks(ErrorCode: %S-%S)", errorCode.GetPointer(), errorMsg.GetPointer());
*		    } 
*		
*		    if (pResults) {
*			    AppLog("Page information : %d/%d", pageNo, totalPageCount);
*			    IEnumerator* pEnumerator = pResults->GetEnumeratorN();
*			
*			    while(!IsFailed(pEnumerator->MoveNext())) {
*				    const Landmark* item = static_cast<const Landmark*>(pEnumerator->GetCurrent());
*				    String name = item->GetName();
*				    AppLog("Landmark Retrieved(%S).", name.GetPointer());
*			    }
*
*			    delete pEnumerator;
*			    pResults->RemoveAll(true);
*			    delete pResults;
*		    }
*	    }
*	
*   	void OnLandmarkStoreNamesReceivedN(RequestId reqId, IList* pResults, int pageNo, int countPerPage, int totalPageCount, int totalCount, result r, const String& errorCode, const String& errorMsg) {}
*	    void OnLandmarkStoreExtraInfoChanged(RequestId reqId, result r, const String& errorCode, const String& errorMsg){}
*	    void OnLandmarkDeleted(RequestId reqId, result r, const String& errorCode, const String& errorMsg) {}
*       void OnLandmarkStoreInfoReceived(RequestId reqId, RemoteLandmarkStoreInfo* pInfo, result r, const String& errorCode, const String& errorMsg) {}
*	    void OnLandmarkUpdated(RequestId reqId, Landmark* pLandmark, result r, const String& errorCode, const String& errorMsg) {}
*	    void OnLandmarkReceived(RequestId reqId, Landmark* pLandmark, result r, const String& errorCode, const String& errorMsg) {}
*	    void OnLandmarkCountReceived(RequestId reqId, int count, result r, const String& errorCode, const String& errorMsg) {}
*	    void OnCategoriesReceivedN(RequestId reqId, IList* pCategoryList, result r, const String& errorCode, const String& errorMsg) {}
*   };
*
*   void
*   MyClass::CreateRemoteLandmarkStore(void) {
*   	result			r = E_SUCCESS;
*	    RequestId		reqId;
*    	String			storeName(L"myStore");
*    	String			extraInfo(L"Travel Notes");
*
*	    // 1. Creates a remote landmark store.
*	    // Note that a named landmark store is unique in the bada Server. 
*	    // The application must use a unique name to avoid the conflicts arising from duplicate names. 
*	    // Creating a landmark store fails if the name is already in use. 
*	    // To ensure uniqueness, you can add an appropriate postfix to the name.
*    	r = RemoteLandmarkStore::CreateLandmarkStore(storeName, extraInfo, *this, reqId);
*	    if (IsFailed(r)) {
*		    AppLog("Failed to CreateLandmarkStore - %s.", GetErrorMessage(r));
*    	}
*    }
*
*   void
*   MyClass::AddLandmarkToRemoteLandmarkStore(void) {
*	    result			r = E_SUCCESS;
*    	RequestId 		reqId;
*    	String			storeName(L"myStore");
*    	Landmark		museum(L"Museum of Art");
*
*    	// 1. Constructs the instance of the remote landmark store.
*    	RemoteLandmarkStore	myStore(storeName, *this);
*
*    	// 2. Adds a landmark to the landmark store, associating it with the global category SIGHTSEEING.
*    	r = myStore.AddLandmark(museum, &SIGHTSEEING, reqId);
*    	if (IsFailed(r)) {
*    		AppLog("Failed to AddLandmark - %s.", GetErrorMessage(r));
*    	}
*   }
*
*   void 
*   MyClass::SearchLandmarksFromRemoteLandmarkStore(void) {
*	    result			r = E_SUCCESS;
*    	RequestId 		reqId;
*    	String			storeName(L"myStore");
*
*    	// 1. Constructs the instance of the remote landmark store.
*    	RemoteLandmarkStore	myStore(storeName, *this);
*
*    	// 2. Searches landmarks categorized by the global category SIGHTSEEING.
*    	r = myStore.SearchLandmarks(&SIGHTSEEING, null, null, reqId);
*    	if (IsFailed(r)) {
*    		AppLog("Failed to SearchLandmarks - %s.", GetErrorMessage(r));
*    	}
*   }
*
*   void
*   MyClass::DeleteRemoteLandmarkStore(void) {
*	    result			r = E_SUCCESS;
*    	RequestId		reqId;
*    	String			storeName(L"myStore");
*
*    	// 1. Deletes the remote landmark store.
*    	r = RemoteLandmarkStore::DeleteLandmarkStore(storeName, *this, reqId);
*    	if (IsFailed(r)) {
*    		AppLog("Failed to DeleteLandmarkStore - %s.", GetErrorMessage(r));
*    	}
*   }
*
* @endcode
* @{
*/
class _EXPORT_LOCATION_ RemoteLandmarkStore:
	public Osp::Base::Object {

// Lifecycle
public:
	/**
	* Initializes this instance of %RemoteLandmarkStore with the specified name and associates it with the listener. @n
	*
	* An application should ensure that the specified landmark store name exists on the server. Even if the landmark store does not exist, this method 
	* creates and returns an instance of %RemoteLandmarkStore. Note that an existing landmark store can also be deleted by others at any time. @n
	*
	* If the @c storeName parameter contains whitespace, this method uses the trimmed result.
    *
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
    * @since 			1.0
    * @compatibility 	This method has compatibility issues with different bada API versions. @n 
    *                   For more information, see issues in version @ref CompRemoteLandmarkStoreRemoteLandmarkStorePage "1.2" and @ref CompRemoteLandmarkStoreRemoteLandmarkStore2Page "2.0".
    *
	* @param[in]	storeName	The name of the landmark store
	* @param[in]	listener	The listener to receive the events associated with the remote landmark store during the life cycle of this instance
	*/
	RemoteLandmarkStore(const Osp::Base::String& storeName, const IRemoteLandmarkStoreListener& listener);

	/**
	* This is the destructor for this class.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*/
	virtual	~RemoteLandmarkStore(void);

// Lifecycle
private:
	// no implementation. force to private
	RemoteLandmarkStore(const RemoteLandmarkStore& value);
	RemoteLandmarkStore& operator=(const RemoteLandmarkStore& rhs);

// Operations - Osp::Locations::RemoteLandmarkStore
public:

	/**
	* Creates a new landmark store in the server-side storage. @n
	*
	* A landmark store with the specified name is created with extra information that can be utilized by an application as a field for application-specific 
	* information. The landmark store created on the server can be accessed by the creator application running on any device. @n
	*
	* A newly created landmark store does not contain any landmark. @n
	*
	* If the @c storeName parameter contains whitespace, this method uses the trimmed result. @n
	*
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarkStoreCreated() method once the request to 
	* the remote landmark store is completed.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in]	storeName			The name of the landmark store to be created
	* @param[in]	extraInfo			The extra information for the store
	* @param[in]	listener			The event listener
	* @param[out]	reqId				The ID of the request sent to the server
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG 		A specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
    * @remarks      The bada Server limits the maximum length of a landmark store name up to 64 characters ands the maximum length of an extra information up 
	*				to 100 characters. A named landmark store is unique in the bada Server. If the named landmark store already exists, the request fails. @n
	*				It is recommended that the application uses a unique name to avoid a name conflict by adding some postfix to the name. @n
	*				The remote landmark store supports Unicode characters for the store name field @b since: @b 2.0.
	*				In the bada API versions prior to 2.0, some Unicode characters are not supported for the store name field. A store of those names is 
	*				created but it cannot be used.
	*				See the compatibility of the RemoteLandmarkStore() and DeleteLandmarkStore() methods for more details.
    * 
	*/
	static result CreateLandmarkStore(const Osp::Base::String& storeName, const Osp::Base::String& extraInfo, const IRemoteLandmarkStoreListener& listener, RequestId& reqId);

	/**
	* Deletes a landmark store that is stored on the server side. @n
	* All the landmarks and categories defined in the specified landmark store are permanently removed. @n
	* If the @c storeName parameter contains whitespace, this method uses the trimmed result. @n
	*
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarkStoreDeleted() method once the request to 
	* the remote landmark store is completed.
    *
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
    * @since 			1.0
    * @compatibility 	This method has compatibility issues with different bada API versions. @n 
    *                   For more information, see issues in version @ref CompRemoteLandmarkStoreDeleteLandmarkStorePage "1.2" and @ref CompRemoteLandmarkStoreDeleteLandmarkStore2Page "2.0".
	*
	* @privlevel		NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in]	storeName			The name of the landmark store to be deleted
	* @param[in]	listener			The event listener
	* @param[out]	reqId				The ID of the request sent to the server
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG 		A specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
    * @remarks      Only the creator of a landmark store can delete the landmark store. 
	*/
	static result DeleteLandmarkStore(const Osp::Base::String& storeName, const IRemoteLandmarkStoreListener& listener, RequestId& reqId);

	/**
	* Searches the remote landmark stores of the user created type. @n	
	* The creator and/or extra information can be specified to match the remote landmark stores of the creator and/or extra information. @n
	* The searched result is divided into a number of fixed-length blocks. A page denotes a block that has a number order starting from @c 1.
	* The value of the @c countPerPage parameter should be between #LOC_MIN_COUNT_PER_PAGE and #LOC_MAX_COUNT_PER_PAGE. If the value of the @c pageNo or 
	* @c countPerPage parameter is less than @c 1, this method returns E_INVALID_ARG. @n
	*
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarkStoreNamesReceivedN() method once the 
	* request to the remote landmark store is completed.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in]	pCreatorId			The user ID of the creator, or @n
	*									@c null to search the remote landmark store created by anyone
	* @param[in]	pExtraInfo			The extra information to match, or @n
	*									@c null to search the remote landmark store having any extra information
	* @param[in]	listener			The event listener
	* @param[out]	reqId				The ID of the request sent to the server
	* @param[in]	pageNo				The page number
	* @param[in]	countPerPage		The number of items in a page
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG 		The specified @c pageNo or @c countPerPage is less than @c 1.
	* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	*/
	static	result	SearchLandmarkStoreNames(const UserId* pCreatorId, const Osp::Base::String* pExtraInfo, const IRemoteLandmarkStoreListener& listener, RequestId& reqId, int pageNo=1, int countPerPage=LOC_DEFAULT_COUNT_PER_PAGE);

	/**
	* Searches the remote landmark stores of the content-provider-published type. @n
	* The content provider may be specified to search the remote landmark stores published only by the provider. @n
	* The searched result is divided into a number of fixed-length blocks. A page denotes a block that has a number order starting from @c 1.
	* The value of the @c countPerPage parameter should be between #LOC_MIN_COUNT_PER_PAGE and #LOC_MAX_COUNT_PER_PAGE. If the value of the @c pageNo or 
	* @c countPerPage parameter is less than @c 1, this method returns E_INVALID_ARG. @n
	*
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarkStoreNamesReceivedN() method once the 
	* request to the remote landmark store is completed.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in]	pProviderName		The name of the content provider, or @n
	*									@c null to search the remote landmark store published by anyone
	* @param[in]	listener			The event listener
	* @param[out]	reqId				The ID of the request sent to the server
	* @param[in]	pageNo				The page number
	* @param[in]	countPerPage		The number of items in a page
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified @c pageNo or @c countPerPage is less than @c 1.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*/
	static	result	SearchLandmarkStoreNames(const Osp::Base::String* pProviderName, const IRemoteLandmarkStoreListener& listener, RequestId& reqId, int pageNo=1, int countPerPage=LOC_DEFAULT_COUNT_PER_PAGE);

	/**
	* Adds a landmark to the specified category in the landmark store. @n
	* If a textual field inside the landmark object (such as the name, author, and description of the landmark) or all the fields in AddressInfo are set to a 
	* value that is longer than the length supported by the landmark store, this method can fail. @n
	*
	* If the %Landmark object (passed as a parameter) is an instance that belongs to this landmark store, the same %Landmark instance is added to the 
	* specified category, in addition to the category/categories that it already belongs to. This method fails if the landmark belongs to this store, but has 
	* @c null or an empty category. If the landmark is deleted after it is obtained from the landmark store, it can be added again when this method is called. @n
	*
	* If the %Landmark object (passed as a parameter) is an instance that is initially constructed by the application using the constructor, or an instance 
	* that belongs to a different landmark store, a new landmark is created in this landmark store. It belongs initially to only the category specified in 
	* the category parameter.
	*
	* If a landmark is to be added to more than one category, the additions must be done one at a time with this method. Adding a landmark to any of the 
	* global landmark categories must be done using the constant global category names defined in this class. @n
	*
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarkAdded() method once the request to the 
	* remote landmark store is completed. The IRemoteLandmarkStoreListener::OnLandmarkAdded() gives the application a landmark if the request is made 
	* successfully. Even though the value of the landmark is the same as the landmark passed to this method, some parts of the information inside the 
	* landmark are updated. For example, the timestamp and relationship with the store. The application must use the updated landmark for subsequent requests.
    *
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
    * @since 			1.0
    * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
    *                	For more information, see @ref CompRemoteLandmarkStoreAddLandmarkPage "here".
	* @privlevel		NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return			An error code
	* @param[in]		landmark			The instance of %Landmark to be added
	* @param[in]		pCategory			The category where %Landmark is added @n
	*										Can be @c null or an empty string.
	* @param[out]		reqId				The ID of the request sent to the server
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG 		The specified @c landmark already exists in the landmark store and @c pCategory is @c null.
	* @exception		E_OUT_OF_MEMORY 	The memory is insufficient.
	* @exception		E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
    * @remarks      	The bada Server limits the maximum length of the name and author of a landmark to @c 32 characters, the maximum length of the 
	*					description of a landmark to @c 100 characters, the maximum number of items in the extra information of a landmark to @c 5, the 
	*					maximum length of each extra information to @c 32 characters, the maximum number of items in the URL of a landmark to @c 5,the 
	*					maximum length of each URL and each description to @c 100 characters, the maximum number of vertices of the geographic area of a 
	*					landmark to @c 20 for the polygon shape, and the maximum length of a landmark category up to @c 32 characters. @n
	* 					A landmark can be added to maximum 10 different categories.
	*/
	result	AddLandmark(const Landmark& landmark, const Osp::Base::String* pCategory, RequestId& reqId);

	/**
	* Changes the extra information of the landmark store. @n
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarkStoreExtraInfoChanged() method once the 
	* request to the remote landmark store is completed.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in]	extraInfo				The extra information that is to be changed
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception	E_SUCCESS 				The method is successful.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_SYSTEM  				A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED  	The application does not have the privilege to call this method.
    * @remarks      The bada Server limits the maximum length of extra information up to @c 100 characters.
	*/
	result	ChangeExtraInfo(const Osp::Base::String& extraInfo, RequestId& reqId);

	/**
	* Deletes a landmark from this landmark store. @n
	* Removes the specified landmark from all categories, and deletes the information from this landmark store. @n
	*
	* The Landmark instance (passed as a parameter) must be an instance that belongs to this landmark store. Note that E_LANDMARK is returned if the 
	* %Landmark instance does not belong to this landmark store, and "not belonging to the landmark store" is different from "not being stored currently in 
	* this landmark store". @n
	*
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarkDeleted() method once the request to the 
	* remote landmark store is completed.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in]	landmark				The instance of %Landmark
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_LANDMARK 				The landmark does not belong to this landmark store.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED  	The application does not have the privilege to call this method.
    * @remarks      Only the creator of a landmark can delete the landmark. 
	*/
	result	DeleteLandmark(const Landmark& landmark, RequestId& reqId);

	/**
	* Gets the category names that are defined in the landmark store. @n
	* The returned list contains the global landmark categories, at least as the constants defined in this namespace. @n
    *
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnCategoriesReceivedN() method once the request to 
	* the remote landmark store is completed.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 			1.0
    * @compatibility    This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
    *                   For more information, see @ref CompRemoteLandmarkStoreGetAllCategoriesPage "here".
    * 
	* @privlevel		NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return			An error code
	* @param[out]		reqId				The ID of the request sent to the server
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_OUT_OF_MEMORY 	The memory is insufficient.
	* @exception		E_SYSTEM  			A system error has occurred.
	* @exception		E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	*/
	result	GetAllCategories(RequestId& reqId) const;

	/**
	* Gets the landmark categories for the specified landmark. @n
	* E_LANDMARK is reported if the specified landmark does not belong to this landmark store. @n
	*
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnCategoriesReceivedN() method once the request to 
	* the remote landmark store is completed.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in]	landmark				The landmark whose categories are queried
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_LANDMARK 				The landmark does not belong to this landmark store.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED  	The application does not have the privilege to call this method.
	*/
	result	GetCategoriesOfLandmark(const Landmark& landmark, RequestId& reqId) const;

	/**
	* Gets information about the landmark store. @n
	*
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarkStoreInfoReceived() method once the 
	* request to the remote landmark store is completed.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED  	The application does not have the privilege to call this method.
	*/
	result	GetInfo(RequestId& reqId) const;

	/**
	* Gets all the landmarks stored in the store. @n
	* A landmark property selector takes only those properties of the landmark that it is interested in. Only the selected properties are filled in the 
	* result landmarks. Passing the @c null value as a selector gives all properties of landmarks. @n
    *
	* The searched result is divided into a number of fixed-length blocks. A page denotes a block that has a number order starting from @c 1.
	* The value of the @c countPerPage parameter should be a value between #LOC_MIN_COUNT_PER_PAGE and #LOC_MAX_COUNT_PER_PAGE. If the value of @c pageNo or 
	* @c countPerPage is less than @c 1, this method returns E_INVALID_ARG.
	*
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarksReceivedN() method once the request to 
	* the remote landmark store is completed.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in]	pSelector				The landmark property selector @n
	*										Can be @c null.
	* @param[out]	reqId					The ID of the request sent to the server
	* @param[in]	pageNo					The page number
	* @param[in]	countPerPage			The number of items in a page
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG 			The specified @c pageNo or @c countPerPage is less than @c 1.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED  	The application does not have the privilege to call this method.
	*/
	result	GetAllLandmarks(const LandmarkPropertySelector* pSelector, RequestId& reqId, int pageNo=1, int countPerPage=LOC_DEFAULT_COUNT_PER_PAGE) const;

	/**
	* Gets the landmark for the specified ID. @n
	* The landmark ID is the unique key to access the landmark. @n
	*
	* A landmark property selector takes only those properties of the landmark that it is interested in. Only the selected properties are filled in the 
	* result landmarks. Passing the @c null value as a selector gives all properties of landmarks. @n
	*
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarkReceived() method once the request to the 
	* remote landmark store is completed.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in]	landmarkId				The ID of landmark that is unique in the landmark store
	* @param[in]	pSelector				The landmark property selector @n
	*										Can be @c null.
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG 			The specified @c landmarkId is equal to or less than INVALID_LANDMARK_ID (=-1).
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED  	The application does not have the privilege to call this method.
	*/
	result	GetLandmark(LandmarkId landmarkId, const LandmarkPropertySelector* pSelector, RequestId& reqId) const;

	/**
	* Requests landmarks in the storage where the category and name match the specified parameters. @n
    * The category and name are handled in a case-sensitive manner. The category is matched exactly. However, the landmark names that are equal to or start 
	* with the specified name are also matched.
    * 
	* A landmark property selector takes only those properties of the landmark that it is interested in. Only the selected properties are filled in the 
	* result landmarks. Passing the @c null value as a selector gives all properties of landmarks. @n
	*
	* The searched result is divided into a number of fixed-length blocks. A page denotes a block, that has a number order starting from @c 1.
	* The value of the @c countPerPage parameter should be a value between #LOC_MIN_COUNT_PER_PAGE and #LOC_MAX_COUNT_PER_PAGE. If the value of @c pageNo or 
	* @c countPerPage is less than @c 1, this method returns E_INVALID_ARG.
	*
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarksReceivedN() method once the request to the 
	* remote landmark store is completed.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
 	* @privgroup	REMOTE_LANDMARK
 	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
 	* @return		An error code
	* @param[in]	pCategory			The category of the landmark @n
	*									@c null, or an empty string implies a wild card that matches all the categories.
	* @param[in]	pName				The name of the desired landmark @n
	*									@c null, or an empty string implies a wild card that matches all the names within the category indicated by the 
	*									category parameter.
	* @param[in]	pSelector			The landmark property selector @n
	*									Can be @c null.
	* @param[out]	reqId				The ID of the request sent to the server
	* @param[in]	pageNo				The page number
	* @param[in]	countPerPage		The number of items in a page
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG 		The specified @c pageNo or @c countPerPage is less than @c 1.
	* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	*/
	result	SearchLandmarks(const Osp::Base::String* pCategory, const Osp::Base::String* pName, const LandmarkPropertySelector* pSelector, RequestId& reqId, int pageNo=1, int countPerPage=LOC_DEFAULT_COUNT_PER_PAGE) const;

	/**
	* Gets the landmarks that are within an area defined by a bounding minimum and maximum latitude and longitude and belong to the defined category if 
	* specified. @n
    *
    * The category is handled in a case-sensitive manner and matched exactly with the corresponding field of the landmark. @n
	*
	* The bounds are included in the specified area. If minLongitude <= maxLongitude, this area covers the longitude 
	* range [minLongitude, maxLongitude].  If minLongitude > maxLongitude, this area covers the longitude range
	* [-180.0, maxLongitude] and [minLongitude, 180.0]. For latitude, the area covers the latitude range [minLatitude, maxLatitude]. @n
	*
	* A landmark property selector takes only those properties of the landmark that it is interested in. Only the selected properties are filled in the 
	* result landmarks. Passing the @c null value as a selector gives all the properties of the landmarks. @n
	*
	* The searched result is divided into a number of fixed-length blocks. A page denotes a block that has a number order starting from @c 1.
	* The value of the @c countPerPage parameter should be a value between #LOC_MIN_COUNT_PER_PAGE and #LOC_MAX_COUNT_PER_PAGE. If the value of @c pageNo or 
	* @c countPerPage is less than @c 1, this method returns E_INVALID_ARG. @n
	*
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarksReceivedN() method once the request to 
	* the remote landmark store is completed.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in]	pCategory			The category of the landmark @n
	*									@c null, or an empty string implies a wild card that matches all the categories.
	* @param[in]	minLatitude			The minimum latitude of the area in the range [-90.0, 90.0]
	* @param[in]	maxLatitude			The maximum latitude of the area in the range [minLatitude, 90.0]
	* @param[in]	minLongitude		The minimum longitude of the area in the range [-180.0, 180.0]
	* @param[in]	maxLongitude		The maximum longitude of the area in the range [-180.0, 180.0]
	* @param[in]	pSelector			The landmark property selector @n
	*									Can be @c null.
	* @param[out]	reqId				The ID of the request sent to the server
	* @param[in]	pageNo				The page number
	* @param[in]	countPerPage		The number of items in a page
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG 		Either of the following conditions has occurred: @n
	*									- The specified @c minLongitude or @c maxLongitude is out of range. The valid range is [-180.0, 180.0]. @n
	*								 	- The specified @c minLatitude or @c maxLatitude is out of range. The valid range is [-90.0, 90.0]. @n
	*								 	- The specified @c minLatitude is greater than the @c maxLatitude. @n
	*								 	- The specified @c pageNo or @c countPerPage is less than @c 1.
	* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	*/
	result	SearchLandmarks(const Osp::Base::String* pCategory, double minLatitude, double maxLatitude, double minLongitude, double maxLongitude, const LandmarkPropertySelector* pSelector, RequestId& reqId, int pageNo=1, int countPerPage=LOC_DEFAULT_COUNT_PER_PAGE) const;

	/**
	* Searches for the landmarks that match the specified filter. @n
	* A landmark filter contains several filters that are used for the matching process. Filters that are not set by the application are ignored. Passing the 
	* @c null value as a landmark filter lists all the landmarks in this store. @n
    *
	* Note that only the @ref ADDRESS_FIELD_CITY, @ref ADDRESS_FIELD_POSTAL_CODE, and @ref ADDRESS_FIELD_STREET_NAME fields in an address filter work 
	* currently. If an application wants to perform a query with an address, it may first geocode the address to the coordinates using  
    * @ref Osp::Locations::Services::IGeocodingServiceProvider, and then perform a proximity query for the landmarks around the coordinates. For example, 
	* using a circular geographic area filter with the coordinates as the center. @n
    *
    * If a polygonal geographic area filter is specified, this method uses a bounding box of that area. @n
	*
	* A landmark property selector takes only those properties of the landmark that it is interested in. Only the selected properties are filled in the 
	* result landmarks. Passing the @c null value as a selector gives all the properties of the landmarks. @n
	*
	* The @c sortBy parameter indicates the field in the %Landmark instance that is used to sort the results. In addition to this, sorting may be done based 
	* on the distance of the landmark from the coordinates specified as parameters. Since the only mandatory field for a landmark is the name, the result set 
	* may contain landmarks that do not have the sort field. @n
	*
	* The searched result is divided into a number of fixed-length blocks. A page denotes a block, that has a number order starting from @c 1. The value of 
	* the @c countPerPage parameter should be a value between #LOC_MIN_COUNT_PER_PAGE and #LOC_MAX_COUNT_PER_PAGE. If the value of @c pageNo or @c 
	* countPerPage is less than @c 1, this method returns E_INVALID_ARG. @n
	*
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarksReceivedN() method once the request to 
	* the remote landmark store is completed.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in]	pFilter				The landmark filter @n
	*									Can be @c null.
	* @param[in]	pSelector			The landmark property selector @n
	*									Can be @c null.
	* @param[in]	pDistFrom			The coordinates from which the distance is calculated if the sorting is done based on that @n
	*									Can be @c null.
	* @param[in]	sortOrder			The order in which the sorting is done
	* @param[in]	sortBy				The field used to sort the result set
	* @param[out]	reqId				The ID of the request sent to the server
	* @param[in]	pageNo				The page number
	* @param[in]	countPerPage		The number of items in a page
	* @exception	E_SUCCESS	    	The method is successful.
	* @exception	E_INVALID_ARG 		Either of the following conditions has occurred: @n
	*									- The specified @c sortBy is SORT_BY_DISTANCE when @c distFrom is @c null. @n
	*									- The specified @c sortOrder or @c sortBy is invalid. @n
	*									- The specified @c pageNo or @c countPerPage is less than @c 1.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
    * @remarks      The bada Server supports the string match option @ref Osp::Base::STRING_MATCH_CRITERIA_EXACT and 
    *               @ref Osp::Base::STRING_MATCH_CRITERIA_START_WITH set in the filter @b since: @b 2.0.
    *               But match options @ref Osp::Base::STRING_MATCH_CRITERIA_CONTAIN and @ref Osp::Base::STRING_MATCH_CRITERIA_WILDCARD are not supported.
	*/
	result	SearchLandmarks(const LandmarkFilter* pFilter, const LandmarkPropertySelector* pSelector, const Coordinates* pDistFrom, Osp::Base::SortOrder sortOrder, SortBy sortBy, RequestId& reqId, int pageNo=1, int countPerPage=LOC_DEFAULT_COUNT_PER_PAGE) const;

	/**
	* Gets the name of this landmark store. @n
	* The name of the landmark is the same as the landmark used in the constructor.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return	The name of the landmark store
	*/
	Osp::Base::String	GetName(void) const;

	/**
	* Gets the number of landmarks in the specified category. @n
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarkCountReceived() method once the request to 
	* the remote landmark store is completed.
    *
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
    * @since 			1.0
    * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n 
    *               	For more information, see @ref CompRemoteLandmarkStoreGetNumberOfLandmarksPage "here".
	*
	* @privlevel		NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return			An error code
	* @param[in]		pCategory				The landmark category from which the landmark number is requested, @n
	*											else @c null if the total number of landmarks in the landmark store is requested
	* @param[out]		reqId					The ID of the request sent to the server
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception		E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	*/
	result	GetNumberOfLandmarks(const Osp::Base::String* pCategory, RequestId& reqId) const;

	/**
	* Removes the specified landmark from all the categories it is associated with. @n
	* The %Landmark instance (passed as a parameter) must be an instance that belongs to this landmark store. Note that E_LANDMARK is returned if the 
	* %Landmark instance does not belong to this landmark store, and "not belonging to the landmark store" is different from "not being stored currently in 
	* this landmark store". @n
	*
	* The landmark is removed from the categories, but the landmark still belongs to the store. The landmark can still be obtained from the store by passing 
	* the @c null value as a category to query methods. @n
	*
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarkUpdated() method once the request to the 
	* remote landmark store is completed.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in]	landmark				The landmark to be removed from all categories
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_LANDMARK 				The landmark does not belong to this landmark store.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED  	The application does not have the privilege to call this method.
	*/
	result	RemoveLandmarkFromAllCategories(const Landmark& landmark, RequestId& reqId);

	/**
	* Removes the specified landmark from the specified category. @n
	* To remove the named landmark from a global landmark category, the constant defined for that global landmark category must be used. @n
	*
	* The %Landmark (passed as a parameter) must be an instance that belongs to this landmark store. Note that E_LANDMARK is returned if the %Landmark 
	* instance does not belong to this landmark store, and "not belonging to the landmark store" is different from "not being stored currently in this 
	* landmark store". @n
	*
	* The landmark is removed from the specified category, but the landmark information is retained in the store. If the landmark no longer belongs to any 
	* category, it can still be obtained from the store by passing the @c null value as the category to query methods.
	*
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarkUpdated() method once the request to the 
	* remote landmark store is completed.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @privlevel	NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return		An error code
	* @param[in]	landmark				The landmark to be removed
	* @param[in]	category				The category from which it is removed
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_LANDMARK 				The landmark does not belong to this landmark store.
	* @exception	E_INVALID_ARG 			The specified @c category is an empty string.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	*/
	result	RemoveLandmarkFromCategory(const Landmark& landmark, const Osp::Base::String& category, RequestId& reqId);

	/**
	* Updates the information about a landmark. @n
	* This method only updates the information about a landmark, and does not modify the categories that the landmark belongs to. @n
	*
	* The %Landmark instance (passed as a parameter) must be an instance that belongs to this landmark store. It cannot be used to add a new landmark to the 
	* store. @n
	*
	* If this method returns E_SUCCESS, the application is notified via the IRemoteLandmarkStoreListener::OnLandmarkUpdated() method once the request to the 
	* remote landmark store is completed. The IRemoteLandmarkStoreListener::OnLandmarkUpdated() gives the application a landmark if the request is made 
	* successfully. The value of the landmark is the same as the landmark that passes to this method (except the timestamp). The application may use the 
	* updated landmark for subsequent requests.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since 			1.0
    * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
    *					For more information, see @ref CompRemoteLandmarkStoreUpdateLandmarkPage "here".
    *
	* @privlevel		NORMAL
	* @privgroup	REMOTE_LANDMARK
	*
	* @pre			The user should be authenticated. @n 
	*						For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	* 
	* @return			An error code
	* @param[in]		landmark			The landmark to be updated
	* @param[out]		reqId				The ID of the request sent to the server
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_LANDMARK			The landmark does not belong to this landmark store.
	* @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
    * @remarks			See the remarks of the AddLandmark() method for the bada Server's restriction. @n
    * 					Only the creator of a landmark can update the landmark. 
	*/
	result	UpdateLandmark(const Landmark& landmark, RequestId& reqId);

// internal util
private:
	result	SearchLandmarks(const LandmarkFilter* pFilter, const LandmarkPropertySelector* pSelector, const Coordinates* pDistFrom, int pageNo, int countPerPage, Osp::Base::SortOrder sortOrder, SortBy sortBy, RequestId& reqId) const;

private:
	Osp::Base::String	__storeName;
    _IRemoteLandmarkStore*  __pIRemoteLS;

private:
	friend class RemoteLandmarkStoreEx;
	class RemoteLandmarkStoreEx* __pRemoteLandmarkStoreEx;

/**
 * @page	CompRemoteLandmarkStoreGetAllCategoriesPage		Compatibility for GetAllCategories()
 *
 * @section	CompRemoteLandmarkStoreGetAllCategoriesPageIssueSection		Issues
 * Implementation of this method in bada API versions prior to 1.1 has the following issue: @n 
 * If the landmark store contains landmarks that are added to global landmark categories, the names of the associated global categories appear twice in 
 * the result list.
 *
 * @section	CompRemoteLandmarkStoreGetAllCategoriesPageSolution		Resolutions
 * The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1 or above. @n 
 *
 * @par When working with bada API versions prior to 1.1:
 * An application should check duplicate items in the category list. @n
 */

/** 
* @page	CompRemoteLandmarkStoreRemoteLandmarkStorePage	Compatibility for RemoteLandmarkStore()
*
* @section	CompRemoteLandmarkStoreRemoteLandmarkStoreIssueSection	Issues 
* Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
* If the name of the landmark store contains characters other than English alphabets, digits, hyphen("-"), period("."), 
* underscore("_"), and tilde("~") and an instance of %RemoteLandmarkStore is constructed with the specified name, the subsequent requests on the 
* %RemoteLandmarkStore fail and the E_SERVER exception is thrown, which is notified via the methods of the listener.
* 
* @section	CompRemoteLandmarkStoreRemoteLandmarkStoreSolutionSection	Resolutions 
* The issue mentioned above is resolved in bada API version 1.2 and it is recommended to use bada API version 1.2 or above. @n
*
* @par When working with bada API versions prior to 1.2:
* For the landmark store name that contains characters other than English alphabets, digits, hyphen("-"), period("."), 
* underscore("_"), and tilde("~"), an application should use the percent-encoded name to get the right response from the RESTful service of the server.
*/

/** 
* @page	CompRemoteLandmarkStoreRemoteLandmarkStore2Page		Compatibility for RemoteLandmarkStore()
*
* @section	CompRemoteLandmarkStoreRemoteLandmarkStore2IssueSection		Issues 
* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
* If the name of the landmark store contains slash('/') or semicolon(';') characters and an instance of the %RemoteLandmarkStore is constructed 
* with the specified name, the subsequent requests on the %RemoteLandmarkStore fail and the E_SERVER exception is thrown, which is notified via the 
* methods of the listener.
* 
* @section	CompRemoteLandmarkStoreRemoteLandmarkStore2SolutionSection	Resolutions 
* The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
*
* @par When working with bada API versions prior to 2.0:
* An application should not use slash('/') or semicolon(';') characters in the store name.
*/

/** 
* @page	CompRemoteLandmarkStoreDeleteLandmarkStorePage	Compatibility for DeleteLandmarkStore()
*
* @section	CompRemoteLandmarkStoreDeleteLandmarkStoreIssueSection	Issues 
* Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
* If the name of the landmark store contains characters other than English alphabets, digits, hyphen("-"), period("."), 
* underscore("_"), and tilde("~"), a request for deletion of the landmark store fails and the E_SERVER exception is thrown, which is notified via the 
* methods of the listener.
* 
* @section	CompRemoteLandmarkStoreDeleteLandmarkStoreSolutionSection	Resolutions 
* The issue mentioned above is resolved in bada API version 1.2 and it is recommended to use bada API version 1.2 or above. @n
*
* @par When working with bada API versions prior to 1.2:
* For the landmark store name that contains characters other than English alphabets, digits, hyphen("-"), period("."), 
* underscore("_"), and tilde("~"), an application should use the percent-encoded name to get the right response from the RESTful service of the server.
*/

/** 
* @page	CompRemoteLandmarkStoreDeleteLandmarkStore2Page		Compatibility for DeleteLandmarkStore()
*
* @section	CompRemoteLandmarkStoreDeleteLandmarkStore2IssueSection	Issues 
* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
* If the name of the landmark store contains slash('/') or semicolon(';') characters, a request to delete the landmark store fails and the E_SERVER 
* exception is thrown, which is notified via the methods of the listener.
* 
* @section	CompRemoteLandmarkStoreDeleteLandmarkStore2SolutionSection	Resolutions 
* The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
*
* @par When working with bada API versions prior to 2.0:
* An application should not use slash('/') or semicolon(';') characters in the store name.
*/

/** 
* @page	CompRemoteLandmarkStoreGetNumberOfLandmarksPage		Compatibility for GetNumberOfLandmarks()
*
* @section	CompRemoteLandmarkStoreGetNumberOfLandmarksIssueSection		Issues 
* Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
* If the name of the category from which the landmark number is requested contains characters other than English alphabets, digits, hyphen("-"), 
* period("."), underscore("_"), and tilde("~"), the request fails and the E_SERVER exception is thrown, which is notified via the methods of the listener.
* 
* @section	CompRemoteLandmarkStoreGetNumberOfLandmarkSolutionSection	Resolutions 
* The issue mentioned above is resolved in bada API version 1.2 and it is recommended to use bada API version 1.2 or above. @n
*
* @par When working with bada API versions prior to 1.2:
* For the category name that contains characters other than English alphabets, digits, hyphen("-"), period("."), underscore("_"), and tilde("~"), an 
* application should use the percent-encoded name to get the right response from the RESTful service of the server.
*/

/** 
* @page	CompRemoteLandmarkStoreAddLandmarkPage	Compatibility for AddLandmark()
* @section	CompRemoteLandmarkStoreAddLandmarkIssueSection	Issues 
* Implementation of this method in bada API versions prior to 2.0 has the following issues: @n 
* -# If a text inside the landmark or category name field consists of only whitespace characters, the field is ignored. @n
* -# If a text inside the landmark or category name field contains the carriage return character, it is removed from the field. @n
* -# The horizontal accuracy of the qualified coordinates of a landmark is ignored.
* 
* @section	CompRemoteLandmarkStoreAddLandmarkSolutionSection	Resolutions 
* The issues mentioned above are resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
*
* @par When working with bada API versions prior to 2.0:
* For a text in the landmark or category name field, an application should not use strings that contain only whitespaces or carriage return characters.
* An application should not use the horizontal accuracy of the qualified coordinates of a landmark with a purpose of keeping it in the remote landmark store.
*/

/** 
* @page	CompRemoteLandmarkStoreUpdateLandmarkPage	Compatibility for UpdateLandmark()
* @section	CompRemoteLandmarkStoreUpdateLandmarkIssueSection	Issues 
* Implementation of this method in bada API versions prior to 2.0 has the following issues: @n 
* -# If a text inside the landmark or category name field consists of only whitespace characters, the field is ignored. @n
* -# If a text inside the landmark or category name field contains the carriage return character, it is removed from the field. @n
* -# The horizontal accuracy of the qualified coordinates of a landmark is ignored.
* 
* @section	CompRemoteLandmarkStoreUpdateLandmarkSolutionSection	Resolutions 
* The issues mentioned above are resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
*
* @par When working with bada API versions prior to 2.0:
* For a text in the landmark or category name field, an application should not use strings that contain only whitespaces or carriage return characters.
* An application should not use the horizontal accuracy of the qualified coordinates of a landmark with a purpose of keeping it in the remote landmark store.
*/

};	// class RemoteLandmarkStore
/**
 * @}
 */

} }	// Osp::Location



#endif	// _FLOC_REMOTE_LANDMARK_STORE_H_
