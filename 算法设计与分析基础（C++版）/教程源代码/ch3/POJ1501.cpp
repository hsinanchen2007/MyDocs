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
 	for(i=0;i<n;i++)											//������ĸ����
		scanf("%s",map[i]);
 	while(scanf("%s",str))									//�������ɸ�����
	{	if(str[0]=='0') break;								//����"0"����
    	int len=strlen(str);
    	bool flag=false;
    	for(i=0;i<n;i++)										//���ÿ����
		{	for(j=0;j<n;j++)									//���ÿ����
			{	for(int d=0;d<8;d++)						//���ÿ����λ
				{	for(int k=0;k<len;k++)					//����str���� 
					{	x=i+dir[d][0]*k;						//���str[k]��ĸ������(x,y)
             	y=j+dir[d][1]*k;
             	if(x<0 || x>=n || y<0 || y>=n || map[x][y]!=str[k])
              	break;								//���곬����߲���ͬ�˳�k��ѭ��
             	if(k==len-1) flag=true;				//���ҳɹ�����flagΪtrue
          	}
          	if(flag) break;
        	}
         	if(flag) break;
     	}
      	if(flag) break;
		}
   	if(flag)													//������ҽ��
			printf("%d,%d %d,%d\n",i+1,j+1,x+1,y+1);
    	else
			printf("Not found\n");
	}
 	return 0;
}

