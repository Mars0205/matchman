
#include "character.h"

void Player::init_player() {
	//����ͼƬ
	loadimage(&s_right, _T("source\\standright.png"));
	loadimage(&s_left, _T("source\\standleft.png")); 
	loadimage(&j_right, _T("source\\jumpright.png")); 
	loadimage(&j_left, _T("source\\jumpleft.png")); 

	playerStatus = standright; // ��ʼΪ����վ������Ϸ״̬
	current_img = s_right;  // ��ʼ��ʾ����վ����ͼƬ
	width = s_right.getwidth(); // ���ͼ��Ŀ��ߣ����ж���ͼƬ��Сһ��
	height = s_right.getheight();

	TCHAR filename[80];
	for (int i = 0;i <= 7;i++) // �����ұ��ܵİ���ͼƬ������ӵ�r_right��
	{
		_stprintf(filename, _T("source\\runright%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		r_right[i] = im;
	}
	for (int i = 0;i <= 7;i++) // �������ܵİ���ͼƬ������ӵ�r_left��
	{
		_stprintf(filename, _T("source\\runleft%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		r_left[i] = im;
	}
	anime_ID = 0; // ����id��ʼ��Ϊ0

	changeXY(WIDTH / 2, HEIGHT / 2 - height); // ��ʼ����ɫ���ڻ����м�
	Vx = 0; // ˮƽ������ٶ�
	Vy = 0;  // ��ֱ�����ٶȳ�ʼΪ0
}

void Player::changeXY(int dx, int dy) // �������룬�����������
{
	corner.x += dx;
	corner.y += dy;
}

void Player::updateV() {
	if (playerStatus == standleft || playerStatus == standright) {
		Vx = Vy = 0;  // վ��ʱ���ٶ�Ϊ0
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
		Vx = (playerStatus == jumpleft) ? -RUN : RUN;  // ����ˮƽ�ٶȣ�ȡ������Ծ����
		Vy += G;  // ������Ӱ�죬���Ӵ�ֱ�ٶ�
	}

}

void Player::draw_player() {
	putimagePng(corner.x, corner.y, &current_img);
	bulletupdate();
}

void Player::change_status(PlayerStatus newStatus) {
	if (playerStatus == newStatus) {
		if (playerStatus == runleft) {
			current_img = r_left[(anime_ID++) % 8]; // ���µ�ǰͼ��Ϊ��ǰ֡
		}
		else if (playerStatus == runright) {
			current_img = r_right[(anime_ID++) % 8]; // ���µ�ǰͼ��Ϊ��ǰ֡
		}
		return; // ���״̬û�б仯���Ͳ����д���
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
			current_img = r_left[anime_ID % 8];// ֡��ʼ��
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
	//���ӵ�����귽�����
	float deltaX = m.x - corner.x;
	float deltaY = m.y - corner.y;
	
	float magnitude = std::sqrt(deltaX * deltaX + deltaY * deltaY);
	float normalizedX = deltaX / magnitude;
	float normalizedY = deltaY / magnitude;
	
	float bulletSpeed = 10.0f;
	float velocityX = normalizedX * bulletSpeed;
	float velocityY = normalizedY * bulletSpeed;
	 
	// �����ӵ�
	bullets.push_back(Bullet(corner.x, corner.y, velocityX, velocityY));
}

void Player::bulletupdate()
{
	for (auto it = bullets.begin(); it != bullets.end(); ) {
		if (it->isOutOfTime()) {
			it = bullets.erase(it);  // ɾ�������������ڵ��ӵ�
		}
		else {
			++it;  // �����������
		}
	}
	// �����ӵ�λ�ò�����
	for (auto& bullet : bullets) {
		bullet.update();
	}
}