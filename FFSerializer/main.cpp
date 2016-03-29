
#include "stdafx.h"
#include "FFSerializer.h"
#include "GameObject.h"
#include "Component.h"

int main()
{
	FFSerializer serializer{ "FFMap" };

	GameObject go{"go1", 1};
	auto comp1 = std::make_shared<Component>(go, 0.1f);
	auto comp2 = std::make_shared<Component>(go, 0.2f);

	go.addComponent(comp1);
	go.addComponent(comp2);

	go.serialize(serializer);

	GameObject go2{ "go2", 2 };
	go2.serialize(serializer);

	serializer.writeToFile("testtest.xml");

    return 0;
}

