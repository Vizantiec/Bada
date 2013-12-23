/* $Change: 1114438 $ */
/**
 * Summary: internal interfaces for XML Path Language implementation
 * Description: internal interfaces for XML Path Language implementation
 *              used to build new modules on top of XPath like XPointer and
 *              XSLT
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

 /**
 * @file		xpathInternals.h
 * @brief	This is the header file for libxml
 *
 *
 */

#ifndef __XML_XPATH_INTERNALS_H__
#define __XML_XPATH_INTERNALS_H__

#include <libxml/xmlversion.h>
#include <libxml/xpath.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup libxml2
 * 
 * @{
 */
 
/************************************************************************
 *									*
 *			Helpers						*
 *									*
 ************************************************************************/

/*
 * Many of these macros may later turn into functions. They
 * shouldn't be used in #ifdef's preprocessor instructions.
 */
/*
 * xmlXPathSetError:
 * @ctxt:  an XPath parser context
 * @err:  an xmlXPathError code
 *
 * Raises an error.
 */
#define xmlXPathSetError(ctxt, err)					\
    { xmlXPatherror((ctxt), __FILE__, __LINE__, (err));			\
      (ctxt)->error = (err); }

/*
 * xmlXPathSetArityError:
 * @ctxt:  an XPath parser context
 *
 * Raises an XPATH_INVALID_ARITY error.
 */
#define xmlXPathSetArityError(ctxt)					\
    xmlXPathSetError((ctxt), XPATH_INVALID_ARITY)

/*
 * xmlXPathSetTypeError:
 * @ctxt:  an XPath parser context
 *
 * Raises an XPATH_INVALID_TYPE error.
 */
#define xmlXPathSetTypeError(ctxt)					\
    xmlXPathSetError((ctxt), XPATH_INVALID_TYPE)

/*
 * xmlXPathGetError:
 * @ctxt:  an XPath parser context
 *
 * Get the error code of an XPath context.
 *
 * Returns the context error.
 */
#define xmlXPathGetError(ctxt)	  ((ctxt)->error)

/*
 * xmlXPathCheckError:
 * @ctxt:  an XPath parser context
 *
 * Check if an XPath error was raised.
 *
 * Returns true if an error has been raised, false otherwise.
 */
#define xmlXPathCheckError(ctxt)  ((ctxt)->error != XPATH_EXPRESSION_OK)

/*
 * xmlXPathGetDocument:
 * @ctxt:  an XPath parser context
 *
 * Get the document of an XPath context.
 *
 * Returns the context document.
 */
#define xmlXPathGetDocument(ctxt)	((ctxt)->context->doc)

/*
 * xmlXPathGetContextNode:
 * @ctxt: an XPath parser context
 *
 * Get the context node of an XPath context.
 *
 * Returns the context node.
 */
#define xmlXPathGetContextNode(ctxt)	((ctxt)->context->node)

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlXPathPopBoolean	(xmlXPathParserContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN double XMLCALL		
    		xmlXPathPopNumber	(xmlXPathParserContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL	
    		xmlXPathPopString	(xmlXPathParserContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodeSetPtr XMLCALL	
    		xmlXPathPopNodeSet	(xmlXPathParserContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void * XMLCALL		
    		xmlXPathPopExternal	(xmlXPathParserContextPtr ctxt);

/*
 * xmlXPathReturnBoolean:
 * @ctxt:  an XPath parser context
 * @val:  a boolean
 *
 * Pushes the boolean @val on the context stack.
 */
#define xmlXPathReturnBoolean(ctxt, val)				\
    valuePush((ctxt), xmlXPathNewBoolean(val))

/*
 * xmlXPathReturnTrue:
 * @ctxt:  an XPath parser context
 *
 * Pushes true on the context stack.
 */
#define xmlXPathReturnTrue(ctxt)   xmlXPathReturnBoolean((ctxt), 1)

/*
 * xmlXPathReturnFalse:
 * @ctxt:  an XPath parser context
 *
 * Pushes false on the context stack.
 */
#define xmlXPathReturnFalse(ctxt)  xmlXPathReturnBoolean((ctxt), 0)

/*
 * xmlXPathReturnNumber:
 * @ctxt:  an XPath parser context
 * @val:  a double
 *
 * Pushes the double @val on the context stack.
 */
#define xmlXPathReturnNumber(ctxt, val)					\
    valuePush((ctxt), xmlXPathNewFloat(val))

/*
 * xmlXPathReturnString:
 * @ctxt:  an XPath parser context
 * @str:  a string
 *
 * Pushes the string @str on the context stack.
 */
#define xmlXPathReturnString(ctxt, str)					\
    valuePush((ctxt), xmlXPathWrapString(str))

/*
 * xmlXPathReturnEmptyString:
 * @ctxt:  an XPath parser context
 *
 * Pushes an empty string on the stack.
 */
#define xmlXPathReturnEmptyString(ctxt)					\
    valuePush((ctxt), xmlXPathNewCString(""))

/*
 * xmlXPathReturnNodeSet:
 * @ctxt:  an XPath parser context
 * @ns:  a node-set
 *
 * Pushes the node-set @ns on the context stack.
 */
#define xmlXPathReturnNodeSet(ctxt, ns)					\
    valuePush((ctxt), xmlXPathWrapNodeSet(ns))

/*
 * xmlXPathReturnEmptyNodeSet:
 * @ctxt:  an XPath parser context
 *
 * Pushes an empty node-set on the context stack.
 */
#define xmlXPathReturnEmptyNodeSet(ctxt)				\
    valuePush((ctxt), xmlXPathNewNodeSet(NULL))

/*
 * xmlXPathReturnExternal:
 * @ctxt:  an XPath parser context
 * @val:  user data
 *
 * Pushes user data on the context stack.
 */
#define xmlXPathReturnExternal(ctxt, val)				\
    valuePush((ctxt), xmlXPathWrapExternal(val))

/*
 * xmlXPathStackIsNodeSet:
 * @ctxt: an XPath parser context
 *
 * Check if the current value on the XPath stack is a node set or
 * an XSLT value tree.
 *
 * Returns true if the current object on the stack is a node-set.
 */
#define xmlXPathStackIsNodeSet(ctxt)					\
    (((ctxt)->value != NULL)						\
     && (((ctxt)->value->type == XPATH_NODESET)				\
         || ((ctxt)->value->type == XPATH_XSLT_TREE)))

/*
 * xmlXPathStackIsExternal:
 * @ctxt: an XPath parser context
 *
 * Checks if the current value on the XPath stack is an external
 * object.
 *
 * Returns true if the current object on the stack is an external
 * object.
 */
#define xmlXPathStackIsExternal(ctxt)					\
	((ctxt->value != NULL) && (ctxt->value->type == XPATH_USERS))

/*
 * xmlXPathEmptyNodeSet:
 * @ns:  a node-set
 *
 * Empties a node-set.
 */
#define xmlXPathEmptyNodeSet(ns)					\
    { while ((ns)->nodeNr > 0) (ns)->nodeTab[(ns)->nodeNr--] = NULL; }

/*
 * CHECK_ERROR:
 *
 * Macro to return from the function if an XPath error was detected.
 */
#define CHECK_ERROR							\
    if (ctxt->error != XPATH_EXPRESSION_OK) return

/*
 * CHECK_ERROR0:
 *
 * Macro to return 0 from the function if an XPath error was detected.
 */
#define CHECK_ERROR0							\
    if (ctxt->error != XPATH_EXPRESSION_OK) return(0)

/*
 * XP_ERROR:
 * @X:  the error code
 *
 * Macro to raise an XPath error and return.
 */
#define XP_ERROR(X)							\
    { xmlXPathErr(ctxt, X); return; }

/*
 * XP_ERROR0:
 * @X:  the error code
 *
 * Macro to raise an XPath error and return 0.
 */
#define XP_ERROR0(X)							\
    { xmlXPathErr(ctxt, X); return(0); }

/*
 * CHECK_TYPE:
 * @typeval:  the XPath type
 *
 * Macro to check that the value on top of the XPath stack is of a given
 * type.
 */
#define CHECK_TYPE(typeval)						\
    if ((ctxt->value == NULL) || (ctxt->value->type != typeval))	\
        XP_ERROR(XPATH_INVALID_TYPE)

/*
 * CHECK_TYPE0:
 * @typeval:  the XPath type
 *
 * Macro to check that the value on top of the XPath stack is of a given
 * type. Return(0) in case of failure
 */
#define CHECK_TYPE0(typeval)						\
    if ((ctxt->value == NULL) || (ctxt->value->type != typeval))	\
        XP_ERROR0(XPATH_INVALID_TYPE)

/*
 * CHECK_ARITY:
 * @x:  the number of expected args
 *
 * Macro to check that the number of args passed to an XPath function matches.
 */
#define CHECK_ARITY(x)							\
    if (nargs != (x))							\
        XP_ERROR(XPATH_INVALID_ARITY);

/*
 * CAST_TO_STRING:
 *
 * Macro to try to cast the value on the top of the XPath stack to a string.
 */
#define CAST_TO_STRING							\
    if ((ctxt->value != NULL) && (ctxt->value->type != XPATH_STRING))	\
        xmlXPathStringFunction(ctxt, 1);

/*
 * CAST_TO_NUMBER:
 *
 * Macro to try to cast the value on the top of the XPath stack to a number.
 */
#define CAST_TO_NUMBER							\
    if ((ctxt->value != NULL) && (ctxt->value->type != XPATH_NUMBER))	\
        xmlXPathNumberFunction(ctxt, 1);

/*
 * CAST_TO_BOOLEAN:
 *
 * Macro to try to cast the value on the top of the XPath stack to a boolean.
 */
#define CAST_TO_BOOLEAN							\
    if ((ctxt->value != NULL) && (ctxt->value->type != XPATH_BOOLEAN))	\
        xmlXPathBooleanFunction(ctxt, 1);

/*
 * Variable Lookup forwarding.
 */
/**
 * xmlXPathVariableLookupFunc:
 * @param[in]	ctxt	an XPath context
 * @param[in]	name	name of the variable
 * @param[in]	s_uri	the namespace name hosting this variable
 *
 * Prototype for callbacks used to plug variable lookup in the XPath
 * engine.
 *
 * Returns the XPath object value or NULL if not found.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlXPathObjectPtr (*xmlXPathVariableLookupFunc) (void *ctxt,
					 const xmlChar *name,
					 const xmlChar *ns_uri);

/**
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL	
	xmlXPathRegisterVariableLookup	(xmlXPathContextPtr ctxt,
					 xmlXPathVariableLookupFunc f,
					 void *data);

/*
 * Function Lookup forwarding.
 */
/**
 * xmlXPathFuncLookupFunc:
 * @param[in]	ctxt	an XPath context
 * @param[in]	name	name of the function
 * @param[in]	ns_uri	the namespace name hosting this function
 *
 * Prototype for callbacks used to plug function lookup in the XPath
 * engine.
 *
 * Returns the XPath function or NULL if not found.
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
typedef xmlXPathFunction (*xmlXPathFuncLookupFunc) (void *ctxt,
					 const xmlChar *name,
					 const xmlChar *ns_uri);

/**
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL	
	    xmlXPathRegisterFuncLookup	(xmlXPathContextPtr ctxt,
					 xmlXPathFuncLookupFunc f,
					 void *funcCtxt);

/*
 * Error reporting.
 */
/**
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlXPatherror	(xmlXPathParserContextPtr ctxt,
				 const char *file,
				 int line,
				 int no);

/**
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL
		xmlXPathErr	(xmlXPathParserContextPtr ctxt,
				 int error);

#ifdef LIBXML_DEBUG_ENABLED
/**
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
		xmlXPathDebugDumpObject	(FILE *output,
					 xmlXPathObjectPtr cur,
					 int depth);
/**
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		
	    xmlXPathDebugDumpCompExpr(FILE *output,
					 xmlXPathCompExprPtr comp,
					 int depth);
#endif
/**
 * NodeSet handling.
 */

/**
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlXPathNodeSetContains		(xmlNodeSetPtr cur,
						 xmlNodePtr val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodeSetPtr XMLCALL	
		xmlXPathDifference		(xmlNodeSetPtr nodes1,
						 xmlNodeSetPtr nodes2);
/**
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodeSetPtr XMLCALL	
		xmlXPathIntersection		(xmlNodeSetPtr nodes1,
						 xmlNodeSetPtr nodes2);

/**
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodeSetPtr XMLCALL	
		xmlXPathDistinctSorted		(xmlNodeSetPtr nodes);
/**
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodeSetPtr XMLCALL	
		xmlXPathDistinct		(xmlNodeSetPtr nodes);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		
		xmlXPathHasSameNodes		(xmlNodeSetPtr nodes1,
						 xmlNodeSetPtr nodes2);

/**
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodeSetPtr XMLCALL	
		xmlXPathNodeLeadingSorted	(xmlNodeSetPtr nodes,
						 xmlNodePtr node);
/**
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodeSetPtr XMLCALL	
		xmlXPathLeadingSorted		(xmlNodeSetPtr nodes1,
						 xmlNodeSetPtr nodes2);
/**
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodeSetPtr XMLCALL	
		xmlXPathNodeLeading		(xmlNodeSetPtr nodes,
						 xmlNodePtr node);
/**
 *
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodeSetPtr XMLCALL	
		xmlXPathLeading			(xmlNodeSetPtr nodes1,
						 xmlNodeSetPtr nodes2);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodeSetPtr XMLCALL	
		xmlXPathNodeTrailingSorted	(xmlNodeSetPtr nodes,
						 xmlNodePtr node);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodeSetPtr XMLCALL	
		xmlXPathTrailingSorted		(xmlNodeSetPtr nodes1,
						 xmlNodeSetPtr nodes2);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodeSetPtr XMLCALL	
		xmlXPathNodeTrailing		(xmlNodeSetPtr nodes,
						 xmlNodePtr node);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodeSetPtr XMLCALL	
		xmlXPathTrailing		(xmlNodeSetPtr nodes1,
						 xmlNodeSetPtr nodes2);


/**
 * Extending a context.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		   
		xmlXPathRegisterNs		(xmlXPathContextPtr ctxt,
						 const xmlChar *prefix,
						 const xmlChar *ns_uri);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN const xmlChar * XMLCALL	   
		xmlXPathNsLookup		(xmlXPathContextPtr ctxt,
						 const xmlChar *prefix);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		   
		xmlXPathRegisteredNsCleanup	(xmlXPathContextPtr ctxt);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		   
		xmlXPathRegisterFunc		(xmlXPathContextPtr ctxt,
						 const xmlChar *name,
						 xmlXPathFunction f);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		   
		xmlXPathRegisterFuncNS		(xmlXPathContextPtr ctxt,
						 const xmlChar *name,
						 const xmlChar *ns_uri,
						 xmlXPathFunction f);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		   
		xmlXPathRegisterVariable	(xmlXPathContextPtr ctxt,
						 const xmlChar *name,
						 xmlXPathObjectPtr value);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		   
		xmlXPathRegisterVariableNS	(xmlXPathContextPtr ctxt,
						 const xmlChar *name,
						 const xmlChar *ns_uri,
						 xmlXPathObjectPtr value);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathFunction XMLCALL   
		xmlXPathFunctionLookup		(xmlXPathContextPtr ctxt,
						 const xmlChar *name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathFunction XMLCALL   
		xmlXPathFunctionLookupNS	(xmlXPathContextPtr ctxt,
						 const xmlChar *name,
						 const xmlChar *ns_uri);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		   
		xmlXPathRegisteredFuncsCleanup	(xmlXPathContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL  
		xmlXPathVariableLookup		(xmlXPathContextPtr ctxt,
						 const xmlChar *name);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL  
		xmlXPathVariableLookupNS	(xmlXPathContextPtr ctxt,
						 const xmlChar *name,
						 const xmlChar *ns_uri);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		   
		xmlXPathRegisteredVariablesCleanup(xmlXPathContextPtr ctxt);

/**
 * Utilities to extend XPath.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathParserContextPtr XMLCALL
		  xmlXPathNewParserContext	(const xmlChar *str,
			  			 xmlXPathContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		  
		xmlXPathFreeParserContext	(xmlXPathParserContextPtr ctxt);

/* TODO: remap to xmlXPathValuePop and Push. */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL 
		valuePop			(xmlXPathParserContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL		  
		valuePush			(xmlXPathParserContextPtr ctxt,
					 	 xmlXPathObjectPtr value);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL 
		xmlXPathNewString		(const xmlChar *val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL 
		xmlXPathNewCString		(const char *val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL 
		xmlXPathWrapString		(xmlChar *val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL 
		xmlXPathWrapCString		(char * val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL 
		xmlXPathNewFloat		(double val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL 
		xmlXPathNewBoolean		(int val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL 
		xmlXPathNewNodeSet		(xmlNodePtr val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL 
		xmlXPathNewValueTree		(xmlNodePtr val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		  
		xmlXPathNodeSetAdd		(xmlNodeSetPtr cur,
						 xmlNodePtr val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL              
		xmlXPathNodeSetAddUnique	(xmlNodeSetPtr cur,
						 xmlNodePtr val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		  
		xmlXPathNodeSetAddNs		(xmlNodeSetPtr cur, 
						 xmlNodePtr node, 
						 xmlNsPtr ns);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL              
		xmlXPathNodeSetSort		(xmlNodeSetPtr set);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		  
		xmlXPathRoot			(xmlXPathParserContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL		  
		xmlXPathEvalExpr		(xmlXPathParserContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL	  
		xmlXPathParseName		(xmlXPathParserContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlChar * XMLCALL	  
		xmlXPathParseNCName		(xmlXPathParserContextPtr ctxt);

/*
 * Existing functions.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN double XMLCALL 
		xmlXPathStringEvalNumber	(const xmlChar *str);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL 
		xmlXPathEvaluatePredicateResult (xmlXPathParserContextPtr ctxt, 
						 xmlXPathObjectPtr res);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL 
		xmlXPathRegisterAllFunctions	(xmlXPathContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodeSetPtr XMLCALL 
		xmlXPathNodeSetMerge		(xmlNodeSetPtr val1, 
						 xmlNodeSetPtr val2);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL 
		xmlXPathNodeSetDel		(xmlNodeSetPtr cur, 
						 xmlNodePtr val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL 
		xmlXPathNodeSetRemove		(xmlNodeSetPtr cur, 
						 int val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL 
		xmlXPathNewNodeSetList		(xmlNodeSetPtr val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL 
		xmlXPathWrapNodeSet		(xmlNodeSetPtr val);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlXPathObjectPtr XMLCALL 
		xmlXPathWrapExternal		(void *val);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL xmlXPathEqualValues(xmlXPathParserContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL xmlXPathNotEqualValues(xmlXPathParserContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL xmlXPathCompareValues(xmlXPathParserContextPtr ctxt, int inf, int strict);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathValueFlipSign(xmlXPathParserContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathAddValues(xmlXPathParserContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathSubValues(xmlXPathParserContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathMultValues(xmlXPathParserContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathDivValues(xmlXPathParserContextPtr ctxt);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathModValues(xmlXPathParserContextPtr ctxt);

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN int XMLCALL xmlXPathIsNodeType(const xmlChar *name);

/*
 * Some of the axis navigation routines.
 */

/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodePtr XMLCALL xmlXPathNextSelf(xmlXPathParserContextPtr ctxt,
			xmlNodePtr cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodePtr XMLCALL xmlXPathNextChild(xmlXPathParserContextPtr ctxt,
			xmlNodePtr cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodePtr XMLCALL xmlXPathNextDescendant(xmlXPathParserContextPtr ctxt,
			xmlNodePtr cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodePtr XMLCALL xmlXPathNextDescendantOrSelf(xmlXPathParserContextPtr ctxt,
			xmlNodePtr cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodePtr XMLCALL xmlXPathNextParent(xmlXPathParserContextPtr ctxt,
			xmlNodePtr cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodePtr XMLCALL xmlXPathNextAncestorOrSelf(xmlXPathParserContextPtr ctxt,
			xmlNodePtr cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodePtr XMLCALL xmlXPathNextFollowingSibling(xmlXPathParserContextPtr ctxt,
			xmlNodePtr cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodePtr XMLCALL xmlXPathNextFollowing(xmlXPathParserContextPtr ctxt,
			xmlNodePtr cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodePtr XMLCALL xmlXPathNextNamespace(xmlXPathParserContextPtr ctxt,
			xmlNodePtr cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodePtr XMLCALL xmlXPathNextAttribute(xmlXPathParserContextPtr ctxt,
			xmlNodePtr cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodePtr XMLCALL xmlXPathNextPreceding(xmlXPathParserContextPtr ctxt,
			xmlNodePtr cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodePtr XMLCALL xmlXPathNextAncestor(xmlXPathParserContextPtr ctxt,
			xmlNodePtr cur);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN xmlNodePtr XMLCALL xmlXPathNextPrecedingSibling(xmlXPathParserContextPtr ctxt,
			xmlNodePtr cur);
/*
 * The official core of XPath functions.
 *
 * @since 1.0
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathLastFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathPositionFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathCountFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathIdFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathLocalNameFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathNamespaceURIFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathStringFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathStringLengthFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathConcatFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathContainsFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathStartsWithFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathSubstringFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathSubstringBeforeFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathSubstringAfterFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathNormalizeFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathTranslateFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathNotFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathTrueFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathFalseFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathLangFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathNumberFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathSumFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathFloorFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathCeilingFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathRoundFunction(xmlXPathParserContextPtr ctxt, int nargs);
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathBooleanFunction(xmlXPathParserContextPtr ctxt, int nargs);

/**
 * Really internal functions
 */
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlXPathNodeSetFreeNs(xmlNsPtr ns);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif
#endif /* ! __XML_XPATH_INTERNALS_H__ */
