// StringVector.cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string A[] =
	{"John","Memi","Brigitte","Daiana","Lulu","Lisa"};
	vector<string>  S(A, A + 6);
	int i, Length=S.size();
	cout << "\nvector S ��Ӭ�: "  << endl;
	for (i = 0; i < Length; i++)
		cout << S[i] << "  ";
	cout << endl;
	// ���J
	S.insert(find(S.begin(), S.end(), "Daiana"), "Joanne");
	cout << "\n�b Daiana �e���J Joanne" 
			<< " ����, vector S ��: "  << endl;
	Length = S.size();
	for (i = 0; i < Length; i++)
		cout << S[i] << "  ";
	cout << endl;
	// ����
	remove( S.begin(), S.end(), "Brigitte");
	S.resize(S.size()-1);
	cout << "\n�b���� Brigitte" 
			<< " ����, vector S ��: "  << endl;
	Length = S.size();
	for (i = 0; i < Length; i++)
		cout << S[i] << "  ";
	cout << endl;

	// ���N
	*find(S.begin(), S.end(), "Daiana")= "William";
	cout << "\n�N Daiana ���N�� William" 
			<< " ����, vector S ��: "  << endl;
	Length = S.size();
	for (i = 0; i < Length; i++)
		cout << S[i] << "  ";
	cout << endl;
	// �]�w�S�w��������
	S.at(2) = "Peter";
	cout << "\n�b����uS.at(2) = Peter�v����, S �ܦ���:"
			<< endl;
	Length = S.size();
	for (i = 0; i < Length; i++)
		cout << S[i] << "  ";
	cout << endl;
	// ���J�B�~������
	S.insert(S.begin() + 3, "Albert");
	cout << "\n�b����uS.insert(S.begin() + 3, Albert)�v"
			<<  "\n����, S �ܦ���:"<< endl;
	Length = S.size();
	for (i = 0; i < Length; i++)
		cout << S[i] << "  ";
	cout << endl;
	// �N vector ����U�������Ȩ̤j�p�Ƨ�
	//cout << endl;//**std::
	sort(S.begin(), S.end());
	cout << "\n�ƧǤ���, S �ܦ���:"
			<< endl;
	Length = S.size();
	for (i = 0; i < Length; i++)   // Length
		cout << S[i] << "  ";
	cout << endl;

	// �N vector ����U�������s���� std::
	random_shuffle(S.begin(), S.end());
	cout << "\n���s���Ƥ���, S �ܦ���:"
			<< endl;
	Length = S.size();
	for (i = 0; i < Length; i++)
		cout << S[i] << "  ";
	cout << endl;

	system("pause");
	return 0;
}
