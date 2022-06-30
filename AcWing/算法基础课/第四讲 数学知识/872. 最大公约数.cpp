/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/49986/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

872. 最大公约数

给定 n 对正整数 ai,bi，请你求出每对数的最大公约数。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个整数对 ai,bi。

输出格式
输出共 n 行，每行输出一个整数对的最大公约数。

数据范围
1≤n≤105,
1≤ai,bi≤2×109
输入样例：
2
3 6
4 6
输出样例：
3
2

*/

#include <iostream>
#include <algorithm>

using namespace std;


int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}


int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }

    return 0;
}
