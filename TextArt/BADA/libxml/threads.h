/* $Change: 1114438 $ */
/**
 * Summary: interfaces for thread handling
 * Description: set of generic threading related routines
 *              should work with pthreads, Windows native or TLS threads
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

#ifndef __XML_THREADS_H__
#define __XML_THREADS_H__

#include <libxml/xmlversion.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * xmlMutex are a simple mutual exception locks.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
typedef struct _xmlMutex xmlMutex;

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
typedef xmlMutex *xmlMutexPtr;

/**
 * xmlRMutex are reentrant mutual exception locks.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
typedef struct _xmlRMutex xmlRMutex;

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
typedef xmlRMutex *xmlRMutexPtr;

#ifdef __cplusplus
}
#endif
#include <libxml/globals.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
XMLPUBFUN xmlMutexPtr XMLCALL		
			xmlNewMutex	(void);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */

XMLPUBFUN void XMLCALL			
			xmlMutexLock	(xmlMutexPtr tok);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlMutexUnlock	(xmlMutexPtr tok);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlFreeMutex	(xmlMutexPtr tok);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
XMLPUBFUN xmlRMutexPtr XMLCALL		
			xmlNewRMutex	(void);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlRMutexLock	(xmlRMutexPtr tok);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlRMutexUnlock	(xmlRMutexPtr tok);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlFreeRMutex	(xmlRMutexPtr tok);

/*
 * Library wide APIs.
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlInitThreads	(void);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlLockLibrary	(void);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlUnlockLibrary(void);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			
			xmlGetThreadId	(void);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			
			xmlIsMainThread	(void);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlCleanupThreads(void);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 1.0
 */
XMLPUBFUN xmlGlobalStatePtr XMLCALL	
			xmlGetGlobalState(void);

#ifdef __cplusplus
}
#endif


#endif /* __XML_THREADS_H__ */
