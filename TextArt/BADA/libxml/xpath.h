/* $Change: 1114438 $ */
/**
 * Summary: XML Path Language implementation
 * Description: API for the XML Path Language implementation
 *
 * XML Path Language implementation
 * XPath is a language for addressing parts of an XML document,
 * designed to be used by both XSLT and XPointer
 *     http://www.w3.org/TR/xpath
 *
 * Implements
 * W3C Recommendation 16 November 1999
 *     http://www.w3.org/TR/1999/REC-xpath-19991116
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

 /**
 * @file		xpath.h
 * @brief	This is the header file for libxml
 *
 *
 */

#ifndef __XML_XPATH_H__
#define __XML_XPATH_H__

#include <libxml/xmlversion.h>
#include <libxml/xmlerror.h>
#include <libxml/tree.h>
#include <libxml/hash.h>

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
typedef struct _xmlXPathContext xmlXPathContext;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlXPathContext *xmlXPathContextPtr;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef struct _xmlXPathParserContext xmlXPathParserContext;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlXPathParserContext *xmlXPathParserContextPtr;

/**
 * @enum xmlXPathError 
 * The set of XPath error codes.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

typedef enum {
    XPATH_EXPRESSION_OK = 0,/**< */
    XPATH_NUMBER_ERROR,/**< */
    XPATH_UNFINISHED_LITERAL_ERROR,/**< */
    XPATH_START_LITERAL_ERROR,/**< */
    XPATH_VARIABLE_REF_ERROR,/**< */
    XPATH_UNDEF_VARIABLE_ERROR,/**< */
    XPATH_INVALID_PREDICATE_ERROR,/**< */
    XPATH_EXPR_ERROR,/**< */
    XPATH_UNCLOSED_ERROR,/**< */
    XPATH_UNKNOWN_FUNC_ERROR,/**< */
    XPATH_INVALID_OPERAND,/**< */
    XPATH_INVALID_TYPE,/**< */
    XPATH_INVALID_ARITY,/**< */
    XPATH_INVALID_CTXT_SIZE,/**< */
    XPATH_INVALID_CTXT_POSITION,/**< */
    XPATH_MEMORY_ERROR,/**< */
    XPTR_SYNTAX_ERROR,/**< */
    XPTR_RESOURCE_ERROR,/**< */
    XPTR_SUB_RESOURCE_ERROR,/**< */
    XPATH_UNDEF_PREFIX_ERROR,/**< */
    XPATH_ENCODING_ERROR,/**< */
    XPATH_INVALID_CHAR_ERROR /**< */
} xmlXPathError;

/**
 * A node-set (an unordered collection of nodes without duplicates).
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

typedef struct _xmlNodeSet xmlNodeSet;
 /**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlNodeSet *xmlNodeSetPtr;
/**
 * @brief Represents a structure in Libxml2
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
struct _xmlNodeSet {
    int nodeNr;			/**< number of nodes in the set */
    int nodeMax;		/**< size of the array as allocated */
    xmlNodePtr *nodeTab;	/**< array of nodes in no particular order */
    /* @@ with_ns to check whether namespace nodes should be looked at @@ */
};

/**
 * @enum xmlXPathObjectType
 * 
 * An expression is evaluated to yield an object, which
 * has one of the following four basic types:
 *   - node-set
 *   - boolean
 *   - number
 *   - string
 *
 * @@ XPointer will add more types !
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 * @since 1.0
 */

typedef enum {
    XPATH_UNDEFINED = 0,/**< */
    XPATH_NODESET = 1,/**< */
    XPATH_BOOLEAN = 2,/**< */
    XPATH_NUMBER = 3,/**< */
    XPATH_STRING = 4,/**< */
    XPATH_POINT = 5,/**< */
    XPATH_RANGE = 6,/**< */
    XPATH_LOCATIONSET = 7,/**< */
    XPATH_USERS = 8,/**< */
    XPATH_XSLT_TREE = 9  /**< An XSLT value tree, non modifiable */
} xmlXPathObjectType;

