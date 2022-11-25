// Decode.cpp
// ½m²ß9
// --------------------------------------
#include <iostream>
#include <cstring> 
using namespace std;

void Encode(char *);
void Decode(char *);

int main()
{
	const int MaxLength=40;
	char InputString[MaxLength];
	cout << "Please input your original code:\n";
	cin.getline(InputString,MaxLength);
	Encode(InputString);
	cout << "The encoded string is:" << endl;
	cout << InputString; 
	Decode(InputString);
	cout << "\n"
		<< "The decoded string is:" << endl;
	cout << InputString<< endl; 
	system("pause");
	return 0;
}
void Encode(char *String)
{
	char Codes[28]="DOJKZCTMYPAWHUQNBVGSRFXLIE ";
	char ABC[28]  ="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	char abc[28]  ="abcdefghijklmnopqrstuvwxyz ";
	int  i, j, Size=strlen(String);
	//cout << "Size:" << Size << "\n" << endl;
	for(i=0; i<Size;i++)
	{ 
		j=0;
		while(String[i]!=ABC[j] && String[i]!=abc[j] && j<26) 
			j++;
		String[i]=Codes[j];
	}
	return;
}

void Decode(char *String)
{
	char Codes[28]="DOJKZCTMYPAWHUQNBVGSRFXLIE ";
	char ABC[28]  ="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	int  i, j, Size=strlen(String);

	for(i=0; i<Size;i++)
	{ 
		j=0;
		while(String[i]!=Codes[j] && j<26) 
			j++;
		String[i]=ABC[j];
	}
	return;
}
