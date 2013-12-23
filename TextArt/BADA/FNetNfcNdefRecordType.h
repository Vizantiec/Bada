/* $Change: 919503 $ */
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
 * @file    FNetNfcNdefRecordType.h
 * @brief   This is the header file for the %NdefRecordType class.
 *
 * This header file contains the declarations of the %NdefRecordType class.
 */

#ifndef _FNET_NFC_NDEF_RECORD_TYPE_H_
#define _FNET_NFC_NDEF_RECORD_TYPE_H_

#include "FNetConfig.h"
#include "FBaseObject.h"
#include "FBaseString.h"
#include "FNetNfcNfcTypes.h"

// Forward declaration
namespace Osp { namespace Base {
class String;
}}

namespace Osp { namespace Net { namespace Nfc {

// Forward declaration
class __NdefRecordTypeImpl;

/**
 * Defines the NDEF RTD Smart Poster type.
 *
 * @since   2.0
 */
static const Osp::Base::String NDEF_RTD_SMART_POSTER = L"Sp";

/**
 * Defines the NDEF RTD %Text type.
 *
 * @since   2.0
 */
static const Osp::Base::String NDEF_RTD_TEXT = L"T";

/**
 * Defines the NDEF RTD URI type.
 *
 * @since   2.0
 */
static const Osp::Base::String NDEF_RTD_URI = L"U";

/**
 * @class   NdefRecordType
 * @brief   This class represents the type of an NDEF record.
 * @since   2.0
 *
 * The %NdefRecordType class represents the type of an NDEF record. It encapsulates the name and the name format of the NDEF record
 * type. @n
 * The name format is represented by the enumeration type, Osp::Net::Nfc::NdefRecordTypeNameFormat. The name is encoded
 * using the US_ASCII character set and follows the rules defined by the NFC forum RTDs and RFCs. The name does not
 * include the prefix @c "urn:nfc:wkt:" and @c "urn:nfc:ext:" defined by the NFC forum.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/nfc.htm">NFC Guide</a>.
 */

class _EXPORT_NET_ NdefRecordType : public Osp::Base::Object
{

public:
    /**
     * This is the default constructor for this class. @n
     * Initializes this instance of %NdefRecordType with the specified parameter.
     *
     * @since       2.0
     *
     * @param[in]   format          The NDEF record type name format
     */
    NdefRecordType(NdefRecordTypeNameFormat format = NDEF_TNF_EMPTY);

    /**
     * This is the copy constructor for the %NdefRecordType class with the specified %NdefRecordType.
     *
     * @since       2.0
     *
     * @param[in]   recordType      An instance of %NdefRecordType
     */
    NdefRecordType(const NdefRecordType& recordType);

    /**
     * This is the destructor for this class.
     *
     * @since       2.0
     */
    ~NdefRecordType(void);

    /**
     * Assigns the value of the specified instance of %NdefRecordType to the current instance of %NdefRecordType.
     *
     * @since       2.0
     *
     * @param[in]   rhs             An instance of %NdefRecordType
     */
    NdefRecordType& operator =(const NdefRecordType& rhs);

    /**
     * Compares the specified instance of an Object with the calling instance of %NdefRecordType.
     *
     * @since       2.0
     *
     * @return      @c true if the values match, @n
     *              else @c false
     * @param[in]   obj             The Object to be compared
     * @remarks     The method returns @c false if the specified object is not an %NdefRecordType instance. @n
     *              Additionally, the comparison rules for the record type name are different depending on the Type
     *              Name Format (TNF) value, as follows: @n
     * <table border=1 cellpadding="1" cellspacing="1">
     * <tr>
     *      <th>Type Name Format (TNF) value</th>
     *      <th>The comparison rule for the record type name</th>
     * </tr>
     * <tr>
     *      <td>NDEF_TNF_WELL_KNOWN</td>
     *      <td>Compares a name, character by character in a case-sensitive manner </td>
     * </tr>
     * <tr>
     *      <td>NDEF_TNF_MIME_MEDIA </td>
     *      <td>Compares a name, character by character in a case-insensitive manner until the first semi-colon (;)
     *      appears </td>
     * </tr>
     * <tr>
     *      <td>NDEF_TNF_ABSOLUTE_URI </td>
     *      <td>The reserved characters must be percent encoded and the hexadecimal digits are normalized to upper-case
     *      letters. The URI scheme and host parts of the URI must be normalized to lower case. After this, the URIs
     *      are compared character by character in a case-sensitive manner. </td>
     * </tr>
     * <tr>
     *      <td>NDEF_TNF_EXTERNAL </td>
     *      <td>Compares a name, character by character in a case-insensitive manner </td>
     * </tr>
     * <tr>
     *      <td>NDEF_TNF_EMPTY | NDEF_TNF_UNKNOWN </td>
     *      <td>Both record type names must be empty </td>
     * </tr>
     * </table>
     */
    virtual bool Equals(const Osp::Base::Object& obj) const;

    /**
     * Gets the hash value of the current instance.
     *
     * @since       2.0
     *
     * @return      The hash value of the current instance
     * @remarks     The two equal %NdefRecordType instances return the same hash value.
     */
    virtual int GetHashCode(void) const;

    /**
     * Gets the name format of this record type.
     *
     * @since       2.0
     *
     * @return      The name format of this record type
     */
    NdefRecordTypeNameFormat GetNameFormat(void) const;

    /**
     * Gets the name of this record type.
     *
     * @since       2.0
     *
     * @return      The name of this record type, @n
     *              else an empty string if the name format is NDEF_TNF_EMPTY or NDEF_TNF_UNKNOWN
     * @remarks     The returned name does not have the prefix @c "urn:nfc:wkt:" and @c "urn:nfc:ext:" defined by the
     *              NFC forum.
     *              In case of NDEF_TNF_ABSOLUTE_URI name format, this method returns the name in the same format as it
     *              is given in the constructor, that is, with or without percent encoding. The name consists of the
     *              characters encoded using the US_ASCII character set.
     */
    Osp::Base::String GetName(void) const;

    /**
     * Sets the name of this record type.
     *
     * @since       2.0
     *
     * @return      An error code
     * @param[in]   name                        The name of this record type
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_OPERATION         This operation is not allowed if the name format is NDEF_TNF_EMPTY,
     *                                          NDEF_TNF_UNKNOWN, or NDEF_TNF_ALL.
     * @exception   E_INVALID_ENCODING_RANGE    The specified input string contains the code points that are outside
     *                                          the bounds specified by the US_ASCII encoding scheme.
     * @exception   E_INVALID_FORMAT            The specified format of the @c name is invalid as per the
     *                                          specifications defined for each type of the name format.
     * @exception   E_MAX_EXCEEDED              The length of the name exceeds @c 256 characters.
     * @remarks     The input name must not have the prefix defined by the NFC forum such as @c "urn:nfc:wkt:" and
     *              @c "urn:nfc:ext:".
     */
    result SetName(const Osp::Base::String& name);

private:
    __NdefRecordTypeImpl*                       __pImpl;

    friend class __NdefRecordTypeImpl;

};

} } } // Osp::Net::Nfc

#endif // _FNET_NFC_NDEF_RECORD_TYPE_H_

