#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//int realw;									//һ����ҵ�����
int no;										//�ҵ��ļٱұ�� 
int light;									//�ٱұ�����ᣨ1�������أ�-1��
int cnt;									//�����ܴ��� 
int Balance(vector<int>&c,int ia,int ib,int n)	//c[ia]��c[ib]��ʼ��n��Ӳ�ҳ���һ�� 
{
	cnt++; 									//����һ�� 
	int sa=0,sb=0;
	for(int i=ia,j=0;j<n;i++,j++)
		sa+=c[i];
	for(int i=ib,j=0;j<n;i++,j++)
		sb+=c[i];
	if(sa<sb)
		return 1;								//A�� 
	else if(sa==sb)
		return 0;								//A��B������ͬ 
	else
		return -1;								//B��
}
/* ���԰汾   
int Balance(vector<int>&c,int ia,int ib,int n)	//c[ia]��c[ib]��ʼ��n��Ӳ�ҳ���һ�� 
{
	int sa=0,sb=0;
	for(int i=ia,j=0;j<n;i++,j++)
		sa+=c[i];
	for(int i=ib,j=0;j<n;i++,j++)
		sb+=c[i];
	if(n==1)
		printf("    Ӳ��%d��%d����: ",ia,ib);
	else
		printf("    Ӳ��c[%d..%d]��c[%d..%d]��Ӳ�ҳ���: ",ia,ia+n-1,ib,ib+n-1);
	if(sa<sb)
	{	printf("ǰ����\n");
		return 1;								//A�� 
	}
	else if(sa==sb)
	{	printf("����������ͬ\n"); 
		return 0;								//A��B������ͬ 
	} 
	else
	{	printf("������\n"); 
		return -1;								//B��
	} 
}
*/
void spcoin(vector<int>&coins,int i,int n)		//��coins[i..i+n-1](��n��Ӳ��)�в��Ҽٱ� 
{	if(n==1)									//ʣ��1��Ӳ��coins[i] 
		no=i;
    else if(n==2)											//ʣ��2��Ӳ��coins[i]��coins[i+1]
    {  	int b=Balance(coins,i,i+1,1);						//2��Ӳ�ҳ���
      	if(b==light)											//coins[i]�Ǽٱ�
        	no=i;
      	else														//coins[i+1]�Ǽٱ�
        	no=i+1;
    }
    else															//ʣ��3����������Ӳ��coins[i..i+n-1]
 	{	int k;														//kΪA��B�е�Ӳ�Ҹ���
      	if(n%3==0 || n%3==1)
        	k=n/3;
      	else
       		k=n/3+1;
      	int ia=i,ib=i+k,ic=i+2*k;							//��ΪA,B,C,Ӳ�Ҹ����ֱ�Ϊ,k,n-2k
      	int b=Balance(coins,ia,ib,k);						//A,B����һ��
      	if(b==0)													//A,B��������ͬ���ٱ���C��
        	spcoin(coins,ic,n-2*k);						//��C�в��Ҽٱ�
      	else if(b==light)										//�ٱ�A��
        	spcoin(coins,ia,k);								//��A�в��Ҽٱ�
      	else spcoin(coins,ib,k);							//�ٱ���B�У���B�в��Ҽٱ�
    }
} 
int main() 
{
	int n=9;
	vector<int> c(n,2);					//������е�Ӳ��
	c[2]=1;								//ָ�����iΪ�ٱ�
	no=-1; light=1;
	printf("�����\n");
	spcoin(c,0,n);
	printf("    �ٱ�Ϊ%d, �ٱ�%s\n",no,(light==1?"��":"��"));
	return 0;
}
	

