/* $Change: 1114438 $ */
/**
 * Summary: The DTD validation
 * Description: API for the DTD handling and the validity checking
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

/**
 * @file		valid.h
 * @brief	This is the header file for libxml
 *
 *
 */

#ifndef __XML_VALID_H__
#define __XML_VALID_H__

#include <libxml/xmlversion.h>
#include <libxml/xmlerror.h>
#include <libxml/tree.h>
#include <libxml/list.h>
#include <libxml/xmlautomata.h>
#include <libxml/xmlregexp.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup libxml2
 * 
 * @{
 */
 
/**
 * Validation state added for non-determinist content model.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef struct _xmlValidState xmlValidState;

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

typedef xmlValidState *xmlValidStatePtr;

/**
 * xmlValidityErrorFunc:
 * @param[in]	ctx		an xmlValidCtxtPtr validity error context
 * @param[in]	msg		the string to format *printf like vararg
 * @param[in]	...		emaining arguments to the format
 *
 * Callback called when a validity error is found. This is a message
 * oriented function similar to an *printf function.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*xmlValidityErrorFunc) (void *ctx,
			     const char *msg,
			     ...);

/**
 * xmlValidityWarningFunc:
 * @param[in]	ctx		an xmlValidCtxtPtr validity error context
 * @param[in]	msg		the string to format *printf like vararg
 * @param[in]	...		remaining arguments to the format
 *
 * Callback called when a validity warning is found. This is a message
 * oriented function similar to an *printf function.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*xmlValidityWarningFunc) (void *ctx,
			       const char *msg,
			       ...);

/**
 * xmlValidCtxt:
 * An xmlValidCtxt is used for error reporting when validating.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
 
typedef struct _xmlValidCtxt xmlValidCtxt;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlValidCtxt *xmlValidCtxtPtr;
/**
 * @brief Represents a structure in Libxml2
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
struct _xmlValidCtxt {
    void *userData;			/**< user specific data block */
    xmlValidityErrorFunc error;		/**< the callback in case of errors */
    xmlValidityWarningFunc warning;	/**< the callback in case of warning */

    /* Node analysis stack used when validating within entities */
    xmlNodePtr         node;          /**< Current parsed Node */
    int                nodeNr;        /**< Depth of the parsing stack */
    int                nodeMax;       /**< Max depth of the parsing stack */
    xmlNodePtr        *nodeTab;       /**< array of nodes */

    int              finishDtd;       /**< finished validating the Dtd ? */
    xmlDocPtr              doc;       /**< the document */
    int                  valid;       /**< temporary validity check result */

    /* state state used for non-determinist content validation */
    xmlValidState     *vstate;        /**< current state */
    int                vstateNr;      /**< Depth of the validation stack */
    int                vstateMax;     /**< Max depth of the validation stack */
    xmlValidState     *vstateTab;     /**< array of validation states */

#ifdef LIBXML_REGEXP_ENABLED
    xmlAutomataPtr            am;     /**< the automata */
    xmlAutomataStatePtr    state;     /**< used to build the automata */
#else
    void                     *am;	/**< */
    void                  *state;	/**< */
#endif
};

/**
 * ALL notation declarations are stored in a table.
 * There is one table per DTD.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef struct _xmlHashTable xmlNotationTable;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlNotationTable *xmlNotationTablePtr;

/**
 * ALL element declarations are stored in a table.
 * There is one table per DTD.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef struct _xmlHashTable xmlElementTable;

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlElementTable *xmlElementTablePtr;

/**
 * ALL attribute declarations are stored in a table.
 * There is one table per DTD.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

typedef struct _xmlHashTable xmlAttributeTable;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlAttributeTable *xmlAttributeTablePtr;

/**
 * ALL IDs attributes are stored in a table.
 * There is one table per document.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

typedef struct _xmlHashTable xmlIDTable;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlIDTable *xmlIDTablePtr;

/**
 * ALL Refs attributes are stored in a table.
 * There is one table per document.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

typedef struct _xmlHashTable xmlRefTable;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlRefTable *xmlRefTablePtr;

/* Allocate/Release Validation Contexts */

#ifdef LIBXML_VALID_ENABLED
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlValidCtxtPtr XMLCALL	    
		xmlNewValidCtxt(void);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		    
		xmlFreeValidCtxt(xmlValidCtxtPtr);
#endif /* LIBXML_VALID_ENABLED */

/* Notation */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNotationPtr XMLCALL	    
		xmlAddNotationDecl	(xmlValidCtxtPtr ctxt,
					 xmlDtdPtr dtd,
					 const xmlChar *name,
					 const xmlChar *PublicID,
					 const xmlChar *SystemID);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNotationTablePtr XMLCALL 
		xmlCopyNotationTable	(xmlNotationTablePtr table);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		    
		xmlFreeNotationTable	(xmlNotationTablePtr table);
