//�x�s�ɦW�Gd:\C++03\C0308.cpp
#include <iostream>
#include <iomanip>	//�]�tsetw()�����D��
using namespace std;

int main(int argc, char** argv)
{
	char string[4];	//�ŧi�r���ܼ�string
	cout << "�п�J�r��G";	//��X�T���r��
	cin >> setw(4) >> string;	//�]�w��J�r�ƨè��o��J
	cout << "��J�r��O�G" << string << endl;	//��ܰT���P��J�r��
}
