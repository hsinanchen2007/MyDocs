//d:\Ex10\Ex1002.cpp
//時間類別
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

struct Time
{
	int hour;
	int minute;
	int second;
};

int main(int argc, char** argv) {
	Time clock;

	cout << "請輸入目前時間(時 分 秒)：";
	cin >> clock.hour >> clock.minute >> clock.second;
	int hrs = clock.hour, min = clock.minute, sec = clock.second;
	
	cout.setf(ios::fixed | ios::right);
	cout.fill('0');

	while (true)
	{
		for(; hrs<24; hrs++)
		{
			for(; min<60; min++)
			{
				for(; sec<60; sec++)
				{
				    cout << setw(2) << hrs << ':';
				    cout << setw(2) << min << ':';
				    cout << setw(2) << sec << '\r';
					unsigned int startTime = time(0)+1;
					while(time(0)<startTime);
				}
				sec = 0;
			}
			min = 0;
		}
		hrs = 0;
	}
	system("PAUSE");
	return 0;
}
