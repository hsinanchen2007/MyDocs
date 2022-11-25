// 猜数游戏（第2版：主要部分）

#include <iostream>
#include "caishu.h"

using namespace std;

int max_no = 9;			// 要猜的数的最大值

int main()
{
	initialize();		// 初始化
	cout << "猜数游戏开始！\n";

	do {
		gen_no();		// 生成问题（要猜的数）
		int panduan;
		do {
			panduan = judge(input());	// 判断答案
			if (panduan == 1)
				cout << "\a再小一点。\n";
			else if (panduan == 2)
				cout << "\a再大一点。\n";
		} while (panduan != 0);
		cout << "正确答案。\n";
	} while (confirm_retry());
}
