// strcat函数和strncat函数的使用例程

#include <cstring>
#include <iostream>

using namespace std;

int main(void)
{
	char s[10];
	char* x = "ABC";

	strcpy(s, "QWE");	// s变为"QWE"
	strcat(s, "RTY");	// s变为"QWERTY"
	cout << "s = " << s << '\n';

	strcpy(s, x);	strncat(s, "123", 1);		cout << "s = " << s << '\n';

	strcpy(s, x);	strncat(s, "123", 3);		cout << "s = " << s << '\n';

	strcpy(s, x);	strncat(s, "123", 5);		cout << "s = " << s << '\n';

	strcpy(s, x);	strncat(s, "12345", 5);		cout << "s = " << s << '\n';

	strcpy(s, x);	strncat(s, "123456789", 5);	cout << "s = " << s << '\n';
}
