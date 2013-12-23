/* $Change: 1114438 $ */
/**
 * Summary: interface for the I/O interfaces used by the parser
 * Description: interface for the I/O interfaces used by the parser
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

/**
 * @file		xmlIO.h
 * @brief	This is the header file for libxml
 *
 *
 */ 
#ifndef __XML_IO_H__
#define __XML_IO_H__

#ifndef SHP
#include <stdio.h>
#endif

#include <libxml/xmlversion.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Those are the functions and datatypes for the parser input
 * I/O structures.
 */

/**
 * xmlInputMatchCallback:
 * @param[in]	filename	the filename or URI
 *
 * Callback used in the I/O Input API to detect if the current handler 
 * can provide input functionalities for this resource.
 *
 * Returns 1 if yes and 0 if another Input module should be used
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef int (*xmlInputMatchCallback) (char const *filename);
/**
 * xmlInputOpenCallback:
 * @param[in]	filename	the filename or URI
 *
 * Callback used in the I/O Input API to open the resource
 *
 * Returns an Input context or NULL in case or error
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void * (*xmlInputOpenCallback) (char const *filename);

/**
 * xmlInputReadCallback:
 * @param[in]	context		an Input context
 * @param[in]	buffer		the buffer to store data read
 * @param[in]	len			the length of the buffer in bytes
 *
 * Callback used in the I/O Input API to read the resource
 *
 * Returns the number of bytes read or -1 in case of error
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since	1.0
 */
 
typedef int (*xmlInputReadCallback) (void * context, char * buffer, int len);

/**
 * xmlInputCloseCallback:
 * @param[in]	context		an Input context
 *
 * Callback used in the I/O Input API to close the resource
 *
 * Returns 0 or -1 in case of error
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since	1.0
 */
typedef int (*xmlInputCloseCallback) (void * context);

#ifdef LIBXML_OUTPUT_ENABLED
/*
 * Those are the functions and datatypes for the library output
 * I/O structures.
 */

/**
 * xmlOutputMatchCallback:
 * @param[in]	filename the filename or URI
 *
 * Callback used in the I/O Output API to detect if the current handler 
 * can provide output functionalities for this resource.
 *
 * Returns 1 if yes and 0 if another Output module should be used
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since	1.0
 */
typedef int (*xmlOutputMatchCallback) (char const *filename);
/**
 * xmlOutputOpenCallback:
 * @param[in]	filename	 the filename or URI
 *
 * Callback used in the I/O Output API to open the resource
 *
 * Returns an Output context or NULL in case or error
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since	1.0
 */
typedef void * (*xmlOutputOpenCallback) (char const *filename);
/**
 * xmlOutputWriteCallback:
 * @param[in]	context	  an Output context
 * @param[in]	buffer	  the buffer of data to write
 * @param[in]	len	  the length of the buffer in bytes
 *
 * Callback used in the I/O Output API to write to the resource
 *
 * Returns the number of bytes written or -1 in case of error
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since	1.0
 */
typedef int (*xmlOutputWriteCallback) (void * context, const char * buffer,
                                       int len);
/**
 * xmlOutputCloseCallback:
 * @param[in]	context	an Output context
 *
 * Callback used in the I/O Output API to close the resource
 *
 * Returns 0 or -1 in case of error
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since	1.0
 */
typedef int (*xmlOutputCloseCallback) (void * context);
#endif /* LIBXML_OUTPUT_ENABLED */

#ifdef __cplusplus
}
#endif

#include <libxml/globals.h>
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/encoding.h>

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief Represents a structure in Libxml2
 *
 *For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 *@since 1.0
 */
struct _xmlParserInputBuffer {
    void*                  context;				/**< */
    xmlInputReadCallback   readcallback;		/**< */
    xmlInputCloseCallback  closecallback;		/**< */
    
    xmlCharEncodingHandlerPtr encoder; /**< I18N conversions to UTF-8 */
    
    xmlBufferPtr buffer;    /**< Local buffer encoded in UTF-8 */
    xmlBufferPtr raw;       /**< if encoder != NULL buffer for raw input */
    int	compressed;			/**< -1=unknown, 0=not compressed, 1=compressed */
    int error;				/**< */
    unsigned long rawconsumed;/**< amount consumed from raw */
};


#ifdef LIBXML_OUTPUT_ENABLED
/**
 * @brief Represents a structure in Libxml2
 *
 *For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 *@since 1.0
 */
struct _xmlOutputBuffer {
    void*                   context;		/**< */
    xmlOutputWriteCallback  writecallback;	/**< */
    xmlOutputCloseCallback  closecallback;	/**< */
    
    xmlCharEncodingHandlerPtr encoder; /**< I18N conversions to UTF-8 */
    
    xmlBufferPtr buffer;    /**< Local buffer encoded in UTF-8 or ISOLatin */
    xmlBufferPtr conv;      /**< if encoder != NULL buffer for output */
    int written;            /**< total number of byte written */
    int error;				/**< */
};
#endif /* LIBXML_OUTPUT_ENABLED */

/*
 * Interfaces for input
 */
/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN void XMLCALL	
	xmlCleanupInputCallbacks		(void);
/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL
	xmlPopInputCallbacks			(void);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */

XMLPUBFUN void XMLCALL	
	xmlRegisterDefaultInputCallbacks	(void);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN xmlParserInputBufferPtr XMLCALL
	xmlAllocParserInputBuffer		(xmlCharEncoding enc);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN xmlParserInputBufferPtr XMLCALL
	xmlParserInputBufferCreateFilename	(const char *URI,
                                                 xmlCharEncoding enc);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN xmlParserInputBufferPtr XMLCALL
	xmlParserInputBufferCreateMem		(const char *mem, int size,
	                                         xmlCharEncoding enc);
