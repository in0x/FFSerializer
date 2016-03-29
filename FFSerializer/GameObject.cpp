#include "stdafx.h"
#include "GameObject.h"
#include "Component.h"

void GameObject::serialize(FFSerializer& serializer) 
{
	serializer.visit(this);

	serializer.setAttribute("m_strID", m_strID.c_str(), "m_number", m_number);

	for (auto& component : m_components)
	{
		component->serialize(serializer);
	}

	serializer.leave(this);
}
