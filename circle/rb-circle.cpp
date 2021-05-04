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
		cout << "1: 초기 위치로 이동" << endl;
		cout << "2: 정해진 원 동작 수행" << endl;

		rb::Joint initial(0, 29.73, 36.17, 79.92, 0, -36.03);
		rb::Point c1(890.06, -621.56, 979.81, -179.98, 70.21, -179.98);
		rb::Point c2(902.4, -621.56, 890.16, -179.98, 70.21, -179.98);
		
		DOUT_PORT port;

		while (true) {
			cin >> input;
			switch (input) {
			case '1':
				cobot.MoveJ(0, 0, 0, 0, 0, 0, 0.5, 0.5);
				break;
			case '2':
				cobot.MoveJ(initial, 0.5, 0.5);
				cobot.MoveCircle_ThreePoint(c1, c2, 0.5, 0.2, rb::CIRCLE_TYPE::CONSTANT);
				break;
			default:
				cout << "Invalid input value" << endl;
				break;

			}
		}
	}
}


