#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
 int i;

 printf("���{���@������R�O�C%d�ӰѼ�\n",argc);
 for (i=0;i<=argc-1;i++)
    printf("argv[%d]�r�ꬰ%s\n",i,argv[i]);
 system("pause");
 return 1;
}
