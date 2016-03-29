#pragma once
#include "stdafx.h"

class GameObject;

class Component 
{
public:
	META_CLASS(Component);

	Component(const GameObject& go, float aFloat) : m_go(go), m_aFloat(aFloat) {}

private:
	const GameObject& m_go;
	float m_aFloat;
};