/* $Change: 1114438 $ */
/**
 * Summary: text writing API for XML
 * Description: text writing API for XML
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Alfred Mickautsch <alfred@mickautsch.de>
 */

 /**
 * @file		xmlwriter.h
 * @brief	This is the header file for libxml
 *
 *
 */

#ifndef __XML_XMLWRITER_H__
#define __XML_XMLWRITER_H__

//#include <stdarg.h>
#include <libxml/xmlIO.h>
#include <libxml/list.h>
#include <libxml/xmlstring.h>

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
    typedef struct _xmlTextWriter xmlTextWriter;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    typedef xmlTextWriter *xmlTextWriterPtr;

/*
 * Constructors & Destructor
 */
 
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */ 
    XMLPUBFUN xmlTextWriterPtr XMLCALL
        xmlNewTextWriter(xmlOutputBufferPtr out);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN xmlTextWriterPtr XMLCALL
        xmlNewTextWriterFilename(const char *uri, int compression);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN xmlTextWriterPtr XMLCALL
        xmlNewTextWriterMemory(xmlBufferPtr buf, int compression);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN xmlTextWriterPtr XMLCALL
        xmlNewTextWriterPushParser(xmlParserCtxtPtr ctxt, int compression);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN xmlTextWriterPtr XMLCALL
        xmlNewTextWriterDoc(xmlDocPtr * doc, int compression);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN xmlTextWriterPtr XMLCALL
        xmlNewTextWriterTree(xmlDocPtr doc, xmlNodePtr node,
                             int compression);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN void XMLCALL xmlFreeTextWriter(xmlTextWriterPtr writer);

/*
 * Functions
 */


