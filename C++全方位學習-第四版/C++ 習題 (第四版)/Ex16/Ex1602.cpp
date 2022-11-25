//d:\Ex16\Ex1604.cpp
//min 與 max 函數範本
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
	    cout << "請輸入數值 (輸入0則結束): ";
	    cin >> x;
	} while(x != 0);
	cout << "總和 = " << Sum << endl;
	system("PAUSE");
	return 0;
}
