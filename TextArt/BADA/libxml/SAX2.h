/* $Change: 1114438 $ */
/**
 * Summary: SAX2 parser interface used to build the DOM tree
 * Description: those are the default SAX2 interfaces used by
 *              the library when building DOM tree.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

/**
 * @file		SAX2.h
 * @brief	This is the header file for libxml
 *
 *
 */
 
#ifndef __XML_SAX2_H__
#define __XML_SAX2_H__

#ifndef SHP
#include <stdio.h>
#endif

//#include <stdlib.h> //header collision  20091216
#include <libxml/xmlversion.h>
#include <libxml/parser.h>
#include <libxml/xlink.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup libxml2
 * 
 * @{
 */
 
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN const xmlChar * XMLCALL
		xmlSAX2GetPublicId		(void *ctx);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN const xmlChar * XMLCALL	
		xmlSAX2GetSystemId		(void *ctx);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
 
XMLPUBFUN void XMLCALL		
		xmlSAX2SetDocumentLocator	(void *ctx,
						 xmlSAXLocatorPtr loc);
    
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlSAX2GetLineNumber		(void *ctx);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlSAX2GetColumnNumber		(void *ctx);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlSAX2IsStandalone		(void *ctx);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlSAX2HasInternalSubset	(void *ctx);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlSAX2HasExternalSubset	(void *ctx);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2InternalSubset		(void *ctx,
						 const xmlChar *name,
						 const xmlChar *ExternalID,
						 const xmlChar *SystemID);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2ExternalSubset		(void *ctx,
						 const xmlChar *name,
						 const xmlChar *ExternalID,
						 const xmlChar *SystemID);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlEntityPtr XMLCALL	
		xmlSAX2GetEntity		(void *ctx,
						 const xmlChar *name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlEntityPtr XMLCALL	
		xmlSAX2GetParameterEntity	(void *ctx,
						 const xmlChar *name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlParserInputPtr XMLCALL 
		xmlSAX2ResolveEntity		(void *ctx,
						 const xmlChar *publicId,
						 const xmlChar *systemId);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2EntityDecl		(void *ctx,
						 const xmlChar *name,
						 int type,
						 const xmlChar *publicId,
						 const xmlChar *systemId,
						 xmlChar *content);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2AttributeDecl		(void *ctx,
						 const xmlChar *elem,
						 const xmlChar *fullname,
						 int type,
						 int def,
						 const xmlChar *defaultValue,
						 xmlEnumerationPtr tree);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2ElementDecl		(void *ctx,
						 const xmlChar *name,
						 int type,
						 xmlElementContentPtr content);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2NotationDecl		(void *ctx,
						 const xmlChar *name,
						 const xmlChar *publicId,
						 const xmlChar *systemId);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2UnparsedEntityDecl	(void *ctx,
						 const xmlChar *name,
						 const xmlChar *publicId,
						 const xmlChar *systemId,
						 const xmlChar *notationName);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2StartDocument		(void *ctx);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2EndDocument		(void *ctx);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2StartElement		(void *ctx,
						 const xmlChar *fullname,
						 const xmlChar **atts);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2EndElement		(void *ctx,
						 const xmlChar *name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL
		xmlSAX2StartElementNs		(void *ctx,
						 const xmlChar *localname,
						 const xmlChar *prefix,
						 const xmlChar *URI,
						 int nb_namespaces,
						 const xmlChar **namespaces,
						 int nb_attributes,
						 int nb_defaulted,
						 const xmlChar **attributes);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL
		xmlSAX2EndElementNs		(void *ctx,
						 const xmlChar *localname,
						 const xmlChar *prefix,
						 const xmlChar *URI);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2Reference		(void *ctx,
						 const xmlChar *name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2Characters		(void *ctx,
						 const xmlChar *ch,
						 int len);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2IgnorableWhitespace	(void *ctx,
						 const xmlChar *ch,
						 int len);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2ProcessingInstruction	(void *ctx,
						 const xmlChar *target,
						 const xmlChar *data);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2Comment			(void *ctx,
						 const xmlChar *value);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2CDataBlock		(void *ctx,
						 const xmlChar *value,
						 int len);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL
		xmlSAXDefaultVersion		(int version);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL
		xmlSAXVersion			(xmlSAXHandler *hdlr,
						 int version);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2InitDefaultSAXHandler    (xmlSAXHandler *hdlr,
						 int warning);
#ifdef LIBXML_HTML_ENABLED
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL	
		xmlSAX2InitHtmlDefaultSAXHandler(xmlSAXHandler *hdlr);
#endif
#ifdef LIBXML_DOCB_ENABLED
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSAX2InitDocbDefaultSAXHandler(xmlSAXHandler *hdlr);
#endif
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlDefaultSAXHandlerInit	(void);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		htmlDefaultSAXHandlerInit	(void);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		docbDefaultSAXHandlerInit	(void);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif
#endif /* __XML_SAX2_H__ */
