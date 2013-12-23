/* $Change: 1114438 $ */
/**
 * Summary: interface for an HTML 4.0 non-verifying parser
 * Description: this module implements an HTML 4.0 non-verifying parser
 *              with API compatible with the XML parser ones. It should
 *              be able to parse "real world" HTML, even if severely
 *              broken from a specification point of view.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

/**
 * @file	HTMLparser.h
 * @brief	This is the header file for libxml
 *
 *
 */

#ifndef __HTML_PARSER_H__
#define __HTML_PARSER_H__
#include <libxml/xmlversion.h>
#include <libxml/parser.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup libxml2
 * 
 * @{
 */

/*
 * Most of the back-end structures from XML and HTML are shared.
 */
 
 /**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef xmlParserCtxt htmlParserCtxt;
/**
 *For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 *@since 2.0
 */
typedef xmlParserCtxtPtr htmlParserCtxtPtr;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef xmlParserNodeInfo htmlParserNodeInfo;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef xmlSAXHandler htmlSAXHandler;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef xmlSAXHandlerPtr htmlSAXHandlerPtr;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef xmlParserInput htmlParserInput;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef xmlParserInputPtr htmlParserInputPtr;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef xmlDocPtr htmlDocPtr;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef xmlNodePtr htmlNodePtr;

/**
 * Internal description of an HTML element, representing HTML 4.01
 * and XHTML 1.0 (which share the same structure).
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef struct _htmlElemDesc htmlElemDesc;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef htmlElemDesc *htmlElemDescPtr;
/**
 * @brief Represents a structure in Libxml2
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
struct _htmlElemDesc {
    const char *name;	/**< The tag name */
    char startTag;      /**< Whether the start tag can be implied */
    char endTag;        /**< Whether the end tag can be implied */
    char saveEndTag;    /**< Whether the end tag should be saved */
    char empty;         /**< Is this an empty element ? */
    char depr;          /**< Is this a deprecated element ? */
    char dtd;           /**< 1: only in Loose DTD, 2: only Frameset one */
    char isinline;      /**< is this a block 0 or inline 1 element */
    const char *desc;   /**< the description */

/* NRK Jan.2003
 * New fields encapsulating HTML structure
 *
 * Bugs:
 *	This is a very limited representation.  It fails to tell us when
 *	an element *requires* sub elements (we only have whether they're
 *	allowed or not), and it doesn't tell us where CDATA and PCDATA
 *	are allowed.  Some element relationships are not fully represented:
 *	these are flagged with the word MODIFIER
 */
    const char** subelts;		/**< allowed sub-elements of this element */
    const char* defaultsubelt;	/**< subelement for suggested auto-repair
					   if necessary or NULL */
    const char** attrs_opt;		/**< Optional Attributes */
    const char** attrs_depr;		/**< Additional deprecated attributes */
    const char** attrs_req;		/**< Required attributes */
};

/**
 * Internal description of an HTML entity.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef struct _htmlEntityDesc htmlEntityDesc;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef htmlEntityDesc *htmlEntityDescPtr;
/**
 * @brief Represents a structure in Libxml2
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
struct _htmlEntityDesc {
    unsigned int value;	/**< the UNICODE value for the character */
    const char *name;	/**< The entity name */
    const char *desc;   /**< the description */
};

/*
 * There is only few public functions.
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN const htmlElemDesc * XMLCALL 	
			htmlTagLookup	(const xmlChar *tag);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN const htmlEntityDesc * XMLCALL 	
			htmlEntityLookup(const xmlChar *name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN const htmlEntityDesc * XMLCALL 	
			htmlEntityValueLookup(unsigned int value);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL			
			htmlIsAutoClosed(htmlDocPtr doc,
					 htmlNodePtr elem);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL			
			htmlAutoCloseTag(htmlDocPtr doc,
					 const xmlChar *name,
					 htmlNodePtr elem);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN const htmlEntityDesc * XMLCALL	
			htmlParseEntityRef(htmlParserCtxtPtr ctxt,
					 const xmlChar **str);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL			
			htmlParseCharRef(htmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN void XMLCALL			
			htmlParseElement(htmlParserCtxtPtr ctxt);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN htmlParserCtxtPtr XMLCALL	
			htmlCreateMemoryParserCtxt(const char *buffer,
						   int size);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL			
			htmlParseDocument(htmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN htmlDocPtr XMLCALL		
			htmlSAXParseDoc	(xmlChar *cur,
					 const char *encoding,
					 htmlSAXHandlerPtr sax,
					 void *userData);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN htmlDocPtr XMLCALL		
			htmlParseDoc	(xmlChar *cur,
					 const char *encoding);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN htmlDocPtr XMLCALL		
			htmlSAXParseFile(const char *filename,
					 const char *encoding,
					 htmlSAXHandlerPtr sax,
					 void *userData);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN htmlDocPtr XMLCALL		
			htmlParseFile	(const char *filename,
					 const char *encoding);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL			
			UTF8ToHtml	(unsigned char *out,
					 int *outlen,
					 const unsigned char *in,
					 int *inlen);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL			
			htmlEncodeEntities(unsigned char *out,
					 int *outlen,
					 const unsigned char *in,
					 int *inlen, int quoteChar);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL			
			htmlIsScriptAttribute(const xmlChar *name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL			
			htmlHandleOmittedElem(int val);

#ifdef LIBXML_PUSH_ENABLED
/**
 * Interfaces for the Push mode.
 *
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN htmlParserCtxtPtr XMLCALL	
			htmlCreatePushParserCtxt(htmlSAXHandlerPtr sax,
						 void *user_data,
						 const char *chunk,
						 int size,
						 const char *filename,
						 xmlCharEncoding enc);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL			
			htmlParseChunk		(htmlParserCtxtPtr ctxt,
						 const char *chunk,
						 int size,
						 int terminate);
#endif /* LIBXML_PUSH_ENABLED */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN void XMLCALL			
			htmlFreeParserCtxt	(htmlParserCtxtPtr ctxt);

