//�ɮצW�١Gd:\VC++09\VC0917\VC0917.cpp
#include <iostream>
#include <string>	//C++���Astring���D��
using namespace std;

int main(int argc, char** argv)
{
	string s1("Dev/Visual C++"), s2("C++");
	int p1, p2;

	p1 = s1.find(s2);	// p1 = 7 (���A��m7)
	if (p1 != -1)	//�P�_�bs1���O�_���s2
		cout << s1 << " ���� " << p1 << " �r����m��� " << s2;	//��X��m
	else
		cout << s1 << " ���䤣�� " << s2;	//��X�r��
	cout << endl;

	p2 = s1.find("C#");	// p2 = -1 (�䤣��)
	if (p2 != -1)	//�P�_�bs1���O�_���Visual
		cout << s1 << " ���� " << p2 << " �r����m��� C#";	//��X��m
	else
		cout << s1 << " ���䤣�� C#";	//��X�r��
	cout << endl;
	return 0;
}
