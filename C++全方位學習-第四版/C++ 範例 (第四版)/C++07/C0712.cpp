//�ɮצW�١Gd:\C++07\C0712.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
	int eq[3][4] = { {7, 1, 3, 6}, 
			 {4, -1, 1, 1},
			 {5, 3, -2, 8} };	//�ŧi�ð_�l�G���}�C
	int dd[3][3] = {0};	//�ŧi�ð_�l�G���}�C
	int i, x, y;	//�ŧi����ܼ�
	//��X��{��
	cout << "�T���@����{��\n";
	for(i=0; i<3; i++)
	{
		cout << eq[i][0] << (eq[i][1]>0 ? "x +" : "x ");	//��Xax
		cout << eq[i][1] << (eq[i][2]>0 ? "y +" : "y ");	//��Xby
		cout << eq[i][2] << "z= ";			//��Xcz
		cout << eq[i][3] << "\n";			//��Xd
	}
	//�ƻs�}�C����
	for(y=0; y<3; y++)	//�~�h�j��,���ܯ��ޭ�y
	{
		for(x=0; x<3; x++)	//���h�j��,���ܯ��ޭ�x
			dd[y][x] = eq[y][x];	//�ƻs�}�C����
	}
	//��X�}�C����
	cout << "\nd  = ";
	for(y=0; y<3; y++)	//�~�h�j��,���ܯ��ޭ�y
	{
		cout << ((y == 0) ? "| " : "     | ");
		for(x=0; x<3; x++)	//���h�j��,���ܯ��ޭ�x
			cout << setw(2) << dd[y][x] << ' ';	//��X�}�C����
		cout << "|\n";
	}
	//�M���}�C����
	for(y=0; y<3; y++)	//�~�h�j��,���ܯ��ޭ�y
	{
		for(x=0; x<3; x++)	//���h�j��,���ܯ��ޭ�x
			dd[y][x] = 0;	//�M���}�C����
	}
	//�ƻs�}�C����
	for(y=0; y<3; y++)	//�~�h�j��,���ܯ��ޭ�y
	{
		for(x=0; x<3; x++)	//���h�j��,���ܯ��ޭ�x
			dd[y][x] = eq[y][x];	//�ƻs�}�C����
	}
	for(y=0; y<3; y++)
		dd[y][0] = eq[y][3];	//�Hd���Na
	//��X�}�C����
	cout << "\ndx = ";
	for(y=0; y<3; y++)	//�~�h�j��,���ܯ��ޭ�y
	{
		cout << ((y == 0) ? "| " : "     | ");
		for(x=0; x<3; x++)	//���h�j��,���ܯ��ޭ�x
			cout << setw(2) << dd[y][x] << ' ';	//��X�}�C����
		cout << "|\n";
	}
	return 0;
}
