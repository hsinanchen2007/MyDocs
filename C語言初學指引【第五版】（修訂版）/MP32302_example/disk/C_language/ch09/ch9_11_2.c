/*    檔名:ch9_11_2.c    功能:~在變數宣告(多檔案示範)    */

void func1(void)
{
 extern int i;      /*  不可省略此行  */
 i++;	
}