typedef struct _xmlXPathObject xmlXPathObject;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlXPathObject *xmlXPathObjectPtr;
/**
 * @brief Represents a structure in Libxml2
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
struct _xmlXPathObject {
    xmlXPathObjectType type;	/**< */
    xmlNodeSetPtr nodesetval;	/**< */
    int boolval;				/**< */
    double floatval;			/**< */
    xmlChar *stringval;			/**< */
    void *user;					/**< */
    int index;					/**< */
    void *user2;				/**< */
    int index2;					/**< */
};

/**
 * xmlXPathConvertFunc:
 * @param[in]	obj		an XPath object
 * @param[in]	type	the number of the target type
 *
 * A conversion function is associated to a type and used to cast
 * the new type to primitive values.
 *
 * Returns -1 in case of error, 0 otherwise
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef int (*xmlXPathConvertFunc) (xmlXPathObjectPtr obj, int type);

/*
 * Extra type: a name and a conversion function.
 */
 
 
 /** For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef struct _xmlXPathType xmlXPathType;

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlXPathType *xmlXPathTypePtr;
/**
 * @brief Represents a structure in Libxml2
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
struct _xmlXPathType {
    const xmlChar         *name;	/**< the type name */
    xmlXPathConvertFunc func;		/**< the conversion function */
};

/*
 * Extra variable: a name and a value.
 */
 /**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef struct _xmlXPathVariable xmlXPathVariable;

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlXPathVariable *xmlXPathVariablePtr;
/**
 * @brief Represents a structure in Libxml2
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
struct _xmlXPathVariable {
    const xmlChar       *name;		/**< the variable name */
    xmlXPathObjectPtr value;		/**< the value */
};

/**
 * xmlXPathEvalFunc:
 * @param[in]	ctxt	an XPath parser context
 * @param[in]	nargs	the number of arguments passed to the function
 *
 * An XPath evaluation function, the parameters are on the XPath context stack.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

typedef void (*xmlXPathEvalFunc)(xmlXPathParserContextPtr ctxt,
	                         int nargs);

/*
 * Extra function: a name and a evaluation function.
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef struct _xmlXPathFunct xmlXPathFunct;
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlXPathFunct *xmlXPathFuncPtr;
/**
 * @brief Represents a structure in Libxml2
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
struct _xmlXPathFunct {
    const xmlChar      *name;	/**< the function name */
    xmlXPathEvalFunc func;		/**< the evaluation function */
};

/**
 * xmlXPathAxisFunc:
 * @param[in]	ctxt	the XPath interpreter context
 * @param[in]	cur		the previous node being explored on that axis
 *
 * An axis traversal function. To traverse an axis, the engine calls
 * the first time with cur == NULL and repeat until the function returns
 * NULL indicating the end of the axis traversal.
 *
 * Returns the next node in that axis or NULL if at the end of the axis.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

typedef xmlXPathObjectPtr (*xmlXPathAxisFunc) (xmlXPathParserContextPtr ctxt,
				 xmlXPathObjectPtr cur);

/*
 * Extra axis: a name and an axis function.
 */

 /**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef struct _xmlXPathAxis xmlXPathAxis;
 /**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlXPathAxis *xmlXPathAxisPtr;
/**
 * @brief Represents a structure in Libxml2
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
struct _xmlXPathAxis {
    const xmlChar      *name;	/**< the axis name */
    xmlXPathAxisFunc func;		/**< the search function */
};

