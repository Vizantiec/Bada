/* $Change: 1114438 $ */
/**
 * Summary: specific APIs to process HTML tree, especially serialization
 * Description: this module implements a few function needed to process
 *              tree in an HTML specific way.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

/**
 * @file	HTMLtree.h
 * @brief	This is the header file for libxml
 *
 *
 */

#ifndef __HTML_TREE_H__
#define __HTML_TREE_H__

#include <stdio.h>
#include <libxml/xmlversion.h>
#include <libxml/tree.h>
#include <libxml/HTMLparser.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup libxml2
 * 
 * @{
 */

/*
 * HTML_TEXT_NODE:
 *
 * Macro. A text node in a HTML document is really implemented
 * the same way as a text node in an XML document.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a> 
 *
 * @since 1.0
 */
#define HTML_TEXT_NODE		XML_TEXT_NODE
/*
 * HTML_ENTITY_REF_NODE:
 *
 * Macro. An entity reference in a HTML document is really implemented
 * the same way as an entity reference in an XML document.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a> 
 *
 * @since 1.0
 */
#define HTML_ENTITY_REF_NODE	XML_ENTITY_REF_NODE
/*
 * HTML_COMMENT_NODE:
 *
 * Macro. A comment in a HTML document is really implemented
 * the same way as a comment in an XML document.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a> 
 *
 * @since 1.0
 */
#define HTML_COMMENT_NODE	XML_COMMENT_NODE
/*
 * HTML_PRESERVE_NODE:
 *
 * Macro. A preserved node in a HTML document is really implemented
 * the same way as a CDATA section in an XML document.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define HTML_PRESERVE_NODE	XML_CDATA_SECTION_NODE
/*
 * HTML_PI_NODE:
 *
 * Macro. A processing instruction in a HTML document is really implemented
 * the same way as a processing instruction in an XML document.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define HTML_PI_NODE		XML_PI_NODE

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN htmlDocPtr XMLCALL
		htmlNewDoc		(const xmlChar *URI,
					 const xmlChar *ExternalID);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN htmlDocPtr XMLCALL	
		htmlNewDocNoDtD		(const xmlChar *URI,
					 const xmlChar *ExternalID);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN const xmlChar * XMLCALL	
		htmlGetMetaEncoding	(htmlDocPtr doc);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		htmlSetMetaEncoding	(htmlDocPtr doc,
					 const xmlChar *encoding);
#ifdef LIBXML_OUTPUT_ENABLED
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL	    
		htmlDocDumpMemory	(xmlDocPtr cur,
					 xmlChar **mem,
					 int *size);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		htmlSaveFile		(const char *filename,
					 xmlDocPtr cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		htmlNodeDump		(xmlBufferPtr buf,
					 xmlDocPtr doc,
					 xmlNodePtr cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		htmlSaveFileEnc		(const char *filename,
					 xmlDocPtr cur,
					 const char *encoding);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		htmlSaveFileFormat	(const char *filename,
					 xmlDocPtr cur,
					 const char *encoding,
					 int format);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		htmlNodeDumpFormatOutput(xmlOutputBufferPtr buf,
					 xmlDocPtr doc,
					 xmlNodePtr cur,
					 const char *encoding,
					 int format);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		htmlDocContentDumpOutput(xmlOutputBufferPtr buf,
					 xmlDocPtr cur,
					 const char *encoding);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		htmlDocContentDumpFormatOutput(xmlOutputBufferPtr buf,
					 xmlDocPtr cur,
					 const char *encoding,
					 int format);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL 
		htmlNodeDumpOutput	(xmlOutputBufferPtr buf, 
					 xmlDocPtr doc,
					 xmlNodePtr cur, 
					 const char *encoding);

#endif /* LIBXML_OUTPUT_ENABLED */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		htmlIsBooleanAttr	(const xmlChar *name);

/**
 * @}
 */
#ifdef __cplusplus
}
#endif

#endif /* __HTML_TREE_H__ */

