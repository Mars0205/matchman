#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <graphics.h>  
#include <conio.h>

#include <time.h>
#include "EasyXPng.h"
#include "Timer.h"
#include <vector>
#include <list>
#include <iostream>
#include <map>

#include <direct.h>
#pragma comment(lib, "Winmm.lib")


#define  WIDTH 800  
#define  HEIGHT 600
#define BULLETLIFE 60

struct Point //坐标
{
	int x, y;
};

struct landlocation {
	int left_x, right_x, top_y; // 用来刻画一块地面的左、右、上坐标
};
struct message
{
	int type;//0方向1跳跃
	int value;//0左1右
};

enum PlayerStatus // 枚举类型，游戏角色所有的可能状态
{
	standleft, standright, runleft, runright, jumpleft, jumpright, die
};

#define G 2 //重力加速度
#define RUN 10
#define JUMP -20

