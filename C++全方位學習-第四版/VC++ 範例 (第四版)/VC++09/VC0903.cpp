//檔案名稱：d:\VC++09\VC0903\VC0903.cpp
#include <iostream>
#include <cstring>	//插入字串標題檔
using namespace std;

int main(int argc, char** argv)
{
	char password[80] = "2020";	//定義並啟始密碼
	char instring[80];
	cout << "您有 3 次機會，";
	for (int i = 1; i <= 3; i++)	//輸入密碼迴圈
	{
		cout << "請輸入密碼：";
		cin.getline(instring, 80, '\n');	//取得來源字串
		int flag = strcmp(password, instring);	//比較字串
		if (flag == 0)
		{
			cout << "恭喜您！密碼正確。";	//顯示目的字串
			break;	//中斷迴圈
		}
		else
		{
			if (i != 3)	//以計數值決定，
				cout << "還有 " << 3 - i << " 次機會，";	//顯示的字串
			else
				cout << "對不起！沒機會了。";
		}
	}
	cout << endl;
	return 0;
}
