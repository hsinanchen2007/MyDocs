//d:\Ex12\Ex1203.cpp
//¦r¦ê¹Bºâ
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
	cout << "½Ð¿é¤J¦r¦ê 1: ";
	cin >> S1;
	cout << "½Ð¿é¤J¦r¦ê 2: ";
	cin >> S2;
    cout << "¦r¦ê 1 += ¦r¦ê 2 => " << S1 << " += " << S2 << " = ";
	S3 = (S1 += S2);
	cout << S3 << endl;
	system("PAUSE");
	return 0;
}
