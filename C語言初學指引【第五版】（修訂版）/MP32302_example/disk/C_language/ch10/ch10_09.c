/*    �ɦW:ch10_09.c    �\��:�ϥ��쵲��C�s��ֳz���X    */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node node;    /* �w�qNode���c���O�W��node */
typedef node *nodePointer;   /* nodePointer�����Ы��A�O�W */

nodePointer GetNode();
void ErrorExit();
nodePointer insertFirst(nodePointer L,int d);
nodePointer last(nodePointer  L);
nodePointer insertLast(nodePointer L,int d);

nodePointer GetNode()
{
 nodePointer NewNode;
 NewNode=(nodePointer) malloc(sizeof(node));
 if(NewNode==NULL)
 {
     printf("�O���餣��!");
     exit(1);
 }
 return  NewNode;
}

void ErrorExit()
{
  printf("error");
  exit(1);
}

nodePointer insertFirst(nodePointer L,int d)
{
  nodePointer n;
  n=GetNode();
  n->data=d;
  n->link=L;
  L=n;
  return L;
}

nodePointer insertLast(nodePointer L,int d)
{
   nodePointer n,LastNP;
   if(L==NULL)
     L=insertFirst(L,d);
   else
   {
     n=GetNode();
     LastNP=last(L);
     n->data=d;
     n->link=NULL;
     LastNP->link=n;
   }
   return L;
}

nodePointer last(nodePointer  L)
{
   nodePointer Trace;
   if (L==NULL) ErrorExit();
   Trace=L;
   while (Trace->link!=NULL)
       Trace=Trace->link;
   return Trace;
}

int main(void)
{
  nodePointer Balls=NULL,visit=NULL;
  
  Balls=insertLast(Balls,27);
  Balls=insertLast(Balls,13);
  Balls=insertLast(Balls,16);
  Balls=insertLast(Balls,32);
  Balls=insertLast(Balls,18);
  Balls=insertLast(Balls,25);
  Balls=insertLast(Balls,22);
  
  printf("�}���y�p�U(�̫�@�y���S�O��):\n");
  visit=Balls;
  while(visit!=NULL) 
  {
     printf("%d  ",visit->data);
     visit=visit->link;     
  }
  /* system("pause"); */system("pause");
  return 0;
}