/**
 * @brief Represents a structure in Libxml2
 *
 * xmlXPathContext:
 *
 * Expression evaluation occurs with respect to a context.
 * The context consists of:
 *    - a node (the context node) 
 *    - a node list (the context node list) 
 *    - a set of variable bindings 
 *    - a function library 
 *    - the set of namespace declarations in scope for the expression 
 * Following the switch to hash tables, this need to be trimmed up at
 * the next binary incompatible release.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

struct _xmlXPathContext {
    xmlDocPtr doc;					/**< The current document */
    xmlNodePtr node;				/**< The current node */

    int nb_variables_unused;		/**< unused (hash table) */
    int max_variables_unused;		/**< unused (hash table) */
    xmlHashTablePtr varHash;		/**< Hash table of defined variables */

    int nb_types;					/**< number of defined types */
    int max_types;					/**< max number of types */
    xmlXPathTypePtr types;			/**< Array of defined types */

    int nb_funcs_unused;			/**< unused (hash table) */
    int max_funcs_unused;			/**< unused (hash table) */
    xmlHashTablePtr funcHash;		/**< Hash table of defined funcs */

    int nb_axis;					/**< number of defined axis */
    int max_axis;					/**< max number of axis */
    xmlXPathAxisPtr axis;			/**< Array of defined axis */

    /* the namespace nodes of the context node */
    xmlNsPtr *namespaces;			/**< Array of namespaces */
    int nsNr;						/**< number of namespace in scope */
    void *user;						/**< function to free */

    /* extra variables */
    int contextSize;				/**< the context size */
    int proximityPosition;			/**< the proximity position */

    /* extra stuff for XPointer */
    int xptr;						/**< it this an XPointer context */
    xmlNodePtr here;				/**< for here() */
    xmlNodePtr origin;				/**< for origin() */

    /* the set of namespace declarations in scope for the expression */
    xmlHashTablePtr nsHash;			/**< The namespaces hash table */
    void *varLookupFunc;			/**< variable lookup func */
    void *varLookupData;			/**< variable lookup data */

    /* Possibility to link in an extra item */
    void *extra;                    /**< needed for XSLT */

    /* The function name and URI when calling a function */
    const xmlChar *function;
    const xmlChar *functionURI;

    /* function lookup function and data */
    void *funcLookupFunc;			/**< function lookup func */
    void *funcLookupData;			/**< function lookup data */

    /* temporary namespace lists kept for walking the namespace axis */
    xmlNsPtr *tmpNsList;			/**< Array of namespaces */
    int tmpNsNr;					/**< number of namespace in scope */

    /* error reporting mechanism */
    void *userData;                 /**< user specific data block */
    xmlStructuredErrorFunc error;   /**< the callback in case of errors */
    xmlError lastError;				/**< the last error */
    xmlNodePtr debugNode;			/**< the source node XSLT */

    /* dictionary */
    xmlDictPtr dict;				/**< dictionary if any */
};

/*
 * The structure of a compiled expression form is not public.
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef struct _xmlXPathCompExpr xmlXPathCompExpr;
 /**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlXPathCompExpr *xmlXPathCompExprPtr;

/**
 * @brief Represents a structure in Libxml2
 *
 * xmlXPathParserContext:
 *
 * An XPath parser context. It contains pure parsing information,
 * an xmlXPathContext, and the stack of objects.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
struct _xmlXPathParserContext {
    const xmlChar *cur;				/**< the current char being parsed */
    const xmlChar *base;			/**< the full expression */

    int error;						/**< error code */

    xmlXPathContextPtr  context;	/**< the evaluation context */
    xmlXPathObjectPtr     value;	/**< the current value */
    int                 valueNr;	/**< number of values stacked */
    int                valueMax;	/**< max number of values stacked */
    xmlXPathObjectPtr *valueTab;	/**< stack of values */

    xmlXPathCompExprPtr comp;		/**< the precompiled expression */
    int xptr;						/**< it this an XPointer expression */
    xmlNodePtr         ancestor;	/**< used for walking preceding axis */
};

/**
 * xmlXPathFunction:
 * @param[in]	ctxt	the XPath interpretation context
 * @param[in]	nargs	the number of arguments
 *
 * An XPath function.
 * The arguments (if any) are popped out from the context stack
 * and the result is pushed on the stack.
*
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */

typedef void (*xmlXPathFunction) (xmlXPathParserContextPtr ctxt, int nargs);

/************************************************************************
 *									*
 *			Public API					*
 *									*
 ************************************************************************/

/*
 * Objects and Nodesets handling
 */

/*
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBVAR double xmlXPathNAN;
/*
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBVAR double xmlXPathPINF;
/*
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBVAR double xmlXPathNINF;

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL
		xmlXPathIsNaN	(double val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL
		xmlXPathIsInf	(double val);

/* These macros may later turn into functions */
/*
 * xmlXPathNodeSetGetLength:
 * @ns:  a node-set
 *
 * Implement a functionality similar to the DOM NodeList.length.
 *
 * Returns the number of nodes in the node-set.
 */
#define xmlXPathNodeSetGetLength(ns) ((ns) ? (ns)->nodeNr : 0)
/*
 * xmlXPathNodeSetItem:
 * @ns:  a node-set
 * @index:  index of a node in the set
 *
 * Implements a functionality similar to the DOM NodeList.item().
 *
 * Returns the xmlNodePtr at the given @index in @ns or NULL if
 *         @index is out of range (0 to length-1)
 */
