/* $Change: 1114438 $ */
/*
 * Summary: compile-time version information
 * Description: compile-time version information for the XML library
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

 /**
 * @file		xmlversion.h
 * @brief	This is the header file for libxml
 *
 *
 */

#ifndef __XML_VERSION_H__
#define __XML_VERSION_H__

#include <libxml/xmlexports.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup libxml2
 * 
 * @{
 */

/*
 * use those to be sure nothing nasty will happen if
 * your library and includes mismatch
 */
#ifndef LIBXML2_COMPILING_MSCCDEF
/**
 * For more information about using Libxml2, go to <a href="http://www.xmlsoft.org" target=_blank> http://www.xmlsoft.org </a>
 *
 * @since 1.0
 */
XMLPUBFUN void XMLCALL xmlCheckVersion(int version);
#endif /* LIBXML2_COMPILING_MSCCDEF */

/*
 * LIBXML_DOTTED_VERSION:
 *
 * the version string like "1.2.3"
 *
 * @since 1.0
 */
#define LIBXML_DOTTED_VERSION "2.6.10"

/*
 * LIBXML_VERSION:
 *
 * the version number: 1.2.3 value is 1002003
 *
 * @since 1.0
 */
#define LIBXML_VERSION 20610

/*
 * LIBXML_VERSION_STRING:
 *
 * the version number string, 1.2.3 value is "1002003"
 *
 * @since 1.0
 */
#define LIBXML_VERSION_STRING "20610"

/*
 * LIBXML_TEST_VERSION:
 *
 * Macro to check that the libxml version in use is compatible with
 * the version the software has been compiled against
 *
 * @since 1.0
 */
#define LIBXML_TEST_VERSION xmlCheckVersion(20610);

#ifndef VMS
#if 0
/**
 * WITH_TRIO:
 *
 * defined if the trio support need to be configured in
 *
 * @since 1.0
 */
#define WITH_TRIO
#else
/**
 * WITHOUT_TRIO:
 *
 * defined if the trio support should not be configured in
 *
 * @since 1.0
 */
#define WITHOUT_TRIO
#endif
#else /* VMS */
/**
 * WITH_TRIO:
 *
 * defined if the trio support need to be configured in
 *
 * @since 1.0
 */
#define WITH_TRIO 0
#endif /* VMS */

#if 0
#if defined(_REENTRANT) || defined(__MT__) || (_POSIX_C_SOURCE - 0 >= 199506L)
/**
 * LIBXML_THREAD_ENABLED:
 *
 * Whether the thread support is configured in
 *
 * @since 1.0
 */
#define LIBXML_THREAD_ENABLED
#endif
#endif

#if 1
/**
 * LIBXML_TREE_ENABLED:
 *
 * Whether the DOM like tree manipulation API support is configured in
 *
 * @since 1.0
 */
#define LIBXML_TREE_ENABLED
#endif

#if 1
/**
 * LIBXML_OUTPUT_ENABLED:
 *
 * Whether the serialization/saving support is configured in
 *
 * @since 1.0
 */
#define LIBXML_OUTPUT_ENABLED
#endif

#if 1
/**
 * LIBXML_PUSH_ENABLED:
 *
 * Whether the push parsing interfaces are configured in
 *
 * @since 1.0
 */
#define LIBXML_PUSH_ENABLED
#endif

#if 1
/**
 * LIBXML_READER_ENABLED:
 *
 * Whether the xmlReader parsing interface is configured in
 *
 * @since 2.0
 */
#define LIBXML_READER_ENABLED
#endif

#if 0
/**
 * LIBXML_PATTERN_ENABLED:
 *
 * Whether the xmlPattern node selection interface is configured in
 *
 */
#define LIBXML_PATTERN_ENABLED
#endif

#if 1
/**
 * LIBXML_WRITER_ENABLED:
 *
 * Whether the xmlWriter saving interface is configured in
 *
 * @since 1.0
 */
#define LIBXML_WRITER_ENABLED
#endif

#if 1
/**
 * LIBXML_SAX1_ENABLED:
 *
 * Whether the older SAX1 interface is configured in
 *
 * @since 1.0
 */
#define LIBXML_SAX1_ENABLED
#endif

#if 0
/**
 * LIBXML_FTP_ENABLED:
 *
 * Whether the FTP support is configured in
 *
 */
#define LIBXML_FTP_ENABLED
#endif

#if 0
/**
 * LIBXML_HTTP_ENABLED:
 *
 * Whether the HTTP support is configured in
 *
 */
#define LIBXML_HTTP_ENABLED
#endif

#if 0
/**
 * LIBXML_VALID_ENABLED:
 *
 * Whether the DTD validation support is configured in
 *
 */
#define LIBXML_VALID_ENABLED
#endif

#if 1
/**
 * LIBXML_HTML_ENABLED:
 *
 * Whether the HTML support is configured in
 *
 * @since 2.0
 */
#define LIBXML_HTML_ENABLED
#endif

#if 0
/**
 * LIBXML_LEGACY_ENABLED:
 *
 * Whether the deprecated APIs are compiled in for compatibility
 *
 */
#define LIBXML_LEGACY_ENABLED
#endif

#if 0
/**
 * LIBXML_C14N_ENABLED:
 *
 * Whether the Canonicalization support is configured in
 *
 */
#define LIBXML_C14N_ENABLED
#endif

#if 0
/**
 * LIBXML_CATALOG_ENABLED:
 *
 * Whether the Catalog support is configured in
 *
 */
#define LIBXML_CATALOG_ENABLED
#endif

#if 0
/**
 * LIBXML_DOCB_ENABLED:
 *
 * Whether the SGML Docbook support is configured in
 *
 */
#define LIBXML_DOCB_ENABLED
#endif

#if 1
/**
 * LIBXML_XPATH_ENABLED:
 *
 * Whether XPath is configured in
 *
 * @since 1.0
 */
#define LIBXML_XPATH_ENABLED
#endif

#if 0
/**
 * LIBXML_XPTR_ENABLED:
 *
 * Whether XPointer is configured in
 *
 */
#define LIBXML_XPTR_ENABLED
#endif

#if 0
/**
 * LIBXML_XINCLUDE_ENABLED:
 *
 * Whether XInclude is configured in
 *
 */
#define LIBXML_XINCLUDE_ENABLED
#endif

#if 0
/**
 * LIBXML_ICONV_ENABLED:
 *
 * Whether iconv support is available
 *
 */
#define LIBXML_ICONV_ENABLED
#endif

#if 1
/**
 * LIBXML_ISO8859X_ENABLED:
 *
 * Whether ISO-8859-* support is made available in case iconv is not
 *
 * @since 1.0
 */
#define LIBXML_ISO8859X_ENABLED
#endif

#if 0
/**
 * LIBXML_DEBUG_ENABLED:
 *
 * Whether Debugging module is configured in
 *
 */
#define LIBXML_DEBUG_ENABLED
#endif

#if 0
/**
 * DEBUG_MEMORY_LOCATION:
 *
 * Whether the memory debugging is configured in
 *
 */
#define DEBUG_MEMORY_LOCATION
#endif

#if 1
/**
 * LIBXML_UNICODE_ENABLED:
 *
 * Whether the Unicode related interfaces are compiled in
 *
 * @since 1.0
 */
#define LIBXML_UNICODE_ENABLED
#endif

#if 0
/**
 * LIBXML_REGEXP_ENABLED:
 *
 * Whether the regular expressions interfaces are compiled in
 *
 */
#define LIBXML_REGEXP_ENABLED
#endif

#if 0
/**
 * LIBXML_AUTOMATA_ENABLED:
 *
 * Whether the automata interfaces are compiled in
 *
 */
#define LIBXML_AUTOMATA_ENABLED
#endif

#if 0
/**
 * LIBXML_SCHEMAS_ENABLED:
 *
 * Whether the Schemas validation interfaces are compiled in
 *
 */
#define LIBXML_SCHEMAS_ENABLED
#endif

/**
 * @}
 */

/*
 * ATTRIBUTE_UNUSED:
 *
 * Macro used to signal to GCC unused function parameters
 *
 * @since 1.0
 */
#ifdef __GNUC__
#ifdef HAVE_ANSIDECL_H
#include <ansidecl.h>
#endif
#ifndef ATTRIBUTE_UNUSED
#define ATTRIBUTE_UNUSED __attribute__((unused))
#endif
#else
#define ATTRIBUTE_UNUSED
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif


