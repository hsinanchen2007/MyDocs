//d:\Ex17\Ex1701.cpp
// ��ƽd���m�� (�G���j�M)
#include <iostream>

using namespace std;

template <class X>
void sort(X *items, int max)
{
	register int si, di;
	X temp;

	for(si=0; si<max-1; si++)
		for(di=si; di<max; di++)
			if(items[si] > items[di]) {
				temp = items[si];
				items[si] = items[di];
				items[di] = temp;
			}
}

template <class X>
void find(X *items, int max, X search)
{
	int low=0, high=max-1, middle;
	do
	{
		if((low+high)%2 > 0.5)
			middle = (low+high)/2+1;
		else
			middle = (low+high)/2;
		
		if(search < items[middle])
			high = middle-1;
		else if(search > items[middle])
			low = middle+1;
		else if(search == items[middle])
			break;
	} while(low <= high);
	if(low > high)
		cout << "\n�䤣��ƭȡG" << search << endl;
	else
		cout << "\n���ƭȡG" << search << endl;
}

int main(int argc, char** argv) {
	int iArray[7] = {57, 19, 33, 92, 6, 48, 65};
	float fArray[5] = {(float)3.5, (float)11.2, (float)100.7, (float)58.3, (float)66.7};
	int iSearch;
	float fSearch;
	int i;

	cout << "�Ƨǫe�G";
	for(i=0; i<7; i++)
		cout << iArray[i] << ' ';
	cout << endl;

	sort(iArray, 7);
	
	cout << "�Ƨǫ�G";
	for(i=0; i<7; i++)
		cout << iArray[i] << ' ';
	cout << endl;

	cout << "�п�J�n�j�M���ƭȡG";
	cin >> iSearch;
	find(iArray, 5, iSearch);
	cout << endl << endl;

	cout << "�Ƨǫe�G";
	for(i=0; i<5; i++)
		cout << fArray[i] << ' ';
	cout << endl;

	sort(fArray, 5);

	cout << "�Ƨǫ�G";
	for(i=0; i<5; i++)
		cout << fArray[i] << ' ';
	cout << endl;

	cout << "�п�J�n�j�M���ƭȡG";
	cin >> fSearch;
	find(fArray, 5, fSearch);
	cout << endl;
	system("PAUSE");
	return 0;
}
