#pragma once
#include "logical.h"

class display
{
public:
	void init();//�����ʼ��
	void show();//������������
	void music();
private:
	Player player;
	Background background;
	Map map;
	Timer timer;
	Logic logic;
};

