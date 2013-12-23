/* $Change: 1114438 $ */
/**
 * Summary: chained hash tables
 * description: this module implement the hash table support used in 
 * various place in the library.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Bjorn Reese <bjorn.reese@systematic.dk>
 */

/**
 * @file		hash.h
 * @brief	This is the header file for libxml
 *
 *
 */

#ifndef __XML_HASH_H__
#define __XML_HASH_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup libxml2
 * 
 * @{
 */
 
/**
 * The hash table.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef struct _xmlHashTable xmlHashTable;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlHashTable *xmlHashTablePtr;

#ifdef __cplusplus
}
#endif

#include <libxml/xmlversion.h>
#include <libxml/parser.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * function types:
 */
/**
 * xmlHashDeallocator:
 * @param[in]	payload		the data in the hash
 * @param[in]	name		the name associated
 *
 * Callback to free data from a hash.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

typedef void (*xmlHashDeallocator)(void *payload, xmlChar *name);
/**
 * xmlHashCopier:
 * @param[in]	payload		the data in the hash
 * @param[in]	name		the name associated
 *
 * Callback to copy data from a hash.
 *
 * Returns a copy of the data or NULL in case of error.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void *(*xmlHashCopier)(void *payload, xmlChar *name);
/**
 * xmlHashScanner:
 * @param[in]	payload		the data in the hash
 * @param[in]	data		extra scanner data
 * @param[in]	name		the name associated
 *
 * Callback when scanning data in a hash with the simple scanner.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*xmlHashScanner)(void *payload, void *data, xmlChar *name);
/**
 * xmlHashScannerFull:
 * @param[in]	payload	the data in the hash
 * @param[in]	data	extra scanner data
 * @param[in]	name	the name associated
 * @param[in]	name2	the second name associated
 * @param[in]	name3	the third name associated
 *
 * Callback when scanning data in a hash with the full scanner.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*xmlHashScannerFull)(void *payload, void *data,
				   const xmlChar *name, const xmlChar *name2,
				   const xmlChar *name3);

/*
 * Constructor and destructor.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlHashTablePtr XMLCALL
			xmlHashCreate	(int size);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
 XMLPUBFUN void XMLCALL			
			xmlHashFree	(xmlHashTablePtr table,
					 xmlHashDeallocator f);

/*
 * Add a new entry to the hash table.
 *
 */
 
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
 XMLPUBFUN int XMLCALL			
			xmlHashAddEntry	(xmlHashTablePtr table,
		                         const xmlChar *name,
		                         void *userdata);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
 XMLPUBFUN int XMLCALL			
			xmlHashUpdateEntry(xmlHashTablePtr table,
		                         const xmlChar *name,
		                         void *userdata,
					 xmlHashDeallocator f);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
 XMLPUBFUN int XMLCALL		    
			xmlHashAddEntry2(xmlHashTablePtr table,
		                         const xmlChar *name,
		                         const xmlChar *name2,
		                         void *userdata);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
 XMLPUBFUN int XMLCALL			
			xmlHashUpdateEntry2(xmlHashTablePtr table,
		                         const xmlChar *name,
		                         const xmlChar *name2,
		                         void *userdata,
					 xmlHashDeallocator f);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
 XMLPUBFUN int XMLCALL			
			xmlHashAddEntry3(xmlHashTablePtr table,
		                         const xmlChar *name,
		                         const xmlChar *name2,
		                         const xmlChar *name3,
		                         void *userdata);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			
			xmlHashUpdateEntry3(xmlHashTablePtr table,
		                         const xmlChar *name,
		                         const xmlChar *name2,
		                         const xmlChar *name3,
		                         void *userdata,
					 xmlHashDeallocator f);

/*
 * Remove an entry from the hash table.
 */
 
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
 XMLPUBFUN int XMLCALL     
			xmlHashRemoveEntry(xmlHashTablePtr table, const xmlChar *name,
                           xmlHashDeallocator f);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL     
			xmlHashRemoveEntry2(xmlHashTablePtr table, const xmlChar *name,
                            const xmlChar *name2, xmlHashDeallocator f);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int  XMLCALL    
			xmlHashRemoveEntry3(xmlHashTablePtr table, const xmlChar *name,
                            const xmlChar *name2, const xmlChar *name3,
                            xmlHashDeallocator f);

/*
 * Retrieve the userdata.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void * XMLCALL			
			xmlHashLookup	(xmlHashTablePtr table,
					 const xmlChar *name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void * XMLCALL			
			xmlHashLookup2	(xmlHashTablePtr table,
					 const xmlChar *name,
					 const xmlChar *name2);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void * XMLCALL			
			xmlHashLookup3	(xmlHashTablePtr table,
					 const xmlChar *name,
					 const xmlChar *name2,
					 const xmlChar *name3);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void * XMLCALL			
			xmlHashQLookup	(xmlHashTablePtr table,
					 const xmlChar *name,
					 const xmlChar *prefix);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void * XMLCALL			
			xmlHashQLookup2	(xmlHashTablePtr table,
					 const xmlChar *name,
					 const xmlChar *prefix,
					 const xmlChar *name2,
					 const xmlChar *prefix2);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void * XMLCALL			
			xmlHashQLookup3	(xmlHashTablePtr table,
					 const xmlChar *name,
					 const xmlChar *prefix,
					 const xmlChar *name2,
					 const xmlChar *prefix2,
					 const xmlChar *name3,
					 const xmlChar *prefix3);

/*
 * Helpers.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlHashTablePtr XMLCALL		
			xmlHashCopy	(xmlHashTablePtr table,
					 xmlHashCopier f);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			
			xmlHashSize	(xmlHashTablePtr table);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlHashScan	(xmlHashTablePtr table,
					 xmlHashScanner f,
					 void *data);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlHashScan3	(xmlHashTablePtr table,
					 const xmlChar *name,
					 const xmlChar *name2,
					 const xmlChar *name3,
					 xmlHashScanner f,
					 void *data);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlHashScanFull	(xmlHashTablePtr table,
					 xmlHashScannerFull f,
					 void *data);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlHashScanFull3(xmlHashTablePtr table,
					 const xmlChar *name,
					 const xmlChar *name2,
					 const xmlChar *name3,
					 xmlHashScannerFull f,
					 void *data);

/**
 * @}
 */
 
#ifdef __cplusplus
}
#endif
#endif /* ! __XML_HASH_H__ */
