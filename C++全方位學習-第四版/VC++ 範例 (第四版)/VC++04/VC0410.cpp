//�x�s�ɦW�Gd:\VC++04\VC0410\VC0410.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	short num1, num2, sum;

	cout << "�п�J�u��� 1�G";
	cin >> num1;	//��J�r���æs�Jnum1
	cout << "�п�J�u��� 2�G";
	cin >> num2;	//��J�r���æs�Jnum2
	if ((num1 + num2) > 32767) {	//�Ynum1+num2 > 32767
		cout << num1 << " + " << num2;
		cout << " = �W������\n";	//  ��ܿ��~�T��
	}
	else if ((num1 + num2) < -32768) {	//�Ynum1+num2 < -32768
		cout << num1 << " + (" << num2;
		cout << ") = �U������\n";	//  ��ܿ��~�T��
	}
	else {			//�H�W�ҫD
		sum = num1 + num2;
		cout << num1 << " + " << num2;
		cout << " = " << sum << endl;	//  ��ܹB���
	}
	return 0;
}
