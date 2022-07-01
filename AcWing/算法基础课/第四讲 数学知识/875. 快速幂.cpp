/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/50237/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

875. 快速幂

给定 n 组 ai,bi,pi，对于每组数据，求出 abiimodpi 的值。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含三个整数 ai,bi,pi。

输出格式
对于每组数据，输出一个结果，表示 abiimodpi 的值。

每个结果占一行。

数据范围
1≤n≤100000,
1≤ai,bi,pi≤2×109
输入样例：
2
3 2 5
4 3 9
输出样例：
4
1

*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;


LL qmi(int a, int b, int p)
{
    LL res = 1 % p;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * (LL)a % p;
        b >>= 1;
    }
    return res;
}


int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        int a, b, p;
        scanf("%d%d%d", &a, &b, &p);
        printf("%lld\n", qmi(a, b, p));
    }

    return 0;
}

