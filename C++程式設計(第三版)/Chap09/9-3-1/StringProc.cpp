// StringProc.cpp
// --------------------------------------
#include <iostream>
#include <cstring> 
using namespace std;

// ---�D�{��------------------------
int main()
{
  const int SLength = 30;
  char S1[SLength] = "Hello, �z�n!";
  char S2[SLength] = "Good boy.";
  char *pS1, *pS2;
  pS1=S1;
  pS2=S2;

  cout << "\n"
       << "pS1 ���Ȭ�  :  " << pS1 << "\n"
       << "pS1 �����׬�:  "
       <<  strlen(pS1) << " �r��." << endl;
  cout << "\n"
       << "S1 ���Ȭ�  :  " << S1 << "\n"
       << "S1 �����׬�:  "
       <<  strlen(S1)  << " �r��." << endl;
  cout << "\n"
       << "pS2 ���Ȭ�  :  " << pS2 << "\n"
       << "pS2 �����׬�:  "
       << strlen(pS2) << " �r��." << endl;
  strcat(S1, S2);
  cout << "���� strcat(S1, S2); ��,"
       << "S1 ���Ȭ�:  \n" 
       << S1 <<  endl;
  cout << "���� strcmp(S1, S2); ���Ȭ�: "
       << strcmp(S1, S2) <<  endl;
  char *p= strchr(S1, 'l');
  cout << "��1�� 'l' ��� S1 ���� "
       << (p - pS1)+1 << " �Ӧr������m" << endl;
  cout << "���� strchr(S1, 'l'); ���Ȭ�: "
       << strchr(S1, 'l') <<  endl;
  strcpy(S1, S2);
  cout << "���� strcpy(S1, S2); ��,"
       << "S1 ���Ȭ�:  \n" 
       << S1 <<  endl;

  system ("pause");
  return 0;
}
