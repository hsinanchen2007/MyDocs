// Sum.cpp
// 要求使用者輸入兩個整數，並把計算結果輸出
// --------------------------------------
// Copyright (c) Yau-Zen Chang (2003.10-) 
// All Rights Reserved.
// 本程式版權屬於 張耀仁
// 使用時必需聲明.
// --------------------------------------
#include <iostream>
using namespace std;

int main()
{
	int x;   // 第一個輸入整數
	int y;   // 第二個輸入整數
	int Sum; // 兩個整數的和

	cout << "請輸入第一個整數\n";
	cin  >> x;
	cout << "請輸入第二個整數\n";
	cin  >> y;
	Sum = x + y;
	cout << "這兩個整數的和是: " << Sum << endl;

	system("PAUSE");
	return 0;
}
