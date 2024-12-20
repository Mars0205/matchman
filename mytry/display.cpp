#include "display.h"

void display::init() {
	player.init_player();
	map.init_map();
	background.init_background();

	initgraph(WIDTH, HEIGHT); // �¿�һ������
	BeginBatchDraw(); // ��ʼ��������
}

void display::show() {
	logic.updateall(player, map, background);//�жϽ�ɫ�ͳ����Ľ���
	FlushBatchDraw();
	timer.Sleep(16); // ��ͣ���ɺ���
}
void display::music() {
	mciSendString(_T("open source\\backgroundmusic.mp3 alias mymusic"), NULL, 0, NULL);
	mciSendString(_T("play mymusic repeat"), NULL, 0, NULL);
}