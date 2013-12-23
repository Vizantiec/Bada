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
 * @file		FBaseUtilZipEntry.h
 * @brief		This is the header file for the %ZipEntry class.
 *
 * This header file contains the declarations of the %ZipEntry class.
 */

#ifndef _FBASE_UTIL_ZIPENTRY_H_
#define _FBASE_UTIL_ZIPENTRY_H_


// Includes
#include "FBaseString.h"
#include "FBaseDateTime.h"
#include "FBaseUtilTypes.h"


namespace Osp { namespace Base { namespace Utility {


/**
 * @class	ZipEntry
 * @brief		This class provides access to the entries of a zip archive.
 * @since	2.0
 *
 * The %ZipEntry class is used for accessing the elements of a zip archive. Each instance of 
 * %ZipEntry represents a single entry in the zip archive.
 * It also stores the information related to that entry, such as name, compressed size, 
 * uncompressed size, compression level, and archive name. 
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/utility_namespace.htm">Utility</a>.
 *
 * The following example demonstrates how to use the %ZipEntry class.
 *
 * @code
 *	#include <FBase.h>
 *	
 *	using namespace Osp::Base;
 *	using namespace Osp::Base::Utility;
 *	
 *	void
 *	MyClass::FileZipSample(void)
 *	{
 *		String str;
 *		int i=0, count = 0;
 *		unsigned long size = 0;
 * 		ZipEntry entry;
 *
 *		FileUnzip unzip;
 *		unzip.Construct(L"/Home/sample.zip");
 *
 *		count = unzip.GetEntryCount();
 *
 *		for (i=0; i < count; i++)
 *		{
 *			// Get a ZipEntry from the zip archive
 *			unzip.GetEntry(i, entry);
 *
 *			// Get an entry name associated with the ZipEntry
 *			str = entry.GetName();
 *		
 *			// Get the name of the zip file which ZipEntry belongs to
 *			str = entry.GetArchiveName();
 *
 *			// Get the compressed size of ZipEntry
 *			size = entry.GetCompressedSize();
 *		}
 *	
 *	}
 * @endcode 
 */
class _EXPORT_BASE_ ZipEntry :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	ZipEntry(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~ZipEntry(void);


// Operation
public:
	/**
	 * Gets an entry name associated with a zip entry (It can be a file or directory name).
	 *
	 * @since			2.0
	 * @return		An entry name
	 *
	 */
	String GetName(void) const;


	/**
	 * Gets the compression level associated with a zip entry.
	 *
	 * @since			2.0
	 * @return		A compression level associated with a zip entry.
	 *
	 */
	CompressionLevel GetCompressionLevel(void) const;


	/**
	 * Checks whether a zip entry is a file or directory.
	 *
	 * @since			2.0
	 * @return		@c true if the entry is a directory, @n
	 *				else @c false	 
	 */
	bool IsDirectory(void) const;


	/**
	 * Gets the compressed size of a zip entry.
	 *
	 * @since			2.0
	 * @return		The compressed size of a zip entry
	 */
	unsigned long  GetCompressedSize(void) const;


	/**
	 * Gets the uncompressed size of a zip entry.
	 *
	 * @since			2.0
	 * @return		The uncompressed size of a zip entry
	 */
	unsigned long  GetUncompressedSize(void) const;


	/**
	 * Gets the name of the zip file to which %ZipEntry belongs.
	 *
	 * @since			2.0
	 * @return		The name of a zip file
	 * @remarks 	This method returns the name of a zip file that is opened 
	 * in the FileUnzipper::Construct() method.
	 */
	String GetArchiveName(void) const;


	/**
	 * Compares the specified instance to the calling instance.
	 *
	 * @since			2.0
	 * @return		@c true if the specified instance equals the current instance, @n
	 *				else @c false
	 * @param[in]	obj	The object to be compared with the current instance
	 * @remarks 	The method returns @c true if all the attributes in the instance are same. 
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const;


	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since			2.0
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;



private:
	/**
	 * This is the copy constructor for this class.
	 *
	 * @since			2.0
	 * @param[in]	entry  The instance of the %ZipEntry class to copy from
	 * @remarks		This constructor is hidden.
	 */
	ZipEntry(const ZipEntry& entry);


	/**
	 * This is the assignment operator for this class.
	 *
	 * @since			2.0
	 * @param[in]	entry   The instance of the %ZipEntry class to assign from
	 * @remarks		This operator is hidden.
	 */
	ZipEntry& operator =(const ZipEntry& entry);


private:
	void __Set(void* unzFile);
	

private:

	String	__name;
	void*	__unzFile;
	CompressionLevel 	__compressionLevel;
	
private:
	friend class FileUnzipper;
	
	friend class ZipEntryEx;
	class ZipEntryEx* __pZipEntryEx;

};

}
}
}
#endif /* _FBASE_UTIL_ZIPENTRY_H_ */
