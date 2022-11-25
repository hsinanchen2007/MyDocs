//檔案名稱：d:\C++09\C0912.cpp
#include <iostream>
#include <string>	//C++型態string標題檔
using namespace std;

void sortArray(string array[]);

int main(int argc, char** argv)
{
	string s1[] = {"Java", "Assembly", "Delpha",
		       "Basic", "Fortran", "Cobol"};	//宣告字串陣列
	cout << "排序前：";	//顯示排序前資料
	for (int i=0; i<5; i++)
		cout << s1[i] << '\0';
	sortArray(s1);	//傳遞s1給sortArray
	cout << "\n排序後：";	//顯示排序後資料
	for (int j=0; j<5; j++)
		cout << s1[j] << '\0';
	cout << endl;
	return 0;
}

void sortArray(string array[])	//氣泡排序函數
{
	string buffer;	//宣告緩衝器變數
	for (int i=0; i<4; i++)	//排序外迴圈
		for (int j=i; j<5; j++)	//排序內迴圈
			if (array[i] > array[j])	//若須要則對調
			{
				buffer = array[i];
				array[i] = array[j];
				array[j] = buffer;
			}
}
