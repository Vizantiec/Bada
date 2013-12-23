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
 * @file	FSclSvcSnsGateway.h
 * @brief	This is the header file for the %SnsGateway class.
 *
 * This header file contains the declarations of the %SnsGateway class.
 */
#ifndef _FSCL_SVC_SNS_GATEWAY_H_
#define _FSCL_SVC_SNS_GATEWAY_H_


#include "FSclSvcISnsGatewayListener.h"
#include "FSclSvcISnsContentListener.h"
#include "FSclSvcISnsPeopleListener.h"
#include "FSclSvcISnsActivityListener.h"
#include "FSclSvcISnsPostListener.h"
#include "FSclSvcSnsAuthResult.h"
#include "FSclSvcSnsUploadContentInfo.h"
#include "FSclSvcSnsPagingParam.h"
#include "FSclSvcSnsPostInfo.h"


#include "FBaseString.h"

#include "FSclSvcTypes.h"
#include "FSclSvcSnsTypes.h"

struct ISnsGateway;


namespace Osp { namespace Social { namespace Services {

/**
 * @class		SnsGateway
 * @brief		This class provides the methods to access the information of a %Social Network Service (SNS) gateway.
 * @deprecated	This class is deprecated due to the operation policy of the bada Server.
 * @since		1.0
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Social namespace.
 * @image html social_sns_gateway_using_the_apis_classdiagram.png 
 *
 * An %SnsGateway defines the interfaces to external social networking services.
 * In version 1.0, the supported service providers are Twitter and Facebook, and MySpace.
 *
 * Authentication is needed to access the service providers. See the @c SnsAuthenticator.
 * In version 1.0, the OAuth authentication is available and it is used for Twitter and MySpace. The Facebook Connect authentication is also available.
 * %SnsGateway needs SnsAuthResult which contains the consumer key, consumer secret, token key and token secret as a result of authentication described on 
 * OAuth specification.
 * More information on the OAuth specification can be found at http://www.oauth.net. 
 * The SnsAuthResult can be obtained using Osp::Social::Services::SnsAuthenticator. 
 * After the authentication on the service provider, the SnsGateway::AddAuthResult() method has to be called to successfully call other methods of %SnsGateway.
 * %SnsGateway uses the value of SnsAuthResult to access the user's resource on the specific service provider. @n
 * 
 * The authentication result will be stored in the application folder of the device when SnsGateway::AddAuthResult() is called. @n
 * Therefore, the authentication result need not be added every time the user uses the application. @n
 *
 * When the authentication result is stored, the user information can be accessed without adding the authentication result after creating the instance of 
 * %SnsGateway. @n
 * The session resumes based on the previously added authentication result. @n
 * The session cannot be resumed if the session of the service provider has expired or if the user has revoked the authentication. @n
 * In these cases, you may receive an error message such as "Unauthorized". @n
 * To remove the stored authentication result of a specific service provider, call SnsGateway::RemoveAuthResult().
 * 
 * @remarks	Only one result is stored for one service provider. If you add a new result without removing the previous one, the new result overwrites the 
 *			previous one. @n
 * 
 * <b>In version 1.0, following feature are supported:</b>
 * @n
<table>
<tr><td> Feature	</td>								<td> Twitter </td>		<td> Facebook </td>	<td> MySpace </td></tr>
<tr><td> Get my buddy list	</td>						<td> O(following)</td>	<td> O </td>		<td> O </td></tr>
<tr><td> Get user status text </td>						<td> O </td>			<td> O </td>		<td> O </td></tr>
<tr><td> Set my status text </td>						<td> O </td>			<td> O </td>		<td> O </td></tr>
<tr><td> Get user profile  </td>						<td> O </td>			<td> O </td>		<td> O </td></tr>
<tr><td> Get activities </td>							<td> O(tweets) </td>	<td> O </td>		<td> O </td></tr>
<tr><td> Get photos by photo ID </td>					<td> - </td>			<td> O </td>		<td> - </td></tr>
<tr><td> Get photos of a specific user </td>			<td> - </td>			<td> - </td>		<td> O(Logged-in user's only) </td></tr>
<tr><td> Get photo album list of a specific user </td>	<td> - </td>			<td> O </td>		<td> O </td></tr>
<tr><td> Get photos in a specific album </td>			<td> - </td>			<td> O </td>		<td> O </td></tr>
<tr><td> Upload photo </td>								<td> - </td>			<td> O </td>		<td> O </td></tr>
</table>
 * @n 
 * <b>In version 1.2, the following feature is added:</b>
 * @n
<table>
<tr><td> Feature	</td>					<td> Twitter </td>	<td> Facebook </td>	<td> MySpace </td></tr>
<tr><td> Publish a post	</td>				<td> -		 </td>	<td> O </td>		<td> - </td></tr>
</table>
 * @n
 * You can access the methods of a service provider that are not supported in this %SnsGateway even if that method requires authentication.
 * The token key and the token secret of SnsAuthResult is also available on the specific service provider.
 * @n
 * @image html Social_Services_SnsGateway_diagram.png
 *
 * @remarks
 *  1. The value of the parameter @c serviceProvider of each method has to be small character, like "twitter", "facebook", and "myspaceid". @n
 *  2. In case of MySpace, the parameter @c seviceProvider has to be "myspaceid". @n
 *
 *
 * See the code snippets for information on how to use the %SnsGateway methods.
 * 
 * Osp::Social::Services::SnsGateway::GetMyBuddies() @n
 * Osp::Social::Services::SnsGateway::UpdateMyStatusText() @n
 * Osp::Social::Services::SnsGateway::GetPhotoAlbums() @n
 * Osp::Social::Services::SnsGateway::GetPhotosInAlbum() @n
 * Osp::Social::Services::SnsGateway::GetPhotosByUser() @n
 * Osp::Social::Services::SnsGateway::UploadPhoto()
 */
class  _EXPORT_SOCIAL_ SnsGateway:
	public Osp::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * This creates an uninitialized instance of %SnsGateway.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 * @see			Construct()
	 */
	SnsGateway(void);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	*/
	virtual ~SnsGateway(void);

