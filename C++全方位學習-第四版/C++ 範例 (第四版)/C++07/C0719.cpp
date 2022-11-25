//檔案名稱：d:\C++07\C0719.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
	int ini, max;	//宣告整數變數
	char days[7][7] = { "星期日", 
			    "星期一",
			    "星期二",
			    "星期三",
			    "星期四",
			    "星期五",
			    "星期六", };	//宣告並起始二維字串陣列

	cout << "輸入本月的總天數："; cin >> max;	//輸入總天數
	cout << "本月第一天星期幾："; cin >> ini;	//輸入起始日
	cout << endl;
	for(int i=0; i<=6; i++)
		cout << days[i] << '\t';	//輸出星期表頭
	cout << endl;
	for(int j=1; j<=ini; j++)	//輸出空格迴圈
		cout << setw(4) << '\t';
	for(int k=1; k<=max; k++)	//輸出月曆迴圈
	{
		cout << setw(4) << k;	//設定輸出格式
		if((k+ini) % 7 != 0)	//若不是7的倍數
			cout << '\t';	//跳下一定位點
		else
			cout << '\n';	//跳下一新行
	}
	cout << endl;   //跳行 
	return 0;
}
