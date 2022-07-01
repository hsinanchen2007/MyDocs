/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/53394/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

886. 求组合数 II

给定 n 组询问，每组询问给定两个整数 a，b，请你输出 Cbamod(109+7) 的值。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一组 a 和 b。

输出格式
共 n 行，每行输出一个询问的解。

数据范围
1≤n≤10000,
1≤b≤a≤105
输入样例：
3
3 1
5 3
2 2
输出样例：
3
10
1

*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010, mod = 1e9 + 7;


int fact[N], infact[N];


int qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}


int main()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i ++ )
    {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }


    int n;
    scanf("%d", &n);
    while (n -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", (LL)fact[a] * infact[b] % mod * infact[a - b] % mod);
    }

    return 0;
}
