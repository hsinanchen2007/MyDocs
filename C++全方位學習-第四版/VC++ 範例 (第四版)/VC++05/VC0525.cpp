//�x�s�ɦW�Gd:\VC++05\VC0525\VC0525.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int a, b, n;	//�ŧi�ܼ�
	cout << "�п�J�G�Ӿ�� (a b)�G";	//��X�T��
	cin >> a >> b;	//��Ja, b�G��
	for (n = a; n <= a * b; n += a)
		if (n%b == 0)	//a�����ư��Hb����0
			break;		//���_�j��
	cout << "LCM = " << n << endl;		//��XLCM
	return 0;
}
