#include <stdio.h>
#include<vector> 
#include <string.h>
using namespace std;
vector<int> a;
int main()
{
	a.resize(5,2);
	for (int i=0;i<a.size();i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}



