#pragma once
#include "stdafx.h"

class XMLSerializer;

class ISerializable
{
public:
	virtual ~ISerializable() {};
	virtual void serialize(const XMLSerializer& xml) = 0;
};