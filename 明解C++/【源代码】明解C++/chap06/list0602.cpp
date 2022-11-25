// 求出三个人的数学和英语的最高分并显示（函数版）

#include <iostream>

using namespace std;

//--- 返回a、b、c中的最大值 ---//
int max(int a, int b, int c)
{
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	return max;
}

int main()
{
	int math[3];	// 数学
	int eng[3];		// 英语

	for (int i = 0; i < 3; i++) {	// 读入分数
		cout << "[" << i + 1 << "] ";
		cout << "数学：";		cin >> math[i];
		cout << "    英语：";	cin >> eng[i];
	}

	int max_math = max(math[0], math[1], math[2]);	// 数学最高分
	int max_eng  = max(eng[0],  eng[1],  eng[2]);	// 英语最高分

	cout << "数学最高分为" << max_math << "。\n";
	cout << "英语最高分为" << max_eng  << "。\n";
}
