#pragma once
#include "ISerializable.h"
#include "TinyXML2\tinyxml2.h"
#include <stack>

/*\
|*| Responsible for traversing hierarchies of ISerializable leaves
|*| and composites and writing them into a tinyxml2 document.
|*|
|*| Composites are leaves with child leaves.
|*|
|*|	ISerializables have to provide an implementation for serialize()
|*| whithin which they call visit(), setAttribute() and leave().
\*/

class FFSerializer
{
public:
	FFSerializer(const std::string& rootName);

	// Creates a new XMLElement. Call when entering serialize().
	void visit(const ISerializable* go);
	
	// Removes the current node from the hierarchy stack.
	// Call when leaving serialize()
	void leave(const ISerializable* go);

	void writeToFile(const std::string& filePath);

	template<class Name, class T>
	void setAttribute(Name name, T value)
	{
		m_hierarchy.top()->SetAttribute(name, value);
		return;
	}

	// Adds attributes to topmost leave on hierarchy
	template<class Name, class T, class ...Properties>
	void setAttribute(Name name, T value, Properties... props)
	{
		m_hierarchy.top()->SetAttribute(name, value);
		setAttribute(props...);
	}

private:
	tinyxml2::XMLDocument* m_document;
	tinyxml2::XMLElement* m_pRoot;
	tinyxml2::XMLElement* m_pCurrent;

	std::stack<tinyxml2::XMLElement*> m_hierarchy;
};
