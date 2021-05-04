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

		cout << "RB-10 ���� ��ǥ �ۼ���" << endl;
		cout << "1: ������ TCP ����" << endl;
		cout << "2: ������ Joint ����" << endl;

		Point current_point;
		Joint current_joint;

		while (true) {
			cin >> input;
			switch (input) {
			case '1':
				current_point = cobot.GetCurrentTCP();
				cout << "���� TCP: "<<current_point << endl;
				break;
			case '2':
				current_joint = cobot.GetCurrentJoint();
				cout << "���� Joint: " << current_joint << endl;
				break;
			default:
				cout << "Invalid input value" << endl;
				break;

			}
		}
	}
}


