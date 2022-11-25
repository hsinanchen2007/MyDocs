// 询问姓名并打招呼（读入并显示字符串）
// 包括空字符在内，限制读入36个字符

#include <iostream>

using namespace std;

int main()
{
	char name[36];

	cout << "姓名：";
	cin.getline(name, 36, '\n');

	cout << "你好，" << name << "!!\n";
}
