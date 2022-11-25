//d:\Ex17\Ex1701.cpp
// 函數範本練習 (二分搜尋)
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
		cout << "\n找不到數值：" << search << endl;
	else
		cout << "\n找到數值：" << search << endl;
}

int main(int argc, char** argv) {
	int iArray[7] = {57, 19, 33, 92, 6, 48, 65};
	float fArray[5] = {(float)3.5, (float)11.2, (float)100.7, (float)58.3, (float)66.7};
	int iSearch;
	float fSearch;
	int i;

	cout << "排序前：";
	for(i=0; i<7; i++)
		cout << iArray[i] << ' ';
	cout << endl;

	sort(iArray, 7);
	
	cout << "排序後：";
	for(i=0; i<7; i++)
		cout << iArray[i] << ' ';
	cout << endl;

	cout << "請輸入要搜尋的數值：";
	cin >> iSearch;
	find(iArray, 5, iSearch);
	cout << endl << endl;

	cout << "排序前：";
	for(i=0; i<5; i++)
		cout << fArray[i] << ' ';
	cout << endl;

	sort(fArray, 5);

	cout << "排序後：";
	for(i=0; i<5; i++)
		cout << fArray[i] << ' ';
	cout << endl;

	cout << "請輸入要搜尋的數值：";
	cin >> fSearch;
	find(fArray, 5, fSearch);
	cout << endl;
	system("PAUSE");
	return 0;
}
