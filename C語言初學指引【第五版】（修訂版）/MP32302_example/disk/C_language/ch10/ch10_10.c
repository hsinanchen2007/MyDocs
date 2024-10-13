/*    檔名:ch10_10.c    功能:使用鏈結儲存二元樹並進行中序走訪    */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node
{
    char data;
    struct Node *left_child;
    struct Node *right_child;
};
typedef struct Node node;    /* 定義Node結構的別名為node */
typedef node *bt;            /* bt為指向node的指標型態別名 */


void inorder(bt ptr) /* 中序走訪 */
{
 /* prt一開始應該指向樹的根節點 */
  if(ptr)     /* 若ptr非NULL */
  {
    inorder(ptr->left_child);
    printf("%c",ptr->data);   
    inorder(ptr->right_child);
  }
}

bt GetNode()
{
 bt NewNode;
 NewNode=(bt) malloc(sizeof(node));
 if(NewNode==NULL)
 {
     printf("記憶體不足!");
     exit(1);
 }
 return  NewNode;
}

int main(void)
{
  bt N1,N2,N3,N4,N5,N6,N7,N8,N9;
  
  N1=GetNode();  N2=GetNode();  N3=GetNode();
  N4=GetNode();  N5=GetNode();  N6=GetNode();
  N7=GetNode();  N8=GetNode();  N9=GetNode();
  
  N1->left_child=N2;   N1->right_child=N3;   N1->data='+';
  N2->left_child=N4;   N2->right_child=N5;   N2->data='+';
  N3->left_child=N6;   N3->right_child=N7;   N3->data='*';
  N4->left_child=NULL; N4->right_child=NULL; N4->data='a';
  N5->left_child=N8;   N5->right_child=N9;   N5->data='*';
  N6->left_child=NULL; N6->right_child=NULL; N6->data='d';
  N7->left_child=NULL; N7->right_child=NULL; N7->data='e';  
  N8->left_child=NULL; N8->right_child=NULL; N8->data='b';
  N9->left_child=NULL; N9->right_child=NULL; N9->data='c';
  
  inorder(N1);
  
  /* system("pause"); */system("pause");
  return 0;
}
