//儲存檔名：d:\C++06\C0621.cpp
#include <iostream>
#include <iomanip>
using namespace std;

#define	BEGIN  {	//定義起始符號
#define	END    }	//定義結束符號
#define	TAB    '\t'	//定義定位符號
#define	PI     3.14159	//定義常數符號

int main(int argc, char** argv)
BEGIN				//使用起始符號
	cout << "半徑\t圓周長\t   圓面積\n";
	cout.precision(3); cout.setf(ios::fixed);	//設定輸出格式
	for (int r = 5; r <= 10; r++)	//顯示計算值迴圈
	BEGIN				//使用起始符號
		cout << setw(3) << r << TAB;	//顯示圓半徑值
		cout << setw(6) << 2 * PI * r << TAB;	//顯示圓周長值
		cout << setw(9) << PI * r * r << endl;	//顯示圓面積值
	END			//使用結束符號
	return 0;
END				//使用結束符號
