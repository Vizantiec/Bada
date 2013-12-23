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
 * @file		FBaseDataType.h
 * @brief		This is the header file for the data types.
 *
 * This header file defines the data types.
 */
#ifndef _FBASE_DATA_TYPE_H_
#define _FBASE_DATA_TYPE_H_


/**
 * @brief 	byte is a unsigned char datatype.
 * @since	 	1.0
 */
typedef unsigned char		byte;

/**
 * @brief 	mchar is a wide character datatype.
 * @since	 	1.0
 */
typedef wchar_t				mchar;

/**
 * @brief 	result is a unsigned long type and indicates the result of the method execution.
 * @since	 	1.0
 */
typedef unsigned long		result;


namespace Osp { namespace Base { class String; };};

typedef Osp::Base::String		UserId;
typedef Osp::Base::String		LoginId;


/**
* @brief 		The invocation ID is returned when a request is sent.
* @since	 	1.0
*/
typedef long				RequestId;
#define INVALID_REQUEST_ID	-1


/* Macro to get the value in byte */
#define GET_MASK(val, pos, msk)	(((val) & ((msk) << (pos)) ) >> (pos))
/* Macro to put the value in byte */
#define PUT_MASK(var, val, pos)	((var) | ((val) << (pos)))


#ifndef Handle
	typedef int	Handle;
	#define	INVALID_HANDLE  -1
#endif // Handle

#ifndef	null
	#define null	0
#endif // null

#ifndef INFINITE
	#define INFINITE    0xFFFFFFFF
#endif // INFINITE


#ifndef UUID
	#ifndef UUID__DEFINED
		typedef struct UUID_ {
			unsigned long	x;
			unsigned short	s1;
			unsigned short	s2;
			unsigned char	c[8];
		} UUID_;

		#define UUID__DEFINED
		#define UUID_DEFINED
	#endif

	#define UUID UUID_
#endif // UUID

#endif// _FBASE_DATA_TYPE_H_
