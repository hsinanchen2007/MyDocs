//�x�s�ɦW�Gd:\C++06\C0601.cpp
#include <iostream>
using namespace std;

void womain(void)	//�ϥΪ̨��
{
	cout << "Womain: I'm doing good. How about you?";
	cout << endl;
}

int main(int argc, char** argv)
{
	cout << "Main: Hi! How are you doing?" << endl;
	womain();	//�I�s�ϥΪ̨��womain
	cout << "Main: Very well! Thank you!" << endl;
	return 0;
}
