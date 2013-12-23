/* $Change: 1114438 $ */
/**
 * Summary: the core parser module
 * Description: Interfaces, constants and types related to the XML parser
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

/**
 * @file		parser.h
 * @brief	This is the header file for libxml
 *
 *
 */

#ifndef __XML_PARSER_H__
#define __XML_PARSER_H__

//#include <stdarg.h>

#include <libxml/xmlversion.h>
#include <libxml/tree.h>
#include <libxml/dict.h>
#include <libxml/hash.h>
#include <libxml/valid.h>
#include <libxml/entities.h>
#include <libxml/xmlerror.h>
#include <libxml/xmlstring.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup libxml2 Libxml2
 * @brief	The list of Libxml2 functions
 * @since	1.0 
 */
 
/**
 * @addtogroup libxml2
 * 
 * @{
 */
 
/*
 * XML_DEFAULT_VERSION:
 *
 * The default version of XML used: 1.0
 */
#define XML_DEFAULT_VERSION	"1.0"

/*
 * xmlParserInput:
 *
 * An xmlParserInput is an input flow for the XML processor.
 * Each entity parsed is associated an xmlParserInput (except the
 * few predefined ones). This is the case both for internal entities
 * - in which case the flow is already completely in memory - or
 * external entities - in which case we use the buf structure for
 * progressive reading and I18N conversions to the internal UTF-8 format.
 */

/**
 * xmlParserInputDeallocate:
 * @param[in]	str	the string to deallocate
 *
 * Callback for freeing some parser input allocations.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (* xmlParserInputDeallocate)(xmlChar *str);

/**
 * @brief Represents a structure in Libxml2
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
struct _xmlParserInput {
    /* Input buffer */
    xmlParserInputBufferPtr buf;      /**< UTF-8 encoded buffer */

    const char *filename;             /**< The file analyzed, if any */
    const char *directory;            /**< the directory/base of the file */
    const xmlChar *base;              /**< Base of the array to parse */
    const xmlChar *cur;               /**< Current char being parsed */
    const xmlChar *end;               /**< end of the array to parse */
    int length;                       /**< length if known */
    int line;                         /**< Current line */
    int col;                          /**< Current column */
    /*
     * NOTE: consumed is only tested for equality in the parser code,
     *       so even if there is an overflow this should not give troubles
     *       for parsing very large instances.
     */
    unsigned long consumed;           /**< How many xmlChars already consumed */
    xmlParserInputDeallocate free;    /**< function to deallocate the base */
    const xmlChar *encoding;          /**< the encoding string for entity */
    const xmlChar *version;           /**< the version string for entity */
    int standalone;                   /**< Was that entity marked standalone */
    int id;                           /**< an unique identifier for the entity */
};

/**
 * xmlParserNodeInfo:
 *
 * The parser can be asked to collect Node information, i.e. at what
 * place in the file they were detected. 
 * NOTE: This is off by default and not very well tested.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef struct _xmlParserNodeInfo xmlParserNodeInfo;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlParserNodeInfo *xmlParserNodeInfoPtr;

/**
 * @brief Represents a structure in Libxml2
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
struct _xmlParserNodeInfo {
  const struct _xmlNode* node;	/**< */
  /* Position & line # that text that created the node begins & ends on */
  unsigned long begin_pos;		/**< */
  unsigned long begin_line;		/**< */
  unsigned long end_pos;		/**< */
  unsigned long end_line;		/**< */
};

/**
 * xmlParserNodeInfoSeq:
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

typedef struct _xmlParserNodeInfoSeq xmlParserNodeInfoSeq;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlParserNodeInfoSeq *xmlParserNodeInfoSeqPtr;
/**
 * @brief Represents a structure in Libxml2
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
struct _xmlParserNodeInfoSeq {
  unsigned long maximum;		/**< */
  unsigned long length;			/**< */
  xmlParserNodeInfo* buffer;	/**< */
};

/**
 * @enum xmlParserInputState
 *
 * The parser is now working also as a state based parser.
 * The recursive one use the state info for entities processing.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef enum {
    XML_PARSER_EOF = -1,	/**< nothing is to be parsed */
    XML_PARSER_START = 0,	/**< nothing has been parsed */
    XML_PARSER_MISC,		/**< Misc* before int subset */
    XML_PARSER_PI,			/**< Within a processing instruction */
    XML_PARSER_DTD,			/**< within some DTD content */
    XML_PARSER_PROLOG,		/**< Misc* after internal subset */
    XML_PARSER_COMMENT,		/**< within a comment */
    XML_PARSER_START_TAG,	/**< within a start tag */
    XML_PARSER_CONTENT,		/**< within the content */
    XML_PARSER_CDATA_SECTION,	/**< within a CDATA section */
    XML_PARSER_END_TAG,		/**< within a closing tag */
    XML_PARSER_ENTITY_DECL,	/**< within an entity declaration */
    XML_PARSER_ENTITY_VALUE,	/**< within an entity value in a decl */
    XML_PARSER_ATTRIBUTE_VALUE,	/**< within an attribute value */
    XML_PARSER_SYSTEM_LITERAL,	/**< within a SYSTEM value */
    XML_PARSER_EPILOG, 		/**< the Misc* after the last end tag */
    XML_PARSER_IGNORE,		/**< within an IGNORED section */
    XML_PARSER_PUBLIC_LITERAL 	/**< within a PUBLIC value */
} xmlParserInputState;

