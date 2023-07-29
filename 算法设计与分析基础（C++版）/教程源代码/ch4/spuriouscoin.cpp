#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//int realw;									//一个真币的重量
int no;										//找到的假币编号 
int light;									//假币比真币轻（1）或者重（-1）
int cnt;									//称重总次数 
int Balance(vector<int>&c,int ia,int ib,int n)	//c[ia]和c[ib]开始的n个硬币称重一次 
{
	cnt++; 									//称重一次 
	int sa=0,sb=0;
	for(int i=ia,j=0;j<n;i++,j++)
		sa+=c[i];
	for(int i=ib,j=0;j<n;i++,j++)
		sb+=c[i];
	if(sa<sb)
		return 1;								//A轻 
	else if(sa==sb)
		return 0;								//A，B重量相同 
	else
		return -1;								//B轻
}
/* 调试版本   
int Balance(vector<int>&c,int ia,int ib,int n)	//c[ia]和c[ib]开始的n个硬币称重一次 
{
	int sa=0,sb=0;
	for(int i=ia,j=0;j<n;i++,j++)
		sa+=c[i];
	for(int i=ib,j=0;j<n;i++,j++)
		sb+=c[i];
	if(n==1)
		printf("    硬币%d与%d称重: ",ia,ib);
	else
		printf("    硬币c[%d..%d]与c[%d..%d]的硬币称重: ",ia,ia+n-1,ib,ib+n-1);
	if(sa<sb)
	{	printf("前者轻\n");
		return 1;								//A轻 
	}
	else if(sa==sb)
	{	printf("两者重量相同\n"); 
		return 0;								//A，B重量相同 
	} 
	else
	{	printf("后者轻\n"); 
		return -1;								//B轻
	} 
}
*/
void spcoin(vector<int>&coins,int i,int n)		//在coins[i..i+n-1](共n个硬币)中查找假币 
{	if(n==1)									//剩余1个硬币coins[i] 
		no=i;
    else if(n==2)											//剩余2个硬币coins[i]和coins[i+1]
    {  	int b=Balance(coins,i,i+1,1);						//2个硬币称重
      	if(b==light)											//coins[i]是假币
        	no=i;
      	else														//coins[i+1]是假币
        	no=i+1;
    }
    else															//剩余3个或者以上硬币coins[i..i+n-1]
 	{	int k;														//k为A和B中的硬币个数
      	if(n%3==0 || n%3==1)
        	k=n/3;
      	else
       		k=n/3+1;
      	int ia=i,ib=i+k,ic=i+2*k;							//分为A,B,C,硬币个数分别为,k,n-2k
      	int b=Balance(coins,ia,ib,k);						//A,B称重一次
      	if(b==0)													//A,B的重量相同，假币在C中
        	spcoin(coins,ic,n-2*k);						//在C中查找假币
      	else if(b==light)										//假币A中
        	spcoin(coins,ia,k);								//在A中查找假币
      	else spcoin(coins,ib,k);							//假币在B中，在B中查找假币
    }
} 
int main() 
{
	int n=9;
	vector<int> c(n,2);					//存放所有的硬币
	c[2]=1;								//指定编号i为假币
	no=-1; light=1;
	printf("求解结果\n");
	spcoin(c,0,n);
	printf("    假币为%d, 假币%s\n",no,(light==1?"轻":"重"));
	return 0;
}
	

