#pragma once
#include "stdafx.h"
#include "ISerializable.h"
#include "FFSerializer.h"

class GameObject;

class Component : public ISerializable
{
public:
	META_CLASS(Component);

	Component(const GameObject& go, float aFloat) : m_go(go), m_aFloat(aFloat) {}

	virtual void serialize(FFSerializer& serializer) override;

private:
	const GameObject& m_go;
	float m_aFloat;
};