/*
 * XML_DETECT_IDS:
 *
 * Bit in the loadsubset context field to tell to do ID/REFs lookups.
 * Use it to initialize xmlLoadExtDtdDefaultValue.
 */
#define XML_DETECT_IDS		2

/*
 * XML_COMPLETE_ATTRS:
 *
 * Bit in the loadsubset context field to tell to do complete the
 * elements attributes lists with the ones defaulted from the DTDs.
 * Use it to initialize xmlLoadExtDtdDefaultValue.
 */
#define XML_COMPLETE_ATTRS	4

/*
 * XML_SKIP_IDS:
 *
 * Bit in the loadsubset context field to tell to not do ID/REFs registration.
 * Used to initialize xmlLoadExtDtdDefaultValue in some special cases.
 */
#define XML_SKIP_IDS		8

/**
 * @brief Represents a structure in Libxml2
 *
 * xmlParserCtxt:
 *
 * The parser context.
 *
 * NOTE This doesn't completely define the parser state, the (current ?)
 *      design of the parser uses recursive function calls since this allow
 *      and easy mapping from the production rules of the specification
 *      to the actual code. The drawback is that the actual function call
 *      also reflect the parser state. However most of the parsing routines
 *      takes as the only argument the parser context pointer, so migrating
 *      to a state based parser for progressive parsing shouldn't be too hard.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
struct _xmlParserCtxt {
    struct _xmlSAXHandler *sax;       /**< The SAX handler */
    void            *userData;        /**< For SAX interface only, used by DOM build */
    xmlDocPtr           myDoc;        /**< the document being built */
    int            wellFormed;        /**< is the document well formed */
    int       replaceEntities;        /**< shall we replace entities ? */
    const xmlChar    *version;        /**< the XML version string */
    const xmlChar   *encoding;        /**< the declared encoding, if any */
    int            standalone;        /**< standalone document */
    int                  html;        /**< an HTML(1)/Docbook(2) document */

    /* Input stream stack */
    xmlParserInputPtr  input;         /**< Current input stream */
    int                inputNr;       /**< Number of current input streams */
    int                inputMax;      /**< Max number of input streams */
    xmlParserInputPtr *inputTab;      /**< stack of inputs */

    /* Node analysis stack only used for DOM building */
    xmlNodePtr         node;          /**< Current parsed Node */
    int                nodeNr;        /**< Depth of the parsing stack */
    int                nodeMax;       /**< Max depth of the parsing stack */
    xmlNodePtr        *nodeTab;       /**< array of nodes */

    int record_info;                  /**< Whether node info should be kept */
    xmlParserNodeInfoSeq node_seq;    /**< info about each node parsed */

    int errNo;                        /**< error code */

    int     hasExternalSubset;        /**< reference and external subset */
    int             hasPErefs;        /**< the internal subset has PE refs */
    int              external;        /**< are we parsing an external entity */

    int                 valid;        /**< is the document valid */
    int              validate;        /**< shall we try to validate ? */
    xmlValidCtxt        vctxt;        /**< The validity context */

    xmlParserInputState instate;      /**< current type of input */
    int                 token;        /**< next char look-ahead */    

    char           *directory;        /**< the data directory */

    /* Node name stack */
    const xmlChar     *name;          /**< Current parsed Node */
    int                nameNr;        /**< Depth of the parsing stack */
    int                nameMax;       /**< Max depth of the parsing stack */
    const xmlChar *   *nameTab;       /**< array of nodes */

    long               nbChars;       /**< number of xmlChar processed */
    long            checkIndex;       /**< used by progressive parsing lookup */
    int             keepBlanks;       /**< ugly but ... */
    int             disableSAX;       /**< SAX callbacks are disabled */
    int               inSubset;       /**< Parsing is in int 1/ext 2 subset */
    const xmlChar *    intSubName;    /**< name of subset */
    xmlChar *          extSubURI;     /**< URI of external subset */
    xmlChar *          extSubSystem;  /**< SYSTEM ID of external subset */

    /* xml:space values */
    int *              space;         /**< Should the parser preserve spaces */
    int                spaceNr;       /**< Depth of the parsing stack */
    int                spaceMax;      /**< Max depth of the parsing stack */
    int *              spaceTab;      /**< array of space info */

    int                depth;         /**< to prevent entity substitution loops */
    xmlParserInputPtr  entity;        /**< used to check entities boundaries */
    int                charset;       /**< encoding of the in-memory content
				         actually an xmlCharEncoding */
    int                nodelen;       /**< Those two fields are there to */
    int                nodemem;       /**< Speed up large node parsing */
    int                pedantic;      /**< signal pedantic warnings */
    void              *_private;      /**< For user data, libxml won't touch it */

    int                loadsubset;    /**< should the external subset be loaded */
    int                linenumbers;   /**< set line number in element content */
    void              *catalogs;       /**< document's own catalog */
    int                recovery;      /**< run in recovery mode */
    int                progressive;   /**< is this a progressive parsing */
    xmlDictPtr         dict;          /**< dictionary for the parser */
    const xmlChar *   *atts;          /**< array for the attributes callbacks */
    int                maxatts;       /**< the size of the array */
    int                docdict;       /**< use strings from dict to build tree */

    /*
     * pre-interned strings
     */
    const xmlChar *str_xml;			/**< */
    const xmlChar *str_xmlns;		/**< */
    const xmlChar *str_xml_ns;		/**< */

    /*
     * Everything below is used only by the new SAX mode
     */
    int                sax2;          /**< operating in the new SAX mode */
    int                nsNr;          /**< the number of inherited namespaces */
    int                nsMax;         /**< the size of the arrays */
    const xmlChar *   *nsTab;         /**< the array of prefix/namespace name */
    int               *attallocs;     /**< which attribute were allocated */
    void *            *pushTab;       /**< array of data for push */
    xmlHashTablePtr    attsDefault;   /**< defaulted attributes if any */
    xmlHashTablePtr    attsSpecial;   /**< non-CDATA attributes if any */
    int                nsWellFormed;  /**< is the document XML Namespace okay */
    int                options;       /**< Extra options */

    /*
     * Those fields are needed only for streaming parsing so far
     */
    int               dictNames;    /**< Use dictionary names for the tree */
    int               freeElemsNr;  /**< number of freed element nodes */
    xmlNodePtr        freeElems;    /**< List of freed element nodes */
    int               freeAttrsNr;  /**< number of freed attributes nodes */
    xmlAttrPtr        freeAttrs;    /**< List of freed attributes nodes */

    /*
     * the complete error information for the last error.
     */
    xmlError          lastError;	/**< */
};

