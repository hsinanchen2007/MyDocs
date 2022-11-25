// 求身高的最大值和体重的最大值

#include <iostream>

using namespace std;

//--- 返回元素个数为n的数组a的最大值 ---//
int maxof(const int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

int main()
{
	const int number = 5;				// 人数
	int height[number], weight[number];	// 身高、体重

	cout << "请输入" << number << "个人的身高和体重。\n";
	for (int i = 0; i < number; i++) {
		cout << "第" << i + 1 << "个人的身高：";
		cin >> height[i];
		cout << "第" << i + 1 << "个人的体重：";
		cin >> weight[i];
	}
	int hmax = maxof(height, number);	// 身高的最大值
	int wmax = maxof(weight, number);	// 体重的最大值

	cout << "身高的最大值：" << hmax << "cm\n";
	cout << "体重的最大值：" << wmax << "kg\n";
}
