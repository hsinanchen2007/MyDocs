//檔案名稱：d:\VC++09\VC0920\VC0920.cpp
#include <iostream>
#include <string>	//C++型態string標題檔
using namespace std;

int main(int argc, char** argv)
{
	string s1, s2, s3;	//宣告字串s1, s2, s3

	cout << "請輸入一字串：";
	getline(cin, s1);	//取得整列字串

	int len1 = s1.length();	//取得s1字串長度
	int count = 0;

	for (int i = 0; i < len1; i++) {
		// 取得單字
		if (isalnum(s1.at(i))) {	//若是英文或數字
			s2 += s1.at(i);	//將字元連接到s2
			if (i != (len1 - 1))	//若不等於最後字元
				continue;	//回到迴圈第一個敘述
		}

		// 檢查對稱字
		bool flag = true;
		int len2 = s2.length();	//取得s2字串長度
		for (int j = 0; j <= (len2 / 2 - 1); j++) {
			if (s2.at(j) != s2.at(len2 - j - 1))
			{		//檢查是否為對稱字
				flag = false;
				break;
			}
		}

		// 顯示對稱字
		if (flag == true) {
			cout << '\"' << s2 << "\" 是對稱字" << endl;
			count++;
		}
		s2 = s3;
	}
	cout << "\n對稱字的總數為 " << count << "\n";
	return 0;
}
