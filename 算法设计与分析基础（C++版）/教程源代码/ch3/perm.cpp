#include<iostream>
#include<vector>
using namespace std;
vector<int> Insert(vector<int> s,int i,int j)  				//��s��λ��j����i
{	vector<int>::iterator it=s.begin()+j;       			//�������λ��
 	s.insert(it,i);                            		//��������i
 	return s;
}
vector<vector<int>> CreatePi(vector<int> s,int i)  		//��s������i-1��0λ�ò���i
{	vector<vector<int>> tmp;
	for (int j=s.size();j>=0;j--)                      	//��s(��i-1������)��ÿ��λ�ò���i
	{	vector<int> s1=Insert(s,i,j);
    	tmp.push_back(s1);                      	//��ӵ�Pi��
	}
	return tmp;
}
/***�����㷨*********************************************/ 
vector<vector<int>> Perm1(int n)  							//��������1-n��ȫ����
{	vector<vector<int>> Pi;										//���1��i��ȫ����
  	Pi.push_back({1});
  	vector<vector<int>> Pi_1;                   	//���1��i-1��ȫ����
  	for (int i=2;i<=n;i++)                       	//ѭ�����2��n
  	{	Pi_1=Pi;															//��ֵȡ����ֵ
     	Pi.clear();
   		for (auto it=Pi_1.begin();it!=Pi_1.end();it++)
    	{	vector<vector<int>> tmp=CreatePi(*it,i);  	//��it�����в���i�õ�tmp
      		for(int k=0;k<tmp.size();k++)
      		Pi.push_back(tmp[k]);								//��tmp��ȫ��Ԫ����ӵ�Pi��
    	}
	}
 	return Pi;
}
/***�ݹ��㷨*********************************************/ 
vector<vector<int>> perm(int n,int i)  	//�ݹ��㷨
{
	if(i==1)
		return {{1}};
	else
	{
		vector<vector<int>> Pi;
		vector<vector<int>> Pi_1=perm(n,i-1);			//���Pi_1 
   		for (auto it=Pi_1.begin();it!=Pi_1.end();it++)
    	{	vector<vector<int>> tmp=CreatePi(*it,i);  	//��it�����в���i�õ�tmp
      		for(int k=0;k<tmp.size();k++)
       			Pi.push_back(tmp[k]);					//��tmp��ȫ��Ԫ����ӵ�Pi��
    	}
	 	return Pi;
	}
}

vector<vector<int>> Perm2(int n)  						//�ݹ鷨��1-n��ȫ����
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
	printf("1-%d��ȫ��������:\n  ",n); 
	printf("�ⷨ1\n"); 
	ans=Perm1(n); disp(ans);
	printf("�ⷨ2\n"); 
	ans=Perm2(n); disp(ans);

	return 0;
}
