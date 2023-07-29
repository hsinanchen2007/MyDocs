#include<iostream>
#include<vector>
using namespace std;
vector<int> x;
int n=5;
int main()
{
	x.resize(n);
	for(int i=0;i<n;i++)
		printf("a[%d]=%d\n",i,x[i]);
	return 0;
	
}
