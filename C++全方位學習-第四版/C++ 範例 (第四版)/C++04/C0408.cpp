//�x�s�ɦW�Gd:\C++04\C0408.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	char letter;
	cout << "�Ы����r��A�A�� Enter�G";
	cin >> letter;	//��J�r���æs�Jletter
	if (letter >= 'A' && letter <= 'Z')	//�Y'A'<=letter<='Z'�h
		cout << letter << " ���j�g��\n";	//   ��X�r��õ��� if
	else if (letter >= 'a' && letter <= 'z')	//�Y'a'<=letter<='z'�h
		cout << letter << " ���p�g��\n";	//  ��X�r��õ��� if
	else if (letter >= '0' && letter <= '9')	//�Y'0'<=letter<='9'�h
		cout << letter << " ���Ʀr��\n";	//  ��X�r��õ��� if
	else			//�H�W�ҫD�h
		cout << letter << " ���Ÿ���\n";	//  ��X�r��õ��� if
	return 0;
}
