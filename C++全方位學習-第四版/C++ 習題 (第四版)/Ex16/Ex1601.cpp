//d:\Ex16\Ex1603.cpp
//min �P max ��ƽd��
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

	cout << m << ", " << n << " ���̤p�� = " << min(m, n) << endl;
	cout << m << ", " << n << " ���̤j�� = " << max(m, n) << endl;
	cout << x << ", " << y << " ���̤p�� = " << min(x, y) << endl;
	cout << x << ", " << y << " ���̤j�� = " << max(x, y) << endl;
	cout << a << ", " << b << " ���̤p�� = " << min(a, b) << endl;
	cout << a << ", " << b << " ���̤j�� = " << max(a, b) << endl;
	system("PAUSE");
	return 0;
}
