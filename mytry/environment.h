#pragma once
#include "setup.h"
class Land {
public:
    int left_x, right_x, top_y;  // 地面块的坐标
    int land_width, land_height;  // 地面块的宽度和高度
    IMAGE land_img;              // 地面块的图像

    void init_land(int x, int y, IMAGE img) {
        left_x = x;
        right_x = x + land_width;
        top_y = y;
        land_img = img;
        land_width = land_img.getwidth(); // 获得地面图像的宽、高
        land_height = land_img.getheight();
    }

    void draw_land() {
        // 绘制地面块
        putimage(left_x, top_y, &land_img);
    }
};

class Map: Land//地图
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
	void draw_bg();//绘制背景
private:
	IMAGE backgroung_img;  // 背景图像	
	IMAGE ending_img; // 终点处放一个星星图案

};

