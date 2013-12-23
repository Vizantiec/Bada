/* $Change: 1198808 $ */
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
 * @file		FAppAppControl.h
 * @brief		This is the header file for the %AppControl class.
 * 
 * This header file contains the declarations of the %AppControl class.
 */

#ifndef _FAPP_APPCONTROL_H_
#define _FAPP_APPCONTROL_H_


#include "FBaseObject.h"
#include "FBaseString.h"
#include "FAppTypes.h"
#include "FAppConfig.h"
#include "FAppIAppControlEventListener.h"

namespace Osp { namespace Base { class String; }; };
namespace Osp { namespace Base { namespace Collection { class IList; }; }; };


namespace Osp { namespace App {

/**
* The Contact %AppControl ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_contact_deprecated.htm">Contact Application Control</a>.
*
* @deprecated This application control provider name is deprecated.
* Instead of using this application control, it is recommended to use App::APPCONTROL_PROVIDER_CONTACT.
*
*	@since	1.0
*/
static const Osp::Base::String APPCONTROL_CONTACT = L"osp.appcontrol.CONTACT";
	
/**
* The Calendar %AppControl ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_calendar_deprecated.htm">Calendar Application Control</a>.
*
* @deprecated This application control provider name is deprecated.
* Instead of using this application control, it is recommended to use App::APPCONTROL_PROVIDER_CALENDAR.
*
*	@since	1.0
*
* @par OPERATION_VIEW:
* @li	input dataList: @n
* The following input data values are updated:
* - @b Since: @b 1.1 @xmlonly <pcheck kind="value" since="1.1"> @endxmlonly viewType:event, eventId @xmlonly </pcheck> @endxmlonly
*/
static const Osp::Base::String APPCONTROL_CALENDAR= L"osp.appcontrol.CALENDAR";

/**
* The Todo %AppControl ID.
*
* @deprecated This application control provider name is deprecated.
*
* @par OPERATION_PICK:
*
*	@since	1.0
* @remarks	This constant is currently not available.
*/
static const Osp::Base::String APPCONTROL_TODO= L"osp.appcontrol.TODO";

/**
* The Dial %AppControl ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_dial_deprecated.htm">Dial Application Control</a>.
*
* @deprecated This application control provider name is deprecated.
* Instead of using this application control, it is recommended to
* use App::APPCONTROL_PROVIDER_CALL with App::APPCONTROL_OPERATION_DIAL.
*
*	@since	1.0
*/
static const Osp::Base::String APPCONTROL_DIAL= L"osp.appcontrol.DIAL";

/**
* The Call %AppControl ID. @n
* Makes a phone call. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_call_deprecated.htm">Call Application Control</a>.
*
* @deprecated This application control provider name is deprecated.
* Instead of using this application control, it is recommended to use App::APPCONTROL_PROVIDER_CALL.
*
* @since			1.0
* @privlevel	NORMAL
*
* @privgroup    TELEPHONY
*
* @remarks Privilege is required to use this application control.
*/
static const Osp::Base::String APPCONTROL_CALL= L"osp.appcontrol.CALL";

/**
* The Message %AppControl ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_message_deprecated.htm">Message Application Control</a>.
*
* @deprecated This application control provider name is deprecated.
* Instead of using this application control, it is recommended to use App::APPCONTROL_PROVIDER_MESSAGE.
*
*	@since	1.0
*
* @remarks An MMS attachment may contain either an image, audio, video, vCard, vCalendar or a combination of an image, audio, vCard, and vCalendar files. @n
* MMS attachments cannot contain a video in combination with an image or an audio file.
*/
static const Osp::Base::String APPCONTROL_MESSAGE= L"osp.appcontrol.MESSAGE";

/**
* The Email %AppControl ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_email_deprecated.htm">Email Application Control</a>.
*
* @deprecated This application control provider name is deprecated.
* Instead of using this application control, it is recommended to use App::APPCONTROL_PROVIDER_EMAIL.
*
*	@since	1.0
*/
static const Osp::Base::String APPCONTROL_EMAIL= L"osp.appcontrol.EMAIL";

/**
* The Media %AppControl ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_media_deprecated.htm">Media Application Control</a>.
*
* @deprecated This application control provider name is deprecated.
* Instead of using this application control, it is recommended to use App::APPCONTROL_PROVIDER_MEDIA.
*
*	@since	1.0
*/
static const Osp::Base::String APPCONTROL_MEDIA= L"osp.appcontrol.MEDIA";

/**
* The Image %AppControl ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_image_deprecated.htm">Image Application Control</a>.
*
* @deprecated This application control provider name is deprecated.
* Instead of using this application control, it is recommended to use App::APPCONTROL_PROVIDER_IMAGE.
*
*	@since	1.0
*/
static const Osp::Base::String APPCONTROL_IMAGE= L"osp.appcontrol.IMAGE";

/**
* The Video %AppControl ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_video_deprecated.htm">Video Application Control</a>.
*
* @deprecated This application control provider name is deprecated.
* Instead of using this application control, it is recommended to use App::APPCONTROL_PROVIDER_VIDEO.
*
*	@since	1.0
*/
static const Osp::Base::String APPCONTROL_VIDEO= L"osp.appcontrol.VIDEO";

/**
* The Audio %AppControl ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_audio_deprecated.htm">Audio Application Control</a>.
*
* @deprecated This application control provider name is deprecated.
* Instead of using this application control, it is recommended to use App::APPCONTROL_PROVIDER_AUDIO.
*
*	@since	1.0
*/
static const Osp::Base::String APPCONTROL_AUDIO= L"osp.appcontrol.AUDIO";

/**
* The Browser %AppControl ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_browser_deprecated.htm">Browser Application Control</a>.
*
* @deprecated This application control provider name is deprecated.
* Instead of using this application control, it is recommended to use App::APPCONTROL_PROVIDER_BROWSER.
*
*	@since			1.0
* @privlevel	NORMAL
* @privgroup    WEB_SERVICE
*/
static const Osp::Base::String APPCONTROL_BROWSER= L"osp.appcontrol.BROWSER";


/**
* The Sign-in %AppControl ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_signin_deprecated.htm">Sign-in Application Control</a>.
*
* @deprecated This application control provider name is deprecated.
* Instead of using this application control, it is recommended to use App::APPCONTROL_PROVIDER_SIGNIN.
*
*	@since	1.0
* @if PRIVCORE
*  @privlevel  NORMAL, SYSTEM, or CORE
*  @privgroup    BUDDY_SERVICE, CONTENT_TRANSFER, LOCATION_UPLOAD, MESSAGING_SERVICE, PRIVACY_SERVICE, PROFILE_SERVICE, REMOTE_CONTENT, REMOTE_LANDMARK, REMOTE_LOCATION, REMOTE_TRACE, REMOTE_ZONE, SOCIAL_SERVICE, or USER_IDENTITY
*
* @else
*  @privlevel  NORMAL or SYSTEM
*  @privgroup    BUDDY_SERVICE, CONTENT_TRANSFER, LOCATION_UPLOAD, MESSAGING_SERVICE, PRIVACY_SERVICE, PROFILE_SERVICE, REMOTE_CONTENT, REMOTE_LANDMARK, REMOTE_LOCATION, or REMOTE_TRACE
* @endif
*
* @remarks	To use the Sign-in AppControl, the application must have at least one of the above privilege groups.
* The CONTENT_TRANSFER, MESSAGING_SERVICE, and REMOTE_CONTENT privilege groups are removed from the required privilege group list to use this application control.
*
*/
static const Osp::Base::String APPCONTROL_SIGNIN= L"osp.appcontrol.SIGNIN";

/**
* The Camera %AppControl ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_camera_deprecated.htm">Camera Application Control</a>.
*
* @deprecated This application control provider name is deprecated.
* Instead of using this application control, it is recommended to use App::APPCONTROL_PROVIDER_CAMERA.
*
*	@since	1.0
*/
static const Osp::Base::String APPCONTROL_CAMERA= L"osp.appcontrol.CAMERA";

/**
* The Bluetooth %AppControl ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_bluetooth_deprecated.htm">Bluetooth Application Control</a>.
*
* @deprecated This application control provider name is deprecated.
* Instead of using this application control, it is recommended to use App::APPCONTROL_PROVIDER_BLUETOOTH.
*
*	@since	1.0
*/
static const Osp::Base::String APPCONTROL_BT= L"osp.appcontrol.BT";

/**
* The Setting %AppControl ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_settings_deprecated.htm">Settings Application Control</a>.
*
* @deprecated This application control provider name is deprecated.
* Instead of using this application control, it is recommended to use App::APPCONTROL_PROVIDER_SETTINGS.
*
* @since 	1.2
*/
static const Osp::Base::String APPCONTROL_SETTINGS= L"osp.appcontrol.SETTINGS";
	
/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 *
 * @since	1.0
 */
static const Osp::Base::String INTERNETPROFILE = L"osp.appcontrol.INTERNETPROFILE";

/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 *
 * @since	1.0
 */
static const Osp::Base::String APPCONTROL_SELF= L"osp.appcontrol.SELF";


/**
* The Contact %AppControl provider ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_contact.htm">Contact Application Control</a>.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_PROVIDER_CONTACT = L"osp.appcontrol.provider.contact";

/**
* The Certificate Manager %AppControl provider ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_certmgr.htm">Certificate Manager Application Control</a>.
*
* @since		2.0
*/
static const Osp::Base::String APPCONTROL_PROVIDER_CERTIFICATE_MANAGER= L"osp.appcontrol.provider.certificatemanager";

/**
* The Calendar %AppControl provider ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_calendar.htm">Calendar Application Control</a>.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_PROVIDER_CALENDAR= L"osp.appcontrol.provider.calendar";

/**
* The Call %AppControl provider ID. @n
* Makes a phone call. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_call.htm">Call Application Control</a>.
*
* @since			2.0
* @privlevel	NORMAL
*
* @privgroup    TELEPHONY
*
* @remarks Privilege is required to use this application control.
*/
static const Osp::Base::String APPCONTROL_PROVIDER_CALL= L"osp.appcontrol.provider.call";

/**
* The Message %AppControl provider ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_message.htm">Message Application Control</a>.
*
*	@since	2.0
*
* @remarks	An MMS attachment may contain either an image, audio, video, vCard, vCalendar or a combination of an image, audio, vCard, and vCalendar files. @n
* 			MMS attachments cannot contain a video in combination with an image or an audio file. @n
*			From bada 2.0, the CC and BCC recipients are merged with the TO recipients when launching the MMS app control.
*/
static const Osp::Base::String APPCONTROL_PROVIDER_MESSAGE= L"osp.appcontrol.provider.message";

/**
* The Email %AppControl provider ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_email.htm">Email Application Control</a>.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_PROVIDER_EMAIL= L"osp.appcontrol.provider.email";

/**
* The Media %AppControl provider ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_media.htm">Media Application Control</a>.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_PROVIDER_MEDIA= L"osp.appcontrol.provider.media";

/**
* The Image %AppControl provider ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_image.htm">Image Application Control</a>.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_PROVIDER_IMAGE= L"osp.appcontrol.provider.image";

/**
* @if PRIVCORE
* The ImageCrop application control provider ID @n
*
*	@since	2.0
* @privlevel	CORE
* @privgroup  IMAGE_EDITOR
*
* @remarks Privilege is required to use this application control. @n
*					 
* @endif
*/
static const Osp::Base::String APPCONTROL_PROVIDER_IMAGE_EDITOR= L"osp.appcontrol.provider.imageeditor";


/**
* The Video %AppControl provider ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_video.htm">Video Application Control</a>.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_PROVIDER_VIDEO= L"osp.appcontrol.provider.video";

/**
* The Audio %AppControl provider ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_audio.htm">Audio Application Control</a>.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_PROVIDER_AUDIO= L"osp.appcontrol.provider.audio";

/**
* The Browser %AppControl provider ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_browser.htm">Browser Application Control</a>.
*
*	@since			2.0
* @privlevel	NORMAL
* @privgroup    WEB_SERVICE
*
* @remarks Privilege is required to use this application control.
*/
static const Osp::Base::String APPCONTROL_PROVIDER_BROWSER= L"osp.appcontrol.provider.browser";


/**
* The Sign-in %AppControl provider ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_signin.htm">Sign-in Application Control</a>.
*
*	@since	2.0
* @if PRIVCORE
*  @privlevel  NORMAL, SYSTEM, or CORE
*  @privgroup    BUDDY_SERVICE, CONTENT_TRANSFER, LOCATION_UPLOAD, MESSAGING_SERVICE, PRIVACY_SERVICE, PROFILE_SERVICE, REMOTE_CONTENT, REMOTE_LANDMARK, REMOTE_LOCATION, REMOTE_TRACE, REMOTE_ZONE, SOCIAL_SERVICE, or USER_IDENTITY
*
* @else
*  @privlevel  NORMAL or SYSTEM
*  @privgroup    BUDDY_SERVICE, CONTENT_TRANSFER, LOCATION_UPLOAD, MESSAGING_SERVICE, PRIVACY_SERVICE, PROFILE_SERVICE, REMOTE_CONTENT, REMOTE_LANDMARK, REMOTE_LOCATION, or REMOTE_TRACE
* @endif
*
* @remarks	To use the Sign-in AppControl, the application must have at least one of the above privilege groups.
*
*/
static const Osp::Base::String APPCONTROL_PROVIDER_SIGNIN= L"osp.appcontrol.provider.signin";

/**
* The Camera %AppControl provider ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_camera.htm">Camera Application Control</a>.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_PROVIDER_CAMERA= L"osp.appcontrol.provider.camera";

/**
* The Bluetooth %AppControl provider ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_bluetooth.htm">Bluetooth Application Control</a>.
*
*	@since	2.0
*
* @remarks Bluetooth functionality cannot be tested on the Emulator.
*/
static const Osp::Base::String APPCONTROL_PROVIDER_BLUETOOTH= L"osp.appcontrol.provider.bluetooth";

/**
* The Setting %AppControl ID. @n
* For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_settings.htm">Settings Application Control</a>.
*
* @since 	2.0
*/
static const Osp::Base::String APPCONTROL_PROVIDER_SETTINGS= L"osp.appcontrol.provider.settings";

/**
* @if PRIVCORE
* The AllShare application control provider ID @n
*
* @since		2.0
* @privlevel	CORE
* @privgroup    ALLSHARE
*
* @remarks Privilege is required to use this application control. @n
*	'path' is the main key of the all keys. Other keys' value are the extra information for the main key's value. @n
*	'path' and 'type' values should be filled mandatorily and the others are optional. @n
*	More than one content can be added if the 'path' key and value item is added in the input list.
*
* @li	Input dataList : @n
* <table border=1 cellpadding="1" cellspacing="1">
* <tr>
* 	<th>Key</th>
* 	<th>value</th>
* 	<th>description</th>
* </tr>
* <tr>
* 	<td>path</td>
* 	<td>Path, such as /Media/Images/sampleImage.jpg or http://localhost:8080/sampleVideo.mp4 or http://mycompany.com/sampleImage.jpg"</td>
* 	<td>This is the main key. @n Path to the media file to be shared.</td>
* </tr>
* <tr>
* 	<td>type</td>
* 	<td>image|audio|video</td>
*	<td>Type of the media file.</td>
* </tr>
* <tr>
* 	<td>title</td>
* 	<td>Title, such as MyTitle</td>
* 	<td>Title of the media file.</td>
* </tr>
* <tr>
* 	<td>duration</td>
* 	<td>Duration in milliseconds, such as 60000 (60secs)</td>
*	<td>Duration of the media file.</td>
* </tr>
* <tr>
* 	<td>bitrate</td>
* 	<td>Bit rate in kilo-bits per second, such as 192</td>
*	<td>Bit rate of the media file.</td>
* </tr>
* <tr>
* 	<td>width</td>
* 	<td>Width in pixel, such as 640</td>
*	<td>Width of the media file</td>
* </tr>
* <tr>
* 	<td>height</td>
* 	<td>Height in pixel, such as 480</td>
*	<td>Height of the media file</td>
* </tr>
*<tr>
*	<td>size</td>
*	<td>Size in bytes, such as 512000 (500KB)</td>
*	<td>Size of the media file.</td>
*</td>
*<tr>
*	<td>mimeType</td>
*	<td>Mime type, such as audio/mp3</td>
*	<td>Mime type of the media file.</td>
*</tr>
*<tr>
*	<td>artist</td>
*	<td>Artist, such as badaSinger</td>
*	<td>Artist of media file.</td>
*</tr>
*<tr>
*	<td>albumTitle</td>
*	<td>Album title, such as badaAlbum</td>
*	<td>Album title of media file.</td>
*</tr>
* </table>
*
* @n
* @li	Example code for AllShare: @n
* @code
*     void
*     MyAppClass::AllShareAppControlSample(void)
*     {
*         ArrayList* pDataList = new ArrayList();
*
*         pDataList->Construct();
*         pDataList->Add(*new String(L"path:/mycompany.com/sampleImage.jpg"));
*         pDataList->Add(*new String(L"type:image"));
*         pDataList->Add(*new String(L"title:MyImage"));
*         pDataList->Add(*new String(L"width:640"));
*         pDataList->Add(*new String(L"height:480"));
*         pDataList->Add(*new String(L"size:51200"));
*         pDataList->Add(*new String(L"mimeType:image/jpg"));
*         pDataList->Add(*new String(L"path:http://mycompany.com/sampleVideo.mp4"));
*         pDataList->Add(*new String(L"type:video"));
*         pDataList->Add(*new String(L"title:MyVideo"));
*         pDataList->Add(*new String(L"duration:600000"));
*         pDataList->Add(*new String(L"width:320"));
*         pDataList->Add(*new String(L"height:240"));
*         pDataList->Add(*new String(L"size:2097152"));
*         pDataList->Add(*new String(L"mimeType:video/mp4"));
*         pDataList->Add(*new String(L"path:http://mycompany.com/sampleAudio.mp3"));
*         pDataList->Add(*new String(L"type:audio"));
*         pDataList->Add(*new String(L"title:MyAudio"));
*         pDataList->Add(*new String(L"duration:200000"));
*         pDataList->Add(*new String(L"size:3565158"));
*         pDataList->Add(*new String(L"mimeType:audio/mp3"));
*         pDataList->Add(*new String(L"artist:badaSinger"));
*         pDataList->Add(*new String(L"albumTitle:badaAlbum"));
*
*         AppControl* pAc = AppManager::FindAppControlN(APPCONTROL_PROVIDER_ALLSHARE, APPCONTROL_OPERATION_SHARE);
*         if(pAc)
*         {
*             pAc->Start(pDataList, null);
*             delete pAc;
*         }
*
*         pDataList->RemoveAll(true);
*         delete pDataList;
*     }
*
* @endcode
* @endif
*/
static const Osp::Base::String APPCONTROL_PROVIDER_ALLSHARE= L"osp.appcontrol.provider.allshare";

/**
* Operation Add. @n
* Adds an application item.
*
* @deprecated This operation is deprecated.
* Instead of using this operation, it is recommended to use App::APPCONTROL_OPERATION_ADD.
*
*	@since	1.0
*/
static const Osp::Base::String OPERATION_ADD= L"osp.appcontrol.operation.ADD";

/**
* Operation Pick. @n
* Picks some application item(s).
*
* @deprecated This operation is deprecated.
* Instead of using this operation, it is recommended to use App::APPCONTROL_OPERATION_PICK.
*
*	@since	1.0
*/
static const Osp::Base::String OPERATION_PICK= L"osp.appcontrol.operation.PICK";

/**
* Operation Edit. @n
* Edits an application item.
*
* @deprecated This operation is deprecated.
* Instead of using this operation, it is recommended to use App::APPCONTROL_OPERATION_EDIT.
*
*	@since	1.0
*/
static const Osp::Base::String OPERATION_EDIT= L"osp.appcontrol.operation.EDIT";

/**
* Operation View. @n
* Shows the application content.
*
* @deprecated This operation is deprecated.
* Instead of using this operation, it is recommended to use App::APPCONTROL_OPERATION_VIEW.
*
*	@since	1.0
*/
static const Osp::Base::String OPERATION_VIEW= L"osp.appcontrol.operation.VIEW";

/**
* Operation Play. @n
* Plays the application content.
*
* @deprecated This operation is deprecated.
* Instead of using this operation, it is recommended to use App::APPCONTROL_OPERATION_PLAY.
*
* @since	1.0
*/
static const Osp::Base::String OPERATION_PLAY= L"osp.appcontrol.operation.PLAY";

/**
* @internal
* This is internal. If used in an application, the application can get rejected during the certification process.
* Operation Main @n
* There is no need to set the operation to "Main" (which means application is launched without operation). @n
* If the operation is not set, AppControl implicitly sets operation to "MAIN".
*
*	@since	1.0
*/
static const Osp::Base::String OPERATION_MAIN= L"osp.appcontrol.operation.MAIN";

/**
* Operation Default. @n
*
* Uses the default operation specific to the application control.
* An application control can export its functionality using an operation. If the application control exports only one operation, OPERATION_DEFAULT can act as the alias for the operation.
*
* @deprecated This operation is deprecated.
* Instead of using this operation, it is recommended to use App::APPCONTROL_OPERATION_DEFAULT.
*
* @since 1.1
*/
static const Osp::Base::String OPERATION_DEFAULT= L"osp.appcontrol.operation.DEFAULT";

/**
* Operation SignIn. @n
* Displays the sign in pop-up.
*
* @deprecated This operation is deprecated.
* Instead of using this operation, it is recommended to use App::APPCONTROL_OPERATION_SIGNIN.
*
*	@since	1.0
*/
static const Osp::Base::String OPERATION_SIGNIN= L"osp.appcontrol.operation.SIGNIN";
/**
* Operation SignOut. @n
* Signs out of the session.
*
* @deprecated This operation is deprecated.
* Instead of using this operation, it is recommended to use App::APPCONTROL_OPERATION_SIGNOUT.
*
*	@since	1.0
*/
static const Osp::Base::String OPERATION_SIGNOUT= L"osp.appcontrol.operation.SIGNOUT";

/**
* Operation Capture.
*
* @deprecated This operation is deprecated.
* Instead of using this operation, it is recommended to use App::APPCONTROL_OPERATION_CAPTURE.
*
*	@since	1.0
*/
static const Osp::Base::String OPERATION_CAPTURE= L"osp.appcontrol.operation.CAPTURE";


/**
* Operation Add. @n
* Adds an application item.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_OPERATION_ADD= L"osp.appcontrol.operation.add";

/**
* Operation Call. @n
* Makes a call to the specified phone number.
*
* @since	2.0
*/
static const Osp::Base::String APPCONTROL_OPERATION_CALL= L"osp.appcontrol.operation.call";

/**
* Operation Capture.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_OPERATION_CAPTURE= L"osp.appcontrol.operation.capture";

/**
* Operation Compose.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_OPERATION_COMPOSE= L"osp.appcontrol.operation.compose";

/**
* Operation Configure Settings.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_OPERATION_CONFIGURE= L"osp.appcontrol.operation.configure";

/**
* Operation Default. @n
*
* Uses the default operation specific to the application control.
* An application control can export its functionality using an operation. If the application control exports only one operation, OPERATION_DEFAULT can act as the alias for the operation.
*
* @since 2.0
*/
static const Osp::Base::String APPCONTROL_OPERATION_DEFAULT= L"osp.appcontrol.operation.default";

/**
* Operation Dial. @n
* Launches the dial screen for making a call.
*
* @since	2.0
*/
static const Osp::Base::String APPCONTROL_OPERATION_DIAL= L"osp.appcontrol.operation.dial";

/**
* Operation Edit. @n
* Edits an application item.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_OPERATION_EDIT= L"osp.appcontrol.operation.edit";

/**
* @internal
* This is internal. If used in an application, the application can get rejected during the certification process.
* Operation Main @n
* There is no need to set the operation to "Main" (which means application is launched without operation). @n
* If the operation is not set, AppControl implicitly sets operation to "MAIN".
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_OPERATION_MAIN= L"osp.appcontrol.operation.main";

/**
* Operation Pick. @n
* Picks some application item(s).
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_OPERATION_PICK= L"osp.appcontrol.operation.pick";

/**
* Operation Play. @n
* Plays the application content.
*
* @since	2.0
*/
static const Osp::Base::String APPCONTROL_OPERATION_PLAY= L"osp.appcontrol.operation.play";

/**
* Operation Record. @n
* Records the content.
*
* @since	2.0
*/
static const Osp::Base::String APPCONTROL_OPERATION_RECORD= L"osp.appcontrol.operation.record";

/**
* Operation Share. @n
* Shares the contents.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_OPERATION_SHARE= L"osp.appcontrol.operation.share";

/**
* Operation SignIn. @n
* Displays the sign in pop-up.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_OPERATION_SIGNIN= L"osp.appcontrol.operation.signin";
/**
* Operation SignOut. @n
* Signs out of the session.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_OPERATION_SIGNOUT= L"osp.appcontrol.operation.signout";

/**
* Operation View. @n
* Shows the application content.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_OPERATION_VIEW= L"osp.appcontrol.operation.view";

/**
* @if PRIVCORE
* Operation Crop. @n
* Shows image with the crop rectangle.
*
*	@since	2.0
* @remarks Privilege is required to use this application control. @n
*					 The result is the path of cropped image file. 
* @endif
*/
static const Osp::Base::String APPCONTROL_OPERATION_CROP= L"osp.appcontrol.operation.crop";

/**
 * @internal
 * Not specified category
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_NONE= L"osp.appcontrol.category.none";

/**
 * The audio category.
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_AUDIO= L"osp.appcontrol.category.audio";

/**
 * The browser category.
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_BROWSER= L"osp.appcontrol.category.browser";

/**
 * The Bluetooth device category.
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_BLUETOOTH= L"osp.appcontrol.category.bluetooth";

/**
 * The calendar category.
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_CALENDAR= L"osp.appcontrol.category.calendar";

/**
 * The certificate category.
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_CERTIFICATE= L"osp.appcontrol.category.certificate";

/**
 * The contact category.
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_CONTACT= L"osp.appcontrol.category.contact";

/**
 * The document category
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_DOCUMENT= L"osp.appcontrol.category.document";

/**
 * The email category.
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_EMAIL= L"osp.appcontrol.category.email";

/**
 * The media category. @n
 * Specifying App::APPCONTROL_CATEGORY_MEDIA is equivalent to specifying all the App::APPCONTROL_CATEGORY_AUDIO,
 * App::APPCONTROL_CATEGORY_IMAGE, and App::APPCONTROL_CATEGORY_VIDEO categories.
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_MEDIA= L"osp.appcontrol.category.media";

/**
 * The MMS category.
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_MMS= L"osp.appcontrol.category.mms";

/**
 * The image category.
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_IMAGE= L"osp.appcontrol.category.image";

/**
 * The security category.
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_SECURITY= L"osp.appcontrol.category.security";

/**
 * The SMS category.
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_SMS= L"osp.appcontrol.category.sms";

/**
 * The settings category.
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_SETTINGS= L"osp.appcontrol.category.settings";

/**
 * The video call category.
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_VIDEO_CALL= L"osp.appcontrol.category.videocall";

/**
 * The voice call category.
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_VOICE_CALL= L"osp.appcontrol.category.voicecall";

/**
 * The video category.
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_VIDEO= L"osp.appcontrol.category.video";

/**
 * The complete URI handling category corresponding to AppManager::StartAppControl().
 *
 * @since	2.0
 */
static const Osp::Base::String APPCONTROL_CATEGORY_URI= L"osp.appcontrol.category.uri";


/**
* The %AppControl operation is successful.
*
*	@since	1.0
*/
static const Osp::Base::String APPCONTROL_RESULT_SUCCEEDED= L"Succeeded";

/**
* The %AppControl operation has failed.
*
*	@since	1.0
*/
static const Osp::Base::String APPCONTROL_RESULT_FAILED= L"Failed";

/**
* The %AppControl operation is canceled.
*
*	@since	1.0
*/
static const Osp::Base::String APPCONTROL_RESULT_CANCELED= L"Canceled";

/**
* The %AppControl is terminated without sending the result.
*
*	@since	2.0
*/
static const Osp::Base::String APPCONTROL_RESULT_TERMINATED= L"Terminated";

/**
*	@class	AppControl
*	@brief	This class represents the application control behavior.
*	@since	1.0
*	
*
*	The %AppControl class represents the application control behavior, that provides a standard mechanism for using specific operations exported by other applications.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/app_controls.htm">Application Controls</a>.
* 
* @see	Osp::App::AppManager
*
* 	The following example demonstrates how to use the %AppControl class.
*
*
*	@code
*
*	using namespace Osp::Base::Collection;
*	using namespace Osp::App;
*
*	void
*	MyAppClass::AppControlCallSample(void)
*	{
*		ArrayList* pDataList = new ArrayList();
*		String* pData = new String(L"tel:1234567890");
*		String* pData2 = new String(L"type:voice");
*
*		pDataList->Construct();
*		pDataList->Add(*pData);
*		pDataList->Add(*pData2);
*
*		AppControl* pAc = AppManager::FindAppControlN(APPCONTROL_PROVIDER_CALL, APPCONTROL_OPERATION_CALL);
*		if(pAc)
*		{
*			pAc->Start(pDataList, null);
*			delete pAc;
*		}
*
*		pDataList->RemoveAll(true);
*		delete pDataList;
*	}
*
*	@endcode
*/
class _EXPORT_APP_  AppControl
	:public Osp::Base::Object
{
public:

// Lifecycle
private:
	/*
	* This is the default constructor for this class.
	*/
	AppControl(void);
public:
	/**
	* This is the destructor for this class.
	*
	*	@since	1.0
	*/
	virtual ~AppControl(void);

	/**
	* @internal
	* This method is for internal use only. The bada platform team is not
	* responsible for any behavioral correctness, consistency, and
	* security-related issues that might arise after using this method.
	*
	*	@since	1.0
	*/
	result Construct(void* launchInfo);

public:
	/**
	* Starts the resolved application control. @n
	* Once the application starts, it goes to the background and the target
	* application control is displayed. Some application controls, such as
	* App::APPCONTROL_PROVIDER_CALL and  App::APPCONTROL_PROVIDER_BROWSER require proper privileges.
	*
	* @since		1.0
	* @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*                For more information, see @ref CompAppControlStartPage "here".
	*
	* @return		An error code	
	* @param[in]	pDataList	The data list to deliver to the resolved application control @n
	*							The maximum size of the list is 4096 bytes.
	* @param[in]	pListener	The application control callback listener @n
	*							Some application controls need to get the callback result by implementing the IAppControlEventListener interface.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_MAX_EXCEEDED			The size of @c pDataList has exceeded the maximum limit @b since: @b 2.0.
	* @exception	E_INVALID_ARG			The target application control does not accept @c pDataList @b since: @b 2.0.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_OBJ_NOT_FOUND			The target application control resource is not found.
	* @exception	E_IN_PROGRESS			The application control is in progress: @n
	* 										- The application has already started an AppControl. @n
	* 										- The target application has already started.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_SYSTEM				A system error has occurred.
	* @remarks		If the %IAppControlEventListener instance (@c pListener) needs to get the
	* 				callback result for an application control, it should be valid till
	* 				IAppControlEventListener::OnAppControlCompleted() is invoked.
	* 				For example, a form object listener should not be deleted before the
	* 				system invokes IAppControlEventListener::OnAppControlCompleted().
	* @remarks		E_INVALID_ARG is returned only for the platform application control. @n
	* 	 			For the list of platform application control, see
	* 				<a href="../com.osp.cppappprogramming.help/html/dev_guide/app/platform_appcontrols.htm">
	* 				Platform Application Control</a>.
	*
	* @see	IAppControlEventListener, AppManager::FindAppControlN(), AppManager::FindAppControlsN()
	*/
	result Start(const Osp::Base::Collection::IList* pDataList, const IAppControlEventListener* pListener);

	/**
	 * @page             CompAppControlStartPage Compatibility for Start()
	 * @section          CompAppControlStartPageIssue Issues
	 *                   Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 *
	 *		-# If the size of @c pDataList exceeds the platform limit, E_SYSTEM is returned.
	 *		-# If the target application control is not able to handle @c pDataList, either E_SYSTEM or E_IN_PROGRESS is returned.
	 *
	 * @section          CompAppControlStartPageResolution Resolutions
	 * The issues mentioned above are resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 *
	 *      -# If the size of @c pDataList exceeds the platform limit, E_MAX_EXCEEDED is returned.
	 *      -# If the target application control is not able to handle @c pDataList, E_INVALID is returned.
	 *
	 */	
	
	/**
	 * Gets the name of the application that provides the features represented by this %AppControl instance.
	 *
	 * @since			2.0
	 * @return		The name of the application providing this %AppControl instance
	 */
	Osp::Base::String GetAppName(void) const;

	/**
	 * Gets the associated application control provider ID. @n
	 *
	 * @since			2.0
	 * @return		The application control provider ID
	 */
	Osp::Base::String GetAppControlProviderId(void) const;

	/**
	 * Gets the associated operation ID. @n
	 *
	 * @since			2.0
	 * @return		The operation ID
	 */
	Osp::Base::String GetOperationId(void) const;

	/**
	 * Returns the associated application control categories.
	 *
	 * @since	2.0
     * @return	A pointer to the list of application control categories, @n
          *    		      else @c null if an error occurs
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList* GetCategoryListN(void) const;

	/**
	 * Stops the activated application control. @n
	 * This method works only with the following %AppControls provided by the platform:
	 * App::APPCONTROL_PROVIDER_AUDIO, App::APPCONTROL_PROVIDER_BLUETOOTH, @n
	 * App::APPCONTROL_PROVIDER_CALENDAR, App::APPCONTROL_PROVIDER_CAMERA, @n
	 * App::APPCONTROL_PROVIDER_CERTIFICATE_MANAGER, App::APPCONTROL_PROVIDER_CONTACT, @n
	 * App::APPCONTROL_PROVIDER_EMAIL, App::APPCONTROL_PROVIDER_IMAGE, @n
	 * App::APPCONTROL_PROVIDER_MEDIA, App::APPCONTROL_PROVIDER_MESSAGE, @n
	 * and App::APPCONTROL_PROVIDER_VIDEO.
	 *
	 * @since		2.0
	 * @return          An error code
	 * @exception E_SUCCESS                        The method is successful.
     * @exception E_SYSTEM                         A system error has occurred.
     * @exception E_INVALID_OPERATION        The application control is not permitted to call this method.
     * @remarks	This method is asynchronous.
	 */
	result Stop(void);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @since			1.0
	 * @return		@c true if it is activated @n
	 *				else @c false
	 */
	static bool IsActivated(void);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	static void SetClear(void);

private:
	result __GetAppControlPrivilegeGroup(const Osp::Base::String& providerId, char* operationId, int& privilege);

private:
	void* __pLaunchInfo;
	static bool __pIsRunning;

	friend class AppManager;
	
	friend class AppControlEx;
	class AppControlEx* __pAppControlEx;	
};

}; }; // Osp::App

#endif // _FAPP_APPCONTROL_H_
