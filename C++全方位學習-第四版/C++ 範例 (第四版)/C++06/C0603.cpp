//纗郎d:\C++06\C0603.cpp
#include <iostream>
using namespace std;

void grandUser(void)	//ㄏノㄧ计2
{
	cout << "秈 grandUser ㄧ计\n";
}

void childUser(void)	//ㄏノㄧ计1
{
	cout << "秈 childUser ㄧ计\n";
	grandUser();	//㊣grandUserㄧ计
	cout << " childUser ㄧ计\n";
}

int main(int argc, char** argv)
{
	cout << "癬﹍ main ㄧ计\n";
	childUser();	//㊣childUser
	cout << " main ㄧ计\n";
	return 0;
}
