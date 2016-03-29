#include "stdafx.h"
#include "Component.h"
#include "GameObject.h"

void Component::serialize(FFSerializer& serializer) 
{
	serializer.visit(this);

	serializer.setAttribute("m_go", m_go.getID().c_str(), "m_aFloat", m_aFloat);

	serializer.leave(this);
}