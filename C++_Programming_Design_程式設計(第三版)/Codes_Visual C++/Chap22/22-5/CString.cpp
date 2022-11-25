// CString.cpp
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

// ---主程式------------------------
int main()
{
	string S1("012345678");
	string S2("abcdefghi");
	string  S3, S4;
	cout << " (1) S1 原來的內容是:" << endl;
	cout << "     " << S1 << endl;
	cout << "     S1.c_str() 可以直接以 cout 輸出:" << endl;
	cout << "     " << S1.c_str() << endl;
	char CS[10];
	char* pS = new char[S1.length()+1];
	cout << " (2) pS 是一個由 strcpy(pS, S1.c_str()) 產生的";
	cout << "  C-style string:" << endl;
	strcpy(pS, S1.c_str());
	cout << "     " << pS << endl;
	cout << " (3) CS 是一個由 strcpy() 複製而來的字串陣列:" << endl;
	strcpy(CS, S1.c_str());
	cout << "     " << CS << endl;
	S1.resize(4);
	cout << " (4) S1 在此以 S1.resize(4) 更動." << endl;
	cout << "     pS 是 (沒有改變):" << endl;
	cout << "     " << pS << endl;
	const char* pSc;
	cout << " (5) pSc = S1.c_str():" << endl;
	pSc = S1.c_str();
	cout << "     pSc 是:" << endl;
	cout << "     " << pSc << endl;
	S1[2]='A';
	cout << " (6) S1[2] 在此以 S1[2]='A' 更動." << endl;
	cout << "     pSc 是:" << endl;
	cout << "     " << pSc << endl;
	cout << " (7) S2 原來的內容是:" << endl;
	cout << "     " << S2 << endl;
	cout << "     pSc = S2.data():" << endl;
	pSc=S2.data();
	cout << "     pSc 是:" << endl;
	cout << "     " << pSc << endl;
	S2.resize(4);
	cout << " (8) S2 在此以 S2.resize(4) 更動." << endl;
	cout << "     pSc 是:" << endl;
	cout << "     " << pSc << endl;

	system("PAUSE");
	return 0;
}

