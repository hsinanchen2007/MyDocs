//�x�s�ɦW�Gd:\C++04\C0412.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	char letter;
	int num1 = 75, num2 = 15;
	cout << "num1 = 75, num2 = 15 \n";
	cout << "�п�� +,-,*,/ �G";
	cin >> letter;	//��J�r���æs�Jletter
	switch (letter)
	{
		case '+':	//�Y letter = '+'
			cout << "num1 + num2 = " << num1 + num2;
			cout << endl; break;	//����B�ø��Xswitch
		case '-':	//�Y letter = '-'
			cout << "num1 - num2 = " << num1 - num2;
			cout << endl; break;	//����B�ø��Xswitch
		case '*':	//�Y letter = '*'
			cout << "num1 * num2 = " << num1 * num2;
			cout << endl; break;	//����B�ø��Xswitch
		case '/':	//�Y letter = '/'
			cout << "num1 / num2 = " << num1 / num2;
			cout << endl; break;	//����B�ø��Xswitch
	}
	return 0;
}
