/* $Change: 934755 $ */
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
 * @file    FNetNfcNfcManager.h
 * @brief   This is the header file for the %NfcManager class.
 *
 * This header file contains the declarations of the %NfcManager class.
 */
#ifndef _FNET_NFC_NFC_MANAGER_H_
#define _FNET_NFC_NFC_MANAGER_H_

#include "FNetConfig.h"
#include "FBaseObject.h"
#include "FBaseResult.h"
#include "FNetNfcNfcTypes.h"

namespace Osp { namespace Net { namespace Nfc {

// Forward declaration
class INfcManagerEventListener;
class INfcTransactionEventListener;
class INfcTagDiscoveryEventListener;
class INdefMessageDiscoveryEventListener;
class NdefMessage;
class NdefRecordType;
class TagConnection;
class __NfcManagerAgent;

/**
 * @class    NfcManager
 * @brief    This is the manager class for the NFC features.
 * @since    2.0
 *
 * The %NfcManager class is the manager class for NFC features that includes the methods for enabling and disabling the NFC feature of
 * the device and the mechanism for establishing a connection with the detected tag. It is also used to detect the NFC
 * tags and NDEF messages. @n@n
 * There are two ways to get the TagConnection instance established with the detected tag. @n
 * @li Use the INfcTagDiscoveryEventListener::OnNfcTagDetectedN() method that is invoked immediately when the target
 *     tag is detected.
 * @li Invoke the GetCurrentTagConnectionN() method after the tag is detected.
 *
 * If the target tag is lost, the INfcTagDiscoveryEventListener::OnNfcTagLost() method is called and the old
 * TagConnection instance becomes invalid. Therefore, the operations performed by the TagConnection class are not
 * processed anymore. Moreover, the TagConnection instance cannot be used again even if the same tags are detected
 * again by the device.
 * 
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/nfc.htm">NFC Guide</a>.
 *
 * The following example demonstrates how to use the %NfcManager class. 
 *
 * @code
 * // MyClass.h
 * #include <FNet.h>
 *
 * class MyClass :
 *            public Osp::Net::Nfc::INfcManagerEventListener,
 *            public Osp::Net::Nfc::INfcTagDiscoveryEventListener,
 *            public Osp::Net::Nfc::INdefMessageDiscoveryEventListener
 * {
 * public:
 *      // The method declarations are hidden for the sake of simplicity.
 *
 * private:
 *      Osp::Net::Nfc::NfcManager*      __pNfcManager;
 *      Osp::Net::Nfc::TagConnection*   __pConnection;
 * };
 *
 * // MyClass.cpp
 * #include "MyClass.h"
 *
 * using namespace Osp::Net::Nfc;
 *
 * MyClass::MyClass(void) : __pNfcManager(null), __pConnection(null)
 * {
 *      __pNfcManager = new NfcManager();
 * }
 *
 * MyClass::~MyClass(void)
 * {
 *      // Removes the tag discovery event listener for all the NFC tag types.
 *      __pNfcManager->RemoveTagDiscoveryEventListener(*this, NFC_TAG_TYPE_ALL);
 *      // Removes the NDEF message discovery event listener for all the TNF types.
 *      __pNfcManager->RemoveNdefMessageDiscoveryEventListener(*this, NdefRecordType(NDEF_TNF_ALL));
 *
 *      delete __pNfcManager;
 * }
 *
 * void
 * MyClass::DiscoverySample(void)
 * {
 *      // Creates the NfcManager instance and registers the manager event listener.
 *      __pNfcManager->Construct(*this);
 *
 *      if (__pNfcManager->IsTagConnected())
 *      {
 *          // This is the way to get the connection already established with the detected tag.
 *          __pConnection = __pNfcManager->GetCurrentTagConnectionN();
 *
 *          // Perform connection operations here.
 *      }
 *
 *      // Adds the tag discovery event listener for all the NFC tag types.
 *      // This is the method to establish the connection with tags that are detected hereafter.
 *      __pNfcManager->AddTagDiscoveryEventListener(*this, NFC_TAG_TYPE_ALL);
 *
 *      // Adds the NDEF message discovery event listener for all the TNF types.
 *      // This is the method to get NDEF messages that are detected hereafter.
 *      __pNfcManager->AddNdefMessageDiscoveryEventListener(*this, NdefRecordType(NDEF_TNF_ALL));
 * }
 *
 * // This method is invoked when a new tag is detected.
 * void
 * MyClass::OnNfcTagDetectedN(TagConnection* pConnection)
 * {
 *      __pConnection = pConnection;
 *
 *      // Perform connection operations here.
 * }
 *
 * // This method is invoked when the target tag is lost.
 * void
 * MyClass::OnNfcTagLost(void)
 * {
 *      // The acquired TagConnection should be deallocated.
 *      delete __pConnection;
 * }
 *
 * // This method is invoked when a new NDEF message is detected.
 * void
 * MyClass::OnNdefMessageDetectedN(NdefMessage* pMessage)
 * {
 *      // Manipulate the received message here.
 *
 *      // Deallocates the received NdefMessage.
 *      pMessage->RemoveAllRecords(true);
 *      delete pMessage;
 * }
 * @endcode
 */
class _EXPORT_NET_ NfcManager : public Osp::Base::Object
{

public:
    /**
     * This is the default constructor for this class.
     *
     * @since       2.0
     *
     * @remarks     After creating an instance of this class, the Construct() method must be called explicitly to
     *              initialize this instance.
     * @see         Construct()
     */
    NfcManager(void);

