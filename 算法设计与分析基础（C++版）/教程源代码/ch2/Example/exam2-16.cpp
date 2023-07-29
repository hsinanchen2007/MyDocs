#include<iostream>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int,vector<int>,greater<int>> minpq; 	//����һ��С����
priority_queue<int> maxpq;                            	//����һ�������
void addx(int x)									//����1:����x
{	if(minpq.empty())                                  //��С���ѿ�
    {	minpq.push(x);
       	return;
    }
    if(x>minpq.top())                                 				//��x����С���ѶѶ�Ԫ��
       	minpq.push(x);                                				//��x���뵽С������
    else
       	maxpq.push(x);                                 				 //����x���뵽�������
    while(minpq.size()<maxpq.size())                      		//��С����Ԫ�ظ�������
    {	minpq.push(maxpq.top());
       	maxpq.pop();                                  						//ȡ������ѶѶ�Ԫ�ز��뵽С������
    }
    while(minpq.size()>maxpq.size()+1)                    		//��С���ѱȴ�������ٶ�2��Ԫ��
    {	maxpq.push(minpq.top());
       	minpq.pop();                            							//ȡ��С���ѵĶѶ�Ԫ�ز��뵽�������
    }
}
double getmiddle()												//����2:����λ��
{	if (minpq.size()!=maxpq.size())								//�������Ԫ�ظ���Ϊ����
       	return minpq.top();
   	else														//�������Ԫ�ظ���Ϊż��
       	return (minpq.top()+maxpq.top())/2.0;
}
void solve(vector<int>&v)					//����㷨 
{
	int i=0,x;
	while(i<v.size())
	{	if(v[i]==1)											//����1
		{	i++;
			x=v[i];
			addx(x);
			printf("    ��������: %d\n",x); 
		}
		else if(v[i]==2)
		{
			double mid=getmiddle();
			printf("��λ��: %g\n",mid); 
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
