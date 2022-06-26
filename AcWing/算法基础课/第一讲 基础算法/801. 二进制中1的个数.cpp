/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/40086/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

801. 二进制中1的个数

给定一个长度为 n 的数列，请你求出数列中每个数的二进制表示中 1 的个数。

输入格式
第一行包含整数 n。

第二行包含 n 个整数，表示整个数列。

输出格式
共一行，包含 n 个整数，其中的第 i 个数表示数列中的第 i 个数的二进制表示中 1 的个数。

数据范围
1≤n≤100000,
0≤数列中元素的值≤109
输入样例：
5
1 2 3 4 5
输出样例：
1 1 2 1 2

*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        int x, s = 0;
        scanf("%d", &x);

        for (int i = x; i; i -= i & -i) s ++ ;

        printf("%d ", s);
    }

    return 0;
}
