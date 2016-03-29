#pragma once
#include <string>

/*\ 
|*| Provides the base interface for serializers
|*| Could be implemented by XML, JSON, etc. serializers
\*/

class ISerializer
{
public:
	virtual ~ISerializer() {};
	
	// Implementers should override this template by using the stream operator to write data into the document
	// Value should therefore by a type that implements operator<<
	template<class Value>
	virtual void serialzeValue(std::string fieldName, Value fieldValue) = 0;

	virtual void writeToFile(const std::string& filePath) = 0;
};