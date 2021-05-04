#include <iostream>
#include "../rb-api/include/rb-world.h"

//debug
//#pragma comment(lib, "../rb-api/x64/debug/rb-apid.lib")
#pragma comment(lib, "../rb-api/x64/release/rb-api.lib")

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
		
		cout << "1: 흡기 HIGH, LOW" << endl;
		cout << "2: 배기 LOW, HIGH" << endl;
		cout << "3: 정상 LOW, LOW" << endl;

		DOUT_PORT port;
		
		while (true) {
			cin >> input;
			switch (input) {
			case '1':
				port.d0 = SIGNAL_HIGH;
				port.d1 = SIGNAL_LOW;
				cobot.ControlBoxDigitalOut(port);
				break;
			case '2':
				port.d0 = SIGNAL_LOW;
				port.d1 = SIGNAL_HIGH;
				cobot.ControlBoxDigitalOut(port);
				break;
			case '3':
				port.d0 = SIGNAL_LOW;
				port.d1 = SIGNAL_LOW;
				cobot.ControlBoxDigitalOut(port);
				break;
			default:
				cout << "Invalid input value" << endl;
				break;

			}
		}
	}
}


