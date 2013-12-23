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
 * @file		FIoDbEnumerator.h
 * @brief		This is the header file for the %DbEnumerator class.
 *
 * This header file contains the declarations of the %DbEnumerator class.
 */
#ifndef _FIO_DB_ENUMERATOR_H_
#define _FIO_DB_ENUMERATOR_H_


#include <FBaseRtThreadMutex.h>
#include <FIoConfig.h>
#include <FIoDbTypes.h>


namespace Osp { namespace Io {

/**
 * @class DbEnumerator 
 * @brief	This class provides methods for navigating the result of %DbStatement.
 * @since	1.0
 *
 *  The %DbEnumerator class provides methods for navigating the result of %DbStatement.
 * All the members of this class are guaranteed to be thread-safe.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/io/database_operations.htm">Database Operations</a>.
 *
 * @see Osp::Io::Database
 */

class _EXPORT_IO_ DbEnumerator
	: /*public virtual Osp::Base::Runtime::IThreadSafe*/
	//, public virtual Osp::Base::Collection::IEnumerator
	public Osp::Base::Object
{
// Lifetime
private:

	/**
	* This is the default constructor for this class.
	*/
	DbEnumerator(void);

public:

	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	virtual ~DbEnumerator(void);


// Operations related to the environment itself
public:

	/**
	* Moves the enumerator to the next position.
	*
	* @since			1.0
	* @return			An error code
	* @exception 	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	* 									- This instance has not been properly constructed as yet. @n
	* 									- The method has tried to fetch the column data of a result set that is not activated (the query did not yield any result). @n
	* 									- The method has tried to move the cursor position of the result set that is not activated (the query did not yield any result). @n 
	* 									- The instance is finalized.
	* @exception	E_OUT_OF_RANGE			The enumerator has reached to the end of the result set returned by the SELECT query.
	* @exception	E_DATABASE					The step has failed.
	* @see				Osp::Io::Database::ExecuteStatementN(), Reset()
	*/
	result MoveNext(void);


	/**
	* Resets the enumerator to the first position.
	*
	* @since			1.0
	* @return			An error code
	* @exception 	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	* 									- This instance has not been properly constructed as yet. @n 
	* 									- The method has tried to reset the cursor position of the result set that is not activated (the query did not yield any result). @n
	* 									- The instance is finalized.
	* @exception	E_DATABASE				The method has failed to reset
	* @remarks		After this method is called, if MoveNext() is called the cursor goes to the first position.
	* @see				MoveNext()
	*/
	result Reset(void);


	/**
	* Gets the value at the specified column index.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]	columnIndex		The index of the column for which the value is required
	* @param[out]	value			The integer value obtained from the column
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	* 									- This instance has not been properly constructed as yet. @n 
	* 									- The method has tried to fetch the column data of a result set that is not activated (the query did not yield any result). @n
	* 									- The instance is finalized.
	* @exception	E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception	E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	*/
	result GetIntAt(int columnIndex, int& value) const;


	/**
	* Gets a long long value from the column for which the index is specified.
	* @since			1.0
	* @return			An error code
	* @param[in]	columnIndex		The index of the column for which the value is required
	* @param[out]	value			The 64-bit integer value obtained from the column
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	* 									- This instance has not been properly constructed as yet. @n
	* 									- The method has tried to fetch the column data of a result set that is not activated (the query did not yield any result). @n
	* 									- The instance is finalized. 
	* @exception	E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception	E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	*/
	result GetInt64At(int columnIndex, long long& value) const;


	/**
	* Gets a double value from the column whose index is specified.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]	columnIndex		The index of the column for which the value is required
	* @param[out]	value			The value obtained from the column as a double
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	* 									- This instance has not been properly constructed as yet. @n 
	* 									- The method has tried to fetch the column data of a result set that is not activated (the query did not yield any result). @n
	* 									- The instance is finalized.
	* @exception	E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception	E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	*/
	result GetDoubleAt(int columnIndex, double& value) const;


	/**
	* Gets the String value from the column whose index is specified.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]	columnIndex		The index of the column for which the value is required
	* @param[out]	value			The value obtained from the column as a String
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	* 									- This instance has not been properly constructed as yet. @n 
	* 									- The method has tried to fetch the column data of a result set that is not activated (the query did not yield any result). @n
	* 									- The instance is finalized. 
	* @exception	E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception	E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	* @exception	E_INVALID_ENCODING_RANGE	The string conversion has failed due to invalid encoding range. @n
	*											It is possible if the database file is corrupt.
	*/
	result GetStringAt(int columnIndex, Osp::Base::String& value) const;


	/**
	* Gets a byte array value from the specified column index.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]	columnIndex			The index of the column for which the value is required
	* @param[in,out]	value			The user-provided buffer used to receive the blob data as a stream of type ByteBuffer. @n
	* 									The buffer will be filled from the current position and data copy will be continued until buffer limitation is reached or no more blob data remains. @n
	*									The maximum size available is limited to 100 MByte.
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	* 									- This instance has not been properly constructed as yet. @n 
	* 									- The method has tried to fetch the column data of a result set that is not activated (the query did not yield any result). @n
	* 									- The instance is finalized.
	* @exception	E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception	E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	* @exception	E_OUT_OF_RANGE		The byte buffer operation has failed.
	* @exception	E_OVERFLOW			The specified @c value of the byte buffer is insufficient to save the data.
	*/
	result GetBlobAt(int columnIndex, Osp::Base::ByteBuffer& value) const;


	/**
	* Gets the blob data from the given column.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]		columnIndex		The index of the column for which the value is required
	* @param[out]		buffer			The user-provided buffer used to receive the blob data @n
	*									The maximum size available is limited to 100 MByte.
	* @param[out]		size			The maximum buffer length in bytes
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	* 									- This instance has not been properly constructed as yet. @n 
	* 									- The method has tried to fetch the column data of a result set that is not activated (the query did not yield any result). @n
	* 									- The instance is finalized.
	* @exception	E_INVALID_ARG		The specified @c columnIndex is out of range, or the specified size is invalid.
	* @exception	E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	* @exception	E_OVERFLOW			The specified buffer is insufficient to save the data.
	*/
	result GetBlobAt(int columnIndex, void* buffer, int size) const;


	/**
	* Gets a value of type %DateTime from the column for which the index is specified.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]	columnIndex		The index of the column for which the value is required
	* @param[out]	value			The value obtained from the column as a DateTime instance
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	* 									- This instance has not been properly constructed as yet. @n 
	* 									- The method has tried to fetch the column data of a result set that is not activated (the query did not yield any result). @n
	* 									- The instance is finalized.
	* @exception	E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception	E_TYPE_MISMATCH		The operation has attempted to access columns of different types.
	* @exception	E_INVALID_FORMAT	The date is not correctly formatted, or the method is trying to access column of type String. @n
    *                                     The date format should be 'mm/dd/yyyy hh:mm:ss'.
	* @exception	E_OUT_OF_RANGE		Either the year(%d), month(%d), day(%d), hour(%d), minute(%d), or second(%d) value is out 
    *                                   of range, or the method is trying to access a column of type String.
	* @remarks		Note that the DateTime is constructed inside the method.
	*/
	result GetDateTimeAt(int columnIndex, Osp::Base::DateTime& value) const;


	/**
	* Gets the number of columns for this enumerator.
	*
	* @since		1.0
	* @return		The number of columns in the calling enumerator, @n
	*				else @c -1 if an exception occurs
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	* 									- This instance has not been properly constructed as yet. @n 
	* 									- The method has tried to fetch the column data of a result set that is not activated (the query did not yield any result). @n
	* 									- The instance is finalized.
	* @remarks		This method should be called after MoveNext(). @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetColumnCount(void) const;


	/**
	* Gets the type of the column indicated by the index.
	*
	* @since			1.0
	* @return			The type of column, @n
	*				else DB_COLUMNTYPE_UNDEFINED if an exception occurs
	* @param[in]	columnIndex		The index of the destination column
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	* 									- This instance has not been properly constructed as yet. @n 
	* 									- The method has tried to fetch the column data of a result set that is not activated (the query did not yield any result). @n
	* 									- The instance is finalized.
	* @exception	E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @remarks		The method should be called after MoveNext(). @n
	*				Currently, DB_COLUMNTYPE_INT is returned for a 64-bit integer. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	DbColumnType GetColumnType(int columnIndex) const;


	/**
	* Gets the name of the column indicated by the index.
	*
	* @since			1.0
	* @return			The name of the column, @n
	*				else an empty string if an exception occurs
	* @param[in]	columnIndex		The index of the destination column
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	* 									- This instance has not been properly constructed as yet. @n 
	* 									- The method has tried to fetch the column data of a result set that is not activated (the query did not yield any result). @n
	* 									- The instance is finalized.
	* @exception	E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @exception	E_INVALID_ENCODING_RANGE	String conversion failed due to invalid encoding range. @n
	*											It is possible if database file is corrupted.
	* @remarks		The method should be called after MoveNext().
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::String GetColumnName(int columnIndex) const;


	/**
	* Gets the size of data in bytes.
	* 
	* @since			1.0
	* @return			The size of the data in bytes, @n
	*				else @c -1 if an exception occurs
	* @param[in]    columnIndex		The index of the destination column
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		Either of the following conditions has occurred: @n
	* 									- This instance has not been properly constructed as yet. @n 
	* 									- The method has tried to fetch the column data of a result set that is not activated (the query did not yield any result). @n
	* 									- The instance is finalized.
	* @exception	E_INVALID_ARG		The specified @c columnIndex is out of range.
	* @remarks		The method should be called after MoveNext(). 
	*				If the destination column is of type %String, this method returns the @c byte length excluding the @c null terminator character.
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetColumnSize(int columnIndex) const;

// Member Variables
private:
	bool __bShouldReleaseResource;
	void*	__pEnum;

	int	__columnCount;
	bool __fromQuery;
	Osp::Base::Runtime::Mutex* __pMutex;

	friend class Database;
	friend class __Database;

private:
	friend class DbEnumeratorEx;
	class DbEnumeratorEx *__pDbEnumeratorEx;


};// DbEnumerator
};// Osp::Io
};// Osp
#endif	//_FIO_DB_Enumerator_H_

