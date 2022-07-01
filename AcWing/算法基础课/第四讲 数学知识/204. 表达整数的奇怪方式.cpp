/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/53307/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

204. 表达整数的奇怪方式

给定 2n 个整数 a1,a2,…,an 和 m1,m2,…,mn，求一个最小的非负整数 x，满足 ∀i∈[1,n],x≡mi(mod ai)。

输入格式
第 1 行包含整数 n。

第 2…n+1 行：每 i+1 行包含两个整数 ai 和 mi，数之间用空格隔开。

输出格式
输出最小非负整数 x，如果 x 不存在，则输出 −1。
如果存在 x，则数据保证 x 一定在 64 位整数范围内。

数据范围
1≤ai≤231−1,
0≤mi<ai
1≤n≤25
输入样例：
2
8 7
11 9
输出样例：
31

*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;


LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }

    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


int main()
{
    int n;
    cin >> n;

    LL x = 0, m1, a1;
    cin >> m1 >> a1;
    for (int i = 0; i < n - 1; i ++ )
    {
        LL m2, a2;
        cin >> m2 >> a2;
        LL k1, k2;
        LL d = exgcd(m1, m2, k1, k2);
        if ((a2 - a1) % d)
        {
            x = -1;
            break;
        }

        k1 *= (a2 - a1) / d;
        k1 = (k1 % (m2/d) + m2/d) % (m2/d);

        x = k1 * m1 + a1;

        LL m = abs(m1 / d * m2);
        a1 = k1 * m1 + a1;
        m1 = m;
    }

    if (x != -1) x = (a1 % m1 + m1) % m1;

    cout << x << endl;

    return 0;
}
