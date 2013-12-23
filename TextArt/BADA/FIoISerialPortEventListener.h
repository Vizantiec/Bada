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
 * @file		FIoISerialPortEventListener.h
 * @brief		This is the header file for the %ISerialPortEventListener class.
 *
 * This is the header file for the %ISerialPortEventListener class.
 */

#ifndef _FIO_SERIALPORT_EVENT_LISTENER_H
#define _FIO_SERIALPORT_EVENT_LISTENER_H

#include "FBaseResult.h"
#include "FBaseRtIEventListener.h"
#include "FIoSerialPort.h"

namespace Osp { namespace Io {

/**
* @interface ISerialPortEventListener
* @brief This interface provides event handlers to receive serial port events synchronously.
* @since	1.2
* 
* The %ISerialPortEventListener interface provides event handlers to receive serial port events synchronously.
* 
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/io/serial_port_comm.htm">Serial Port Communication</a>.
* 
*/

class _EXPORT_IO_ ISerialPortEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:
	
  /**
	* Called when the data is received on the serial port.
	*
	* @since			1.2
	* @param[in]	byteBuffer		A byte buffer that contains the received data
	* @remarks			The %ByteBuffer instance needs to be deleted by the application.
	*/
	virtual void OnSerialPortDataReceivedN(Osp::Base::ByteBuffer& byteBuffer) = 0;
		
  /**
	* Called when an error occurs on the serial port.
	*
	* @since			1.2
	* @param[in]	r	The error code
	* @exception 	E_INVALID_DATA	The data is invalid.
	* @exception	E_SYSTEM				A system error has occurred.
	*/
	virtual void OnSerialPortErrorOccured(result r) = 0;
	
private:	
	//friend class ISerialPortEventListenerEx;
	//class ISerialPortEventListenerEx* __pISerialPortEventListenerEx;

};

}; }; 

#endif 