/**
 * @brief Represents a structure in Libxml2
 *
 * xmlSAXLocator:
 *
 * A SAX Locator.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

struct _xmlSAXLocator {
    const xmlChar *(*getPublicId)(void *ctx);	/**< */
    const xmlChar *(*getSystemId)(void *ctx);	/**< */
    int (*getLineNumber)(void *ctx);			/**< */
    int (*getColumnNumber)(void *ctx);			/**< */
};

/*
 * xmlSAXHandler:
 *
 * A SAX handler is bunch of callbacks called by the parser when processing
 * of the input generate data or structure information.
 */

/**
 * resolveEntitySAXFunc:
 *
 * @param[in]	ctx				The user data (XML parser context)
 * @param[in]	publicId		The public ID of the entity
 * @param[in]	systemId		The system ID of the entity
 *
 * Callback:
 * The entity loader, to control the loading of external entities,
 * the application can either:
 *    - override this resolveEntity() callback in the SAX block
 *    - or better use the xmlSetExternalEntityLoader() function to
 *      set up it's own entity resolution routine
 *
 * Returns the xmlParserInputPtr if inline or NULL for DOM behavior.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlParserInputPtr (*resolveEntitySAXFunc) (void *ctx,
				const xmlChar *publicId,
				const xmlChar *systemId);
/**
 * internalSubsetSAXFunc:
 *
 * @param[in]	ctx			The user data (XML parser context)
 * @param[in]	name:  		The root element name
 * @param[in]	ExternalID: The external ID
 * @param[in]	SystemID:   The SYSTEM ID (e.g. filename or URL)
 *
 * Callback on internal subset declaration.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*internalSubsetSAXFunc) (void *ctx,
				const xmlChar *name,
				const xmlChar *ExternalID,
				const xmlChar *SystemID);
/**
 * externalSubsetSAXFunc:
 *
 * @param[in]	ctx           The user data (XML parser context)
 * @param[in]	name  		  The root element name
 * @param[in]	ExternalID    The external ID
 * @param[in]	SystemID      The SYSTEM ID (e.g. filename or URL)
 *
 * Callback on external subset declaration.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*externalSubsetSAXFunc) (void *ctx,
				const xmlChar *name,
				const xmlChar *ExternalID,
				const xmlChar *SystemID);
/**
 * getEntitySAXFunc:
 *
 * @param[in]	ctx    The user data (XML parser context)
 * @param[in]	name   The entity name
 *
 * Get an entity by name.
 *
 * Returns the xmlEntityPtr if found.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlEntityPtr (*getEntitySAXFunc) (void *ctx,
				const xmlChar *name);
/**
 * getParameterEntitySAXFunc:
 *
 * @param[in]	ctx    The user data (XML parser context)
 * @param[in]	name   The entity name
 *
 * Get a parameter entity by name.
 *
 * Returns the xmlEntityPtr if found.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlEntityPtr (*getParameterEntitySAXFunc) (void *ctx,
				const xmlChar *name);
/**
 * entityDeclSAXFunc:
 *
 * @param[in]	ctx        The user data (XML parser context)
 * @param[in]	name       The entity name
 * @param[in]	type       The entity type
 * @param[in]	publicId   The public ID of the entity
 * @param[in]	systemId   The system ID of the entity
 * @param[in]	content    The entity value (without processing).
 *
 * An entity definition has been parsed.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*entityDeclSAXFunc) (void *ctx,
				const xmlChar *name,
				int type,
				const xmlChar *publicId,
				const xmlChar *systemId,
				xmlChar *content);
/**
 * notationDeclSAXFunc:
 *
 * @param[in]	ctx       The user data (XML parser context)
 * @param[in]	name      The name of the notation
 * @param[in]	publicId  The public ID of the entity
 * @param[in]	systemId  The system ID of the entity
 *
 * What to do when a notation declaration has been parsed.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*notationDeclSAXFunc)(void *ctx,
				const xmlChar *name,
				const xmlChar *publicId,
				const xmlChar *systemId);
/**
 * attributeDeclSAXFunc:
 *
 * @param[in]	ctx             The user data (XML parser context)
 * @param[in]	elem   			The name of the element
 * @param[in]	fullname   		The attribute name
 * @param[in]	type  			The attribute type
 * @param[in]	def 			The type of default value
 * @param[in]	defaultValue    The attribute default value
 * @param[in]	tree            The tree of enumerated value set
 *
 * An attribute definition has been parsed.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*attributeDeclSAXFunc)(void *ctx,
				const xmlChar *elem,
				const xmlChar *fullname,
				int type,
				int def,
				const xmlChar *defaultValue,
				xmlEnumerationPtr tree);
/**
 * elementDeclSAXFunc:
 *
 * @param[in]	ctx      The user data (XML parser context)
 * @param[in]	name     The element name
 * @param[in]	type     The element type
 * @param[in]	content  The element value tree
 *
 * An element definition has been parsed.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*elementDeclSAXFunc)(void *ctx,
				const xmlChar *name,
				int type,
				xmlElementContentPtr content);

/**
 * unparsedEntityDeclSAXFunc:
 *
 * @param[in]	ctx           The user data (XML parser context)
 * @param[in]	name 		  The name of the entity
 * @param[in]	publicId	  The public ID of the entity
 * @param[in]	systemId	  The system ID of the entity
 * @param[in]	notationName  The name of the notation
 *
 * What to do when an unparsed entity declaration is parsed.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 *
 */
