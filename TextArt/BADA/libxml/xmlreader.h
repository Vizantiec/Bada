/* $Change: 1114438 $ */
/**
 * Summary: the XMLReader implementation
 * Description: API of the XML streaming API based on C# interfaces.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

/**
 * @file	xmlreader.h
 * @brief	This is the header file for libxml
 *
 *
 */
 
#ifndef __XML_XMLREADER_H__
#define __XML_XMLREADER_H__

#include <libxml/xmlversion.h>
#include <libxml/tree.h>
#include <libxml/xmlIO.h>
#ifdef LIBXML_SCHEMAS_ENABLED
#include <libxml/relaxng.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup libxml2
 * 
 * @{
 */

/**
 * @enum xmlTextReaderMode
 *
 * Internal state values for the reader.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef enum {
    XML_TEXTREADER_MODE_INITIAL = 0,/**< */
    XML_TEXTREADER_MODE_INTERACTIVE = 1,/**< */
    XML_TEXTREADER_MODE_ERROR = 2,/**< */
    XML_TEXTREADER_MODE_EOF =3,/**< */
    XML_TEXTREADER_MODE_CLOSED = 4,/**< */
    XML_TEXTREADER_MODE_READING = 5 /**< */
} xmlTextReaderMode;

/**
 * @enum xmlParserProperties
 *
 * Some common options to use with xmlTextReaderSetParserProp, but it
 * is better to use xmlParserOption and the xmlReaderNewxxx and 
 * xmlReaderForxxx APIs now.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef enum {
    XML_PARSER_LOADDTD = 1,/**< */
    XML_PARSER_DEFAULTATTRS = 2,/**< */
    XML_PARSER_VALIDATE = 3,/**< */
    XML_PARSER_SUBST_ENTITIES = 4 /**< */
} xmlParserProperties;

/**
 * @enum xmlParserSeverities
 *
 * How severe an error callback is when the per-reader error callback API
 * is used.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>

 * @since 2.0
 */
typedef enum {
    XML_PARSER_SEVERITY_VALIDITY_WARNING = 1, /**< */
    XML_PARSER_SEVERITY_VALIDITY_ERROR = 2,/**< */
    XML_PARSER_SEVERITY_WARNING = 3,/**< */
    XML_PARSER_SEVERITY_ERROR = 4 /**< */
} xmlParserSeverities;

/**
 * @enum xmlReaderTypes
 *
 * Predefined constants for the different types of nodes.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef enum {
    XML_READER_TYPE_NONE = 0,/**< */
    XML_READER_TYPE_ELEMENT = 1,/**< */
    XML_READER_TYPE_ATTRIBUTE = 2,/**< */
    XML_READER_TYPE_TEXT = 3,/**< */
    XML_READER_TYPE_CDATA = 4,/**< */
    XML_READER_TYPE_ENTITY_REFERENCE = 5,/**< */
    XML_READER_TYPE_ENTITY = 6,/**< */
    XML_READER_TYPE_PROCESSING_INSTRUCTION = 7,/**< */
    XML_READER_TYPE_COMMENT = 8,/**< */
    XML_READER_TYPE_DOCUMENT = 9,/**< */
    XML_READER_TYPE_DOCUMENT_TYPE = 10,/**< */
    XML_READER_TYPE_DOCUMENT_FRAGMENT = 11,/**< */
    XML_READER_TYPE_NOTATION = 12,/**< */
    XML_READER_TYPE_WHITESPACE = 13,/**< */
    XML_READER_TYPE_SIGNIFICANT_WHITESPACE = 14,/**< */
    XML_READER_TYPE_END_ELEMENT = 15,/**< */
    XML_READER_TYPE_END_ENTITY = 16,/**< */
    XML_READER_TYPE_XML_DECLARATION = 17 /**< */
} xmlReaderTypes;

