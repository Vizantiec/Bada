/* $Change: 1142016 $ */
//
// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file			FXml.h
 * @brief			This is the header file for the %Xml namespace.
 *
 * This header file contains the introduction of the %Xml namespace.
 */


#ifndef _FXML_H_
#define _FXML_H_

#include <FBase.h>
#include <stdarg.h>
#include <stdio.h>

namespace Osp
{
/**
 * @namespace	Osp::Xml
 * @brief		This namespace contains interfaces to manipulate %XML documents.
 * @since	1.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FXml.h> @n
 *				@b Library : @b FOsp
 *
 *
 *
 *
 * The %Xml namespace provides <a href ="group__libxml2.html">Libxml2</a> library methods to manipulate XML documents.
 * An application can access the Libxml2 library by including the FXml.h file.
 * For more information about using Libxml2, see <a href="http://www.xmlsoft.org">http://www.xmlsoft.org</a>.
 *
 * For more information on the %Xml namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/xml/xml_namespace.htm">Xml</a> Guide.
 *
 *
 *	@code

// sample data - map.xml
<?xml version="1.0" encoding="ISO-8859-1" ?> 

<map>
	<item>
		<country>United Arab Emirates</country>
		<capital>Abu Dhabi</capital>
	</item>
	
	<item>
		<country>Nigeria</country>
		<capital>Abuja</capital>
	</item>

	<item>
		<country>Ghana</country>
		<capital>Accra</capital>
	</item>
	
	<item>
		<country>Pitcairn Islands</country>
		<capital>Adamstown</capital>
	</item>			
</map>

// Sample Code for XmlSample.h
#include <FBase.h>
#include <FUi.h>

class XmlSample :
	public Osp::Ui::Controls::Form
{

// Construction
public:
	XmlSample(void);
	~XmlSample(void);

public:
	virtual result OnInitializing(void);
};

// Sample Code for XmlSample.cpp
#include "XmlSample.h"
#include "FXml.h"

using namespace Osp::Xml;
using namespace Osp::Base;


result
XmlSample::OnInitializing(void)
{
	xmlDocPtr pDocument = null;
	xmlNodePtr pRoot = null;
	xmlNodePtr pCurrentElement = null;

	// Create xml document
	pDocument = xmlParseFile("/Home/map.xml");
	pRoot = xmlDocGetRootElement(pDocument);

	for(pCurrentElement = pRoot->children; pCurrentElement; pCurrentElement = pCurrentElement->next)
	{
		String countryName;
		xmlNodePtr pChildElement = null;

		if(pCurrentElement->type == XML_ELEMENT_NODE)
		{
			// Get <country> element from <item> element
			pChildElement = pCurrentElement->children->next;

			if(pChildElement)
			{
				// Get content from XML_TEXT_NODE
				Osp::Base::Utility::StringUtil::Utf8ToString ((char*)pChildElement->children->content, countryName);
				AppLog("country : %S\n", countryName.GetPointer());
			}
		}
	}

	xmlFreeDoc(pDocument);
	return E_SUCCESS;
}

 *	@endcode
 *
 */

namespace Xml
{
#include <libxml/parser.h>
#include <libxml/HTMLparser.h>
#include <libxml/parserInternals.h>
#include <libxml/SAX.h>
#include <libxml/SAX2.h>
#include <libxml/xpath.h>
#include <libxml/xmlmemory.h>

#include <libxml/xmlerror.h>
#include <libxml/tree.h>

#include <libxml/uri.h>
#include <libxml/xmlsave.h>
#include <libxml/xmlunicode.h>
#include <libxml/encoding.h>
#include <libxml/xmlIO.h>
#include <libxml/xmlwriter.h>
#include <libxml/xmlreader.h>
#include <libxml/xpathInternals.h>


};// Osp::Xml
};// Osp
#endif // _FXML_H_