	/**
	* Initializes this instance of %SnsGateway with the specified listeners.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	gatewayListener		The event listener @n
	*									This listener is mandatory as it receives the response of IsLoggedIn().
	* @param[in]	pContentListener	The listener for receiving the response of content-related methods from the server @n
	*									This listener is optional as it receives the response of a request related to a photo. 
	* @param[in]	pPeopleListener		The listener for receiving the response of people-related methods from the server @n
	*									This listener is optional as it receives the response of a request related to a buddy, profile, and status text.
	* @param[in]	pActivityListener	The listener for receiving the response of activity-related methods from the server @n
	*									This listener is optional as it receives the response of a request related to an activity.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_INVALID_STATE		This instance has already been constructed.
	*/
	result Construct(const ISnsGatewayListener& gatewayListener, const ISnsContentListener* pContentListener, const ISnsPeopleListener* pPeopleListener, const ISnsActivityListener* pActivityListener);

	/**
	* Initializes this instance of %SnsGateway with the specified listeners.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.2
	*
	* @return		An error code
	* @param[in]	gatewayListener		The event listener @n
	*									This listener is mandatory as it receives the response of IsLoggedIn().
	* @param[in]	pContentListener	The listener for receiving the response of content-related methods from the server @n
	*									This listener is optional as it receives the response of a request related to a photo. 
	* @param[in]	pPeopleListener		The listener for receiving the response of people-related methods from the server @n
	*									This listener is optional as it receives the response of a request related to a buddy, profile, and status text.
	* @param[in]	pActivityListener	The listener for receiving the response of activity-related methods from the server @n
	*									This listener is optional as it receives the response of a request related to an activity.
	* @param[in]	pPostListener		The listener for receiving the response of post-related methods from the server @n
	* 									This listener is optional as it receives the response of a request related to a post.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_INVALID_STATE		This instance has already been constructed.
	*/
	result Construct(const ISnsGatewayListener& gatewayListener, const ISnsContentListener* pContentListener, const ISnsPeopleListener* pPeopleListener, const ISnsActivityListener* pActivityListener, const ISnsPostListener* pPostListener);

private:
	SnsGateway(const SnsGateway& value);
	SnsGateway& operator =(const SnsGateway& value);

public:
	/**
	 * Adds the authentication result of the specific service provider.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	SNS_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	snsAuthResult			The authentication result
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @see Construct()
	 * @see SnsAuthenticator
	 * @see SnsAuthResult
	 */
	result AddAuthResult(const Osp::Social::Services::SnsAuthResult& snsAuthResult);

	/**
	 * Removes the authentication result of the service provider. @n
	 * The token key and token secret of the specific service provider are not expired.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	SNS_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	serviceProvider			The service provider
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c serviceProvider is an empty string.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @see Construct()
	 */
	result RemoveAuthResult(const Osp::Base::String& serviceProvider);

	/**
	* @if PRIVCORE
	* Signs in to the specified service provider. @n
	* If used in an application, the application can get rejected during the certification process.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup	PRIVILEGED_SNS
	*
	* @return		An error code
	* @param[in]	serviceProvider			The service provider to sign in to
	* @param[in]	loginId					The login ID of the user for the service provider
	* @param[in]	password				The password of the user for the service provider
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			The specified @c serviceProvider is an empty string, or @n
	*										the specified @c loginId or @c password is an empty string.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see Construct()
	*
	* The following example demonstrates how to use this method:
	* @code
	* MyClass::LogInToProvider(void)
	* {
	*    result r = E_SUCCESS;
	*    RequestId reqId;
	*
	*    r = pSnsGateway->LogIn(L"twitter", L"loginId", L"password");
	*
	* }
	* @endcode
	* @endif
	*/
	result LogIn(const Osp::Base::String& serviceProvider, const Osp::Base::String& loginId, const Osp::Base::String& password);


	/**
	* @if PRIVCORE
	* Signs out from the specified service provider. @n
	* If used in an application, the application can get rejected during the certification process.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup	PRIVILEGED_SNS
	*
	* @return		An error code
	* @param[in]	serviceProvider			The service provider to sign out from
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet, or @n
	*										the sign-in is not completed.
	* @exception	E_INVALID_ARG			The specified @c serviceProvider is an empty string.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see Construct()
	*
	* The following example demonstrates how to use this method:
	* @code
	* MyClass::LogOutFromProvider(void)
	* {
	*    result r = E_SUCCESS;
	*    RequestId reqId;
	*
	*    r = pSnsGateway->LogOut(L"twitter");
	*
	* }
	* @endcode
	* @endif
	*/
	result LogOut(const Osp::Base::String& serviceProvider);


	/**
	 * Gets the sign-in status for the specified service provider. @n
	 * This method checks whether the added authentication result is currently valid or not. @n
	 * If ISnsGatewayListener::OnSnsLoggedInStatusReceived() returns @c false, it means that the user authentication is needed for the specific service 
	 * provider.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	SNS_SERVICE
	 *
 	 * @return		An error code
 	 * @param[in]	serviceProvider			The service provider
	 * @param[out]	reqId					The request ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c serviceProvider is an empty string.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet, or @n
	 *										the sign-in is not completed.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @see 	Construct()
	 * @see 	ISnsGatewayListener::OnSnsLoggedInStatusReceived()
	 */
	result IsLoggedIn(const Osp::Base::String& serviceProvider, RequestId& reqId);

