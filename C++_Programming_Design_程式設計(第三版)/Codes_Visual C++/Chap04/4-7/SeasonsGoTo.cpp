// SeasonsGoTo.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ 主程式 --------------------
int main()
{
	int Month;
	cout << "\n"
		<< "請輸入一個月份  :  " << endl;
	cin  >> Month;
	if (Month < 1 || Month >12)
	{
		cout <<  "您輸入的月份沒有意義!" << endl;
		goto EndofProgram;
	}
	cout << "\n" << Month << "月是";
	switch ((Month%12)/3)
	{
	case 0:
		cout << "冬季"<< endl;
		break;
	case 1:
		cout << "春季"<< endl;
		break;
	case 2:
		cout << "夏季"<< endl;
		break;
	case 3:
		cout << "秋季"<< endl;
		break;
	default:
		cout << "程式有問題!" << endl;
	}
EndofProgram:
	system("pause");
	return 0;
}
