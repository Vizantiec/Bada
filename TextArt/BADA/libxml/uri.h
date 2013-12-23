/* $Change: 1114438 $ */
/**
 * Summary: library of generic URI related routines
 * Description: library of generic URI related routines
 *              Implements RFC 2396
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

 /**
 * @file		uri.h
 * @brief	This is the header file for libxml
 *
 *
 */

#ifndef __XML_URI_H__
#define __XML_URI_H__

#include <libxml/xmlversion.h>
#include <libxml/tree.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup libxml2
 * 
 * @{
 */
 
/* STDIO_FILE */
/* Blocked API -> Osp App cannot use FILE pointer in stdio.h */
/* 2010 / 01 / 15, Seonhyung Lee */
/*
XMLPUBFUN void XMLCALL		
		xmlPrintURI		(FILE *stream,
					 xmlURIPtr uri);
*/

/**
 * xmlURI:
 *
 * A parsed URI reference. This is a struct containing the various fields
 * as described in RFC 2396 but separated for further processing.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef struct _xmlURI xmlURI;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlURI *xmlURIPtr;
/**
 * @brief Represents a structure in Libxml2
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
struct _xmlURI {
    char *scheme;	/**< the URI scheme */
    char *opaque;	/**< opaque part */
    char *authority;	/**< the authority part */
    char *server;	/**< the server part */
    char *user;		/**< the user part */
    int port;		/**< the port number */
    char *path;		/**< the path string */
    char *query;	/**< the query string */
    char *fragment;	/**< the fragment identifier */
    int  cleanup;	/**< parsing potentially unclean URI */
};

/*
 * This function is in tree.h:
 * xmlChar *	xmlNodeGetBase	(xmlDocPtr doc,
 *                               xmlNodePtr cur);
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlURIPtr XMLCALL	
		xmlCreateURI		(void);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL	
		xmlBuildURI		(const xmlChar *URI,
	                        	 const xmlChar *base);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlURIPtr XMLCALL	
		xmlParseURI		(const char *str);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlParseURIReference	(xmlURIPtr uri,
					 const char *str);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL	
		xmlSaveUri		(xmlURIPtr uri);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL       
		xmlURIEscapeStr         (const xmlChar *str,
 					 const xmlChar *list);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN char * XMLCALL		
		xmlURIUnescapeString	(const char *str,
					 int len,
					 char *target);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlNormalizeURIPath	(char *path);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL	
		xmlURIEscape		(const xmlChar *str);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlFreeURI		(xmlURIPtr uri);
/**
 * xmlCanonicPath
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar* XMLCALL	
		xmlCanonicPath		(const xmlChar *path);

/**
 * @}
 */
 
#ifdef __cplusplus
}
#endif
#endif /* __XML_URI_H__ */
