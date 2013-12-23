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
 * @file		FIoRegistry.h
 * @brief		This is the header file for the %Registry class.
 *
 * This header file contains the declarations of the %Registry class.
 */
#ifndef _FIO_REGISTRY_H_
#define _FIO_REGISTRY_H_


#include <FBaseUuId.h>
#include <FBaseColArrayList.h>
#include <FBaseByteBuffer.h>
#include <FBaseResult.h>
#include <FBaseResource.h>
#include <FIoConfig.h>


namespace Osp {namespace Base {class String;}}
namespace Osp {namespace Base {class ByteBuffer;}}


namespace Osp { namespace Io {

#define REG_OPEN_READ_ONLY	(0x00000001L)
#define REG_OPEN_READ_WRITE	(0x00000002L)
#define REG_OPEN_CREATE		(0x00000004L)

/**
 * @class	Registry
 * @brief	This class provides a mechanism to access and manipulate registry files
 * @since	1.0
 *			
 * The %Registry class provides a mechanism to access and manipulate registry files
 * All the members of this class are guaranteed to be thread-safe.
 *
 * For more information on the class features,
 * see <a href="../com.osp.cppappprogramming.help/html/dev_guide/io/io_namespace.htm">Io Guide</a>.
 *
 * The following example demonstrates how to use the %Registry class.
 *
 * @code
#include <FBase.h>
#include <FIo.h>

using namespace Osp::Base;
using namespace Osp::Io;

void
RegistryTest()
{
	Registry reg;
	String regPathName(L"regTest.ini");

	// section name
	String sect1(L"section1");
	String sect2(L"section2");
	String sect3(L"section3");

	// entry name
	String entry1(L"entry1");
	String entry2(L"entry2");

	int iVal;
	result r;

	r = reg.Construct(regPathName, true); // create a new registry if not exists
	if(IsFailed(r))
		goto CATCH;

	// Creates sections
	r = reg.AddSection(sect1);
	r = reg.AddSection(sect2);
	r = reg.AddSection(sect3);

	// add value: section1 { entry1 = 999 }
	r = reg.AddValue(sect1, entry1, 999);
	if(IsFailed(r))
		goto CATCH;

	// change value: section1 { entry1 = 3 }
	r = reg.SetValue(sect1, entry1, 3);
	if(IsFailed(r))
		goto CATCH;

	// add value: section2 { entry2 = 1.1234599 }
	r = reg.AddValue(sect2, entry2, 1.1234599);
	if(IsFailed(r))
		goto CATCH;

	// get value: section1 { entry1 = ? }
	r = reg.GetValue(sect1, entry1, iVal);
	if(IsFailed(r))
		goto CATCH;

	// write to the file
	r = reg.Flush();
	if(IsFailed(r))
		goto CATCH;

	return;

CATCH:
	// Do some error handling
	return;
}
 * @endcode
 */

/**
 * @page RegistryPrefixReadable Allowed Path Prefixes
 * - '/Home' or '/HomeExt' (read and write permission)
 * - '/Home/Share', '/Home/Share2', '/HomeExt/Share', or '/HomeExt/Share2' (read and write permission)
 * - '/Share/[@e appid]' or '/ShareExt/[@e appid]' (read-only permission)
 * - '/Share2/[@e appid]' or '/Share2Ext/[@e appid]' (read and write permission)
 * - '/Res' (read-only permission)
 *
 * Refer to <a href="../com.osp.documentation.help/html/bada_overview/bada_file_system.htm">bada File System</a>
 * for the detailed usage and permission of each allowed path prefix.
 */

/**
 * @page RegistryPrefixWritable Allowed Path Prefixes
 * - '/Home' or '/HomeExt' (read and write permission)
 * - '/Home/Share', '/Home/Share2', '/HomeExt/Share', or '/HomeExt/Share2' (read and write permission)
 * - '/Share2/[@e appid]' or '/Share2Ext/[@e appid]' (read and write permission)
 *
 * Refer to <a href="../com.osp.documentation.help/html/bada_overview/bada_file_system.htm">bada File System</a>
 * for the detailed usage and permission of each allowed path prefix.
 */

class _EXPORT_IO_ Registry
	: public Osp::Base::Object,
	public Osp::Base::__Resource
{
// Lifecycle
public:

	/**
	* This is the default constructor for this class.
	*
	* @since	1.0
	* @remarks	After creating an instance of this class, the Construct() method must be called explicitly to
	*			initialize this instance.
	*/
	Registry(void);

	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	virtual ~Registry(void);

	/**
	* Initializes this instance of %Registry with the specified parameters.
	* This method loads a registry file in the read-write mode.
	* @since		1.0
	* @return		An error code
	* @param[in]	regPath					The path to the registry file to load or create @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref RegistryPrefixReadable "here".
	* @param[in]	createIfNotExist		Set to @c true to create a registry file, @n
	*                                       else @c false to open an existing registry file
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has already been constructed.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The length of the specified string of a file path is less
	*                                             than or equal to @c 0. @n
	*											- The translated overall length of the specified path exceeds the
	*											  system limitation. @n
	*											- The specified path contains prohibited character(s). @n
	*											- The specified path is invalid. @n
	*											- The application ID of the application accessing '/Share2/[@e appid]' or '/Share2Ext/[@e appid]'
	*											  does not belong to the trusted application list of the provider application. @n
	*											- This method cannot open a secure registry file encrypted by the platform. @n
	*											  Use Construct(const Osp::Base::String& regPath, long openMode,
	*											  bool secureMode, long option) in this case.
	* @exception	E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found. 
	* @exception	E_ILLEGAL_ACCESS		The specified path is not permitted, or
	* 										access is denied due to insufficient permission.
	* @exception	E_END_OF_FILE			The file pointer has reached end-of-file.
	* @exception	E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception 	E_STORAGE_FULL			The disk space is full.
	* @exception	E_IO					An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
    * @exception	E_INVALID_FORMAT		The input registry file contains '0x00' in the middle of file.
	* @exception	E_PARSING_FAILED		The method has failed to parse the registry file.
	* @remarks		To load the registry in read-only mode, use the Registry::Construct(const Osp::Base::String& regPath,
	* 				long openMode, long option) method with REG_OPEN_READ_ONLY as a value for the open mode flag.
	*/
	result Construct(const Osp::Base::String& regPath, bool createIfNotExist);


	/**
	* Initializes this instance of %Registry with the specified parameters.
	* This method loads a registry file in the read-only or the read-write mode.
	* @since		1.1
	*
	* @return		An error code
	* @param[in]	regPath					The path to the registry file to load or create @n
	*										This path should be an absolute path beginning with an allowed path prefix.
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref RegistryPrefixReadable "here".
	* @param[in]	openMode				An open mode flag @n
	* 										Currently, the following flags can be used in combination with the logical OR operator. @n
	*										 (1) REG_OPEN_READ_ONLY @n
	*										 (2) REG_OPEN_READ_WRITE @n
	*										 (3) REG_OPEN_READ_WRITE | REG_OPEN_CREATE
	* @param[in]	option					This argument is reserved for further use. It is recommended to use @c 0.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has already been constructed.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The length of the specified string of a file path is less
	*                                             than or equal to @c 0. @n
	*											- The translated overall length of the specified path exceeds the
	*											  system limitation. @n
	*											- The specified path contains prohibited character(s). @n
	*											- The specified path is invalid. @n
	*											- The application ID of the application accessing '/Share2/[@e appid]' or '/Share2Ext/[@e appid]'
	*											  does not belong to the trusted application list of the provider application. @n
	*											- This method cannot open a secure registry file encrypted by the platform. @n
	*											  Use Construct(const Osp::Base::String& regPath, long openMode,
	*											  bool secureMode, long option) in this case.
	* @exception	E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found. 
	* @exception	E_ILLEGAL_ACCESS		The specified path is not permitted, or
	* 										access is denied due to insufficient permission.
	* @exception	E_END_OF_FILE			The file pointer has reached end-of-file.
	* @exception	E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception 	E_STORAGE_FULL			The disk space is full.
	* @exception	E_IO					 An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	* @exception	E_INVALID_FORMAT		 The input registry file contains '0x00' in the middle of the file.
	* @exception	E_PARSING_FAILED		The method has failed to parse the registry file.
	*/
	result Construct(const Osp::Base::String& regPath, long openMode, long option);


	/**
	* Initializes this instance of %Registry with the specified parameters. @n
	* This method loads a normal/secure registry file in the read-only or the read-write mode. @n
	* In the secure mode, the contents read from the secure registry file is automatically decrypted by the platform. @n
	* An application using this method cannot access the secure registry files that are created by other applications
	* because of the application-specific key.
	*
	* @deprecated	This method is deprecated because using platform device key for encryption is no longer recommended.
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	regPath					The path to the registry file to load or create @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref RegistryPrefixReadable "here".
	* @param[in]	openMode				An open mode flag @n
	* 										Currently, the following flags can be used in combination with the logical OR operator: @n
	* 										 (1) REG_OPEN_READ_ONLY @n
	*										 (2) REG_OPEN_READ_WRITE @n
	*										 (3) REG_OPEN_READ_WRITE | REG_OPEN_CREATE
	* @param[in]	secureMode				Set to @c true to handle a registry file in encrypted form, @n
	*                                       else @c false @n
	*	 									Applications cannot open a normal registry file in secure mode and
	*	 									a secure registry file in normal mode.
	* @param[in]	option					This argument is reserved for further use @n It is recommended to use @c 0.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has already been constructed.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The length of the specified string of a file path is less
	*                                             than or equal to @c 0. @n
	*											- The translated overall length of the specified path exceeds the
	*											  system limitation. @n
	*											- The specified path contains prohibited character(s). @n
	*											- The specified path is invalid. @n
	*											- The application ID of the application accessing '/Share2/[@e appid]' or '/Share2Ext/[@e appid]'
	*											  does not belong to the trusted application list of the provider application. @n
	*											- The secure registry file cannot be accessed in normal mode or
	*											  the normal registry file cannot be accessed in secure mode.
	* @exception	E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found. 
	* @exception	E_ILLEGAL_ACCESS		The specified path is not permitted, or
	* 										access is denied due to insufficient permission.
	* @exception	E_END_OF_FILE			The file pointer has reached end-of-file.
	* @exception	E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception 	E_STORAGE_FULL			The disk space is full.
	* @exception	E_IO					An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	* @exception	E_INVALID_FORMAT		The input registry file contains '0x00' in the middle of the file.
	* @exception	E_PARSING_FAILED		The method has failed to parse the registry file.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	*/
	result Construct(const Osp::Base::String& regPath, long openMode, bool secureMode, long option);


	/**
	* Initializes this instance of %Registry with the specified parameters.
	* This method loads a normal/secure registry file in the read-only or the read-write mode. @n
	* In the secure mode, the contents read from the secure registry file is automatically decrypted by the platform. @n
	* Applications using this method can access the same secure registry files that are created by other applications
	* with the identical key value.
	*
	* @deprecated	This method is deprecated and will be replaced with a new one in the near future.
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	regPath					The path to the registry file to load or create. @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref RegistryPrefixReadable "here".
	* @param[in]	openMode				An open mode flag. @n
	* 										Currently, the following flags can be used in combination with the logical OR operator. @n
	* 										 (1) REG_OPEN_READ_ONLY @n
	*										 (2) REG_OPEN_READ_WRITE @n
	*										 (3) REG_OPEN_READ_WRITE | REG_OPEN_CREATE
	* @param[in]	secureMode				Set to @c true to handle a registry file in encrypted form, @n
	*                                       else @c false @n
	*	 									Applications cannot open a normal registry file in secure mode and
	*	 									a secure registry file in normal mode.
	* @param[in]	key						A key that encrypts or decrypts a secure registry file @n
	* 										If the secure registry file is created with a specific key value,
	* 										applications can access the same secure registry file with the identical key value.
	* @param[in]	option					This argument is reserved for further use. It is recommended to use @c 0.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has already been constructed.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The length of the specified string of a file path is less
	*                                             than or equal to @c 0. @n
	*											- The translated overall length of the specified path exceeds the
	*											  system limitation. @n
	*											- The specified path contains prohibited character(s). @n
	*											- The specified path is invalid. @n
	*											- The application ID of the application accessing '/Share2/[@e appid]' or '/Share2Ext/[@e appid]'
	*											  does not belong to the trusted application list of the provider application. @n
	*											- The secure registry file cannot be accessed in normal mode or
	*											  the normal registry file cannot be accessed in secure mode.
	* @exception	E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found. 
	* @exception	E_ILLEGAL_ACCESS		The specified path is not permitted, or
	* 										access is denied due to insufficient permission.
	* @exception	E_END_OF_FILE			The file pointer has reached end-of-file.
	* @exception	E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception 	E_STORAGE_FULL			The disk space is full.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*											- An unexpected device failure has occurred as the media ejected suddenly. @n
	*											- %File corruption is detected. @n
	*											- The specified key is incorrect.
	* @exception	E_INVALID_FORMAT		The input registry file contains '0x00' in the middle of the file.
	* @exception	E_PARSING_FAILED		The method has failed to parse the registry file.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	*/
	result Construct(const Osp::Base::String& regPath, long openMode, bool secureMode, const Osp::Base::ByteBuffer& key, long option);


// Operations
public:

	/**
	* Writes the current contents of a registry in memory to the non-volatile storage. @n
	* If the secure mode is set to be true, the contents of the registry are automatically encrypted
	* and saved by the platform.
	*
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found. 
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception 	E_STORAGE_FULL			The disk space is full.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*											- An unexpected device failure has occurred as the media ejected suddenly. @n
	*											- %File corruption is detected. @n
	*											- The memory is insufficient.
	*/
	result Flush(void);


	/**
	* Creates the specified section then adds it into the registry.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			The length of the specified string for a section name is less than
	*                                       or equal to @c 0.
	* @exception	E_SECTION_ALREADY_EXIST	A section with the specified name already exists.
	*/
	result AddSection(const Osp::Base::String& sectionName);


	/**
	* Removes the section from %Registry.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name to remove
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			The length of the specified string for a section is less than
	*                                       or equal to @c 0.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	*/
	result RemoveSection(const Osp::Base::String& sectionName);


	/**
	* Gets all section names in the registry.
	*
	* @since		1.0
	* @return		A list of section names @n
	*				If this method fails, @c null value is returned.
	*				The specific error code can be accessed using the GetLastResult() method. @n
	*				When there are no sections at all, the method returns an empty list instance. @n
	*				Use the GetCount() method to check the number of elements in the list.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @remarks		Do not forget to delete not only the returned IList instance, but also its
	*               contents by invoking IList::RemoveAll().
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::Collection::IList* GetAllSectionNamesN(void);


	/**
	* Adds the name-value pair of type integer as an entry of the specific section.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name
	* @param[in]	value					The @c int value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_ALREADY_EXIST		The specified @c entryName already exists in this section.
	*/
	result AddValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, int value);


