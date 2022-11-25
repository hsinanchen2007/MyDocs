// strcmp函数和strncmp函数的使用例程

#include <cstring>
#include <iostream>

using namespace std;

int main(void)
{
	char st[128];

	cout << "\"与"ABCDE"进行比较。\n";
	cout << "\"以"XXXXX"结束。\n";

	while (1) {
		cout << "\n字符串st：";
		cin >> st;

		if (strcmp(st, "XXXXX") == 0)
			break;
		cout << "strcmp( \"ABCDE\", st)    = " << strcmp( "ABCDE", st) << '\n';
		cout << "strncmp(\"ABCDE\", st, 3) = " << strncmp("ABCDE", st, 3) << '\n';
	}
}