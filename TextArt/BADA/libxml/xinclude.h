/* $Change: 1114438 $ */
/*
 * Summary: implementation of XInclude
 * Description: API to handle XInclude processing,
 * implements the
 * World Wide Web Consortium Last Call Working Draft 10 November 2003
 * http://www.w3.org/TR/2003/WD-xinclude-20031110
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

#ifndef __XML_XINCLUDE_H__
#define __XML_XINCLUDE_H__

#include <libxml/xmlversion.h>
#include <libxml/tree.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * XINCLUDE_NS:
 *
 * Macro defining the Xinclude namespace: http://www.w3.org/2003/XInclude
 *
 * @since 1.0
 */
#define XINCLUDE_NS (const xmlChar *) "http://www.w3.org/2003/XInclude"
/*
 * XINCLUDE_OLD_NS:
 *
 * Macro defining the draft Xinclude namespace: http://www.w3.org/2001/XInclude
 *
 * @since 1.0
 */
#define XINCLUDE_OLD_NS (const xmlChar *) "http://www.w3.org/2001/XInclude"
/*
 * XINCLUDE_NODE:
 *
 * Macro defining "include"
 *
 * @since 1.0
 */
#define XINCLUDE_NODE (const xmlChar *) "include"
/*
 * XINCLUDE_FALLBACK:
 *
 * Macro defining "fallback"
 *
 * @since 1.0
 */
#define XINCLUDE_FALLBACK (const xmlChar *) "fallback"
/*
 * XINCLUDE_HREF:
 *
 * Macro defining "href"
 *
 * @since 1.0
 */
#define XINCLUDE_HREF (const xmlChar *) "href"
/*
 * XINCLUDE_PARSE:
 *
 * Macro defining "parse"
 *
 * @since 1.0
 */
#define XINCLUDE_PARSE (const xmlChar *) "parse"
/*
 * XINCLUDE_PARSE_XML:
 *
 * Macro defining "xml"
 *
 * @since 1.0
 */
#define XINCLUDE_PARSE_XML (const xmlChar *) "xml"
/*
 * XINCLUDE_PARSE_TEXT:
 *
 * Macro defining "text"
 *
 * @since 1.0
 */
#define XINCLUDE_PARSE_TEXT (const xmlChar *) "text"
/*
 * XINCLUDE_PARSE_ENCODING:
 *
 * Macro defining "encoding"
 *
 * @since 1.0
 */
#define XINCLUDE_PARSE_ENCODING (const xmlChar *) "encoding"
/*
 * XINCLUDE_PARSE_XPOINTER:
 *
 * Macro defining "xpointer"
 *
 * @since 1.0
 */
#define XINCLUDE_PARSE_XPOINTER (const xmlChar *) "xpointer"

typedef struct _xmlXIncludeCtxt xmlXIncludeCtxt;
typedef xmlXIncludeCtxt *xmlXIncludeCtxtPtr;

/*
 * standalone processing
 */
XMLPUBFUN int XMLCALL	
		xmlXIncludeProcess	(xmlDocPtr doc);
XMLPUBFUN int XMLCALL	
		xmlXIncludeProcessFlags	(xmlDocPtr doc,
					 int flags);
XMLPUBFUN int XMLCALL	
		xmlXIncludeProcessTree	(xmlNodePtr tree);
XMLPUBFUN int XMLCALL	
		xmlXIncludeProcessTreeFlags(xmlNodePtr tree,
					 int flags);
/*
 * contextual processing
 */
XMLPUBFUN xmlXIncludeCtxtPtr XMLCALL
		xmlXIncludeNewContext	(xmlDocPtr doc);
XMLPUBFUN int XMLCALL
		xmlXIncludeSetFlags	(xmlXIncludeCtxtPtr ctxt,
					 int flags);
XMLPUBFUN void XMLCALL
		xmlXIncludeFreeContext	(xmlXIncludeCtxtPtr ctxt);
XMLPUBFUN int XMLCALL
		xmlXIncludeProcessNode	(xmlXIncludeCtxtPtr ctxt,
					 xmlNodePtr tree);
#ifdef __cplusplus
}
#endif
#endif /* __XML_XINCLUDE_H__ */
