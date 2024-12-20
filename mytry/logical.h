#pragma once
#include "character.h"
#include "environment.h"
#include "control.h"

class Logic {
public:
    void updateall(Player& player, Map& map, Background& background);

    void update_playerXY(Player& player);  // ֻ������ҵ�״̬
    void handle_input(Player& player);  // �����������
    void check_land_collision(Player& player, Map& map);  // ����ɫ��������ײ
private:
    control admin;
};

