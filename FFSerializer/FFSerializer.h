#pragma once
#include "ISerializable.h"
#include "TinyXML2\tinyxml2.h"

class FFSerializer
{
public:
	FFSerializer(const std::string& rootName);

	void visit(const ISerializable* go);
	void leave(const ISerializable* go);

	void writeToFile(const std::string& filePath);

	template<class Name, class T>
	void setAttribute(Name name, T value)
	{
		m_pCurrent->SetAttribute(name, value);
		return;
	}

	template<class Name, class T, class ...Properties>
	void setAttribute(Name name, T value, Properties... props)
	{
		m_pCurrent->SetAttribute(name, value);
		setAttribute(props...);
	}

private:
	tinyxml2::XMLDocument* m_document;
	tinyxml2::XMLElement* m_pRoot;
	tinyxml2::XMLElement* m_pCurrent;
};
