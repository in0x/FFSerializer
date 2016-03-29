#pragma once
#include "stdafx.h"

class FFSerializer;

/*\
|*| Interface for FFSerializer leaves.
\*/

class ISerializable
{
public:
	META_CLASS(ISerializable);

	virtual ~ISerializable() {};
	virtual void serialize(FFSerializer& serializer) = 0;
};