//�ɮצW�١Gd:\C++07\C0705.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int eq[2][2] = { {3, 8}, 
			 {4, 9} };	//�ŧi�ð_�l�G���}�C
	cout << "�D��C��x����\n";
	//�p���C����
	int d = eq[0][0] * eq[1][1] - eq[1][0] * eq[0][1];
	//��X�}�C����
	cout << "x = |" << eq[0][0] << " " << eq[0][1] << "| = ";
	cout << d << endl;	//��X��C����
	cout << "    |" << eq[1][0] << " " << eq[1][1] << "|\n";
	return 0;
}
