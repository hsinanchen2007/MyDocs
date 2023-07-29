#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Stud						//学生元素类型 
{	int no;						//学号 
	string name;				//姓名 
	int score;					//分数
	int rank;					//名次 
	Stud(int no1,string name1,int score1)	//构造函数
	{	no=no1;
		name=name1;
		score=score1;
		rank=0; 
	}
	bool operator<(const Stud &s) const	//方式1：重载<运算符
	{
		return score>s.score;			//用于按score递减排序，将>改为<则按score递增排序
	}
};
struct Cmp
{
	bool operator()(Stud&s,Stud&t)	//方式2：重载()运算符
	{
		return s.score>t.score;			//用于按score递减排序，将>改为<则按score递增排序
	}
};
bool myfun(Stud&s,Stud&t)				//方式3：φ定义比较函数 
{
	return s.score>t.score;			//用于按score递减排序，将>改为<则按score递增排序
}
void getrank(vector<Stud> &v)		//求所有学生的名次 
{
	//sort(v.begin(),v.end());		//将v中所有元素按分数递减排序 
	//sort(v.begin(),v.end(),Cmp());	//将v中所有元素按分数递减排序 
	sort(v.begin(),v.end(),myfun);	//将v中所有元素按分数递减排序 
	v[0].rank=1;
	for(int i=1;i<v.size();i++)
	{
		if(v[i].score==v[i-1].score)
			v[i].rank=v[i-1].rank;
		else
			v[i].rank=i+1;			
	}
}

void disp(vector<Stud> &v)				//输出v的所有元素 
{
	for(auto e:v)
	{
		cout << "    [" << e.no << "," << e.name << "," << e.score << "]";
		if(e.rank!=0)
			cout << ": 第" << e.rank << "名" << endl;
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
	printf("求名次\n");
	printf("v:\n"); disp(v);
	return 0;
}
