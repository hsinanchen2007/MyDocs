//�x�s�ɦW�Gd:\VC++06\VC0604\VC0604.cpp
#include <iostream>
using namespace std;

void womain(void);	//�ŧi�ϥΪ̨�ƭ쫬

int main(int argc, char** argv)
{
	cout << "Main: Hi! How are you doing?" << endl;
	womain();	//�I�s�ϥΪ̨��womain
	cout << "Main: Very well! Thank you!" << endl;
	return 0;
}

void womain(void)	//�ϥΪ̨��
{
	cout << "Womain: I'm doing good. How about you?";
	cout << endl;
}
