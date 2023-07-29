#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define INF 0x3f3f3f3f
struct Point
{
    int x,y;
    Point(int x1,int y1):x(x1),y(y1) {}			//构造函数 
};
int cmpx(Point a,Point b)		//用于按x递增排序 
{
    return a.x<b.x;
}
int cmpy(Point a,Point b)		//用于按y递增排序
{
    return a.y<b.y;
}
double dis(Point a,Point b)		//求两个点之间的距离
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double mindistance1(vector<Point>&p,int l,int r)	//被mindistance调用 
{
    if(l>=r)					//区间中只有一个点 
		return INF;
    if(l+1==r)					//区间中只有两个点
        return dis(p[l],p[r]);
    int mid=(l+r)/2;			//求中点位置
	double d1=mindistance1(p,l,mid);
	double d2=mindistance1(p,mid+1,r);
    double d=min(d1,d2);
    vector<Point> p1;
    for(int i=l;i<=r;i++)				//与中点x方向距离<d的点存放在p1中 
        if(fabs(p[i].x-p[mid].x)<d)
            p1.push_back(p[i]);
    sort(p1.begin(),p1.end(),cmpy);		//p1中所有点按y递增排序 
    for(int i=0;i<p1.size();i++)
        for(int j=i+1,k=0;k<7 && j<p1.size() && p1[j].y-p1[i].y<d;j++,k++)
            d=min(d,dis(p1[i],p1[j]));
    return d;
}
double mindistance(vector<Point>&p)	//求p中最近点对距离 
{
	sort(p.begin(),p.end(),cmpx);				//全部点按x递增排序 
	int n=p.size();
	return mindistance1(p,0,n-1);
}
	
int main()
{
	vector<Point> p={Point(4,10),Point(3,7),Point(9,7),Point(3,4),Point(5,6),Point(5,4),Point(6,3),Point(8,1),Point(3,0),Point(1,6)};
	printf("最近点对距离=%g\n",mindistance(p));
    return 0;
}

