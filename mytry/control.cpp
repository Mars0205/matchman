#include "control.h"

std::vector<message> control::listen()
{	
	std::vector<message>messages;
	//BYTE keyState[256];
	if (_kbhit()) {
		message key;
		if (GetAsyncKeyState('D') & 0x8000)// ����D�����ҷ����
		{
			key.type = 0;
			key.value= runright;
			messages.push_back(key);
		}
		else if (GetAsyncKeyState('A') & 0x8000)// ����A���������
		{
			key.type = 0;
			key.value = runleft;
			messages.push_back(key);
		}
		if (GetAsyncKeyState('W') & 0x8000)
		{
			key.type = 1;
			key.value = 0;
			messages.push_back(key);
		}
	}
	return messages;
}

void control::mouse()
{
	peekmessage(&m, EX_MOUSE);
}