typedef void (*unparsedEntityDeclSAXFunc)(void *ctx,
				const xmlChar *name,
				const xmlChar *publicId,
				const xmlChar *systemId,
				const xmlChar *notationName);
/**
 * setDocumentLocatorSAXFunc:
 *
 * @param[in]	ctx   The user data (XML parser context)
 * @param[in]	loc   A SAX Locator
 *
 * Receive the document locator at startup, actually xmlDefaultSAXLocator.
 * Everything is available on the context, so this is useless in our case.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*setDocumentLocatorSAXFunc) (void *ctx,
				xmlSAXLocatorPtr loc);
/**
 * startDocumentSAXFunc:
 *
 * @param[in]	ctx  The user data (XML parser context)
 *
 * Called when the document start being processed.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*startDocumentSAXFunc) (void *ctx);

/**
 * endDocumentSAXFunc:
 *
 * @param[in]	ctx  The user data (XML parser context)
 *
 * Called when the document end has been detected.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*endDocumentSAXFunc) (void *ctx);

/**
 * startElementSAXFunc:
 *
 * @param[in]	ctx   The user data (XML parser context)
 * @param[in]	name  The element name, including namespace prefix
 * @param[in]	atts  An array of name/value attributes pairs, NULL terminated
 *
 * Called when an opening tag has been processed.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*startElementSAXFunc) (void *ctx,
				const xmlChar *name,
				const xmlChar **atts);

/**
 * endElementSAXFunc:
 *
 * @param[in]	ctx   The user data (XML parser context)
 * @param[in]	name  The element name
 *
 * Called when the end of an element has been detected.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*endElementSAXFunc) (void *ctx,
				const xmlChar *name);

/**
 * attributeSAXFunc:
 *
 * @param[in]	ctx  	The user data (XML parser context)
 * @param[in]	name 	The attribute name, including namespace prefix
 * @param[in]	value   The attribute value
 *
 * Handle an attribute that has been read by the parser.
 * The default handling is to convert the attribute into an
 * DOM subtree and past it in a new xmlAttr element added to
 * the element.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*attributeSAXFunc) (void *ctx,
				const xmlChar *name,
				const xmlChar *value);

/**
 * referenceSAXFunc:
 *
 * @param[in]	ctx   The user data (XML parser context)
 * @param[in]	name  The entity name
 *
 * Called when an entity reference is detected. 
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*referenceSAXFunc) (void *ctx,
				const xmlChar *name);

/**
 * charactersSAXFunc:
 *
 * @param[in]	ctx  The user data (XML parser context)
 * @param[in]	ch   A xmlChar string
 * @param[in]	len  The number of xmlChar
 *
 * Receiving some chars from the parser.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*charactersSAXFunc) (void *ctx,
				const xmlChar *ch,
				int len);
/**
 * ignorableWhitespaceSAXFunc:
 *
 * @param[in]	ctx  The user data (XML parser context)
 * @param[in]	ch   A xmlChar string
 * @param[in]	len  The number of xmlChar
 *
 * Receiving some ignorable whitespaces from the parser.
 * UNUSED: by default the DOM building will use characters.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

typedef void (*ignorableWhitespaceSAXFunc) (void *ctx,
				const xmlChar *ch,
				int len);

/**
 * processingInstructionSAXFunc:
 *
 * @param[in]	ctx:     The user data (XML parser context)
 * @param[in]	target   The target name
 * @param[in]	data     The PI data's
 *
 * A processing instruction has been parsed.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*processingInstructionSAXFunc) (void *ctx,
				const xmlChar *target,
				const xmlChar *data);

/**
 *
 * commentSAXFunc:
 *
 * @param[in]	ctx     The user data (XML parser context)
 * @param[in]	value  	The comment content
 *
 * A comment has been parsed.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

typedef void (*commentSAXFunc) (void *ctx,
				const xmlChar *value);
/**
 * cdataBlockSAXFunc:
 *
 * @param[in]	ctx     The user data (XML parser context)
 * @param[in]	value   The pcdata content
 * @param[in]	len     The block length
 *
 * Called when a pcdata block has been parsed.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*cdataBlockSAXFunc) (
	                        void *ctx,
				const xmlChar *value,
				int len);
/**
 * warningSAXFunc:
 * 
 * @param[in]	ctx   An XML parser context
 * @param[in]	msg   The message to display/transmit
 * @param[in]	...   Extra parameters for the message display
 *
 * Display and format a warning messages, callback.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*warningSAXFunc) (void *ctx,
				const char *msg, ...);

/**
 * errorSAXFunc:
 * 
 * @param[in]	ctx  An XML parser context
 * @param[in]	msg  The message to display/transmit
 * @param[in]	...  Extra parameters for the message display
 *
 * Display and format an error messages, callback.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*errorSAXFunc) (void *ctx,
				const char *msg, ...);

/**
 * fatalErrorSAXFunc:
 * 
 * @param[in]	ctx  An XML parser context
 * @param[in]	msg  The message to display/transmit
 * @param[in]	...  Extra parameters for the message display
 *
 * Display and format fatal error messages, callback.
 * Note: so far fatalError() SAX callbacks are not used, error()
 *       get all the callbacks for errors.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef void (*fatalErrorSAXFunc) (void *ctx,
				const char *msg, ...);
/**
 * isStandaloneSAXFunc:
 *
 * @param[in]	ctx  the user data (XML parser context)
 *
 * Is this document tagged standalone?
 *
 * Returns 1 if true
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef int (*isStandaloneSAXFunc) (void *ctx);

/**
 * hasInternalSubsetSAXFunc:
 *
 * @param[in]	ctx  The user data (XML parser context)
 *
 * Does this document has an internal subset.
 *
 * Returns 1 if true
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef int (*hasInternalSubsetSAXFunc) (void *ctx);

/**
 * hasExternalSubsetSAXFunc
 *
 * @param[in]	ctx  The user data (XML parser context)
 *
 * Does this document has an external subset?
 *
 * Returns 1 if true
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef int (*hasExternalSubsetSAXFunc) (void *ctx);

/***********************************************************************
 *									*
 *			The SAX version 2 API extensions		*
 *									*
 ************************************************************************/
