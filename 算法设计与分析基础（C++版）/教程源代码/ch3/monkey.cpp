#include<iostream>
#include<vector>
using namespace std;
int peaches(int n)
{
	int ans=1;
	for(int i=n-1;i>=1;i--)
		ans=2*(ans+1);
	return ans; 
}
int main()
{
	for(int n=1;n<=10;n++)
		printf(" n=%dʱ: %d\n",n,peaches(n));
	return 0;
}
