/* $Change: 1262183 $ */
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
 * @file		FIoFile.h
 * @brief		This is the header file for the %File and %FileAttribute classes.
 *
 * This header file contains the declarations of the %File and %FileAttribute classes.
 */
#ifndef _FIO_FILE_H_
#define _FIO_FILE_H_

#include <FBaseDateTime.h>
#include <FBaseString.h>
#include <FBaseColIList.h>
#include <FBaseResult.h>
#include <FBaseByteBuffer.h>
#include <FBaseResource.h>
#include <FIoConfig.h>

namespace Osp {namespace Base {class String;}}
namespace Osp {namespace Base {class ByteBuffer;}}

namespace Osp { namespace Io {

#define FILEPATH_LEN_MAX				(200)

// Enumeration


/**
 * @enum FileSeekPosition
 * Defines the file seek position.
 *
 * @since	1.0
 */
enum FileSeekPosition
{
	FILESEEKPOSITION_BEGIN,			/**<The beginning of the file */
	FILESEEKPOSITION_CURRENT,		/**<The current position of the file */
	FILESEEKPOSITION_END			/**<The end of the file */
};


#define FILEATTRIBUTE_READONLY		MFILE_ATTRIBUTE_READONLY
#define FILEATTRIBUTE_HIDDEN		MFILE_ATTRIBUTE_HIDDEN
#define FILEATTRIBUTE_DIR			MFILE_ATTRIBUTE_DIR
#define FILEATTRIBUTE_SYSTEM		MFILE_ATTRIBUTE_SYSTEM


/**
 * @class	FileAttributes
 * @brief	This class provides a collection of the basic file attributes.
 * @since	1.0
 *
 * The %FileAttributes class provides the attributes of a file or directory.
 * It can be used to determine the various file properties such as file attributes
 * (read only, hidden, system, or directory), creation time, last modified time, and file size.
 *
 * For more information on the class features,
 * see <a href="../com.osp.cppappprogramming.help/html/dev_guide/io/io_namespace.htm">Io Guide</a>.
 *
 * The following example demonstrates how to use the %FileAttributes class.
 *
 * @code
#include <FBase.h>
#include <FIo.h>

using namespace Osp::Base;
using namespace Osp::Io;

int main(void)
{
	String fileName(L"/Home/test.txt");
	File file;
	FileAttributes attr;
	long long size;
	Osp::Base::DateTime dtCreate ;
	Osp::Base::DateTime dtModified ;
	result r = E_SUCCESS;

	r = File::GetAttributes(fileName, attr);
	if(IsFailed(r))
		goto CATCH;

	size = attr.GetFileSize();
	AppLog("* size=%d", size);

	dtCreate = attr.GetDateTime();
	AppLog("* creation time: %d year, %d month, %d day, %d hour, %d min, %d sec.\n",
		dtCreate.GetYear(),
		dtCreate.GetMonth(),
		dtCreate.GetDay(),
		dtCreate.GetHour(),
		dtCreate.GetMinute(),
		dtCreate.GetSecond()
		);

	dtModified = attr.GetLastModifiedTime();
	AppLog("* last modified time: %d year, %d month, %d day, %d hour, %d min, %d sec.\n",
		dtCreate.GetYear(),
		dtCreate.GetMonth(),
		dtCreate.GetDay(),
		dtCreate.GetHour(),
		dtCreate.GetMinute(),
		dtCreate.GetSecond()
		);

	if(attr.IsDirectory())
		AppLog("* This is a directory.");
	if(attr.IsHidden())
		AppLog("* This is a hidden file.");
	if(attr.IsReadOnly())
		AppLog("* This is a read-only file.");

	AppLog("Succeeded!");
	return 0;

CATCH:
	AppLog("Failed...");
	return -1;
}
 * @endcode
 */
class _EXPORT_IO_ FileAttributes :
	public Osp::Base::Object
{
public:

	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	*/
	FileAttributes(void);

	/**
	* @internal		This method is for internal use only. The bada platform team is not
	* 				responsible for any behavioral correctness, consistency, and
	* 				security-related issues that might arise after using this method.
	* Initializes this instance of FileAttributes with the specified Datetime, size, and attributes.
	*
	* @since		1.0
	* @param[in]	dateTime		The date and time of the Osp::Base::DateTime format
	* @param[in]	fileSize		The file size
	* @param[in]	attribute		The properties of file such as 'read only', 'hidden', 'system', and 'directory'
	*/
	FileAttributes(const Osp::Base::DateTime& dateTime, long long fileSize, unsigned long attribute);

	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~FileAttributes(void);


// Accessors
public:
	/**
	* Gets the file size.
	*
	* @since		1.0
	* @return		The file size in bytes
	*/
	long long GetFileSize(void) const;

	/**
	* Checks whether the current file is a directory.
	*
	* @since		1.0
    * @return		@c true if the file is a directory, @n
	*				else @c false
	*/
	bool IsDirectory(void) const;

	/**
	* Checks whether the file has a hidden attribute.
 	*
 	* @since		1.0
	* @return		@c true if the file has a hidden attribute, @n
	*				else @c false
	*/
	bool IsHidden(void) const;

	/**
	* Checks whether the file has a read-only attribute.
	*
	* @since		1.0
	* @return		@c true if the file has a read-only attribute, @n
	*				else @c false
	*/
	bool IsReadOnly(void) const;

	/**
	* @internal		This method is for internal use only. The bada platform team is not
	* 				responsible for any behavioral correctness, consistency, and
	* 				security-related issues that might arise after using this method.
	* Checks whether the file has a common file attribute.
	*
	* @since		1.0
	* @return		@c true if the file has a common file attribute, @n
	*				else @c false
	* @remarks		This method will soon be deprecated.
	*/
	bool IsNomalFile(void) const;

	/**
	* @internal		This method is for internal use only. The bada platform team is not
	* 				responsible for any behavioral correctness, consistency, and
	* 				security-related issues that might arise after using this method.
	* Checks whether the file has a system file attribute.
	*
	* @since		1.0
	* @return		@c true if the file has a system file attribute, @n
	*				else @c false
	* @remarks		This method will soon be deprecated.
	*/
	bool IsSystemFile(void) const;

	/**
	* Gets the date and time of the file creation.
	*
	* @since		1.0
	* @return		The date and time of the file creation
	*/
	Osp::Base::DateTime GetDateTime(void) const;


	/**
	* Gets the date and time of the last modification to the file.
	*
	* @since		1.0
	* @return		The date and time of the last modification to the file
	*/
	Osp::Base::DateTime GetLastModifiedTime(void) const;


	/**
	 *	Compares the specified instance to the calling instance.
	 *
	 *  @since		1.0
	 *	@return		@c true if the specified instance is equal to the current instance, @n
	 *				else @c false
	 *	@param[in]	obj	The object to be compared with the current instance
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const;

private:
	friend class File;
	void __Set(const Osp::Base::DateTime& dateTime, const Osp::Base::DateTime& modifiedTime,long long fileSize, unsigned long attribute);

	long long __fileSize;
	bool __bDirectory;
	bool __bHidden;
	bool __bReadOnly;
	bool __bSysFile;
	Osp::Base::DateTime __creationTime;
	Osp::Base::DateTime __lastModifiedTime;

private:
	friend class FileAttributesEx;
	class FileAttributesEx *__pFileAttributesEx;

};



/**
 * @class	File
 * @brief	This class provides the basic file I/O operations, such as read, write, create, and remove.
 * @since	1.0
 *
 * The %File class provides the basic file I/O operations, such as read, write, create, and remove.
 * It only provides synchronous file read-write with raw data bytes or string data.
 * It is constructed using the Construct() method to access files and control file I/O operations.
 * There is no method like Close() to close the opened file instances.
 * The only way to close an opened file is by invoking the destructor of the %File class.
 * Therefore, if the %File class is instantiated as a local variable, it is not closed until it goes out of scope.
 * To get a detailed information on a file or directory, use the FileAttributes and Directory classes.
 * All the members of this class are guaranteed to be thread-safe.
 *
 * For more information on class features and the file system with allowed path prefixes,
 * see <a href="../com.osp.cppappprogramming.help/html/dev_guide/io/io_namespace.htm">Io Guide</a>
 * and <a href="../com.osp.documentation.help/html/bada_overview/bada_file_system.htm">bada File System</a>, respectively.
 *
 * The following example demonstrates how to use the %File class.
 *
 * @code

#include <FBase.h>
#include <FIo.h>

using namespace Osp::Base;
using namespace Osp::Io;

int main(void)
{
	String fileName(L"/Home/test.txt");
	File file;
	char buffer[10];
	char buffer2[5];
	int i;
	int readCnt;
	result r = E_SUCCESS;

	// Creates file
	r = file.Construct(fileName, L"w+");
	if(IsFailed(r))
		goto CATCH;

	for(i = 0 ; i < 10 ; i++)
		buffer[i] = (char) i;

	// Writes to the file
	r = file.Write(buffer, 10);
	if(IsFailed(r))
		goto CATCH;

	// Repositions the file pointer
	r = file.Seek(FILESEEKPOSITION_CURRENT, -5);
	if(IsFailed(r))
		goto CATCH;

	// Reads
	readCnt = file.Read(buffer2, 5);
	r = GetLastResult();
	if(IsFailed(r))
		goto CATCH;
	if(readCnt != 5)
		goto CATCH;

	// Checks the correctness of the read data
	for(i = 0; i < readCnt ; i++)
	{
		char m, n;
		m = buffer2[i];
		n = buffer[i + 5];
		if(m != n)
			goto CATCH;
	}
	AppLog("Succeeded!");
	return 0;

CATCH:
	AppLog("Failed...");
	return -1;
}

 * @endcode
 */

/**
 * @page FilePrefixReadable Allowed Path Prefixes
 * - '/Home' or '/HomeExt' (read and write permission)
 * - '/Home/Share', '/Home/Share2', '/HomeExt/Share', or '/HomeExt/Share2' (read and write permission)
 * - '/Share/[appid]' or '/ShareExt/[appid]' (read-only permission)
 * - '/Share2/[appid]' or '/Share2Ext/[appid]' (read and write permission)
 * - '/Res' (read-only permission)
 * - '/Media', '/Media/Images', '/Media/Sounds', '/Media/Videos', '/Media/Themes', or '/Media/Others' (read-only permission)
 * - '/Storagecard/Media', '/Storagecard/Media/Images', '/Storagecard/Media/Sounds', '/Storagecard/Media/Videos',
 *   '/Storagecard/Media/Themes', or '/Storagecard/Media/Others' (read-only permission)
 *
 * Refer to <a href="../com.osp.documentation.help/html/bada_overview/bada_file_system.htm">bada File System</a>
 * for the detailed usage and permission for each of the allowed path prefixes.
 */

/**
 * @page FilePrefixWritable Allowed Path Prefixes
 * - '/Home' or '/HomeExt' (read and write permission)
 * - '/Home/Share', '/Home/Share2', '/HomeExt/Share', or '/HomeExt/Share2' (read and write permission)
 * - '/Share2/[appid]' or '/Share2Ext/[appid]' (read and write permission) @n
 *
 * Refer to <a href="../com.osp.documentation.help/html/bada_overview/bada_file_system.htm">bada File System</a>
 * for the detailed usage and permission for each of the allowed path prefixes.
 */

class _EXPORT_IO_ File
	: public Osp::Base::Object,
	public Osp::Base::__Resource
	/*: public virtual Osp::Base::Runtime::IThreadSafe*/
{

// Lifecycle
public:

	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	* @remarks		After creating an instance of this class,
	* 				the Construct() method must be called explicitly to initialize this instance.
	*/
	File(void);


	/**
	* Initializes this instance of %File with the specified parameters. @n
	* This method safely opens an existing file or creates a new file according to the specified file open mode.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]		filePath				The path of the file that is to be opened or created @n
	*											This path should be an absolute path beginning with an allowed path prefix. @n
	*											For more information on the allowed path prefixes for this argument,
	*											see @ref FilePrefixReadable "here".
	* @param[in]		openMode				The file opening mode @n
	*											It can be any one of the following: "r", "r+", "w", "w+", "a", "a+".
	*											In addition to this, "b"(binary) can also be used. Although "b" is recognized by
	*											this method for compatibility, it has no effect on the actual file operation.
	*											The meaning of each file opening mode is exactly the same as the file opening modes of
	*											a standard C library.
	* @param[in]		createParentDirectories	Set to @c true to automatically create non-existent parent directories up to destination, @n
	*											else @c false @n
	*											This parameter is useful only if the specified @c openMode allows creation of an absent
	*											file. For example, the following modes: "w", "w+", "a" and "a+". @n
	*											If the value of @c openMode is not any one of these, E_INVALID_ARG exception is thrown.
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_STATE			This instance has already been constructed.
	* @exception		E_INVALID_ARG			Either of the following conditions has occurred: @n
	*												- The overall length of the specified path is equal to @c 0 or
	*												  exceeds system limitations. @n
	* 												- The specified path contains prohibited character(s). @n
	*												- The specified path is invalid. @n
	* 												- The specified combination of the file opening mode is not allowed. @n
	*	 											- The application ID of the application accessing '/Share2/[appid]' or '/Share2Ext/[appid]'
	*	 											  does not belong to the trusted application list of the provider application. @n
	*	 											- A file encrypted by the bada platform cannot be properly opened by this method. @n
	*												  Therefore, use Construct(const Osp::Base::String& filePath, const
	*												  Osp::Base::String& openMode, bool secureMode, bool createParentDirectories) in this case.
	* @exception		E_ILLEGAL_ACCESS		The specified path is not permitted, or
	* 											access is denied due to insufficient permission. @n
	*											For example, opening a read-only file in the write mode or
	*											opening a file that is previously opened in the no-sharing mode.
	* @exception		E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception		E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception		E_STORAGE_FULL			The disk space is full.
	* @exception		E_IO					An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	*
	* @remarks			The following file opening mode strings are recognized by this method: "w+", "wb+", "w+b", "w", "wb", "a+",
	*					"ab+", "a+b", "a", "ab", "r+", "rb+", "r+b", "r", "rb". @n
	*					Other strings lead to E_INVALID_ARG. However, "b"(binary) open mode is ignored internally.
	*/
	result Construct(const Osp::Base::String& filePath, const Osp::Base::String& openMode, bool createParentDirectories = false);


	/**
	* Initializes this instance of %File with the specified parameters. @n
	* This method safely opens an existing normal/secure file or creates a new one according to the specified file open mode.
	* An application using this method cannot access the secure files that are created by other applications
	* because of the application-specific key.
	*
	* @deprecated		This method is deprecated because using platform device key for encryption is no longer recommended.
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		filePath				The path of the file that is to be opened or created @n
	*											This path should be an absolute path beginning with an allowed path prefix. @n
	*											For more information on the allowed path prefixes for this argument,
	*											see @ref FilePrefixReadable "here".
	* @param[in]		openMode				The file opening mode @n
	*											It can be one of the following: "r", "r+", "w", "w+", "a", "a+".
	*											In addition to this, "b"(binary) can also be used.
	*											Although "b" is recognized by this method for compatibility,
	*											it has no effect on the actual file operation.
	*											The meaning of each file opening mode is exactly the same as the file opening modes of
	*											a standard C library.
	* @param[in]		secureMode				Set to @c true to deal with a file in the encrypted form, @n
	*											else @c false @n
	*	 										An application cannot open a normal file in a secure mode and a secure file in a
	*											normal mode.
	* @param[in]		createParentDirectories	Set to @c true to automatically create non-existent parent directories up to destination, @n
	*											else @c false @n
	*											This parameter is useful only if the specified @c openMode allows creation of an absent
	*											file. For example, the following modes: "w", "w+", "a" and "a+". @n
	*											If the value of @c openMode is not any one of these, E_INVALID_ARG exception is thrown.
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_STATE			This instance has already been constructed.
	* @exception		E_INVALID_ARG			Either of the following conditions has occurred: @n
	*												- The overall length of the specified path is equal to @c 0 or
	*												  exceeds system limitations. @n
	* 												- The specified path contains prohibited character(s). @n
	*												- The specified path is invalid. @n
	* 												- The specified combination of the file opening mode is not allowed. @n
	*	 											- The application ID of the application accessing '/Share2/[appid]' or '/Share2Ext/[appid]'
	*	 											  does not belong to the trusted application list of the provider application. @n
	*	 											- The secure file cannot be accessed in a normal mode or
	*												  the normal file cannot be accessed in a secure mode.
	* @exception		E_ILLEGAL_ACCESS		The specified path is not permitted, or
	* 											access is denied due to insufficient permission. @n
	*											For example, opening a read-only file in the write mode or
	*											opening a file that is previously opened in the no-sharing mode.
	* @exception		E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception		E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception		E_STORAGE_FULL			The disk space is full.
	* @exception		E_IO					An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	*												
	*/
	result Construct(const Osp::Base::String& filePath, const Osp::Base::String& openMode, bool secureMode, bool createParentDirectories);


    /**
    * Initializes this instance of %File with the specified parameters. @n
	* This method safely opens an existing normal/secure file or creates a new one according to the specified file open mode.
	* Applications using this method can access the same secure files that are created by other applications
	* with the identical key value.
	*
	* @deprecated		This method is deprecated and will be replaced with a new one in the near future.
	* @since			2.0
	* @return			An error code
	* @param[in]		filePath				The path of the file that is to be opened or created @n
	*											This path should be an absolute path beginning with an allowed path prefix. @n
	*											For more information on the allowed path prefixes for this argument,
	*											see @ref FilePrefixReadable "here".
	* @param[in]		openMode				The file opening mode @n
	*											It can be one of the following: "r", "r+", "w", "w+", "a", "a+".
	*											In addition to this, "b"(binary) can also be used.
	*											Although "b" is recognized by this method for compatibility,
	*											it has no effect on the actual file operation.
	*											The meaning of each file opening mode is exactly the same as the file opening modes of
	*											a standard C library.
	* @param[in]		secureMode				Set to @c true to deal with a file in the encrypted form, @n
	*											else @c false @n
	*	 										An application cannot open a normal file in a secure mode and a secure file in a
	*											normal mode.
	* @param[in]		key						A key that encrypts or decrypts a secure file @n
	* 											If the secure file is created with a specific key value,
	* 											applications can access the same secure file with the identical key value.
	* @param[in]		createParentDirectories	Set to @c true to automatically create non-existent parent directories up to destination, @n
	*                                           else @c false @n
	*											This parameter is useful only if the specified @c openMode allows creation of an absent
	*											file. For example, the following modes: "w", "w+", "a" and "a+". @n
	*											If the value of @c openMode is not any one of these, E_INVALID_ARG exception is thrown.
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_STATE			This instance has already been constructed.
	* @exception		E_INVALID_ARG			Either of the following conditions has occurred: @n
	*												- The overall length of the specified path is equal to @c 0 or
	*												  exceeds system limitations. @n
	* 												- The specified path contains prohibited character(s). @n
	*												- The specified path is invalid. @n
	* 												- The specified combination of the file opening mode is not allowed. @n
	*	 											- The application ID of the application accessing '/Share2/[appid]' or '/Share2Ext/[appid]'
	*	 											  does not belong to the trusted application list of the provider application. @n
	*	 											- The secure file cannot be accessed in a normal mode or
	*												  the normal file cannot be accessed in a secure mode.
	* @exception		E_ILLEGAL_ACCESS		The specified path is not permitted, or
	* 											access is denied due to insufficient permission. @n
	*											For example, opening a read-only file in the write mode or
	*											opening a file that is previously opened in the no-sharing mode.
	* @exception		E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception		E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception		E_STORAGE_FULL			The disk space is full.
	* @exception		E_IO					Either of the following conditions has occurred: @n
	*												- An unexpected device failure has occurred as the media ejected suddenly. @n
	*												- %File corruption is detected. @n
    *                                            	- The specified @c key is incorrect.
    */
    result Construct(const Osp::Base::String& filePath, const Osp::Base::String& openMode, bool secureMode, const Osp::Base::ByteBuffer& key, bool createParentDirectories);


	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	virtual ~File(void);


// Operations
public:
	/**
	* Reads the byte data from the current file pointer. @n
	* The user-specified ByteBuffer is filled with the byte data from the current position in the file.
	* The read operation continues until the specified ByteBuffer is filled or end-of-file is met. @n
	* In the secure mode, the byte data read from the secure file is automatically decrypted by a platform security module.
	*
	* @since			1.0
	* @return			An error code
	* @param[in, out]	buffer				A reference to the buffer that is used to receive the byte data read from the file
	* @exception 		E_SUCCESS			The method is successful.
	* @exception 		E_INVALID_STATE		The file has not been opened as yet.
	* @exception 		E_INVALID_ARG		The specified @c buffer has no space to store the read data, or
	*										the file handle is invalid (either the file is closed by another method, or the memory is corrupted).
	* @exception 		E_ILLEGAL_ACCESS	The file is not opened for read operation, or
	* 										access is denied due to insufficient permission.
	* @exception 		E_END_OF_FILE		The file pointer has reached end-of-file.
	* @exception 		E_IO				An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	* @remarks			The ByteBuffer should be constructed before being passed to the method.
	*/
	result Read(Osp::Base::ByteBuffer& buffer);


	/**
	* Reads the byte data from the current file pointer and copies it to the specified buffer. @n
	* In the secure mode, the byte data read from the secure file is automatically decrypted by a platform security module.
	*
	* @since			1.0
	* @return			The length of the data read in bytes, @n
	*					else @c 0 in case of failure
	* @param[out]		buffer				A pointer to the user-supplied buffer where the read data is copied
	* @param[in]		length				The buffer length in bytes
	* @exception	 	E_SUCCESS			The method is successful.
	* @exception 		E_INVALID_STATE		The file has not been opened as yet.
	* @exception 		E_INVALID_ARG		Either of the following conditions has occurred: @n
	*											- The specified @c buffer contains a @c null pointer. @n
	*											- The length of the specified @c buffer is equal to or smaller than @c 0. @n
	*											- The file handle is invalid (either the file is closed by another method, or the memory is corrupted).
	* @exception 		E_ILLEGAL_ACCESS	The file is not opened for read operation, or
	* 										access is denied due to insufficient permission.
	* @exception 		E_END_OF_FILE		The file pointer has reached end-of-file.
	* @exception 		E_IO				An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.
	*/
	int Read(void *buffer, int length);


	/**
	* Reads the string data from the current file pointer and copies the string to the specified buffer (it is assumed that the
	* file is in the UTF-8 format). @n
	* The read operation continues until new line character or end-of-file is met.
	* In the secure mode, the string data read from the secure file is automatically decrypted by a platform security module.
	*
	* @since			1.0
	* @return			An error code
	* @param[out]		buffer				A reference to the buffer where the data is copied
	* @exception	 	E_SUCCESS			The method is successful.
	* @exception 		E_INVALID_STATE		The file has not been opened as yet.
	* @exception 		E_INVALID_ARG		The file handle is invalid (either the file is closed by another method, or the
	*										memory is corrupted).
	* @exception 		E_ILLEGAL_ACCESS	The file is not opened for read operation, or
	* 										access is denied due to insufficient permission.
	* @exception 		E_END_OF_FILE		The file pointer has reached end-of-file.
	* @exception 		E_IO				An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	* @remarks			To get the expected string value from a file, which is not in the UTF-8 format (Unicode or any other format),
	*					user should use other encoding or decoding methods of the Osp::Text namespace after reading the content of
	*					a file in binary format. @n
	*					The maximum length of characters read by this method is defined as 4096.
	*					Therefore, if the length of a single line (considering new line character or end-of-file) from the current
	*					file position is longer than 4096, the rest of the characters remain as not read. @n
	*					'ByteBuffer' or 'void*' version of the File::Read() API can be used to overcome this limitation.
	*/
	result Read(Osp::Base::String& buffer);


	/**
	* Writes the entire data from the specified buffer to a file. @n
	* In the secure mode, the byte data written by a user is automatically encrypted to the secure file by a platform security module.
	* The size of a secure file can be greater than the size of a normal (original) file because of the encryption.
	* However, the file pointer for a secure file is equal to the file pointer for an original file.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]		buffer				A reference to the buffer that contains byte data to be written
	* @exception	 	E_SUCCESS			The method is successful.
	* @exception 		E_INVALID_STATE		The file has not been opened as yet.
	* @exception 		E_INVALID_ARG		The file handle is invalid (either the file is closed by another method, or the
	*										memory is corrupted).
	* @exception 		E_ILLEGAL_ACCESS	The file is not opened for write operation, or
	* 										access is denied due to insufficient permission.
	* @exception 		E_STORAGE_FULL		The disk space is full.
	* @exception 		E_IO				An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	*/
	result Write(const Osp::Base::ByteBuffer& buffer);


	/**
	* Writes the byte data into a file. @n
	* In the secure mode, the byte data written by a user is automatically encrypted to the secure file by a platform security module.
	* The size of a secure file can be greater than the size of a normal (original) file because of the encryption.
	* However, the file pointer for a secure file is equal to the file pointer for an original file.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]		buffer 				A pointer to the user-supplied buffer that contains @c byte data to be written
	* @param[in]		length				The buffer length in bytes
	* @exception	 	E_SUCCESS			The method is successful.
	* @exception 		E_INVALID_STATE		The file has not been opened as yet.
	* @exception 		E_ILLEGAL_ACCESS	The file is not opened for write operation, or
*						        access is denied due to insufficient permission.
	* @exception 		E_INVALID_ARG		Either of the following conditions has occurred: @n
	*											- The specified @c buffer contains a @c null pointer. @n
	*											- The specified buffer length is equal or smaller than @c 0. @n
	*											- The file handle is invalid (either the file is closed by another method, or the
	*											  memory is corrupted).
	* @exception 		E_STORAGE_FULL		The disk space is full.
	* @exception 		E_IO				An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.

	*/
	result Write(const void *buffer, int length);


	/**
	* Writes the string data into a file. @n
    * In the secure mode, the string data written by a user is automatically encrypted to the secure file by a platform security
	* module.
	* The size of a secure file can be greater than the size of a normal (original) file because of the encryption.
	* However, the file pointer for a secure file is equal to the file pointer for an original file.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]		buffer 				A reference to the buffer that contains string data to be written
	* @exception		E_SUCCESS			The method is successful.
	* @exception 		E_INVALID_STATE		The file has not been opened as yet.
	* @exception 		E_ILLEGAL_ACCESS	The file is not opened for write operation, or
*						        access is denied due to insufficient permission.
	* @exception 		E_INVALID_ARG		The specified @c buffer contains an empty string, or
	*										the file handle is invalid (either the file is closed by another method, or the
	*											memory is corrupted).
	* @exception 		E_STORAGE_FULL		The disk space is full.
	* @exception 		E_IO				Either of the following conditions has occurred: @n
	* 											- An unexpected device failure has occurred as the media ejected suddenly. @n
	*											- %File corruption is detected. @n
	*											- The volume or quota is no more available.
	*/
	result Write(const Osp::Base::String& buffer);


	/**
	* Flushes the internally buffered data into a permanent storage immediately.
	*
	* @since			1.0
	* @return			An error code
	* @exception	 	E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The file has not been opened as yet.
	* @exception		E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception		E_INVALID_ARG		The file handle is invalid (either the file is closed by another method, or the
	*										memory is corrupted).
	* @exception 		E_IO				An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	*/
	result Flush(void);


	/**
	* Gets the offset of the current file pointer relative to the beginning of the file. @n
	* The size of a secure file can be greater than the size of a normal (original) file because of the encryption.
	* However, the file pointer for a secure file is equal to the file pointer for an original file.
	*
	* @since			1.0
	* @return			The offset of the current file pointer, @n
	*					else @c -1L if an error occurs
	* @exception	 	E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The file has not been opened as yet.
	* @exception		E_INVALID_ARG		The file handle is invalid (either the file is closed by another method, or the
	*										memory is corrupted).
	* @exception 		E_IO				An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.
	* @see				Seek()
	*/
	int Tell(void) const;


	/**
	* Repositions the file pointer associated with an opened file. @n
	* Each opened file has its own file pointer, and it points to the next byte to be read or written in the file.
	* The repositioning offset can be specified with respect to the beginning of file, current position, or end of the file.
	* If the file pointer is over the end-of-file, it expands the file size to the specified position. But the expanded area is
	* filled with garbage values or zero depending on the native OS. @n
	* The size of a secure file can be greater than the size of a normal (original) file because of the encryption.
	* However, the file pointer for a secure file is equal to the file pointer for an original file.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]		position			The origin from where to start the repositioning a file pointer
	* @param[in]		offset 				The number of bytes to move a file pointer @n
	*										A negative offset moves the pointer backwards.
	* @exception 		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The file has not been opened as yet.
	* @exception		E_INVALID_ARG		The file handle is invalid (either the file is closed by another method, or the
	*										memory is corrupted).
	* @exception		E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception 		E_STORAGE_FULL		The disk space is full.
	* @exception 		E_IO				Either of the following conditions has occurred: @n
	* 										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- Detected corruption of a file. @n
	*										- The volume or quota is no more available.
	* @see				FileSeekPosition()
	*/
	result Seek(FileSeekPosition position, long offset);


	/**
	* Truncates the file size to the specified length. @n
	* If the specified length is less than the length of file, the bytes present between the @c length and size of a file are
	* removed. @n
	* If the file size is small, its size is increased. @n
	* The size of a secure file can be greater than the size of a normal (original) file because of the encryption.
	* However, the file pointer for a secure file is equal to the file pointer for an original file.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]		length				The required file size in bytes after this method is executed
	* @exception	 	E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The file has not been opened as yet.
	* @exception 		E_ILLEGAL_ACCESS	The file is not opened for write operation, or
*						        access is denied due to insufficient permission.
	* @exception		E_INVALID_ARG		The specified @c length has a negative value, or
	*										the file handle is invalid (either the file is closed by another method, or the
	*											memory is corrupted).
	* @exception 		E_STORAGE_FULL		The disk space is full.
	* @exception 		E_IO				Either of the following conditions has occurred: @n
	* 										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- Detected corruption of a file. @n
	*										- The volume or quota is no more available.
	*/
	result Truncate(int length);


	/**
	* Gets the path associated with an opened file.
	*
	* @since			1.0
	* @return			The file path to the currently opened file if successful, @n
	*					else an empty string in case of failure
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		The file has not been opened as yet.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::String GetName(void);

// static methods
public:
	/**
	* Deletes the file specified. @n
	* The opened file cannot be deleted.This method is static.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]		filePath			The path of the file to be deleted @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref FilePrefixWritable "here".
	* @exception	 	E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	*											- The overall length of the specified path is equal to @c 0 or
	*											  exceeds system limitations. @n
	* 											- The specified path contains prohibited character(s). @n
	*											- The specified path is invalid. @n
	*	 										- The application ID of the application accessing '/Share2/[appid]' or '/Share2Ext/[appid]'
	*	 										  does not belong to the trusted application list of the provider application.
	* @exception		E_ILLEGAL_ACCESS	The specified path is not permitted, or
	* 										access is denied due to insufficient permission. @n
	* 										For example, opening a read-only file in the write mode or
	* 										opening a file that is previously opened in the no-sharing mode.
	* @exception		E_FILE_NOT_FOUND	An entry for the specified file or path cannot be found.
	* @exception 		E_IO				An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	* @remarks 			The opened file cannot be deleted.
	*/
	static result Remove(const Osp::Base::String& filePath);


	/**
	* Moves the specified file to another location. @n
	* The opened files cannot be moved. This method is static.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]		oldFilePath				The old file path @n
	*											This path should be an absolute path beginning with an allowed path prefix.
	*											For more information on the allowed path prefixes for this argument,
	*											see @ref FilePrefixWritable "here".
	* @param[in]		newFilePath				The new file path @n
	*											This path should be an absolute path beginning with an allowed path prefix.
	*											For more information on the allowed path prefixes for this argument,
	*											see @ref FilePrefixWritable "here".
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_ARG			Either of the following conditions has occurred: @n
	*												- The overall length of the specified path is equal to @c 0 or
	*												  exceeds system limitations. @n
	* 												- The specified path contains prohibited character(s). @n
	*												- The specified path is invalid. @n
	*	 											- The application ID of the application accessing '/Share2/[appid]' or '/Share2Ext/[appid]'
	*	 											  does not belong to the trusted application list of the provider application.
	* @exception		E_ILLEGAL_ACCESS		The specified path is not permitted, or
	* 											access is denied due to insufficient permission. @n
	* 											For example, opening a read-only file in the write mode or
	* 											opening a file that is previously opened in the no-sharing mode.
	* @exception		E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception		E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception		E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception 		E_STORAGE_FULL			The disk space is full.
	* @exception 		E_IO					Either of the following conditions has occurred: @n
	* 											- An unexpected device failure has occurred as the media ejected suddenly. @n
	*											- Detected corruption of a file. @n
	*											- The volume or quota is no more available.
	* @see				Copy(), Remove()
	*/
	static result Move(const Osp::Base::String& oldFilePath, const Osp::Base::String& newFilePath);


	/**
	* Copies the existing source file to the destined location. @n
	* This method is static.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]		srcFilePath		 		The source file path @n
	*											This path should be an absolute path beginning with an allowed path prefix.
	*											For more information on the allowed path prefixes for this argument,
	*											see @ref FilePrefixReadable "here".
	* @param[in]		destFilePath	 		The destination file path @n
	*											This path should be an absolute path beginning with an allowed path prefix.
	*											For more information on the allowed path prefixes for this argument,
	*											see @ref FilePrefixWritable "here".
	* @param[in]		failIfExist				Set to @c true to return an error if the destination file already exists, @n
	*											else @c false
	* @exception	 	E_SUCCESS				The method is successful.
	* @exception		E_INVALID_ARG			Either of the following conditions has occurred: @n
	*												- The overall length of the specified path is equal to @c 0 or
	*												  exceeds system limitations. @n
	* 												- The specified path contains prohibited character(s). @n
	*												- The specified path is invalid. @n
	*	 											- The application ID of the application accessing '/Share2/[appid]' or '/Share2Ext/[appid]'
	*	 											  does not belong to the trusted application list of the provider application.
	* @exception		E_ILLEGAL_ACCESS		The specified path is not permitted, or
	* 											access is denied due to insufficient permission. @n
	* 											For example, opening a read-only file in the write mode or
	* 											opening a file that is previously opened in the no-sharing mode.
	* @exception		E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception		E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception		E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception 		E_STORAGE_FULL			The disk space is full.
	* @exception 		E_IO					Either of the following conditions has occurred: @n
	* 											- An unexpected device failure has occurred as the media ejected suddenly. @n
	*											- Detected corruption of a file. @n
	*											- The volume or quota is no more available.
	* @see				Move(), Remove()
	*/
	static result Copy(const Osp::Base::String& srcFilePath, const Osp::Base::String& destFilePath, bool failIfExist);


	/**
	* Reads the file information such as size, attribute, creation date, and so on. @n
	* This method is static.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	filePath			The path of the file @n
	*									This path should be an absolute path beginning with an allowed path prefix. @n
	*									For more information on the allowed path prefixes for this argument,
	*									see @ref FilePrefixReadable "here".
	* @param[out]	attribute			A %File attribute instance
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*										- The overall length of the specified path is equal to @c 0 or
	*										  exceeds system limitations. @n
	* 										- The specified path contains prohibited character(s). @n
	*										- The specified path is invalid. @n
	*	 									- The application ID of the application accessing '/Share2/[appid]' or '/Share2Ext/[appid]'
	*	 									  does not belong to the trusted application list of the provider application.
	* @exception	E_ILLEGAL_ACCESS	The specified path is not permitted, or
	* 									access is denied due to insufficient permission.
	* @exception	E_FILE_NOT_FOUND	An entry for the specified file or path cannot be found.
	* @exception 	E_IO				An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	*/
	static result GetAttributes(const Osp::Base::String& filePath, FileAttributes& attribute);


	/**
	* Gets only the file name from the specified file path. @n
	* For example, if the file path passed is '/Home/file.txt', 'file.txt' is returned.
	* This method is static.
	*
	* @since		1.0
	* @return		The file name of type String
	* @param[in]	filePath		The path of the file
	* @exception 	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The length of the specified path is @c 0 or exceeds system limitations.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			GetFileExtension()
	*/
	static const Osp::Base::String GetFileName(const Osp::Base::String& filePath);


	/**
	* Gets the file extension of the specified file path. @n
	* This method is static.
	*
	* @since		1.0
	* @return		The file extension, @n
	*				else an empty string if the file has no extension
	* @param[in]	filePath		The path of the file
	* @exception 	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The length of the specified path is @c 0 or exceeds system limitations.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			GetFileName()
	*/
	static  const Osp::Base::String GetFileExtension(const Osp::Base::String& filePath);


	/**
	* Checks whether the specified file or directory exists. @n
	* This method is static.
	*
	* @since		1.0
	* @return		@c true if file or directory exists, @n
	*				else @c false
	* @param[in]	filePath			The path of the file or directory @n
	*									This path should be an absolute path beginning with an allowed path prefix. @n
	*									For more information on the allowed path prefixes for this argument,
	*									see @ref FilePrefixReadable "here".
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*										- The overall length of the specified path is equal to @c 0 or
	*										  exceeds system limitations. @n
	* 										- The specified path contains prohibited character(s). @n
	*										- The specified path is invalid. @n
	*	 									- The application ID of the application accessing '/Share2/[appid]' or '/Share2Ext/[appid]'
	*	 									  does not belong to the trusted application list of the provider application.
	* @exception	E_ILLEGAL_ACCESS	The specified path is not permitted, or
	* 									access is denied due to insufficient permission.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	static bool IsFileExist(const Osp::Base::String& filePath);


	/**
	* @if PRIVCORE
	* Gets a list of paths to all the apps installed on the device. @n
	* This method is static.
	*
	* @since 		1.2
	* @privlevel 	CORE
	* @privgroup 	PRIVILEGED_IO
	*
	* @return		A list of virtual path to each installed application, where each path is of type Osp::Base::String, @n
	*				else @c null if an exception occurs
	* @exception	E_SUCCESS                 The method is successful.
	* @exception	E_E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_SYSTEM                  A system error has occurred.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	*				The returned path may become invalid if the application is uninstalled or if the application's path is changed
	*				by the user.
	* @endif
	*/
	static Osp::Base::Collection::IList *GetPathsToAppsN(void);

	/**
	* Converts a normal file to a secure file. @n
	* A secure file that is converted by this method is only used for a current application.
	* This method is static.
	*
	* @deprecated	This method is deprecated because using platform device key for encryption is no longer recommended.
	* @since 2.0
	*
	* @return		An error code
	* @param[in]	plainFilePath			The normal (non-encrypted) file path @n
	*										This path should be an absolute path beginning with an allowed path prefix.
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref FilePrefixReadable "here".
	* @param[in]	secureFilePath			The secure (encrypted) file path to be created @n
	*										This path should be an absolute path beginning with an allowed path prefix.
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref FilePrefixWritable "here".
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The overall length of the specified path is equal to @c 0 or
	*											  exceeds system limitations. @n
	* 											- The specified path contains prohibited character(s). @n
	*											- The specified path is invalid. @n
	*	 										- The application ID of the application accessing '/Share2/[appid]' or '/Share2Ext/[appid]'
	*	 										  does not belong to the trusted application list of the provider application. @n
	* 											- The input file specified by the @c plainFilePath parameter is an encrypted file.
	* @exception	E_ILLEGAL_ACCESS		The specified path is not permitted, or
	* 										access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception	E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception	E_STORAGE_FULL			The disk space is full.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*											- An unexpected device failure has occurred as the media ejected suddenly. @n
	*											- %File corruption is detected. @n
	*											- The number of opened files has exceeded the maximum limit.
	*
	* @remarks		If applications share a secure file that is to be converted, use ConvertToSecureFile(const Osp::Base::String &plainFilePath,
	* 				const Osp::Base::String &secureFilePath, const Osp::Base::ByteBuffer& key).
	*/
	static result ConvertToSecureFile(const Osp::Base::String &plainFilePath, const Osp::Base::String &secureFilePath);

    /**
	* Converts a normal file to a secure file. @n
	* A secure file that is converted by this method can be shared among applications with the same key value.
	* This method is static.
	* @since 2.0
	*
	* @return		An error code
	* @param[in]	plainFilePath			The normal (non-encrypted) file path @n
	*										This path should be an absolute path beginning with an allowed path prefix.
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref FilePrefixReadable "here".
	* @param[in]	secureFilePath			The secure (encrypted) file path to be created @n
	*										This path should be an absolute path beginning with an allowed path prefix.
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref FilePrefixWritable "here".
	* @param[in]	key						A key that encrypts a secure file @n
	*										If the secure file is converted with a specific key value,
	*										applications can access the same secure file with the identical key value.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The overall length of the specified path is equal to @c 0 or
	*											  exceeds system limitations. @n
	* 											- The specified path contains prohibited character(s). @n
	*											- The specified path is invalid. @n
	*	 										- The application ID of the application accessing '/Share2/[appid]' or '/Share2Ext/[appid]'
	*	 										  does not belong to the trusted application list of the provider application. @n
	* 											- The input file specified by the @c plainFilePath parameter is an encrypted file.
	* @exception	E_ILLEGAL_ACCESS		The specified path is not permitted, or
	* 										access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception	E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception	E_STORAGE_FULL			The disk space is full.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*											- An unexpected device failure has occurred as the media ejected suddenly. @n
	*											- %File corruption is detected. @n
	*											- The number of opened files has exceeded the maximum limit.
	*/
	static result ConvertToSecureFile(const Osp::Base::String &plainFilePath, const Osp::Base::String &secureFilePath, const Osp::Base::ByteBuffer& key);

	/**
	* Checks whether the specified path of the file, database or registry is encrypted. @n
	* This method is static.
	*
	* @deprecated	This method is deprecated.
	* @since 2.0
	*
	* @return		@c true if the file is encrypted, @n
	*				else @c false if the file is not encrypted, the file size is @c 0, or an exception occurs
	* @param[in]	filePath			The path of the file, database, or registry to be checked @n
	*									This path should be an absolute path beginning with an allowed path prefix. @n
	*									For more information on the allowed path prefixes for this argument,
	*									see @ref FilePrefixReadable "here".
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*										- The overall length of the specified path is equal to @c 0 or
	*										  exceeds system limitations. @n
	* 										- The specified path contains prohibited character(s). @n
	*										- The specified path is invalid. @n
	*	 									- The application ID of the application accessing '/Share2/[appid]' or '/Share2Ext/[appid]'
	*	 									  does not belong to the trusted application list of the provider application.
	* @exception	E_ILLEGAL_ACCESS	The specified path is not permitted.
	* @exception	E_FILE_NOT_FOUND	An entry for the specified file or path cannot be found.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected. @n
	*										- The number of opened files has exceeded the maximum limit. @n
	*										- The disk space is full.
	*
	*/
	static bool IsEncrypted(const Osp::Base::String &filePath);

private:
	static result CheckAccessibilityToPath(void* path, int *pPathKind, int nPrivilegeKind);
	result ReleaseRsrc(void);

	/**
	* Frees the resource allocated by this instance.
	*
	* @return		An error code
	* @exception	E_SUCCESS The method is successful.
	* @exception	E_SYSTEM The method is unable to free the resource currently possessed by this instance.
	*/
	result Dispose(void);

private:
	Osp::Base::String __fileName;
	void *__pMFile;
	bool __bWriteEnabled;
	bool __bReadEnabled;
	bool __bConstructed;
	bool __isMonitored;

private:
	friend class FileEx;
	class FileEx *__pFileEx;

};// File
};// Osp::Io
};// Osp
#endif//_FIO_FILE_H_