/*
 * XML_SAX2_MAGIC:
 *
 * Special constant found in SAX2 blocks initialized fields
 */
#define XML_SAX2_MAGIC 0xDEEDBEAF

/**
 * startElementNsSAX2Func:
 *
 * @param[in]	ctx              The user data (XML parser context)
 * @param[in]	localname   	 The local name of the element
 * @param[in]	prefix   		 The element namespace prefix if available
 * @param[in]	URI  			 The element namespace name if available
 * @param[in]	nb_namespaces    Number of namespace definitions on that node
 * @param[in]	namespaces       Pointer to the array of prefix/URI pairs namespace definitions
 * @param[in]	nb_attributes    The number of attributes on that node
 * @param[in]	nb_defaulted     The number of defaulted attributes. The defaulted
 *                  			 ones are at the end of the array
 * @param[in]	attributes       Pointer to the array of (localname/prefix/URI/value/end)
 *                               attribute values.
 *
 * SAX2 callback when an element start has been detected by the parser.
 * It provides the namespace information for the element, as well as
 * the new namespace declarations on the element.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

typedef void (*startElementNsSAX2Func) (void *ctx,
					const xmlChar *localname,
					const xmlChar *prefix,
					const xmlChar *URI,
					int nb_namespaces,
					const xmlChar **namespaces,
					int nb_attributes,
					int nb_defaulted,
					const xmlChar **attributes);
 
/**
 * endElementNsSAX2Func:
 *
 * @param[in]	ctx         The user data (XML parser context)
 * @param[in]	localname   The local name of the element
 * @param[in]	prefix      The element namespace prefix if available
 * @param[in]	URI			The element namespace name if available
 *
 * SAX2 callback when an element end has been detected by the parser.
 * It provides the namespace information for the element.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

typedef void (*endElementNsSAX2Func)   (void *ctx,
					const xmlChar *localname,
					const xmlChar *prefix,
					const xmlChar *URI);


/**
 * @brief Represents a structure in Libxml2
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
struct _xmlSAXHandler {
    internalSubsetSAXFunc internalSubset;			/**< */
    isStandaloneSAXFunc isStandalone;				/**< */
    hasInternalSubsetSAXFunc hasInternalSubset;		/**< */
    hasExternalSubsetSAXFunc hasExternalSubset;		/**< */
    resolveEntitySAXFunc resolveEntity;				/**< */			
    getEntitySAXFunc getEntity;						/**< */
    entityDeclSAXFunc entityDecl;					/**< */
    notationDeclSAXFunc notationDecl;				/**< */
    attributeDeclSAXFunc attributeDecl;				/**< */
    elementDeclSAXFunc elementDecl;					/**< */
    unparsedEntityDeclSAXFunc unparsedEntityDecl;	/**< */
    setDocumentLocatorSAXFunc setDocumentLocator;	/**< */
    startDocumentSAXFunc startDocument;				/**< */
    endDocumentSAXFunc endDocument;					/**< */
    startElementSAXFunc startElement;				/**< */
    endElementSAXFunc endElement;					/**< */
    referenceSAXFunc reference;						/**< */
    charactersSAXFunc characters;					/**< */
    ignorableWhitespaceSAXFunc ignorableWhitespace;	/**< */
    processingInstructionSAXFunc processingInstruction;	/**< */
    commentSAXFunc comment;							/**< */
    warningSAXFunc warning;							/**< */
    errorSAXFunc error;								/**< */
    fatalErrorSAXFunc fatalError; 					/**< *nused error() get all the errors */
    getParameterEntitySAXFunc getParameterEntity;	/**< */
    cdataBlockSAXFunc cdataBlock;					/**< */
    externalSubsetSAXFunc externalSubset;			/**< */
    unsigned int initialized;						/**< */
    /* The following fields are extensions available only on version 2 */
    void *_private;									/**< */
    startElementNsSAX2Func startElementNs;			/**< */
    endElementNsSAX2Func endElementNs;				/**< */
    xmlStructuredErrorFunc serror;					/**< */
};