	/**
	 * Gets a list of the albums of the user from the specified service provider.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	SNS_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	serviceProvider			The service provider
	 * @param[in]	pAlbumOwnerId			The ID of the user whose album is required, @n
	 *										set to @c null if the album required is of the signed-in user
	 * @param[in]	pagingParam				The SnsPagingParam instance that indicates the page number and the maximum number of result items on a page
	 * @param[out]	reqId					The request ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet, or @n
	 *										the sign-in is not completed.
	 * @exception	E_INVALID_ARG			The specified @c serviceProvider or @c albumId is an empty string, or @n
	 *										a proper listener is not registered.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks	Use the SnsGateway::GetMyBuddies() method to get an album owner's user ID.
	 * @see Construct()
	 * @see ISnsContentListener::OnSnsPhotoAlbumsReceivedN()
	 * @see Osp::Social::Services::SnsAlbumInfo
	 *
	 * @n The following example demonstrates how to use this method:
	 * @code
	 * void
   * MyClass::GetMyPhotoAlbums(void)
   * {
   *    result r = E_SUCCESS;
	 *    RequestId reqId;
	 *    SnsPagingParam pagingParam(5);
   *
   *    r = pSnsGateway->GetPhotoAlbums(L"facebook", null, pagingParam, reqId);
	 *
   * }
	 *
	 * void
   * MyClass::GetBuddyPhotoAlbums(SnsProfile* pBuddyProfile)
   * {
   *    result r = E_SUCCESS;
	 *    RequestId reqId;
	 *    String snsUserId = pBuddyProfile->GetSnsUserId();
	 *    String serviceProvider = pBuddyProfile->GetServiceProvider();
	 *
	 *    SnsPagingParam pagingParam(5);
   *
   *    r = pSnsGateway->GetPhotoAlbums(serviceProvider, &snsUserId, pagingParam, reqId);
	 *
   * }
	 * @endcode
	 */
	result GetPhotoAlbums(const Osp::Base::String& serviceProvider, const Osp::Base::String* pAlbumOwnerId, SnsPagingParam& pagingParam, RequestId& reqId);

	/**
	 * Gets the photos in the specified album of the user identified by the specified snsUserId.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	SNS_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	serviceProvider			The service provider
 	 * @param[in]	pAlbumOwnerId			The ID of the user owning the photo album, @n
	 *								  		else set to @c null if the album belongs to the signed-in user
	 * @param[in]	albumId					The album ID
	 * @param[in]	pagingParam				The SnsPagingParam instance that indicates the page number and the maximum number of result items on a page
	 * @param[out]	reqId					The request ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet, or @n
	 *										the sign-in is not completed.
	 * @exception	E_INVALID_ARG			The specified @c serviceProvider or @c albumId is an empty string, or @n
	 *										a proper listener is not registered.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks	Use SnsGateway::GetPhotoAlbums() method to get an album ID and an album owner's user ID.
	 * @see Construct()
	 * @see Osp::Social::Services::ISnsContentListener::OnSnsPhotosInAlbumReceivedN()
	 * @see Osp::Social::Services::SnsPhotoInfo
	 *
	 * @n The following example demonstrates how to use this method:
	 * @code
	 * void
   * MyClass::GetBuddyPhotosInAlbum(SnsAlbumInfo *pAlbum)
   * {
   *    result r = E_SUCCESS;
	 *    RequestId reqId;
	 *    String snsUserId;
	 *    String albumId;
	 *    String serviceProvider;
	 *    SnsPagingParam pagingParam(5);
	 *
	 *    r = pAlbum->GetValue(SNS_ALBUM_PID_OWNER_ID, snsUserId);
	 *    albumId = pAlbum->GetAlbumId();
	 *    serviceProvider = pAlbum->GetServiceProvider();
   *
   *    r = pSnsGateway->GetPhotosInAlbum(serviceProvider, &snsUserId, albumId, pagingParam, reqId);
	 *
   * }
	 * @endcode
	 */
	result GetPhotosInAlbum(const Osp::Base::String& serviceProvider, const Osp::Base::String* pAlbumOwnerId, const Osp::Base::String& albumId, SnsPagingParam& pagingParam, RequestId& reqId);

