#include <iostream>
#include "../rb-api/include/rb-world.h"

//debug
#pragma comment(lib, "../rb-api/x64/debug/rb-apid.lib")

using namespace rb;

int main()
{
	Cobot cobot;

	//버전 확인
	cobot.__Version();

	//컨트롤 박스 연결
	bool ret = cobot.ConnectToCB();

	if (!ret) {
		cout << "제어박스의 IP 주소를 확인하세요" << endl;
	}
	else {
		char input;
		Point p1(580, -420, 1050, 0, 0, 0);
		Point p2(450, -400, 1040, -15, -30, 50);
		

		float spd = 0.5;
		float acc = 0.5;
		cout << "RB-10 기준 좌표 작성됨" << endl;
		cout << "1: p1 위치로 움직임\t" << p1 << endl;
		cout << "2: p2 위치로 움직임\t" << p2 << endl;

		cobot.SetProgramMode(PG_MODE::SIMULATION);

		while (true) {
			cin >> input;
			switch (input) {
			case '1':
				cobot.MoveJ(0, 45, -80, 0, 0, 0, spd, acc);
				cobot.MoveL(p1, spd, acc);
				break;
			case '2':
				cobot.MoveJ(0, 45, -80, 0, 0, 0, spd, acc);
				cobot.MoveL(p1, spd, acc);
				cobot.MoveL(p2, spd, acc);
				break;
			default:
				cout << "Invalid input value" << endl;
				break;

			}
		}
	}
}


