/*
  此程序为全国交通咨询模拟；
  具有交通系统的编辑和用户查询等功能；
  由陈勇，马斌，华成，田昕辉，王洋，张益玮，杜媛媛，冯红伟，李年，刘丽娟开发；
  开发时间是2003.10——2003.12；
  此程序为最终版本；
*/
#define MAX_VERTEX_NUM 18
#define NULL 0
#define MAX_ARC_SIZE 100
#define MAX_ROUTE_NUM 5
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define False 0
#define True 1
#define INFINITY 10000
typedef struct
{int number;
 float expenditure;
 int begintime[2];
 int arrivetime[2];
}Vehide;
typedef struct
{Vehide stata[MAX_ROUTE_NUM];
 int last;
}infolist;
typedef struct ArcNode
{int adjvex;
 struct ArcNode *nextarc;
 infolist info;
}ArcNode;
typedef struct VNode
{char cityname[10];
 ArcNode *planefirstarc,*trainfirstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct
{AdjList vertices;
 int vexnum,planearcnum,trainarcnum;
}ALGraph;
typedef struct Node
{int adjvex;
 int route;
 struct Node *next;
}Node;
typedef struct QNode
{int adjvex;
 struct QNode *next;
}QNode;
typedef struct
{QNode *front;
 QNode *rear;
}LinkQueue;
typedef struct TimeNode
{int adjvex;
 int route;
 int begintime[2];
 int arrivetime[2];
 struct TimeNode *child[MAX_ROUTE_NUM];
}TimeNode,*TimeTree;
struct arc
{int co;
 char vt[10];
 char vh[10];
 int bt[2];
 int at[2];
 float mo;
}a[MAX_ARC_SIZE];
char city[MAX_VERTEX_NUM][10];
int TTime[2];
int time[2];
int time1[2];
int time2[2];
int c[MAX_VERTEX_NUM];
int d[MAX_VERTEX_NUM];
main()
/*
  显示程序功能选择界面
*/
{ALGraph G;
 int i;
 printf("请选择程序功能:\n");
 printf("1=管理员管理\n2=用户咨询\n3=显示交通系统\n4=退出\n");
 printf("选择?");
 scanf("%d",&i);
 getchar();
 while(i!=4)
 {switch(i)
  {case 1:Administer(&G);break;
   case 2:UserDemand(G);break;
   case 3:PrintGraph(&G);break;
  }
  printf("\n请选择程序功能:\n");
  printf("1=管理员管理\n2=用户咨询\n3=显示交通系统\n4=退出\n");
  printf("选择?");
  scanf("%d",&i);
  getchar();
 }
}
Administer(ALGraph *G)
/*
  显示管理员管理项目选择界面
*/
{int i;
 printf("\n请选择管理项目:\n");
 printf("1=初始化交通系统\n2=城市编辑\n3=飞机航班编辑\n4=列车车次编辑\n5=返回上一级菜单\n");
 printf("选择?");
 scanf("%d",&i);
 getchar();
 while(i!=5)
 {switch(i)
  {case 1:initgraph(G);
          break;
   case 2:cityedit(G);
          break;
   case 3:flightedit(G);
          break;
   case 4:trainedit(G);
          break;
  }
  printf("\n请选择管理项目:\n");
  printf("1=初始化交通系统\n2=城市编辑\n3=飞机航班编辑\n4=列车车次编辑\n5=返回上一级菜单\n");
  printf("选择?");
  scanf("%d",&i);
  getchar();
 }
}
initgraph(ALGraph *G)
/*
  初始化交通系统方式选择界面
*/
{int i;
 printf("\n请选择初始化方式:\n");
 printf("1=键盘\n2=文档\n");
 printf("选择?");
 scanf("%d",&i);
 getchar();
 switch(i)
 {case 1:createcityfile();
         createplanefile();
         createtrainfile();
         CreateGraph(G);
         break;
  case 2:CreateGraph(G);
         break;
 }
}
createcityfile()
/*
  创建城市名称文档
*/
{int i=0;
 int j;
 char flag='y';
 FILE *fp;
 printf("\n请输入城市名称的信息:\n");
 while(flag=='y'||flag=='Y')
 {printf("城市名称:");
  gets(city[i]);
  i++;
  printf("继续输入?(Y/N)");
  scanf("%c",&flag);
  getchar();
 }
 printf("\n");
 if((fp=fopen("city.txt","wb"))==NULL)
 {printf("无法打开文件!\n");
  return;
 }
 for(j=0;j<i;j++)
  fprintf(fp,"%10s",city[j]);
 fclose(fp);
}
createplanefile()
/*
  创建飞机航班文档
*/
{int code,bt[2],at[2];
 float money;
 int i;
 int count;
 char vt[10],vh[10],flag;
 FILE *fp;
 flag='y';
 count=0;
 while(flag=='Y'||flag=='y')
 {printf("请输入飞机航班的信息:\n");
  printf("飞机航班编号:");
  scanf("%d",&code);
  getchar();
  printf("起始城市:");
  gets(vt);
  printf("目的城市:");
  gets(vh);
  printf("航班费用:");
  scanf("%f",&money);
  getchar();
  printf("起飞时间:");
  scanf("%d:%d",&bt[0],&bt[1]);
  getchar();
  while(bt[0]<0||bt[0]>=24||bt[1]<0||bt[1]>=60)
  {printf("\n时间输入有误，请重新输入\n");
   scanf("%d:%d",&bt[0],&bt[1]);
   getchar();
  }
  printf("到达时间:");
  scanf("%d:%d",&at[0],&at[1]);
  getchar();
  while(at[0]<0||at[0]>=24||at[1]<0||at[1]>=60)
  {printf("\n时间输入有误，请重新输入\n");
   scanf("%d:%d",&at[0],&at[1]);
   getchar();
  }
  a[count].co=code;
  strcpy(a[count].vt,vt);
  strcpy(a[count].vh,vh);
  a[count].bt[0]=bt[0];
  a[count].bt[1]=bt[1];
  a[count].at[0]=at[0];
  a[count].at[1]=at[1];
  a[count].mo=money;
  count++;
  printf("继续输入?(Y/N)");
  scanf("%c",&flag);
  getchar();
  printf("\n");
 }
 if((fp=fopen("plane.txt","wb"))==NULL)
  printf("\n无法打开文件!\n");
 fprintf(fp,"%d",count);
 for(i=0;i<count;i++)
  if(fwrite(&a[i],sizeof(struct arc),1,fp)!=1)
   printf("\n文件写入错误!\n");
 fclose(fp);
}
createtrainfile()
/*
  创建列车车次文档
*/
{int code,bt[2],at[2];
 float money;
 int i;
 int count;
 char vt[10],vh[10],flag;
 FILE *fp;
 flag='y';
 count=0;
 while(flag=='y'||flag=='Y')
 {printf("请输入列车车次的信息:\n");
  printf("列车车次编号:");
  scanf("%d",&code);
  getchar();
  printf("起始城市:");
  gets(vt);
  printf("目的城市:");
  gets(vh);
  printf("车次费用:");
  scanf("%f",&money);
  getchar();
  printf("发车时间:");
  scanf("%d:%d",&bt[0],&bt[1]);
  getchar();
  while(bt[0]<0||bt[0]>=24||bt[1]<0||bt[1]>=60)
  {printf("\n时间输入有误，请重新输入\n");
   scanf("%d:%d",&bt[0],&bt[1]);
   getchar();
  }
  printf("到达时间:");
  scanf("%d:%d",&at[0],&at[1]);
  getchar();
  while(at[0]<0||at[0]>=24||at[1]<0||at[1]>=60)
  {printf("\n时间输入有误，请重新输入\n");
   scanf("%d:%d",&at[0],&at[1]);
   getchar();
  }
  a[count].co=code;
  strcpy(a[count].vt,vt);
  strcpy(a[count].vh,vh);
  a[count].bt[0]=bt[0];
  a[count].bt[1]=bt[1];
  a[count].at[0]=at[0];
  a[count].at[1]=at[1];
  a[count].mo=money;
  count++;
  printf("继续输入?(Y/N)");
  scanf("%c",&flag);
  getchar();
  printf("\n");
 }
 if((fp=fopen("train.txt","wb"))==NULL)
  printf("\n无法打开文件!\n");
 fprintf(fp,"%d",count);
 for(i=0;i<count;i++)
  if(fwrite(&a[i],sizeof(struct arc),1,fp)!=1)
   printf("\n文件写入错误!\n");
 fclose(fp);
}
int LocateVertex(ALGraph *G,char *v)
/*
  城市名在交通系统中定位操作
*/
{int j,k;
 j=-1;
 for(k=0;k<G->vexnum;k++)
  if(strcmp(G->vertices[k].cityname,v)==0)
  {j=k;
   break;
  }
 return(j);
}
CreateGraph(ALGraph *G)
/*
  用city，plan，train三个文档创建城市交通系统
*/
 {int i,j,k;
 int arc_num;
 int count1,count2;
 int m,t;
 ArcNode *p,*q;
 FILE *fp;
 i=0;
 if((fp=fopen("city.txt","rb"))==NULL)
 {printf("\n无法打开文件!\n");
  return;
 }
 while(!feof(fp))
 {fscanf(fp,"%10s",city[i]);
  i++;
 }
 fclose(fp);
 j=0;
 while(j<i)
 {strcpy(G->vertices[j].cityname,city[j]);
  G->vertices[j].planefirstarc=NULL;
  G->vertices[j].trainfirstarc=NULL;
  j++;
 }
 G->vexnum=i;
 if((fp=fopen("plane.txt","rb"))==NULL)
  printf("\n无法打开文件!\n");
 k=0;
 fscanf(fp,"%d",&count1);
 while(k<count1)
 {if(fread(&a[k],sizeof(struct arc),1,fp)!=1)
   printf("\n文件读入错误!\n");
  k++;
 }
 fclose(fp);
 k=0;
 arc_num=0;
 while(k<count1)
 {i=LocateVertex(G,a[k].vt);
  j=LocateVertex(G,a[k].vh);
  q=G->vertices[i].planefirstarc;
  m=0;
  while(q!=NULL)
  {if(q->adjvex==j)
   {t=q->info.last+1;
    q->info.stata[t].number=a[k].co;
    q->info.stata[t].expenditure=a[k].mo;
    q->info.stata[t].begintime[0]=a[k].bt[0];
    q->info.stata[t].begintime[1]=a[k].bt[1];
    q->info.stata[t].arrivetime[0]=a[k].at[0];
	q->info.stata[t].arrivetime[1]=a[k].at[1];
    q->info.last=t;
    m=1;
    break;
   }
   q=q->nextarc;
  }
  if(m==0)
  {p=(ArcNode*)malloc(sizeof(ArcNode));
   p->adjvex=j;
   p->info.stata[0].number=a[k].co;
   p->info.stata[0].expenditure=a[k].mo;
   p->info.stata[0].begintime[0]=a[k].bt[0];
   p->info.stata[0].begintime[1]=a[k].bt[1];
   p->info.stata[0].arrivetime[0]=a[k].at[0];
   p->info.stata[0].arrivetime[1]=a[k].at[1];
   p->info.last=0;
   p->nextarc=G->vertices[i].planefirstarc;
   G->vertices[i].planefirstarc=p;
   arc_num++;
  }
  k++;
 }
 G->planearcnum=arc_num;
 if((fp=fopen("train.txt","rb"))==NULL)
 {printf("\n无法打开文件!\n");
  return;
 }
 k=0;
 fscanf(fp,"%d",&count2);
 while(k<count2)
 {if(fread(&a[k],sizeof(struct arc),1,fp)!=1)
   printf("\n文件读入错误!\n");
  k++;
 }
 fclose(fp);
 k=0;
 arc_num=0;
 while(k<count2)
 {i=LocateVertex(G,a[k].vt);
  j=LocateVertex(G,a[k].vh);
  q=G->vertices[i].trainfirstarc;
  m=0;
  while(q!=NULL)
  {if(q->adjvex==j)
   {t=q->info.last+1;
    q->info.stata[t].number=a[k].co;
    q->info.stata[t].expenditure=a[k].mo;
    q->info.stata[t].begintime[0]=a[k].bt[0];
	q->info.stata[t].begintime[1]=a[k].bt[1];
    q->info.stata[t].arrivetime[0]=a[k].at[0];
	q->info.stata[t].arrivetime[1]=a[k].at[1];
    q->info.last=t;
    m=1;
    break;
   }
   q=q->nextarc;
  }
  if(m==0)
  {p=(ArcNode*)malloc(sizeof(ArcNode));
   p->adjvex=j;
   p->info.stata[0].number=a[k].co;
   p->info.stata[0].expenditure=a[k].mo;
   p->info.stata[0].begintime[0]=a[k].bt[0];
   p->info.stata[0].begintime[1]=a[k].bt[1];
   p->info.stata[0].arrivetime[0]=a[k].at[0];
   p->info.stata[0].arrivetime[1]=a[k].at[1];
   p->info.last=0;
   p->nextarc=G->vertices[i].trainfirstarc;
   G->vertices[i].trainfirstarc=p;
   arc_num++;
  }
  k++;
 }
 G->trainarcnum=arc_num;
}
save(ALGraph *G)
/*
  保存城市交通系统到相应的文档
*/
{int i,j,k,t;
 ArcNode *q;
 FILE *fp;
 j=0;
 while(j<G->vexnum)
 {strcpy(city[j],G->vertices[j].cityname);
  j++;
 }
 i=0;
 if((fp=fopen("city.txt","wb"))==NULL)
 printf("\n\错误！无法打开文件!\n");
 while(i<G->vexnum)
 {fprintf(fp,"%10s",city[i]);
  i++;
 }
 fclose(fp);
 k=0;
 for(i=0;i<G->vexnum;i++)
 {q=G->vertices[i].planefirstarc;
  while(q!=NULL)
  {for(t=0;t<=q->info.last;t++)
   {strcpy(a[k].vt,G->vertices[i].cityname);
    strcpy(a[k].vh,G->vertices[q->adjvex].cityname);
    a[k].co=q->info.stata[t].number;
    a[k].mo=q->info.stata[t].expenditure;
    a[k].bt[0]=q->info.stata[t].begintime[0];
	a[k].bt[1]=q->info.stata[t].begintime[1];
    a[k].at[0]=q->info.stata[t].arrivetime[0];
	a[k].at[1]=q->info.stata[t].arrivetime[1];
    k++;
   }
   q=q->nextarc;
  }
 }
 if((fp=fopen("plane.txt","wb"))==NULL)
 {printf("\n无法打开文件!\n");
  return;
 }
 i=0;
 fprintf(fp,"%d",k);
 while(i<k)
 {if(fwrite(&a[i],sizeof(struct arc),1,fp)!=1)
  printf("\n文件写入错误!\n");
  i++;
 }
 fclose(fp);
 k=0;
 for(i=0;i<G->vexnum;i++)
 {q=G->vertices[i].trainfirstarc;
  while(q!=NULL)
  {for(t=0;t<=q->info.last;t++)
   {strcpy(a[k].vt,G->vertices[i].cityname);
    strcpy(a[k].vh,G->vertices[q->adjvex].cityname);
    a[k].co=q->info.stata[t].number;
    a[k].mo=q->info.stata[t].expenditure;
    a[k].bt[0]=q->info.stata[t].begintime[0];
	a[k].bt[1]=q->info.stata[t].begintime[1];
    a[k].at[0]=q->info.stata[t].arrivetime[0];
	a[k].at[1]=q->info.stata[t].arrivetime[1];
    k++;				
   }
   q=q->nextarc;
  }
 }
 if((fp=fopen("train.txt","wb"))==NULL)
 {printf("\n无法打开文件!\n");
  return;
 }
 i=0;
 fprintf(fp,"%d",k);
 while(i<k)
 {if(fwrite(&a[i],sizeof(struct arc),1,fp)!=1)
  printf("\n文件写入错误!\n");
  i++;
 }
 fclose(fp); 
}
cityedit(ALGraph *G)
/*
  显示城市编辑项目选择界面
*/
{int i;
 char q;
 printf("\n请选择城市编辑项目:\n");
 printf("1=增加城市\n2=删除城市\n");
 printf("选择?");
 scanf("%d",&i);
 getchar();
 if(i==1)
  EnterVertex(G);
 if(i==2)
  DeleteVertex(G);
}
EnterVertex(ALGraph *G)
/*
  增加城市
*/
{char v[10],c;
 int i;
 printf("\n请输入新增城市的名称:");
 gets(v);
 i=LocateVertex(G,v);
 if(i>=0&&i<G->vexnum)
 {printf("\n错误！此城市已存在\n");
  return;
 }
 else
 {printf("\n确认?(Y/N)");
  c=getchar();
  getchar();
  if(c=='Y'||c=='y')
  {i=G->vexnum;
   strcpy(G->vertices[i].cityname,v);
   G->vertices[i].planefirstarc=NULL;
   G->vertices[i].trainfirstarc=NULL;
   G->vexnum=i+1;
   save(G);
  }
  else
   return;
 }
}
DeleteVertex(ALGraph *G)
/*
  删除城市
*/
{int i,j,k,n;
 char v[10],c;
 ArcNode *p,*q,*m;
 printf("\n请输入删除的城市:");
 gets(v);
 printf("\n确认?(Y/N)");
 c=getchar();
 getchar();
 if(c=='Y'||c=='y')
 {n=0;
  while(n<G->vexnum&&strcmp(G->vertices[n].cityname,v)!=0)
   n++;
  if(n==G->vexnum)
   printf("\n错误！无法找到此城市!\n");
  else
  {i=LocateVertex(G,v);
   p=G->vertices[i].planefirstarc;
   while(p!=NULL)
   {q=p;
    p=p->nextarc;
    free(q);
   }
   p=G->vertices[i].trainfirstarc;
   while(p!=NULL)
   {q=p;
    p=p->nextarc;
    free(q);
   }
   for(j=i;j<G->vexnum-1;j++)
   {strcpy(G->vertices[j].cityname,G->vertices[j+1].cityname);
    G->vertices[j].planefirstarc=G->vertices[j+1].planefirstarc;
    G->vertices[j].trainfirstarc=G->vertices[j+1].trainfirstarc;
   }
   G->vertices[j].planefirstarc=NULL;
   G->vertices[j].trainfirstarc=NULL;
   for(k=0;k<G->vexnum-1;k++)
   {p=G->vertices[k].planefirstarc;
    while(p!=NULL)
    {if(p->adjvex>i)
     {p->adjvex=p->adjvex-1;
      q=p;
      p=p->nextarc;
     }
     else if(p->adjvex==i)
     {if(p==G->vertices[k].planefirstarc)
      {m=p;
       G->vertices[k].planefirstarc=p->nextarc;
       p=p->nextarc;
       free(m);
      }
      else
      {q->nextarc=p->nextarc;
       m=p;
       p=p->nextarc;
       free(q);
      }
     }
     else
     {q=p;
      p=p->nextarc;
     }
    }
   }
   for(k=0;k<G->vexnum-1;k++)
   {p=G->vertices[k].trainfirstarc;
    while(p!=NULL)
    {if(p->adjvex>i)
     {p->adjvex=p->adjvex-1;
      q=p;
      p=p->nextarc;
     }
     else if(p->adjvex==i)
     {if(p==G->vertices[k].trainfirstarc)
      {m=p;
       G->vertices[k].trainfirstarc=p->nextarc;
       p=p->nextarc;
       free(m);
      }
      else
      {q->nextarc=p->nextarc;
       m=p;
       p=p->nextarc;
       free(q);
      }
     }
     else
     {q=p;
      p=p->nextarc;
     }
    }
   }
  }
  G->vexnum--;
  save(G);
 }
 else
  return;
}
flightedit(ALGraph *G)
/*
  飞机航班编辑项目选择界面
*/
{int i;
 char q;
 printf("\n请选择飞机航班编辑项目:\n");
 printf("1=新增航班\n2=删除航班\n");
 printf("选择?");
 scanf("%d",&i);
 getchar();
 if(i==1)
  EnterplaneArc(G);
 if(i==2)
  DeleteplaneArc(G);
}
trainedit(ALGraph *G)
/* 
  列车车次编辑项目选择界面
*/
{int i;
 char q;
 printf("\n请选择列车车次编辑项目:\n");
 printf("1=新增车次\n2=删除车次\n");
 printf("选择?");
 scanf("%d",&i);
 getchar();
 if(i==1)
  EntertrainArc(G);
 if(i==2)
  DeletetrainArc(G);
}
EnterplaneArc(ALGraph *G)
/*
  增加飞机航班
*/
{int i,j,bt[2],at[2];
 int code;
 float money;
 int m,t;
 char vt[10],vh[10],c;
 ArcNode *p,*q;
 printf("\n请输入新增飞机航班的信息:\n");
 printf("飞机航班编号:");
 scanf("%d",&code);
 getchar();
 printf("起始城市:");
 gets(vt);
 printf("目的城市:");
 gets(vh);
 printf("航班费用:");
 scanf("%f",&money);
 getchar();
 printf("起飞时间:");
 scanf("%d:%d",&bt[0],&bt[1]);
 getchar();
 while(bt[0]<0||bt[0]>=24||bt[1]<0||bt[1]>=60)
 {printf("\n时间输入有误，请重新输入\n");
  scanf("%d:%d",&bt[0],&bt[1]);
  getchar();
 }
 printf("到达时间:");
 scanf("%d:%d",&at[0],&at[1]);
 getchar();
 while(at[0]<0||at[0]>=24||at[1]<0||at[1]>=60)
 {printf("\n时间输入有误，请重新输入\n");
  scanf("%d:%d",&at[0],&at[1]);
  getchar();
 }
 printf("\n确认?(Y/N)");
 c=getchar();
 getchar();
 if(c=='Y'||c=='y')
 {i=LocateVertex(G,vt);
  j=LocateVertex(G,vh);
  if(i==-1)
  {printf("\n错误！无法找到起始城市\n");
   return;
  }
  if(j==-1)
  {printf("\n错误！无法找到到达城市\n");
   return;
  }
  q=G->vertices[i].planefirstarc;
  m=0;
  while(q!=NULL)
  {if(q->adjvex==j)
   {t=q->info.last+1;
    q->info.stata[t].number=code;
    q->info.stata[t].expenditure=money;
    q->info.stata[t].begintime[0]=bt[0];
    q->info.stata[t].begintime[1]=bt[1];
    q->info.stata[t].arrivetime[0]=at[0];
	q->info.stata[t].arrivetime[1]=at[1];
    q->info.last=t;
    m=1;
    break;
   }
   q=q->nextarc;
  }
  if(m==0)
  {p=(ArcNode*)malloc(sizeof(ArcNode));
   p->adjvex=j;
   p->info.stata[0].number=code;
   p->info.stata[0].expenditure=money;
   p->info.stata[0].begintime[0]=bt[0];
   p->info.stata[0].begintime[1]=bt[1];
   p->info.stata[0].arrivetime[0]=at[0];
   p->info.stata[0].arrivetime[1]=at[1];
   p->info.last=0;
   p->nextarc=G->vertices[i].planefirstarc;
   G->vertices[i].planefirstarc=p;
   G->planearcnum++;
  }
  save(G);
 }
 else
  return;
}
EntertrainArc(ALGraph *G)
/*
  增加列车车次
*/
{int i,j,bt[2],at[2];
 int code;
 float money;
 int m,t;
 char vt[10],vh[10],c;
 ArcNode *p,*q;
 printf("\n请输入新增列车车次的信息:\n");
 printf("列车车次编号:");
 scanf("%d",&code);
 getchar();
 printf("起始城市:");
 gets(vt);
 printf("目的城市:");
 gets(vh);
 printf("车次费用:");
 scanf("%f",&money);
 getchar();
 printf("发车时间:");
 scanf("%d:%d",&bt[0],&bt[1]);
 getchar();
 while(bt[0]<0||bt[0]>=24||bt[1]<0||bt[1]>=60)
 {printf("\n时间输入有误，请重新输入\n");
  scanf("%d:%d",&bt[0],&bt[1]);
  getchar();
 }
 printf("到达时间:");
 scanf("%d:%d",&at[0],&at[1]);
 getchar();
 while(at[0]<0||at[0]>=24||at[1]<0||at[1]>=60)
 {printf("\n时间输入有误，请重新输入\n");
  scanf("%d:%d",&at[0],&at[1]);
  getchar();
 }
 printf("\n确认?(Y/N)");
 c=getchar();
 getchar();
 if(c=='Y'||c=='y')
 {i=LocateVertex(G,vt);
  j=LocateVertex(G,vh);
  if(i==-1)
  {printf("\n错误！无法找到起始城市\n");
   return;
  }
  if(j==-1)
  {printf("\n错误！无法找到到达城市\n");
   return;
  }
  q=G->vertices[i].trainfirstarc;
  m=0;
  while(q!=NULL)
  {if(q->adjvex==j)
   {t=q->info.last+1;
    q->info.stata[t].number=code;
    q->info.stata[t].expenditure=money;
    q->info.stata[t].begintime[0]=bt[0];
	q->info.stata[t].begintime[1]=bt[1];
    q->info.stata[t].arrivetime[0]=at[0];
	q->info.stata[t].arrivetime[1]=at[1];
    q->info.last=t;
    m=1;
    break;
   }
   q=q->nextarc;
  }
  if(m==0)
  {p=(ArcNode*)malloc(sizeof(ArcNode));
   p->adjvex=j;
   p->info.stata[0].number=code;
   p->info.stata[0].expenditure=money;
   p->info.stata[0].begintime[0]=bt[0];
   p->info.stata[0].begintime[1]=bt[1];
   p->info.stata[0].arrivetime[0]=at[0];
   p->info.stata[0].arrivetime[1]=at[1];
   p->info.last=0;
   p->nextarc=G->vertices[i].trainfirstarc;
   G->vertices[i].trainfirstarc=p;
   G->trainarcnum++;
  }
  save(G);
 }
 else
  return;
}
DeleteplaneArc(ALGraph *G)
/*
  删除飞机航班
*/
{int i,j;
 int code;
 char vt[10],vh[10],c;
 int n;
 int k;
 ArcNode *p,*q;
 printf("\n请输入删除飞机航班的信息:\n");
 printf("飞机航班的编号:");
 scanf("%d",&code);
 getchar();
 printf("起始城市:");
 gets(vt);
 printf("目的城市:");
 gets(vh);
 printf("\n确认?(Y/N)");
 c=getchar();
 getchar();
 if(c=='Y'||c=='y')
 {i=LocateVertex(G,vt);
  j=LocateVertex(G,vh);
  if(i==-1)
  {printf("\n错误！无法找到起始城市\n");
   return;
  }
  if(j==-1)
  {printf("\n错误！无法找到目的城市\n");
   return;
  }
  p=G->vertices[i].planefirstarc;
  q=p;
  while(p!=NULL)
  {if(p->adjvex==j)
   {n=-1;
    for(k=0;k<=p->info.last;k++)
    {if(p->info.stata[k].number==code)
     {n=k;
      break;
     }
    }
    if(n!=-1)
     if(p->info.last==0)
     {if(q==p)
       G->vertices[i].planefirstarc=p->nextarc;
      else
       q->nextarc=p->nextarc;
      free(p);
     }
     else
     {for(k=n;k<p->info.last;k++)
      {p->info.stata[k].number=p->info.stata[k+1].number;
       p->info.stata[k].expenditure=p->info.stata[k+1].expenditure;
       p->info.stata[k].begintime[0]=p->info.stata[k+1].begintime[0];
	   p->info.stata[k].begintime[1]=p->info.stata[k+1].begintime[1];
       p->info.stata[k].arrivetime[0]=p->info.stata[k+1].arrivetime[0];
	   p->info.stata[k].arrivetime[1]=p->info.stata[k+1].arrivetime[1];
      }
      p->info.last=p->info.last-1;
     }
    else
     printf("\n在此两城市之间无法找到No.%d飞机航班\n",code);
    save(G);
    return;
   }
   q=p;
   p=p->nextarc;
  }
  if(p==NULL)
   printf("\n在此两城市之间无飞机航班存在\n");
 }
 else
  return;
}
DeletetrainArc(ALGraph *G)
/*
  删除列车车次
*/
{int i,j;
 int code;
 char vt[10],vh[10],c;
 int n;
 int k;
 ArcNode *p,*q;
 printf("\n请输入删除列车车次的信息:\n");
 printf("列车车次的编号:");
 scanf("%d",&code);
 getchar();
 printf("起始城市:");
 gets(vt);
 printf("目的城市:");
 gets(vh);
 printf("\n确认?(Y/N)");
 c=getchar();
 getchar();
 if(c=='Y'||c=='y')
 {i=LocateVertex(G,vt);
  j=LocateVertex(G,vh);
  if(i==-1)
  {printf("\n错误！无法找到起始城市\n");
   return;
  }
  if(j==-1)
  {printf("\n错误！无法找到目的城市\n");
   return;
  }
  p=G->vertices[i].trainfirstarc;
  q=p;
  while(p!=NULL)
  {if(p->adjvex==j)
   {n=-1;
    for(k=0;k<=p->info.last;k++)
    {if(p->info.stata[k].number==code)
     {n=k;
      break;
     }
    }
    if(n!=-1)
     if(p->info.last==0)
     {if(q==p)
       G->vertices[i].trainfirstarc=p->nextarc;
      else
       q->nextarc=p->nextarc;
      free(p);
     }
     else
     {for(k=n;k<p->info.last;k++)
      {p->info.stata[k].number=p->info.stata[k+1].number;
       p->info.stata[k].expenditure=p->info.stata[k+1].expenditure;
       p->info.stata[k].begintime[0]=p->info.stata[k+1].begintime[0];
	   p->info.stata[k].begintime[1]=p->info.stata[k+1].begintime[1];
       p->info.stata[k].arrivetime[0]=p->info.stata[k+1].arrivetime[0];
	   p->info.stata[k].arrivetime[1]=p->info.stata[k+1].arrivetime[1];
      }
      p->info.last=p->info.last-1;
     }
    else
     printf("\n在此两城市之间无法找到No.%d列车车次\n",code);
    save(G);
    return;
   }
   q=p;
   p=p->nextarc;
  }
  if(p==NULL)
   printf("\n在此两城市之间无列车车次存在\n");
 }
 else
  return;
}
UserDemand(ALGraph G)
/*
  用户咨询项目选择界面
*/
{int i;
 char q;
 printf("\n请选择咨询项目:\n");
 printf("1=最少旅行费用\n2=最少旅行时间\n3=最少旅行中转次数\n4=返回上一级菜单\n");
 printf("选择?");
 scanf("%d",&i);
 getchar();
 while(i!=4)
 {switch(i)
  {case 1:DemandDispose(1,G);break;
   case 2:DemandDispose(2,G);break;
   case 3:DemandDispose(3,G);break;
  }
  printf("按回车继续\n");
  scanf("%c",&q);
  scanf("%c",&q);
  printf("请选择咨询项目:\n");
  printf("1=最少旅行费用\n2=最少旅行时间\n3=最少旅行中转次数\n4=返回上一级菜单\n");
  printf("选择?");
  scanf("%d",&i);
  getchar();
 }
}
DemandDispose(int n,ALGraph G)
/*
  用户咨询选择信息输入界面
*/
{char name[10],q;
 ArcNode *plane,*train;
 infolist planearcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM],trainarcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
 int i,j,k,final[MAX_VERTEX_NUM],T[MAX_VERTEX_NUM][2];
 float M[MAX_VERTEX_NUM];
 for(i=0;i<G.vexnum;i++)
  for(j=0;j<G.vexnum;j++)
   for(k=0;k<MAX_ROUTE_NUM;k++)
   {planearcs[i][j].stata[k].expenditure=INFINITY;
    planearcs[i][j].stata[k].begintime[0]=0;
	planearcs[i][j].stata[k].begintime[1]=0;
    planearcs[i][j].stata[k].arrivetime[0]=INFINITY;
	planearcs[i][j].stata[k].arrivetime[1]=INFINITY;
    planearcs[i][j].last=-1;
    trainarcs[i][j].stata[k].expenditure=INFINITY;
    trainarcs[i][j].stata[k].begintime[0]=0;
	trainarcs[i][j].stata[k].begintime[1]=0;
    trainarcs[i][j].stata[k].arrivetime[0]=INFINITY;
	trainarcs[i][j].stata[k].arrivetime[1]=INFINITY;
    trainarcs[i][j].last=-1;
   }
 for(i=0;i<G.vexnum;i++)
 {plane=G.vertices[i].planefirstarc;
  train=G.vertices[i].trainfirstarc;
  while(plane!=NULL)
  {planearcs[i][plane->adjvex]=plane->info;
   plane=plane->nextarc;
  }
  while(train!=NULL)
  {trainarcs[i][train->adjvex]=train->info;
   train=train->nextarc;
  }
 }
 printf("\n请选择旅行起始城市:\n");
 for(k=0;k<G.vexnum;k++)
  printf("%d=%s\n",k,G.vertices[k].cityname);
 printf("选择?");
 scanf("%d",&i);
 printf("\n请选择旅行到达城市:\n");
 for(k=0;k<G.vexnum;k++)
  printf("%d=%s\n",k,G.vertices[k].cityname);
 printf("选择?");
 scanf("%d",&j);
 printf("\n请选择交通工具:\n");
 printf("1=列车\n2=飞机\n");
 printf("选择?");
 scanf("%d",&k);
 printf("\n确认? (Y/N)");
 scanf("%c",&q);
 scanf("%c",&q);
 if(q=='Y'||q=='y')
 {if(k==1&&n==1)
   ExpenditureDispose(1,trainarcs,G,i,j,M,final);
  else if(k==1&&n==2)
   TimeDispose(1,trainarcs,G,i,j,T,final);
  else if(k==1&&n==3)
   TransferDispose(1,trainarcs,G,i,j);
  else if(k==2&&n==1)
   ExpenditureDispose(2,planearcs,G,i,j,M,final);
  else if(k==2&&n==2)
   TimeDispose(2,planearcs,G,i,j,T,final);
  else if(k==2&&n==3)
   TransferDispose(2,planearcs,G,i,j);
 }
 else if(q=='N'||q=='n')
  UserDemand(G);
 else
 {printf("\n选择错误\n\n");
  DemandDispose(k,G);
 }
}
void InitQueue(LinkQueue *Q)
/*
  初始化队列
*/
{Q->front=(QNode *)malloc(sizeof(QNode));
 Q->rear=Q->front;
 Q->front->next=NULL;
}
void EnterQueue(LinkQueue *Q,int x)
/*
  入队操作
*/
{QNode *newnode;
 newnode=(QNode *)malloc(sizeof(QNode));
 newnode->adjvex=x;
 newnode->next=NULL;
 Q->rear->next=newnode;
 Q->rear=newnode;
}
void DeleteQueue(LinkQueue *Q,int *x)
/*
  出队操作
*/
{QNode *p;
 p=Q->front->next;
 Q->front->next=p->next;
 if(Q->rear==p)
  Q->rear=Q->front;
 *x=p->adjvex;
 free(p);
}
int IsEmpty(LinkQueue *Q)
/*
  队列判空操作
*/
{if(Q->front==Q->rear)
  return(1);
 else
  return(0);
}
TransferDispose(int k,infolist (*arcs)[MAX_VERTEX_NUM],ALGraph G,int v0,int v1)
/*
  最少旅行中转次数处理
*/
{int visited[MAX_VERTEX_NUM],v,w,n=1;
 LinkQueue Q;
 ArcNode *t;
 Node *p,*q,*r,*s;
 p=(Node *)malloc(G.vexnum*sizeof(Node));
 for(v=0;v<G.vexnum;v++)
 {visited[v]=0;
  p[v].next=NULL;
 }
 InitQueue(&Q);
 visited[v0]=1;
 q=(Node *)malloc(sizeof(Node));
 q->adjvex=v0;
 q->next=NULL;
 p[v0].next=q;
 EnterQueue(&Q,v0);
 while(!IsEmpty(&Q))
 {DeleteQueue(&Q,&v);
  if(k==1)
   t=G.vertices[v].trainfirstarc;
  else
   t=G.vertices[v].planefirstarc;
  while(t!=NULL)
  {w=t->adjvex;
   if(!visited[w])
   {visited[w]=1;
    q=&p[w];
    s=p[v].next;
    while(s!=NULL)
    {r=(Node *)malloc(sizeof(Node));
     r->adjvex=s->adjvex;
     q->next=r;
     q=r;
     s=s->next;
    }
    r=(Node *)malloc(sizeof(Node));
    r->adjvex=w;
    r->next=NULL;
    q->next=r;
    if(w==v1)
    {q=p[w].next;
     r=q->next;
     printf("\n旅行路线是:\n");
     while(r!=NULL)
     {if(k==1)
       printf("乘坐No.%d列车车次在%d:%d从%s到%s\n",(*(*(arcs+q->adjvex)+r->adjvex)).stata[0].number,(*(*(arcs+q->adjvex)+r->adjvex)).stata[0].begintime[0],(*(*(arcs+q->adjvex)+r->adjvex)).stata[0].begintime[1],G.vertices[q->adjvex].cityname,G.vertices[r->adjvex].cityname);
      else
       printf("乘坐No.%d飞机航班在%d:%d从%s到%s\n",(*(*(arcs+q->adjvex)+r->adjvex)).stata[0].number,(*(*(arcs+q->adjvex)+r->adjvex)).stata[0].begintime[0],(*(*(arcs+q->adjvex)+r->adjvex)).stata[0].begintime[1],G.vertices[q->adjvex].cityname,G.vertices[r->adjvex].cityname);
      q=r;
      r=r->next;
      n++;
     }
     printf("最少中转次数是%d次\n\n",n-2);
     for(v=0;v<G.vexnum;v++)
     {q=p[v].next;
      while(q!=NULL)
      {s=q;
       q=q->next;
       free(s);
      }
      p[v].next=NULL;
     }
     free(p);
     return;
    }
    EnterQueue(&Q,w);
   }
   t=t->nextarc;
  }
 }
 for(v=0;v<G.vexnum;v++)
 {q=p[v].next;
  while(q!=NULL)
  {s=q;
   q=q->next;
   free(s);
  }
  p[v].next=NULL;
 }
 free(p);
 if(k==1)
  printf("\n不存在列车车次从%s到%s\n\n",G.vertices[v0].cityname,G.vertices[v1].cityname);
 else
  printf("\n不存在飞机航班从%s到%s\n\n",G.vertices[v0].cityname,G.vertices[v1].cityname);
}
MinExpenditure(infolist arcs,float *expenditure,int *route)
/*
  两直达城市之间最少旅行费用和相应路径
*/
{int i;
 *expenditure=arcs.stata[0].expenditure;
 if(*expenditure<INFINITY)
  *route=0;
 else
  *route=-1;
 for(i=1;i<=arcs.last;i++)
  if(arcs.stata[i].expenditure<*expenditure)
  {*expenditure=arcs.stata[i].expenditure;
   *route=i;
  }
}
ExpenditureDispose(int k,infolist (*arcs)[MAX_VERTEX_NUM],ALGraph G,int v0,int v1,float *M,int *final)
/*
  最少旅行费用处理
*/
{int v=-1,w,i,route;
 float m,expenditure;
 Node *p,*q,*r,*s;
 p=(Node *)malloc(G.vexnum*sizeof(Node));
 for(v=0;v<G.vexnum;v++)
 {*(final+v)=False;
  MinExpenditure(*(*(arcs+v0)+v),M+v,&route);
  p[v].next=NULL;
  if(*(M+v)<INFINITY)
  {q=(Node *)malloc(sizeof(Node));
   s=(Node *)malloc(sizeof(Node));
   q->adjvex=v0;
   s->adjvex=v;
   s->route=route;
   p[v].next=q;
   q->next=s;
   s->next=NULL;
  }
 }
 *(M+v0)=0;
 *(final+v0)=True;
 for(i=1;i<G.vexnum;i++)
 {m=INFINITY;
  v=-1;
  for(w=0;w<G.vexnum;w++)
   if(*(final+w)==False)
    if(*(M+w)<m)
    {v=w;
     m=*(M+w);
    }
  if(v==v1)
  {q=p[v].next;
   r=q->next;
   printf("\n旅行路线是:\n");
   while(r!=NULL)
   {if(k==1)
     printf("乘坐No.%d列车车次在%d:%d从%s到%s\n",(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].number,(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[0],(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[1],G.vertices[q->adjvex].cityname,G.vertices[r->adjvex].cityname);
    else
     printf("乘坐No.%d飞机航班在%d:%d从%s到%s\n",(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].number,(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[0],(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[1],G.vertices[q->adjvex].cityname,G.vertices[r->adjvex].cityname);
    q=r;
    r=r->next;
   }
   printf("最少旅行费用是%f元\n\n",m);
   for(v=0;v<G.vexnum;v++)
   {q=p[v].next;
    while(q!=NULL)
    {s=q;
     q=q->next;
     free(s);
    }
    p[v].next=NULL;
   }
   free(p);
   return;
  }
  else if(v!=-1)
  {*(final+v)=True;
   for(w=0;w<G.vexnum;w++)
    if(*(final+w)==False&&(*(*(arcs+v)+w)).last>-1)
    {MinExpenditure(*(*(arcs+v)+w),&expenditure,&route);
     if(*(M+w)>m+expenditure)
     {*(M+w)=m+expenditure;
      q=p[w].next;
      while(q!=NULL)
      {s=q;
       q=q->next;
       free(s);
      }
      q=&p[w];
      s=p[v].next;
      while(s!=NULL)
      {r=(Node *)malloc(sizeof(Node));
       r->adjvex=s->adjvex;
       r->route=s->route;
       q->next=r;
       q=r;
       s=s->next;
      }
      r=(Node *)malloc(sizeof(Node));
      r->adjvex=w;
      r->route=route;
      r->next=NULL;
      q->next=r;
     }
    }
  }
 }
 for(v=0;v<G.vexnum;v++)
 {q=p[v].next;
  while(q!=NULL)
  {s=q;
   q=q->next;
   free(s);
  }
  p[v].next=NULL;
 }
 free(p);
 if(k==1)
  printf("\n不存在列车车次从%s到%s\n\n",G.vertices[v0].cityname,G.vertices[v1].cityname);
 else
  printf("\n不存在飞机航班从%s到%s\n\n",G.vertices[v0].cityname,G.vertices[v1].cityname);
}
MinTime(infolist arcs,int *time,int *route)
/*
  两直达城市之间最少旅行时间和相应路径
*/
{int i,t[2];
 time[0]=arcs.stata[0].arrivetime[0]-arcs.stata[0].begintime[0];
 time[1]=arcs.stata[0].arrivetime[1]-arcs.stata[0].begintime[1];
 if(time[0]<0)
  time[0]=time[0]+24;
 if(time[1]<0)
 {time[0]--;
  time[1]=time[1]+60;
 }
 *route=0;
 for(i=1;i<=arcs.last;i++)
 {t[0]=arcs.stata[i].arrivetime[0]-arcs.stata[i].begintime[0];  
  t[1]=arcs.stata[i].arrivetime[1]-arcs.stata[i].begintime[1];	 
  if(t[0]<0)
   t[0]=t[0]+24;
  if(t[1]<0)
  {t[0]--;
   t[1]=t[1]+60;
  }
  if(t[0]<time[0]||(t[0]==time[0]&&t[1]<time[1]))
  {time[0]=t[0];
   time[1]=t[1];
   *route=i;
  }
 }
}
TimeTreeDispose(Node *head,infolist (*arcs)[MAX_VERTEX_NUM])
/*
  时间树处理
*/
{int n,i,j;
 Node *p;
 LinkQueue Q;
 TimeTree root,q;
 root=(TimeNode *)malloc(sizeof(TimeNode));
 InitQueue(&Q);
 TTime[0]=INFINITY;
 TTime[1]=INFINITY;
 p=head->next;
 while(p!=NULL)
 {EnterQueue(&Q,p->adjvex);
  p=p->next;
 }
 DeleteQueue(&Q,&i);
 root->adjvex=i;
 DeleteQueue(&Q,&j);
 CreateTimeTree(root,i,j,&Q,arcs); 
 for(n=0;n<=(*(*(arcs+i)+j)).last;n++)
 {time1[0]=0;
  time1[1]=0;
  time2[0]=root->child[n]->begintime[0];
  time2[1]=root->child[n]->begintime[1];
  time[0]=INFINITY;
  time[1]=INFINITY;
  VisitTimeTree(root->child[n]);
  if(time[0]<TTime[0]||(time[0]==TTime[0]&&time[1]<TTime[1]))
  {TTime[0]=time[0];
   TTime[1]=time[1];
   p=head->next;
   while(p!=NULL)
   {p->route=d[p->adjvex];
    p=p->next;
   }
  }
 }
 DestoryTimeTree(root);
}
CreateTimeTree(TimeTree p,int i,int j,LinkQueue *Q,infolist (*arcs)[MAX_VERTEX_NUM])
/*
  创建时间树
*/
{int n,x,y;
 TimeTree q,r;
 q=(TimeNode *)malloc(sizeof(TimeNode));
 q->adjvex=j;
 q->begintime[0]=(*(*(arcs+i)+j)).stata[0].begintime[0];
 q->begintime[1]=(*(*(arcs+i)+j)).stata[0].begintime[1];
 q->arrivetime[0]=(*(*(arcs+i)+j)).stata[0].arrivetime[0];
 q->arrivetime[1]=(*(*(arcs+i)+j)).stata[0].arrivetime[1];
 q->route=0;
 p->child[0]=q;
 for(n=1;n<=(*(*(arcs+i)+j)).last;n++)
 {q=(TimeNode *)malloc(sizeof(TimeNode));
  q->adjvex=j;
  q->begintime[0]=(*(*(arcs+i)+j)).stata[n].begintime[0];
  q->begintime[1]=(*(*(arcs+i)+j)).stata[n].begintime[1];
  q->arrivetime[0]=(*(*(arcs+i)+j)).stata[n].arrivetime[0];
  q->arrivetime[1]=(*(*(arcs+i)+j)).stata[n].arrivetime[1];
  q->route=n;
  p->child[n]=q;
 }
 while(n<MAX_ROUTE_NUM)
 {p->child[n]=NULL;
  n++;
 }
 x=j;
 if(!IsEmpty(Q))
 {DeleteQueue(Q,&y);
  CreateTimeTree(p->child[0],x,y,Q,arcs);
  for(n=1;n<=(*(*(arcs+i)+j)).last;n++)
   CopyTimeTree(p->child[n],p->child[0]);
 }
 else
 {for(n=0;n<MAX_ROUTE_NUM;n++)
   p->child[0]->child[n]=NULL;
  for(n=1;n<=(*(*(arcs+i)+j)).last;n++)
   CopyTimeTree(p->child[n],p->child[0]);
 }
}
CopyTimeTree(TimeTree p,TimeTree q)
/*
  复制时间树
*/
{TimeTree r;
 int n=0;
 while(q->child[n]!=NULL)
 {r=(TimeNode *)malloc(sizeof(TimeNode));
  r->adjvex=q->child[n]->adjvex;
  r->begintime[0]=q->child[n]->begintime[0];
  r->begintime[1]=q->child[n]->begintime[1];
  r->arrivetime[0]=q->child[n]->arrivetime[0];
  r->arrivetime[1]=q->child[n]->arrivetime[1];
  r->route=q->child[n]->route;
  p->child[n]=r;
  CopyTimeTree(p->child[n],q->child[n]);
  n++;
 }
 while(n<MAX_ROUTE_NUM)
 {p->child[n]=NULL;
  n++;
 }
}
VisitTimeTree(TimeTree p)
/*
  访问时间树界面
*/
{int n,x[2],y[2];
 TimeTree q;
 x[0]=time1[0];
 x[1]=time1[1];
 y[0]=time2[0];
 y[1]=time2[1];
 if(p->begintime[0]>time2[0]||(p->begintime[0]==time2[0]&&p->begintime[1]>=time2[1]))
 {time1[0]=time1[0]+p->begintime[0]-time2[0];
  time1[1]=time1[1]+p->begintime[1]-time2[1];
  if(time1[1]<0)
  {time1[1]=time1[1]+60;
   time1[0]--;
  }
  if(time1[1]>=60)
  {time1[1]=time1[1]-60;
   time1[0]++;
  }
 }
 else if(p->begintime[0]<time2[0]||(p->begintime[0]==time2[0]&&p->begintime[1]<time2[1]))
 {time1[0]=time1[0]+p->begintime[0]-time2[0]+24;
  time1[1]=time1[1]+p->begintime[1]-time2[1];
  if(time1[1]<0)
  {time1[1]=time1[1]+60;
   time1[0]--;
  }
  if(time1[1]>=60)
  {time1[1]=time1[1]-60;
   time1[0]++;
  }
 }
 if(p->arrivetime[0]>p->begintime[0]||(p->arrivetime[0]==p->begintime[0]&&p->arrivetime[1]>=p->begintime[1]))
 {time1[0]=time1[0]+p->arrivetime[0]-p->begintime[0];
  time1[1]=time1[1]+p->arrivetime[1]-p->begintime[1];
  if(time1[1]<0)
  {time1[1]=time1[1]+60;
   time1[0]--;
  }
  if(time1[1]>=60)
  {time1[1]=time1[1]-60;
   time1[0]++;
  }
 }
 else if(p->arrivetime[0]<p->begintime[0]||(p->arrivetime[0]==p->begintime[0]&&p->arrivetime[1]<p->begintime[1]))
 {time1[0]=time1[0]+p->arrivetime[0]-p->begintime[0]+24;
  time1[1]=time1[1]+p->arrivetime[1]-p->begintime[1];
  if(time1[1]<0)
  {time1[1]=time1[1]+60;
   time1[0]--;
  }
  if(time1[1]>=60)
  {time1[1]=time1[1]-60;
   time1[0]++;
  }
 }
 time2[0]=p->arrivetime[0];
 time2[1]=p->arrivetime[1];
 c[p->adjvex]=p->route;
 if(p->child[0]==NULL)
 {if(time1[0]<time[0]||(time1[0]==time[0]&&time1[1]<time[1]))
  {time[0]=time1[0];
   time[1]=time1[1];
   for(n=0;n<MAX_VERTEX_NUM;n++)
    d[n]=c[n];
  }
 }
 else
 {n=0;
  while(p->child[n]!=NULL)
  {VisitTimeTree(p->child[n]);
   n++;
  }
 }
 time1[0]=x[0];
 time1[1]=x[1];
 time2[0]=y[0];
 time2[1]=y[1];
}
DestoryTimeTree(TimeTree p)
/*
  销毁时间树
*/
{if(p!=NULL)
 {DestoryTimeTree(p->child[0]);
  DestoryTimeTree(p->child[1]);
  DestoryTimeTree(p->child[2]);
  DestoryTimeTree(p->child[3]);
  DestoryTimeTree(p->child[4]);
  p->child[0]=NULL;
  p->child[1]=NULL;
  p->child[2]=NULL;
  p->child[3]=NULL;
  p->child[4]=NULL;
  free(p);
 }
}
TimeDispose(int k,infolist (*arcs)[MAX_VERTEX_NUM],ALGraph G,int v0,int v1,int (*T)[2],int *final)
/*
  最少旅行时间处理
*/
{int v,w,i,route,m[2];
 Node *p,*q,*r,*s,*t;
 p=(Node *)malloc(G.vexnum*sizeof(Node));
 for(v=0;v<G.vexnum;v++)
 {*(final+v)=False;
  MinTime(*(*(arcs+v0)+v),*(T+v),&route);
  p[v].next=NULL;
  if(*(*(T+v)+0)<INFINITY&&*(*(T+v)+1)<INFINITY)
  {q=(Node *)malloc(sizeof(Node));
   s=(Node *)malloc(sizeof(Node));
   q->adjvex=v0;
   s->adjvex=v;
   s->route=route;
   p[v].next=q;
   q->next=s;
   s->next=NULL;
  }
 }
 *(*(T+v0)+0)=0;
 *(*(T+v0)+1)=0;
 *(final+v0)=True;
 for(i=1;i<G.vexnum;i++)
 {m[0]=INFINITY;
  m[1]=INFINITY;
  v=-1;
  for(w=0;w<G.vexnum;w++)
   if(*(final+w)==False)
    if(*(*(T+w)+0)<m[0]||(*(*(T+w)+0)==m[0]&&*(*(T+w)+1)<m[1]))
    {v=w;
     m[0]=*(*(T+w)+0);
	 m[1]=*(*(T+w)+1);
    }
  if(v==v1)
  {q=p[v].next;
   r=q->next;
   printf("\n旅行路线是:\n");
   while(r!=NULL)
   {if(k==1)
     printf("乘坐No.%d列车车次在%d:%d从%s到%s\n",(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].number,(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[0],(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[1],G.vertices[q->adjvex].cityname,G.vertices[r->adjvex].cityname);
    else
     printf("乘坐No.%d飞机航班在%d:%d从%s到%s\n",(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].number,(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[0],(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[1],G.vertices[q->adjvex].cityname,G.vertices[r->adjvex].cityname);
    q=r;
    r=r->next;
   }
   printf("最少旅行时间是%d:%d\n\n",m[0],m[1]);
   for(v=0;v<G.vexnum;v++)
   {q=p[v].next;
    while(q!=NULL)
    {s=q;
     q=q->next;
     free(s);
    }
    p[v].next=NULL;
   }
   free(p);
   return;
  }
  else if(v!=-1)
  {*(final+v)=True;
   for(w=0;w<G.vexnum;w++)
    if(*(final+w)==False&&(*(*(arcs+v)+w)).last>-1)
    {t=p[w].next;
     q=&p[w];
     s=p[v].next;
     while(s!=NULL)
     {r=(Node *)malloc(sizeof(Node));
      r->adjvex=s->adjvex;
      r->route=s->route;
      q->next=r;
      q=r;
      s=s->next;
     }
     r=(Node *)malloc(sizeof(Node));
     r->adjvex=w;
     r->route=route;
     r->next=NULL;
     q->next=r;
     TimeTreeDispose(&p[w],arcs);
     if(*(*(T+w)+0)>TTime[0]||(*(*(T+w)+0)==TTime[0]&&*(*(T+w)+1)>TTime[1]))
     {*(*(T+w)+0)=TTime[0];
	  *(*(T+w)+1)=TTime[1];
      while(t!=NULL)
      {q=t;
       t=t->next;
       free(q);
      }
     }
     else
     {q=p[w].next;
      while(q!=NULL)
      {r=q;
       q=q->next;
       free(r);
      }
      p[w].next=t;
     }
    }
  }
 }
 for(v=0;v<G.vexnum;v++)
 {q=p[v].next;
  while(q!=NULL)
  {s=q;
   q=q->next;
   free(s);
  }
  p[v].next=NULL;
 }
 free(p);
 if(k==1)
  printf("\n不存在列车车次从%s到%s\n\n",G.vertices[v0].cityname,G.vertices[v1].cityname);
 else
  printf("\n不存在飞机航班从%s到%s\n\n",G.vertices[v0].cityname,G.vertices[v1].cityname);
}
PrintGraph(ALGraph *G)
/*
  显示城市交通系统
*/
{int i,j,k;
 ArcNode *q;
 printf("\n请选择显示项目:\n");
 printf("0=显示城市\n1=显示飞机航班\n2=显示列车车次\n3=返回上一级菜单\n");
 printf("选择?");
 scanf("%d",&i);
 getchar();
 while(i!=3)
 {switch(i)
  {case 0:printf("\n城市:\n");
          for(j=0;j<G->vexnum;j++)
           printf("%s  ",G->vertices[j].cityname);
          printf("\n");
          break;
   case 1:printf("\n飞机航班:\n");
          for(j=0;j<G->vexnum;j++)
          {q=G->vertices[j].planefirstarc;
           while(q!=NULL)
           {printf("%s---->%s\n",G->vertices[j].cityname,G->vertices[q->adjvex].cityname);
            for(k=0;k<=q->info.last;k++)
             printf("     number:%d  expenditure:%5.2f begintime:%5.2f  arrivetime:%5.2f\n",q->info.stata[k].number,q->info.stata[k].expenditure,q->info.stata[k].begintime,q->info.stata[k].arrivetime);
            q=q->nextarc;
           }
          }
          break;
   case 2:printf("\n列车车次:\n");
          for(j=0;j<G->vexnum;j++)
          {q=G->vertices[j].trainfirstarc;
           while(q!=NULL)
           {printf("%s---->%s\n",G->vertices[j].cityname,G->vertices[q->adjvex].cityname);
            for(k=0;k<=q->info.last;k++)
             printf("    number:%d  expenditure:%5.2f begintime:%5.2f  arrivetime:%5.2f\n",q->info.stata[k].number,q->info.stata[k].expenditure,q->info.stata[k].begintime,q->info.stata[k].arrivetime);
            q=q->nextarc;
           }
          }
          break;
  }
  printf("\n请选择显示项目:\n");
  printf("0=显示城市\n1=显示飞机航班\n2=显示列车车次\n3=返回上一级菜单\n");
  printf("选择?");
  scanf("%d",&i);
  getchar();
 }
}
