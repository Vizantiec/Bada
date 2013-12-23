/* $Change: 880962 $ */
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
 * @file    FNetNfcNdefTagConnection.h
 * @brief   This is the header file for the %NdefTagConnection class.
 *
 * This header file contains the declarations of the %NdefTagConnection class.
 */

#ifndef _FNET_NFC_NDEF_TAG_CONNECTION_H_
#define _FNET_NFC_NDEF_TAG_CONNECTION_H_

#include "FNetConfig.h"
#include "FBaseResult.h"
#include "FNetNfcTagConnection.h"

namespace Osp { namespace Net { namespace Nfc {

// Forward declaration
class __NdefTagConnectionImpl;
class NdefMessage;
class INdefTagConnectionListener;

/**
 * @class    NdefTagConnection
 * @brief    This class represents the connection with an NFC tag that has the NDEF data.
 * @since    2.0
 *
 * The %NdefTagConnection class provides the mechanism to communicate with the tag that has NFC Data Exchange Format (NDEF) data and
 * supports the NDEF message operations. @n
 * This class can be derived from the TagConnection class. Use the IsNdefConnection() method to check the availability
 * of the derivation. @n
 * Use the Read() and Write() methods to read and write the NDEF data. After the completion of the read and write
 * operations, the response is received by the INdefTagConnectionListener::OnNdefReadCompletedN() and
 * INdefTagConnectionListener::OnNdefWriteCompleted() event handlers, respectively.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/nfc.htm">NFC Guide</a>.
 *
 * The following example demonstrates how to use the %NdefTagConnection class.
 * @code
 * // MyClass.h
 * #include <FNet.h>
 *
 * class MyClass :
 *            public Osp::Net::Nfc::INfcManagerEventListener,
 *            public Osp::Net::Nfc::INfcTagDiscoveryEventListener,
 *            public Osp::Net::Nfc::INdefTagConnectionListener
 * {
 * public:
 *      void WriteNdefMessageSample(void);
 *      virtual void OnNfcTagDetectedN(Osp::Net::Nfc::TagConnection* pConnection);
 *      virtual void OnNfcTagLost(void);
 *      virtual void OnNdefWriteCompleted(result r);
 *      // Other methods are hidden for the sake of simplicity.
 *
 * private:
 *      Osp::Net::Nfc::NfcManager*            __pNfcManager;
 *      Osp::Net::Nfc::NdefTagConnection*     __pNdefConnection;
 * };
 *
 * // MyClass.cpp
 * #include "MyClass.h"
 *
 * using namespace Osp::Net::Nfc;
 *
 * MyClass::MyClass(void) : __pNfcManager(null), __pNdefConnection(null)
 * {
 *      __pNfcManager = new NfcManager();
 * }
 *
 * MyClass::~MyClass(void)
 * {
 *      // Removes the tag discovery event listener for all the NDEF tag types.
 *      __pNfcManager->RemoveTagDiscoveryEventListener(*this, NFC_TAG_TYPE_ALL_NDEF_COMPATIBLE);
 *
 *      delete __pNfcManager;
 * }
 *
 * void
 * MyClass::WriteNdefMessageSample(void)
 * {
 *      // Creates NfcManager instance and registers the manager event listener.
 *      __pNfcManager->Construct(*this);
 *
 *      // Adds the tag discovery event listener for all the NDEF tag types.
 *      __pNfcManager->AddTagDiscoveryEventListener(*this, NFC_TAG_TYPE_ALL_NDEF_COMPATIBLE);
 * }
 *
 * // This method is invoked when a new NDEF tag is detected.
 * void
 * MyClass::OnNfcTagDetectedN(TagConnection* pConnection)
 * {
 *      // Checks whether the connection supports NDEF operations,
 *      // but the evaluation result of the below code is always true in this example.
 *      if (pConnection->IsNdefConnection())
 *      {
 *          __pNdefConnection = dynamic_cast<NdefTagConnection*>(pConnection);
 *
 *          // Registers the NDEF tag connection listener.
 *          __pNdefConnection->SetNdefTagConnectionListener(this);
 *
 *          NdefMessage message;
 *          // Fill up the NdefMessage object here.
 *
 *          __pNdefConnection->Write(message);
 *      }
 * }
 *
 * // This method is invoked when the target tag is lost.
 * void
 * MyClass::OnNfcTagLost(void)
 * {
 *      // The acquired NdefTagConnection should be deallocated.
 *      delete __pNdefConnection;
 * }
 *
 * // This method is invoked when the write request is completed.
 * void
 * MyClass::OnNdefWriteCompleted(result r)
 * {
 *      if (r == E_SUCCESS)
 *      {
 *          // Writing NdefMessage is successful.
 *      }
 * }
 * @endcode
 */
class _EXPORT_NET_ NdefTagConnection : public TagConnection
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
     * Sets a listener for receiving the result of reading or writing on this NDEF tag connection.
     *
     * @since       2.0
     *
     * @return      An error code
     * @param[in]   pListener           The listener to be added
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @remarks     At the most, one event listener can be registered. If the input parameter is @c null, the listener
     *              that is currently registered gets unregistered.
     */
    result SetNdefTagConnectionListener(const INdefTagConnectionListener* pListener);

    /**
     * Reads the NDEF data from the NDEF tag.
     *
     * @since       2.0
     *
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_IN_PROGRESS       The read process is in progress.
     * @exception   E_CONNECTION_BUSY   The connection is busy. Therefore, the method cannot process the read request.
     * @exception   E_CONNECTION_FAILED The connection to the tag is closed or it has failed.
     * @exception   E_SYSTEM            A system error has occurred.
     * @see         INdefTagConnectionListener::OnNdefReadCompletedN()
     */
    result Read(void);

    /**
     * Writes the NDEF data to the NDEF tag.
     *
     * @since       2.0
     *
     * @return      An error code
     * @param[in]   message             The NDEF message to be written to the target
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_ARG       The input @c message is invalid. @n
     *                                  For example, it does not contain any NDEF records.
     * @exception   E_IN_PROGRESS       The write process is in progress.
     * @exception   E_CONNECTION_BUSY   The connection is busy. Therefore, the method cannot process the write request.
     * @exception   E_CONNECTION_FAILED The connection to the tag is closed or it has failed.
     * @exception   E_SYSTEM            A system error has occurred.
     * @see         INdefTagConnectionListener::OnNdefWriteCompleted()
     */
    result Write(const NdefMessage& message);

    /**
     * This is the destructor for this class.
     *
     * @since       2.0
     */
    virtual ~NdefTagConnection(void);

private:
    /*
     * Initializes this instance of NdefTagConnection with the specified parameter.
     */
    NdefTagConnection(const NfcTag& target);

    NdefTagConnection(void);
    NdefTagConnection(const NdefTagConnection& value);
    NdefTagConnection& operator =(const NdefTagConnection& value);

private:
    __NdefTagConnectionImpl*                    __pNdefImpl;

friend class __TagConnectionImpl;
friend class __NdefTagConnectionImpl;

};

} } } // Osp::Net::Nfc

#endif // _FNET_NFC_NDEF_TAG_CONNECTION_H_

