// 猜数游戏（第1版：输入/输出部分）

#include <iostream>

using namespace std;

extern int max_no;

//--- 提示输入 ---//
static void prompt()
{
	cout << "0~" << max_no << "的数：";
}

//--- 输入答案 ---//
int input()
{
	int val;
	do {
		prompt();	// 提示输入
		cin >> val;
	} while (val < 0 || val > max_no);
	return val;
}

//--- 确认是否继续 ---//
bool confirm_retry()
{
	int cont;
	cout << "再试一次？\n"
		 << "<Yes...1/No...0>：";
	cin >> cont;
	return static_cast<bool>(cont);
}
