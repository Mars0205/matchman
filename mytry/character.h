#pragma once
#include "setup.h"
#include "Bullet.h"
#include "control.h"

class Player
{
public:
	PlayerStatus playerStatus; // 当前的状态
	int anime_ID;
	int Vx, Vy;
	int width, height;
	Point corner = { 0,0 };//玩家坐标(以左上角为准)
	bool isJumping;  // 是否正在跳跃，防止空中二次跳跃
	
	void init_player();//角色初始化
	void changeXY(int dx, int dy); //更新玩家坐标
	void updateV();//更新速度,输入脚下的地面对象
	void draw_player();//绘制角色
	void change_status(PlayerStatus newStatus);//更新玩家动作状态
	void shoot(ExMessage m);//发射子弹
	void bulletupdate();// 更新所有子弹
private:
	//图部分
	IMAGE current_img; //角色图
	IMAGE s_right, s_left, j_right, j_left;//各种动作 
	IMAGE r_right[10];
	IMAGE r_left[10];
	std::map<int, IMAGE> actions;
	std::list<Bullet> bullets;//子弹
	
	PlayerStatus pastStatus;
	
	
	
};

class Enermy
{
public:
	int Vx;
private:

};
