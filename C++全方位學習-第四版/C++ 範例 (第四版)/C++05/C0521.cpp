//儲存檔名：d:\C++05\C0521.cpp
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main(int argc, char** argv)
{
	cout.setf(ios::fixed | ios::right);	//設定輸出向右對齊
	cout.fill('0');		//若左邊空白則補0
	while (true)	//無窮迴圈
	{
		for (int hrs=0; hrs<24; hrs++)	//時: 從 0 數到 23
		{
			for (int min=0; min<60; min++)	//分: 從 0 數到 59
			{
				for (int sec=0; sec<60; sec++)	//秒: 從 0 數到 59
				{
				    cout << setw(2) << hrs << ':';	//輸出時數
				    cout << setw(2) << min << ':';	//輸出分鐘數
				    cout << setw(2) << sec << ' ';	//輸出秒數
					cout << '\r';					//游標移至前面 
				    unsigned int startTime = time(0)+1;
				    while(time(0)<startTime);	//延遲1秒迴圈 
				}
			}
		}
	}
	return 0;
}