#define xmlXPathNodeSetItem(ns, index)				\
		((((ns) != NULL) && 				\
		  ((index) >= 0) && ((index) < (ns)->nodeNr)) ?	\
		 (ns)->nodeTab[(index)]				\
		 : NULL)
/*
 * xmlXPathNodeSetIsEmpty:
 * @ns: a node-set
 *
 * Checks whether @ns is empty or not.
 *
 * Returns %TRUE if @ns is an empty node-set.
 */
#define xmlXPathNodeSetIsEmpty(ns)                                      \
    (((ns) == NULL) || ((ns)->nodeNr == 0) || ((ns)->nodeTab == NULL))


/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		   
		    xmlXPathFreeObject		(xmlXPathObjectPtr obj);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodeSetPtr XMLCALL	   
		    xmlXPathNodeSetCreate	(xmlNodePtr val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		   
		    xmlXPathFreeNodeSetList	(xmlXPathObjectPtr obj);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		   
		    xmlXPathFreeNodeSet		(xmlNodeSetPtr obj);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL  
		    xmlXPathObjectCopy		(xmlXPathObjectPtr val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		   
		    xmlXPathCmpNodes		(xmlNodePtr node1,
						 xmlNodePtr node2);
/*
 * Conversion functions to basic types.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		   
		    xmlXPathCastNumberToBoolean	(double val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		   
		    xmlXPathCastStringToBoolean	(const xmlChar * val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		   
		    xmlXPathCastNodeSetToBoolean(xmlNodeSetPtr ns);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		   
		    xmlXPathCastToBoolean	(xmlXPathObjectPtr val);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN double XMLCALL		   
		    xmlXPathCastBooleanToNumber	(int val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN double XMLCALL		   
		    xmlXPathCastStringToNumber	(const xmlChar * val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN double XMLCALL		   
		    xmlXPathCastNodeToNumber	(xmlNodePtr node);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN double XMLCALL		   
		    xmlXPathCastNodeSetToNumber	(xmlNodeSetPtr ns);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN double XMLCALL		   
		    xmlXPathCastToNumber	(xmlXPathObjectPtr val);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL	   
		    xmlXPathCastBooleanToString	(int val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL	   
		    xmlXPathCastNumberToString	(double val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL	   
		    xmlXPathCastNodeToString	(xmlNodePtr node);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL	   
		    xmlXPathCastNodeSetToString	(xmlNodeSetPtr ns);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL	   
		    xmlXPathCastToString	(xmlXPathObjectPtr val);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL  
		    xmlXPathConvertBoolean	(xmlXPathObjectPtr val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL  
		    xmlXPathConvertNumber	(xmlXPathObjectPtr val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL  
		    xmlXPathConvertString	(xmlXPathObjectPtr val);

/*
 * Context handling.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		   
		    xmlXPathInit		(void);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathContextPtr XMLCALL 
		    xmlXPathNewContext		(xmlDocPtr doc);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		   
		    xmlXPathFreeContext		(xmlXPathContextPtr ctxt);

/*
 * Evaluation functions.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN long XMLCALL               
		    xmlXPathOrderDocElems	(xmlDocPtr doc);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL  
		    xmlXPathEval		(const xmlChar *str,
						 xmlXPathContextPtr ctx);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL  
		    xmlXPathEvalExpression	(const xmlChar *str,
						 xmlXPathContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL                
		    xmlXPathEvalPredicate	(xmlXPathContextPtr ctxt,
						 xmlXPathObjectPtr res);
/*
 * Separate compilation/evaluation entry points.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathCompExprPtr XMLCALL 
		    xmlXPathCompile		(const xmlChar *str);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathCompExprPtr XMLCALL 
		    xmlXPathCtxtCompile		(xmlXPathContextPtr ctxt,
		    				 const xmlChar *str);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL   
		    xmlXPathCompiledEval	(xmlXPathCompExprPtr comp,
						 xmlXPathContextPtr ctx);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL                
		    xmlXPathFreeCompExpr	(xmlXPathCompExprPtr comp);

/**
 * @}
 */
 
#ifdef __cplusplus
}
#endif
#endif /* ! __XML_XPATH_H__ */
