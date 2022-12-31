// StringList.cpp
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	list<string>  S;
	list<string>::iterator Index;
	// �[�J����
	S.push_front("John");
	S.push_front("Memi");
	S.push_front("Brigitte");
	S.push_back("Daiana");
	S.push_back("Lulu");
	S.push_back("Lisa");
  
	cout << "\nlist S ��Ӭ�: "  << endl;
	for (Index = S.begin(); Index != S.end(); Index++)
		cout << *Index << "  ";
	cout << endl;
	// ���J
	S.insert(find(S.begin(), S.end(), "Daiana"), "Joanne");
	cout << "\n�b Daiana �e���J Joanne" 
			<< " ����, list S ��: "  << endl;
	for (Index = S.begin(); Index != S.end(); Index++)
		cout << *Index << "  ";
	cout << endl;
	// ����
	S.remove( "Brigitte");
	cout << "\n�b���� Brigitte" 
			<< " ����, list S ��: "  << endl;
	for (Index = S.begin(); Index != S.end(); Index++)
		cout << *Index << "  ";
	cout << endl;
	// ���N
	*find(S.begin(), S.end(), "Daiana")= "William";
	cout << "\n�N Daiana ���N�� William" 
			<< " ����, list S ��: "  << endl;
	for (Index = S.begin(); Index != S.end(); Index++)
		cout << *Index << "  ";
	cout << endl;
	// �N list ����U�������Ȩ̤j�p�Ƨ�
	S.sort();
	cout << "\n�ƧǤ���, S �ܦ���:"
			<< endl;
	for (Index = S.begin(); Index != S.end(); Index++)
		cout << *Index << "  ";
	cout << endl;

	system("pause");
	return 0;
}