/*
 * New set of simpler/more flexible APIs
 */
/**
 * @enum htmlParserOption
 *
 * This is the set of HTML parser options that can be passed down
 * to the htmlReadDoc() and similar calls.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef enum {
    HTML_PARSE_NOERROR	= 1<<5,	/**< suppress error reports */
    HTML_PARSE_NOWARNING= 1<<6,	/**< suppress warning reports */
    HTML_PARSE_PEDANTIC	= 1<<7,	/**< pedantic error reporting */
    HTML_PARSE_NOBLANKS	= 1<<8,	/**< remove blank nodes */
    HTML_PARSE_NONET	= 1<<11 /**< Forbid network access */
} htmlParserOption;

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN void XMLCALL
		htmlCtxtReset		(htmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL
		htmlCtxtUseOptions	(htmlParserCtxtPtr ctxt,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN htmlDocPtr XMLCALL
		htmlReadDoc		(const xmlChar *cur,
					 const char *URL,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN htmlDocPtr XMLCALL
		htmlReadFile		(const char *URL,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN htmlDocPtr XMLCALL
		htmlReadMemory		(const char *buffer,
					 int size,
					 const char *URL,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN htmlDocPtr XMLCALL
		htmlReadIO		(xmlInputReadCallback ioread,
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
XMLPUBFUN htmlDocPtr XMLCALL
		htmlCtxtReadDoc		(xmlParserCtxtPtr ctxt,
					 const xmlChar *cur,
					 const char *URL,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN htmlDocPtr XMLCALL
		htmlCtxtReadFile		(xmlParserCtxtPtr ctxt,
					 const char *filename,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN htmlDocPtr XMLCALL
		htmlCtxtReadMemory		(xmlParserCtxtPtr ctxt,
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
XMLPUBFUN htmlDocPtr XMLCALL
		htmlCtxtReadIO		(xmlParserCtxtPtr ctxt,
					 xmlInputReadCallback ioread,
					 xmlInputCloseCallback ioclose,
					 void *ioctx,
					 const char *URL,
					 const char *encoding,
					 int options);

/** 
 * @enum htmlStatus
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
typedef enum {
  HTML_NA = 0 ,		/**< something we don't check at all */
  HTML_INVALID = 0x1 ,/**< */
  HTML_DEPRECATED = 0x2 ,/**< */
  HTML_VALID = 0x4 ,/**< */
  HTML_REQUIRED = 0xc /**< VALID bit set so ( & HTML_VALID ) is TRUE */
} htmlStatus ;

/* Using htmlElemDesc rather than name here, to emphasize the fact
   that otherwise there's a lookup overhead
*/
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN htmlStatus XMLCALL htmlAttrAllowed(const htmlElemDesc*, const xmlChar*, int) ;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN int XMLCALL htmlElementAllowedHere(const htmlElemDesc*, const xmlChar*) ;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN htmlStatus XMLCALL htmlElementStatusHere(const htmlElemDesc*, const htmlElemDesc*) ;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 2.0
 */
XMLPUBFUN htmlStatus XMLCALL htmlNodeStatus(const htmlNodePtr, int) ;
/*
 * htmlDefaultSubelement
 * \@elt: HTML element
 *
 * Returns the default subelement for this element
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 2.0
 */
#define htmlDefaultSubelement(elt) elt->defaultsubelt
/*
 * htmlElementAllowedHereDesc
 * \@parent: HTML parent element
 * \@elt: HTML element
 *
 * Checks whether an HTML element description may be a
 * direct child of the specified element.
 *
 * Returns 1 if allowed; 0 otherwise.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 2.0
 */
#define htmlElementAllowedHereDesc(parent,elt) \
	htmlElementAllowedHere((parent), (elt)->name)
/*
 * htmlRequiredAttrs
 * \@elt: HTML element
 *
 * Returns the attributes required for the specified element.
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * 
 * @since 2.0
 */
#define htmlRequiredAttrs(elt) (elt)->attrs_req

/**
 * @}
 */
#ifdef __cplusplus
}
#endif

#endif /* __HTML_PARSER_H__ */
