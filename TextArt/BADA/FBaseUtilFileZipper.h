/* $Change: 333898 $ */
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
 * @file		FBaseUtilFileZipper.h
 * @brief		This is the header file for the %FileZipper class.
 *
 * This header file contains the declarations of the %FileZipper class.
 */

#ifndef _FBASE_UTIL_FILEZIPPER_H_
#define _FBASE_UTIL_FILEZIPPER_H_


// Includes
#include "FBaseUtilTypes.h"
#include "FBaseString.h"


namespace Osp { namespace Base { namespace Utility {

/**
 * @class	FileZipper
 * @brief	This class provides methods that compresses data to a zip archive using zlib.
 * @since	2.0
 *
 * The %FileZipper class provides a zip operation for a simple and efficient file-based access to a zip archive. 
 * It is possible to create a zip file, and add the file to an already existing zip archive.
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/utility_namespace.htm">Utility</a>.
 *
 * The following example demonstrates how to use the %FileZipper class.
 *
 * @code
 *	#include <FBase.h>
 *	
 *	using namespace Osp::Base;
 *	using namespace Osp::Base::Utility;
 *	
 *	void
 *	MyClass::FileZipperSample(void)
 *	{
 *		FileZipper zip;
 *		zip.Construct(L"/Home/sample.zip");
 *
 *		// Add files to the zip file-archive
 *		zip.AddToZip(L"/Home/data1.txt");
 *		zip.AddToZip(L"/Home/dataDir/data2.txt");
 *	
 *	}
 * @endcode
 */
class _EXPORT_BASE_ FileZipper :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	FileZipper(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~FileZipper(void);


	/**
	 * Initializes this instance of %FileZipper with the specified filepath. @n
	 * This method opens an existing zip file in append mode. If the file does not exist, it creates and opens the file in
	 * append mode.
	 *
	 * @since				2.0
	 * @return			An error code
	 * @param [in] 		filePath  			The path of the zip file to be opened or created
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE 	This instance has already been constructed.
	 * @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *										- The length of the specified path is @c 0 or exceeds system limitations. @n
	 *										- The specified path contains prohibited character(s). @n
	 *										- The specified path is invalid.
	 * @exception		E_ILLEGAL_ACCESS 	The specified file path is inaccessible as per the bada platform policy.
	 * @exception		E_IO				An unexpected device failure has occurred.
	 * @remarks			The paths for '/Share/[appid]' and '/Share2/[appid]' are not supported.
	 * @see				Osp::Io::File
	 */
	result Construct(const String& filePath);


// Operation
public:

	/**
	 * Adds a new file to an already opened zip file.
	 *
	 * @since				2.0
	 * @return			An error code
	 * @param [in] 		filePath  	The path of the file to be added to the zip file
	 * @param [in] 		excludePath	Set to @c true to exclude the path and to store only the file name, @n
	 *								 else @c false to insert the entire path name in the zip archive
	 * @param [in] 		level		Set to @c BEST_SPEED or @c BEST_COMPRESSION @n
	 * 								By default, it is set to @c DEFAULT_COMPRESSION.
	 * @exception		E_SUCCESS			The method is successful. 
	 * @exception 		E_INVALID_STATE		The zip file has not been opened as yet.
	 * @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *										- The length of the specified path is @c 0 or exceeds system limitations. @n
	 *										- The specified path contains prohibited character(s). @n
	 *										- The specified path is invalid.
	 * @exception		E_ILLEGAL_ACCESS 	The specified file path is inaccessible as per the bada platform policy.
	 * @exception		E_FILE_NOT_FOUND  	The specified file cannot be found.
	 * @exception		E_FILE_ALREADY_EXIST	The specified file already exists in the zip archive, but the
	 *											flag for overwriting the file is not set.
	 * @exception		E_IO			An unexpected device failure has occurred.
	 * @remarks			The paths for '/Share/[appid]' and '/Share2/[appid]' are not supported.
	 * @remarks			If the value of @c excludePath is set to @c false, full path name is inserted to the zip-
	 *					archive. Therefore, developers should handle the path name carefully. @n
	 *			 		For example, if you add '/Home/Test/data.txt' file to the zip archive, and if the
	 *					@c excludePath parameter is set to @c false, while unzipping the file in '/Home'
	 *					directory, then the file is extracted in '/Home/Home/Test/data.txt'. 
	 * @see				Osp::Io::File
	 */
	result AddToZip(const String& filePath, bool excludePath = true, CompressionLevel level = DEFAULT_COMPRESSION);


	/**
	 * Gets the value of the overwritten flag. @n
	 * If @c true, it overwrites the existing file. 
	 *
	 * @since				2.0
	 * @return			The value of the overwritten flag for the zip file
	 */
	bool GetOverwriteFlag(void) const;


	/**
	 * Sets the value of the overwritten flag. @n
	 * If @c true, the existing file gets overwritten during file addition.
	 * The default value of this flag is @c false. 
	 *
	 * @since	2.0
	 * @param [in]		flag 	The flag value to set
	 */
	void SetOverwriteFlag(bool flag);


private:
// Lifecycle

	/**
	 * This is the copy constructor for this class.
	 * @param [in]		fileZipper		The instance of the FileZip class to copy from
	 * @remarks			This constructor is hidden.
	 */
	FileZipper(const FileZipper& fileZipper);

// Operator	

	/**
	 * This is the assignment operator.
	 * @param [in]		fileZipper		The instance of the FileZip class to assign from
	 * @remarks			This operator is hidden.
	 */
	FileZipper& operator =(const FileZipper& fileZipper);


private:
	void* 	__zFile;

	bool		__bOverwrite;
	String	__archiveName;


private:
	friend class FileZipperEx;
	class FileZipperEx* __pFileZipperEx;

};
}}}
#endif // _FBASE_UTIL_FILEZIPPER_H_

