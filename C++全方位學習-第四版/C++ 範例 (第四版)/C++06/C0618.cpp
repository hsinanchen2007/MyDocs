//儲存檔名：d:\C++06\C0618.cpp
#include <iostream>
using namespace std;

int total(int);	//宣告函數原型

int main(int argc, char** argv)
{
	int count, oddsum;	//宣告區域變數
	for (count = 1; count <= 100; count += 2)	//呼叫函數迴圈
		oddsum = total(count);	//oddsum=函數傳回值
	cout << "1+3+5+...+99=" << oddsum;	//顯示最後oddsum值
	cout << endl;
	return 0;
}

int total(int n)	//計算總和函數
{
	static int sum;	//宣告靜態變數
	sum += n;	//sum(n+1)=sum(n)+n
	return sum;	//返回並傳回sum
}
