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

		cout << "RB-10 기준 좌표 작성됨" << endl;
		cout << "1: 현재의 TCP 정보" << endl;
		cout << "2: 현재의 Joint 정보" << endl;

		Point current_point;
		Joint current_joint;

		while (true) {
			cin >> input;
			switch (input) {
			case '1':
				current_point = cobot.GetCurrentTCP();
				cout << "현재 TCP: "<<current_point << endl;
				break;
			case '2':
				current_joint = cobot.GetCurrentJoint();
				cout << "현재 Joint: " << current_joint << endl;
				break;
			default:
				cout << "Invalid input value" << endl;
				break;

			}
		}
	}
}


