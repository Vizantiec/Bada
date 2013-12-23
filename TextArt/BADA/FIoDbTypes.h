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
 * @file		FIoDbTypes.h
 * @brief		This header file contains enum declarations of the Database class.
 *
 * This header file contains enum declarations of the %Database class.
 */
#ifndef _FIO_DB_TYPES_H_
#define _FIO_DB_TYPES_H_

namespace Osp { namespace Io {

#define DB_OPEN_READ_ONLY	(0x00000001L)
#define DB_OPEN_READ_WRITE	(0x00000002L)
#define DB_OPEN_CREATE		(0x00000004L)

/**
 * @enum	DbColumnType
 * Defines the column types.
 * 
 * @since  1.0
 */
enum DbColumnType
{
	DB_COLUMNTYPE_INT = 0,	/**< The column type is a 32-bit integer */
	DB_COLUMNTYPE_INT64,	/**< The column type is a 64-bit integer */
	DB_COLUMNTYPE_DOUBLE,	/**< The column type is double */
	DB_COLUMNTYPE_TEXT,		/**< The column type is text */
	DB_COLUMNTYPE_BLOB,		/**< The column type is blob */
	DB_COLUMNTYPE_NULL,		/**< The column type is null */
	DB_COLUMNTYPE_UNDEFINED /**< The column type is undefined */
};

/**
* @internal
* This is internal. If used in an application, the application can get rejected during the certification process.
* @enum __DbStatementType[A1][A1]
* Defines types of statement.
*
* @since  1.0
*/
enum __DbStatementType
{
	DB_STATEMENT_OTHER = 0,
	DB_STATEMENT_SELECT =1
};

};// Osp::Io
};// Osp
#endif//_FIO_DB_TABLE_H_

