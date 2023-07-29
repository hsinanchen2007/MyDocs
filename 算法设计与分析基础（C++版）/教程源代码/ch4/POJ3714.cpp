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
int cmpx(Point a,Point b)		//���ڰ�x�������� 
{
    return a.x<b.x;
}
int cmpy(Point a,Point b)		//���ڰ�y��������
{
    return a.y<b.y;
}
double dis(Point a,Point b)		//��������֮��ľ���
{
    if(a.flag!=b.flag)			//��ͬ��ĵ�֮������� 
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return INF;					//ͬ���е�֮�����ΪINF 
}
double mindistance(int l,int r)	//��p[l..r]�в�ͬ���֮�����С���� 
{
    if(l>=r)					//������ֻ��һ���� 
		return INF;
    if(l+1==r)					//������ֻ��������
        return dis(p[l],p[r]);
    int mid=(l+r)/2;			//���е�λ��
	double d1=mindistance(l,mid);
	double d2=mindistance(mid+1,r);
    double d=min(d1,d2);
    int cnt=0;
    for(int i=l;i<=r;i++)		//���е�x�������<d�ĵ�����p1�� 
        if(fabs(p[i].x-p[mid].x)<d)
            p1[cnt++]=p[i];
    sort(p1,p1+cnt,cmpy);		//p1�����е㰴y�������� 
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
        for(int i=0;i<n;i++)			//����A���ϵĵ� 
            scanf("%lf%lf",&p[i].x,&p[i].y),p[i].flag='A';
        for(int i=n;i<2*n;i++)			//����B���ϵĵ�
            scanf("%lf%lf",&p[i].x,&p[i].y),p[i].flag='B';
        sort(p,p+2*n,cmpx);				//ȫ���㰴x�������� 
        printf("%.3f\n",mindistance(0,2*n-1));
    }
    return 0;
}

