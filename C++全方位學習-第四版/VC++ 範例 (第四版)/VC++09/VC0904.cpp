//檔案名稱：d:\VC++09\VC0904\VC0904.cpp
#include <iostream>
#include <cstring>	//插入字串標題檔
using namespace std;

int main(int argc, char** argv)
{
	char first[80], last[80], full[160] = "";
	cout << "請輸入英文名字 (first name)：";	//顯示訊息字串
	cin.getline(first, 80, '\n');	//取得名字字串
	cout << "請輸入英文姓氏 (last name) ：";	//顯示訊息字串
	cin.getline(last, 80, '\n');	//取得姓氏字串
	strcat_s(full, first);	//附加名字字串
	strcat_s(full, " ");	//附加空白字串
	strcat_s(full, last);	//附加姓氏字串
	cout << "您的全名為：" << full << endl;	//顯示全名字串
	return 0;
}
