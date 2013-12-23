/* $Change: 1255989 $ */
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
 * @file FIoDatabase.h
 * @brief This is the header file for the %Database class.
 *
 * This header file contains the declarations of the %Database class.
 */
#ifndef _FIO_DATABASE_H_
#define _FIO_DATABASE_H_

#include <FBaseColArrayList.h>
#include <FBaseString.h>
#include <FBaseRtThreadMutex.h>
#include <FBaseResource.h>
#include <FIoConfig.h>

namespace Osp {namespace Base {class ByteBuffer;}}

namespace Osp { namespace Io {
	class DbStatement;
	class DbEnumerator;
//	class IDbListener;

/**
 * @class	Database 
 * @brief	This class provides the basic database and database entry management methods.
 * @since	1.0
 *
 * The %Database class provides the basic database and database entry management methods.
 * All members of this class are guaranteed to be thread-safe.
 * However, process safety is not guaranteed.
 *
 * For more information on the class features,
 * see <a href="../com.osp.cppappprogramming.help/html/dev_guide/io/database_operations.htm">Database Operations</a>.
 *
 * @see Osp::Io::DbStatement, Osp::Io::DbEnumerator
 *
 * The following example demonstrates how to use the %Database class.
 *
 * @code
#include <FIo.h>
using namespace Osp::Io;

result
MyTest::UsingDatabase(void)
{
	Database *pDatabase;
	DbStatement* pStmt;
	DbEnumerator* pEnum;

	String dbName(L"/Home/sampleDb");
	String sql, sql2, sql3;
	String statement;
	String stringItem;

	result r = E_SUCCESS;

	pDatabase = new Database();
	if (!pDatabase)
		goto CATCH;

	r = pDatabase->Construct(dbName, true);
	if (IsFailed(r))
		goto CATCH;

	// Creates a database table
	AppLog("Create database table:");
	sql.Append(L"CREATE TABLE IF NOT EXISTS myTable1 ( column0 INTEGER PRIMARY KEY, column1 DOUBLE, column2 TEXT )");

	r = pDatabase->ExecuteSql(sql, true);
	if (IsFailed(r))
		goto CATCH;

	// Inserts the rows
	AppLog("Insert rows:");
	pDatabase->BeginTransaction();

	statement.Append(L"INSERT INTO myTable1 (column0, column1, column2) VALUES (?, ?, ?)");
	pStmt = pDatabase->CreateStatementN(statement);

	stringItem.Append(L"Initial Data");
	for (int i=0; i<10; i++)
	{
		pStmt->BindInt(0, i);		// integer
		pStmt->BindDouble(1, i*0.1);	// double
		pStmt->BindString(2, stringItem);	// String

		pEnum = pDatabase->ExecuteStatementN(*pStmt);
		AppAssert(!pEnum);
	}

	pDatabase->CommitTransaction();

	delete pStmt;

	// Selects a query using the Database::QueryN() wrapper API
	AppLog("Select query using Database::QueryN() wrapper API:");
	pEnum = pDatabase->QueryN(L"SELECT * FROM myTable1 WHERE column0 < 5");
	if (pEnum)
	{
		int nRows = 0;
		int iVal;
		double fVal;
		String strVal;
		while (pEnum->MoveNext() == E_SUCCESS)
		{
			r = pEnum->GetIntAt(0, iVal);
			if (IsFailed(r))
				goto CATCH;

			r = pEnum->GetDoubleAt(1, fVal);
			if (IsFailed(r))
				goto CATCH;

			r = pEnum->GetStringAt(2, strVal);
			if (IsFailed(r))
				goto CATCH;

			AppLog("[%d] column0=%d, column1=%f, column2=%ls", nRows++, iVal, fVal, strVal.GetPointer());
		}
		delete pEnum;
	}

	// Selects a query using statement
	AppLog("Select query using statement:");
	pStmt = pDatabase->CreateStatementN(L"SELECT * FROM myTable1 WHERE column0 > ? AND column0 < ?");
	r = GetLastResult();
	if (IsFailed(r))
		goto CATCH;
	AppAssert(pStmt);

	r = pStmt->BindInt(0, 3);
	if (IsFailed(r))
		goto CATCH;

	r = pStmt->BindInt(1, 8);
	if (IsFailed(r))
		goto CATCH;

	pEnum = pDatabase->ExecuteStatementN(*pStmt);
	r = GetLastResult();
	if (IsFailed(r))
		goto CATCH;

	if (pEnum)
	{
		int nRows = 0;
		int iVal;
		double fVal;
		String strVal;
		while (pEnum->MoveNext() == E_SUCCESS)
		{
			r = pEnum->GetIntAt(0, iVal);
			if (IsFailed(r))
				goto CATCH;

			r = pEnum->GetDoubleAt(1, fVal);
			if (IsFailed(r))
				goto CATCH;

			r = pEnum->GetStringAt(2, strVal);
			if (IsFailed(r))
				goto CATCH;

			AppLog("[%d] column0=%d, column1=%f, column2=%ls", nRows++, iVal, fVal, strVal.GetPointer());
		}
		delete pEnum;
	}

	// Deletes the rows
	AppLog("Delete rows:");
	pDatabase->BeginTransaction();

	sql2.Append(L"DELETE FROM myTable1 WHERE column0 = 1");
	r = pDatabase->ExecuteSql(sql2, true);

	if (r != E_SUCCESS)
		goto CATCH;

	pDatabase->CommitTransaction();

	// Updates the rows
	AppLog("Update rows:");
	pDatabase->BeginTransaction();

	sql3.Append(L"UPDATE myTable1 SET column2 = 'Converted Data' WHERE column2 = 'Initial Data'");
	r = pDatabase->ExecuteSql(sql3, true);

	if (r != E_SUCCESS)
		goto CATCH;

	pDatabase->CommitTransaction();

	// Resource cleanup
	delete pDatabase;
	pDatabase = null;

	r = Database::Delete(dbName);
	if (IsFailed(r))
		goto CATCH;

	AppLog("Finished successfully...");
	return E_SUCCESS;

CATCH:
	if(pDatabase)
	{
		delete pDatabase;
		pDatabase = null;
	}

	if (Database::Exists(dbName))
		Database::Delete(dbName);

	return r;
}
 * @endcode
 */

/**
 * @page DatabasePrefixReadable Allowed Path Prefixes
 * - '/Home' or '/HomeExt' (read and write permission)
 * - '/Home/Share', '/Home/Share2', '/HomeExt/Share', or '/HomeExt/Share2' (read and write permission)
 * - '/Share/[appid]' or '/ShareExt/[appid]' (read-only permission)
 * - '/Share2/[appid]' or '/Share2Ext/[appid]' (read and write permission)
 * - '/Res' (read-only permission) @n
 *
 * Refer to <a href="../com.osp.documentation.help/html/bada_overview/bada_file_system.htm">bada File System</a>
 * for the detailed usage and permission for each of the allowed path prefixes.
 */

/**
 * @page DatabasePrefixWritable Allowed Path Prefixes
 * - '/Home' or '/HomeExt' (read and write permission)
 * - '/Home/Share', '/Home/Share2', '/HomeExt/Share', or '/HomeExt/Share2' (read and write permission)
 * - '/Share2/[appid]' or '/Share2Ext/[appid]' (read and write permission) @n
 *
 * Refer to <a href="../com.osp.documentation.help/html/bada_overview/bada_file_system.htm">bada File System</a>
 * for the detailed usage and permission for each of the allowed path prefixes.
 */

class _EXPORT_IO_ Database
	: /*public virtual Osp::Base::Runtime::IThreadSafe*/
	public Osp::Base::Object,
	public Osp::Base::__Resource
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @since	1.0
	*/
	Database(void);


	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	virtual ~Database(void);


// Operations related to the environment itself
public:

