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
 * @file		FIoDbStatement.h
 * @brief		This is the header file for the %DbStatement class.
 *
 * This header file contains declarations of the %DbStatement class.
 */
#ifndef _FIO_DB_STATEMENT_H_
#define _FIO_DB_STATEMENT_H_

#include <FBaseRtThreadMutex.h>
#include <FBaseString.h>
#include <FBaseByteBuffer.h>
#include <FBaseDateTime.h>

#include <FIoDbTypes.h>

namespace Osp { namespace Io {

/**
 * @class   DbStatement
 * @brief	This class provides a method for evaluating pre-compiled statements.
 * @since	1.0
 *
 * The %DbStatement class provides a method for evaluating pre-compiled statements.
 * All members of this class are guaranteed to be thread-safe.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/io/database_operations.htm">Database Operations</a>.

 */

class _EXPORT_IO_ DbStatement
	: public Osp::Base::Object
{

// Lifetime
private:

	DbStatement (void);

public:


	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	virtual ~DbStatement (void);

// Operations related to the DbStatement itself
public:


	/**
	* Binds an integer value to the statement parameter.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	columnIndex			The index of the column for which the value is bound
	* @param[out]	value				The integer value to be bound
	* @exception 	E_SUCCESS			The method is successful.
    * @exception	E_INVALID_STATE		The instance has not been properly constructed,
    *                                   or the instance is finalized. 
	* 									
	* @exception	E_INVALID_ARG		The specified @c columnIndex is invalid. 
	* @exception	E_DATABASE			The method has failed to bind the parameter because the database state has not been reset after executing the SELECT query by using 
    *                                   Database::ExecuteStatementN(), or a specified input parameter is invalid. 

	* @remarks		After the execution of the SELECT query with Database::ExecuteStatementN(), the database state should be reset by invoking DbEnumerator::Reset() before calling this method.
	*/
	result BindInt(int columnIndex, int value);


	/**
	* Binds a long long value to the statement parameter.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	columnIndex			The index of the column for which the value is bound
	* @param[out]	value				The 64-bit integer value to be bounded
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		The instance has not been properly constructed,
    *                                   or the instance is finalized. 
	* @exception	E_INVALID_ARG		The specified @c columnIndex is invalid.
	* @exception	E_DATABASE			The method has failed to bind the parameter because the database state has not been reset after executing the SELECT query by using 
    *                                   Database::ExecuteStatementN(), or a specified input parameter is invalid. 

	* @remarks		After the execution of the SELECT query with Database::ExecuteStatementN(), the database state should be reset by invoking DbEnumerator::Reset() before calling this method.
	*/
	result BindInt64(int columnIndex, long long value);


	/**
	* Binds a double value to the statement parameter.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	columnIndex		The index of the column for which the value is bound
	* @param[out]	value		    The double value to be bound
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE	   The instance has not been properly constructed,
    *                                   or the instance is finalized. 
	* @exception	E_INVALID_ARG		The specified @c columnIndex is invalid.
	* @exception	E_DATABASE			The method has failed to bind the parameter because the database state has not been reset after executing the SELECT query by using 
    *                                   Database::ExecuteStatementN(), or a specified input parameter is invalid. 
	* @remarks		After the execution of the SELECT query with Database::ExecuteStatementN(), the database state should be reset by invoking DbEnumerator::Reset() before calling this method.
	*/
	result BindDouble(int columnIndex, double value);

	/**
	* Binds a String value to the statement parameter.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	columnIndex		The index of the column for which the value is bound
	* @param[out]	value		The string value to be bound
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE	   The instance has not been properly constructed,
    *                                   or the instance is finalized. 
	* @exception	E_INVALID_ARG		The specified @c value exceeds size limit.
	* @exception	E_DATABASE			The method has failed to bind the parameter because the database state has not been reset after executing the SELECT query by using 
    *                                   Database::ExecuteStatementN(), or a specified input parameter is invalid. 
	* @remarks		After the execution of the SELECT query with Database::ExecuteStatementN(), the database state should be reset by invoking DbEnumerator::Reset() before calling this method.
	*/	
	result BindString(int columnIndex, const Osp::Base::String& value);

	/**
	* Binds a value of type %ByteBuffer to the statement parameter.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	columnIndex		    The index of the column for which the value is bound
	* @param[out]	value		        The blob value to be bound @n
	*							        The maximum available size is limited to 100 MBytes.
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE	     The instance has not been properly constructed,
    *                                   or the instance is finalized. 
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	* 									- The specified @c columnIndex is invalid. @n
	* 									- The size of byte buffer is less than @c 0 or has @c null data. @n
	* 									- The specified @c value exceeds size limit.
	* @exception	E_DATABASE			The method has failed to bind the parameter because the database state has not been reset after executing the SELECT query by using 
  *                                      Database::ExecuteStatementN(), or a specified input parameter is invalid. 
	* @remarks		After the execution of the SELECT query with Database::ExecuteStatementN(), the database state should be reset by invoking DbEnumerator::Reset() before calling this method. @n
	*				The bound @c byte array size is from the current position of byte buffer to the limit.
	*/
	result BindBlob(int columnIndex, const Osp::Base::ByteBuffer& value);

	/**
	* Binds the raw blob data to the statement parameter.
	* 
	* @since		1.0
	* @return		An error code
	* @param[in]	columnIndex	           The index of the column for which the value will be bound
	* @param[in]	buffer	               A pointer to the buffer where blob data is located @n
	*						               The maximum available size is limited to 100 MBytes.
	* @param[in]	size	               The blob data length in bytes
	* @exception 	E_SUCCESS			   The method is successful.
	* @exception	E_INVALID_STATE	       The instance has not been properly constructed,
    *                                   or the instance is finalized. 
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	* 									- The specified @c columnIndex is invalid. @n
	* 									- The specified @c size is less than @c 0. @n
	* 									- The pointer to the buffer is null. @n
	* 									- The specified @c buffer exceeds size limit.
	* @exception	E_DATABASE			The method has failed to bind the parameter because the database state has not been reset after executing the SELECT query by using 
  *                                     Database::ExecuteStatementN(), or a specified input parameter is invalid. 
	* @remarks		After the execution of the SELECT query with Database::ExecuteStatementN(), the database state should be reset by invoking DbEnumerator::Reset() before calling this method.
	*/
	result BindBlob(int columnIndex, const void* buffer, int size);

	/**
	* Binds a DateTime value to the statement parameter.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	columnIndex		The index of the column for which the value is bound
	* @param[out]	value		    The date value to be bound
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE	   The instance has not been properly constructed,
    *                                   or the instance is finalized. 
	* @exception	E_INVALID_ARG		The specified @c columnIndex is invalid, or
	*									the value is less than @c  or a @c null pointer.
	* @exception	E_DATABASE			The method has failed to bind the parameter because the database state has not been reset after executing the SELECT query by using 
    *                                   Database::ExecuteStatementN(), or a specified input parameter is invalid. 
	* @remarks		After the execution of the SELECT query with Database::ExecuteStatementN(), the database state should be reset by invoking DbEnumerator::Reset() before calling this method.
	*/
	result BindDateTime(int columnIndex, const Osp::Base::DateTime& value);


	/**
	* Binds a null value to the statement parameter.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	columnIndex		   The index of the column for which the value is bound
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE	 The instance has not been properly constructed,
    *                                   or the instance is finalized. 
	* @exception	E_INVALID_ARG		The specified @c columnIndex is invalid.
	* @exception	E_DATABASE			The method has failed to bind the parameter because the database state has not been reset after executing the SELECT query by using 
  *                                     Database::ExecuteStatementN(), or a specified input parameter is invalid. 
	* @remarks		After the execution of the SELECT query with Database::ExecuteStatementN(), the database state should be reset by invoking DbEnumerator::Reset() before calling this method.
	*/
	result BindNull(int columnIndex);


// Private Member Variables
private:

	/**
	* Destroy the created statement.
	*
	* @return		An error code
	* @exception 	E_SUCCESS			The method is successful.
	*/
	result __Destroy (void);

// Member Variables
private:
	bool __bShouldReleaseResource;
	__DbStatementType __stmtType;
	void* __hStmt;

	//static bool __sMutexCreated;
	//Osp::Runtime::Mutex* __pMutex;

	friend class Database;
	friend class __Database;

private:
	friend class DbStatementEx;
	class DbStatementEx *__pDbStatementEx;


};// DbStatement
};// Osp::Io
};// Osp
#endif	//_FIO_DB_STATEMENT_H_

