//d:\Ex16\Ex1603.cpp
//min 籔 max ㄧ计絛セ
#include <iostream>

using namespace std;

template <class X>
X min(X &a, X &b)
{
	X temp;
	if(a > b)
	    temp = b;
	else if(b > a)
	    temp = a;
	else
	    temp = a;
	return temp;
}

template <class Y>
Y max(Y &a, Y &b)
{
	Y temp;
	if(a > b)
	    temp = a;
	else if(b > a)
	    temp = b;
	else
	    temp = a;
	return temp;
}

int main(int argc, char** argv) {
	int m = 4, n = 10;
	float x = 6.33, y = 3.66;
	double a = 5.75, b = 5.75;

	cout << m << ", " << n << " 程 = " << min(m, n) << endl;
	cout << m << ", " << n << " 程 = " << max(m, n) << endl;
	cout << x << ", " << y << " 程 = " << min(x, y) << endl;
	cout << x << ", " << y << " 程 = " << max(x, y) << endl;
	cout << a << ", " << b << " 程 = " << min(a, b) << endl;
	cout << a << ", " << b << " 程 = " << max(a, b) << endl;
	system("PAUSE");
	return 0;
}
