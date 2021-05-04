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
		cout << "1: �ʱ� ��ġ�� �̵�" << endl;
		cout << "2: ������ �� ���� ����" << endl;

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


