// FindSub.cpp --------------------------
#include <string>
#include <iostream>
using namespace std;

// ---�D�{��------------------------
int main()
{
	string S1="I do not know it at all.";
	string S2="���u���A�ڤ����D�o�O�_�R�ڡC";
	int Site, Length1, Length2, Count;
	string Sub1 = "no";
	string Sub2 = "��";

	Length1= Sub1.size();
	Count= 0;
	Site = 0;
	cout << "(1) �r�� \"" << Sub1 << "\" ���r�� \""
			<< S1 << "\" ����m�b:" << endl;
	while ((Site = S1.find(Sub1,Site)) !=-1)
	{
		cout << Site << " ";
		Site=Site+Length1;  Count++; 
	};
	cout << "\n �@�� " << Count 
			<< " �� \"" << Sub1 << "\" �b�䤤." << endl;

	Length2= Sub2.size();
	Count= 0;
	Site = 0;
	cout << "(2) ����r \"" << Sub2 << "\" ���r�� \""
			<< S2 << "\" ����m�b:" << endl;
	while ((Site = S2.find(Sub2,Site)) !=-1)
	{
		cout << Site << " ";
		Site=Site+Length2;  Count++; 
	};
	cout << "\n �@�� " << Count 
			<< " �� \"" << Sub2 << "\" �b�䤤." << endl;
	system("PAUSE");
	return 0;
}

