//�x�s�ɦW�Gd:\C++05\C0521.cpp
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main(int argc, char** argv)
{
	cout.setf(ios::fixed | ios::right);	//�]�w��X�V�k���
	cout.fill('0');		//�Y����ťիh��0
	while (true)	//�L�a�j��
	{
		for (int hrs=0; hrs<24; hrs++)	//��: �q 0 �ƨ� 23
		{
			for (int min=0; min<60; min++)	//��: �q 0 �ƨ� 59
			{
				for (int sec=0; sec<60; sec++)	//��: �q 0 �ƨ� 59
				{
				    cout << setw(2) << hrs << ':';	//��X�ɼ�
				    cout << setw(2) << min << ':';	//��X������
				    cout << setw(2) << sec << ' ';	//��X���
					cout << '\r';					//��в��ܫe�� 
				    unsigned int startTime = time(0)+1;
				    while(time(0)<startTime);	//����1��j�� 
				}
			}
		}
	}
	return 0;
}
