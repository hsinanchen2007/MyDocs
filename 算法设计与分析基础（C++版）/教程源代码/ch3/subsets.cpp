#include<iostream>
#include<vector>
using namespace std;

void disp(vector<vector<int>> ans)			//输出幂集 
{
	printf("    ");
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		if((*it).size()==0)
			printf("[]  ");
		else
		{
			printf("[");
		   	for(int j=0;j<(*it).size();j++)
		   		if(j==0)
				printf("%d",(*it)[j]);
			else
				printf(" %d",(*it)[j]);
			printf("]  ");
		}
	}
	printf("\n");
}
vector<vector<int>> appendi(vector<vector<int>> Mi_1,int i)	//向Mi_1中每个集合元素末尾添加i
{
	vector<vector<int>> Ai=Mi_1;
	for(int j=0;j<Ai.size();j++)
		Ai[j].push_back(i);
	return Ai;	
}
vector<vector<int>> subsets1(int n)			//迭代算法 
{
	vector<vector<int>> Mi;					//存放{1-n}的幂集
	vector<vector<int>> Mi_1={{},{1}};		//存放M1
	for(int i=2;i<=n;i++)
    {
    	vector<vector<int>> Ai=appendi(Mi_1,i);
    	Mi=Mi_1;
        for(int j=0;j<Ai.size();j++)          //将Ai所有集合元素添加到Mi中
        	Mi.push_back(Ai[j]);
        Mi_1=Mi;
	}
	return Mi;
}
/* 
vector<vector<int>> pset(vector<vector<int>> M,int n,int i)		//递归算法 
{
	vector<vector<int>> A=appendi(M,i);			//求A 
   	for(int j=0;j<A.size();j++)          		//将A所有集合元素添加到M中
   		M.push_back(A[j]);
   	if(i==n)									//已经求出结果时返回M 
   		return M;
   	else										//否则递归调用 
		return pset(M,n,i+1);
}
vector<vector<int>> subsets2(int n)			//递归算法 
{
	vector<vector<int>> M={{},{1}};			//M存放{1-n}的幂集,初始时置为M1
	if(n==1)
		return M;
	else
		return pset(M,n,2);
}
*/

vector<vector<int>> pset(int n,int i)				//递归算法 
{
	if(i==1)
		return {{},{1}};
	else
	{	vector<vector<int>> Mi_1=pset(n,i-1);		//递归求出Mi_1 
		vector<vector<int>> Mi=Mi_1;				//Mi置为Mi_1 
		vector<vector<int>> Ai=appendi(Mi_1,i);		//求Ai,appendi算法参见3.3.3节
   		for(int j=0;j<Ai.size();j++)          		//将Ai所有集合元素添加到Mi中
   			Mi.push_back(Ai[j]);
   		return Mi;									//返回Mi 
   }
}

vector<vector<int>> subsets2(int n)				//递归算法 
{
	return pset(n,n);
}

int main()
{
	int n=3;
	vector<vector<int>> ans;
	printf("{1-%d}的幂集如下:\n",n); 
	printf("解法1\n"); 
	ans=subsets1(n);
	disp(ans);
	printf("解法2\n"); 
	ans=subsets2(n);
	disp(ans);
	return 0;
}
