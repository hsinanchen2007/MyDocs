//�ɮצW�١Gd:\VC++09\VC0907\VC0907.cpp
#include <iostream>
#include <iomanip>
#include <cstdlib>	//�ഫ�ƭȼ��D��
using namespace std;

int main(int argc, char** argv)
{
	char intArray[10];

	_itoa_s(1234, intArray, 8);	//1234�ন�r��"2322"
	cout << "1234�ন�K�i�쫬�A�r��G\"" << intArray << "\"\n";

	_itoa_s(1234, intArray, 10);	//1234�ন�r��"1234"
	cout << "1234�ন�Q�i�쫬�A�r��G\"" << intArray << "\"\n";

	_itoa_s(1234, intArray, 16);	//1234�ন�r��"4d2"
	cout << "1234�ন�Q���i�쫬�A�r��G\"" << intArray << "\"\n";
	return 0;
}
