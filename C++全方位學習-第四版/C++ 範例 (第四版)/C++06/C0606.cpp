// �x�s�ɦW�Gd:\C++06\C0606.cpp
#include <iostream>
using namespace std;

void sum(int, int, int);	//�ŧi��ƭ쫬

int main(int argc, char** argv)
{
	sum(95, 24, 657);	//�ǻ�3�ӰѼƵ�sum���
	sum(562, 194, 817);	//�ǻ�3�ӰѼƵ�sum���
	sum(16, 256, 1024);	//�ǻ�3�ӰѼƵ�sum���
	return 0;
}

void sum(int a, int b, int c)	//�p���`�M���
{
	cout << a << " + " << b << " + " << c;
	cout << " = " << a + b + c << endl;	//�p��ÿ�X�`�M
}
