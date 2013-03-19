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

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Debug.h"
#include "XMLNode.h"

XMLNode::XMLNode() : m_Node(0) {
}

XMLNode::~XMLNode() {
}

XMLNode::XMLNode(xmlNode *node) : m_Node(node) {
}

bool XMLNode::HasChild(const string& name) {
    return GetChild(name).IsValid();
}

string XMLNode::GetText() {
    // Little dance to avoid memory leak...
    const char *tmp = (const char*)xmlNodeGetContent(m_Node->children);
    string ret(tmp);
    xmlFree((void*)tmp);
    return ret;
}

bool XMLNode::IsValid() {
    return m_Node != NULL;
}

string XMLNode::GetName() {
    return string((const char*)m_Node->name);
}

double XMLNode::GetTextAsDouble() {
    // return boost::lexical_cast<double>(GetText());
    return strtod(GetText().c_str(), NULL);
}

int XMLNode::GetTextAsInt() {
    // return boost::lexical_cast<int>(GetText());
    return strtol(GetText().c_str(), NULL, 0);
}

bool XMLNode::GetTextAsBool() {
    string text = GetText();
    if (text == "1" || text == "true" ||text == "TRUE" || text == "True") {
        return true;
    } else {
        return false;
    }
}

void XMLNode::GetTextAsCoord(double &x, double &y) {
    string text = GetText();
    Assert(text.find(',',0) != string::npos, "coordinates must contain a comma");
    sscanf(text.c_str(), "%lf,%lf", &x, &y);
}

XMLNode XMLNode::GetChild(const string& name) {
    xmlNode *curNode = m_Node->children;

    // Iterate through the children
    for (; curNode; curNode = curNode->next) {
        if (curNode->type == XML_ELEMENT_NODE) {
            // Check the node name
            if (strcmp((const char*)curNode->name, name.c_str()) == 0) {
                return XMLNode(curNode);
            }
        }
    }
    return XMLNode();
}

bool XMLNode::HasProperty(const string& name)
{
    return GetProperty(name) != "";
}

string XMLNode::GetProperty(const string& name)
{
    for (xmlAttr *prop = m_Node->properties; prop; prop = prop->next)
        if (strcmp((const char*)prop->name, name.c_str()) == 0)
        {
            // Little dance to avoid memory leak...
            const char *val = (const char*)xmlNodeGetContent(prop->children);
            string ret(val);
            xmlFree((void*)val);
            return ret;
        }

    return string("");
}

XMLNode::NodeList XMLNode::GetChildList() {
    xmlNode *curNode = m_Node->children;
    XMLNode::NodeList nodeList;

    // Iterate through the children
    for (; curNode; curNode = curNode->next) {
        if (curNode->type == XML_ELEMENT_NODE) {
            nodeList.push_back(XMLNode(curNode));
        }
    }
    return nodeList;
}

XMLNode::NodeList XMLNode::GetChildList(const string& name) {
    xmlNode *curNode = m_Node->children;
    XMLNode::NodeList nodeList;

    // Iterate through the children
    for (; curNode; curNode = curNode->next) {
        if (curNode->type == XML_ELEMENT_NODE) {
            // Check the node name
            if (strcmp((const char*)curNode->name, name.c_str()) == 0) {
                nodeList.push_back(XMLNode(curNode));
            }
        }
    }
    return nodeList;
}