/**
 * SAX Version 1
 *
 * xmlSAXHandlerV1
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 *
 */
typedef struct _xmlSAXHandlerV1 xmlSAXHandlerV1;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlSAXHandlerV1 *xmlSAXHandlerV1Ptr;
/**
 * @brief Represents a structure in Libxml2
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
struct _xmlSAXHandlerV1 {
    internalSubsetSAXFunc internalSubset;				/**< */			
    isStandaloneSAXFunc isStandalone;					/**< */
    hasInternalSubsetSAXFunc hasInternalSubset;			/**< */
    hasExternalSubsetSAXFunc hasExternalSubset;			/**< */
    resolveEntitySAXFunc resolveEntity;					/**< */
    getEntitySAXFunc getEntity;							/**< */
    entityDeclSAXFunc entityDecl;						/**< */
    notationDeclSAXFunc notationDecl;					/**< */
    attributeDeclSAXFunc attributeDecl;					/**< */
    elementDeclSAXFunc elementDecl;						/**< */
    unparsedEntityDeclSAXFunc unparsedEntityDecl;		/**< */
    setDocumentLocatorSAXFunc setDocumentLocator;		/**< */
    startDocumentSAXFunc startDocument;					/**< */	
    endDocumentSAXFunc endDocument;						/**< */
    startElementSAXFunc startElement;					/**< */
    endElementSAXFunc endElement;						/**< */
    referenceSAXFunc reference;							/**< */
    charactersSAXFunc characters;						/**< */
    ignorableWhitespaceSAXFunc ignorableWhitespace;		/**< */
    processingInstructionSAXFunc processingInstruction;	/**< */
    commentSAXFunc comment;								/**< */
    warningSAXFunc warning;								/**< */
    errorSAXFunc error;									/**< */
    fatalErrorSAXFunc fatalError; /**< unused error() get all the errors */
    getParameterEntitySAXFunc getParameterEntity;		/**< */
    cdataBlockSAXFunc cdataBlock;						/**< */
    externalSubsetSAXFunc externalSubset;				/**< */
    unsigned int initialized;							/**< */
};


