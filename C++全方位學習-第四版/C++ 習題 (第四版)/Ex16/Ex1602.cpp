//d:\Ex16\Ex1604.cpp
//min �P max ��ƽd��
#include <iostream>
using namespace std;

template <class X>
void total(X &s, X a)
{
	s += a;
}

int main(int argc, char** argv) {
	float Sum = 0.0, x = 0.0;
	do {
	    total(Sum, x);
	    cout << "�п�J�ƭ� (��J0�h����): ";
	    cin >> x;
	} while(x != 0);
	cout << "�`�M = " << Sum << endl;
	system("PAUSE");
	return 0;
}
