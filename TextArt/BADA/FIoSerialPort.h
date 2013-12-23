/* $Change: 574438 $ */
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
 * @file		FIoSerialPort.h
 * @brief		This is the header file for the %SerialPort class.
 *
 * This header file contains the declarations of the %SerialPort class.
 */
#ifndef _FIO_SERIALPORT_H_
#define _FIO_SERIALPORT_H_

#include <FIo.h>

namespace Osp { namespace Io {

class ISerialPortEventListener;

/**
 * @class	SerialPort
 * @brief	This class provides an interface for controlling a serial port resource.
 * @since 1.2 
 *
 * @remarks The serial communication feature is reset when the USB connection is broken or a host device sends the
 * deactivate command. Any serial port options are not supported by the current version.
 *
 * The %SerialPort class provides an interface for controlling a serial port resource.
 *
 *  For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/io/serial_port_comm.htm">Serial Port Communication</a>.
 *
 *
 * @see ISerialPortEventListener
 * 
 * The following example demonstrates how to use the %SerialPort class.
 *
 * @code
 * #include <FIo.h>
 * #include <FBase.h>
 *
 * using namespace Osp::Base;
 * using namespace Osp::Io;
 *
 * class SerialRecv :
 *      public Osp::Io::ISerialPortEventListener
 * {
 *      void OnSerialPortDataReceivedN(Osp::Base::ByteBuffer& byteBuffer)
 *      {
 *            //Read data.
 *      }
 *
 *      void OnSerialPortErrorOccured(result r)
 *      {
 *            //Check error status.
 *      }
 * }
 * void
 * MyClass::SerialPortSample(void)
 * {
 *      SerialPort serialPort;
 *      ByteBuffer buf;
 *      String szMessage = L"Hello";
 *      SerialRecv listener;
 *
 *      buf.Construct(1024);
 *      buf.SetArray(szMessage.GetPointer(), 0, 6);
 *      buf.SetPosition(0);
 *      buf.SetLimit(6);
 *
 *      //Construct serial port.
 *      serialPort.Construct(listener);
 *      //Write buf on output buffer.
 *      serialPort.Write(buf);
 *		   
 * }
 * @endcode
 *
 * 
 *
 */
class _EXPORT_IO_ SerialPort
	: public Osp::Base::Object
{

public:
// Lifecycle

  /**
	* This is the default constructor for this class.	
	*
	* @since 1.2
	*/
	SerialPort(void);

  /**
	* This is the destructor for this class.
	*
	* @since 1.2
	*/
	virtual ~SerialPort(void);
		
	/**
	 * Constructs a new serial port connection. If the specified port is open, E_SYSTEM is returned.
	 *
	 * @since 		1.2
	 * @param[in]	listener		The serial port event listener
	 * @return			An error code
	 * @exception	E_SUCCESS		The method is successful.	 	 
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception	E_SYSTEM	A system error has occurred.
	 */
	result Construct(ISerialPortEventListener& listener);
			
	/**
	 * Writes data to the output buffer synchronously.
	 *
	 * @since 		1.2
	 * @return		An error code	 
	 * @param[in]	byteBuffer					A reference to the buffer that contains the string data to be written	 
	 * @exception	E_SUCCESS					The method is successful.	 
	 * @exception  E_INVALID_STATE		The file has not been opened as yet.  
	 * @exception	E_MAX_EXCEEDED   The buffer size has exceeded the maximum limit of the current device. 
	 * @exception	E_SYSTEM	   			A system error has occurred.
	 * @see GetWriteBufferSize()
	 */
	result Write(const Osp::Base::ByteBuffer& byteBuffer);
	
	/**
	 * Gets the size of the write buffer.
	 *
	 * @since 	1.2
	 * @return 	The size of the write buffer
	 * @remarks 	The size of the write buffer depends on the device.
	 */
	int GetWriteBufferSize(void) const;
		
private:
	void* __pSerialPortEvent;
		
	friend class SerialPortEx;
	class SerialPortEx* __pSerialPortEx;
};
};};

#endif