	/**
	* Adds the name-value pair of type double as an entry of the specific section.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name
	* @param[in]	value					The @c double value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_ALREADY_EXIST		The specified @c entryName already exists in this section.
	*/
	result AddValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, double value);


	/**
	* Adds the name-value pair of type float as an entry of the specific section.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name
	* @param[in]	value					The @c float value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_ALREADY_EXIST		The specified @c entryName already exists in this section.
	*/
	result AddValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, float value);


	/**
	* Adds the name-value pair of type String as an entry of the specific section.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name
	* @param[in]	value					The @c String value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_ALREADY_EXIST		The specified @c entryName already exists in this section.
	*/
	result AddValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, const Osp::Base::String& value);


	/**
	* Adds the name-value pair of type UuId as an entry for the specified section.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name
	* @param[in]	value					The @c UuId value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_ALREADY_EXIST		The specified @c entryName already exists in this section.
	*/
	result AddValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, const Osp::Base::UuId& value);


	/**
	* Adds the name-value pair of type %ByteBuffer as an entry for the specified section.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name
	* @param[in]	value					The @c ByteBuffer value
	*                                       Note that, it should be constructed before being passed to the method.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_ALREADY_EXIST		The specified @c entryName already exists in this section.
	* @remarks		Note that all the contents of @c ByteBuffer are saved as an entry value.
	*               That is, byte data from @c 0 up to the buffer limit is saved.
	* @see			Osp::Base::ByteBuffer
	*/
	result AddValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, const Osp::Base::ByteBuffer& value);


	/**
	* Gets the int value of the specified entry.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The name of entry where its value will be fetched
	* @param[out]	retVal					The return value obtained from the registry
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @exception	E_PARSING_FAILED		The method has failed to parse the encoded entry value string, or the value is retrieved by using an incorrect data type.
	* @exception	E_DATA_NOT_FOUND		The name-value pair has no value assigned (if the value is retrieved using the REGTYPE_STRING type, an empty string is returned even if no value is assigned).
	*/
	result GetValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, int& retVal) const;


	/**
	* Gets the double value of the specified entry.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The name of entry where its value will be fetched
	* @param[out]	retVal					The return value obtained from the registry
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @exception	E_PARSING_FAILED		The method has failed to parse the encoded entry value string, or the value is retrieved by using an incorrect data type.
	* @exception	E_DATA_NOT_FOUND		The name-value pair has no value assigned (if the value is retrieved using the REGTYPE_STRING type, an empty string is returned even if no value is assigned).
	*/
	result GetValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, double& retVal) const;


	/**
	* Gets the float value of the specified entry.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The name of entry where its value will be fetched
	* @param[out]	retVal					The return value obtained from the registry
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @exception	E_PARSING_FAILED		The method has failed to parse the encoded entry value string, or the value is retrieved by using an incorrect data type.
	* @exception	E_DATA_NOT_FOUND		The name-value pair has no value assigned (if the value is retrieved using the REGTYPE_STRING type, an empty string is returned even if no value is assigned).
	*/
	result GetValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, float& retVal) const;


	/**
	* Gets the String value of a specific entry.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The name of entry where its value will be fetched
	* @param[out]	retVal					The return value obtained from the registry
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @exception	E_PARSING_FAILED		The method has failed to parse the encoded entry value string, or the value is retrieved by using an incorrect data type.
	* @exception	E_DATA_NOT_FOUND		The name-value pair has no value assigned (if the value is retrieved using the REGTYPE_STRING type, an empty string is returned even if no value is assigned).
	*/
	result GetValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, Osp::Base::String& retVal) const;


	/**
	* Gets the UuId value of the specified entry.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The name of entry where its value will be fetched
	* @param[out]	retVal					The return value obtained from the registry
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND	    The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @exception	E_PARSING_FAILED		The method has failed to parse the encoded entry value string, or the value is retrieved by using an incorrect data type.
	* @exception	E_DATA_NOT_FOUND		The name-value pair has no value assigned (if the value is retrieved using the REGTYPE_STRING type, an empty string is returned even if no value is assigned).
	*/
	result GetValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, Osp::Base::UuId& retVal) const;


	/**
	* Gets the ByteBuffer value of the specified entry.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The name of entry where its value will be fetched
	* @param[out]	retVal					The return value obtained from the registry
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @exception	E_PARSING_FAILED		The method has failed to parse the encoded entry value string, or the value is retrieved by using an incorrect data type.
	* @exception	E_DATA_NOT_FOUND		The name-value pair has no value assigned (if the value is retrieved using the REGTYPE_STRING type, an empty string is returned even if no value is assigned).
	* @remarks		The ByteBuffer should be constructed before passing it to the method.
	*				That is, the size of the binary data to be fetched should be decided beforehand.
	*				When the ByteBuffer capacity is less than the actual binary data stored in the registry,
	*				this method reads the data as much as the ByteBuffer capacity. The position of the ByteBuffer and
	*				limit are not changed. When the ByteBuffer capacity is greater than the actual data size,
	*				the method reads the whole data and adjusts the limit of the buffer accordingly.
	* @see			Osp::Base::ByteBuffer
	*/
	result GetValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, Osp::Base::ByteBuffer& retVal) const;


	/**
	* Modifies the value of the specified entry using the specified int value.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name to modify
	* @param[in]	newValue				The @c int value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @remarks		This method will not add a name-value pair as an entry of a specific section
	*               if no entry with the specified name exists.
	*				In such a case, it returns E_KEY_NOT_FOUND. Use AddValue() to insert a new entry.
	* @see			AddValue()
	*/
	result SetValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, int newValue);


	/**
	* Modifies the value of the specified entry using the specified double value.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name to modify
	* @param[in]	newValue				The @c double value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @remarks		This method will not add a name-value pair as an entry of a specific section
	*               if no entry with the specified name exists.
	*				In such a case, it returns E_KEY_NOT_FOUND. Use AddValue() to insert a new entry.
	* @see			AddValue()
	*/
	result SetValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, double newValue);


	/**
	* Modifies the value of the specified entry using the specified float value.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name to modify
	* @param[in]	newValue				The @c float value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @remarks		This method will not add a name-value pair as an entry of a specific section
	*               if no entry with the specified name exists.
	*				In such a case, it returns E_KEY_NOT_FOUND. Use AddValue() to insert a new entry.
	* @see			AddValue()
	*/
	result SetValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, float newValue);

	/**
	* Modifies the value of the specified entry using the specified String value.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name to modify
	* @param[in]	newValue				The @c String value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @remarks		This method will not add a name-value pair as an entry of a specific section
	*               if no entry with the specified name exists.
	*				In such a case, it returns E_KEY_NOT_FOUND. Use AddValue() to insert a new entry.
	* @see			AddValue()
	*/
	result SetValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, const Osp::Base::String& newValue);


	/**
	* Modifies the value of the specified entry using the specified UuID value.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name to modify
	* @param[in]	newValue				The UuId value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @remarks		This method will not add a name-value pair as an entry of a specific section if no
	*               entry with the specified name exists.
	*				In such a case, it returns E_KEY_NOT_FOUND. Use AddValue() to insert a new entry.
	* @see			AddValue()
	*/
	result SetValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, const Osp::Base::UuId& newValue);


	/**
	* Modifies the value of the specified entry using the specified ByteBuffer value.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name to modify
	* @param[in]	newValue				The @c ByteBuffer value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @remarks		This method will not add a name-value pair as an entry of a specific section
	*               if no entry with the specified name exists.
	*				In such a case, it returns E_KEY_NOT_FOUND. Use AddValue() to insert a new entry.
	* @see			AddValue()
	*/
	result SetValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName, const Osp::Base::ByteBuffer& newValue);


	/**
	* Removes the name-value pair entry from specific section.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The name of the entry to remove
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			The length of the specified string for a section or entry is less
	*                                       than or equal to @c 0.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	*/
	result RemoveValue(const Osp::Base::String& sectionName, const Osp::Base::String& entryName);


