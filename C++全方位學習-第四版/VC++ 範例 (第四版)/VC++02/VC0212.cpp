//�x�s�ɦW�Gd:\VC++02\VC0212\VC0212.cpp
#include <iostream>
#include <cfloat>
using namespace std;

const float PI = 3.14159f;	//�ŧi�`��PI = 3.14159

int main(int argc, char** argv)
{
	char str1[] = "���� pi = ";	//�ŧi�r��str1
	char str2[] = "����� val = ";	//�ŧi�r��str2
	double val = 4.5e+101;	//�ŧival = 4.5e+101
	cout << str1 << PI << endl	//��X�r��B���ơB����
		<< str2 << val << endl;	//��X�r��B�����
	return 0;
}
