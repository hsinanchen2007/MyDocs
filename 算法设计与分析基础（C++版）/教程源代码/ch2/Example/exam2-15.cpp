#include<iostream>
#include<vector>
#include<set>
using namespace std;
set<int> s;							//定义集合容器s 
void solve(vector<int>& v)
{
	int i=0,x;
	while(i<v.size())
	{
		if(v[i]==1)					//操作1
		{
			i++;
			x=v[i];
			s.insert(x);
			printf("    输入整数: %d\n",x); 
		}
		else if(v[i]==2)			//操作2
		{
			auto it=s.end();
			it--;
			printf("删除最大整数: %d\n",*it); 
			s.erase(it);
		}
		else if(v[i]==3)			//操作3
		{
			auto it=s.begin();
			printf("删除最小整数: %d\n",*it); 
			s.erase(it);
		}
		else						//操作4
		{
			printf("    整数序列: "); 
			for(auto it=s.begin();it!=s.end();it++)
				printf("%d ",*it);
			printf("\n");
		}
		i++;
	}
}
int main()
{
	vector<int> v={1,2,1,5,4,2,1,6,1,8,3,4};
	solve(v);
	return 0;
}
