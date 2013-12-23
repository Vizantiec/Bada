/* $Change: 1114438 $ */
/**
 * Summary: interface for the XML entities handling
 * Description: this module provides some of the entity API needed
 *              for the parser and applications.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

/**
 * @file		entities.h
 * @brief	This is the header file for libxml
 *
 *
 */

#ifndef __XML_ENTITIES_H__
#define __XML_ENTITIES_H__

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
 
/**
 * @enum xmlEntityType
 * 
 * The different valid entity types.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since 1.0
 */
typedef enum {
    XML_INTERNAL_GENERAL_ENTITY = 1,/**< */
    XML_EXTERNAL_GENERAL_PARSED_ENTITY = 2,/**< */
    XML_EXTERNAL_GENERAL_UNPARSED_ENTITY = 3,/**< */
    XML_INTERNAL_PARAMETER_ENTITY = 4,/**< */
    XML_EXTERNAL_PARAMETER_ENTITY = 5,/**< */
    XML_INTERNAL_PREDEFINED_ENTITY = 6 /**< */
} xmlEntityType;

/**
 * @brief Represents a structure in Libxml2
 *
 * An unit of storage for an entity, contains the string, the value
 * and the linkind data needed for the linking in the hash table.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

struct _xmlEntity {
    void           *_private;	        /**< application data */
    xmlElementType          type;       /**< XML_ENTITY_DECL, must be second ! */
    const xmlChar          *name;	/**< Entity name */
    struct _xmlNode    *children;	/**< First child link */
    struct _xmlNode        *last;	/**< Last child link */
    struct _xmlDtd       *parent;	/**< -> DTD */
    struct _xmlNode        *next;	/**< next sibling link  */
    struct _xmlNode        *prev;	/**< previous sibling link  */
    struct _xmlDoc          *doc;       /**< the containing document */

    xmlChar                *orig;	/**< content without ref substitution */
    xmlChar             *content;	/**< content or ndata if unparsed */
    int                   length;	/**< the content length */
    xmlEntityType          etype;	/**< The entity type */
    const xmlChar    *ExternalID;	/**< External identifier for PUBLIC */
    const xmlChar      *SystemID;	/**< URI for a SYSTEM or PUBLIC Entity */

    struct _xmlEntity     *nexte;	/**< unused */
    const xmlChar           *URI;	/**< the full URI as computed */
    int                    owner;	/**< does the entity own the children */
};

/**
 * All entities are stored in an hash table.
 * There is 2 separate hash tables for global and parameter entities.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

typedef struct _xmlHashTable xmlEntitiesTable;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlEntitiesTable *xmlEntitiesTablePtr;

/*
 * External functions:
 */

#ifdef LIBXML_LEGACY_ENABLED
/**
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlInitializePredefinedEntities	(void);
#endif /* LIBXML_LEGACY_ENABLED */
/**
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlEntityPtr XMLCALL
			xmlAddDocEntity		(xmlDocPtr doc,
						 const xmlChar *name,
						 int type,
						 const xmlChar *ExternalID,
						 const xmlChar *SystemID,
						 const xmlChar *content);
/**
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlEntityPtr XMLCALL		
			xmlAddDtdEntity		(xmlDocPtr doc,
						 const xmlChar *name,
						 int type,
						 const xmlChar *ExternalID,
						 const xmlChar *SystemID,
						 const xmlChar *content);
/**
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlEntityPtr XMLCALL		
			xmlGetPredefinedEntity	(const xmlChar *name);
/**
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlEntityPtr XMLCALL		
			xmlGetDocEntity		(xmlDocPtr doc,
						 const xmlChar *name);
/**
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlEntityPtr XMLCALL		
			xmlGetDtdEntity		(xmlDocPtr doc,
						 const xmlChar *name);
/**
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlEntityPtr XMLCALL		
			xmlGetParameterEntity	(xmlDocPtr doc,
						 const xmlChar *name);

#ifdef LIBXML_LEGACY_ENABLED
/**
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN const xmlChar * XMLCALL		
			xmlEncodeEntities	(xmlDocPtr doc,
						 const xmlChar *input);
#endif /* LIBXML_LEGACY_ENABLED */

/**
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlEncodeEntitiesReentrant(xmlDocPtr doc,
						 const xmlChar *input);
/**
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL		
			xmlEncodeSpecialChars	(xmlDocPtr doc,
						 const xmlChar *input);
/**
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlEntitiesTablePtr XMLCALL	
			xmlCreateEntitiesTable	(void);
/**
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlEntitiesTablePtr XMLCALL	
			xmlCopyEntitiesTable	(xmlEntitiesTablePtr table);
/**
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlFreeEntitiesTable	(xmlEntitiesTablePtr table);
#ifdef LIBXML_OUTPUT_ENABLED
/**
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlDumpEntitiesTable	(xmlBufferPtr buf,
						 xmlEntitiesTablePtr table);
/**
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlDumpEntityDecl	(xmlBufferPtr buf,
						 xmlEntityPtr ent);
#endif /* LIBXML_OUTPUT_ENABLED */

#ifdef LIBXML_LEGACY_ENABLED
/**
 * 
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL			
			xmlCleanupPredefinedEntities(void);

#endif /* LIBXML_LEGACY_ENABLED */
/**
 * @}
 */
 
#ifdef __cplusplus
}
#endif

# endif /* __XML_ENTITIES_H__ */
