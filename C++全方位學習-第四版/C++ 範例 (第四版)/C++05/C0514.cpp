//�x�s�ɦW�Gd:\C++05\C0514.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
	int count = 1, factor = 1;	//while �j����
	cout << "�p��\t" << setw(8) << "����\n";	//��X�r��
	do				//do �j��
	{
		factor *= count;	//�p�ⶥ��
		cout << setw(3) << count << '\t';	//��X�p�ƭ�
		cout << setw(7) << factor << endl;	//��X����
	} while (++count <= 10);	//count<=10�j���~��
	return 0;
}