	/**
	 * Gets the photos belonging to the user specified by snsUserId. @n
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	SNS_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	serviceProvider			The service provider
 	 * @param[in]	pSnsUserId				The ID of the user who owns the photos, @n
	 *								  		else set to @c null if the photos are owned by the signed-in user
	 * @param[in]	pagingParam				The SnsPagingParam instance that indicates the page number and maximum number of result items on the page
	 * @param[out]	reqId					The request ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet, or @n
	 *										the sign-in is not completed.
	 * @exception	E_INVALID_ARG			The specified @c serviceProvider is an empty string, or @n
	 *										a proper listener is not registered.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		Use SnsGateway::GetMyBuddies() method to get a user ID for the buddy.
	 * @see 	Construct()
	 * @see 	Osp::Social::Services::ISnsContentListener::OnSnsPhotosByUserReceivedN()
	 * @see 	Osp::Social::Services::SnsPhotoInfo
	 *
	 * @n The following example demonstrates how to use this method:
	 * @code
	 * void
     * MyClass::GetBuddyPhotos(SnsProfile* pSnsBuddyProfile)
     * {
     *    result r = E_SUCCESS;
	 *    RequestId reqId;
	 *
     *    String providerName = pSnsBuddyProfile->GetServiceProvider();
	 *    String buddyId = pSnsBuddyProfile->GetSnsUserId();
	 *
	 *    SnsPagingParam pagingParam(5);
	 *
     *    r = pSnsGateway->GetPhotosByUser(providerName, &buddyId, pagingParam, reqId);
	 *
     * }
	 *
	 *
     * void
	 * MySnsContentListener::OnSnsPhotosByUserReceivedN(RequestId reqId, Osp::Base::Collection::IList* pPhotoList,
	 *	 bool hasNext, SnsPagingParam& pagingParam, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg)
	 * {
	 *    IEnumerator* pEnum = null;
	 *    SnsPhotoInfo* pPhoto = null;
	 *    String title;
	 *
	 *    if (r != E_SUCCESS)
	 *    {
	 *  	// Do something for an error.
	 *    }
     *
	 *    if (pPhotoList)
	 *    {
	 *  	// Do something (show photo list or get image).
	 *      pEnum = pPhotoList->GetEnumeratorN();
	 *      while (true)
	 *      {
	 *        if (pEnum->MoveNext() == E_OUT_OF_RANGE)
	 *        {
	 *          break;
	 *        }
	 *        pPhoto = (SnsPhotoInfo*)pEnum->GetCurrent();
	 *        if (pPhoto == null)
	 *        {
	 *		    // Do something for an error.
	 *        }
	 *        r = pPhoto->GetValue(SNS_PHOTO_PID_TITLE, title);
	 *        // Check result.
	 *
	 *        // Do something more.
	 *      }
	 *     delete pEnum;
	 *   }
	 *
	 *    // Deletes the list and deallocates the memory.
	 *    pPhotoList->RemoveAll(true);
	 *    delete pPhotoList;
     * }
	 * @endcode
	 */
	result GetPhotosByUser(const Osp::Base::String& serviceProvider, const Osp::Base::String* pSnsUserId, SnsPagingParam& pagingParam, RequestId& reqId);

	/**
	 * Gets the photo by specific photoId.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	SNS_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	serviceProvider  		The service provider
	 * @param[in]   pPhotoOwnerId	 		The user ID who owns the photo, @n
	 *					 					else set to @c null if the photo is that of the logged-in user
 	 * @param[in]	photoId			 		The photo ID to be got
	 * @param[out]	reqId					The ID of the request
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet, or @n
	 *										the sign-in is not completed.
	 * @exception	E_INVALID_ARG			The specified @c serviceProvider is an empty string, or @n
	 *										a proper listener is not registered.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		Use the SnsGateway::GetPhotosByUser() method or SnsGateway::GetPhotosInAlbum() method to get a photo ID and the user ID of the photo owner.
	 * @see 	Construct()
	 * @see 	ISnsContentListener::OnSnsPhotoReceived()
	 * @see 	SnsPhotoInfo
	 */
	result GetPhoto(const Osp::Base::String& serviceProvider, const Osp::Base::String* pPhotoOwnerId,  const Osp::Base::String& photoId, RequestId& reqId );

