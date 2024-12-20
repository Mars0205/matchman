#pragma once
#include "setup.h"

class Bullet {
public:
    float x, y;         // �ӵ�λ��
    float velocityX, velocityY;  // �ӵ��ٶ�
    bool isActive;      // �ӵ��Ƿ���Ȼ��Ծ
    int life = 0;

    Bullet(float startX, float startY, float velocityX, float velocityY)
        : x(startX), y(startY), velocityX(velocityX), velocityY(velocityY), isActive(true) {
    }

    void drawBullet() {
        fillcircle(x, y, 5);  // �� (x, y) λ�û��ư뾶Ϊ 5 ��Բ�Σ������ӵ�
    }
    void update() {
        x += velocityX;
        y += velocityY;
        life++;
        drawBullet();
    }

    bool isOutOfTime() {
        if (life < BULLETLIFE) {
            return 0;
        }
        else return 1;
    }
};


