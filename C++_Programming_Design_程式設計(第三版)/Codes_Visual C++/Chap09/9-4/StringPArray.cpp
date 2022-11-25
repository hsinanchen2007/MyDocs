// StringPArray.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// ---函數FindSeason()的宣告--------
char* FindSeason(int);

// ---主程式------------------------
int main()
{
	int N;
	cout << "\n" 
		<< "請輸入一個月份  :  " << endl;
	cin  >> N;
	cout << "\n" 
		<< N << "月是" 
		<< FindSeason(N)<< endl;
	system ("pause");
	return 0;
}

// ---函數 FindSeason() 的定義-----
char* FindSeason(int Month)
{
	int N;
	char* Seasons[]={"冬季","春季","夏季","秋季"};
	if (Month < 1 || Month >12) 
		return "(您輸入的月份沒有意義)";
	N=(Month%12)/3;
	return Seasons[N];	
}
