#include "display.h"

void display::init() {
	player.init_player();
	map.init_map();
	background.init_background();

	initgraph(WIDTH, HEIGHT); // 新开一个画面
	BeginBatchDraw(); // 开始批量绘制
}

void display::show() {
	logic.updateall(player, map, background);//判断角色和场景的交互
	FlushBatchDraw();
	timer.Sleep(16); // 暂停若干毫秒
}
void display::music() {
	mciSendString(_T("open source\\backgroundmusic.mp3 alias mymusic"), NULL, 0, NULL);
	mciSendString(_T("play mymusic repeat"), NULL, 0, NULL);
}