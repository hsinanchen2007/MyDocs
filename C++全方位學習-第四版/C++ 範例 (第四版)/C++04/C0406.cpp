//�x�s�ɦW�Gd:\C++04\C0406.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	short num1, num2, sum;

	cout << "�п�J�u��� 1�G";
	cin >> num1;	//��J�u��ƨæs�Jnum1
	cout << "�п�J�u��� 2�G";
	cin >> num2;	//��J�u��ƨæs�Jnum2
	if ((num1 + num2) > 32767) {	//�Ynum1+num2 > 32767
		cout << num1 << " + " << num2 << " = �W������\n";	//  ��ܿ��~�T��
	} else {			//�Ynum1+num2 <= 32767
		sum = num1 + num2;
		cout << num1 << " + " << num2 << " = " << sum << endl;	//  ��ܹB���
	}
	return 0;
}
