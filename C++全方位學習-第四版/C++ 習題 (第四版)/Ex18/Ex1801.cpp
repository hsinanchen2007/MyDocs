//�x�s�ɦW�Gd:\Ex18\Ex1801.cpp
//�Q�λ��^��ƨD�T��GCD
#include <iostream>
using namespace std;

int gcd(int, int, int, int);

int main(int argc, char** argv) {
	int a, b, c, n;	//�ŧi�ܼ�
	cout << "�п�J�T�Ӿ�� (a b c)�G";	//��X�T��
	cin >> a >> b >> c;	//��Ja, b, c�T��
	n = a;
	cout << "GCD = " << gcd(a, b, c, n) << endl;		//��XGCD
	system("PAUSE");
	return 0;
}

int gcd(int a, int b, int c, int n)
{
	if(a%n==0 && b%n==0 && c%n==0)	//�T�ư��Hn�ҵ���0
		return n;
	else
		return gcd(a, b, c, n-1);
}
