/****  filename:pro5.c   �إߥؿ�  *****/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void)
{
   char *path="./newdir/";

   if(mkdir(path,00400|00200|00040))
      printf("Directory %s is not create!\n",path);
   else
      printf("Directory %s is create!\n",path);
}
