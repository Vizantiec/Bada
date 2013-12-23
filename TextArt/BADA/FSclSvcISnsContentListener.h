/* $Change: 1202329 $ */
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
 * @file		FSclSvcISnsContentListener.h
 * @brief		This is the header file for the %ISnsContentListener interface.
 *
 * This header file contains the declarations of the %ISnsContentListener interface.
 */
#ifndef _FSCL_SVC_ISNS_CONTENT_LISTENER_H_
#define _FSCL_SVC_ISNS_CONTENT_LISTENER_H_


#include "FBaseRtIEventListener.h"
#include "FBaseColIList.h"
#include "FBaseColIMap.h"
#include "FSclConfig.h"

#include "FSclSvcSnsPhotoInfo.h"
#include "FSclSvcSnsPagingParam.h"

namespace Osp { namespace Social { namespace Services {

/**
* @interface	ISnsContentListener 
* @brief		This listener interface receives the responses to requests initiated from SnsGateway.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since		1.0
*
* The %ISnsContentListener interface receives the responses to requests initiated from SnsGateway.
*/
class  _EXPORT_SOCIAL_ ISnsContentListener
	: public Osp::Base::Runtime::IEventListener
{
public:

	/**
	* Called when the response to SnsGateway::GetPhotoAlbums() is received from the server.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	reqId					The request ID
	* @param[in]	pAlbumList				The list of albums @n
	*										The list consists of SnsAlbumInfo instances.
	* @param[in]	hasNext					The value indicates whether the next page exists @n
	*                               		Set to @c true if the next page exists, @n
	*										else @c false.
	* @param[in]	pagingParam				The current page number and the desired maximum count on this page
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful.
	* @exception	E_SERVER				An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see  Osp::Social::Services::SnsAlbumInfo
	* @see	Osp::Social::Services::SnsGateway::GetPhotoAlbums()
	*/
	virtual void	OnSnsPhotoAlbumsReceivedN(RequestId reqId, Osp::Base::Collection::IList* pAlbumList,
		bool hasNext, SnsPagingParam& pagingParam, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the response to SnsGateway::GetPhotosInAlbum() is received from the server.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	reqId					The request ID
	* @param[in]	pPhotoList				The list of photos @n
	*										The list consists of SnsPhotoInfo instances.
	* @param[in]	hasNext					The value indicates whether the next page exists @n
	*                               		Set to @c true if the next page exists, @n
	*										else @c false.
	* @param[in]	pagingParam				The current page number and the desired maximum count on this page
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful.
	* @exception	E_SERVER				An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see  Osp::Social::Services::SnsPhotoInfo
	* @see  Osp::Social::Services::SnsGateway::GetPhotosInAlbum()
	*/
	virtual void	OnSnsPhotosInAlbumReceivedN(RequestId reqId, Osp::Base::Collection::IList* pPhotoList,
		bool hasNext, SnsPagingParam& pagingParam, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;
	
	/**
	* Called when the response to SnsGateway::GetPhotosByUser() is received from the server.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	reqId					The request ID
	* @param[in]	pPhotoList				The list of photos @n
	*										The list consists of SnsPhotoInfo instances.
	* @param[in]	hasNext					The value indicates whether the next page exists @n
	*                               		Set to @c true if the next page exists, @n
	*										else @c false
	* @param[in]	pagingParam				The current page number and the desired maximum count on this page
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful.
	* @exception	E_SERVER				An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see	Osp::Social::Services::SnsPhotoInfo
	* @see	Osp::Social::Services::SnsGateway::GetPhotosByUser()
	*/
	virtual void	OnSnsPhotosByUserReceivedN(RequestId reqId, Osp::Base::Collection::IList* pPhotoList,
		bool hasNext, SnsPagingParam& pagingParam, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;
	
	/**
	* Called when the response to SnsGateway::GetPhoto() is received from the server.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	reqId					The request ID
	* @param[in]	pPhoto					The Sns Photo
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful.
	* @exception	E_SERVER				An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	*
	* @see	Osp::Social::Services::SnsPhotoInfo
	* @see	Osp::Social::Services::SnsGateway::GetPhoto()
	*/
	virtual void	OnSnsPhotoReceived(RequestId reqId, Osp::Social::Services::SnsPhotoInfo* pPhoto,
		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;
	
	/**
	* Called when the response to SnsGateway::UploadPhoto() is received from the server. @n
	* This is only for a single uploading request.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	reqId					The ID of the request
	* @param[in]	serviceProvider			The service provider
	* @param[in]	pPhotoId				The photo ID @n
	*										The parameter is set to @c null if the photo upload fails.
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful.
	* @exception	E_SERVER				An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	*
	* @see	Osp::Social::Services::SnsGateway::UploadPhoto()
	*/
	virtual void	OnSnsPhotoUploaded(RequestId reqId, Osp::Base::String& serviceProvider, Osp::Base::String* pPhotoId,
		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

};

};};};

#endif
