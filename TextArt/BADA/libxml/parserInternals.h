/* $Change: 1114438 $ */
/**
 * Summary: internals routines exported by the parser.
 * Description: this module exports a number of internal parsing routines
 *              they are not really all intended for applications but
 *              can prove useful doing low level processing.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

/**
 * @file		parserInternals.h
 * @brief	This is the header file for libxml
 *
 *
 */
 
#ifndef __XML_PARSER_INTERNALS_H__
#define __XML_PARSER_INTERNALS_H__

#include <libxml/xmlversion.h>
#include <libxml/parser.h>
#include <libxml/HTMLparser.h>
#include <libxml/chvalid.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup libxml2
 * 
 * @{
 */
 
/*
 * xmlParserMaxDepth:
 *
 * arbitrary depth limit for the XML documents that we allow to 
 * process. This is not a limitation of the parser but a safety 
 * boundary feature.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBVAR unsigned int xmlParserMaxDepth;

 /*
  * XML_MAX_NAMELEN:
  *
  * Identifiers can be longer, but this will be more costly
  * at runtime.
  *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define XML_MAX_NAMELEN 100

/*
 * INPUT_CHUNK:
 *
 * The parser tries to always have that amount of input ready.
 * One of the point is providing context when reporting errors.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define INPUT_CHUNK	250

/************************************************************************
 *									*
 * UNICODE version of the macros.      					*
 *									*
 ************************************************************************/
/*
 * IS_BYTE_CHAR:
 *
 * \@c:  an byte value (int)
 *
 * Macro to check the following production in the XML spec:
 *
 * [2] Char ::= #x9 | #xA | #xD | [#x20...]
 * any byte character in the accepted range
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_BYTE_CHAR(c)	 xmlIsChar_ch(c)

/*
 * IS_CHAR:
 *
 * \@c:  an UNICODE value (int)
 *
 * Macro to check the following production in the XML spec:
 *
 * [2] Char ::= #x9 | #xA | #xD | [#x20-#xD7FF] | [#xE000-#xFFFD]
 *                  | [#x10000-#x10FFFF]
 * any Unicode character, excluding the surrogate blocks, FFFE, and FFFF.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_CHAR(c)   xmlIsCharQ(c)

/*
 * IS_CHAR_CH:
 *
 * \@c: an xmlChar (usually an unsigned char)
 *
 * Behaves like IS_CHAR on single-byte value
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_CHAR_CH(c)  xmlIsChar_ch(c)

/*
 * IS_BLANK:
 *
 * \@c:  an UNICODE value (int)
 *
 * Macro to check the following production in the XML spec:
 *
 * [3] S ::= (#x20 | #x9 | #xD | #xA)+
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_BLANK(c)  xmlIsBlankQ(c)

/*
 * IS_BLANK_CH:
 *
 * \@c:  an xmlChar value (normally unsigned char)
 *
 * Behavior same as IS_BLANK
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_BLANK_CH(c)  xmlIsBlank_ch(c)

/*
 * IS_BASECHAR:
 *
 * \@c:  an UNICODE value (int)
 *
 * Macro to check the following production in the XML spec:
 *
 * [85] BaseChar ::= ... long list see REC ...
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_BASECHAR(c) xmlIsBaseCharQ(c)

/*
 * IS_DIGIT:
 *
 * \@c:  an UNICODE value (int)
 *
 * Macro to check the following production in the XML spec:
 *
 * [88] Digit ::= ... long list see REC ...
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_DIGIT(c) xmlIsDigitQ(c)

/*
 * IS_DIGIT_CH:
 *
 * \@c:  an xmlChar value (usually an unsigned char)
 *
 * Behaves like IS_DIGIT but with a single byte argument
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_DIGIT_CH(c)  xmlIsDigit_ch(c)

/*
 * IS_COMBINING:
 *
 * \@c:  an UNICODE value (int)
 *
 * Macro to check the following production in the XML spec:
 *
 * [87] CombiningChar ::= ... long list see REC ...
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_COMBINING(c) xmlIsCombiningQ(c)

/*
 * IS_COMBINING_CH:
 *
 * \@c:  an xmlChar (usually an unsigned char)
 *
 * Always false (all combining chars > 0xff)
*
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_COMBINING_CH(c) 0 

/*
 * IS_EXTENDER:
 *
 * \@c:  an UNICODE value (int)
 *
 * Macro to check the following production in the XML spec:
 *
 *
 * [89] Extender ::= #x00B7 | #x02D0 | #x02D1 | #x0387 | #x0640 |
 *                   #x0E46 | #x0EC6 | #x3005 | [#x3031-#x3035] |
 *                   [#x309D-#x309E] | [#x30FC-#x30FE]
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_EXTENDER(c) xmlIsExtenderQ(c)

/*
 * IS_EXTENDER_CH:
 *
 * \@c:  an xmlChar value (usually an unsigned char)
 *
 * Behaves like IS_EXTENDER but with a single-byte argument
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_EXTENDER_CH(c)  xmlIsExtender_ch(c)

/*
 * IS_IDEOGRAPHIC:
 *
 * \@c:  an UNICODE value (int)
 *
 * Macro to check the following production in the XML spec:
 *
 *
 * [86] Ideographic ::= [#x4E00-#x9FA5] | #x3007 | [#x3021-#x3029]
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_IDEOGRAPHIC(c) xmlIsIdeographicQ(c)

/*
 * IS_LETTER:
 *
 * \@c:  an UNICODE value (int)
 *
 * Macro to check the following production in the XML spec:
 *
 *
 * [84] Letter ::= BaseChar | Ideographic 
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_LETTER(c) (IS_BASECHAR(c) || IS_IDEOGRAPHIC(c))

/*
 * IS_LETTER_CH:
 *
 * \@c:  an xmlChar value (normally unsigned char)
 *
 * Macro behaves like IS_LETTER, but only check base chars
 *
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_LETTER_CH(c) xmlIsBaseChar_ch(c)
/*
 * IS_PUBIDCHAR:
 *
 * \@c:  an UNICODE value (int)
 *
 * Macro to check the following production in the XML spec:
 *
 *
 * [13] PubidChar ::= #x20 | #xD | #xA | [a-zA-Z0-9] | [-'()+,./:=?;!*#@$_%]
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_PUBIDCHAR(c)	xmlIsPubidCharQ(c)

/*
 * IS_PUBIDCHAR_CH:
 *
 * \@c:  an xmlChar value (normally unsigned char)
 *
 * Same as IS_PUBIDCHAR but for single-byte value
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define IS_PUBIDCHAR_CH(c) xmlIsPubidChar_ch(c)

/*
 * SKIP_EOL:
 *
 * \@p:  and UTF8 string pointer
 *
 * Skips the end of line chars.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define SKIP_EOL(p) 							\
    if (*(p) == 0x13) { p++ ; if (*(p) == 0x10) p++; }			\
    if (*(p) == 0x10) { p++ ; if (*(p) == 0x13) p++; }

/*
 * MOVETO_ENDTAG:
 *
 * \@p:  and UTF8 string pointer
 *
 * Skips to the next '>' char.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define MOVETO_ENDTAG(p)						\
    while ((*p) && (*(p) != '>')) (p)++

/*
 * MOVETO_STARTTAG:
 *
 * \@p:  and UTF8 string pointer
 *
 * Skips to the next '<' char.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
#define MOVETO_STARTTAG(p)						\
    while ((*p) && (*(p) != '<')) (p)++

/*
 * Global variables used for predefined strings.
 */
 /*
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBVAR const xmlChar xmlStringText[];
/*
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBVAR const xmlChar xmlStringTextNoenc[];
/*
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBVAR const xmlChar xmlStringComment[];

/*
 * Function to finish the work of the macros where needed.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL                   xmlIsLetter     (int c);

/*  Parser context. */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */ 
XMLPUBFUN xmlParserCtxtPtr XMLCALL	
			xmlCreateFileParserCtxt	(const char *filename);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlParserCtxtPtr XMLCALL	
			xmlCreateURLParserCtxt	(const char *filename,
						 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlParserCtxtPtr XMLCALL	
			xmlCreateMemoryParserCtxt(const char *buffer,
						 int size);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlParserCtxtPtr XMLCALL	
			xmlCreateEntityParserCtxt(const xmlChar *URL,
						 const xmlChar *ID,
						 const xmlChar *base);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			
			xmlSwitchEncoding	(xmlParserCtxtPtr ctxt,
						 xmlCharEncoding enc);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			
			xmlSwitchToEncoding	(xmlParserCtxtPtr ctxt,
					 xmlCharEncodingHandlerPtr handler);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			
			xmlSwitchInputEncoding	(xmlParserCtxtPtr ctxt,
						 xmlParserInputPtr input,
					 xmlCharEncodingHandlerPtr handler);

#ifdef IN_LIBXML
/* internal error reporting */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL
			__xmlErrEncoding	(xmlParserCtxtPtr ctxt,
						 xmlParserErrors error,
						 const char *msg,
						 const xmlChar * str1,
						 const xmlChar * str2);
#endif

/* Entities  */

#ifdef LIBXML_LEGACY_ENABLED
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlHandleEntity		(xmlParserCtxtPtr ctxt,
						 xmlEntityPtr entity);
#endif /* LIBXML_LEGACY_ENABLED */
/* Input Streams. */
 
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlParserInputPtr XMLCALL	
			xmlNewStringInputStream	(xmlParserCtxtPtr ctxt,
						 const xmlChar *buffer);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlParserInputPtr XMLCALL	
			xmlNewEntityInputStream	(xmlParserCtxtPtr ctxt,
						 xmlEntityPtr entity);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlPushInput		(xmlParserCtxtPtr ctxt,
						 xmlParserInputPtr input);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar XMLCALL			
			xmlPopInput		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlFreeInputStream	(xmlParserInputPtr input);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlParserInputPtr XMLCALL	
			xmlNewInputFromFile	(xmlParserCtxtPtr ctxt,
						 const char *filename);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlParserInputPtr XMLCALL	
			xmlNewInputStream	(xmlParserCtxtPtr ctxt);

/* Namespaces. */
 
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlSplitQName		(xmlParserCtxtPtr ctxt,
						 const xmlChar *name,
						 xmlChar **prefix);

#ifdef LIBXML_LEGACY_ENABLED
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlNamespaceParseNCName	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlNamespaceParseQName	(xmlParserCtxtPtr ctxt,
						 xmlChar **prefix);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlNamespaceParseNSDef	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlParseQuotedString	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParseNamespace	(xmlParserCtxtPtr ctxt);

/* Generic production rules. */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlScanName		(xmlParserCtxtPtr ctxt);
#endif /* LIBXML_LEGACY_ENABLED */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN const xmlChar * XMLCALL		
			xmlParseName		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlParseNmtoken		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlParseEntityValue	(xmlParserCtxtPtr ctxt,
						 xmlChar **orig);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlParseAttValue	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlParseSystemLiteral	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlParsePubidLiteral	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0*/
 
XMLPUBFUN void XMLCALL			
			xmlParseCharData	(xmlParserCtxtPtr ctxt,
						 int cdata);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlParseExternalID	(xmlParserCtxtPtr ctxt,
						 xmlChar **publicID,
						 int strict);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParseComment		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN const xmlChar * XMLCALL		
			xmlParsePITarget	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParsePI		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParseNotationDecl	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParseEntityDecl	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			
			xmlParseDefaultDecl	(xmlParserCtxtPtr ctxt,
						 xmlChar **value);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlEnumerationPtr XMLCALL	
			xmlParseNotationType	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0*/
 
XMLPUBFUN xmlEnumerationPtr XMLCALL	
			xmlParseEnumerationType	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			
			xmlParseEnumeratedType	(xmlParserCtxtPtr ctxt,
						 xmlEnumerationPtr *tree);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			
			xmlParseAttributeType	(xmlParserCtxtPtr ctxt,
						 xmlEnumerationPtr *tree);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParseAttributeListDecl(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlElementContentPtr XMLCALL	
			xmlParseElementMixedContentDecl
						(xmlParserCtxtPtr ctxt,
						 int inputchk);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlElementContentPtr XMLCALL	
			xmlParseElementChildrenContentDecl
						(xmlParserCtxtPtr ctxt,
						 int inputchk);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			
			xmlParseElementContentDecl(xmlParserCtxtPtr ctxt,
						 const xmlChar *name,
						 xmlElementContentPtr *result);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			
			xmlParseElementDecl	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParseMarkupDecl	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			
			xmlParseCharRef		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlEntityPtr XMLCALL		
			xmlParseEntityRef	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParseReference	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParsePEReference	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParseDocTypeDecl	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN const xmlChar * XMLCALL		
			xmlParseAttribute	(xmlParserCtxtPtr ctxt,
						 xmlChar **value);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN const xmlChar * XMLCALL		
			xmlParseStartTag	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParseEndTag		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParseCDSect		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParseContent		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParseElement		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlParseVersionNum	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlParseVersionInfo	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlParseEncName		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN const xmlChar * XMLCALL		
			xmlParseEncodingDecl	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			
			xmlParseSDDecl		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParseXMLDecl		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParseTextDecl	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParseMisc		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlParseExternalSubset	(xmlParserCtxtPtr ctxt,
						 const xmlChar *ExternalID,
						 const xmlChar *SystemID); 
/*
 * XML_SUBSTITUTE_NONE:
 *
 * If no entities need to be substituted.
 */
#define XML_SUBSTITUTE_NONE	0
/*
 * XML_SUBSTITUTE_REF:
 *
 * Whether general entities need to be substituted.
 */
#define XML_SUBSTITUTE_REF	1
/*
 * XML_SUBSTITUTE_PEREF:
 *
 * Whether parameter entities need to be substituted.
 */
#define XML_SUBSTITUTE_PEREF	2
/*
 * XML_SUBSTITUTE_BOTH:
 *
 * Both general and parameter entities need to be substituted.
 */
#define XML_SUBSTITUTE_BOTH 	3

#ifdef LIBXML_PUSH_ENABLED
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL
		xmlDecodeEntities		(xmlParserCtxtPtr ctxt,
						 int len,
						 int what,
						 xmlChar end,
						 xmlChar  end2,
						 xmlChar end3);
#endif /* LIBXML_LEGACY_ENABLED */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL
		xmlStringDecodeEntities		(xmlParserCtxtPtr ctxt,
						 const xmlChar *str,
						 int what,
						 xmlChar end,
						 xmlChar  end2,
						 xmlChar end3);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL
		xmlStringLenDecodeEntities	(xmlParserCtxtPtr ctxt,
						 const xmlChar *str,
						 int len,
						 int what,
						 xmlChar end,
						 xmlChar  end2,
						 xmlChar end3);

/*
 * Generated by MACROS on top of parser.c c.f. PUSH_AND_POP.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			nodePush		(xmlParserCtxtPtr ctxt,
						 xmlNodePtr value);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodePtr XMLCALL		nodePop			(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0*/
 
XMLPUBFUN int XMLCALL			inputPush		(xmlParserCtxtPtr ctxt,
						 xmlParserInputPtr value);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlParserInputPtr XMLCALL	inputPop		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN const xmlChar * XMLCALL	namePop			(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			namePush		(xmlParserCtxtPtr ctxt,
						 const xmlChar *value);

/*
 * other commodities shared between parser.c and parserInternals.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			xmlSkipBlankChars	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			xmlStringCurrentChar	(xmlParserCtxtPtr ctxt,
						 const xmlChar *cur,
						 int *len);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			xmlParserHandlePEReference(xmlParserCtxtPtr ctxt);

#ifdef LIBXML_LEGACY_ENABLED
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			xmlParserHandleReference(xmlParserCtxtPtr ctxt);
#endif /* LIBXML_LEGACY_ENABLED */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			xmlCheckLanguageID	(const xmlChar *lang);

/*
 * Really core function shared with HTML parser.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			xmlCurrentChar		(xmlParserCtxtPtr ctxt,
						 int *len);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		xmlCopyCharMultiByte	(xmlChar *out,
						 int val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL			xmlCopyChar		(int len,
						 xmlChar *out,
						 int val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			xmlNextChar		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			xmlParserInputShrink	(xmlParserInputPtr in);

#ifdef LIBXML_HTML_ENABLED
/*
 * Actually comes from the HTML parser but launched from the init stuff.
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			htmlInitAutoClose	(void);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN htmlParserCtxtPtr XMLCALL	htmlCreateFileParserCtxt(const char *filename,
	                                         const char *encoding);
#endif

/*
 * Specific function to keep track of entities references
 * and used by the XSLT debugger.
 */
/**
 * xmlEntityReferenceFunc:
 * @param[in]	ent			the entity
 * @param[in]	firstNode	the fist node in the chunk
 * @param[in]	lastNode	the last nod in the chunk
 *
 * Callback function used when one needs to be able to track back the
 * provenance of a chunk of nodes inherited from an entity replacement.
 * 
 *For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 *@since 1.0
 */
typedef	void	(*xmlEntityReferenceFunc)	(xmlEntityPtr ent,
						 xmlNodePtr firstNode,
						 xmlNodePtr lastNode);
  
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		xmlSetEntityReferenceFunc	(xmlEntityReferenceFunc func);

#ifdef IN_LIBXML
/*
 * internal only
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL
	xmlErrMemory		(xmlParserCtxtPtr ctxt,
				 const char *extra);
#endif

/**
 * @}
 */

#ifdef __cplusplus
}
#endif
#endif /* __XML_PARSER_INTERNALS_H__ */