	/**
	* Initializes this instance of %Database with the specified parameters. @n
    * This method creates a new database file or opens an existing database file in the read-write mode.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	databasePath			The path of the database file to be opened @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref DatabasePrefixReadable "here".
	* @param[in]	createIfNotExist		Set to @c true to create a database file, @n    
	*                                       else @c false to open an existing database file
	* @exception 	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has already been constructed.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The length of the specified @c databasePath is invalid. @n
	*											- The specified @c databasePath parameter contains an invalid path or the path ends with '/'. @n
	*											- The directory name path is missing. @n
	*											- The parent directory does not exist. @n
	*											- An I/O security issue. @n
	*											  This method cannot open a secure database file encrypted by the bada platform.
	*											  Use Construct(const Osp::Base::String& databasePath, long openMode, bool secureMode,
	*											  long option) in this case.
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST	The specified database file already exists. @n
	*										Creation of database file failed because the destination file already exists. @n
	*										Creation of the database file is attempted if the file does not exist and
	*										the specified @c createIfNotExist is true.
	*										However, at this moment another thread has been already created the database file
	*										with the same file path.
	*										This is a rare case, however it is possible if a race condition is present between several threads.
	* @exception	E_FILE_NOT_FOUND		The specified database file cannot be found or accessed.
	* @exception	E_DATABASE				The method has failed to open or create a file.
	* @remarks		To open the database file in the read-only mode,
	* 				use the Database::Construct(const Osp::Base::String& databasePath, long openMode, long option) method
	* 				with DB_OPEN_READ_ONLY as the value for the open mode flag.
	*
	*/
	result Construct(const Osp::Base::String& databasePath, bool createIfNotExist);


