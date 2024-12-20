#include "logical.h"
void Logic::update_playerXY(Player& player) {
    // 更新角色的速度
    switch (player.playerStatus) {
    case standleft:
    case standright:
        player.Vx = 0;  // 站立时，停止水平速度
        break;
    case runleft:
        player.Vx = -RUN;  // 向左跑
        break;
    case runright:
        player.Vx = RUN;   // 向右跑
        break;
    case jumpleft:
    case jumpright:
        // 跳跃时保持水平速度
        player.Vy += G;  // 受到重力影响
        break;
    default:
        break;
    }

    // 更新角色的位置
    player.changeXY(player.Vx,player.Vy);
}

void Logic::handle_input(Player& player) {
    std::vector<message> msgs = admin.listen();
    admin.mouse();
    //键盘消息
    if (!msgs.empty()) {
        for (auto p : msgs) {
            message msg = p;
            int _type = msg.type;
            int _value = msg.value;

            if (_type == 0) {  // 水平移动
                if (!player.isJumping)
                {
                    if (_value == runleft) {
                        player.change_status(runleft);
                    }
                    else if (_value == runright) {
                        player.change_status(runright);
                    }
                }
                else {
                    if (_value == runleft) {
                        player.change_status(jumpleft);
                    }
                    else if (_value == runright) {
                        player.change_status(jumpright);
                    }
                }
            }
            else if (_type == 1) {  // 跳跃
                if (!player.isJumping) {  // 如果角色没有跳跃中，才可以跳跃
                    player.change_status(_value == jumpleft ? jumpleft : jumpright);
                    player.Vy = JUMP;
                    player.isJumping = 1;
                }
            }
        }
    }
    else {  // 如果没有输入，角色保持站立
        // 没有键盘输入时，恢复到站立状态
        if (player.playerStatus == runleft || player.playerStatus == runright) {
            // 如果在跑步状态，则恢复到站立状态
            if (player.playerStatus == runleft) {
                player.change_status(standleft);
            }
            else if (player.playerStatus == runright) {
                player.change_status(standright);
            }
        }
    }
    //鼠标消息
    if (admin.m.message == WM_LBUTTONDOWN) {
        player.shoot(admin.m);
    }
}

void Logic::check_land_collision(Player& player, Map& map) {
    for (int i = 0;i < map.lands.size();i++) {
        Land theland = *(map.lands[i]);
        // 如果角色与地面发生碰撞
        if (player.corner.y + player.height >= theland.top_y) {
            player.corner.y = theland.top_y - player.height;  // 调整角色位置，使其站在地面上
            player.Vy = 0;  // 垂直速度归零，表示停止下落

            // 如果角色正在跳跃，切换为站立或跑步状态
            if (player.playerStatus == jumpleft || player.playerStatus == jumpright) {
                if (player.Vx < 0) {
                    player.change_status(standleft);
                }
                else {
                    player.change_status(standright);
                }
                player.isJumping = 0;
            }
        }
    }
    
}

void Logic::updateall(Player& player, Map& map, Background& background) {
    handle_input(player);
    update_playerXY(player);
    check_land_collision(player, map);
    background.draw_bg();
    map.draw_map();
    player.draw_player();
}