#ifdef LIBXML_OUTPUT_ENABLED
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		    
		xmlDumpNotationDecl	(xmlBufferPtr buf,
					 xmlNotationPtr nota);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		    
		xmlDumpNotationTable	(xmlBufferPtr buf,
					 xmlNotationTablePtr table);
#endif /* LIBXML_OUTPUT_ENABLED */

/* Element Content */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlElementContentPtr XMLCALL 
		xmlNewElementContent	(const xmlChar *name,
					 xmlElementContentType type);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlElementContentPtr XMLCALL 
		xmlCopyElementContent	(xmlElementContentPtr content);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		     
		xmlFreeElementContent	(xmlElementContentPtr cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		     
		xmlSnprintfElementContent(char *buf,
					 int size,
	                                 xmlElementContentPtr content,
					 int glob);
/* DEPRECATED */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		     
		xmlSprintfElementContent(char *buf,
	                                 xmlElementContentPtr content,
					 int glob);
/* DEPRECATED */
/* Element */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlElementPtr XMLCALL	   
		xmlAddElementDecl	(xmlValidCtxtPtr ctxt,
					 xmlDtdPtr dtd,
					 const xmlChar *name,
					 xmlElementTypeVal type,
					 xmlElementContentPtr content);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlElementTablePtr XMLCALL 
		xmlCopyElementTable	(xmlElementTablePtr table);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		   
		xmlFreeElementTable	(xmlElementTablePtr table);
#ifdef LIBXML_OUTPUT_ENABLED

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		   
		xmlDumpElementTable	(xmlBufferPtr buf,
					 xmlElementTablePtr table);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		   
		xmlDumpElementDecl	(xmlBufferPtr buf,
					 xmlElementPtr elem);
#endif /* LIBXML_OUTPUT_ENABLED */

/* Enumeration */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlEnumerationPtr XMLCALL 
		xmlCreateEnumeration	(const xmlChar *name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		   
		xmlFreeEnumeration	(xmlEnumerationPtr cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlEnumerationPtr XMLCALL  
		xmlCopyEnumeration	(xmlEnumerationPtr cur);

/* Attribute */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlAttributePtr XMLCALL	    
		xmlAddAttributeDecl	(xmlValidCtxtPtr ctxt,
					 xmlDtdPtr dtd,
					 const xmlChar *elem,
					 const xmlChar *name,
					 const xmlChar *ns,
					 xmlAttributeType type,
					 xmlAttributeDefault def,
					 const xmlChar *defaultValue,
					 xmlEnumerationPtr tree);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlAttributeTablePtr XMLCALL 
		xmlCopyAttributeTable  (xmlAttributeTablePtr table);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		     
		xmlFreeAttributeTable  (xmlAttributeTablePtr table);
#ifdef LIBXML_OUTPUT_ENABLED
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		     
		xmlDumpAttributeTable  (xmlBufferPtr buf,
					xmlAttributeTablePtr table);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		     
		xmlDumpAttributeDecl   (xmlBufferPtr buf,
					xmlAttributePtr attr);
#endif /* LIBXML_OUTPUT_ENABLED */

/* IDs */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlIDPtr XMLCALL	
		xmlAddID	       (xmlValidCtxtPtr ctxt,
					xmlDocPtr doc,
					const xmlChar *value,
					xmlAttrPtr attr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlFreeIDTable	       (xmlIDTablePtr table);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlAttrPtr XMLCALL	
		xmlGetID	       (xmlDocPtr doc,
					const xmlChar *ID);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlIsID		       (xmlDocPtr doc,
					xmlNodePtr elem,
					xmlAttrPtr attr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlRemoveID	       (xmlDocPtr doc, 
					xmlAttrPtr attr);

/* IDREFs */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlRefPtr XMLCALL	
		xmlAddRef	       (xmlValidCtxtPtr ctxt,
					xmlDocPtr doc,
					const xmlChar *value,
					xmlAttrPtr attr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlFreeRefTable	       (xmlRefTablePtr table);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlIsRef	       (xmlDocPtr doc,
					xmlNodePtr elem,
					xmlAttrPtr attr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlRemoveRef	       (xmlDocPtr doc, 
					xmlAttrPtr attr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlListPtr XMLCALL	
		xmlGetRefs	       (xmlDocPtr doc,
					const xmlChar *ID);

/* The public function calls related to validity checking. */

#ifdef LIBXML_VALID_ENABLED
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateRoot		(xmlValidCtxtPtr ctxt,
					 xmlDocPtr doc);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateElementDecl	(xmlValidCtxtPtr ctxt,
					 xmlDocPtr doc,
		                         xmlElementPtr elem);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL	
		xmlValidNormalizeAttributeValue(xmlDocPtr doc,
					 xmlNodePtr elem,
					 const xmlChar *name,
					 const xmlChar *value);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL	
		xmlValidCtxtNormalizeAttributeValue(xmlValidCtxtPtr ctxt,
					 xmlDocPtr doc,
					 xmlNodePtr elem,
					 const xmlChar *name,
					 const xmlChar *value);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateAttributeDecl(xmlValidCtxtPtr ctxt,
					 xmlDocPtr doc,
		                         xmlAttributePtr attr);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateAttributeValue(xmlAttributeType type,
					 const xmlChar *value);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateNotationDecl	(xmlValidCtxtPtr ctxt,
					 xmlDocPtr doc,
		                         xmlNotationPtr nota);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateDtd		(xmlValidCtxtPtr ctxt,
					 xmlDocPtr doc,
					 xmlDtdPtr dtd);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateDtdFinal	(xmlValidCtxtPtr ctxt,
					 xmlDocPtr doc);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateDocument	(xmlValidCtxtPtr ctxt,
					 xmlDocPtr doc);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateElement	(xmlValidCtxtPtr ctxt,
					 xmlDocPtr doc,
					 xmlNodePtr elem);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateOneElement	(xmlValidCtxtPtr ctxt,
					 xmlDocPtr doc,
		                         xmlNodePtr elem);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL	
		xmlValidateOneAttribute	(xmlValidCtxtPtr ctxt,
					 xmlDocPtr doc,
					 xmlNodePtr	elem,
					 xmlAttrPtr attr,
					 const xmlChar *value);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateOneNamespace	(xmlValidCtxtPtr ctxt,
					 xmlDocPtr doc,
					 xmlNodePtr elem,
					 const xmlChar *prefix,
					 xmlNsPtr ns,
					 const xmlChar *value);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateDocumentFinal(xmlValidCtxtPtr ctxt,
					 xmlDocPtr doc);
#endif /* LIBXML_VALID_ENABLED */
#if defined(LIBXML_VALID_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED)
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateNotationUse	(xmlValidCtxtPtr ctxt,
					 xmlDocPtr doc,
					 const xmlChar *notationName);
#endif /* LIBXML_VALID_ENABLED or LIBXML_SCHEMAS_ENABLED */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlIsMixedElement	(xmlDocPtr doc,
					 const xmlChar *name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlAttributePtr XMLCALL	
		xmlGetDtdAttrDesc	(xmlDtdPtr dtd,
					 const xmlChar *elem,
					 const xmlChar *name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlAttributePtr XMLCALL	
		xmlGetDtdQAttrDesc	(xmlDtdPtr dtd,
					 const xmlChar *elem,
					 const xmlChar *name,
					 const xmlChar *prefix);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNotationPtr XMLCALL	
		xmlGetDtdNotationDesc	(xmlDtdPtr dtd,
					 const xmlChar *name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlElementPtr XMLCALL	
		xmlGetDtdQElementDesc	(xmlDtdPtr dtd,
					 const xmlChar *name,
					 const xmlChar *prefix);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlElementPtr XMLCALL	
		xmlGetDtdElementDesc	(xmlDtdPtr dtd,
					 const xmlChar *name);

#ifdef LIBXML_VALID_ENABLED
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidGetValidElements(xmlNode *prev,
					 xmlNode *next,
					 const xmlChar **names,
					 int max);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidGetPotentialChildren(xmlElementContent *ctree,
					 const xmlChar **list,
					 int *len,
					 int max);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateNameValue	(const xmlChar *value);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateNamesValue	(const xmlChar *value);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateNmtokenValue	(const xmlChar *value);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidateNmtokensValue(const xmlChar *value);

#ifdef LIBXML_REGEXP_ENABLED
/*
 * Validation based on the regexp support
 */
/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidBuildContentModel(xmlValidCtxtPtr ctxt,
					 xmlElementPtr elem);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidatePushElement	(xmlValidCtxtPtr ctxt,
					 xmlDocPtr doc,
					 xmlNodePtr elem,
					 const xmlChar *qname);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidatePushCData	(xmlValidCtxtPtr ctxt,
					 const xmlChar *data,
					 int len);

/**
 *
 ** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since	1.0
 */
XMLPUBFUN int XMLCALL		
		xmlValidatePopElement	(xmlValidCtxtPtr ctxt,
					 xmlDocPtr doc,
					 xmlNodePtr elem,
					 const xmlChar *qname);
#endif /* LIBXML_REGEXP_ENABLED */

#endif /* LIBXML_VALID_ENABLED */
/**
 * @}
 */
 
#ifdef __cplusplus
}
#endif
#endif /* __XML_VALID_H__ */
