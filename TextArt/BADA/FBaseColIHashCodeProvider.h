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
 * @file		FBaseColIHashCodeProvider.h 
 * @brief		This is the header file for the %IHashCodeProvider interface.
 *
 * This header file contains the declarations of the %IHashCodeProvider interface.
 */
#ifndef _FBASE_COL_IHASH_CODE_PROVIDER_H_
#define _FBASE_COL_IHASH_CODE_PROVIDER_H_

namespace Osp {namespace Base {class Object;}}

namespace Osp { namespace Base { namespace Collection {

/**
 * @interface	IHashCodeProvider
 *
 * @brief	This interface represents classes that can provide the hash code of a specific type of object.
 * @since	1.0
 *
 * The %IHashCodeProvider interface represents classes that can provide the hash code of a specific type of object.
 */
class _EXPORT_BASE_ IHashCodeProvider
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~IHashCodeProvider(void) {}


	/** 
	 * Provides the hash code of the specified object.
	 *
	 * @since			1.0
	 * @return		The hash code of the specified object
	 * @param[in]	obj      A pointer to the object whose hash code is required
	 * @remarks 	The hash algorithm is usually specific to a type.
	 *				Two equal instances should return the same hash value. 
	 *				For better performance, the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(const Osp::Base::Object& obj) const = 0;


}; // IHashCodeProvider

}; }; }; // Osp::Base::Collection
#endif // _FBASE_COL_IHASH_CODE_PROVIDER_H_

