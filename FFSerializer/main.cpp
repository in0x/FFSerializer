
#include "stdafx.h"
#include "FFSerializer.h"
#include "GameObject.h"
#include "Component.h"

int main()
{

	FFSerializer serializer{ "FFMap" };

	GameObject go{"go1", 1};
	Component{go, 0.1f};
	Component{ go, 0.3f };

	go.serialize(serializer);

	serializer.writeToFile("testtest.xml");

    return 0;
}

