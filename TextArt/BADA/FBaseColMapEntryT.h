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
 * @file		FBaseColMapEntryT.h 
 * @brief		This is the header file for the %MapEntryT class.
 *
 * This header file contains the declarations of the %MapEntryT class.
 */
#ifndef _FBASE_COL_MAP_ENTRY_T_H_
#define _FBASE_COL_MAP_ENTRY_T_H_

#include "FBaseObject.h"


namespace Osp { namespace Base { namespace Collection {

/**
 * @class MapEntryT
 *
 * @brief	This class represents a template-based key-value pair.
 * @since	1.0
 *
 * The %MapEntryT class represents a template-based key-value pair.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/mapentry.htm">MapEntry</a>.
 *
 */
template<class KeyType, class ValueType>
class MapEntryT
:	public Osp::Base::Object
{
public:

// Lifecycle

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	 1.0
	 */
	MapEntryT(void)
		:	__key(0), 
			__val(0)
	{

	}


	/**
	 * Initializes this instance of %MapEntryT with the specified key-value pair.
	 *
	 * @since	 		1.0
	 * @param[in]	key The key for this mapping
	 * @param[in]	value	The value for this mapping
	 */
	MapEntryT(const KeyType& key, const ValueType& value)
	:	__key(key), 
		__val(value)
	{

	}
	

	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~MapEntryT(void)
	{	
	
	}



// Operator

	/**
	 * This is the assignment operator.
	 *
	 * @since	 		1.0
	 * @param[in]	map	The map
	 */
	void operator =(const MapEntryT<KeyType, ValueType>& map)
	{
		__key = map.__key;
		__val = map.__val;
	}


// Access
	/**
	 * Gets the key corresponding to this entry.
	 *
	 * @since	 	1.0
	 * @return	The key corresponding to this entry
	 * @see			GetValue()
	 */
	virtual const KeyType& GetKey(void) const
	{
		return __key;
	}


	/**
	 * Gets the value corresponding to this entry.
	 *
	 * @since	 	1.0
	 * @return	The value corresponding to this entry
	 * @see			GetKey()
	 */
	virtual const ValueType& GetValue(void) const
	{
		return __val;
	}


private:

// Attribute

	KeyType __key;
	ValueType __val;

}; // MapEntryT

}; }; }; // Osp::Base::Collection
#endif // _FBASE_COL_MAP_ENTRY_T_H_

