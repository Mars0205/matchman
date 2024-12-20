#include "environment.h"

void Map::init_map() {
	IMAGE img0;
	loadimage(&img0, _T("source\\land.png")); // 导入地面图片
	modelland.init_land(WIDTH / 2,HEIGHT / 2,img0);
	lands.push_back(&modelland);
}

void Map::draw_map() {
	for (int i = 0;i < lands.size();i++) {
		(*lands[i]).draw_land();
	}
}

void Background::init_background() {
	loadimage(&backgroung_img, _T("source\\landscape.png"));
	loadimage(&ending_img, _T("source\\star.png")); // 导入星星图片，放在终点处的目标

}
void Background::draw_bg() {
	putimagePng(0, 0, &backgroung_img);
}