//�x�s�ɦW�Gd:\VC++04\VC0413\VC0413.cpp
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	char inChar;
	cout << "a. �s�W���\tb. ���J���\tc. �R�����\t��L. �����{���G";
	cin >> inChar;	//inChar=��J�r��
	switch (inChar)
	{
	case 'A':	//�YinChar��A�r��
	case 'a':	//��inChar��a�r��
		cout << "�s�W���\n";
		break;
	case 'B':	//�YinChar��B�r��
	case 'b':	//��inChar��b�r��
		cout << "���J���\n";
		break;
	case 'C':	//�YinChar��C�r��
	case 'c':	//��inChar��c�r��
		cout << "�R�����\n";
		break;
	default:	//inChar����L�r��
		cout << "�����{��\n";
	}
	return 0;
}