/**
 * xmlExternalEntityLoader:
 *
 * @param[in]	URL      The System ID of the resource requested
 * @param[in]	ID       The Public ID of the resource requested
 * @param[in]	context  The XML parser context
 *
 * External entity loaders types.
 *
 * Returns the entity input parser.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlParserInputPtr (*xmlExternalEntityLoader) (const char *URL,
					 const char *ID,
					 xmlParserCtxtPtr context);

#ifdef __cplusplus
}
#endif

#include <libxml/encoding.h>
#include <libxml/xmlIO.h>
#include <libxml/globals.h>

#ifdef __cplusplus
extern "C" {
#endif


/*
 * Init/Cleanup
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlInitParser		(void);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlCleanupParser	(void);

/*
 * Input functions
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlParserInputRead	(xmlParserInputPtr in,
					 int len);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlParserInputGrow	(xmlParserInputPtr in,
					 int len);

/*
 * Basic parsing Interfaces
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL	
		xmlParseDoc		(xmlChar *cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL	
		xmlParseMemory		(const char *buffer,
					 int size);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL	
		xmlParseFile		(const char *filename);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlSubstituteEntitiesDefault(int val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlKeepBlanksDefault	(int val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlStopParser		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlPedanticParserDefault(int val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlLineNumbersDefault	(int val);

/*
 * Recovery mode 
 *
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL	
		xmlRecoverDoc		(xmlChar *cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL	
		xmlRecoverMemory	(const char *buffer,
					 int size);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL	
		xmlRecoverFile		(const char *filename);

/*
 * Less common routines and SAX interfaces
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlParseDocument	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlParseExtParsedEnt	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL	
		xmlSAXParseDoc		(xmlSAXHandlerPtr sax,
					 xmlChar *cur,
					 int recovery);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlSAXUserParseFile	(xmlSAXHandlerPtr sax,
					 void *user_data,
					 const char *filename);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlSAXUserParseMemory	(xmlSAXHandlerPtr sax,
					 void *user_data,
					 const char *buffer,
					 int size);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL	
		xmlSAXParseMemory	(xmlSAXHandlerPtr sax,
					 const char *buffer,
                                   	 int size,
					 int recovery);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL	
		xmlSAXParseMemoryWithData (xmlSAXHandlerPtr sax,
					 const char *buffer,
                                   	 int size,
					 int recovery,
					 void *data);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL	
		xmlSAXParseFile		(xmlSAXHandlerPtr sax,
					 const char *filename,
					 int recovery);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL	
		xmlSAXParseFileWithData	(xmlSAXHandlerPtr sax,
					 const char *filename,
					 int recovery,
					 void *data);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL	
		xmlSAXParseEntity	(xmlSAXHandlerPtr sax,
					 const char *filename);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL	
		xmlParseEntity		(const char *filename);

#ifdef LIBXML_VALID_ENABLED
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDtdPtr XMLCALL	
		xmlParseDTD		(const xmlChar *ExternalID,
					 const xmlChar *SystemID);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDtdPtr XMLCALL	
		xmlSAXParseDTD		(xmlSAXHandlerPtr sax,
					 const xmlChar *ExternalID,
					 const xmlChar *SystemID);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDtdPtr XMLCALL	
		xmlIOParseDTD		(xmlSAXHandlerPtr sax,
					 xmlParserInputBufferPtr input,
					 xmlCharEncoding enc);
#endif /* LIBXML_VALID_ENABLED */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL	
		xmlParseBalancedChunkMemory(xmlDocPtr doc,
					 xmlSAXHandlerPtr sax,
					 void *user_data,
					 int depth,
					 const xmlChar *string,
					 xmlNodePtr *lst);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL          
		xmlParseBalancedChunkMemoryRecover(xmlDocPtr doc,
                     xmlSAXHandlerPtr sax,
                     void *user_data,
                     int depth,
                     const xmlChar *string,
                     xmlNodePtr *lst,
                     int recover);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlParseExternalEntity	(xmlDocPtr doc,
					 xmlSAXHandlerPtr sax,
					 void *user_data,
					 int depth,
					 const xmlChar *URL,
					 const xmlChar *ID,
					 xmlNodePtr *lst);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlParseCtxtExternalEntity(xmlParserCtxtPtr ctx,
					 const xmlChar *URL,
					 const xmlChar *ID,
					 xmlNodePtr *lst);

/*
 * Parser contexts handling.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlParserCtxtPtr XMLCALL	
		xmlNewParserCtxt	(void);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlInitParserCtxt	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlClearParserCtxt	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlFreeParserCtxt	(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSetupParserForBuffer	(xmlParserCtxtPtr ctxt,
					 const xmlChar* buffer,
					 const char *filename);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlParserCtxtPtr XMLCALL 
		xmlCreateDocParserCtxt	(const xmlChar *cur);

/*
 * Reading/setting optional parsing features.
 */
#ifdef LIBXML_LEGACY_ENABLED
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlGetFeaturesList	(int *len,
					 const char **result);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlGetFeature		(xmlParserCtxtPtr ctxt,
					 const char *name,
					 void *result);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlSetFeature		(xmlParserCtxtPtr ctxt,
					 const char *name,
					 void *value);
#endif /* LIBXML_LEGACY_ENABLED */

#ifdef LIBXML_PUSH_ENABLED
/*
 * Interfaces for the Push mode.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
 XMLPUBFUN xmlParserCtxtPtr XMLCALL 
		xmlCreatePushParserCtxt(xmlSAXHandlerPtr sax,
					 void *user_data,
					 const char *chunk,
					 int size,
					 const char *filename);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
 XMLPUBFUN int XMLCALL		 
		xmlParseChunk		(xmlParserCtxtPtr ctxt,
					 const char *chunk,
					 int size,
					 int terminate);
#endif /* LIBXML_PUSH_ENABLED */

