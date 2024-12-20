
#include "character.h"

void Player::init_player() {
	//导入图片
	loadimage(&s_right, _T("source\\standright.png"));
	loadimage(&s_left, _T("source\\standleft.png")); 
	loadimage(&j_right, _T("source\\jumpright.png")); 
	loadimage(&j_left, _T("source\\jumpleft.png")); 

	playerStatus = standright; // 初始为向右站立的游戏状态
	current_img = s_right;  // 初始显示向右站立的图片
	width = s_right.getwidth(); // 获得图像的宽、高，所有动画图片大小一样
	height = s_right.getheight();

	TCHAR filename[80];
	for (int i = 0;i <= 7;i++) // 把向右奔跑的八张图片对象添加到r_right中
	{
		_stprintf(filename, _T("source\\runright%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		r_right[i] = im;
	}
	for (int i = 0;i <= 7;i++) // 把向左奔跑的八张图片对象添加到r_left中
	{
		_stprintf(filename, _T("source\\runleft%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		r_left[i] = im;
	}
	anime_ID = 0; // 动画id开始设为0

	changeXY(WIDTH / 2, HEIGHT / 2 - height); // 开始将角色放在画面中间
	Vx = 0; // 水平方向初速度
	Vy = 0;  // 竖直方向速度初始为0
}

void Player::changeXY(int dx, int dy) // 根据输入，更新玩家坐标
{
	corner.x += dx;
	corner.y += dy;
}

void Player::updateV() {
	if (playerStatus == standleft || playerStatus == standright) {
		Vx = Vy = 0;  // 站立时，速度为0
	}
	else if (playerStatus == runleft) {
		Vx = -RUN;
		Vy = 0;
	}
	else if (playerStatus == runright) {
		Vx = RUN;
		Vy = 0;
	}
	else if (playerStatus == jumpleft || playerStatus == jumpright) {
		Vx = (playerStatus == jumpleft) ? -RUN : RUN;  // 保持水平速度，取决于跳跃方向
		Vy += G;  // 受重力影响，增加垂直速度
	}

}

void Player::draw_player() {
	putimagePng(corner.x, corner.y, &current_img);
	bulletupdate();
}

void Player::change_status(PlayerStatus newStatus) {
	if (playerStatus == newStatus) {
		if (playerStatus == runleft) {
			current_img = r_left[(anime_ID++) % 8]; // 更新当前图像为当前帧
		}
		else if (playerStatus == runright) {
			current_img = r_right[(anime_ID++) % 8]; // 更新当前图像为当前帧
		}
		return; // 如果状态没有变化，就不进行处理
	}
	playerStatus = newStatus;
	switch (newStatus) {
		case PlayerStatus::standleft:
			current_img = s_left;
			break;
		case PlayerStatus::standright:
			current_img = s_right;
			break;
		case PlayerStatus::runleft:
			anime_ID = 0;
			current_img = r_left[anime_ID % 8];// 帧初始化
			break;
		case PlayerStatus::runright:
			anime_ID = 0;
			current_img = r_right[anime_ID % 8]; 
			break;
		case PlayerStatus::jumpleft:
			current_img = j_left;
			break;
		case PlayerStatus::jumpright:
			current_img = j_right;
			break;
		default:
			break;
	}
}

void Player::shoot(ExMessage m)
{
	//让子弹向鼠标方向飞行
	float deltaX = m.x - corner.x;
	float deltaY = m.y - corner.y;
	
	float magnitude = std::sqrt(deltaX * deltaX + deltaY * deltaY);
	float normalizedX = deltaX / magnitude;
	float normalizedY = deltaY / magnitude;
	
	float bulletSpeed = 10.0f;
	float velocityX = normalizedX * bulletSpeed;
	float velocityY = normalizedY * bulletSpeed;
	 
	// 发射子弹
	bullets.push_back(Bullet(corner.x, corner.y, velocityX, velocityY));
}

void Player::bulletupdate()
{
	for (auto it = bullets.begin(); it != bullets.end(); ) {
		if (it->isOutOfTime()) {
			it = bullets.erase(it);  // 删除超出生命周期的子弹
		}
		else {
			++it;  // 否则继续遍历
		}
	}
	// 更新子弹位置并绘制
	for (auto& bullet : bullets) {
		bullet.update();
	}
}