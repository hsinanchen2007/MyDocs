#include<iostream>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int,vector<int>,greater<int>> minpq; 	//定义一个小根堆
priority_queue<int> maxpq;                            	//定义一个大根堆
void addx(int x)									//操作1:插入x
{	if(minpq.empty())                                  //若小根堆空
    {	minpq.push(x);
       	return;
    }
    if(x>minpq.top())                                 				//若x大于小根堆堆顶元素
       	minpq.push(x);                                				//将x插入到小根堆中
    else
       	maxpq.push(x);                                 				 //否则将x插入到大根堆中
    while(minpq.size()<maxpq.size())                      		//若小根堆元素个数较少
    {	minpq.push(maxpq.top());
       	maxpq.pop();                                  						//取出大根堆堆顶元素插入到小根堆中
    }
    while(minpq.size()>maxpq.size()+1)                    		//若小根堆比大根堆至少多2个元素
    {	maxpq.push(minpq.top());
       	minpq.pop();                            							//取出小根堆的堆顶元素插入到大根堆中
    }
}
double getmiddle()												//操作2:求中位数
{	if (minpq.size()!=maxpq.size())								//输入的总元素个数为奇数
       	return minpq.top();
   	else														//输入的总元素个数为偶数
       	return (minpq.top()+maxpq.top())/2.0;
}
void solve(vector<int>&v)					//求解算法 
{
	int i=0,x;
	while(i<v.size())
	{	if(v[i]==1)											//操作1
		{	i++;
			x=v[i];
			addx(x);
			printf("    输入整数: %d\n",x); 
		}
		else if(v[i]==2)
		{
			double mid=getmiddle();
			printf("中位数: %g\n",mid); 
		}
		i++;
	}
}
int main()
{
	vector<int> v={1,2,1,6,1,3,1,2,2,1,5,2};
	solve(v);
	return 0;
}