	/**
	 * Uploads a photo to a specific service provider. @n
	 * The content type and the source file path must be set in SnsUploadContentInfo instance. @n
	 * The album ID is optional. If you want to upload a photo to the specific user created album of @c serviceProvider, the @c pAlbumId has to be set.
	 * If you want to upload a photo to the common album, the @c albumId should be set to @c null.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	SNS_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	serviceProvider			The service provider
	 * @param[in]	pAlbumId				The destination album ID
	 * @param[in]	contentInfo  			The information of the content to be uploaded
	 * @param[out]	reqId					The ID of the request
	 *
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet, or @n
	 *										the sign-in is not completed.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *										- The mandatory properties are not set in the specified @c contentInfo. @n
	 *										- The specified @c serviceProvider or @c pAlbumId parameter has an empty string. @n
	 *										- A proper listener is not registered.
	 * @exception	E_FILE_NOT_FOUND		The source file is not found.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		Use SnsGateway::GetPhotoAlbums() method to get an album ID.
	 * @see 	Construct()
	 * @see 	Osp::Social::Services::ISnsContentListener::OnSnsPhotoUploaded()
	 * @see 	Osp::Social::Services::SnsUploadContentInfo
	 *
	 * @n The following example demonstrates how to use this method:
	 * @code
	 * void
     * MyClass::UploadPhotoToProvider(String filePath)
     * {
     *    result r = E_SUCCESS;
	 *    RequestId reqId;
	 *    String serviceProvider = L"facebook";
	 *    SnsUploadContentInfo* pContent = new SnsUploadContentInfo(SNS_UPLOAD_CONTENT_PHOTO, filePath);
	 *
	 *    pContent->SetValue(SNS_CONTENT_PID_TITLE, L"trip");
	 *
     *    r = pSnsGateway->UploadPhoto(serviceProvider, null, *pContent, reqId);
	 *
	 *    delete pContent;
     * }
	 *
	 * @endcode
	 */
	result UploadPhoto(const Osp::Base::String& serviceProvider, const Osp::Base::String* pAlbumId, const SnsUploadContentInfo& contentInfo, RequestId& reqId);

	/**
	 * Gets the buddies of the signed-in user from the specified service provider.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	SNS_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	serviceProvider			The service provider
 	 * @param[in]	pagingParam				The SnsPagingParam instance that indicates the page number and maximum number of result items on the page
	 * @param[out]	reqId					The request ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet, or @n
	 *										the sign-in is not completed.
	 * @exception	E_INVALID_ARG			The specified @c serviceProvider is an empty string, or @n
	 *										a proper listener is not registered.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @see 	Construct()
	 * @see 	Osp::Social::Services::ISnsPeopleListener::OnMySnsBuddiesReceivedN()
	 * @see 	Osp::Social::Services::SnsProfile
	 *
	 * @n The following example demonstrates how to use this method:
	 * @code
	 * void
	 * MyClass::GetBuddies(void)
	 * {
	 *    result r = E_SUCCESS;
	 *    RequestId reqId;
	 *    String providerName = L"twitter";
	 *
	 *    SnsPagingParam pagingParam(5);
	 *
	 *    r = pSnsGateway->GetMyBuddies(providerName, pagingParam, reqId);
	 *
	 * }
	 *
	 *
	 * void
	 * MySnsPeopleListener::OnMySnsBuddiesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pBuddyProfileList,
		bool hasNext, SnsPagingParam& pagingParam, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg)
	 * {
	 *    IEnumerator* pEnum = null;
	 *    SnsProfile* pProfile = null;
	 *    String buddyName;
	 *
	 *    if (r != E_SUCCESS)
	 *    {
	 *  	// Do something for an error.
	 *    }
	 *
	 *    if (pBuddyProfileList)
	 *    {
	 *  	// Do something.
	 *      pEnum = pBuddyProfileList->GetEnumeratorN();
	 *      while (true)
	 *      {
	 *        if (pEnum->MoveNext() == E_OUT_OF_RANGE)
	 *        {
	 *          break;
	 *        }
	 *        pProfile = (SnsProfile*)pEnum->GetCurrent();
	 *        if (pProfile == null)
	 *        {
	 *		    // Do something for an error.
	 *        }
	 *        r = pProfile->GetValue(SNS_PROFILE_PID_USER_NAME, buddyName);
	 *        // Check result.
	 *
	 *        // Do something more.
	 *      }
	 *     delete pEnum;
	 *   }
	 *
	 *    // Deletes the list and deallocates the memory
	 *    pBuddyProfileList->RemoveAll(true);
	 *    delete pBuddyProfileList;
	 * }
	 * @endcode
	 */
	result GetMyBuddies(const Osp::Base::String& serviceProvider, SnsPagingParam& pagingParam, RequestId& reqId);

