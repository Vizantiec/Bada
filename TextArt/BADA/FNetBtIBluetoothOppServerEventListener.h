/* $Change: 1142016 $ */
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
 * @file    FNetBtIBluetoothOppServerEventListener.h
 * @brief   This is the header file for the %IBluetoothOppServerEventListener interface.
 *
 * This header file contains the declarations of the %IBluetoothOppServerEventListener interface.
 */
#ifndef FNET_BT_IBLUETOOTHOPPSERVEREVENTLISTENER_H
#define FNET_BT_IBLUETOOTHOPPSERVEREVENTLISTENER_H

#include "FBaseRtIEventListener.h"

namespace Osp { namespace Net { namespace Bluetooth {

// Forward declaration
class BluetoothOppServer;
class BluetoothDevice;
/**
 * @interface    IBluetoothOppServerEventListener
 * @brief        This interface provides a listener for the %BluetoothOppServer events.
 * @since        1.0
 *
 * The %IBluetoothOppServerEventListener interface specifies the methods used for creating notifications about the
 * different kinds of BluetoothOppServer events. When a BluetoothOppServer event is generated, one of these methods
 * is called.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _EXPORT_NET_ IBluetoothOppServerEventListener : public Osp::Base::Runtime::IEventListener {

public:
    /**
     * This is the destructor for this class.
     *
     * @since       1.0
     */
    virtual ~IBluetoothOppServerEventListener(void) {}

    /**
     * Called when an incoming push request is received from a remote OPP client.
     *
     * @since       1.0
     *
     * @param[in]   device          The remote device that requests the connection
     */
    virtual void OnOppPushRequested(const BluetoothDevice& device) = 0;

    /**
     * Called when the file is being transferred. @n
     * Gets the progress information of the file transfer.
     *
     * @since       1.0
     *
     * @param[in]   percent         The progress in percentage ranging from @c 1 to @c 100 percent
     * @see         BluetoothOppServer::SetMinProgressInterval()
     */
    virtual void OnOppTransferInProgress(int percent) = 0;

    /**
     * Called when the file transfer has finished.
     *
     * @since           1.0
     * @compatibility   This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *                  For more information, see @ref IBluetoothOppServerEventListenerOnOppTransferDonePage "here".
     *
     * @param[in]       fileName        The name of the transferred file
     * @param[in]       fileSize        The size of the transferred file
     * @param[in]       isCompleted     Set to @c true if the transfer is successfully completed, @n
     *                                  else @c false
     */
    virtual void OnOppTransferDone(const Osp::Base::String& fileName, int fileSize, bool isCompleted) = 0;

    /**
     * @page        IBluetoothOppServerEventListenerOnOppTransferDonePage Compatibility for OnOppTransferDone()
     *
     * @section     IBluetoothOppServerEventListenerOnOppTransferDonePageIssueSection Issues
     *              Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     *
     *              -# If the name of the received file already exists in the destination path, the transfer fails and
     *              @c isCompleted is set to @c false.
     *
     * @section     IBluetoothOppServerEventListenerOnOppTransferDonePageSolutionSection Resolutions
     *              The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada
     *              API version 2.0 or above. @n
     *
     *              -# The received file is renamed automatically and @c isCompleted is set to @c true. For renaming,
     *              the specified postfix is appended to the original file name. The postfix consists of an underscore
     *              and three digit sequence numbers starting from 001. For example, "MySong.mp3" may be changed to
     *              "MySong_001.mp3"
     *
     * @par         When working with bada API versions prior to 2.0:
     *
     *              -# Use a temporary directory for the destination path to avoid the possibility of a transfer
     *              failure due to duplication of the received file name. The application is able to check duplication
     *              and rename itself while the received file is moved from the temporary directory to the final
     *              destination path.
     */
};
} } }
#endif // FNET_BT_IBLUETOOTHOPPSERVEREVENTLISTENER_H
