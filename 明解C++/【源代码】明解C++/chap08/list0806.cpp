// ÏÔÊ¾½ÓÊÕµÄ×Ö·û´®

#include <iostream>

using namespace std;

//--- ÏÔÊ¾×Ö·û´®s ---//
void put_str(const char s[])
{
	for (int i = 0; s[i] != 0; i++)
		cout << s[i];
}

int main()
{
	char str[36];

	put_str("×Ö·û´®£º");
	cin >> str;

	put_str(str);
	cout << '\n';
}
