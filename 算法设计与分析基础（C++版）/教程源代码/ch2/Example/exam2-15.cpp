#include<iostream>
#include<vector>
#include<set>
using namespace std;
set<int> s;							//���弯������s 
void solve(vector<int>& v)
{
	int i=0,x;
	while(i<v.size())
	{
		if(v[i]==1)					//����1
		{
			i++;
			x=v[i];
			s.insert(x);
			printf("    ��������: %d\n",x); 
		}
		else if(v[i]==2)			//����2
		{
			auto it=s.end();
			it--;
			printf("ɾ���������: %d\n",*it); 
			s.erase(it);
		}
		else if(v[i]==3)			//����3
		{
			auto it=s.begin();
			printf("ɾ����С����: %d\n",*it); 
			s.erase(it);
		}
		else						//����4
		{
			printf("    ��������: "); 
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
