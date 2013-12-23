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
 * @file		FBaseUtilFileUnzipper.h
 * @brief		This is the header file for the %FileUnzipper class.
 *
 * This header file contains the declarations of the %FileUnzipper class.
 */

#ifndef _FBASE_UTIL_FILEUNZIPPER_H_
#define _FBASE_UTIL_FILEUNZIPPER_H_


// Includes
#include "FBaseString.h"
#include "FBaseUtilZipEntry.h"

namespace Osp { namespace Base { namespace Utility {

/**
 * @class	FileUnzipper
 * @brief	This class provides methods that decompress data from a zip archive using zlib.
 * @since	2.0
 *
 * The %FileUnzipper class provides an unzip operation for a simple and efficient file-based access to a zip archive. 
 * It is possible to extract a zipped file completely or partially and access the entry of a zip archive.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/utility_namespace.htm">Utility</a>.
 * 
 * The following example demonstrates how to use the %FileUnzipper class.
 * @code
 *	#include <FBase.h>
 *	
 *	using namespace Osp::Base;
 *	using namespace Osp::Base::Utility;
 *	
 *	void
 *	MyClass::FileUnzipperSample(void)
 *	{
 *		int count = 0;
 *
 *		FileUnzipper unzip;
 *		unzip.Construct(L"/Home/sample.zip");
 *
 *		// Unzip the zip archive fully
 *		unzip.UnzipTo(L"/Home/");
 *
 *		// Unzip a file from the zip archive
 *		unzip.UnzipTo(L"/Home/Sample/", L"data1.txt");
 *	
 *		// Get the number of entries
 *		count = unzip.GetEntryCount();
 *
 *	}
 * @endcode
 */

class _EXPORT_BASE_ FileUnzipper :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	FileUnzipper(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~FileUnzipper(void);


	/**
	 * Initializes this instance of %FileUnzipper with the specified filepath. @n
	 * This method opens a zip file in the read mode.
	 *
	 * @since				2.0
	 *
	 * @return			An error code
	 * @param [in] 		filePath  			The path of the file to be opened or created
	 * @exception		E_SUCCESS			The method is successful. 
	 * @exception		E_INVALID_STATE		This instance has already been constructed.
	 * @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *										- The length of the specified path is @c 0 or exceeds system limitations. @n
	 *										- The specified path contains prohibited character(s). @n
	 *										- The specified path is invalid.
	 * @exception 		E_ILLEGAL_ACCESS 	The specified file path is inaccessible as per the bada platform policy.
	 * @exception		E_FILE_NOT_FOUND  	The specified file cannot be found or accessed.
	 * @exception		E_IO 				An unexpected device failure has occurred.
	 * @remarks			The paths for '/Share/[appid]' and '/Share2/[appid]' are not supported.
	 * @see				Osp::Io::File
	 */
	result Construct(const String& filePath);


// Operation
public:

	/**
	 * Unzips a zip file at the specified path or destination.
	 *
	 * @since				2.0
	 * @return			An error code
	 * @param [in] 		dirPath   			A directory path to unzip
	 * @exception		E_SUCCESS			The method is successful. 
	 * @exception 		E_INVALID_STATE		The file to unzip has not been opened as yet.
	 * @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *										- The length of the specified path is @c 0 or exceeds system limitations. @n
	 *										- The specified path contains prohibited character(s). @n
	 *										- The specified path is invalid.
	 * @exception 		E_ILLEGAL_ACCESS	The specified file path is inaccessible as per the bada platform policy.
	 * @exception		E_IO 				An unexpected device failure has occurred.
	 * @remarks			The paths for '/Share/[appid]' and '/Share2/[appid]' are not supported.
	 * @remarks			This operation consumes a lot of time if the zip archive contains large number of files or
	 *					directories.
	 *           		In such cases, it is recommended to call this method in a separate thread.
	 * @see				Osp::Io::File
	 */
	result UnzipTo(const String& dirPath) const;


	/**
	 * Extracts a zip entry from a zip archive to the specified path.
	 *
	 * @since				2.0
	 * @return			An error code
	 * @param [in] 		dirPath  			A directory path to unzip
	 * @param [in] 		zipEntryName		A zip entry name that could be a file or directory name
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception 		E_INVALID_STATE		The file to unzip has not been opened as yet.
	 * @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *										- The length of the specified path is @c 0 or exceeds system limitations. @n
	 *										- The specified path contains prohibited character(s). @n
	 *										- The specified path is invalid.
	 * @exception		E_ILLEGAL_ACCESS 	The specified file path is inaccessible as per the bada platform policy.
 	 * @exception		E_FILE_NOT_FOUND	The entry of the specified file or path cannot be found in the archive.
	 * @exception		E_IO 				An unexpected device failure has occurred.
	 * @remarks			The paths for '/Share/[appid]' and '/Share2/[appid]' are not supported.
	 * @remarks			If the value of @c zipEntryName is a directory name present in the archive, this method
	 *					creates an empty directory. @n
	 *					For example, UnzipTo(L"/Home/Test/", L"/someDir/") will create '/Home/Test/someDir'
	 *					directory only, and the files or subdirectories under 'someDir' will not be extracted.
	 * @see				Osp::Io::File
	 */
	result UnzipTo(const String& dirPath, const String& zipEntryName) const;


	/**
	 * Gets the number of entries present in a zip archive.
	 *
	 * @since				2.0
	 * @return			The number of entries present in a zip archive, @n
	 *					else @c -1 in case of an error
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE		The file has not been opened as yet.
	 * @exception		E_IO 				An unexpected device failure has occurred.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetEntryCount(void) const;


	/**
	 * Gets the number of files present in a zip archive.
	 *
	 * @since				2.0
	 * @return			The number of files present in a zip archive, @n
	 *					else @c -1 in case of an error
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE		The file has not been opened as yet.
	 * @exception		E_IO 				An unexpected device failure has occurred.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.	 
	 */
	int GetFileCount(void) const;


	/**
	 * Gets the number of directories present in a zip archive.
	 *
	 * @since				2.0
	 * @return			The number of directories present in a zip archive, @n
	 *					else @c -1 in case of an error
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE		The file has not been opened as yet.
	 * @exception		E_IO 				An unexpected device failure has occurred.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetDirectoryCount(void) const;


	/**
	 * Gets a zip entry associated with the file or directory name passed as parameter. 
	 *
	 * @since				2.0
	 * @return			An error code
	 * @param [in] 		zipEntryName		A zip entry name that could be a file or directory name
	 * @param [out]		entry				A reference to the ZipEntry
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception 		E_INVALID_STATE		The file has not been opened as yet.
	 * @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *										- The length of the specified path is @c 0 or exceeds system limitations. @n
	 *										- The specified path contains prohibited character(s). @n
	 *										- The specified path is invalid.
	 * @exception		E_FILE_NOT_FOUND	The entry of the specified file or path cannot be found in the archive.
	 * @exception		E_IO 				An unexpected device failure has occurred.
	 * @remarks			If the value of @c zipEntryName is a directory name, it should have a suffix '/'.
	 *					For example, L"/Home/Test/" or L"/Home/Test/DATA/".
	 */
	result GetEntry(const String &zipEntryName, ZipEntry &entry) const;


	/**
	 * Gets a zip entry associated with the index from the root directory.
	 *
	 * @since				2.0
	 * @return			An error code
	 * @param [in] 		index				An index of the zip entry to be accessed @n
	 *										The index starts from @c 0.
	 * @param [out] 	entry				A reference to the ZipEntry
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception 		E_INVALID_STATE		The file has not been opened as yet.
	 * @exception		E_INVALID_ARG		The specified index is out of range, or an invalid index is passed. 
	 * @exception		E_IO 				An unexpected device failure has occurred.
	 */
	result GetEntry(int index, ZipEntry &entry) const;


private:

// Lifecycle

	/**
	 * This is the copy constructor for this class.
	 * @param [in]	fileUnzipper	The instance of the FileUnzipper class to copy from
	 * @remarks		This constructor is hidden.
	 */
	FileUnzipper(const FileUnzipper& fileUnzipper);

// Operator	

	/**
	 * This is the assignment operator.
	 * @param [in]	fileUnzipper	The instance of the FileUnzipper class to assign from
	 * @remarks		This operator is hidden.
	 */
	FileUnzipper& operator =(const FileUnzipper& fileUnzipper);

private:
	void*	__uzFile;


private:
	friend class FileUnzipperEx;
	class FileUnzipperEx* __pFileUnzipperEx;

};

}}}
#endif // _FBASE_UTIL_FILEUNZIPPER_H_

