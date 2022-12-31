// FindSub.cpp --------------------------
#include <string>
#include <iostream>
using namespace std;

// ---主程式------------------------
int main()
{
	string S1="I do not know it at all.";
	string S2="說真的，我不知道她是否愛我。";
	int Site, Length1, Length2, Count;
	string Sub1 = "no";
	string Sub2 = "我";

	Length1= Sub1.size();
	Count= 0;
	Site = 0;
	cout << "(1) 字串 \"" << Sub1 << "\" 位於字串 \""
			<< S1 << "\" 的位置在:" << endl;
	while ((Site = S1.find(Sub1,Site)) !=-1)
	{
		cout << Site << " ";
		Site=Site+Length1;  Count++; 
	};
	cout << "\n 共有 " << Count 
			<< " 個 \"" << Sub1 << "\" 在其中." << endl;

	Length2= Sub2.size();
	Count= 0;
	Site = 0;
	cout << "(2) 中文字 \"" << Sub2 << "\" 位於字串 \""
			<< S2 << "\" 的位置在:" << endl;
	while ((Site = S2.find(Sub2,Site)) !=-1)
	{
		cout << Site << " ";
		Site=Site+Length2;  Count++; 
	};
	cout << "\n 共有 " << Count 
			<< " 個 \"" << Sub2 << "\" 在其中." << endl;
	system("PAUSE");
	return 0;
}

