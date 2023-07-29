先说下题意，很简单，给n个点的坐标，求距离最近的一对点之间距离的一半。第一行是一个数n表示有n个点，接下来n行是n个点的x坐标和y坐标，实数。


     这个题目其实就是求最近点对的距离。主要思想就是分治。先把n个点按x坐标排序，然后求左边n/2个和右边n/2个的最近距离，最后合并。合并要重点说一下，比较麻烦。


     首先，假设点是n个，编号为1到n。我们要分治求，则找一个中间的编号mid，先求出1到mid点的最近距离设为d1，还有mid+1到n的最近距离设为d2。这里的点需要按x坐标的顺序排好，并且假设这些点中，没有2点在同一个位置。（若有，则直接最小距离为0了）。


     然后，令d为d1, d2中较小的那个点。如果说最近点对中的两点都在1-mid集合中，或者mid+1到n集合中，则d就是最小距离了。但是还有可能的是最近点对中的两点分属这两个集合，所以我们必须先检测一下这种情况是否会存在，若存在，则把这个最近点对的距离记录下来，去更新d。这样我们就可以得道最小的距离d了。


    关键是要去检测最近点对，理论上每个点都要和对面集合的点匹配一次，那效率还是不能满足我们的要求。所以这里要优化。怎么优化呢？考虑一下，假如以我们所选的分割点mid为界，如果某一点的横坐标到点mid的横坐标的绝对值超过d1并且超过d2，那么这个点到mid点的距离必然超过d1和d2中的小者，所以这个点到对方集合的任意点的距离必然不是所有点中最小的。


    所以我们先把在mid为界左右一个范围内的点全部筛选出来，放到一个集合里。筛选好以后，当然可以把这些点两两求距离去更新d了，不过这样还是很慢，万一满足条件的点很多呢。这里还得继续优化。首先把这些点按y坐标排序。假设排序好以后有cnt个点，编号为0到cnt-1。那么我们用0号去和1到cnt-1号的点求一下距离，然后1号和2到cnt-1号的点求一下距离。。。如果某两个点y轴距离已经超过了d，这次循环就可以直接break了，开始从下一个点查找了.
代码：



#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
struct node
{
  double x;
  double y;
}p[100005];
int a[100005];
double cmpx(node a,node b)
{
  return a.x<b.x;
}
double cmpy(int a,int b)
{
  return p[a].y<p[b].y;
}
double min(double a,double b)
{
  return a<b?a:b;
}
double dis(node a,node b)
{
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double find(int l,int r)
{
     if(r==l+1)
      return dis(p[l],p[r]);
     if(l+2==r)
      return min(dis(p[l],p[r]),min(dis(p[l],p[l+1]),dis(p[l+1],p[r])));
     int mid=(l+r)>>1;
     double ans=min(find(l,mid),find(mid+1,r));
     int i,j,cnt=0;
     for(i=l;i<=r;i++)
     {
       if(p[i].x>=p[mid].x-ans&&p[i].x<=p[mid].x+ans)
          a[cnt++]=i;
     }
     sort(a,a+cnt,cmpy);
     for(i=0;i<cnt;i++)
     {
       for(j=i+1;j<cnt;j++)
       {
         if(p[a[j]].y-p[a[i]].y>=ans) break;
         ans=min(ans,dis(p[a[i]],p[a[j]]));
       }
     } 
     return ans;
}
int main()
{
    int i;
   
    while(scanf("%d",&n)!=EOF)
    {
      if(!n) break;
      for(i=0;i<n;i++)
       scanf("%lf %lf",&p[i].x,&p[i].y);
      sort(p,p+n,cmpx);
      printf("%.2lf%\n",find(0,n-1)/2);
    }
    return 0;
}

