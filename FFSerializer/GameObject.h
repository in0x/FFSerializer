#pragma once
#include "stdafx.h"
#include "ISerializable.h"
#include "FFSerializer.h"

class Component;

class GameObject : public ISerializable
{
public:
	META_CLASS(GameObject);

	GameObject(const std::string& strID, int aNumber) : m_strID(strID), m_number(aNumber) {}

	void addComponent(std::shared_ptr<Component> pComp) 
	{
		m_components.push_back(pComp);
	}

	virtual void serialize(FFSerializer& serializer) override;

	const std::string& getID() const
	{
		return m_strID;
	}

private:
	std::string m_strID;
	int m_number;

	std::list<std::shared_ptr<Component>> m_components;
};