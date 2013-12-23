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
* @file		FNetSockSocketLingerOption.h
* @brief	This is the header file for the %LingerOption class.
*
* This header file contains the declarations of the %LingerOption class.
*/

#ifndef _FNET_SOCK_SOCKET_LINGER_H_
#define _FNET_SOCK_SOCKET_LINGER_H_

// Includes
#include "FNetSockSocket.h"
#include "FBaseObject.h"

namespace Osp { namespace Net { namespace Sockets {

	// Forward declaration
	class LingerOptionEx;

	/**
	* @class	LingerOption
	* @brief	This class specifies whether a socket remains connected after the Close() method is called. 
	*			It also specifies the amount of time for which it remains connected, if the data is not sent.
	*
	* @since	1.0
	*
	* The %LingerOption class specifies whether a socket remains connected after the Close() method is called. 
	*			It also specifies the amount of time for which it remains connected, if the data is not sent.
	* 
	*For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/sockets.htm">Sockets Guide</a>.
	*
	* @see		<a href="classOsp_1_1Net_1_1Sockets_1_1Socket.html#1b899c18b6a2aed9f09b76371d8e29c3">Osp::Net::Sockets::Socket::SetSockOpt</a>
	*
	* The following example demonstrates how to use the %LingerOption class.
	*
	*	@code
	*	using namespace Osp::Base;
	*	using namespace Osp::Net::Sockets;
	*
	*	void
	*	MyClass::SomeMethod(void)
	*	{
	* 		// Constructs a LingerOption object.
	* 		LingerOption socketLinger(true, 10);
	*
	*		// Gets information on a LingerOption object.
	*		if (socketLinger.IsEnabled())
	*		{
	*			ushort time = socketLinger.GetLingerTime();
	*		}
	* 	}
	*	@endcode
	*/
	class _EXPORT_NET_ LingerOption :
		public Osp::Base::Object
	{
	// Lifecycle
	public:
		/**
		* Initializes this instance of %LingerOption class with the specified parameters.
		*
		* @since		1.0
		* @param[in]	enable		Set to @c true to remain connected after the Socket::Close() method is called, @n
		*							else @c false
		* @param[in]	seconds		The number of seconds to remain connected after the Socket::Close() method is called
		* @remarks 		Data may still be available in the outgoing network buffer after the socket is closed.
		*				If you want to specify the amount of time the socket attempts to transmit unsent data after being closed,
		*				create a %LingerOption with the @c enable parameter set to @c true, and the @c seconds parameter set to the desired
		*				amount of time. The @c seconds parameter is used to indicate how long the socket remains connected
		*				before getting timed out. If the socket is not required to stay connected for any amount of time after being closed,
		*				create a %LingerOption with the enabled parameter set to @c false. In this case, the socket closes immediately
		*				and any unsent data is lost. Once created, pass the %LingerOption to the Socket::SetSoLinger() method.
		*
		*/
		LingerOption(bool enable, int seconds);

		/**
		* This is the destructor for this class.
		*
		* @since		1.0
		*/
		virtual ~LingerOption(void);

		/**
		* This is the copy constructor for the %LingerOption class.
		*
		* @since		1.0
		* @param[in]	value		An instance of %LingerOption
		*/
		LingerOption(const LingerOption& value);


	// Operation
		/**
		* This is the assignment operator.
		*
		* @since		1.0
		* @return		A reference to this instance
		* @param[in]	rhs			An instance of %LingerOption
		*/
		const LingerOption& operator =(const LingerOption& rhs);

	// Accessor
	public:
		/**
		* Sets a value indicating whether the socket should linger after being closed.
		*
		* @since		1.0
		* @param[in]	on			Set to @c true if the socket should linger after Socket::Close() is called, @n
		*							else @c false
		*/
		void SetEnabled(bool on);

		/**
		* Sets the linger time. @n
		* This is the amount of time to remain connected after calling the Close() method if data remains to be sent.
		*
		* @since		1.0
		* @param[in]	seconds		The amount of time, in seconds, to remain connected after calling Close()
		*
		* @remarks		Use this method to determine how @c long a closed socket attempts transferring unsent data before getting timed out. The value can 
		*				also be set to the desired time-out period in seconds. If the Enabled property is set to @c true, and LingerTime is set to @c 0, the 
		*				socket attempts to send the data until there is no data left in the outgoing network buffer.
		*
		* @see			Socket::SetSockOpt()
		*/
		void SetLingerTime(int seconds);

		/**
		* Gets the linger time. @n
		* This is the amount of time to remain connected after calling the Close() method if data still remains to be sent.
		*
		* @since		1.0
		* @return		The amount of time in seconds to remain connected after calling Close()
		*
		*/
		int GetLingerTime(void) const;

	// Inquery
	public:
	   /**
		* Checks whether the linger option is enabled.
		*
		* @since		1.0
		* @return		@c true if the socket lingers after Socket::Close() is called, @n
		*				else @c false
		*/
		bool IsEnabled(void) const;

	// Lifecycle
	private:
		/**
		* This is the default constructor for this class.
		*/
		LingerOption(void);

	// Accessor
	private:
		/**
		* This method gets the SocketLinger object representing the %LingerOption object, which is used in the subsystem.
		* @return		The method returns no data
		* @param[out]	socketLinger	The SocketLinger object representing the LingerOption object
		*/
		//void GetSocketLinger(SocketLinger& socketLinger) const;

		/**
		* This method sets the LingerOption object with the SocketLinger object, which is used in the subsystem.
		* @param[in]	socketLinger	The socketLinger object representing the LingerOption object in the subsystem
		*/
		//void SetLingerOption(const SocketLinger& socketLinger);

	// Attribute
	private:
		bool __enabled;
		int __lingerTime;

	private:
		// for ABC
		class LingerOptionEx* __pLingerOptionEx;

		// Friend class declaration
		friend class Socket;
		friend class LingerOptionEx;
	};

};// Osp::Net::Sockets
};// Osp::Net
};// Osp

#endif // _FNET_SOCK_NET_SOCKET_LINGER_H_

