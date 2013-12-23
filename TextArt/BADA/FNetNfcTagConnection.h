/* $Change: 884473 $ */
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
 * @file    FNetNfcTagConnection.h
 * @brief   This is the header file for the %TagConnection class.
 *
 * This header file contains the declarations of the %TagConnection class.
 */

#ifndef _FNET_NFC_TAG_CONNECTION_H_
#define _FNET_NFC_TAG_CONNECTION_H_

#include "FNetConfig.h"
#include "FBaseObject.h"
#include "FBaseResult.h"

// Forward declaration
namespace Osp { namespace Base {
class ByteBuffer;
}}

namespace Osp { namespace Net { namespace Nfc {

// Forward declaration
class NfcTag;
class __TagConnectionImpl;
class ITagConnectionListener;

/**
 * @class   TagConnection
 * @brief   This class represents the connection with an NFC tag. It provides the mechanism to communicate with the NFC
 *          tag through ISO14443 or a general Radio Frequency Identification (RFID) manner.
 * @since   2.0
 *
 * The %TagConnection class represents the connection with an NFC tag. It provides the mechanism to communicate with the NFC tag
 * through ISO14443 or a general Radio Frequency Identification (RFID) manner. @n
 * The class has an NfcTag instance that represents the target tag. This class can be inherited by the
 * NdefTagConnection class if the target tag supports the NFC Data Exchange Format (NDEF) operations.
 * 
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/nfc.htm">NFC Guide</a>.
 *
 * The following example demonstrates how to use the %TagConnection class.
 *
 * @code
 * // MyClass.h
 * #include <FNet.h>
 *
 * class MyClass :
 *            public Osp::Net::Nfc::INfcManagerEventListener,
 *            public Osp::Net::Nfc::INfcTagDiscoveryEventListener,
 *            public Osp::Net::Nfc::ITagConnectionListener
 * {
 * public:
 *      // Method declarations are hidden for the sake of simplicity.
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
 *      // Removes the tag discovery event listener for the ISO14443-4 tag type.
 *      __pNfcManager->RemoveTagDiscoveryEventListener(*this, NFC_TAG_TYPE_ISO14443_4);
 *
 *      delete __pNfcManager;
 * }
 *
 * void
 * MyClass::SendApduCommandSample(void)
 * {
 *      // Creates an instance of NfcManager and registers the manager event listener.
 *      __pNfcManager->Construct(*this);
 *
 *      // Adds the tag discovery event listener for the ISO14443-4 tag type.
 *      __pNfcManager->AddTagDiscoveryEventListener(*this, NFC_TAG_TYPE_ISO14443_4);
 * }
 *
 * // This method is invoked when a new ISO14443-4 tag like a Mifare DESFire is detected.
 * void
 * MyClass::OnNfcTagDetectedN(TagConnection* pConnection)
 * {
 *      // Checks whether the connection supports ISO14443-4,
 *      // but the evaluation result of the below code is always true in this example.
 *      if (pConnection->GetTargetTag()->HasTagType(NFC_TAG_TYPE_ISO14443_4))
 *      {
 *          __pConnection = pConnection;
 *
 *          // Registers the tag connection listener.
 *          __pConnection->SetTagConnectionListener(this);
 *
 *          Osp::Base::ByteBuffer command;
 *          // Makes an APDU(ISO7816-4) command here.
 *
 *          __pConnection->SendCommand(command);
 *      }
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
 * // This method is invoked when the response of the command is received.
 * void
 * MyClass::OnNfcResponseReceivedN(Osp::Base::ByteBuffer* pResponse, result r)
 * {
 *      if (r == E_SUCCESS)
 *      {
 *          // Use the response data here.
 *
 *          // Deallocate the response data.
 *          delete pResponse;
 *      }
 * }
 * @endcode
 */
class _EXPORT_NET_ TagConnection : public Osp::Base::Object
{

public:
    /**
     * Checks whether the connection supports the NDEF message operations.
     *
     * @since       2.0
     *
     * @return      @c true if the connection supports the NDEF message operations, @n
     *              else @c false
     */
    virtual bool IsNdefConnection(void) const;

    /**
     * Gets the target tag object with which this connection is established.
     *
     * @since       2.0
     *
     * @return      The tag object
     */
    const NfcTag* GetTargetTag(void) const;

    /**
     * Sets a listener for receiving the response of the command sent on this tag connection.
     *
     * @since       2.0
     *
     * @return      An error code
     * @param[in]   pListener           The listener to be added
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @remarks     Only one event listener can be registered. If the input parameter is @c null, the listener that is
     *              already registered gets unregistered.
     */
    result SetTagConnectionListener(const ITagConnectionListener* pListener);

    /**
     * Sends the specified command to the target tag.
     *
     * @since       2.0
     *
     * @return      An error code
     * @param[in]   command             The command to be sent
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_ARG       The input @c command is invalid.
     * @exception   E_IN_PROGRESS       The previous send request is in progress.
     * @exception   E_CONNECTION_BUSY   The connection is busy. Therefore, the method cannot process the send request.
     * @exception   E_CONNECTION_FAILED The connection to the tag is closed or it has failed.
     * @exception   E_SYSTEM            A system error has occurred.
     * @see         ITagConnectionListener::OnNfcResponseReceivedN()
     */
    result SendCommand(const Osp::Base::ByteBuffer &command);

    /**
     * This is the destructor for this class.
     *
     * @since       2.0
     */
    virtual ~TagConnection(void);

protected:
    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * This is a constructor for this class.
     *
     * @since       2.0
     */
    TagConnection(const NfcTag& target);

    // reserved virtual methods for later extension
    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of methods can be changed at any time without prior notice.
     *
     * @since       2.0
     */
    virtual void TagConnection_Reserved1 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of methods can be changed at any time without prior notice.
     *
     * @since       2.0
     */
    virtual void TagConnection_Reserved2 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of methods can be changed at any time without prior notice.
     *
     * @since       2.0
     */
    virtual void TagConnection_Reserved3 (void) {}

private:
    TagConnection(void);
    TagConnection(const TagConnection& value);
    TagConnection& operator =(const TagConnection& value);

protected:
    /**
     * @internal
     * This variable is for internal use only. The bada platform team is not responsible for any behavioral
     * correctness, consistency, and security-related issues that might arise after using this variable.
     *
     * The point for indicating the implementation object.
     *
     * @since       2.0
     */
    __TagConnectionImpl*                __pImpl;

friend class __TagConnectionImpl;

};

} } } // Osp::Net::Nfc

#endif // _FNET_NFC_TAG_CONNECTION_H_

