/*    �ɦW:ch14_04.cpp    �\��:�}�ɻP����   */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
 ifstream readfile;
 string filename;
 
 cout << "�п�J�ɦW(�i�t���|):";
 cin >> filename;
 
 readfile.open(filename.c_str(),ios::in);
 
 if(readfile.fail())   //�}�ɥ���
 {
  cout << "�ɮ�" << filename << "�}�ҥ���" << endl;
  exit(1); //�j�������{��
 }
 
 cout << "�ɮ�" << filename << "�}�Ҥ�..." << endl;
 readfile.close();
 cout << "�ɮ�" << filename << "����" << endl;
 return 0;
}
