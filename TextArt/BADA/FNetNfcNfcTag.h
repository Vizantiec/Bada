/* $Change: 874088 $ */
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
 * @file    FNetNfcNfcTag.h
 * @brief   This is the header file for the %NfcTag class.
 *
 * This header file contains the declarations of the %NfcTag class.
 */

#ifndef _FNET_NFC_NFC_TAG_H_
#define _FNET_NFC_NFC_TAG_H_

#include "FNetConfig.h"
#include "FBaseObject.h"
#include "FBaseResult.h"
#include "FNetNfcNfcTypes.h"

// Forward declaration
namespace Osp { namespace Base {
class ByteBuffer;
namespace Collection {
template<class Type> class IListT;
}}}

namespace Osp { namespace Net { namespace Nfc {

// Forward declaration
class __NfcTagImpl;

/**
 * @class   NfcTag
 * @brief   This class represents the NFC target tag.
 * @since   2.0
 *
 * The %NfcTag class provides information about the detected NFC tag. @n
 * This class has multiple tag types for the target tag. For example, the GetTagTypeList() method returns a list of tag
 * types that include NFC_TAG_TYPE_MIFARE_UL and NFC_TAG_TYPE_FORUM_TYPE_2, because the tag is a Mifare Ultralight tag
 * and it is also an NFC Forum tag type 2.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/nfc.htm">NFC Guide</a>.
 */
class _EXPORT_NET_ NfcTag : public Osp::Base::Object
{

public:
    /**
     * Gets the list of the tag types.
     *
     * @since       2.0
     *
     * @return      The list of the tag types
     * @remarks     The return list includes single or multiple tags. For example, if the target tag is Mifare
     *              Ultralight tag type and the NFC Forum tag 2 type, the list includes NFC_TAG_TYPE_MIFARE_UL and
     *              NFC_TAG_TYPE_FORUM_TYPE_2.
     */
    const Osp::Base::Collection::IListT<NfcTagType>* GetTagTypeList(void) const;

    /**
     * Checks whether the tag has the specified tag type.
     *
     * @since       2.0
     *
     * @return      @c true if the tag has the specified tag type, @n
     *              else @c false
     * @param[in]   type                The tag type to be checked
     */
    bool HasTagType(NfcTagType type) const;

    /**
     * Gets the ID of the tag.
     *
     * @since       2.0
     *
     * @return      The ID of the tag, @n
     *              else @c null if the tag has no ID
     * @remarks     Most tags have an unique ID (UID) or a random ID (RID) that is generated every time when they are
     *              discovered. Some tags, however, do not have any ID.
     */
    const Osp::Base::ByteBuffer* GetId(void) const;

    /**
     * This is the destructor for this class.
     *
     * @since       2.0
     */
    virtual ~NfcTag(void);

private:
    /*
     * This is a constructor for this class.
     */
    NfcTag(const Osp::Base::ByteBuffer* pId, const Osp::Base::Collection::IListT<NfcTagType>& types);

    NfcTag(void);
    NfcTag(const NfcTag& value);
    NfcTag& operator =(const NfcTag& value);

private:
    __NfcTagImpl*                   __pImpl;

friend class __NfcTagImpl;

};

} } } // Osp::Net::Nfc

#endif // _FNET_NFC_NFC_TAG_H_

