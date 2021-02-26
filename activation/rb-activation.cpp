#include <iostream>
#include "../rb-api/include/rb-world.h"

#pragma comment(lib, "../rb-api/x64/debug/rb-api.lib")

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


