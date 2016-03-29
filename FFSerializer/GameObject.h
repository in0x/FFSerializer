#pragma once
#include "stdafx.h"

class Component;

class GameObject
{
public:
	META_CLASS(GameObject);

	GameObject(const std::string& strID, int aNumber) : m_strID(strID), m_number(aNumber) {}

	void addComponent(std::shared_ptr<Component> pComp) 
	{
		m_components.push_back(pComp);
	}

private:
	std::string m_strID;
	int m_number;

	std::list<std::shared_ptr<Component>> m_components;
};