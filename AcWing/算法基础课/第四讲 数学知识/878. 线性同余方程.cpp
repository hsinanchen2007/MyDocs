/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/50248/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

878. 线性同余方程

给定 n 组数据 ai,bi,mi，对于每组数求出一个 xi，使其满足 ai×xi≡bi(modmi)，如果无解则输出 impossible。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一组数据 ai,bi,mi。

输出格式
输出共 n 行，每组数据输出一个整数表示一个满足条件的 xi，如果无解则输出 impossible。

每组数据结果占一行，结果可能不唯一，输出任意一个满足条件的结果均可。

输出答案必须在 int 范围之内。

数据范围
1≤n≤105,
1≤ai,bi,mi≤2×109
输入样例：
2
2 3 6
4 3 5
输出样例：
impossible
-3

*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;


int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        int a, b, m;
        scanf("%d%d%d", &a, &b, &m);

        int x, y;
        int d = exgcd(a, m, x, y);
        if (b % d) puts("impossible");
        else printf("%d\n", (LL)b / d * x % m);
    }

    return 0;
}
