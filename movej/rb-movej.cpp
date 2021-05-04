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
		Joint j1(90, -90, 90, 45, -45, 45);
		Joint j2(45, 45, 45, 90, 0, -90);
		Joint j3 = j1 + j2;

		float spd = 0.5;
		float acc = 0.5;
		cout << "RB-10 기준 좌표 작성됨" << endl;
		cout << "1: j1 위치로 움직임\t" << j1 << endl;
		cout << "2: j2 위치로 움직임\t" << j2 << endl;
		cout << "3: j3 위치로 움직임\t" << j3 << endl;

		cobot.SetProgramMode(PG_MODE::SIMULATION);

		while (true) {
			cin >> input;
			switch (input) {
			case '1':
				cobot.MoveJ(j1, spd, acc);
				break;
			case '2':
				cobot.MoveJ(j2, spd, acc);
				break;
			case '3':
				cobot.MoveJ(j3, spd, acc);				
				break;
			default:
				cout << "Invalid input value" << endl;
				break;

			}
		}
	}
}


