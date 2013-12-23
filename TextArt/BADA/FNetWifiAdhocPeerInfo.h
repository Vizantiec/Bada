/* $Change: 1144988 $ */
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
 * @file	FNetWifiAdhocPeerInfo.h 
 * @brief	This is the header file for the %AdhocPeerInfo class.
 *
 * This header file contains the declarations of the %AdhocPeerInfo class.
 */

#ifndef _FNET_WIFI_ADHOCPEERINFO_H_
#define _FNET_WIFI_ADHOCPEERINFO_H_


#include "FBase.h"
#include "FNet.h"

namespace Osp {
    namespace Net {
        namespace Wifi {


// Forward declaration for class extension.
class AdhocPeerInfoEx;

/**
 * @class		AdhocPeerInfo 
 * @brief		This class represents a base type for the information on the ad hoc neighbor peer.
 * @deprecated 	This class is deprecated. Instead of using this class, it is recommended to use classes related with Wi-Fi Direct.
 * @since		1.0
 *
 * 	The %AdhocPeerInfo class provides the methods for getting information on a neighboring peer. %AdhocPeerInfo can be obtained from the GetNeighborsN() 
 *			method. 
 *
 */

class _EXPORT_NET_ AdhocPeerInfo
	: public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * This is the default constructor for this class.
	 *
	 * @since 		1.0
	 */
	AdhocPeerInfo(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 		1.0
	 */
	~AdhocPeerInfo(void);


// Operations
public:
	
	/** 
	 * Gets the peer name.
	 *
	 * @since 		1.0
	 * @return		The peer name
	 */
	Osp::Base::String GetName(void) const;

	/** 
	 * Gets the IpAddress of the peer.
	 *
	 * @since 		1.0
	 * @return		The IpAddress of the peer
	 */
	const Osp::Net::IpAddress* GetAddress(void) const;

protected:
	/** 
	 * @internal 
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Sets the peer name.
	 *
	 * @since 		1.0
	 */ 
	bool SetName(Osp::Base::String name);

	/**
	 * @internal 
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Sets the IpAddress of a peer.
	 *
	 * @since 		1.0
	 */ 
	bool SetAddress(Osp::Net::IpAddress* ipaddr);

	/** 
	 * @internal 
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Sets the keepalive time of peer.
	 * 
	 * @since 		1.0
	 */ 
	void SetUpdatedTime(Osp::Base::DateTime time);

	/** 
	 * @internal 
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Gets the keepalive time of peer.
	 * 
	 * @since 		1.0
	 */ 
	Osp::Base::DateTime GetUpdatedTime();

private:
	Osp::Base::String		__peerName;
	Osp::Net::IpAddress*	__pPeerIpAddr;
	Osp::Base::DateTime	__updatedTime;	

	AdhocPeerInfoEx* __pAdhocPeerInfoEx;

private:
	AdhocPeerInfo(const AdhocPeerInfo& value);
	AdhocPeerInfo& operator =(const AdhocPeerInfo& value);

	friend class __AdhocServiceAgent;
	friend class AdhocPeerInfoEx;
};

        }
    }
}
#endif //_FNET_WIFI_ADHOCPEERINFO_H_