	/**
	* Initializes this instance of %Database with the specified parameters. @n
	* This method creates a new database file or opens an existing database file in the read-only or the read-write mode. 
	*
	* @since		1.1
	*
	* @return		An error code
	* @param[in]	databasePath			The path of the database file to be opened @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref DatabasePrefixReadable "here".
	* @param[in]	openMode				An open mode flag @n
	*										Currently, the following flags can be used in combination with the logical OR operator: @n
	*										 (1) DB_OPEN_READ_ONLY @n
	*										 (2) DB_OPEN_READ_WRITE @n
	*										 (3) DB_OPEN_READ_WRITE | DB_OPEN_CREATE
	* @param[in]	option					This argument is reserved for further use.
	* @exception 	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has already been constructed.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The length of the specified @c databasePath is invalid. @n
	*											- The specified @c openMode is invalid. @n
	*											- The specified @c databasePath parameter contains an invalid path or the path ends with '/'. @n
	*											- The directory name path is missing. @n
	*											- The parent directory does not exist. @n
	*											- An I/O security issue. @n
	*											- This method cannot open a secure database file encrypted by the bada platform. @n
	*											  Use Construct(const Osp::Base::String& databasePath, long openMode, bool secureMode,
	*											  long option) in this case.
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST	The specified database file already exists.
	* @exception	E_FILE_NOT_FOUND		The specified database file cannot be found or accessed.
	* @exception	E_DATABASE				The method has failed to open or create a file.
	*/
	result Construct(const Osp::Base::String& databasePath, long openMode, long option);


	/**
	* Initializes this instance of %Database with the specified parameters. @n
	* This method creates a new normal/secure database file or opens an existing normal/secure database file
	* in the read-only or the read-write mode.
	* An application using this method cannot access the secure database files that are created by other applications
	* because of the application-specific key.
	*
	* @deprecated	This method is deprecated because using platform device key for encryption is no longer recommended.
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	databasePath			The path of the database file to be opened @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref DatabasePrefixReadable "here".
	* @param[in]	openMode				An open mode flag @n
	*										Currently, the following flags can be used in combination with the logical OR operator: @n
	*										 (1) DB_OPEN_READ_ONLY @n
	*										 (2) DB_OPEN_READ_WRITE @n
	*										 (3) DB_OPEN_READ_WRITE | DB_OPEN_CREATE
	* @param[in]	secureMode				Set to @c true to deal with a database file in encrypted form, @n
	*                                       else @c false @n
	* 										Applications cannot open a normal database file in a secure mode and
	* 										a secure database file in a normal mode.
	* @param[in]	option					This argument is reserved for further use.
	* @exception 	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has already been constructed.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The length of the specified @c databasePath is invalid. @n
	*											- The specified @c openMode is invalid. @n
	*											- The specified @c databasePath parameter contains an invalid path or the path ends with '/'. @n
	*											- The directory name path is missing. @n
	*											- The parent directory does not exist. @n
	*											- An I/O security issue. @n
	*											- A secure database file cannot be accessed in the normal mode or
	*											  a normal database file cannot be accessed in the secure mode.
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST	The specified database file already exists.
	* @exception	E_FILE_NOT_FOUND		The specified database file cannot be found or accessed.
	* @exception	E_DATABASE				The method has failed to open or create a file.
	*/
	result Construct(const Osp::Base::String& databasePath, long openMode, bool secureMode, long option);

