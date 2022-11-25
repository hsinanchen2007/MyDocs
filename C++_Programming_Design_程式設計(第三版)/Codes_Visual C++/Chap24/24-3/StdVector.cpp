// StdVector.cpp
#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

// ------------- �D�{�� ----------------------
int main()
{
	const int Size = 5;
	int i, SizeF, SizeC;
	float A[Size] = {1.5, 2.9, 3.8, 4.2, 5.7};
	char  B[Size] = {'b', 'a', 'i', 'r', 'w'};

	// �w�q vector ����
	vector<float> Vf(A, A + Size);
	vector<char>  Vc(B, B + Size);
	SizeF=Vf.size();
	SizeC=Vc.size();
	// �w�q ostream ����
	ostream_iterator<float> IntOut(cout, "  ");
	ostream_iterator<char>  CharOut(cout, "  ");
	cout << std::showpoint
		<< std::setprecision(4);
	cout << "\n-------���� vector<float>-------------"
		<< endl;
	cout << "\nVf ��: "  << endl;
	// vector ���󪺿�X
	for (i = 0; i < SizeF; i++)
		cout  << Vf[i] << "  ";
	// �]�w�S�w��������
	Vf.at(2) = 9.9;
	cout << endl;
	cout << "�b����uVf.at(2) = 9.9�v����, Vf �ܦ���:"
		<< endl;
	// vector ���󪺿�X
	copy(Vf.begin(), Vf.end(), IntOut);
	cout << endl;
	Vf[3] = 2.8;
	cout << "�b����uVf[3] = 2.8;�v����, Vf �ܦ���:"
		<< endl;
	copy(Vf.begin(), Vf.end(), IntOut);
	// ���J�B�~������
	Vf.insert(Vf.begin() + 3, 1.2);
	cout << "\n�b����uVf.insert(Vf.begin() + 3, 1.2)�v"
		<<  "\n����, Vf �ܦ���:"<< endl;
	copy(Vf.begin(), Vf.end(), IntOut);
	// �N vector ����U�������Ȩ̤j�p�Ƨ�
	sort(Vf.begin(), Vf.end());
	cout << "\n�ƧǤ���, Vf �ܦ���:"     << endl;
	copy(Vf.begin(), Vf.end(), IntOut);
	// �Nvector����U�������s����
	random_shuffle(Vf.begin(), Vf.end());
	cout << "\n���s���Ƥ���, Vf �ܦ���:(�|�P�ҥ���ܤ��P)" << endl;
	// vector ���󪺿�X
	copy(Vf.begin(), Vf.end(), IntOut);
	cout << endl;
	cout << "\n--------���� vector<char>-----------------"
		<< endl;
	cout << "\nVc ��: "  << endl;
	// vector ���󪺿�X
	for (i = 0; i < SizeC; i++)
		cout << Vc[i] << "  ";
	cout << endl;
	// �]�w�S�w��������
	Vc.at(2) = 'h';
	cout << "�b����uVc.at(2) = 'h'�v����, Vc �ܦ���:"
		<< endl;
	copy(Vc.begin(), Vc.end(), CharOut);
	cout << endl;
	Vc[3] = 'G';
	cout << "�b����uVc[3] = 'G';�v����, Vf �ܦ���:"
		<< endl;
	copy(Vc.begin(), Vc.end(), CharOut);
	// ���J�B�~������
	Vc.insert(Vc.begin() + 3, 'p');
	cout << "�b����uVc.insert(Vc.begin() + 3, 'p')�v"
		<<  "\n����, Vc �ܦ���:"<< endl;
	copy(Vc.begin(), Vc.end(), CharOut);
	// �N vector ����U�������Ȩ̤j�p�Ƨ�
	sort(Vc.begin(), Vc.end());
	cout << "\n�ƧǤ���, Vc �ܦ���:"
		<< endl;
	copy(Vc.begin(), Vc.end(), CharOut);
	// �Nvector����U�������s����
	random_shuffle(Vc.begin(), Vc.end());
	cout << "\n���s���Ƥ���, Vc �ܦ���:(�|�P�ҥ���ܤ��P)"
		<< endl;
	copy(Vc.begin(), Vc.end(), CharOut);
	system("pause");
	return 0;
}

