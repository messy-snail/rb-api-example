#include <iostream>
#include "../rb-api/include/rb-world.h"

//debug
#pragma comment(lib, "../rb-api/x64/debug/rb-apid.lib")

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
		Joint j1(90, -90, 90, 45, -45, 45);
		Joint j2(45, 45, 45, 90, 0, -90);
		Joint j3 = j1 + j2;

		float spd = 0.5;
		float acc = 0.5;
		cout << "RB-10 ���� ��ǥ �ۼ���" << endl;
		cout << "1: j1 ��ġ�� ������\t" << j1 << endl;
		cout << "2: j2 ��ġ�� ������\t" << j2 << endl;
		cout << "3: j3 ��ġ�� ������\t" << j3 << endl;

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


