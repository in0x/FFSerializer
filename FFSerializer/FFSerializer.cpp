// FFSerializer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameObject.h"
#include "XMLSerializer.h"
#include <string>

int main()
{
	XMLSerializer xml{"FFMap"};

	xml.createNode("GameObject", "go1", 1);
	xml.createNode("GameObject", "go2", 2);
	xml.writeToFile("test.xml");

    return 0;
}

