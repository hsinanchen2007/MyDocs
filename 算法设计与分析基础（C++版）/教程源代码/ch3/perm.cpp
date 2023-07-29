#include<iostream>
#include<vector>
using namespace std;
vector<int> Insert(vector<int> s,int i,int j)  				//在s的位置j插入i
{	vector<int>::iterator it=s.begin()+j;       			//求出插入位置
 	s.insert(it,i);                            		//插入整数i
 	return s;
}
vector<vector<int>> CreatePi(vector<int> s,int i)  		//在s集合中i-1到0位置插入i
{	vector<vector<int>> tmp;
	for (int j=s.size();j>=0;j--)                      	//在s(含i-1个整数)的每个位置插入i
	{	vector<int> s1=Insert(s,i,j);
    	tmp.push_back(s1);                      	//添加到Pi中
	}
	return tmp;
}
/***迭代算法*********************************************/ 
vector<vector<int>> Perm1(int n)  							//迭代法求1-n的全排列
{	vector<vector<int>> Pi;										//存放1～i的全排列
  	Pi.push_back({1});
  	vector<vector<int>> Pi_1;                   	//存放1～i-1的全排列
  	for (int i=2;i<=n;i++)                       	//循环添加2～n
  	{	Pi_1=Pi;															//新值取代旧值
     	Pi.clear();
   		for (auto it=Pi_1.begin();it!=Pi_1.end();it++)
    	{	vector<vector<int>> tmp=CreatePi(*it,i);  	//在it集合中插入i得到tmp
      		for(int k=0;k<tmp.size();k++)
      		Pi.push_back(tmp[k]);								//将tmp的全部元素添加到Pi中
    	}
	}
 	return Pi;
}
/***递归算法*********************************************/ 
vector<vector<int>> perm(int n,int i)  	//递归算法
{
	if(i==1)
		return {{1}};
	else
	{
		vector<vector<int>> Pi;
		vector<vector<int>> Pi_1=perm(n,i-1);			//求出Pi_1 
   		for (auto it=Pi_1.begin();it!=Pi_1.end();it++)
    	{	vector<vector<int>> tmp=CreatePi(*it,i);  	//在it集合中插入i得到tmp
      		for(int k=0;k<tmp.size();k++)
       			Pi.push_back(tmp[k]);					//将tmp的全部元素添加到Pi中
    	}
	 	return Pi;
	}
}

vector<vector<int>> Perm2(int n)  						//递归法求1-n的全排列
{
	return perm(n,n);
}


void disp(vector<vector<int>>&ans)
{
	printf("    ");
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		for(int j=0;j<(*it).size();j++)
			printf("%d",(*it)[j]);
		printf("  ");
	}
	printf("\n");
}

int main()
{
	int n=3;
	vector<vector<int>> ans;
	printf("1-%d的全排列如下:\n  ",n); 
	printf("解法1\n"); 
	ans=Perm1(n); disp(ans);
	printf("解法2\n"); 
	ans=Perm2(n); disp(ans);

	return 0;
}