	/**
	* Initializes this instance of %Database with the specified parameters. @n
	* This method creates a new normal/secure database file or opens an existing normal/secure database file
	* in the read-only or the read-write mode.
	* Applications using this method can access the same secure database files that are created by other applications
	* with the identical key value.
	*
	* @deprecated	This method is deprecated and will be replaced with a new one in the near future.
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	databasePath			The path of the database file to be opened @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref DatabasePrefixReadable "here".
	* @param[in]	openMode				An open mode flag @n
	*										Currently, the following flags can be used in combination with the logical OR operator: @n
	*										 (1) DB_OPEN_READ_ONLY @n
	*										 (2) DB_OPEN_READ_WRITE @n
	*										 (3) DB_OPEN_READ_WRITE | DB_OPEN_CREATE
	* @param[in]	secureMode				Set to @c true to deal with a database file in encrypted form, @n
	*										else @c false @n
	* 										Applications cannot open a normal database file in a secure mode and
	* 										a secure database file in a normal mode.
	* @param[in]	key						A key that encrypts or decrypts a secure database file @n
	* 										If the secure database file is created with a specific key value,
	* 										applications can access the same secure database file with the identical key value.
	* @param[in]	option					This argument is reserved for further use.
	* @exception 	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has already been constructed.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The length of the specified @c databasePath is invalid. @n
	*											- The specified @c openMode is invalid. @n
	*											- The specified @c databasePath parameter contains an invalid path or the path ends with '/'. @n
	*											- The directory name path is missing. @n
	*											- The parent directory does not exist. @n
	*											- An I/O security issue. @n
	*											- A secure database file cannot be accessed in the normal mode or
	*											  a normal database file cannot be accessed in the secure mode.
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST	The specified database file already exists.
	* @exception	E_FILE_NOT_FOUND		The specified database file cannot be found or accessed.
	* @exception	E_DATABASE				The method has failed to open or create a file.
	* @exception	E_IO					The specified @c key is incorrect.
	*/
	result Construct(const Osp::Base::String& databasePath, long openMode, bool secureMode, const Osp::Base::ByteBuffer& key, long option);



public:


	/**
	* Creates a query statement for the current database.
	*
	* @since		1.0
	* @return		A pointer to the %DbStatement instance, @n
    * 				else @c null if an exception occurs
	* @param[in]	statement			The statement to be compiled
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		The database has not opened or created as yet. 
	* @exception	E_INVALID_ARG		The length of the query is invalid.
	* @exception	E_DATABASE			The method has failed to prepare a statement.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see ExecuteStatementN()
	*/
	DbStatement* CreateStatementN(const Osp::Base::String& statement);


	/**
	* Executes a statement in the calling %Database instance. @n
	* If an application opens a database file in the secure mode
	* using Database::Construct(const Osp::Base::String& databasePath, long openMode, bool secureMode, long option),
	* the data set written by INSERT/UPDATE is automatically encrypted by the bada platform and
	* the data set read by SELECT is also decrypted by itself.
	* 
	* @since		1.0
	* @return		A pointer to the %DbEnumerator instance, @n
	* 				else  @c null if an exception occurs or if no result set is generated after the successful execution of the SELECT query
	* @param[in]	statement			The statement to be executed
	* @exception 	E_SUCCESS			The method is successful.	
	* @exception	E_INVALID_STATE		The database has not opened or created as yet.
	* @exception	E_INVALID_ARG		The specified @c statement is invalid. @n
	*									A @c null handle is assigned or finalized statement is passed.
	* @exception	E_DATABASE			The method has failed to reset the compiled statement back to its initial state
	* 									or execute the compiled statement in the database engine.
	* @exception	E_SERVICE_BUSY		The database is busy.
	* @remarks		If @c statement contains the SELECT query, the Reset() method of the %DbEnumerator instance returned
	* 				from this method should be called. The Reset() method should be called before re-binding the statement
	* 				with the bind methods of the %DbStatement class.
	* 				This method returns an enumerator if the result set is generated by the SELECT query.
	* 				@c null is returned if no result set is available after the successful execution of the SELECT query.
	* 				Note that, a return value of @c null does not mean that the statement execution has failed.
	* 				The enumerator returned by the SELECT query does not indicate any row before it calls DbEnumerator::MoveNext().
	* 				The specific error code can be accessed using the GetLastResult() method.
	*/
	DbEnumerator* ExecuteStatementN(const DbStatement& statement);