	/**
	* @if PRIVCORE
	* Gets the buddies of the signed-in user with the phone numbers and email addresses from the specified service provider. @n
	* The phone numbers and email addresses are supported only by Facebook.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	SOCIAL_SERVICE
	*
	* @return		An error code
	* @param[in]	serviceProvider		The service provider
	* @param[in]	pagingParam			The SnsPagingParam instance that indicates the page number and maximum number of result items on the page
	* @param[out]	reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet, or @n
	*									the sign-in is not completed.
	* @exception	E_INVALID_ARG		The specified @c serviceProvider is an empty string, or @n
	*									a proper listener is not registered.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @see Construct()
	* @see Osp::Social::Services::ISnsPeopleListener::OnMySnsBuddiesReceivedN()
	* @see Osp::Social::Services::SnsProfile
	* @endif
	*/
	result GetBuddies(const Osp::Base::String& serviceProvider, SnsPagingParam& pagingParam, RequestId& reqId);

	/**
	 * Gets the status text of the specified user on the specified service provider.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	SNS_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	serviceProvider			The service provider
	 * @param[in]	pSnsUserId				The snsUserId of the user, @n
	 *								  		else set to @c null if the status of the sign-in user is required
	 * @param[out]	reqId					The request ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet, or @n
	 *										the sign-in is not completed.
	 * @exception	E_INVALID_ARG			The specified @c serviceProvider is an empty string, or @n
	 *										a proper listener is not registered.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
 	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		Use SnsGateway::GetMyBuddies() method to get a user ID for the buddy.
	 * @see 	Construct()
	 * @see 	Osp::Social::Services::ISnsPeopleListener::OnSnsStatusTextReceived()
	 * @see 	Osp::Social::Services::SnsStatusText
	 */
	result GetStatusText(const Osp::Base::String& serviceProvider, const Osp::Base::String* pSnsUserId, RequestId& reqId);

	/**
	 * Sets the status text to the specified service provider.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	SNS_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	serviceProvider			The service provider
	 * @param[in]	statusText				The status text to update
	 * @param[out]	reqId					The request ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet, or @n
	 *										the sign-in is not completed.
	 * @exception	E_INVALID_ARG			The specified @c serviceProvider or @c statusText is an empty string, or @n
	 *										a proper listener is not registered.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @see 	Construct()
	 * @see 	ISnsPeopleListener::OnMySnsStatusTextUpdated()
	 *
	 * @n The following example demonstrates how to use this method:
	 * @code
	 * void MyClass::UpdateStatusText(void)
	 * {
     *    result r = E_SUCCESS;
	 *    RequestId reqId;
     *    String serviceProvider = L"twitter";
     *    String statusText = L"Hello, bada!";
	 *
     *    r = pSnsGateway->UpdateMyStatusText(serviceProvider, statusText, reqId);
	 * }
	 * @endcode
	 */
	result UpdateMyStatusText(const Osp::Base::String& serviceProvider, const Osp::Base::String& statusText, RequestId& reqId);