public:
	/**
	* Removes the specified registry file.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	regPath					The path of the registry file to remove
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref RegistryPrefixWritable "here".
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The length of the specified string of a file path is less
	*                                             than or equal to @c 0. @n
	*											- The translated overall length of the specified path exceeds the
	*											  system limitation. @n
	*											- The specified path contains prohibited character(s). @n
	*											- The specified path is invalid. @n
	*											- The application ID of the application accessing '/Share2/[@e appid]' or '/Share2Ext/[@e appid]'
	*											  does not belong to the trusted application list of the provider application.
	* @exception	E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception	E_ILLEGAL_ACCESS        The specified path is not permitted, or
	* 										access is denied due to insufficient permission.
	* @exception	E_IO			        An unexpected device failure has occurred as the media ejected suddenly or file corruption is detected.
	*/
	static result Remove(const Osp::Base::String& regPath);

	/**
	* Converts a normal registry file to a secure registry file. @n
	* A secure registry file that is converted by this method is only used for a current application. @n
	* This method is static.
	*
	* @deprecated	This method is deprecated because using platform device key for encryption is no longer recommended.
	* @since 2.0
	*
	* @return		An error code
	* @param[in]	plainRegPath			The normal (non-encrypted) registry file path @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref RegistryPrefixReadable "here".
	* @param[in]	secureRegPath			The secure (encrypted) registry file path to be created @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref RegistryPrefixWritable "here".
	* @exception	E_SUCCESS              	The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The length of the specified string of a file path is less
	*                                             than or equal to @c 0. @n
	*											- The translated overall length of the specified path exceeds the
	*											  system limitation. @n
	* 											- The specified path contains prohibited character(s). @n
	*											- The specified path is invalid. @n
	*											- The application ID of the application accessing '/Share2/[@e appid]' or '/Share2Ext/[@e appid]'
	*											  does not belong to the trusted application list of the provider application. @n
	*											- The input registry file specified by the @c plainRegPath parameter
	*											  is an encrypted registry file.
	* @exception	E_ILLEGAL_ACCESS		The specified path is not permitted, or
	* 										access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already existed.
	* @exception	E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found. 
	* @exception	E_INVALID_FORMAT		The input registry file contains '0x00' in the middle of the file.
	* @exception	E_PARSING_FAILED		The method has failed to parse the registry file.
	* @exception	E_STORAGE_FULL			The disk space is full.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*											- An unexpected device failure has occurred as the media ejected suddenly. @n
	*											- %File corruption is detected. @n
	*											- The number of opened files has exceeded the maximum limit.
	*
	* @remarks		If applications share a secure registry file that is to be converted, use ConvertToSecureRegistry(const Osp::Base::String &plainRegPath,
	* 				const Osp::Base::String &secureRegPath, const Osp::Base::ByteBuffer& key).
	*/
	static result ConvertToSecureRegistry(const Osp::Base::String &plainRegPath, const Osp::Base::String &secureRegPath);

	/**
	* Converts a normal registry file to a secure registry file. @n
	* A secure registry file that is converted by this method can be shared among applications with the same key value. @n
	* This method is static.
	* @since 2.0
	*
	* @return		An error code
	* @param[in]	plainRegPath			The normal (non-encrypted) registry file path @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref RegistryPrefixReadable "here".
	* @param[in]	secureRegPath			The secure (encrypted) registry file path to be created @n
	*										This path should be an absolute path beginning with an allowed path prefix. @n
	*										For more information on the allowed path prefixes for this argument,
	*										see @ref RegistryPrefixWritable "here".
	* @param[in]	key						A key that encrypts a secure registry file @n
	*										If the secure registry file is converted with a specific key value,
	*										applications can access the same secure registry file with the identical key value.
	* @exception	E_SUCCESS              	The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The length of the specified string of a file path is less
	*                                             than or equal to @c 0. @n
	*											- The translated overall length of the specified path exceeds the
	*											  system limitation. @n
	* 											- The specified path contains prohibited character(s). @n
	*											- The specified path is invalid. @n
	*											- The application ID of the application accessing '/Share2/[@e appid]' or '/Share2Ext/[@e appid]'
	*											  does not belong to the trusted application list of the provider application.
	*											- The input registry file specified by the @c plainRegPath parameter
	*											  is an encrypted registry file.
	* @exception	E_ILLEGAL_ACCESS		The specified path is not permitted, or
	* 										access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already existed.
	* @exception	E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found. 
	* @exception	E_INVALID_FORMAT		The input registry file contains '0x00' in the middle of the file.
	* @exception	E_PARSING_FAILED		The method has failed to parse the registry file.
	* @exception	E_STORAGE_FULL			The disk space is full.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*											- An unexpected device failure has occurred as the media ejected suddenly. @n
	*											- %File corruption is detected. @n
	*											- The number of opened files has exceeded the maximum limit. 
	*/
	static result ConvertToSecureRegistry(const Osp::Base::String &plainRegPath, const Osp::Base::String &secureRegPath, const Osp::Base::ByteBuffer& key);


private:

// Lifecycle

	/**
	* This is the copy constructor for the %Registry class.
	*
	* @remarks		This constructor is hidden.
	*/
	Registry(const Registry& value);


// Operator

	/**
	* This is the assignment operator.
	*
	* @remarks		This operator is hidden.
	*/
	Registry& operator =(const Registry& value);


	/**
	* Frees the resource allocated by this instance.
	*
	* @return		An error code
	* @exception	E_SUCCESS	The method is successful.
	*/
	result Dispose(void);

private:
	static result CheckAccessibilityToPath(void *path, int *pPathKind, int nPrivilegeKind);
	result ReleaseRsrc(void);

private:
	bool __bConstructed;
	bool __isMonitored;
	void *__pMRegistry;
	Osp::Base::String __regFilePathName;

private:
	friend class RegistryEx;
	class RegistryEx *__pRegistryEx;

};// Registry
};// Osp::Io
};// Osp
#endif//_FIO_REGISTRY_H_