/**
 * xmlTextReader:
 *
 * Structure for an xmlReader context.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef struct _xmlTextReader xmlTextReader;

/**
 * xmlTextReaderPtr:
 *
 * Pointer to an xmlReader context.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef xmlTextReader *xmlTextReaderPtr;

/*
 * Constructors & Destructor
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlTextReaderPtr XMLCALL
			xmlNewTextReader	(xmlParserInputBufferPtr input,
	                                         const char *URI);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlTextReaderPtr XMLCALL	
			xmlNewTextReaderFilename(const char *URI);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN void XMLCALL			
			xmlFreeTextReader	(xmlTextReaderPtr reader);

/*
 * Iterators
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
			xmlTextReaderRead	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlChar * XMLCALL	
			xmlTextReaderReadInnerXml	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlChar * XMLCALL	
			xmlTextReaderReadOuterXml	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlChar * XMLCALL	
			xmlTextReaderReadString		(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
			xmlTextReaderReadAttributeValue	(xmlTextReaderPtr reader);

/*
 * Attributes of the node
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
			xmlTextReaderAttributeCount(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
			xmlTextReaderDepth	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
			xmlTextReaderHasAttributes(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
			xmlTextReaderHasValue(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
			xmlTextReaderIsDefault	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
			xmlTextReaderIsEmptyElement(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
			xmlTextReaderNodeType	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
			xmlTextReaderQuoteChar	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
			xmlTextReaderReadState	(xmlTextReaderPtr reader);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN const xmlChar * XMLCALL	
		    xmlTextReaderConstBaseUri	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN const xmlChar * XMLCALL	
		    xmlTextReaderConstLocalName	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN const xmlChar * XMLCALL	
		    xmlTextReaderConstName	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN const xmlChar * XMLCALL	
		    xmlTextReaderConstNamespaceUri(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN const xmlChar * XMLCALL	
		    xmlTextReaderConstPrefix	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN const xmlChar * XMLCALL	
		    xmlTextReaderConstXmlLang	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN const xmlChar * XMLCALL	
		    xmlTextReaderConstString	(xmlTextReaderPtr reader,
		    				 const xmlChar *str);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN const xmlChar * XMLCALL	
		    xmlTextReaderConstValue	(xmlTextReaderPtr reader);

/*
 * use the Const version of the routine for
 * better performance and simpler code
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlChar * XMLCALL	
			xmlTextReaderBaseUri	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlChar * XMLCALL	
			xmlTextReaderLocalName	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlChar * XMLCALL	
			xmlTextReaderName	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlChar * XMLCALL	
			xmlTextReaderNamespaceUri(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlChar * XMLCALL	
			xmlTextReaderPrefix	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlChar * XMLCALL	
			xmlTextReaderXmlLang	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlChar * XMLCALL	
			xmlTextReaderValue	(xmlTextReaderPtr reader);

/*
 * Methods of the XmlTextReader
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
		    xmlTextReaderClose		(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlChar * XMLCALL	
		    xmlTextReaderGetAttributeNo	(xmlTextReaderPtr reader,
						 int no);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlChar * XMLCALL	
		    xmlTextReaderGetAttribute	(xmlTextReaderPtr reader,
						 const xmlChar *name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlChar * XMLCALL	
		    xmlTextReaderGetAttributeNs	(xmlTextReaderPtr reader,
						 const xmlChar *localName,
						 const xmlChar *namespaceURI);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlParserInputBufferPtr XMLCALL 
		    xmlTextReaderGetRemainder	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlChar * XMLCALL	
		    xmlTextReaderLookupNamespace(xmlTextReaderPtr reader,
						 const xmlChar *prefix);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
		    xmlTextReaderMoveToAttributeNo(xmlTextReaderPtr reader,
						 int no);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
		    xmlTextReaderMoveToAttribute(xmlTextReaderPtr reader,
						 const xmlChar *name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
		    xmlTextReaderMoveToAttributeNs(xmlTextReaderPtr reader,
						 const xmlChar *localName,
						 const xmlChar *namespaceURI);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
		    xmlTextReaderMoveToFirstAttribute(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
		    xmlTextReaderMoveToNextAttribute(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
		    xmlTextReaderMoveToElement	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
		    xmlTextReaderNormalization	(xmlTextReaderPtr reader);

/*
 * Extensions
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
		    xmlTextReaderSetParserProp	(xmlTextReaderPtr reader,
						 int prop,
						 int value);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
		    xmlTextReaderGetParserProp	(xmlTextReaderPtr reader,
						 int prop);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlNodePtr XMLCALL	
		    xmlTextReaderCurrentNode	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlNodePtr XMLCALL	
		    xmlTextReaderPreserve	(xmlTextReaderPtr reader);

#ifdef LIBXML_PATTERN_ENABLED
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL	
		    xmlTextReaderPreservePattern(xmlTextReaderPtr reader,
		    				 const xmlChar *pattern,
						 const xmlChar **namespaces);
#endif
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlDocPtr XMLCALL	
		    xmlTextReaderCurrentDoc	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlNodePtr XMLCALL	
		    xmlTextReaderExpand		(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
		    xmlTextReaderNext		(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL
		    xmlTextReaderNextSibling	(xmlTextReaderPtr reader);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL		
		    xmlTextReaderIsValid	(xmlTextReaderPtr reader);
#ifdef LIBXML_SCHEMAS_ENABLED
XMLPUBFUN int XMLCALL		
		    xmlTextReaderRelaxNGValidate(xmlTextReaderPtr reader,
						 const char *rng);
XMLPUBFUN int XMLCALL		
		    xmlTextReaderRelaxNGSetSchema(xmlTextReaderPtr reader,
						 xmlRelaxNGPtr schema);
#endif

/*
 * New more complete APIs for simpler creation and reuse of readers
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlTextReaderPtr XMLCALL
		xmlReaderWalker		(xmlDocPtr doc);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlTextReaderPtr XMLCALL
		xmlReaderForDoc		(const xmlChar * cur,
					 const char *URL,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlTextReaderPtr XMLCALL
		xmlReaderForFile	(const char *filename,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlTextReaderPtr XMLCALL
		xmlReaderForMemory	(const char *buffer,
					 int size,
					 const char *URL,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlTextReaderPtr XMLCALL
		xmlReaderForIO		(xmlInputReadCallback ioread,
					 xmlInputCloseCallback ioclose,
					 void *ioctx,
					 const char *URL,
					 const char *encoding,
					 int options);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL
		xmlReaderNewWalker	(xmlTextReaderPtr reader,
					 xmlDocPtr doc);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL
		xmlReaderNewDoc		(xmlTextReaderPtr reader,
					 const xmlChar * cur,
					 const char *URL,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL
		xmlReaderNewFile	(xmlTextReaderPtr reader,
					 const char *filename,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL
		xmlReaderNewMemory	(xmlTextReaderPtr reader,
					 const char *buffer,
					 int size,
					 const char *URL,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL
		xmlReaderNewFd		(xmlTextReaderPtr reader,
					 int fd,
					 const char *URL,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL
		xmlReaderNewIO		(xmlTextReaderPtr reader,
					 xmlInputReadCallback ioread,
					 xmlInputCloseCallback ioclose,
					 void *ioctx,
					 const char *URL,
					 const char *encoding,
					 int options);
/*
 * Error handling extensions
 */
 /**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef void *  xmlTextReaderLocatorPtr;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef void (XMLCALL *xmlTextReaderErrorFunc)(void *arg,
													 const char *msg,
													 xmlParserSeverities severity,
													 xmlTextReaderLocatorPtr locator);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL             
		    xmlTextReaderLocatorLineNumber(xmlTextReaderLocatorPtr locator);
/*int             xmlTextReaderLocatorLinePosition(xmlTextReaderLocatorPtr locator);*/
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN xmlChar * XMLCALL       
		    xmlTextReaderLocatorBaseURI (xmlTextReaderLocatorPtr locator);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN void XMLCALL            
		    xmlTextReaderSetErrorHandler(xmlTextReaderPtr reader, 
						 xmlTextReaderErrorFunc f, 
						 void *arg);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN void XMLCALL
		    xmlTextReaderSetStructuredErrorHandler(xmlTextReaderPtr reader,
							   xmlStructuredErrorFunc f,
							   void *arg);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN void XMLCALL            
		    xmlTextReaderGetErrorHandler(xmlTextReaderPtr reader, 
						 xmlTextReaderErrorFunc *f, 
						 void **arg);
/**
 * @}
 */
#ifdef __cplusplus
}
#endif
#endif /* __XML_XMLREADER_H__ */

