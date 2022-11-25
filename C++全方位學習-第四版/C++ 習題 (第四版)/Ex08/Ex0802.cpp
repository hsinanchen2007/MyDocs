//d:\Ex08\Ex0806.cpp
//反向輸出字串
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int reverse(char *, int);

int main(int argc, char** argv) {
	char str[80];
	cout << "請輸入英文字串：";
	cin.getline(str, 81);

	int len = strlen(str);
	cout << "輸出反向後字串：";
	reverse(str, len-1);
	system("PAUSE");
	return 0;
}

int reverse(char *array, int n)
{
	if (n >= 0) {
		cout << array[n];
		return reverse(array, n-1);
	} else {
		cout << endl;
		return 0;
	}

}
