// 读入5个人的分数并显示总分和平均分

#include <iostream>

using namespace std;

int main()
{
	int wangming, liyang, zhanghong, zhaogang, zhouyan;	// 分数
	int sum = 0;		// 总分

	cout << "计算5个人的总分和平均分。\n";
	cout << "第1个人的分数：";   cin >> wangming;    sum += wangming;
	cout << "第2个人的分数：";   cin >> liyang;    sum += liyang;
	cout << "第3个人的分数：";   cin >> zhanghong;  sum += zhanghong;
	cout << "第4个人的分数：";   cin >> zhaogang;   sum += zhaogang;
	cout << "第5个人的分数：";   cin >> zhouyan;    sum += zhouyan;

	cout << "总分为" << sum << "。\n";
	cout << "平均分为" << static_cast<double>(sum) / 5 << "。\n";
}
