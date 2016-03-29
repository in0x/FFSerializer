#include "stdafx.h"
#include "FFSerializer.h"

FFSerializer::FFSerializer(const std::string& rootName) 
{
	m_document = new tinyxml2::XMLDocument();

	m_pRoot = m_document->NewElement(rootName.c_str());

	m_document->InsertFirstChild(m_pRoot);

	m_hierarchy.push(m_pRoot);
}

void FFSerializer::visit(const ISerializable* go)
{
	auto pElement = m_document->NewElement(go->ClassNameInstance().c_str());
	
	m_hierarchy.top()->InsertEndChild(pElement);

	m_hierarchy.push(pElement);
}

void FFSerializer::leave(const ISerializable* go)
{
	m_hierarchy.pop();
}


void FFSerializer::writeToFile(const std::string& filePath)
{
	m_document->SaveFile(filePath.c_str());
}
