/*    �ɦW:ch5_03.c    �\��:if�ԭz���m��     */

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
 printf("=======================\n");
 TotalPrice = OnePrice*Qty;
 if(Qty>=10)
 {
     TotalPrice=TotalPrice*0.9;
     printf("�ʶR10�i�H�W���E��\n");
 }
 printf("�`����%.0f��\n",TotalPrice);
 /*  system("pause");  */
}