/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN xmlParserInputBufferPtr XMLCALL
	xmlParserInputBufferCreateStatic	(const char *mem, int size,
	                                         xmlCharEncoding enc);
/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN xmlParserInputBufferPtr XMLCALL
	xmlParserInputBufferCreateIO		(xmlInputReadCallback   ioread,
						 xmlInputCloseCallback  ioclose,
						 void *ioctx,
	                                         xmlCharEncoding enc);
/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL	
	xmlParserInputBufferRead		(xmlParserInputBufferPtr in,
						 int len);
/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL	
	xmlParserInputBufferGrow		(xmlParserInputBufferPtr in,
						 int len);
/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL	
	xmlParserInputBufferPush		(xmlParserInputBufferPtr in,
						 int len,
						 const char *buf);
/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN void XMLCALL	
	xmlFreeParserInputBuffer		(xmlParserInputBufferPtr in);
/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN char * XMLCALL	
	xmlParserGetDirectory			(const char *filename);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL     
	xmlRegisterInputCallbacks		(xmlInputMatchCallback matchFunc,
						 xmlInputOpenCallback openFunc,
						 xmlInputReadCallback readFunc,
						 xmlInputCloseCallback closeFunc);
#ifdef LIBXML_OUTPUT_ENABLED
/*
 * Interfaces for output
 */
/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN void XMLCALL	
	xmlCleanupOutputCallbacks		(void);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN void XMLCALL	
	xmlRegisterDefaultOutputCallbacks(void);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN xmlOutputBufferPtr XMLCALL
	xmlAllocOutputBuffer		(xmlCharEncodingHandlerPtr encoder);


/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN xmlOutputBufferPtr XMLCALL
	xmlOutputBufferCreateFilename	(const char *URI,
					 xmlCharEncodingHandlerPtr encoder,
					 int compression);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN xmlOutputBufferPtr XMLCALL
	xmlOutputBufferCreateIO		(xmlOutputWriteCallback   iowrite,
					 xmlOutputCloseCallback  ioclose,
					 void *ioctx,
					 xmlCharEncodingHandlerPtr encoder);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL	
	xmlOutputBufferWrite		(xmlOutputBufferPtr out,
					 int len,
					 const char *buf);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL	
	xmlOutputBufferWriteString	(xmlOutputBufferPtr out,
					 const char *str);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL	
	xmlOutputBufferWriteEscape	(xmlOutputBufferPtr out,
					 const xmlChar *str,
					 xmlCharEncodingOutputFunc escaping);


/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL	
	xmlOutputBufferFlush		(xmlOutputBufferPtr out);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL	
	xmlOutputBufferClose		(xmlOutputBufferPtr out);


/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL     
	xmlRegisterOutputCallbacks	(xmlOutputMatchCallback matchFunc,
					 xmlOutputOpenCallback openFunc,
					 xmlOutputWriteCallback writeFunc,
					 xmlOutputCloseCallback closeFunc);
#endif /* LIBXML_OUTPUT_ENABLED */

/*  This function only exists if HTTP support built into the library  */
#ifdef LIBXML_HTTP_ENABLED

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN void * XMLCALL	
	xmlIOHTTPOpenW			(const char * post_uri,
					 int   compression );

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN void XMLCALL	
	xmlRegisterHTTPPostCallbacks	(void );
#endif

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN xmlParserInputPtr XMLCALL
	xmlCheckHTTPInput		(xmlParserCtxtPtr ctxt,
					 xmlParserInputPtr ret);

/*
 * A predefined entity loader disabling network accesses
 */

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN xmlParserInputPtr XMLCALL 
	xmlNoNetExternalEntityLoader	(const char *URL,
					 const char *ID,
					 xmlParserCtxtPtr ctxt);

/* 
 * xmlNormalizeWindowsPath is obsolete, don't use it. 
 * Check xmlCanonicPath in uri.h for a better alternative.
 */
/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN xmlChar * XMLCALL 
	xmlNormalizeWindowsPath		(const xmlChar *path);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL	
	xmlCheckFilename		(const char *path);
/*
 * Default 'file://' protocol callbacks 
 */

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL	
	xmlFileMatch 			(const char *filename);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN void * XMLCALL	
	xmlFileOpen 			(const char *filename);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL	
	xmlFileRead 			(void * context, 
					 char * buffer, 
					 int len);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL	
	xmlFileClose 			(void * context);

/*
 * Default 'http://' protocol callbacks 
 */
#ifdef LIBXML_HTTP_ENABLED

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL	
	xmlIOHTTPMatch 			(const char *filename);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN void * XMLCALL	
	xmlIOHTTPOpen 			(const char *filename);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL 	
	xmlIOHTTPRead			(void * context, 
					 char * buffer, 
					 int len);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL	
	xmlIOHTTPClose 			(void * context);
#endif /* LIBXML_HTTP_ENABLED */

/*
 * Default 'ftp://' protocol callbacks 
 */
#ifdef LIBXML_FTP_ENABLED 

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL	
	xmlIOFTPMatch 			(const char *filename);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN void * XMLCALL	
	xmlIOFTPOpen 			(const char *filename);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL 	
	xmlIOFTPRead			(void * context, 
					 char * buffer, 
					 int len);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL 	
	xmlIOFTPClose 			(void * context);
#endif /* LIBXML_FTP_ENABLED */

#ifdef __cplusplus
}
#endif

#endif /* __XML_IO_H__ */
