#include <iostream>
#include "maxof.h"

using namespace std;

int main()
{
	int a, b;
	char s[64], t[64];

	cout << "整数a：";	  cin >> a;
	cout << "整数b：";	  cin >> b;
	cout << "字符串s：";  cin >> s;
	cout << "字符串t：";  cin >> t;

	cout << "a和b中的较大值为" <<       maxof(a, b)                  << "。\n";
	cout << "s和t中的较大值为" <<       maxof<const char*>(s, t)     << "。\n";
	cout << "s和\"ABC\"中的较大值为" << maxof<const char*>(s, "ABC") << "。\n";
}