    /**
     * This is the destructor for this class.
     *
     * @since       2.0
     */
    ~NfcManager(void);

    /**
     * Initializes this instance of %NfcManager with the specified listener.
     *
     * @since       2.0
     *
     * @return      An error code
     * @param[in]   listener                The %INfcManagerEventListener instance to be added
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_UNSUPPORTED_OPERATION The device does not support the NFC feature.
     * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
     *                                      For example, this method is called repeatedly.
     * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
     * @exception   E_SYSTEM                A system error has occurred.
     */
    result Construct(const INfcManagerEventListener& listener);

    /**
     * Activates the NFC feature of the device.
     *
     * @since       2.0
     * @privlevel   NORMAL
     * @privgroup   NFC
     *
     * @return      An error code
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
     *                                      For example, this instance has not been constructed as yet.
     * @exception   E_IN_PROGRESS           The activation process is in progress.
     * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
     *                                      operation. @n
     *                                      For example, the NFC feature is already activated.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_SYSTEM                A system error has occurred.
     * @see         INfcManagerEventListener::OnNfcActivated()
     */
    result Activate(void);

    /**
     * Deactivates the NFC feature of the device.
     *
     * @since       2.0
     * @privlevel   NORMAL
     * @privgroup   NFC
     *
     * @return      An error code
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
     *                                      For example, this instance has not been constructed as yet.
     * @exception   E_IN_PROGRESS           The deactivation process is in progress.
     * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
     *                                      operation. @n
     *                                      For example, the NFC feature is already deactivated.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_SYSTEM                A system error has occurred.
     * @see         INfcManagerEventListener::OnNfcDeactivated()
     */
    result Deactivate(void);

    /**
     * Checks whether the NFC feature is activated.
     *
     * @since       2.0
     *
     * @return      @c true if the NFC feature is activated, @n
     *              else @c false
     */
    bool IsActivated(void) const;

    /**
     * Checks whether the NFC tag is currently connected with the device.
     *
     * @since       2.0
     *
     * @return      @c true if the NFC tag is currently connected, @n
     *              else @c false
     */
    bool IsTagConnected(void) const;

    /**
     * Gets the tag connection with the currently detected tag.
     *
     * @since       2.0
     * @privlevel   NORMAL
     * @privgroup   NFC
     *
     * @return      The tag connection with the currently detected tag, @n
     *              else @c null if no tag is connected or if the connection fails
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
     *                                      For example, this instance has not been constructed as yet or the NFC
     *                                      feature is not activated.
     * @exception   E_CONNECTION_FAILED     The connection to the tag is closed or has failed.
     * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_SYSTEM                A system error has occurred.
     * @remarks     The NdefTagConnection class can inherit the TagConnection class if the currently detected tag
     *              supports the NDEF operations. To check whether the TagConnection class is inherited, use the
     *              TagConnection::IsNdefConnection() method.
     *              The specific error code can be accessed using the GetLastResult() method.
     */
    TagConnection* GetCurrentTagConnectionN(void) const;

    /**
     * Gets the NDEF message cached when the tag is detected.
     *
     * @since       2.0
     * @privlevel   NORMAL
     * @privgroup   NFC
     *
     * @return      The cached %NdefMessage instance, @n
     *              else @c null if the method is not successful
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_UNSUPPORTED_OPERATION The method has failed because the device does not support the NFC feature.
     * @exception   E_ILLEGAL_ACCESS        This operation is not allowed because the application is not launched by
     *                                      Conditional %App Launch.
     * @exception   E_INVALID_FORMAT        The cached data cannot be converted to the NDEF message.
     * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_SYSTEM                A system error has occurred.
     * @remarks     This method is available only to the application that is launched by Conditional %App Launch until
     *              the application is terminated or another tag is detected.
     *              The input NdefMessage instance should be deleted by the application after it is used, even outside
     *              this method. The NdefMessage::RemoveAllRecords() method should be called with @c true as the input
     *              value immediately before the NdefMessage instance is deleted.
     *              The specific error code can be accessed using the GetLastResult() method.
     * @see         <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/conditional_nfc_app_launch.htm">
     *              The Conditional NFC App Launch guide</a>
     * @see         Osp::App::AppManager::RegisterAppLaunch
     */
    static NdefMessage* GetCachedNdefMessageN(void);