	/**
	* Executes SQL queries in this %Database instance. @n
	* Any query that does not give a dataset result can be run using this method; for example, CREATE, INSERT, UPDATE, DELETE.
	* The SELECT statement cannot be executed using this method. @n
	* If an application opens a database file in the secure mode
	* using Database::Construct(const Osp::Base::String& databasePath, long openMode, bool secureMode, long option),
	* the data set written by INSERT/UPDATE is automatically encrypted by the bada platform.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sql					The query to be executed
	* @param[in]	autoCommit			The flag to commit automatically
	* @exception 	E_SUCCESS			The method is successful.	
	* @exception	E_INVALID_STATE		The database has not opened or created as yet.
	* @exception	E_INVALID_ARG		The length of the query is invalid.
	* @exception	E_INVALID_OPERATION	The specified query is a SELECT statement.
	* @exception	E_SERVICE_BUSY		The database is busy.
	* @exception	E_DATABASE			The method has failed to compile the query or execute the compiled statement in the database engine.
	* @remarks	Use QueryN() to execute SELECT statements.
	* @see QueryN()
	*/
	result ExecuteSql(const Osp::Base::String& sql, bool autoCommit);


	/**
	* Executes the SELECT query in the calling %Database instance. @n
	* If an application opens a database file in the secure mode
	* using Database::Construct(const Osp::Base::String& databasePath, long openMode, bool secureMode, long option),
	* the data set read by SELECT is automatically decrypted by the bada platform.
	*
	* @since		1.0
	* @return		A pointer to the %DbEnumerator instance, @n
	* 				else @c null if an exception occurs or if no result set is generated after the successful execution of the SELECT query
	* @param[in]	query					The query to be executed
	* @exception 	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			The database has not been opened or created yet.
	* @exception	E_INVALID_ARG			The length of the query is invalid.
	* @exception	E_INVALID_OPERATION		The specified query is not a SELECT statement.
	* @exception	E_DATABASE				The method has failed to reset the compiled statement back to its initial state
	* 										or execute the compiled statement in the database engine.
	* @exception	E_SERVICE_BUSY			The database is busy.
	* @remarks		This method returns an enumerator if the result set is generated by the SELECT query.
	* 				@c null is returned if no result set is available after the successful execution of the SELECT query.
	* 				Note that, a return value of @c null does not mean that the statement execution has failed.
	* 				The enumerator returned by the SELECT query does not indicate any row before it calls
	* 				DbEnumerator::MoveNext().
	* 				The specific error code can be accessed using the GetLastResult() method.
	* @see ExecuteSql()
	*/
	DbEnumerator* QueryN(const Osp::Base::String& query);


// Operations related to the transaction
public:
	/**
	* Begins a transaction within this %Database instance.
	*
	* @since		1.0
	* @return		An error code
	* @exception 	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE 		The database has not opened or created as yet, or 
	*										the transaction has already begun.
	* @exception	E_DATABASE 				The method has failed to compile the query or execute the compiled statement in the database engine.
	* @exception	E_SERVICE_BUSY			The database is busy.
	* @see CommitTransaction(), RollbackTransaction()
	*/
	result BeginTransaction(void);


