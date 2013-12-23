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
 * @file		FBaseObject.h 
 * @brief		This is the header file for the %Object class.
 *
 * This header file contains the declarations of the %Object class. @n 
 * This class defines a set of behaviors shared by all bada classes.
 */
#ifndef _FBASE_OBJECT_H_
#define _FBASE_OBJECT_H_

// Includes
#include "FBaseTypes.h"
#include "FBaseConfig.h"


namespace Osp { namespace Base { 
/**
 * @class	Object 
 * @brief	This class is the @b root class of bada.
 * @since	1.0
 *
 * The %Object class defines a set of behaviors and characteristics shared by all the other classes.
 * 
 * Derived classes can override some of these methods, such as the Equals() method, which tests for object equivalence. 
 */
class _EXPORT_BASE_ Object
{
// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class.
	 *
	 *  @since	1.0
	 */
	Object(void);

	/** 
	 *	This is the destructor for this class.
	 *
	 *  @since	1.0
	 */
	virtual ~Object(void);


// Operation
public:
	/** 
	 *	Checks whether the value of the specified instance is equal to the value of the current instance of %Object.
	 *
	 *  @since			1.0
	 *	@return			@c true if the value of the specified instance of %Object is equal to the value of the current instance of %Object, @n
	 *				else @c false
	 *	@param[in]	obj	An instance of %Object to compare
	 *	@remarks 	The default implementation of this method returns @c true 
	 *				if the two instances have the same address.
	 *				@par
	 *				The method can be overridden to support value equality. Furthermore, this method must return the same result as the equality operator.
	 */
	virtual bool Equals(const Object& obj) const;

	/** 
	 *	Gets the hash value of the current instance of %Object.
	 *
	 *  @since		1.0
	 *	@return		An integer value indicating the hash value of the current instance of %Object
	 *	@remarks 	Two equal instances should return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs.
	 *				@par
	 *				The default implementation of this method returns the address of the current instance.
	 */
	virtual int GetHashCode(void) const;

// Operator
public:

};

}; };// Osp::Base
#endif//_FBASE_OBJECT_H_


