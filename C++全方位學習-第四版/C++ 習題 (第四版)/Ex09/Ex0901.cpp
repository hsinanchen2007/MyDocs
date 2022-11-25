//d:\Ex09\Ex0902.cpp
//計算英文單字個數
#include <iostream>
#include <cctype>
#include <cstring> 
using namespace std;

int wordCount(char []);

int main(int argc, char** argv) {
	char str[80];
	cout << "請輸入字串 (可含空白)：";
	cin.getline(str, 81);

	cout << "字串：" << str << endl;
	cout << "字串中含有 " << wordCount(str) << " 個單字" << endl;
	system("PAUSE");
	return 0;
}

int wordCount(char array[])
{
	int len = strlen(array);
	bool aflag = false;
	int n = 0;

	for (int i=0; i<=len; i++) {
		if (isalpha(array[i]) != 0) {
			if(aflag == false) {
				n++;
				aflag = true;
			}
		} else {
			aflag = false;
		}
	}
	return n;
}
