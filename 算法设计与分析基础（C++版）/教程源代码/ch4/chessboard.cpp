#include<iostream>
using namespace std;
#define MAX 1025
//问题表示
int board[MAX][MAX];										//表示棋盘，MAX为常量 
int tile=1;													//L型骨牌的编号,从1开始
void ChessBoard1(int tr,int tc,int dr,int dc,int k)			//被ChessBoard调用 
{
	if(k==0) return;										//递归出口
	int t=tile++;											//取一个L型骨，其牌号为tile
	int size=1<<(k-1);										//分割的子棋盘大小 

	if(dr<tr+size && dc<tc+size)							//特殊方格在左上角象限中
		ChessBoard1(tr,tc,dr,dc,k-1);						//继续分割左上角象限
	else													//特殊方格不在左上角象限中
	{
		board[tr+size-1][tc+size-1]=t;						//用t号L型骨牌覆盖左上角象限的右下角
		ChessBoard1(tr,tc,tr+size-1,tc+size-1,k-1);			//继续分割左上角象限
	}
	if(dr<tr+size && dc>=tc+size)  
		ChessBoard1(tr,tc+size,dr,dc,size);					//特殊方格在右上角象限中 
	else													//特殊方格不在右上角象限中
	{
		board[tr+size-1][tc+size]=t;						//用t号L型骨牌覆盖右上角象限的左下角
		ChessBoard1(tr,tc+size,tr+size-1,tc+size,k-1);  		//继续分割右上角象限
	}
	//处理左下角象限
	if(dr>=tr+size && dc<tc+size)							//特殊方格在左下角象限中
		ChessBoard1(tr+size,tc,dr,dc,k-1);  					//继续分割左下角象限
	else 													//特殊方格不在左下角象限中
	{
		board[tr+size][tc+size-1]=t;  						//用t号L型骨牌覆盖左下角象限的右上角
       	ChessBoard1(tr+size,tc,tr+size,tc+size-1,k-1);		//继续分割左下角象限
   	}
	//处理右下角象限
	if(dr>=tr+size && dc>=tc+size)							//特殊方格在右下角象限中
		ChessBoard1(tr+size,tc+size,dr,dc,k-1); 				//继续分割右下角象限
	else													//特殊方格在右下角象限中
	{	
		board[tr+size][tc+size]=t;  						//用t号L型骨牌覆盖右下角象限的左上角
		ChessBoard1(tr+size,tc+size,tr+size,tc+size,k-1);  	//继续分割右下角象限
	}
}
void ChessBoard(int dr,int dc,int k)		//递归算法，求2^k*2^k棋盘的覆盖问题 
{ 
	ChessBoard1(0,0,dr,dc,k);
} 

int main()  
{
	int k=3;							//表示棋盘大小为2^k*2^k 
	int dr=1,dc=2;						//特殊方格的位置
	int size=1<<k;
	ChessBoard(dr,dc,k);
	for(int i=0;i<size;i++)					//输出方案
	{
		for(int j=0; j<size;j++)
			printf("%4d",board[i][j]);
		printf("\n");
	}
	return 0;
}
