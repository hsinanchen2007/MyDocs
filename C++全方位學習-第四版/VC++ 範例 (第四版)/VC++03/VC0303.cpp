//�x�s�ɦW�Gd:\VC++03\VC0303\VC0303.cpp
#include <iostream>
#include <iomanip>	//�]�tsetw()�����D��
using namespace std;

int main(int argc, char** argv)
{
	int n11 = 14, n12 = 21474836, n13 = 44;
	int n21 = -889162, n22 = 9, n23 = 524;
	cout << setw(12) << n11 	//�]�w12�Ŷ���n11��X
		<< setw(12) << n12 	//�]�w12�Ŷ���n12��X
		<< setw(12) << n13	//�]�w12�Ŷ���n13��X
		<< endl;	//���ܤU�@��
	cout << setw(12) << n21 	//�]�w12�Ŷ���n21��X
		<< setw(12) << n22 	//�]�w12�Ŷ���n22��X
		<< setw(12) << n23 	//�]�w12�Ŷ���n23��X
		<< endl;	//���ܤU�@��
	return 0;
}
