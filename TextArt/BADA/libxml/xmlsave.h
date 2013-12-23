/* $Change: 1114438 $ */
/**
 * Summary: the XML document serializer
 * Description: API to save document or subtree of document
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

/**
 * @file		xmlSave.h
 * @brief	This is the header file for libxml
 *
 *
 */
 
#ifndef __XML_XMLSAVE_H__
#define __XML_XMLSAVE_H__

#include <libxml/xmlversion.h>
#include <libxml/tree.h>
#include <libxml/encoding.h>
#include <libxml/xmlIO.h>

#ifdef LIBXML_OUTPUT_ENABLED
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

typedef struct _xmlSaveCtxt xmlSaveCtxt;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlSaveCtxt *xmlSaveCtxtPtr;

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlSaveCtxtPtr XMLCALL
		xmlSaveToFilename	(const char *filename,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlSaveCtxtPtr XMLCALL
		xmlSaveToBuffer		(xmlBufferPtr buffer,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlSaveCtxtPtr XMLCALL
		xmlSaveToIO		(xmlOutputWriteCallback iowrite,
					 xmlOutputCloseCallback ioclose,
					 void *ioctx,
					 const char *encoding,
					 int options);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN long XMLCALL
		xmlSaveDoc		(xmlSaveCtxtPtr ctxt,
					 xmlDocPtr doc);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN long XMLCALL
		xmlSaveTree		(xmlSaveCtxtPtr ctxt,
					 xmlNodePtr node);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL
		xmlSaveFlush		(xmlSaveCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL
		xmlSaveClose		(xmlSaveCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL
		xmlSaveSetEscape	(xmlSaveCtxtPtr ctxt,
					 xmlCharEncodingOutputFunc escape);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL
		xmlSaveSetAttrEscape	(xmlSaveCtxtPtr ctxt,
					 xmlCharEncodingOutputFunc escape);

/**
 * @}
 */
 
#ifdef __cplusplus
}
#endif
#endif /* LIBXML_OUTPUT_ENABLED */
#endif /* __XML_XMLSAVE_H__ */


