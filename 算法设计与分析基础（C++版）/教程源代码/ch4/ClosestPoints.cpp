#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define INF 0x3f3f3f3f
struct Point
{
    int x,y;
    Point(int x1,int y1):x(x1),y(y1) {}			//���캯�� 
};
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
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double mindistance1(vector<Point>&p,int l,int r)	//��mindistance���� 
{
    if(l>=r)					//������ֻ��һ���� 
		return INF;
    if(l+1==r)					//������ֻ��������
        return dis(p[l],p[r]);
    int mid=(l+r)/2;			//���е�λ��
	double d1=mindistance1(p,l,mid);
	double d2=mindistance1(p,mid+1,r);
    double d=min(d1,d2);
    vector<Point> p1;
    for(int i=l;i<=r;i++)				//���е�x�������<d�ĵ�����p1�� 
        if(fabs(p[i].x-p[mid].x)<d)
            p1.push_back(p[i]);
    sort(p1.begin(),p1.end(),cmpy);		//p1�����е㰴y�������� 
    for(int i=0;i<p1.size();i++)
        for(int j=i+1,k=0;k<7 && j<p1.size() && p1[j].y-p1[i].y<d;j++,k++)
            d=min(d,dis(p1[i],p1[j]));
    return d;
}
double mindistance(vector<Point>&p)	//��p�������Ծ��� 
{
	sort(p.begin(),p.end(),cmpx);				//ȫ���㰴x�������� 
	int n=p.size();
	return mindistance1(p,0,n-1);
}
	
int main()
{
	vector<Point> p={Point(4,10),Point(3,7),Point(9,7),Point(3,4),Point(5,6),Point(5,4),Point(6,3),Point(8,1),Point(3,0),Point(1,6)};
	printf("�����Ծ���=%g\n",mindistance(p));
    return 0;
}

