// SeasonsFnc.cpp
// --------------------------------------
#include <iostream>
using namespace std;

void CheckSeason(int);
//------ �D�{�� -------------------------------
int main()
{
	int M;
	cout << "\n"
			<< "�п�J�@�Ӥ��  :  " << endl;
	cin  >> M;
	CheckSeason(M);
	system("PAUSE");
	return 0;
}

void CheckSeason(int Month)
{
	if (Month < 1 || Month >12)
    {
		cout <<  "�z��J������S���N�q!" << endl; 
		return;
    }   

	cout << "\n" << Month << "��O";
	switch ((Month%12)/3)
	{
	case 0:
		cout << "�V�u"<< endl;
		break;
	case 1:
		cout << "�K�u"<< endl;
		break;
	case 2:
		cout << "�L�u"<< endl;
		break;
	case 3:
		cout << "��u"<< endl;
		break;
    default:
		cout << "�{�������D!" << endl;
	}
	return;					// �����O�i�H�ٲ�
}

