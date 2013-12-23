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
 * @file		FNetNetStatistics.h 
 * @brief		This is the header file for the %NetStatistics class.
 *
 * This header file contains declarations of the %NetStatistics class.
 */
#ifndef _FNET_NET_STATISTICS_H_
#define _FNET_NET_STATISTICS_H_

// Includes
#include "FBaseObject.h"
#include "FBaseResult.h"
#include "FNetNetTypes.h" 
#include "FNetNetAccountInfo.h"


namespace Osp { namespace Net {
// Forward declaration
class INetStatisticsPi;

/**
 * @class	NetStatistics 
 * @brief	This class represents the statistical information on the Packet-Switched (PS) data call.
 * @since	1.0
 *
 * @remarks	The %NetStatistics class cannot be tested on the Emulator.
 *
 * The %NetStatistics class provides methods for getting the statistical information on the packet-switched(PS) data call.
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/network_statistics.htm">Network Statistics</a>.
 *
 *
 * 
 *
 */
class _EXPORT_NET_ NetStatistics :
	public Osp::Base::Object
{
// Lifecycle
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 * @see			Construct()
	 */
	NetStatistics(void);

	/**
	 * Initializes this instance of %NetStatistics.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 *
	 */
	result Construct(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~NetStatistics(void);


// Operation
public:
	/**
	 * Gets the statistical information. @n
	 * This can consist of details such as the call duration, the sent and received size, and so on.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref GetNetStatisticsInfoPage1 "here".
	 *
	 * @privlevel		NORMAL
	 * @privgroup		NET
	 *
	 * @return			The number of bytes sent or received, @n
	 *					else @c INVALID_HANDLE if an error occurs
	 * @param[in]		bearerType			The bearer type of the data call operation @n 
	 *										NET_BEARER_WIFI_DIRECT and NET_BEARER_USB are not supported.
	 * @param[in]		netStatType			The type of statistical information to get
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		The input is invalid.
	 * @exception		E_INVALID_STATE		This instance is in an invalid state.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	long long GetNetStatisticsInfo(NetBearerType bearerType, NetStatisticsInfoType netStatType) const;

    /**
     * @page		GetNetStatisticsInfoPage1	Compatibility for GetNetStatisticsInfo()
     *
     * @section		GetNetStatisticsInfoPage1IssueSection	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# If the @c netStatType parameter is set as NET_STAT_SENT_SIZE or NET_STAT_RCVD_SIZE, this method returns a wrong value from the second invocation 
	 * within the active timespan of the specified bearer type.
     *
     * @section		GetNetStatisticsInfoPage1ResolutionSection	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
     */

	/** 
	 * Re-initializes the specified statistical information on the network according to the operation mode.
	 *
	 * @since		1.0
	 * @privlevel	SYSTEM
	 * @privgroup	NET_STATISTICS
	 *
	 * @return		An error code
	 * @param[in]	bearerType			The bearer type (OperationMode) whose statistical information is reset. @n NET_BEARER_WIFI_DIRECT and NET_BEARER_USB are not supported.
	 * @param[in]	netStatType			The type of statistical information to be reset
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @remarks		This method should use warning pop-up for user notification.
	 * @see			GetNetStatisticsInfo()
	 */
	result Reset(NetBearerType bearerType, NetStatisticsInfoType netStatType);

	/** 
	 * Initializes all the specified statistical information on the network according to the operation mode.
	 *
	 * @since		1.0
	 * @privlevel	SYSTEM
	 * @privgroup	NET_STATISTICS
	 *
	 * @return		An error code
	 * @param[in]	bearerType			The bearer type (OperationMode) whose statistical information would be reset. @n NET_BEARER_WIFI_DIRECT and NET_BEARER_USB are not supported.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @remarks		This method should use warning pop-up for user notification.
	 * @see			GetNetStatisticsInfo()
	 */
	result ResetAll(NetBearerType bearerType);


// Attribute
private:
	bool __isConstructed;
	INetStatisticsPi* __pNetStatisticsInterface;

	friend class NetStatisticsEx;
	class NetStatisticsEx* __pNetStatisticsEx;
};

}; }; // Osp::Net
#endif // _FNET_NET_STATISTICS_H_

