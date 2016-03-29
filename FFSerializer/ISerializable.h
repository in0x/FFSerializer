#pragma once
#include "stdafx.h"

class FFSerializer;

/*\
|*| Interface for FFSerializer leaves.
|*| Classes only have to implement this
|*| interface to be serializable.
\*/

class ISerializable
{
public:
	META_CLASS(ISerializable);

	virtual ~ISerializable() {};
	virtual void serialize(FFSerializer& serializer) = 0;
};
