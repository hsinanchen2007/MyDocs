// EncodeText.cpp
// --------------------------------------

#include <iostream>
#include <cstring> 
using namespace std;

// ---函數 Encode() 的宣告--------
void Encode(char *);

// ---主程式----------------------
int main()
{
	const int MaxLength=40;
	char InputString[MaxLength];
	cout << "Please input your original code:\n";
	cin.getline(InputString, MaxLength);
	Encode(InputString);
	cout << "The answer is:\n";
	cout << InputString<< endl;
	system("pause");
	return 0;
}

// ---函數 Encode() 的定義--------
void Encode(char *String)
{
	char Codes[28]="DOJKZCTMYPAWHUQNBVGSRFXLIE ";
	char ABC[28]  ="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	char abc[28]  ="abcdefghijklmnopqrstuvwxyz ";
	int  i, j, Size = strlen(String);

	for(i=0; i<Size;i++)
	{ 
		j=0;
		while(String[i]!=ABC[j] && String[i]!=abc[j] && j<26)
			j++;
		String[i]=Codes[j];
	}
	return;
}
