//�ɮצW�١Gd:\VC++09\VC0915\VC0915.cpp
#include <iostream>
#include <string>	//C++���Astring���D��
using namespace std;

int main(int argc, char** argv)
{
	string s1("Dev/Visual C++");	//�ŧi�ð_�l�r��s1
	string s2("Visual C++");	//�ŧi�ð_�l�r��s2

	if (s1.compare(s2) == 0)	//���s1�Ps2
		cout << s1 << " == " << s2;	//��X�r��
	else
		cout << s1 << " != " << s2;	//��X�r��
	cout << endl;

	if (s1.compare(11, 3, s2, 7, 3) == 0)	//���s1�Ps2���l�r��
		cout << s1.substr(11, 3) << " == " << s2.substr(7, 3);	//��X�l�r��
	else
		cout << s1.substr(11, 3) << " != " << s2.substr(7, 3);	//��X�l�r��
	cout << endl;
	return 0;
}
