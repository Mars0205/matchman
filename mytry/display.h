#pragma once
#include "logical.h"

class display
{
public:
	void init();//画面初始化
	void show();//持续产生画面
	void music();
private:
	Player player;
	Background background;
	Map map;
	Timer timer;
	Logic logic;
};