    /**
     * Enables or disables the Conditional NFC %App Launch pop-up. @n
     * The pop-up includes all kinds of UI components that the system raises about NFC as well as a pop-up for
     * selecting the launching application when a tag is detected.
     *
     * @since       2.0
     * @privlevel   NORMAL
     * @privgroup   NFC
     *
     * @return      An error code
     * @param[in]   enable                  Set to @c true to enable the Conditional NFC %App Launch pop-up, @n
     *                                      else @c false
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_UNSUPPORTED_OPERATION The method has failed because the device does not support the NFC feature.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_SYSTEM                A system error has occurred.
     * @remarks     Note that this method is used to enable or disable the launch pop-up when the application is in the
     *              foreground. Although the application disables the launch pop-up by invoking this method, it is
     *              automatically enabled when the application goes to the background. The launch pop-up is enabled by
     *              default.
     * @see         <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/conditional_nfc_app_launch.htm">
     *              The Conditional NFC App Launch guide</a>
     */
    static result SetLaunchPopupEnabled(bool enable);

    /**
     * Adds the specified %INfcTagDiscoveryEventListener instance for the tag events with the specified tag type.
     *
     * @since       2.0
     * @privlevel   NORMAL
     * @privgroup   NFC
     *
     * @return      An error code
     * @param[in]   listener                The listener to be added
     * @param[in]   type                    The tag type for which the listener is added
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
     *                                      For example, this instance has not been constructed as yet.
     * @exception   E_OBJ_ALREADY_EXIST     The listener with the specified type is already added.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_SYSTEM                A system error has occurred.
     * @remarks     This method can be invoked several times with different Osp::Net::Nfc::NfcTagType values for the
     *              same listener instance. In this case, the listener is called if the specified type of the target
     *              tag matches with any one of the registered type.
     */
    result AddTagDiscoveryEventListener(const INfcTagDiscoveryEventListener& listener, NfcTagType type);

    /**
     * Removes the specified %INfcTagDiscoveryEventListener instance. @n
     * The removed listener cannot listen to the events that are fired.
     *
     * @since       2.0
     * @privlevel   NORMAL
     * @privgroup   NFC
     *
     * @return      An error code
     * @param[in]   listener                The listener to be removed
     * @param[in]   type                    The tag type for which the listener is removed
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
     *                                      For example, this instance has not been constructed as yet.
     * @exception   E_OBJ_NOT_FOUND         The listener with the specified type is not found.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_SYSTEM                A system error has occurred.
     */
    result RemoveTagDiscoveryEventListener(const INfcTagDiscoveryEventListener& listener, NfcTagType type);

    /**
     * Adds the specified %INdefMessageDiscoveryEventListener instance for the events related to an NDEF message that
     * includes the NDEF record with the specified type.
     *
     * @since       2.0
     * @privlevel   NORMAL
     * @privgroup   NFC
     *
     * @return      An error code
     * @param[in]   listener                The listener to be added
     * @param[in]   type                    The type of the NDEF record for which the listener is added
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
     *                                      For example, this instance has not been constructed as yet.
     * @exception   E_INVALID_ARG           The specified @c type is invalid. @n
     *                                      For example, the name of the record type is an empty string if the name
     *                                      format is NDEF_TNF_WELL_KNOWN, NDEF_TNF_MIME_MEDIA, NDEF_TNF_ABSOLUTE_URI,
     *                                      or NDEF_TNF_EXTERNAL.
     * @exception   E_OBJ_ALREADY_EXIST     The listener with the specified type is already added.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_SYSTEM                A system error has occurred.
     * @remarks     This method can be invoked several times with different NdefRecordType values for the same listener
     *              instance. In this case, the listener is called if the record type in the detected NDEF records
     *              matches with one of the registered types.
     *              In case of the MIME %Media type as Type Name Format (TNF), asterisks can be used in the type name
     *              for wildcard matching, such as @htmlonly "image&#47;*" @endhtmlonly.
     */
    result AddNdefMessageDiscoveryEventListener(const INdefMessageDiscoveryEventListener& listener, const NdefRecordType& type);

    /**
     * Removes the specified %INdefMessageDiscoveryEventListener instance. @n
     * The removed listener cannot listen to the events that are fired.
     *
     * @since       2.0
     * @privlevel   NORMAL
     * @privgroup   NFC
     *
     * @return      An error code
     * @param[in]   listener                The listener to be removed
     * @param[in]   type                    The type of the NDEF record for which the listener is removed
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
     *                                      For example, this instance has not been constructed as yet.
     * @exception   E_INVALID_ARG           The specified @c type is invalid. @n
     *                                      For example, the name of the record type is an empty string if the name
     *                                      format is NDEF_TNF_WELL_KNOWN, NDEF_TNF_MIME_MEDIA, NDEF_TNF_ABSOLUTE_URI,
     *                                      or NDEF_TNF_EXTERNAL.
     * @exception   E_OBJ_NOT_FOUND         The listener with the specified type is not found.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_SYSTEM                A system error has occurred.
     */
    result RemoveNdefMessageDiscoveryEventListener(const INdefMessageDiscoveryEventListener& listener, const NdefRecordType& type);

private:
    NfcManager(const NfcManager& value);
    NfcManager& operator =(const NfcManager& value);

private:
    __NfcManagerAgent*                  __pNfcManagerAgent;

    friend class __NfcManagerAgent;

};

} } } // Osp::Net::Nfc

#endif // _FNET_NFC_NFC_MANAGER_H_
