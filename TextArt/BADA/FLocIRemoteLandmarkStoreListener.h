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
 * @file		FLocIRemoteLandmarkStoreListener.h 
 * @brief		This is the header file for the %IRemoteLandmarkStoreListener interface.
 *
 * This header file contains the declarations of the %IRemoteLandmarkStoreListener interface.
 */

#ifndef _FLOC_IREMOTE_LANDMARK_STORE_LISTENER_H_
#define _FLOC_IREMOTE_LANDMARK_STORE_LISTENER_H_

#include "FLocationConfig.h"
#include "FBaseColIList.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Locations { 

/**
* @interface	IRemoteLandmarkStoreListener
* @brief		This interface represents a listener that receives the events associated with the RemoteLandmarkStore class.
* @deprecated   This interface is deprecated due to the operation policy of the bada Server.
* @since		1.0
* 
* The %IRemoteLandmarkStoreListener interface represents a listener that receives the events associated with the %RemoteLandmarkStore class.
* Applications can implement this interface and pass it in the constructors of the %RemoteLandmarkStore class to be notified when the 
* request for the remote landmark store is completed.
*
*/
class	_EXPORT_LOCATION_	IRemoteLandmarkStoreListener
	: public Osp::Base::Runtime::IEventListener{

// Lifecycle
public:
    /**
     * This is the destructor for this class.
     *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
     * @since   1.0
     */
    virtual ~IRemoteLandmarkStoreListener(void);

public:

	/**
	* Called when the RemoteLandmarkStore::CreateLandmarkStore() method is completed. @n 
	* 
	* If the request is made successfully, this method is called with the E_SUCCESS result. Otherwise this method is called with an error code.
	* 
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId				The ID of the request sent to the server
	* @param[in]	r					The result of the request @n
	*									The result can be one of the exception codes mentioned below.
	* @param[in]	errorCode			The error code
	* @param[in]	errorMsg			The error message
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_NETWORK_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED	The response data from the server cannot be parsed.
	* @exception	E_SERVER			The request to the server has failed. Check @c errorCode and @c errorMsg for details.
	* @see			Osp::Locations::RemoteLandmarkStore, RemoteLandmarkStore::CreateLandmarkStore()
	*/
	virtual	void	OnLandmarkStoreCreated(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the RemoteLandmarkStore::DeleteLandmarkStore() method is completed. @n
	* 
	* If the request is made successfully, this method is called with the E_SUCCESS result. Otherwise this method is called with an error code.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request sent to the server
	* @param[in]	r						The result of the request @n 
	*										The result can be one of the exception codes mentioned below.
	* @param[in]	errorCode				The error code
	* @param[in]	errorMsg				The error message
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 		The network connection has failed.
	* @exception	E_SERVER				The request to the server has failed. Check @c errorCode and @c errorMsg for details.
	* @see			Osp::Locations::RemoteLandmarkStore, RemoteLandmarkStore::DeleteLandmarkStore()
	*/
	virtual	void	OnLandmarkStoreDeleted(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the RemoteLandmarkStore::SearchLandmarkStoreNames() method is completed. @n
	* 
	* If the request is made successfully, this method is called with the E_SUCCESS result and the names of the remote landmark store that match
	* the request criteria. Otherwise this method is called with an error code.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId				The ID of the request sent to the server
	* @param[in]	pResults			A list containing the names of the remote landmark stores as strings, @n
	*									else @c null if no matching landmark stores are found
	* @param[in]	pageNo				The page number
	* @param[in]	countPerPage		The number of items on a page
	* @param[in]	totalPageCount		The total number of pages
	* @param[in]	totalCount			The total number of items
	* @param[in]	r					The result of the request @n
	*									The result can be one of the exception codes mentioned below.
	* @param[in]	errorCode			The error code
	* @param[in]	errorMsg			The error message
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_PARSING_FAILED	The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 	The network connection has failed.
	* @exception	E_SERVER			The request to the server has failed. Check @c errorCode and @c errorMsg for details.
	* @remarks		The result list must be deleted by the application.
	* @see			Osp::Locations::RemoteLandmarkStore, RemoteLandmarkStore::SearchLandmarkStoreNames()
	*/
	virtual void	OnLandmarkStoreNamesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pResults, int pageNo, int countPerPage, int totalPageCount, int totalCount, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the RemoteLandmarkStore::AddLandmark() method is completed. @n
	* 
	* If the request is made successfully, this method is called with the E_SUCCESS result and the newly added landmark that belongs to the remote landmark 
	* store. Otherwise this method is called with an error code and @c null for @c pLandmark.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId				The ID of the request sent to the server
	* @param[in]	pLandmark			The new landmark added to the remote landmark store, @n
	*									else @c null if the request to add has failed
	* @param[in]	r					The result of the request @n 
	*									The result can be one of the exception codes mentioned below.
	* @param[in]	errorCode			The error code
	* @param[in]	errorMsg			The error message
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_PARSING_FAILED	The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 	The network connection has failed.
	* @exception	E_SERVER			The request to the server has failed. Check @c errorCode and @c errorMsg for details.
	* @see			Osp::Locations::RemoteLandmarkStore, RemoteLandmarkStore::AddLandmark()
	*/
	virtual void OnLandmarkAdded(RequestId reqId, Landmark* pLandmark, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the RemoteLandmarkStore::ChangeExtraInfo() method is completed. @n
	* 
	* If the request is made successfully, this method is called with the E_SUCCESS result. Otherwise this method is called with an error code.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId				The ID of the request sent to the server
	* @param[in]	r					The result of the request @n
	*									The result can be one of the exception codes mentioned below.
	* @param[in]	errorCode			The error code
	* @param[in]	errorMsg			The error message
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_PARSING_FAILED	The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 	The network connection has failed.
	* @exception	E_SERVER			The request to the server has failed. Check @c errorCode and @c errorMsg for details.
	* @see			Osp::Locations::RemoteLandmarkStore, RemoteLandmarkStore::ChangeExtraInfo()
	*/
	virtual	void	OnLandmarkStoreExtraInfoChanged(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the RemoteLandmarkStore::DeleteLandmark() method is completed. @n
	* 
	* If the request is made successfully, this method is called with the E_SUCCESS result. Otherwise this method is called with an error code.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId				The ID of the request sent to the server
	* @param[in]	r					The result of the request @n
	*									The result can be one of the exception codes mentioned below.
	* @param[in]	errorCode			The error code
	* @param[in]	errorMsg			The error message
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_PARSING_FAILED	The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 	The network connection has failed.
	* @exception	E_SERVER			The request to the server has failed. Check @c errorCode and @c errorMsg for details.
	* @see			Osp::Locations::RemoteLandmarkStore, RemoteLandmarkStore::DeleteLandmark()
	*/
	virtual	void	OnLandmarkDeleted(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the RemoteLandmarkStore::GetInfo() method is completed. @n
	* 
	* If the request is made successfully, this method is called with the E_SUCCESS result and the information requested. Otherwise this method is called 
	* with an error code and @c null for @c pInfo.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId				The ID of the request sent to the server
	* @param[in]	pInfo				The	features of the remote landmark store, such as the created time
	* @param[in]	r					The result of the request @n
	*									The result can be one of the exception codes mentioned below.
	* @param[in]	errorCode			The error code
	* @param[in]	errorMsg			The error message
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_PARSING_FAILED	The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 	The network connection has failed.
	* @exception	E_SERVER			The request to the server has failed. Check @c errorCode and @c errorMsg for details.
	* @see			Osp::Locations::RemoteLandmarkStore, RemoteLandmarkStore::GetInfo()
	*/
	virtual void OnLandmarkStoreInfoReceived(RequestId reqId, RemoteLandmarkStoreInfo* pInfo, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when either the RemoteLandmarkStore::RemoveLandmarkFromAllCategories() method, RemoteLandmarkStore::RemoveLandmarkFromCategory() method, or 
	* the RemoteLandmarkStore::UpdateLandmark() method is completed. @n
	* 
	* If the request is made successfully, this method is called with the E_SUCCESS result and the updated landmark. Otherwise this method is called with an 
	* error code and @c null for @c pLandmark.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId				The ID of the request sent to the server
	* @param[in]	pLandmark			The updated landmark, @n
	*									else @c null if the update request has failed
	* @param[in]	r					The result of the request @n
	*									The result can be one of the exception codes mentioned below.
	* @param[in]	errorCode			The error code
	* @param[in]	errorMsg			The error message
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_PARSING_FAILED	The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 	The network connection has failed.
	* @exception	E_SERVER			The request to the server has failed. Check @c errorCode and @c errorMsg for details.
	* @see			Osp::Locations::RemoteLandmarkStore, RemoteLandmarkStore::RemoveLandmarkFromAllCategories(), 
	*				RemoteLandmarkStore::RemoveLandmarkFromCategory(), RemoteLandmarkStore::UpdateLandmark()
	*/
	virtual void OnLandmarkUpdated(RequestId reqId, Landmark* pLandmark, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the RemoteLandmarkStore::GetLandmark() method is completed. @n
	* 
	* If the request is made successfully, this method is called with the E_SUCCESS result and the landmark of the specified ID. Otherwise this method is 
	* called with an error code.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId				The ID of the request sent to the server
	* @param[in]	pLandmark			The requested landmark, @n
	*									else @c null if the landmark cannot be found
	* @param[in]	r					The result of the request @n
	*									The result can be one of the exception codes mentioned below.
	* @param[in]	errorCode			The error code
	* @param[in]	errorMsg			The error message
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_PARSING_FAILED	The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 	The network connection has failed.
	* @exception	E_SERVER			The request to the server has failed. Check @c errorCode and @c errorMsg for details.
	* @see			Osp::Locations::RemoteLandmarkStore, RemoteLandmarkStore::GetLandmark()
	*/
	virtual void	OnLandmarkReceived(RequestId reqId, Landmark* pLandmark, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the RemoteLandmarkStore::GetAllLandmarks() method or the RemoteLandmarkStore::SearchLandmarks() method is completed. @n
	* 
	* If the request is made successfully, this method is called with the E_SUCCESS result and the landmarks that match the request criteria. Otherwise this 
	* method is called with an error code.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId				The ID of the request sent to the server
	* @param[in]	pResults			A list of the matched landmarks, @n
	*									else @c null if no landmarks matched
	* @param[in]	pageNo				The page number
	* @param[in]	countPerPage		The number of items on a page
	* @param[in]	totalPageCount		The total number of pages
	* @param[in]	totalCount			The total number of items
	* @param[in]	r					The result of the request @n
	*									The result can be one of the exception codes mentioned below.
	* @param[in]	errorCode			The error code
	* @param[in]	errorMsg			The error message
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_PARSING_FAILED	The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 	The network connection has failed.
	* @exception	E_SERVER			The request to the server has failed. Check @c errorCode and @c errorMsg for details.
	* @remarks		The result list must be deleted by the application.
	* @see			Osp::Locations::RemoteLandmarkStore, RemoteLandmarkStore::GetAllLandmarks(), RemoteLandmarkStore::SearchLandmarks()
	*/
	virtual void	OnLandmarksReceivedN(RequestId reqId, Osp::Base::Collection::IList* pResults, int pageNo, int countPerPage, int totalPageCount, int totalCount, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the RemoteLandmarkStore::GetNumberOfLandmarks() method is completed. @n
	*
	* If the request is made successfully, this method is called with the E_SUCCESS result and the number of landmarks. Otherwise this method is called with 
	* an error code and @c -1 for the count.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId				The ID of the request sent to the server
	* @param[in]	count				The number of landmarks
	* @param[in]	r					The result of the request @n
	*									The result can be one of the exception codes mentioned below.
	* @param[in]	errorCode			The error code
	* @param[in]	errorMsg			The error message
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_PARSING_FAILED	The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 	The network connection has failed.
	* @exception	E_SERVER			The request to the server has failed. Check @c errorCode and @c errorMsg for details.
	* @see			Osp::Locations::RemoteLandmarkStore, RemoteLandmarkStore::GetNumberOfLandmarks()
	*/
	virtual	void	OnLandmarkCountReceived(RequestId reqId, int count, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the RemoteLandmarkStore::GetAllCategories() method or the RemoteLandmarkStore::GetCategoriesOfLandmark() method is completed. @n
	*
	* If the request is made successfully, this method is called with the E_SUCCESS result and the list of categories. Otherwise this method is called with an 
	* error code and a null list.
	*
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId				The ID of the request sent to the server
	* @param[in]	pCategoryList		A list of category names as strings, @n
	*									else @c null if there are no categories associated with the landmark or the landmark store
	* @param[in]	r					The result of the request @n
	*									The result can be one of the exception codes mentioned below.
	* @param[in]	errorCode			The error code
	* @param[in]	errorMsg			The error message
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_PARSING_FAILED	The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 	The network connection has failed.
	* @exception	E_SERVER			The request to the server has failed. Check @c errorCode and @c errorMsg for details.
	* @remarks		The category list must be deleted by the application.
	* @see			Osp::Locations::RemoteLandmarkStore, RemoteLandmarkStore::GetAllCategories(), RemoteLandmarkStore::GetCategoriesOfLandmark()
	*/
	virtual	void	OnCategoriesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pCategoryList, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;
};	// class IRemoteLandmarkStoreListener

} }	// Osp::Location

#endif// _FLOC_IREMOTE_LANDMARK_STORE_LISTENER_H_
