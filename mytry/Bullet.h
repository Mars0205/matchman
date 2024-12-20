#pragma once
#include "setup.h"

class Bullet {
public:
    float x, y;         // 子弹位置
    float velocityX, velocityY;  // 子弹速度
    bool isActive;      // 子弹是否仍然活跃
    int life = 0;

    Bullet(float startX, float startY, float velocityX, float velocityY)
        : x(startX), y(startY), velocityX(velocityX), velocityY(velocityY), isActive(true) {
    }

    void drawBullet() {
        fillcircle(x, y, 5);  // 在 (x, y) 位置绘制半径为 5 的圆形，代表子弹
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


