#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 200005
struct Point
{
    double x,y;
    char flag;
} p[MAXN],p1[MAXN];
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
    if(a.flag!=b.flag)			//不同组的点之间求距离 
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return INF;					//同组中点之间距离为INF 
}
double mindistance(int l,int r)	//求p[l..r]中不同组点之间的最小距离 
{
    if(l>=r)					//区间中只有一个点 
		return INF;
    if(l+1==r)					//区间中只有两个点
        return dis(p[l],p[r]);
    int mid=(l+r)/2;			//求中点位置
	double d1=mindistance(l,mid);
	double d2=mindistance(mid+1,r);
    double d=min(d1,d2);
    int cnt=0;
    for(int i=l;i<=r;i++)		//与中点x方向距离<d的点存放在p1中 
        if(fabs(p[i].x-p[mid].x)<d)
            p1[cnt++]=p[i];
    sort(p1,p1+cnt,cmpy);		//p1中所有点按y递增排序 
    for(int i=0;i<cnt;i++)
        for(int j=i+1,k=0;k<7 && j<cnt && p1[j].y-p1[i].y<d;j++,k++)
            d=min(d,dis(p1[i],p1[j]));
    return d;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)			//输入A集合的点 
            scanf("%lf%lf",&p[i].x,&p[i].y),p[i].flag='A';
        for(int i=n;i<2*n;i++)			//输入B集合的点
            scanf("%lf%lf",&p[i].x,&p[i].y),p[i].flag='B';
        sort(p,p+2*n,cmpx);				//全部点按x递增排序 
        printf("%.3f\n",mindistance(0,2*n-1));
    }
    return 0;
}

