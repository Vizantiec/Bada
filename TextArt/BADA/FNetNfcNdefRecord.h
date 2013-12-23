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
 * @file    FNetNfcNdefRecord.h
 * @brief   This is the header file for the %NdefRecord class.
 *
 * This header file contains the declarations of the %NdefRecord class.
 */

#ifndef _FNET_NFC_NDEF_RECORD_H_
#define _FNET_NFC_NDEF_RECORD_H_

#include "FNetConfig.h"
#include "FBaseObject.h"
#include "FBaseResult.h"

// Forward declaration
namespace Osp { namespace Base {
class ByteBuffer;
class String;
}}

namespace Osp { namespace Net { namespace Nfc {

// Forward declaration
class __NdefRecordImpl;
class NdefMessage;
class NdefRecordType;

/**
 * @class   NdefRecord
 * @brief   This class represents an NDEF record.
 * @since   2.0
 *
 * The %NdefRecord class represents an NDEF record, including certain attributes such as the type, the payload, and the payload
 * identifier. It provides the operations to manipulate them. However, this class does not expose all the attributes of
 * an NDEF record. Some attributes defined in the NDEF specification are hidden because they are not important for
 * applications. @n
 * The NDEF record may contain an NDEF message in the payload. It can be converted from an Osp::Base::ByteBuffer
 * instance to an NdefMessage instance through the NdefMessage::GetInstanceN() method.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/nfc.htm">NFC Guide</a>.
 */
class _EXPORT_NET_ NdefRecord : public Osp::Base::Object
{

public:
    /**
     * Initializes this instance of %NdefRecord with the specified parameter.
     *
     * @since       2.0
     *
     * @param[in]   recordType      A specified NDEF record type
     */
    NdefRecord(const NdefRecordType& recordType);

    /**
     * This is the copy constructor for the %NdefRecord class. @n
     * Initializes this instance of %NdefRecord with the specified parameter.
     *
     * @since       2.0
     *
     * @param[in]   value           An instance of %NdefRecord
     * @remarks     It performs a deep copy.
     */
    NdefRecord(const NdefRecord& value);

    /**
     * This is the destructor for this class.
     *
     * @since       2.0
     */
    ~NdefRecord(void);

    /**
     * Gets the payload identifier for this NDEF record.
     *
     * @since       2.0
     *
     * @return      The identifier of the payload, @n
     *              else an empty string if the identifier does not exist in the NDEF record
     */
    Osp::Base::String GetPayloadId(void) const;

    /**
     * Gets the payload in this record as ByteBuffer.
     *
     * @since       2.0
     *
     * @return      The payload, @n
     *              else @c null if the NDEF record does not have the payload
     * @remarks     If the payload is modified after it is fetched, the payload of this record also changes.
     */
    Osp::Base::ByteBuffer* GetPayload(void) const;

    /**
     * Gets the record type of the NDEF record.
     *
     * @since       2.0
     *
     * @return      The record type of the NDEF record
     */
    NdefRecordType GetRecordType(void) const;

    /**
     * Sets the record type of the NDEF record.
     *
     * @since       2.0
     *
     * @return      An error code
     * @param[in]   type                The record type to be set
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_ARG       The input argument is invalid. @n
     *                                  For example, NDEF_TNF_EMPTY is not allowed as the input value if the identifier
     *                                  is not an empty string or the payload is not @c null.
     */
    result SetRecordType(NdefRecordType& type);

    /**
     * Sets the identifier of the payload.
     *
     * @since       2.0
     *
     * @return      An error code
     * @param[in]   id                          The identifier of the payload
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_OPERATION         This operation is not allowed if the type name format of this record is
     *                                          NDEF_TNF_EMPTY.
     * @exception   E_INVALID_ARG               The specified identifier is not unique compared to the other records in
     *                                          the same NDEF message.
     * @exception   E_INVALID_ENCODING_RANGE    The specified input string contains code points that are outside the
     *                                          bounds specified by the US_ASCII encoding scheme.
     * @exception   E_MAX_EXCEEDED              The length of @c id exceeds @c 256 characters.
     * @remarks     The identifier is compared with other records only if this NDEF record is already included in an
     *              NDEF message.
     */
    result SetPayloadId(const Osp::Base::String& id);

    /**
     * Sets the specified data in the payload of this NDEF record.
     *
     * @since       2.0
     *
     * @return      An error code
     * @param[in]   payload                 The specified payload data
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_OPERATION     This operation is not allowed if the type name format of this record is
     *                                      NDEF_TNF_EMPTY.
     * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
     * @exception   E_INVALID_ARG           The @c payload is invalid. @n
     *                                      For example, @c payload is not constructed.
     * @remarks     The view of the specified @c payload parameter is copied and the data is shared. Therefore, if the
     *              data of @c payload is modified after setting, the data of the payload in this record also changes.
     */
    result SetPayload(const Osp::Base::ByteBuffer& payload);

private:
    NdefRecord(void);
    NdefRecord& operator =(const NdefRecord& value);

private:
    __NdefRecordImpl*                __pImpl;

friend class __NdefRecordImpl;

};

} } } // Osp::Net::Nfc

#endif // _FNET_NFC_NDEF_RECORD_H_

