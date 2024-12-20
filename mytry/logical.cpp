#include "logical.h"
void Logic::update_playerXY(Player& player) {
    // ���½�ɫ���ٶ�
    switch (player.playerStatus) {
    case standleft:
    case standright:
        player.Vx = 0;  // վ��ʱ��ֹͣˮƽ�ٶ�
        break;
    case runleft:
        player.Vx = -RUN;  // ������
        break;
    case runright:
        player.Vx = RUN;   // ������
        break;
    case jumpleft:
    case jumpright:
        // ��Ծʱ����ˮƽ�ٶ�
        player.Vy += G;  // �ܵ�����Ӱ��
        break;
    default:
        break;
    }

    // ���½�ɫ��λ��
    player.changeXY(player.Vx,player.Vy);
}

void Logic::handle_input(Player& player) {
    std::vector<message> msgs = admin.listen();
    admin.mouse();
    //������Ϣ
    if (!msgs.empty()) {
        for (auto p : msgs) {
            message msg = p;
            int _type = msg.type;
            int _value = msg.value;

            if (_type == 0) {  // ˮƽ�ƶ�
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
            else if (_type == 1) {  // ��Ծ
                if (!player.isJumping) {  // �����ɫû����Ծ�У��ſ�����Ծ
                    player.change_status(_value == jumpleft ? jumpleft : jumpright);
                    player.Vy = JUMP;
                    player.isJumping = 1;
                }
            }
        }
    }
    else {  // ���û�����룬��ɫ����վ��
        // û�м�������ʱ���ָ���վ��״̬
        if (player.playerStatus == runleft || player.playerStatus == runright) {
            // ������ܲ�״̬����ָ���վ��״̬
            if (player.playerStatus == runleft) {
                player.change_status(standleft);
            }
            else if (player.playerStatus == runright) {
                player.change_status(standright);
            }
        }
    }
    //�����Ϣ
    if (admin.m.message == WM_LBUTTONDOWN) {
        player.shoot(admin.m);
    }
}

void Logic::check_land_collision(Player& player, Map& map) {
    for (int i = 0;i < map.lands.size();i++) {
        Land theland = *(map.lands[i]);
        // �����ɫ����淢����ײ
        if (player.corner.y + player.height >= theland.top_y) {
            player.corner.y = theland.top_y - player.height;  // ������ɫλ�ã�ʹ��վ�ڵ�����
            player.Vy = 0;  // ��ֱ�ٶȹ��㣬��ʾֹͣ����

            // �����ɫ������Ծ���л�Ϊվ�����ܲ�״̬
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
