//纗郎d:\C++06\C0610.cpp
#include <iostream>
using namespace std;

void weight(float lb = 1.0);	//,﹚把计箇砞

int main(int argc, char** argv)
{
	weight(150.0);	//肚患把计150.0
	weight(170.0);	//肚患把计170.0
	weight();	//肚患箇砞把计1
	return 0;
}

void weight(float lb)	//秖锣传ㄧ计
{
	cout << lb << "絊 = " << lb / 2.20462 << "そょ";	//陪ボㄧ计肚
	cout << endl;
}
