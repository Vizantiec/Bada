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
 * @file		FIoDirectory.h
 * @brief		This is the header file for the %Directory, %DirEnumerator and %DirEntry classes.
 *
 * This header file contains the declarations of the %Directory, %DirEnumerator, and %DirEntry classes.
 */
#ifndef _FIO_DIRECTORY_H_
#define _FIO_DIRECTORY_H_

#include <FBaseTypes.h>
#include <FBaseDateTime.h>
#include <FBaseString.h>
#include <FBaseResource.h>
#include <FBaseColArrayList.h>
#include <FIoConfig.h>

namespace Osp { namespace Io {

/**
 * @class	DirEntry
 * @brief	This class stores the information about each directory entry.
 * @since	1.0
 *
 * The %DirEntry class stores the information about each directory entry.
 *
 * For more information on the class features,
 * see <a href="../com.osp.cppappprogramming.help/html/dev_guide/io/io_namespace.htm">Io Guide</a>.
 *
 * @see		Osp::Io::Directory, Osp::Io::File
 *
 * The following example demonstrates how to use the %DirEntry class.
 *
 * @code

#include <FBase.h>
#include <FIo.h>

using namespace Osp::Base;
using namespace Osp::Io;

int main(void)
{
	String dirName(L"/Home/test");
	Directory dir;
	DirEnumerator *pDirEnum = null;
	String name;
	Osp::Base::DateTime dt;
	result r = E_SUCCESS;

	// Opens the directory
	r = dir.Construct(dirName);
	if(IsFailed(r))
		goto CATCH;

	// Reads all the directory entries
	pDirEnum = dir.ReadN();
	if(!pDirEnum)
		goto CATCH;

	// Loops through all the directory entries
	while(pDirEnum->MoveNext() == E_SUCCESS)
	{
		DirEntry dirEntry = pDirEnum->GetCurrentDirEntry();

		// Gets several properties of each directory entry.
		name = dirEntry.GetName();

		name += L": size=";
		name += Long((long) dirEntry.GetFileSize()).ToString();

		if(dirEntry.IsDirectory())
			name += L", [directory]";
		if(dirEntry.IsReadOnly())
			name += L", [read-only]";
		if(dirEntry.IsHidden())
			name += L", [hidden]";

		dt = dirEntry.GetDateTime();

		name += L", year=";
		name += dt.GetYear();

		name += L", month=";
		name += dt.GetMonth();

		name += L", day=";
		name += dt.GetDay();

		name += L", hour=";
		name += dt.GetHour();

		name += L", min=";
		name += dt.GetMinute();

		name += L", second=";
		name += dt.GetSecond();

		// Prints out the message... 
	}

	// Deletes the enumerator
	delete pDirEnum;

	AppLog("Succeeded");

	// The opened directory is closed automatically when the destructor of %Directory class is invoked
	return 0;

CATCH:
	if(pDirEnum)
		delete pDirEnum;
	AppLog("Failed...");
	return -1;
}
 * @endcode
 */
class _EXPORT_IO_ DirEntry
	: public Osp::Base::Object
{
	friend class DirEnumerator;

public:
	/**
	* This is the copy constructor for the %DirEntry class.
	*
	* @since	1.0
	*/
	DirEntry(DirEntry& dirEntry);

	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	~DirEntry(void);

public:
	/**
	* Copies the value of the specified instance to the calling instance
    * by overloading the assignment operator. 
	*
	* @since		1.0
	* @return		A reference to the calling instance
	*/
	DirEntry& operator =(const DirEntry& dirEntry);


	/**
	* Gets the name of this directory entry.
	*
	* @since		1.0
	* @return		The name of this directory entry
	*/
	const Osp::Base::String GetName(void) const;


	/**
	* Gets the file size of this directory entry.
	*
	* @since		1.0
	* @return		The file size of this directory entry 
	*/
	unsigned long GetFileSize(void) const;


	/**
	* Checks whether the current %DirEntry instance is a directory.
	*
	* @since		1.0
	* @return		@c true if it is a directory, @n
	*				else @c false
	*/
	bool IsDirectory(void) const;


	/**
	* Checks whether a file has a hidden attribute.
	*
	* @since		1.0
	* @return		@c true if the file has a hidden attribute, @n
	*				else @c false
	*/
	bool IsHidden(void) const;


	/**
	* Checks whether a file has a read-only attribute.
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
	* Checks whether the file is a regular file.
	*
	* @since		1.0
	* @return		@c true if the file has a regular file attribute @n
	*				@c false, otherwise
	* @remarks		This method will be deprecated very soon.
	*/
	bool IsNomalFile(void) const;


	/**
	* @internal		This method is for internal use only. The bada platform team is not
	* 				responsible for any behavioral correctness, consistency, and
	* 				security-related issues that might arise after using this method.
	* Checks whether the file is system file.
	*
	* @since		1.0
	* @return		@c true if the file has a system file attribute, @n
	*				@c false, otherwise
	* @remarks		This method will be deprecated very soon.
	*/
	bool IsSystemFile(void) const;


	/**
	* Gets the date and time of creation of the directory entry.
	*
	* @since		1.0
	* @return		The date and time of creation
	*/
	Osp::Base::DateTime GetDateTime(void) const;

private:
	/**
	* This is the default constructor for this class.
	*/
	DirEntry(void);
	DirEntry(void* pFileFindInfo);

	void *__pFileFindInfo;
	bool __bDirectory;
	bool __bHidden;
	bool __bReadOnly;
	bool __bSysFile;

private:
	friend class DirEntryEx;
	class DirEntryEx *__pDirEntryEx;

} ;


/**
* @class	DirEnumerator
* @brief	This class provides methods to access the collection of a specific directory entry list.
* @since	1.0
* 
* The %DirEnumerator class provides methods to access the collection of a specific directory entry list.
* Generally, %DirEnumerator is instantiated by the Directory::ReadN() method,
* and used to get the %DirEntry instances that have information pertaining to the directory.
*
* For more information on the class features,
* see <a href="../com.osp.cppappprogramming.help/html/dev_guide/io/io_namespace.htm">Io Guide</a>.
*
* @see		Osp::Io::Directory, Osp::Io::DirEntry, Osp::Io::File
*
*The following example demonstrates how to use the %DirEnumerator class.
*
* @code
#include <FBase.h>
#include <FIo.h>

using namespace Osp::Base;
using namespace Osp::Io;

int main(void)
{
	String dirName(L"/Home/test");
	Directory dir;
	DirEnumerator *pDirEnum = null;
	result r = E_SUCCESS;

	// Opens the directory
	r = dir.Construct(dirName);
	if(IsFailed(r))
		goto CATCH;

	// Reads all the directory entries
	pDirEnum = dir.ReadN();
	if(!pDirEnum)
		goto CATCH;

	// Loops through all the directory entries
	while(pDirEnum->MoveNext() == E_SUCCESS)
	{
		DirEntry dirEntry = pDirEnum->GetCurrentDirEntry();

		// Do something...
	}

	// Deletes the enumerator
	delete pDirEnum;

	AppLog("Succeeded");

	// The opened directory is closed automatically when the destructor of the Directory class is invoked.
	return 0;

CATCH:
	if(pDirEnum)
		delete pDirEnum;
	AppLog("Failed...");
	return -1;
}
* @endcode
*
*/
class _EXPORT_IO_ DirEnumerator :
	public Osp::Base::Object,
	public Osp::Base::Collection::IEnumerator
{
private:
	/**
	* This is the copy constructor for the %DirEnumerator class.
	*/
	DirEnumerator(const Osp::Base::String& regexpFileName);

public:
	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	~DirEnumerator(void);

public:
	/**
	* Gets the value of the %DirEntry instance in the currently accessed directory.
	*
	* @since			1.0
	* @return			A reference to the %DirEntry instance
	* @exception 		E_SUCCESS			The method is successful.
	* @exception 		E_INVALID_STATE		The current position of the collection is not valid.
	* @remarks			Use the MoveNext() method to get information from another file or directory to the currently accessed directory. @n
	*					The specific error code can be accessed using the GetLastResult() method.
	*/
	DirEntry& GetCurrentDirEntry(void) const;


	/**
	* Gets the pointer to the object at the current position of a directory entry collection.
	*
	* @since		 	1.0
	* @return		 	A pointer to the %DirEntry instance, @n
	* 					else @c null if the current position of the collection is invalid.
	* @remarks			Use the MoveNext() method to get information of another file or directory in the currently accessed directory.
	*/
	Osp::Base::Object* GetCurrent(void) const;


	/**
	* Moves the current position of the collection to the next position in the currently accessed directory. @n
	* When %DirEnumerator is instantiated, its initial position is set to @c -1. @n
	* Therefore, calling the GetCurrentDirEntry() method without a call to MoveNext() throws an E_INVALID_STATE exception,
	* and returns a reference to an empty %DirEntry instance. @n
	* Similarly, calling the GetCurrent() method without a call to MoveNext() returns a @c null pointer to indicate an error condition.
	*
	* @since			1.0
	* @return			An error code
	* @exception 		E_SUCCESS			The method is successful.
	* @exception 		E_INVALID_ARG		Either of the following conditions has occurred: @n
	*											- The length of the specified path is @c 0 or exceeds system limitations. @n
	*											- The specified path contains prohibited character(s). @n
	*											- The specified path is invalid. @n
	*											- The file handle is invalid (Either the file is closed by 
	*											  another method, or the memory is corrupted).
	* @exception 		E_FILE_NOT_FOUND	An entry for the specified file or path cannot be found.
	* @exception 		E_MAX_EXCEEDED		The number of opened files has exceeded the maximum limit.
	* @exception 		E_END_OF_FILE		There are no more directory entries to read.
	* @exception 		E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception 		E_IO				An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	*/
	result MoveNext(void);


	/**
	* Resets the current position of the collection to @c -1.
	*
	* @since			1.0
	* @return			An error code
	* @exception 		E_SUCCESS			The method is successful.
	* @exception 		E_INVALID_ARG		The file handle is invalid (either the file is closed by another method, or the memory is corrupted).
	*/
	result Reset(void);

private:
	static result CheckAccessibilityToPath(void *path, int *pPathKind, int nPrivilegeKind);

private:
	friend class Directory;

	bool __bValidAccess;
	Osp::Base::String __absPatternFileName;
	void *__pFileFindInfo;
	DirEntry *__pCurDirEntry;

private:
	friend class DirEnumeratorEx;
	class DirEnumeratorEx *__pDirEnumeratorEx;

};


/**
 * @class	Directory
 * @brief	This class provides methods to operate on directories.
 * @since	1.0
 *
 * The %Directory class provides methods to operate on directories.
 * All the members of this class are guaranteed to be thread-safe.
 *
 * For more information on the class features,
 * see <a href="../com.osp.cppappprogramming.help/html/dev_guide/io/io_namespace.htm">Io Guide</a>.
 *
 * @see		Osp::Io::DirEntry, Osp::Io::File
 *
 * The following example demonstrates how to use the %Directory class.
 *
 * @code
#include <FBase.h>
#include <FIo.h>

using namespace Osp::Base;
using namespace Osp::Io;

int main(void)
{
	String dirName(L"/Home/test");
	String modifyName(L"/Home/test2");
	Directory* pDir;
	DirEnumerator* pDirEnum;
	result r = E_SUCCESS;

	//------------------------------------------------
	// Directory entry traversal example
	//------------------------------------------------
	pDir = new Directory; // Allocates the %Directory instance

	// Opens the directory
	r = pDir->Construct(dirName);
	if(IsFailed(r))
		goto CATCH;

	// Reads all the directory entries
	pDirEnum = pDir->ReadN();
	if(!pDirEnum)
		goto CATCH;

	// Loops through all the directory entries
	while(pDirEnum->MoveNext() == E_SUCCESS)
	{
		DirEntry entry = pDirEnum->GetCurrentDirEntry();

		// Do something...
	}

	// Releases the %Directory instance.
	// The opened directory is closed automatically when the destructor of the %Directory class is invoked.
	delete pDir;
	pDir = null;

	//------------------------------------------------
	// Renames the directory example
	//------------------------------------------------
	r = Directory::Rename(dirName, modifyName);
	if(IsFailed(r))
		goto CATCH;
	AppLog("Succeeded!");
	return 0;

CATCH:
	if(pDir)
		delete pDir;
	AppLog("Failed...");
	return -1;
}
 * @endcode
 *
 */

/**
 * @page DirectoryPrefixReadable Allowed Path Prefixes
 * - '/Home' or '/HomeExt' (read and write permission)
 * - '/Home/Share', '/Home/Share2', '/HomeExt/Share', or '/HomeExt/Share2' (read and write permission)
 * - '/Share/[@e appid]' or '/ShareExt/[@e appid]' (read-only permission)
 * - '/Share2/[@e appid]' or '/Share2Ext/[@e appid]' (read and write permission)
 * - '/Res' (read-only permission)
 * - '/Media', '/Media/Images', '/Media/Sounds', '/Media/Videos', '/Media/Themes', or '/Media/Others' (read-only permission)
 * - '/Storagecard/Media', '/Storagecard/Media/Images', '/Storagecard/Media/Sounds', '/Storagecard/Media/Videos',
 *   '/Storagecard/Media/Themes', or '/Storagecard/Media/Others' (read-only permission)
 *
 * Refer to <a href="../com.osp.documentation.help/html/bada_overview/bada_file_system.htm">bada File System</a>
 * for the detailed usage and permission of each allowed path prefix.
 */

/**
 * @page DirectoryPrefixWritable Allowed Path Prefixes
 * - '/Home' or '/HomeExt' (read and write permission)
 * - '/Home/Share', '/Home/Share2', '/HomeExt/Share', or '/HomeExt/Share2' (read and write permission)
 * - '/Share2/[@e appid]' or '/Share2Ext/[@e appid]' (read and write permission)
 *
 * Refer to <a href="../com.osp.documentation.help/html/bada_overview/bada_file_system.htm">bada File System</a>
 * for the detailed usage and permission of each allowed path prefix.
 */

class _EXPORT_IO_ Directory :
	public Osp::Base::Object,
	public Osp::Base::__Resource
{
// Lifecycle
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	* @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	*/
	Directory(void);


	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	~Directory(void);


	/**
	* Initializes this instance of %Directory with the specified parameter. @n
	* The Construct() method safely opens an existing directory using the specified directory name.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]		dirPath				The path to the directory to open @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref DirectoryPrefixReadable "here".
	* @exception 		E_SUCCESS			The method is successful.
	* @exception 		E_INVALID_STATE		This instance has already been constructed.
	* @exception 		E_INVALID_ARG		Either of the following conditions has occurred: @n
	*											- The length of the specified path is @c 0 or exceeds system limitations. @n
	* 											- The specified path contains prohibited character(s). @n
	*											- The specified path is invalid. @n
	*											- The %App ID of the application accessing '/Share2/[@e appid]' or '/Share2Ext/[@e appid]'
	*											  does not belong to the trusted application list of the provider application.
	* @exception		E_ILLEGAL_ACCESS	The specified path is not permitted, or
	* 										access is denied due to insufficient permission.
	* 										(The file is already open or in no-sharing mode.)
	* @exception 		E_FILE_NOT_FOUND	An entry for the specified file or path cannot be found.
	* @exception 		E_MAX_EXCEEDED		The number of opened files has exceeded the maximum limit.
	* @exception		E_IO				An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	*/
	result Construct(const Osp::Base::String& dirPath);


	/**
	* Reads all the directory entries from the current directory and then returns a %DirEnumerator instance that is used to traverse each directory entry.
	*
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	* 					For more information, see @ref CompReadNPage "here".
	* @return			A pointer to the DirEnumerator object that provides a way to access the collection of a
	* 					directory entry list, @n
	*					else @c null if an exception occurs
	* @exception 		E_SUCCESS			The method is successful.
	* @exception 		E_INVALID_STATE		The %Directory has not been opened as yet.
	* @exception 		E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception 		E_MAX_EXCEEDED		The number of opened files has exceeded the maximum limit.
	* @exception 		E_IO				An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	* @remarks			The returned enumeration objects should be released by the caller.
	*					The specific error code can be accessed using the GetLastResult() method.
	*/
	DirEnumerator* ReadN(void);
	
	/**
	* @page				CompReadNPage Compatibility for ReadN()
	* @section			CompReadNPageIssueSection Issues
	* 					Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	*
	* -# The result set of ReadN() includes relative paths, such as '.' (current directory) or '..' (parent
	* directory), which are not permitted by the bada platform policy.
	* If applications read an empty directory, the returned DirEnumerator contains the relative paths.
	*
	* @section CompReadNPageSolutionSection Resolutions
	* The issues mentioned above are resolved in bada API version 2.0 as follows, and it is recommended to use bada API version 2.0 or above. @n
	*
	* -# If the application reads an empty directory, the returned DirEnumerator does not contain the relative paths.
	*/

// static methods
public:
	/**
	* Creates a new directory. @n
	* This method is static.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]		dirPath					The path at which the directory is to be created @n
	*											This path should be an absolute path beginning with an allowed path prefix. @n
	*											For more information on the allowed path prefixes for this argument,
	*											see @ref DirectoryPrefixWritable "here".
	* @param[in]		createParentDirectories Set to @c true if the non-existing parent directories are created automatically
	* 											up to the destination, @n
	* 											else @c false if an absent parent directory causes an exception
	* @exception	 	E_SUCCESS				The method is successful.
	* @exception 		E_INVALID_ARG			Either of the following conditions has occurred: @n
	*												- The length of the specified path is @c 0 or exceeds system limitations. @n
	* 												- The specified path contains prohibited character(s). @n
	*												- The specified path is invalid. @n
	*												- The %App ID of the application accessing '/Share2/[@e appid]' or '/Share2Ext/[@e appid]'
	*												  does not belong to the trusted application list of the provider application.
	* @exception		E_ILLEGAL_ACCESS		The specified path is not permitted, or
    *                                           access is denied due to insufficient permission.
	* @exception		E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception		E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception		E_STORAGE_FULL			The disk space is full.
	* @exception		E_IO					An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	*/
	static result Create(const Osp::Base::String& dirPath, bool createParentDirectories = false);


	/**
	* Deletes the directory specified by the path. @n
	* This method is static. @n
	* When @c recursive is set to be @c true, it removes all the subdirectories and their contents.
	* When @c false, this method removes the directory only if it is empty.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]		dirPath					The path to the directory that is to be removed @n
	*											This path should be an absolute path beginning with an allowed path prefix.
	*											For more information on the allowed path prefixes for this argument,
	*											see @ref DirectoryPrefixWritable "here".
	* @param[in]		recursive 				Set to @c true to remove the sub-directories recursively, @n
	*											else @c false
	* @exception	 	E_SUCCESS				The method is successful.
	* @exception 		E_INVALID_ARG			Either of the following conditions has occurred: @n
	*												- The length of the specified path is @c 0 or exceeds system limitations. @n
	* 												- The specified path contains prohibited character(s). @n
	*												- The specified path is invalid. @n
	*												- The %App ID of the application accessing '/Share2/[@e appid]' or '/Share2Ext/[@e appid]'
	*												  does not belong to the trusted application list of the provider application.
	* @exception		E_ILLEGAL_ACCESS		    The specified path is not permitted, or
	* 												access is denied due to insufficient permission.
	* @exception		E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception		E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception		E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception		E_IO					An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	*/
	static result Remove(const Osp::Base::String& dirPath, bool recursive = false);


	/**
	* Renames the specified directory to the specified name. @n
	* This method is static. @n
	* This method does not create parent directories automatically. For example, "/CurrentDir" cannot be moved to
	* "/NewDir/SubDir" if "/NewDir" does not already exist. An E_FILE_NOT_FOUND exception is thrown.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]		orgDirPath				The original directory path @n
	*											This path should be an absolute path beginning with an allowed path prefix. @n
	*											For more information on the allowed path prefixes for this argument,
	*											see @ref DirectoryPrefixReadable "here".
	* @param[in]		newDirPath				The new directory path @n
	*											This path should be an absolute path beginning with an allowed path prefix. @n
	*											For more information on the allowed path prefixes for this argument,
	*											see @ref DirectoryPrefixWritable "here".
	* @exception		E_SUCCESS				The method is successful.
	* @exception 		E_INVALID_ARG			Either of the following conditions has occurred: @n
	*												- The length of the specified path is @c 0 or exceeds system limitations. @n
	* 												- The specified path contains prohibited character(s). @n
	*												- The specified path is invalid. @n
	*												- The %App ID of the application accessing '/Share2/[@e appid]' or '/Share2Ext/[@e appid]'
	*												  does not belong to the trusted application list of the provider application.
	* @exception		E_ILLEGAL_ACCESS		The specified path is not permitted, or
    *                                           access is denied due to insufficient permission.
	* @exception		E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception		E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception		E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception		E_STORAGE_FULL			The disk space is full.
	* @exception		E_IO					Either of the following conditions has occurred: @n
	*												- An unexpected device failure has occurred as the media ejected suddenly. @n
	*												- %File corruption is detected. @n
	*												- The volume or quota is no more available.
	*/
	static result Rename(const Osp::Base::String& orgDirPath, const Osp::Base::String& newDirPath);


private:
	static result CheckAccessibilityToPath(void *path, int *pPathKind, int nPrivilegeKind);
	result ReleaseRsrc(void);	


	/**
	* Frees the resource allocated by this instance.
	*
	* @return		An error code
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_SYSTEM	The method is unable to free the resource currently possessed by this instance.
	*/
	result Dispose(void);

private:
	Osp::Base::String __dirName;
	void *__pMFile;
	bool __bConstructed;

private:
	friend class DirectoryEx;
	class DirectoryEx *__pDirectoryEx;

};// DIRECTORY
};// Osp::Io
};// Osp
#endif//_FIO_DIRECTORY_H_
