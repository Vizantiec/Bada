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
 * @file		FBaseColMapEntry.h 
 * @brief		This is the header file for the %MapEntry class.
 *
 * This header file contains the declarations of the %MapEntry class.
 */
#ifndef _FCOL_MAP_ENTRY_H_
#define _FCOL_MAP_ENTRY_H_

#include "FBaseObject.h"


namespace Osp { namespace Base { namespace Collection {

/**
 * @class MapEntry
 *
 * @brief	This class represents a key-value pair.
 * @since	1.0
 *
 * The %MapEntry class represents a key-value pair.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/mapentry.htm">MapEntry</a>.
 */
class _EXPORT_BASE_ MapEntry
:	public Object
{
public:

// Lifecycle

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	 		1.0
	 * @param[in]	key	The key
	 * @param[in]	value	The value 
	 */
	MapEntry(const Object& key, const Object& value);
	

	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~MapEntry(void);


// Access

	/**
	 * Gets the key corresponding to this entry.
	 *
	 * @since	 	1.0
	 * @return	The key corresponding to this entry
	 * @see			GetValue()
	 */
	virtual const Object* GetKey(void) const;


	/**
	 * Gets the value corresponding to this entry.
	 *
	 * @since	 	1.0
	 * @return	The value corresponding to this entry
	 * @see			GetKey()
	 */
	virtual const Object* GetValue(void) const;


	/**
	 * Gets the key corresponding to this entry.
	 *
	 * @since	 	1.0
	 * @return	The key corresponding to this entry
	 * @see			GetValue()
	 */
	virtual Object* GetKey(void);


	/**
	 * Gets the value corresponding to this entry.
	 *
	 * @since	 	1.0
	 * @return	The value corresponding to this entry
	 * @see			GetKey()
	 */
	virtual Object* GetValue(void);


	/** 
	 * Compares the value of the given Object to the
	 * value of the calling object.
	 *
	 * @since	 		1.0
	 * @return		@c true if the values are equal, @n
	 *				else @c false
	 * @param[in]	obj		The object to compare with the calling object
	 * @remarks 	Returns @c false if the given object is not a %MapEntry object.
	 */
	virtual bool Equals(const Object& obj) const;


private:

// Lifecycle

	/**
	 * This is the copy constructor for the %MapEntry class.
	 *
	 * @param[in]	entry The instance of the %MapEntry class to copy from
	 * @remarks		This constructor is hidden.
	 */
	MapEntry(const MapEntry& entry);


// Operator

	/**
	 * This is the assignment operator.
	 *
	 * @param[in]	entry The instance of the %MapEntry class to assign from
	 * @remarks		This operator is hidden.
	 */
	MapEntry& operator =(const MapEntry& entry);


protected:

// Lifecycle
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	MapEntry(void);


// Attribute
	/**
	 * @internal
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	Object* __pKey;

	/**
	 * @internal
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	Object* __pValue;	



private:
	friend class MapEntryEx;
	class MapEntryEx* __pMapEntryEx;

}; // MapEntry

}; }; }; // Osp::Collection
#endif // _FCOL_MAP_ENTRY_H_

