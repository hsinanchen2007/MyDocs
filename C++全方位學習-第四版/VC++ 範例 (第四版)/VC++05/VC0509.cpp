//�x�s�ɦW�Gd:\VC++05\VC0509\VC0509.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	double count = 0;	//while�j����
	double power;	//�ŧipower�ܼ�
	cout << "�p��\t" << "2��n����\n";	//��X�r��
	while (count++ < 10)	//�P�_count<10��A�[1
	{
		power = pow(2, count);	//�p��2��n����
		cout << setw(3) << count << '\t';	//��X�p�ƭ�
		cout << setw(6) << power << endl;	//��X2��n�����
	}
	return 0;
}
