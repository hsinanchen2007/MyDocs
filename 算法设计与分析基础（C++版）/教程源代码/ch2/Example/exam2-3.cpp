#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Stud						//ѧ��Ԫ������ 
{	int no;						//ѧ�� 
	string name;				//���� 
	int score;					//����
	int rank;					//���� 
	Stud(int no1,string name1,int score1)	//���캯��
	{	no=no1;
		name=name1;
		score=score1;
		rank=0; 
	}
	bool operator<(const Stud &s) const	//��ʽ1������<�����
	{
		return score>s.score;			//���ڰ�score�ݼ����򣬽�>��Ϊ<��score��������
	}
};
struct Cmp
{
	bool operator()(Stud&s,Stud&t)	//��ʽ2������()�����
	{
		return s.score>t.score;			//���ڰ�score�ݼ����򣬽�>��Ϊ<��score��������
	}
};
bool myfun(Stud&s,Stud&t)				//��ʽ3���ն���ȽϺ��� 
{
	return s.score>t.score;			//���ڰ�score�ݼ����򣬽�>��Ϊ<��score��������
}
void getrank(vector<Stud> &v)		//������ѧ�������� 
{
	//sort(v.begin(),v.end());		//��v������Ԫ�ذ������ݼ����� 
	//sort(v.begin(),v.end(),Cmp());	//��v������Ԫ�ذ������ݼ����� 
	sort(v.begin(),v.end(),myfun);	//��v������Ԫ�ذ������ݼ����� 
	v[0].rank=1;
	for(int i=1;i<v.size();i++)
	{
		if(v[i].score==v[i-1].score)
			v[i].rank=v[i-1].rank;
		else
			v[i].rank=i+1;			
	}
}

void disp(vector<Stud> &v)				//���v������Ԫ�� 
{
	for(auto e:v)
	{
		cout << "    [" << e.no << "," << e.name << "," << e.score << "]";
		if(e.rank!=0)
			cout << ": ��" << e.rank << "��" << endl;
		else
			cout << endl;
	}
}

int main()
{
	Stud a[]={Stud(1,"Stud1",88),Stud(3,"Stud3",72),Stud(5,"Stud5",88),Stud(3,"Stud3",72),Stud(2,"Stud2",80)};
	int n=sizeof(a)/sizeof(a[0]);
	vector<Stud> v(a,a+n);
	printf("v:\n"); disp(v);
	getrank(v);
	printf("������\n");
	printf("v:\n"); disp(v);
	return 0;
}
