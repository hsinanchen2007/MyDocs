#include<iostream>
using namespace std;
void solve1(int a,int b)
{
	for(int x=0;x<=a;x++)
		for(int y=0;y<=a;y++)
		{
			if(x+y==a && 2*x+4*y==b)
				printf("x=%d,y=%d\n",x,y);
		}
}
void solve2(int a,int b)
{
	for(int x=0;x<=min(a,b/2);x++)
		for(int y=0;y<=min(a,b/4);y++)
		{
			if(x+y==a && 2*x+4*y==b)
				printf("x=%d,y=%d\n",x,y);
		}
}
int main()
{
	int a=3,b=8;
	solve2(a,b);
	return 0;
}
