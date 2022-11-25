//儲存檔名：d:\VC++04\VC0408\VC0408.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	char letter;
	cout << "請按打字鍵，再按 Enter：";
	cin >> letter;	//輸入字元並存入letter
	if (letter >= 'A' && letter <= 'Z')	//若'A'<=letter<='Z'則
		cout << letter << " 為大寫鍵\n";	//   輸出字串並結束 if
	else if (letter >= 'a' && letter <= 'z')	//若'a'<=letter<='z'則
		cout << letter << " 為小寫鍵\n";	//  輸出字串並結束 if
	else if (letter >= '0' && letter <= '9')	//若'0'<=letter<='9'則
		cout << letter << " 為數字鍵\n";	//  輸出字串並結束 if
	else			//以上皆非則
		cout << letter << " 為符號鍵\n";	//  輸出字串並結束 if
	return 0;
}
