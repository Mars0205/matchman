#pragma once
#include "character.h"
#include "environment.h"
class control
{
public:
	std::vector<message> listen(); //������������
	void mouse();//�����������
	ExMessage m;
};

