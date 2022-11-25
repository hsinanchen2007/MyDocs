//  Encoding.cpp
// --------------------------------------
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// ---函數 GetString () 的宣告--------
void  GetString (char *FileNameIn, char *String);
// ---函數 Encode() 的宣告------------
void  Encode(char *String);
// ---函數 WriteString () 的宣告------
void  WriteString (char *, char *, int Mode);

const int MaxLength = 40;

// ---主程式--------------------------
int main ()
{
	char FileNameIn[20]  = "OriginalText.txt";
	char FileNameOut[20]  = "EncodedText.txt";
	char String[MaxLength];
	GetString(FileNameIn, String);
	Encode(String);
	cout << "編碼後的內容是:\n" << String << endl;
	WriteString (FileNameOut, String, 0);
	system("PAUSE");
	return 0;
}

// ---函數 GetString () 的定義--------
void  GetString (char *FileNameIn, char *String)
{
	ifstream FileInput;
	FileInput.open( FileNameIn );

	if (!FileInput)
	{
		cout << "檔案: " << FileNameIn << " 開啟失敗!"  << endl; 
		exit(1);
	}
	FileInput.getline(String,MaxLength);

	FileInput.close();
	cout << "檔案: " << FileNameIn
		    << " 開啟完成,\n下列是原有檔案內容:\n"
		    << String << endl;
}

// ---函數 Encode() 的定義-----------
void Encode(char *String)
{
	char Codes[28]="DOJKZCTMYPAWHUQNBVGSRFXLIE ";
	char ABC[28]  ="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	char abc[28]  ="abcdefghijklmnopqrstuvwxyz ";
	int  i, j, Size=strlen(String);

	for(i=0; i<Size;i++)
	{ 
		j=0;
		while(String[i]!=ABC[j] && String[i]!=abc[j] && j<26)
			j++;
		String[i]=Codes[j];
	}
	return;
}

// ---函數 WriteString () 的定義--------
void  WriteString (char *FileNameOut,
				   char *String, int Mode)
{
	ofstream FileOutput;
	if (Mode)
		FileOutput.open( FileNameOut, ios::app);
	else
		FileOutput.open( FileNameOut, ios::out);

	if (!FileOutput)
	{
		cout<< "檔案: " << FileNameOut << " 存檔失敗!" << endl; 
		exit(1);
	}
	FileOutput << String;
	FileOutput.close();
	cout << "已經存於檔案 "	<< FileNameOut << " 內." << endl;
}
