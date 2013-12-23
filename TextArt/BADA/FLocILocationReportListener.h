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
 * @file	FLocILocationReportListener.h 
 * @brief	This is the header file for the %LocationReportListener interface.
 *
 * This header file contains the declarations of the %ILocationReportListener interface. @n
 * This interface represents a listener that receives the events associated with changes in location reporting. 
 */

#ifndef _FLOC_ILOCATION_REPORT_LISTENER_H_
#define _FLOC_ILOCATION_REPORT_LISTENER_H_

#include "FLocationConfig.h"

namespace Osp { namespace Locations {

/**
* @interface	ILocationReportListener
* @brief		This interface provides a listener that receives the events associated with reporting location state changes to the bada Server.
* @deprecated   This interface is deprecated due to the operation policy of the bada Server.
* @since 		1.0
*
* The %ILocationReportListener interface provides a listener that receives the events associated with reporting location state changes to the bada Server.
* An application implements this interface and registers it with the RemoteLocationProvider::StartLocationReport() method to obtain 
* notifications about changes in location.
*
*
*/
class _EXPORT_LOCATION_ ILocationReportListener 
{
// Lifecycle
public:
    /**
     * This is the destructor for this class.
     *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
     * @since   1.0
     */
	virtual ~ILocationReportListener(void)  {}

// Operations
public:
	/**
	 * Called to notify that the state of the location report has changed. @n
	 * If the state is set to @c true, the state of the location reporting is good, but if the network connection is bad or the location cannot be obtained, 
	 * @c isState is set as @c false.
	 *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	 * @since		1.0
	 *
	 * @param[in] 	isState		Set to @c true to indicate that the state of the location reporting is good, @n
	 *							else @c false if the network connection is bad or the location cannot be obtained
	 */
	virtual void	OnReportingStateChanged(bool isState) = 0;

};		// class ILocationReportListener

};};	// Osp::Locations


#endif // _FLOC_ILOCATION_REPORT_LISTENER_H_
