//儲存檔名：d:\VC++06\VC0620\VC0620.cpp
#include <iostream>
using namespace std;

#define	PI 3.14159	//定義符號 PI

int main(int argc, char** argv)
{
	int r = 5;
	cout << "圓半徑 = " << r;	//顯示圓半徑值
	cout << "\n圓周長 = " << 2 * PI * r;	//顯示圓周長值
	cout << "\n圓面積 = " << PI * r * r;	//顯示圓面積值
	cout << endl;
	return 0;	//告訴OS程式正常結束
}
