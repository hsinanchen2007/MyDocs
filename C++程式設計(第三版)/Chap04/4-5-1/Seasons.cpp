// Seasons.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ �D�{�� --------------------
int main()
{
	int Month;
	cout << "\n"
		<< "�п�J�@�Ӥ��  :  " << endl;
	cin  >> Month;
	if (Month < 1 || Month >12)
		cout <<  "�z��J������S���N�q!";    
	else
	{
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
	}
	system("pause");
	return 0;
}

