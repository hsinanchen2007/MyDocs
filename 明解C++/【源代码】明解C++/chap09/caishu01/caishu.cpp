// 猜数游戏（第1版：主要部分）

#include <iostream>

using namespace std;

void initialize();			//【初始化】根据当前时刻设置随机数种子
void gen_no();				//【生成问题】用随机数生成0~max_no的值
int judge(int cand);		//【判断答案】判断cand是否为正确答案
int input();				//【输入答案】输入0~max_no的值
bool confirm_retry();		//【确认是否继续】确认是否再试一次

int max_no = 9;		// 要猜的数的最大值

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
			else if (hantei == 2)
				cout << "\a再大一点。\n";
		} while (panduan != 0);
		cout << "正确答案。\n";
	} while (confirm_retry());
}