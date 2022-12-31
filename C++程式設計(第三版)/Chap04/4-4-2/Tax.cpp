// Tax.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ 主程式 --------------------
int main()
{
	float GIncome, Tax;
	cout << "\n"
		<< "請輸入綜合所得淨額  :  " << endl;
	cin  >> GIncome;
	if (GIncome < 0.0)
		cout << "您輸入的綜合所得淨額沒有意義!\n";    
	else if (GIncome <  330000.0)
		Tax = GIncome * 0.06;
	else if (GIncome <  890000.0)
		Tax = GIncome * 0.13 - 23100;
	else if (GIncome < 1780000.0)
		Tax = GIncome * 0.21 - 94300;
	else if (GIncome < 3340000.0)
		Tax = GIncome * 0.3 - 254500;
	else 
		Tax = GIncome * 0.4 - 588500;
	cout << "您要繳的綜合所得稅是: " 
		<< Tax << " 元"<<endl;
	system("pause");
	return 0;
}
