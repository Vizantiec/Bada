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
 * @file    FNetNfcNdefMessage.h
 * @brief   This is the header file for the %NdefMessage class.
 *
 * This header file contains the declarations of the %NdefMessage class.
 */

#ifndef _FNET_NFC_NDEF_MESSAGE_H_
#define _FNET_NFC_NDEF_MESSAGE_H_

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
class __NdefMessageImpl;
class NdefRecord;

/**
 * @class   NdefMessage
 * @brief   This class represents an NDEF message.
 * @since   2.0
 *
 * The %NdefMessage class represents an NDEF message. An NDEF message is composed of 1 or more NDEF records. Therefore, this class
 * has NdefRecord instances and provides the operations to manipulate the list of those instances. These operations are
 * very similar to those of the Osp::Base::Collection::IList class.
 *
 * If a new NDEF record is inserted, the uniqueness of its payload identifier is checked. This class also provides
 * methods which convert %NdefMessage to Osp::Base::ByteBuffer and vice versa.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/nfc.htm">NFC Guide</a>.
 */
class _EXPORT_NET_ NdefMessage : public Osp::Base::Object
{

public:
    /**
     * This is the default constructor for this class.
     *
     * @since       2.0
     */
    NdefMessage(void);

    /**
     * This is copy constructor for the %NdefMessage class. @n
     * Initializes this instance of %NdefMessage with the specified parameters.
     *
     * @since       2.0
     *
     * @param[in]   value               An instance of %NdefMessage
     * @remarks     This performs a deep copy.
     */
    NdefMessage(const NdefMessage& value);

    /**
     * This is the destructor for this class.
     *
     * @since       2.0
     */
    ~NdefMessage(void);

    /**
     * Gets the number of NDEF records in this NDEF message.
     *
     * @since       2.0
     *
     * @return      The number of NDEF records
     */
    int GetRecordsCount(void) const;

    /**
     * Searches for an NdefRecord object in this class. @n
     * Gets the index of the NdefRecord object if the record is present.
     *
     * @since       2.0
     *
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_OBJ_NOT_FOUND     The specified record is not found.
     * @remarks     This method verifies the equality of its pointers, but does not check the content of the specified
     *              record.
     */
    result IndexOf(const NdefRecord& record, int& index) const;

    /**
     * Gets the NdefRecord object from the specified location.
     *
     * @since       2.0
     *
     * @return      The requested NdefRecord object, @n
     *              else @c null if the index is not valid
     * @param[in]   index               The index of the NDEF record to get
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_OUT_OF_RANGE      The specified index is outside the bounds of the record list. @n
     *                                  The specified @c index parameter is either greater than or equal to the number
     *                                  of elements or less than @c 0.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    NdefRecord* GetRecordAt(int index) const;

    /**
     * Gets the NdefRecord object with the specified payload identifier.
     *
     * @since       2.0
     *
     * @return      The requested NdefRecord object, @n
     *              else @c null if no record matches
     * @param[in]   payloadId           The payload identifier of the NDEF record to get
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_OBJ_NOT_FOUND     The specified @c id is not found in any of the NDEF records.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    NdefRecord* GetRecord(const Osp::Base::String& payloadId) const;

    /**
     * Appends the specified NDEF record at the end of the last record in the NDEF message.
     *
     * @since       2.0
     *
     * @return      An error code
     * @param[in]   record              The NDEF record to be appended
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_ARG       The specified NDEF record is invalid. @n
     *                                  For example, the record has the same payload identifier as the other records in
     *                                  this NDEF message.
     * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
     * @remarks     This method performs a shallow copy. It adds just the pointer, not the NdefRecord instance.
     */
    result AppendRecord(const NdefRecord& record);

    /**
     * Inserts the specified NDEF record in the NDEF message at the specified location.
     *
     * @since       2.0
     *
     * @return      An error code
     * @param[in]   record              The NDEF record to be inserted
     * @param[in]   index               The index at which the NDEF record should be inserted
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_OUT_OF_RANGE      The specified index is outside the bounds of the record list. @n
     *                                  The specified @c index is greater than the number of elements or less than
     *                                  @c 0.
     * @exception   E_INVALID_ARG       The specified NDEF record is invalid. @n
     *                                  For example, the record has the same payload identifier as the other records in
     *                                  this NDEF message.
     * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
     * @remarks     The NDEF records that appear after the insertion point move downwards to accommodate the inserted
     *              NDEF record.
     *              This method performs a shallow copy. It adds just the pointer, not the NdefRecord instance.
     */
    result InsertRecordAt(const NdefRecord& record, int index);

    /**
     * Replaces the NDEF record from the specified location with the specified NDEF record.
     *
     * @since       2.0
     *
     * @return      An error code
     * @param[in]   record              The NDEF record to be set
     * @param[in]   index               The index at which the NDEF record is to be set
     * @param[in]   deallocate          Set to @c true to deallocate the replaced record, @n
     *                                  else @c false
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_OUT_OF_RANGE      The specified index is outside the bounds of the record list. @n
     *                                  The specified @c index is either equal to or greater than the number of
     *                                  elements or less than @c 0.
     * @exception   E_INVALID_ARG       The specified NDEF record is invalid. @n
     *                                  For example, the record has the same payload identifier as the other records in
     *                                  this NDEF message.
     * @remarks     This method performs a shallow copy. It adds just the pointer, not the NdefRecord instance.
     */
    result SetRecordAt(const NdefRecord& record, int index, bool deallocate = false);

    /**
     * Removes the NDEF record from a specified location.
     *
     * @since       2.0
     *
     * @return      An error code
     * @param[in]   index               The index from where the NDEF record is removed
     * @param[in]   deallocate          Set to @c true to deallocate the record, @n
     *                                  else @c false
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_OUT_OF_RANGE      The specified index is outside the bounds of the record list. @n
     *                                  The specified @c index is either equal to or greater than the number of
     *                                  elements or less than @c 0.
     * @remarks     The NDEF records that appear after the deletion point move upwards to occupy the vacated spot.
     */
    result RemoveRecordAt(int index, bool deallocate = false);

    /**
     * Removes all the records in the NDEF message. @n
     * If the specified @c deallocate parameter is set to @c true, it deallocates all the NdefRecord instances in the
     * message.
     *
     * @since       2.0
     *
     * @param[in]   deallocate          Set to @c true to deallocate the record, @n
     *                                  else @c false
     */
    void RemoveAllRecords(bool deallocate = false);

    /**
     * Converts the entire NDEF message with all the NDEF records into a byte sequence as per the NDEF specification.
     *
     * @since       2.0
     *
     * @return      The NDEF message as a ByteBuffer, @n
     *              else @c null if the conversion fails
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_DATA      The specified NDEF message does not contain any NDEF records.
     * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
     * @exception   E_SYSTEM            A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    Osp::Base::ByteBuffer* ToByteBufferN(void) const;

    /**
     * Gets a new instance of the NDEF message from the specified ByteBuffer.
     *
     * @since       2.0
     *
     * @return      The instance of the created NDEF message, @n
     *              else @c null if the conversion fails
     * @param[in]   buffer              An NDEF message as a byte sequence
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_FORMAT    The specified @c buffer cannot be formulated to the NDEF message.
     * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
     * @exception   E_SYSTEM            A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    static NdefMessage* GetInstanceN(const Osp::Base::ByteBuffer& buffer);

private:
    NdefMessage& operator =(const NdefMessage& value);

private:
    __NdefMessageImpl*                  __pImpl;

    friend class __NdefMessageImpl;

};

} } } // Osp::Net::Nfc

#endif // _FNET_NFC_NDEF_MESSAGE_H_

