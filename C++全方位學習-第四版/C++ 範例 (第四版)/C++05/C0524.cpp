//�x�s�ɦW�Gd:\C++05\C0524.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int a, b, n;	//�ŧi�ܼ�
	cout << "�п�J�G�Ӿ�� (a b)�G";	//��X�T��
	cin >> a >> b;	//��Ja, b�G��
	for(n=a; n>=1; n--)
		if(a%n==0 && b%n==0)	//�G�ư��Hn�ҵ���0
			break;		//���_�j��
	cout << "GCD = " << n << endl;		//��XGCD
	return 0;
}
