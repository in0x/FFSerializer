#include "stdafx.h"
#include "FFSerializer.h"

FFSerializer::FFSerializer(const std::string& rootName) 
{
	m_document = new tinyxml2::XMLDocument();

	m_pRoot = m_document->NewElement(rootName.c_str());

	m_document->InsertFirstChild(m_pRoot);

	m_pCurrent = m_pRoot;
}

void FFSerializer::visit(const ISerializable* go)
{
	auto pElement = m_document->NewElement(go->ClassNameInstance().c_str());
	m_pCurrent->InsertEndChild(pElement);
	m_pCurrent = pElement;
}

void FFSerializer::leave(const ISerializable* go)
{
	m_pCurrent = m_pRoot;
}


void FFSerializer::writeToFile(const std::string& filePath)
{
	m_document->SaveFile(filePath.c_str());
}
