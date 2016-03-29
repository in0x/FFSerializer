#pragma once
#include "stdafx.h"
#include "TinyXML2\tinyxml2.h"

/*\
|*| Responsible for creating an XML Document from recieved data
\*/

class XMLSerializer 
{
public:
	XMLSerializer(const std::string& rootName);

	// Base case for recursive createNode
	template<class Name, class T>
	void createNode(const std::string& nodeName, Name name, T value)
	{
		if (m_currentElement == nullptr)
		{
			m_currentElement = m_document->NewElement(nodeName.c_str());
		}

		m_currentElement->SetAttribute(name, value);

		m_pRoot->InsertEndChild(m_currentElement);
		m_currentElement = nullptr;
		return;
	}

	// Creates a new XML element with nodeName 
	// and creates name="value" attribute pairs from parameter pack.
	template<class Name, class T, class ...Properties>
	void createNode(const std::string& nodeName, Name name, T value, Properties... props)
	{
		if (m_currentElement == nullptr)
		{
			m_currentElement = m_document->NewElement(nodeName.c_str());
		}

		m_currentElement->SetAttribute(name, value);

		setNodeAttribs(nodeName, props...);
	}

	void writeToFile(const std::string& filePath) 
	{
		m_document->SaveFile(filePath.c_str());	
	}
		
private:
	// Stored as pointers to prevent clashing with tinyxml2's memory management
	tinyxml2::XMLDocument* m_document;
	tinyxml2::XMLNode* m_pRoot;
	tinyxml2::XMLElement* m_currentElement;
};
