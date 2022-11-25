// 纗郎d:\VC++06\VC0605\VC0605.cpp
#include <iostream>
using namespace std;

void number(int n);	//ㄧ计

int main(int argc, char** argv)
{
	number(5);	//肚患5倒numberㄧ计
	number(58);	//肚患58倒numberㄧ计
	number(135);	//肚患135倒numberㄧ计
	return 0;
}

void number(int n)	//耞5计ㄧ计
{
	if (n % 5 == 0)	//璝把计n埃5緇计0
		cout << n << " 琌 5 计\n";
	else
		cout << n << " ぃ琌 5 计\n";
}
