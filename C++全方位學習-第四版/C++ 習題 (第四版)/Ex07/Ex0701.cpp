//d:\Ex07\Ex0705.cpp
// 找尋最大值與最小值
#include <iostream>
using namespace std;

int findMax(int []);
int findMin(int []);
const int len = 19;

int main(int argc, char** argv) {
	int counti;
	int number[len] = {120, 92, 351, 66, 1024, 964, 47, 539, 76, 33,
			   88, 524, 67, 1000, 666, 737, 25, 999, 373};
	cout << "資料列：";
	for (counti = 0; counti < len; counti++)
		cout << number[counti] << '\0';

	cout << "\n最大值：" << findMax(number);
	cout << "\n最小值：" << findMin(number) << endl;
	system("PAUSE");
	return 0;
}

int findMax(int array[])
{
	int max = 0;
	for (int i = 0; i<len; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}

int findMin(int array[])
{
	int min = 2147483647;
	for (int i = 0; i<len; i++)
		if (array[i] < min)
			min = array[i];
	return min;
}
