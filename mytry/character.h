#pragma once
#include "setup.h"
#include "Bullet.h"
#include "control.h"

class Player
{
public:
	PlayerStatus playerStatus; // ��ǰ��״̬
	int anime_ID;
	int Vx, Vy;
	int width, height;
	Point corner = { 0,0 };//�������(�����Ͻ�Ϊ׼)
	bool isJumping;  // �Ƿ�������Ծ����ֹ���ж�����Ծ
	
	void init_player();//��ɫ��ʼ��
	void changeXY(int dx, int dy); //�����������
	void updateV();//�����ٶ�,������µĵ������
	void draw_player();//���ƽ�ɫ
	void change_status(PlayerStatus newStatus);//������Ҷ���״̬
	void shoot(ExMessage m);//�����ӵ�
	void bulletupdate();// ���������ӵ�
private:
	//ͼ����
	IMAGE current_img; //��ɫͼ
	IMAGE s_right, s_left, j_right, j_left;//���ֶ��� 
	IMAGE r_right[10];
	IMAGE r_left[10];
	std::map<int, IMAGE> actions;
	std::list<Bullet> bullets;//�ӵ�
	
	PlayerStatus pastStatus;
	
	
	
};

class Enermy
{
public:
	int Vx;
private:

};