	/**
	 * Gets the profile of the users specified by the @c snsUserId for a specific service provider.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	SNS_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	serviceProvider	  		The service provider
	 * @param[in]	pSnsUserId		  		The Sns user ID, @n
	 *								  		else set to @c null if the profile is of the logged-in user
	 * @param[out]	reqId					The ID of the request
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet, or @n
	 *										the sign-in is not completed.
	 * @exception	E_INVALID_ARG			The specified @c serviceProvider is an empty string, or @n
	 *										a proper listener is not registered.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		Use SnsGateway::GetMyBuddies() method to get a user ID for the buddy.
	 * @see 	Construct()
	 * @see 	Osp::Social::Services::ISnsPeopleListener::OnSnsProfileReceived()
	 * @see 	Osp::Social::Services::SnsProfile
	 */
	result GetProfile(const Osp::Base::String& serviceProvider, const Osp::Base::String* pSnsUserId, RequestId& reqId);

	/**
	 * Gets the activities of the users specified by the owner for a specific service provider. @n
	 * The owner can be "All" or the specific snsUserId.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	SNS_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	serviceProvider	  		The service provider
	 * @param[in]	pActivityOwner	  		The owner of activity @n
	 *										The parameter is set to @c null to get the activities of the logged-in user. @n
	 *										The parameter is set to @c all if you want to get the activities of the logged-in user and logged-in user's friends. @n
	 *										The parameter is set to @c snsUserId if you want to get the activity of some user.
	 * @param[in]	pagingParam				The SnsPagingParam instance that indicates the page number and maximum count of result items in the page
	 * @param[out]	reqId					The request ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet, or @n
	 *										the sign-in is not completed.
	 * @exception	E_INVALID_ARG 			Either of the following conditions has occurred: @n
	 *										- The specified @c serviceProvider is an empty string. @n
	 *										- The specified @c pActivityOwner is an empty string. @n
	 *										- A proper listener is not registered.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks 	Use SnsGateway::GetMyBuddies() method to get a user ID for the buddy.
	 * @see 	Construct()
	 * @see 	Osp::Social::Services::ISnsActivityListener::OnSnsActivitiesReceivedN()
	 * @see 	Osp::Social::Services::SnsActivity
	 */
	result GetActivities(const Osp::Base::String& serviceProvider, const Osp::Base::String* pActivityOwner, const SnsPagingParam& pagingParam, RequestId& reqId);

    /**
     * Publishes the post to the specified service provider. 
     *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
     * @since		1.2
     * @privlevel 	NORMAL
     * @privgroup 	SNS_SERVICE
     *
     * @return		An error code
     * @param[in] 	serviceProvider      	The service provider
     * @param[in] 	postInfo     			The SnsPostInfo instance that contains the information of the post to be published
     * @param[out]	reqId               	The request ID
     * @exception 	E_SUCCESS               The method is successful.
     * @exception 	E_INVALID_STATE         This instance has not been constructed as yet or, @n 
	 *										the sign-in process has not finished.
     * @exception 	E_INVALID_ARG           The specified @c serviceProvider is an empty string, or @n
	 *										a proper listener is not registered.
     * @exception 	E_PRIVILEGE_DENIED    	The application does not have the privilege to call this method.
     * @exception 	E_OUT_OF_MEMORY         The memory is insufficient.
     * @remarks 	The available service provider is Facebook.
     * @see 	Construct()
     * @see 	Osp::Social::Services::ISnsPostListener::OnSnsPostPublished()
     * @see	 	Osp::Social::Services::SnsPostInfo
     */
    result PublishPost(const Osp::Base::String& serviceProvider, const SnsPostInfo& postInfo, RequestId& reqId);

private:
		ISnsGateway* __pISnsGateway;
		void* __pMGatewayListener;
		void* __pMContentListener;
		void* __pMPeopleListener;
		void* __pMActivityListener;

		//
		Osp::Base::String appId;

		friend class SnsGatewayEx;
		class SnsGatewayEx* __pSnsGatewayEx;

};

};};};

#endif
