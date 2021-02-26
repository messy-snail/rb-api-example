#include <iostream>
#include "../rb-api/include/rb-world.h"

#pragma comment(lib, "../rb-api/x64/debug/rb-api.lib")

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

		while (true) {
			cin >> input;
			switch (input) {
			case '1':
				cobot.CobotInit();
				break;
			case '2':
				cobot.SetProgramMode(PG_MODE::REAL);
				break;
			case '3':
				cobot.SetProgramMode(PG_MODE::SIMULATION);
				break;
			default:
				cout << "Invalid input value" << endl;
				break;

			}
		}
	}
}


