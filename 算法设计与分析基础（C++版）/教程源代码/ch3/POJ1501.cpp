#include<iostream>
#include<cstring>
#define MAXN 105
using namespace std;
int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
char map[MAXN][MAXN];
char str[MAXN];
int main()
{	int n,i,j,x,y;
 	scanf("%d",&n);
 	for(i=0;i<n;i++)											//输入字母矩阵
		scanf("%s",map[i]);
 	while(scanf("%s",str))									//输入若干个单词
	{	if(str[0]=='0') break;								//输入"0"结束
    	int len=strlen(str);
    	bool flag=false;
    	for(i=0;i<n;i++)										//穷举每个行
		{	for(j=0;j<n;j++)									//穷举每个列
			{	for(int d=0;d<8;d++)						//穷举每个方位
				{	for(int k=0;k<len;k++)					//遍历str单词 
					{	x=i+dir[d][0]*k;						//求出str[k]字母的坐标(x,y)
             	y=j+dir[d][1]*k;
             	if(x<0 || x>=n || y<0 || y>=n || map[x][y]!=str[k])
              	break;								//坐标超界或者不相同退出k的循环
             	if(k==len-1) flag=true;				//查找成功，置flag为true
          	}
          	if(flag) break;
        	}
         	if(flag) break;
     	}
      	if(flag) break;
		}
   	if(flag)													//输出查找结果
			printf("%d,%d %d,%d\n",i+1,j+1,x+1,y+1);
    	else
			printf("Not found\n");
	}
 	return 0;
}

