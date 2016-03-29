#include "stdafx.h"
#include "XMLSerializer.h"

XMLSerializer::XMLSerializer(const std::string& rootName) : m_currentElement(nullptr)
{
	m_document = new tinyxml2::XMLDocument();
	m_pRoot = m_document->NewElement(rootName.c_str());
	m_document->InsertFirstChild(m_pRoot);
};