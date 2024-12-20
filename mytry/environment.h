#pragma once
#include "setup.h"
class Land {
public:
    int left_x, right_x, top_y;  // ����������
    int land_width, land_height;  // �����Ŀ�Ⱥ͸߶�
    IMAGE land_img;              // ������ͼ��

    void init_land(int x, int y, IMAGE img) {
        left_x = x;
        right_x = x + land_width;
        top_y = y;
        land_img = img;
        land_width = land_img.getwidth(); // ��õ���ͼ��Ŀ���
        land_height = land_img.getheight();
    }

    void draw_land() {
        // ���Ƶ����
        putimage(left_x, top_y, &land_img);
    }
};

class Map: Land//��ͼ
{
public:
	void init_map();
	void draw_map();
	std::vector<Land*> lands;
	Land modelland;
};




class Background
{
public:
	void init_background();
	void draw_bg();//���Ʊ���
private:
	IMAGE backgroung_img;  // ����ͼ��	
	IMAGE ending_img; // �յ㴦��һ������ͼ��

};

