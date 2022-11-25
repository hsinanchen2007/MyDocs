// ModifyString.cpp
#include <string>
#include <iostream>
using namespace std;

// ---主程式------------------------
int main()
{
	string S1("0123456789");
	string S2("abcdefghi");
	string S3("必須 do it");
	string S4;
	string S5 ("長度是 123");
	string S6(1,'A');
	string S7(S3,1,3);
	string S8 (S3, 2, 5);
	cout << "(1)  S3 原來的內容是: " << endl;
	cout << "     " << S3 << endl;
	cout << "     執行 string S8 (S3, 2, 5); 後\n" 
		<< "     S8 = " << S8 << endl;
	cout << "(2)  S1 原來的內容是: " << endl;
	cout << "     " << S1 << endl;
	S1.resize(7);
	cout << "     執行 S1.resize(7); 後\n " 
		<< "    S1 = " << S1 << endl;
	cout << "(3)  S5 原來的內容是: " << endl;
	cout << "     " << S5 << endl;
	S5='A';
	cout << "     執行 S5 ='A'; 後\n " 
		<< "     S5 = " << S5 << endl;
	cout << "(4)  S1 原來的內容是:" << endl;
	cout << "     " << S1 << endl;
	cout << "     S3 原來的內容是:" << endl;
	cout << "     " << S3 << endl;
	S3=S1.substr(2,5);
	cout << "     執行 S3=S1.substr(2,5); 後." << endl;
	cout << "     S3 的內容是:" << endl;
	cout << "     " << S3 << endl;
	cout << "(5)  S1 原來的內容是:" << endl;
	cout << "     " << S1 << endl;
	S1.erase(1,3);
	cout << "     執行 S1.erase(1,3); 後." << endl;
	cout << "     S1 的內容是:" << endl;
	cout << "     " << S1 << endl;
	cout << "(6)  執行 S4=S1+S3; 後." << endl;
	S4=S1+S3;
	cout << "     S4 的內容是:" << endl;
	cout << "     " << S4 << endl;
	system("PAUSE");
	return 0;
}

