//�x�s�ɦW�Gd:\C++04\C0409.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	short number;
	cout << "�п�J���Z (0 - 100)�G";
	cin >> number;	//��J�ƭȨæs�Jnumber
	if (number >= 90 && number <= 100)	//�Y90<=number<=100�h
		cout << "���Z�ҵ�\n";	//   ��X�r��õ��� if
	else if (number >= 80 && number <= 89)	//�Y80<=number<=89�h
		cout << "���Z�A��\n";	//  ��X�r��õ��� if
	else if (number >= 70 && number <= 79)	//�Y70<=number<=79�h
		cout << "���Z����\n";	//  ��X�r��õ��� if
	else if (number >= 60 && number <= 69)	//�Y60<=number<=69�h
		cout << "���Z�B��\n";	//  ��X�r��õ��� if
	else if (number <= 59)	//�Ynumber<=59�h
		cout << "���Z����\n";	//  ��X�r��õ��� if
	return 0;
}
