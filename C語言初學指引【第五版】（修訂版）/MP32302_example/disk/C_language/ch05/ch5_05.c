/*    �ɦW:ch5_05.c    �\��:if-else�ԭz���m��    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int OnePrice,Qty;
 float TotalPrice;
 OnePrice=200;
 printf("�C�i�J�������欰%d��\n",OnePrice);
 printf("�п�J�z�n�ʶR���i��:");
 scanf("%d",&Qty);
 printf("==========================\n");
 if(Qty>=10)
 {
     TotalPrice=OnePrice*Qty*0.9;
     printf("�ʶR10�i�H�W���E��\n");
 }
 else
 {
     TotalPrice=OnePrice*Qty;
     printf("�z���ʶR10�i�H�W���J����,��������\n");
 }
 printf("�`����%.0f��\n",TotalPrice);
 /*  system("pause");  */
}
