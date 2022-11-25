// 读入5个人的分数并显示总分和平均分

#include <iostream>

using namespace std;

int main()
{
	const int number = 5    //人数
	int score[number];		// number个人的分数
	int sum = 0;		// 总分

	cout << "计算"<<number<<"个人的总分和平均分。\n";
	for (int i = 0; i < number; i++) {
		cout << "第" << i + 1 << "个人的分数：";
		cin >> score[i];		// 读入score[i]
		sum += score[i];		// 把score[i]加到sum上
	}

	cout << "总分为" << sum << "。\n";
	cout << "平均分为" << static_cast<double>(sum) / 5 << "。\n";
}