/*
 * Document
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterStartDocument(xmlTextWriterPtr writer,
                                   const char *version,
                                   const char *encoding,
                                   const char *standalone);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterEndDocument(xmlTextWriterPtr
                                                   writer);

/*
 * Comments
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterStartComment(xmlTextWriterPtr
                                                    writer);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterEndComment(xmlTextWriterPtr writer);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteFormatComment(xmlTextWriterPtr writer,
                                        const char *format, ...);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteVFormatComment(xmlTextWriterPtr writer,
                                         const char *format,
                                         va_list argptr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterWriteComment(xmlTextWriterPtr
                                                    writer,
                                                    const xmlChar *
                                                    content);

/*
 * Elements
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterStartElement(xmlTextWriterPtr writer,
                                  const xmlChar * name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterStartElementNS(xmlTextWriterPtr
                                                      writer,
                                                      const xmlChar *
                                                      prefix,
                                                      const xmlChar * name,
                                                      const xmlChar *
                                                      namespaceURI);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterEndElement(xmlTextWriterPtr writer);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterFullEndElement(xmlTextWriterPtr
                                                      writer);

/*
 * Elements conveniency functions
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteFormatElement(xmlTextWriterPtr writer,
                                        const xmlChar * name,
                                        const char *format, ...);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteVFormatElement(xmlTextWriterPtr writer,
                                         const xmlChar * name,
                                         const char *format,
                                         va_list argptr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterWriteElement(xmlTextWriterPtr
                                                    writer,
                                                    const xmlChar * name,
                                                    const xmlChar *
                                                    content);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteFormatElementNS(xmlTextWriterPtr writer,
                                          const xmlChar * prefix,
                                          const xmlChar * name,
                                          const xmlChar * namespaceURI,
                                          const char *format, ...);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteVFormatElementNS(xmlTextWriterPtr writer,
                                           const xmlChar * prefix,
                                           const xmlChar * name,
                                           const xmlChar * namespaceURI,
                                           const char *format,
                                           va_list argptr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterWriteElementNS(xmlTextWriterPtr
                                                      writer,
                                                      const xmlChar *
                                                      prefix,
                                                      const xmlChar * name,
                                                      const xmlChar *
                                                      namespaceURI,
                                                      const xmlChar *
                                                      content);

/*
 * Text
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteFormatRaw(xmlTextWriterPtr writer,
                                    const char *format, ...);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteVFormatRaw(xmlTextWriterPtr writer,
                                     const char *format, va_list argptr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteRawLen(xmlTextWriterPtr writer,
                                 const xmlChar * content, int len);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteRaw(xmlTextWriterPtr writer,
                              const xmlChar * content);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterWriteFormatString(xmlTextWriterPtr
                                                         writer,
                                                         const char
                                                         *format, ...);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterWriteVFormatString(xmlTextWriterPtr
                                                          writer,
                                                          const char
                                                          *format,
                                                          va_list argptr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterWriteString(xmlTextWriterPtr writer,
                                                   const xmlChar *
                                                   content);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterWriteBase64(xmlTextWriterPtr writer,
                                                   const char *data,
                                                   int start, int len);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterWriteBinHex(xmlTextWriterPtr writer,
                                                   const char *data,
                                                   int start, int len);

/*
 * Attributes
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterStartAttribute(xmlTextWriterPtr writer,
                                    const xmlChar * name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterStartAttributeNS(xmlTextWriterPtr
                                                        writer,
                                                        const xmlChar *
                                                        prefix,
                                                        const xmlChar *
                                                        name,
                                                        const xmlChar *
                                                        namespaceURI);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterEndAttribute(xmlTextWriterPtr
                                                    writer);

/*
 * Attributes conveniency functions
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteFormatAttribute(xmlTextWriterPtr writer,
                                          const xmlChar * name,
                                          const char *format, ...);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteVFormatAttribute(xmlTextWriterPtr writer,
                                           const xmlChar * name,
                                           const char *format,
                                           va_list argptr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterWriteAttribute(xmlTextWriterPtr
                                                      writer,
                                                      const xmlChar * name,
                                                      const xmlChar *
                                                      content);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteFormatAttributeNS(xmlTextWriterPtr writer,
                                            const xmlChar * prefix,
                                            const xmlChar * name,
                                            const xmlChar * namespaceURI,
                                            const char *format, ...);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0*/
 
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteVFormatAttributeNS(xmlTextWriterPtr writer,
                                             const xmlChar * prefix,
                                             const xmlChar * name,
                                             const xmlChar * namespaceURI,
                                             const char *format,
                                             va_list argptr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterWriteAttributeNS(xmlTextWriterPtr
                                                        writer,
                                                        const xmlChar *
                                                        prefix,
                                                        const xmlChar *
                                                        name,
                                                        const xmlChar *
                                                        namespaceURI,
                                                        const xmlChar *
                                                        content);

/*
 * PI's
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterStartPI(xmlTextWriterPtr writer,
                             const xmlChar * target);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterEndPI(xmlTextWriterPtr writer);

/*
 * PI conveniency functions
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteFormatPI(xmlTextWriterPtr writer,
                                   const xmlChar * target,
                                   const char *format, ...);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteVFormatPI(xmlTextWriterPtr writer,
                                    const xmlChar * target,
                                    const char *format, va_list argptr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWritePI(xmlTextWriterPtr writer,
                             const xmlChar * target,
                             const xmlChar * content);

/*
 * xmlTextWriterWriteProcessingInstruction:
 *
 * This macro maps to xmlTextWriterWritePI
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define xmlTextWriterWriteProcessingInstruction xmlTextWriterWritePI

/*
 * CDATA
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterStartCDATA(xmlTextWriterPtr writer);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterEndCDATA(xmlTextWriterPtr writer);

/*
 * CDATA conveniency functions
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteFormatCDATA(xmlTextWriterPtr writer,
                                      const char *format, ...);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteVFormatCDATA(xmlTextWriterPtr writer,
                                       const char *format, va_list argptr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteCDATA(xmlTextWriterPtr writer,
                                const xmlChar * content);

/*
 * DTD
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterStartDTD(xmlTextWriterPtr writer,
                              const xmlChar * name,
                              const xmlChar * pubid,
                              const xmlChar * sysid);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterEndDTD(xmlTextWriterPtr writer);

/*
 * DTD conveniency functions
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteFormatDTD(xmlTextWriterPtr writer,
                                    const xmlChar * name,
                                    const xmlChar * pubid,
                                    const xmlChar * sysid,
                                    const char *format, ...);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteVFormatDTD(xmlTextWriterPtr writer,
                                     const xmlChar * name,
                                     const xmlChar * pubid,
                                     const xmlChar * sysid,
                                     const char *format, va_list argptr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteDTD(xmlTextWriterPtr writer,
                              const xmlChar * name,
                              const xmlChar * pubid,
                              const xmlChar * sysid,
                              const xmlChar * subset);

/*
 * xmlTextWriterWriteDocType:
 *
 * this macro maps to xmlTextWriterWriteDTD
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define xmlTextWriterWriteDocType xmlTextWriterWriteDTD

/*
 * DTD element definition
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterStartDTDElement(xmlTextWriterPtr writer,
                                     const xmlChar * name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterEndDTDElement(xmlTextWriterPtr
                                                     writer);

/*
 * DTD element definition conveniency functions
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteFormatDTDElement(xmlTextWriterPtr writer,
                                           const xmlChar * name,
                                           const char *format, ...);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteVFormatDTDElement(xmlTextWriterPtr writer,
                                            const xmlChar * name,
                                            const char *format,
                                            va_list argptr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterWriteDTDElement(xmlTextWriterPtr
                                                       writer,
                                                       const xmlChar *
                                                       name,
                                                       const xmlChar *
                                                       content);

/*
 * DTD attribute list definition
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterStartDTDAttlist(xmlTextWriterPtr writer,
                                     const xmlChar * name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
 XMLPUBFUN int XMLCALL xmlTextWriterEndDTDAttlist(xmlTextWriterPtr
                                                     writer);

/*
 * DTD attribute list definition conveniency functions
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteFormatDTDAttlist(xmlTextWriterPtr writer,
                                           const xmlChar * name,
                                           const char *format, ...);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteVFormatDTDAttlist(xmlTextWriterPtr writer,
                                            const xmlChar * name,
                                            const char *format,
                                            va_list argptr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterWriteDTDAttlist(xmlTextWriterPtr
                                                       writer,
                                                       const xmlChar *
                                                       name,
                                                       const xmlChar *
                                                       content);

/*
 * DTD entity definition
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterStartDTDEntity(xmlTextWriterPtr writer,
                                    int pe, const xmlChar * name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterEndDTDEntity(xmlTextWriterPtr
                                                    writer);

/*
 * DTD entity definition conveniency functions
 */
 
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteFormatDTDInternalEntity(xmlTextWriterPtr writer,
                                                  int pe,
                                                  const xmlChar * name,
                                                  const char *format, ...);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteVFormatDTDInternalEntity(xmlTextWriterPtr writer,
                                                   int pe,
                                                   const xmlChar * name,
                                                   const char *format,
                                                   va_list argptr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteDTDInternalEntity(xmlTextWriterPtr writer,
                                            int pe,
                                            const xmlChar * name,
                                            const xmlChar * content);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteDTDExternalEntity(xmlTextWriterPtr writer,
                                            int pe,
                                            const xmlChar * name,
                                            const xmlChar * pubid,
                                            const xmlChar * sysid,
                                            const xmlChar * ndataid);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteDTDExternalEntityContents(xmlTextWriterPtr
                                                    writer,
                                                    const xmlChar * pubid,
                                                    const xmlChar * sysid,
                                                    const xmlChar *
                                                    ndataid);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterWriteDTDEntity(xmlTextWriterPtr
                                                      writer, int pe,
                                                      const xmlChar * name,
                                                      const xmlChar *
                                                      pubid,
                                                      const xmlChar *
                                                      sysid,
                                                      const xmlChar *
                                                      ndataid,
                                                      const xmlChar *
                                                      content);

/*
 * DTD notation definition
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterWriteDTDNotation(xmlTextWriterPtr writer,
                                      const xmlChar * name,
                                      const xmlChar * pubid,
                                      const xmlChar * sysid);

/*
 * Indentation
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterSetIndent(xmlTextWriterPtr writer, int indent);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL
        xmlTextWriterSetIndentString(xmlTextWriterPtr writer,
                                     const xmlChar * str);

/*
 * misc
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
    XMLPUBFUN int XMLCALL xmlTextWriterFlush(xmlTextWriterPtr writer);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif
#endif                          /* __XML_XMLWRITER_H__ */
