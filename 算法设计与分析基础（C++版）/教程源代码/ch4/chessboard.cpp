#include<iostream>
using namespace std;
#define MAX 1025
//�����ʾ
int board[MAX][MAX];										//��ʾ���̣�MAXΪ���� 
int tile=1;													//L�͹��Ƶı��,��1��ʼ
void ChessBoard1(int tr,int tc,int dr,int dc,int k)			//��ChessBoard���� 
{
	if(k==0) return;										//�ݹ����
	int t=tile++;											//ȡһ��L�͹ǣ����ƺ�Ϊtile
	int size=1<<(k-1);										//�ָ�������̴�С 

	if(dr<tr+size && dc<tc+size)							//���ⷽ�������Ͻ�������
		ChessBoard1(tr,tc,dr,dc,k-1);						//�����ָ����Ͻ�����
	else													//���ⷽ�������Ͻ�������
	{
		board[tr+size-1][tc+size-1]=t;						//��t��L�͹��Ƹ������Ͻ����޵����½�
		ChessBoard1(tr,tc,tr+size-1,tc+size-1,k-1);			//�����ָ����Ͻ�����
	}
	if(dr<tr+size && dc>=tc+size)  
		ChessBoard1(tr,tc+size,dr,dc,size);					//���ⷽ�������Ͻ������� 
	else													//���ⷽ�������Ͻ�������
	{
		board[tr+size-1][tc+size]=t;						//��t��L�͹��Ƹ������Ͻ����޵����½�
		ChessBoard1(tr,tc+size,tr+size-1,tc+size,k-1);  		//�����ָ����Ͻ�����
	}
	//�������½�����
	if(dr>=tr+size && dc<tc+size)							//���ⷽ�������½�������
		ChessBoard1(tr+size,tc,dr,dc,k-1);  					//�����ָ����½�����
	else 													//���ⷽ�������½�������
	{
		board[tr+size][tc+size-1]=t;  						//��t��L�͹��Ƹ������½����޵����Ͻ�
       	ChessBoard1(tr+size,tc,tr+size,tc+size-1,k-1);		//�����ָ����½�����
   	}
	//�������½�����
	if(dr>=tr+size && dc>=tc+size)							//���ⷽ�������½�������
		ChessBoard1(tr+size,tc+size,dr,dc,k-1); 				//�����ָ����½�����
	else													//���ⷽ�������½�������
	{	
		board[tr+size][tc+size]=t;  						//��t��L�͹��Ƹ������½����޵����Ͻ�
		ChessBoard1(tr+size,tc+size,tr+size,tc+size,k-1);  	//�����ָ����½�����
	}
}
void ChessBoard(int dr,int dc,int k)		//�ݹ��㷨����2^k*2^k���̵ĸ������� 
{ 
	ChessBoard1(0,0,dr,dc,k);
} 

int main()  
{
	int k=3;							//��ʾ���̴�СΪ2^k*2^k 
	int dr=1,dc=2;						//���ⷽ���λ��
	int size=1<<k;
	ChessBoard(dr,dc,k);
	for(int i=0;i<size;i++)					//�������
	{
		for(int j=0; j<size;j++)
			printf("%4d",board[i][j]);
		printf("\n");
	}
	return 0;
}
