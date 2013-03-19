/*=========================================================================
    OpenGC - The Open Source Glass Cockpit Project

    Copyright (c) 2001-2004 Damion Shelton
    Copyright (c) 2005-2010 Hugo Vincent <hugo.vincent@gmail.com>
    Copyright (c) 2008-2010 Yuriy Kinakh <ykinakh@gmail.com>
    Copyright (c) 2008-2010 Bohdan Mushkevych <mushkevych@gmail.com>
    All rights reserved.

    This branch of OpenGC is developed within "Albatross UAV Project"
    http://gitorious.org/albatross/

    This software is distributed WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See Copyright.txt or http://opengc.sourceforge.net/licensing.html for more information.
=========================================================================*/

#ifndef XMLParser_h
#define XMLParser_h

#include <string>
#include <libxml/parser.h>
#include "XMLNode.h"

using namespace std;

/** XMLParser is a thin wrapper around libxml-2, supporting reading, parsing
 * and extracting data from XML files. It is intended that classes to read
 * specific types of XML documents (such as PropertyLists) inherit from this
 * class, adding extra validation and data extraction methods.
 */
class XMLParser
{
	public:
		XMLParser();
		~XMLParser();

		/** Read an XML file into the parser */
		bool ReadFile(const string& filename);

		/** Heirarchically print the tree for debugging.
		 * Call as PrintTree(0, 0) - its recursive. */
		void PrintTree(xmlNode *aNode, string indentation);

		/** Check if the XML document has a particular node */
		bool HasNode(const string& path) { return GetNode(path).IsValid(); }

		/** Get a particular node from the XML document
		 * Note: should be a unique path, otherwise the first
		 * matching node will be found */
		XMLNode GetNode(const string& path);

	protected:
		/** The libxml-2 XML document structure */
		xmlDoc *m_XMLDoc;

		/** The root (top level) node of the XML document */
		xmlNode *m_XMLRootNode;

		/** Overload to change what types of documents are accepted,
		 * for example, by checking what the top level node is named */
		bool CheckFileType() { return true; }

		/** Checks if a string is wholely white space. */
		static bool IsWhiteSpace(const string& str);
};

#endif

