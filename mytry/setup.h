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

struct Point //����
{
	int x, y;
};

struct landlocation {
	int left_x, right_x, top_y; // �����̻�һ���������ҡ�������
};
struct message
{
	int type;//0����1��Ծ
	int value;//0��1��
};

enum PlayerStatus // ö�����ͣ���Ϸ��ɫ���еĿ���״̬
{
	standleft, standright, runleft, runright, jumpleft, jumpright, die
};

#define G 2 //�������ٶ�
#define RUN 10
#define JUMP -20

