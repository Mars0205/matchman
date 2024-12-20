#pragma once
#include "character.h"
#include "environment.h"
class control
{
public:
	std::vector<message> listen(); //¼àÌı¼üÅÌÊäÈë
	void mouse();//¼àÌıÊó±êÊäÈë
	ExMessage m;
};

