//d:\Ex12\Ex1203.cpp
//�r��B��
#include <iostream>
#include <cstring> 
using namespace std;

class CString
{
	char str[80];
public:
	CString operator += (CString);
	friend istream &operator>> (istream &in, CString &obj);
	friend ostream &operator<< (ostream &out, CString &obj);
};

CString CString::operator += (CString obj)
{
	strcat(str, obj.str);
	return *this;
}

istream &operator>> (istream &in, CString &obj)
{
	in >> obj.str;
	return in;
}

ostream &operator<< (ostream &out, CString &obj)
{
	out << obj.str;
	return out;
}

int main(int argc, char** argv) {
	CString S1, S2, S3;
	cout << "�п�J�r�� 1: ";
	cin >> S1;
	cout << "�п�J�r�� 2: ";
	cin >> S2;
    cout << "�r�� 1 += �r�� 2 => " << S1 << " += " << S2 << " = ";
	S3 = (S1 += S2);
	cout << S3 << endl;
	system("PAUSE");
	return 0;
}
