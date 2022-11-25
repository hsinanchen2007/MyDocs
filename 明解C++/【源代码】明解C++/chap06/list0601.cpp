// 求出三个人的数学和英语的最高分并显示

#include <iostream>

using namespace std;

int main()
{
	int math[3];	// 数学分数
	int eng[3];		// 英语分数

	for (int i = 0; i < 3; i++) {	// 读入分数
		cout << "[" << i + 1 << "] ";
		cout << "数学：";		cin >> math[i];
		cout << "    英语：";	cin >> eng[i];
	}

	int max_math = math[0];	  // 数学最高分
	if (math[1] > max_math) max_math = math[1];
	if (math[2] > max_math) max_math = math[2];

	int max_eng = eng[0];	  // 英语最高分
	if (eng[1] > max_eng) max_eng = eng[1];
	if (eng[2] > max_eng) max_eng = eng[2];

	cout << "数学最高分为" << max_math << "。\n";
	cout << "英语最高分为" << max_eng  << "。\n";
}