/*
 * Special I/O mode.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlParserCtxtPtr XMLCALL 
		xmlCreateIOParserCtxt	(xmlSAXHandlerPtr sax,
					 void *user_data,
					 xmlInputReadCallback   ioread,
					 xmlInputCloseCallback  ioclose,
					 void *ioctx,
					 xmlCharEncoding enc);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlParserInputPtr XMLCALL 
		xmlNewIOInputStream	(xmlParserCtxtPtr ctxt,
					 xmlParserInputBufferPtr input,
					 xmlCharEncoding enc);

/*
 * Node info.
 */
 
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN const xmlParserNodeInfo* XMLCALL
		xmlParserFindNodeInfo	(const xmlParserCtxtPtr ctxt,
				         const xmlNodePtr node);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlInitNodeInfoSeq	(xmlParserNodeInfoSeqPtr seq);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlClearNodeInfoSeq	(xmlParserNodeInfoSeqPtr seq);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN unsigned long XMLCALL 
		xmlParserFindNodeInfoIndex(const xmlParserNodeInfoSeqPtr seq,
                                         const xmlNodePtr node);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlParserAddNodeInfo	(xmlParserCtxtPtr ctxt,
					 const xmlParserNodeInfoPtr info);

/*
 * External entities handling actually implemented in xmlIO.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlSetExternalEntityLoader(xmlExternalEntityLoader f);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlExternalEntityLoader XMLCALL
		xmlGetExternalEntityLoader(void);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlParserInputPtr XMLCALL
		xmlLoadExternalEntity	(const char *URL,
					 const char *ID,
					 xmlParserCtxtPtr ctxt);

/*
 * Index lookup, actually implemented in the encoding module
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN long XMLCALL
		xmlByteConsumed		(xmlParserCtxtPtr ctxt);

/**
 * @enum xmlParserOption
 *
 * This is the set of XML parser options that can be passed down
 * to the xmlReadDoc() and similar calls.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef enum {
    XML_PARSE_RECOVER	= 1<<0,	/**< recover on errors */
    XML_PARSE_NOENT	= 1<<1,	/**< substitute entities */
    XML_PARSE_DTDLOAD	= 1<<2,	/**< load the external subset */
    XML_PARSE_DTDATTR	= 1<<3,	/**< default DTD attributes */
    XML_PARSE_DTDVALID	= 1<<4,	/**< validate with the DTD */
    XML_PARSE_NOERROR	= 1<<5,	/**< suppress error reports */
    XML_PARSE_NOWARNING	= 1<<6,	/**< suppress warning reports */
    XML_PARSE_PEDANTIC	= 1<<7,	/**< pedantic error reporting */
    XML_PARSE_NOBLANKS	= 1<<8,	/**< remove blank nodes */
    XML_PARSE_SAX1	= 1<<9,	/**< use the SAX1 interface internally */
    XML_PARSE_XINCLUDE	= 1<<10,/**< Implement XInclude substitution.  */
    XML_PARSE_NONET	= 1<<11,/**< Forbid network access */
    XML_PARSE_NODICT	= 1<<12,/**< Do not reuse the context dictionary */
    XML_PARSE_NSCLEAN	= 1<<13,/**< remove redundant namespaces declarations */
    XML_PARSE_NOCDATA	= 1<<14 /**< merge CDATA as text nodes */
} xmlParserOption;

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL
		xmlCtxtReset		(xmlParserCtxtPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL
		xmlCtxtResetPush	(xmlParserCtxtPtr ctxt,
					 const char *chunk,
					 int size,
					 const char *filename,
					 const char *encoding);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL
		xmlCtxtUseOptions	(xmlParserCtxtPtr ctxt,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL
		xmlReadDoc		(const xmlChar *cur,
					 const char *URL,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL
		xmlReadFile		(const char *URL,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL
		xmlReadMemory		(const char *buffer,
					 int size,
					 const char *URL,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL
		xmlReadIO		(xmlInputReadCallback ioread,
					 xmlInputCloseCallback ioclose,
					 void *ioctx,
					 const char *URL,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL
		xmlCtxtReadDoc		(xmlParserCtxtPtr ctxt,
					 const xmlChar *cur,
					 const char *URL,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL
		xmlCtxtReadFile		(xmlParserCtxtPtr ctxt,
					 const char *filename,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL
		xmlCtxtReadMemory		(xmlParserCtxtPtr ctxt,
					 const char *buffer,
					 int size,
					 const char *URL,
					 const char *encoding,
					 int options);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlDocPtr XMLCALL
		xmlCtxtReadIO		(xmlParserCtxtPtr ctxt,
					 xmlInputReadCallback ioread,
					 xmlInputCloseCallback ioclose,
					 void *ioctx,
					 const char *URL,
					 const char *encoding,
					 int options);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif
#endif /* __XML_PARSER_H__ */

