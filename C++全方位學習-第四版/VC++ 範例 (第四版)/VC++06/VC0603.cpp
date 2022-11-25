//纗郎d:\VC++06\VC0603\VC0603.cpp
#include <iostream>
using namespace std;

void grandUser(void)	//ㄏノㄧ计2
{
	cout << "秈 grandUser ㄧ计\n";
}

void subUser(void)	//ㄏノㄧ计1
{
	cout << "秈 subUser ㄧ计\n";
	grandUser();	//㊣grandUserㄧ计
	cout << " subUser ㄧ计\n";
}

int main(int argc, char** argv)
{
	cout << "癬﹍ main ㄧ计\n";
	subUser();	//㊣subUser
	cout << " main ㄧ计\n";
	return 0;
}