	/**
	* Commits a transaction within this %Database instance.
	*
	* @since		1.0
	* @return		An error code
	* @exception 	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			The database has not opened or created as yet, or
	*										the transaction mode is not activated.
	* @exception	E_DATABASE				The method has failed to compile the query or execute the compiled statement in the database engine.
	* @exception	E_SERVICE_BUSY			The database is busy.
	* @remarks		Database::CommitTransaction() automatically resets not only all the %DbStatement instances
	*				but also all the %DbEnumerator instances obtained from the current %Database instance.
	*				As a result, the prepared statement of the %DbStatement instances are reset to its initial state, ready to be re-executed,
	*				and enumerator of the %DbEnumerator instances are reset to the first position.
	*				Therefore, the user should be careful when the same instance of the %Database class is shared across multiple threads.
	*				Further, access to the %DbStatement or %DbEnumerator instances resets due to commit operation. This will eventually lead to crash.
	*				To avoid a crash, the user can use multiple database instances for each thread.
	*				Sharing of the same database instance across multiple threads is not recommended.
	* @see BeginTransaction(), RollbackTransaction()
	*/
	result CommitTransaction(void);


	/**
	* Aborts a running transaction within this %Database instance.
	*
	* @since		1.0
	* @return		An error code
	* @exception 	E_SUCCESS				The method is successful.	
	* @exception	E_INVALID_STATE			The database has not opened or created as yet, or
	*										the transaction mode is not activated.
	* @exception	E_DATABASE				The method has failed to compile the query or execute the compiled statement in the database engine.
	* @exception	E_SERVICE_BUSY			The database is busy.
	* @see BeginTransaction(), CommitTransaction()
	*/
	result RollbackTransaction(void);


	/**
	* Gets the database's filename.
	*
	* @since		1.0
	* @return		The filename of this %Database instance
	* @exception 	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			The database is not opened.
	*/
	Osp::Base::String GetName(void);


// Protected methods
protected:


// Static methods
public:

	/**
	* Deletes the database file with the specified file name.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	databasePath		The path of the database file to be deleted @n
	*									This path should be an absolute path beginning with an allowed path prefix. @n
	*									For more information on the allowed path prefixes for this argument,
	*									see @ref DatabasePrefixWritable "here".
	* @exception 	E_SUCCESS			The method is successful.
	* @exception 	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*										- The length of the specified @c databasePath is invalid. @n
	*										- The specified @c databasePath parameter contains an invalid path or the path ends with '/'. @n
	*										- The directory name path is missing. @n
	*										- The parent directory does not exist. @n
	*										- An I/O security issue.
	* @exception 	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception 	E_FILE_NOT_FOUND	The specified database file cannot be found.
	* @exception 	E_IO				An unexpected device failure has occurred as the media ejected suddenly or
   * 									file corruption is detected.

	*/
	static result Delete(const Osp::Base::String& databasePath);


	/**
	* Checks whether the database file exists.
	*
	* @since		1.0
	* @return		@c true if the database file exists, @n
	*				else @c false
	* @param[in]	databasePath		The path of the database file to be checked @n
	*									This path should be an absolute path beginning with an allowed path prefix. @n
	*									For more information on the allowed path prefixes for this argument,
	*									see @ref DatabasePrefixReadable "here".
	* @exception 	E_SUCCESS			The method is successful.
	* @exception 	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*										- The length of the specified @c databasePath is invalid. @n
	*										- The specified @c databasePath parameter contains an invalid path or the path ends with '/'. @n
	*										- The directory name path is missing. @n
	*										- The parent directory does not exist. @n
	*										- An I/O security issue.
	* @exception 	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	*/
	static bool Exists(const Osp::Base::String& databasePath);


