#include <iostream>
#include "../rb-api/include/rb-world.h"

//debug
//#pragma comment(lib, "../rb-api/x64/debug/rb-apid.lib")
#pragma comment(lib, "../rb-api/x64/release/rb-api.lib")

using namespace rb;

int main()
{
	Cobot cobot;

	//���� Ȯ��
	cobot.__Version();

	//��Ʈ�� �ڽ� ����
	bool ret = cobot.ConnectToCB();

	if (!ret) {
		cout << "����ڽ��� IP �ּҸ� Ȯ���ϼ���" << endl;
	}
	else {
		char input;
		
		cout << "1: ��� HIGH, LOW" << endl;
		cout << "2: ��� LOW, HIGH" << endl;
		cout << "3: ���� LOW, LOW" << endl;

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


