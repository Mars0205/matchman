#pragma once
#include "character.h"
#include "environment.h"
#include "control.h"

class Logic {
public:
    void updateall(Player& player, Map& map, Background& background);

    void update_playerXY(Player& player);  // 只更新玩家的状态
    void handle_input(Player& player);  // 处理玩家输入
    void check_land_collision(Player& player, Map& map);  // 检查角色与地面的碰撞
private:
    control admin;
};