	/**
	* Converts a normal database file to a secure database file. @n
	* A secure database file, that is converted by this method, is only used for the current application.
	* This method is static.
	*
	* @deprecated	This method is deprecated because using platform device key for encryption is no longer recommended.
	* @since		2.0
	* @return		An error code
	* @param[in]	plainDatabasePath		The normal (non-encrypted) database file path @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref DatabasePrefixReadable "here".
	* @param[in]	secureDatabasePath		The secure (encrypted) database file path to be created @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref DatabasePrefixWritable "here".
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The length of the specified path is @c 0 or exceeds system limitations. @n
 	*											- The specified path contains prohibited character(s). @n
	*											- The specified path is invalid. @n
	*											- The application ID of the application accessing '/Share2/[appid]' or '/Share2Ext/[appid]'
	*											  does not belong to the trusted application list of the provider application. @n
	*											- The input database file specified by the @c plainDatabasePath parameter
	*											  is an encrypted database file.
	* @exception 	E_ILLEGAL_ACCESS		The specified path is not permitted, or
	* 										access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already exists. 
	* @exception 	E_FILE_NOT_FOUND 		The specified database file does not exist.
	* @exception 	E_SERVICE_BUSY 			The database is busy now.
	* @exception 	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception 	E_DATABASE 				The method has failed to open or create a database file, or
	* 										the method has failed to compile the query or execute the compiled statement in the database engine.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*											- An unexpected device failure has occurred as the media ejected suddenly. @n
	*											- %File corruption is detected. @n
	* 											- A system error has occurred.
	*
	* @remarks		If an application shares a secure database file that is to be converted, use ConvertToSecureDatabase(const Osp::Base::String& plainDatabasePath,
	* 				const Osp::Base::String& secureDatabasePath, const Osp::Base::ByteBuffer& key).
	*/
	static result ConvertToSecureDatabase(const Osp::Base::String& plainDatabasePath, const Osp::Base::String& secureDatabasePath);


	/**
	* Converts a normal database file to a secure database file. @n
	* A secure database file, that is converted by this method, can be shared among applications with the same key value.
	* This method is static.
	*
	* @since		2.0
	* @return		An error code
	* @param[in]	plainDatabasePath		The normal (non-encrypted) database file path @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref DatabasePrefixReadable "here".
	* @param[in]	secureDatabasePath		The secure (encrypted) database file path to be created @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref DatabasePrefixWritable "here".
	* @param[in]	key						A key that encrypts a secure database file @n
	*										If the secure database file is converted with a specific key value,
	*										applications can access the same secure database file with the identical key value.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The length of the specified path is @c 0 or exceeds system limitations. @n
	*											- The specified path contains prohibited character(s). @n
	*											- The specified path is invalid. @n
	*											- The application ID of the application accessing '/Share2/[appid]' or '/Share2Ext/[appid]'
	*											  does not belong to the trusted application list of the provider application. @n
	*											- The input database file specified by the @c plainDatabasePath parameter
	*											  is an encrypted database file.
	* @exception 	E_ILLEGAL_ACCESS		The specified path is not permitted, or
	* 										access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception 	E_FILE_NOT_FOUND 		The specified database file does not exist.
	* @exception 	E_SERVICE_BUSY 			The database is busy now.
	* @exception 	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception 	E_DATABASE 				The method has failed to open or create a database file, or
	* 										the method has failed to compile the query or execute the compiled statement in the database engine.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*											- An unexpected device failure has occurred as the media ejected suddenly. @n
	*											- %File corruption is detected. @n
	* 											- A system error has occurred.
	*/
	static result ConvertToSecureDatabase(const Osp::Base::String& plainDatabasePath, const Osp::Base::String& secureDatabasePath, const Osp::Base::ByteBuffer& key);


// Private Member Functions
private:
	static result CheckAccessibilityToPath(void* path, int *pPathKind, int nPrivilegeKind);
	result ReleaseRsrc(void);	

	/**
	* Frees the resource allocated by this instance.
	*
	* @return		An error code
	* @exception	E_SUCCESS 			The method is successful.
	* @exception	E_INVALID_STATE		This instance has been finalized.
	* @exception	E_DATABASE			The method has failed to close the database file.
	*/
	result Dispose(void);

private:

	Osp::Base::String __dbName;
	Osp::Base::Runtime::Mutex *__pMutex;
	void *__pMDatabase;
	bool __bTransactionGoingOn;
	bool __isMonitored;

private:
	friend class DatabaseEx;
	class DatabaseEx *__pDatabaseEx;


};// Database
};// Osp::Io
};// Osp
#endif//_FIO_DATABASE_H_

