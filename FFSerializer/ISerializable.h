#pragma once
#include "stdafx.h"

class FFSerializer;

class ISerializable
{
public:
	META_CLASS(ISerializable);

	virtual ~ISerializable() {};
	virtual void serialize(FFSerializer& serializer) = 0;
};