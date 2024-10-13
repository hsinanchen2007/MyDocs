/*    �ɦW:ch7_24.c    �\��:�ϥΩR�O�C�ѼƨM�w�}�X���y��   */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int SeqSearch(int Target,int *arr,int arr_index);
void generate_lotto(int *spec_num,int *arr,int arr_index);

/**************�`�Ƿj�M**************/
int SeqSearch(int Target,int *arr,int arr_index)
{
 int i;
 
 for(i=0;i<arr_index;i++)
    if(Target == arr[i])     /*  ���F  */
       return i;
 return -1;                  /*  �����䤣��  */
}

/**************���ͼֳz���X**************/
void generate_lotto(int *spec_num,int *arr,int arr_index)
{
 int i,generate_num;
 srand((unsigned) time(NULL));

 for(i=0;i<arr_index;i++)
 {
    generate_num=rand()%49+1;
    while(SeqSearch(generate_num,arr,i+1)!=-1)  /*  �O�_����  */
    {
        generate_num=rand()%49+1;
    }
    arr[i]=generate_num;
 }
 generate_num=rand()%49+1;
 while(SeqSearch(generate_num,arr,i)!=-1)  /*  �S�O���O�_�P��L���X����  */
  {
     generate_num=rand()%49+1;
  }
  *spec_num=generate_num;
}

/**************main()**************/
void main(int argc,char *argv[])
{
 int lotto[49],i,special,ball_qty=6;

 if(argc>1)
 {
    ball_qty=atoi(argv[1]);
 }
 generate_lotto(&special,lotto,ball_qty);
   
 printf("�ֳz���X�p�U.....\n");
 for (i=0;i<ball_qty;i++)
 {
   if ((i%6==0)&&(i!=0))
       printf("\n");
   printf("%d\t",lotto[i]);
 }
 printf("\n");
 printf("�S�O��:%d\n",special);
 /*  system("pause");  */
}
