/*    檔名:ch11_10.c    功能:讀取二進位檔圖檔資料   */

#include <stdlib.h>
#include <stdio.h>

FILE *fp;

/**************main**************/
void main(void)
{
 unsigned char title[54];
 int i,num;
 int filesize,value1,value2,value3,value4,low,high;
 
 if((fp = fopen("PG30009.bmp", "rb")) == NULL)
 {
   printf("檔案錯誤\n");
   exit(0);
  }

 num = fread(title,sizeof(unsigned char),54,fp);

 low=title[2]%16;
 high=(title[2]-low)/16;
 value1=high*16+low;
 
 low=title[3]%16;
 high=(title[3]-low)/16;
 value2=high*16*16*16+low*16*16;

 low=title[4]%16;
 high=(title[4]-low)/16;
 value3=high*16*16*16*16*16+low*16*16*16*16;
 
 low=title[5]%16;
 high=(title[5]-low)/16;
 value4=high*16*16*16*16*16*16*16+low*16*16*16*16*16*16;

 filesize=value1+value2+value3+value4;
 
 printf("檔案大小為%d個位元組\n",filesize);
 fclose(fp); 

 /* system("pause"); */system("pause");
}
