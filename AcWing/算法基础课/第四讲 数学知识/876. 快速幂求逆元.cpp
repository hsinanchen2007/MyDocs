/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/50238/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

876. 快速幂求逆元

给定 n 组 ai,pi，其中 pi 是质数，求 ai 模 pi 的乘法逆元，若逆元不存在则输出 impossible。

注意：请返回在 0∼p−1 之间的逆元。

乘法逆元的定义
若整数 b，m 互质，并且对于任意的整数 a，如果满足 b|a，则存在一个整数 x，使得 a/b≡a×x(modm)，则称 x 为 b 的模 m 乘法逆元，记为 b−1(modm)。
b 存在乘法逆元的充要条件是 b 与模数 m 互质。当模数 m 为质数时，bm−2 即为 b 的乘法逆元。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个数组 ai,pi，数据保证 pi 是质数。

输出格式
输出共 n 行，每组数据输出一个结果，每个结果占一行。

若 ai 模 pi 的乘法逆元存在，则输出一个整数，表示逆元，否则输出 impossible。

数据范围
1≤n≤105,
1≤ai,pi≤2∗109
输入样例：
3
4 3
8 5
6 3
输出样例：
1
2
impossible

*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;


LL qmi(int a, int b, int p)
{
    LL res = 1;
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
        int a, p;
        scanf("%d%d", &a, &p);
        if (a % p == 0) puts("impossible");
        else printf("%lld\n", qmi(a, p - 2, p));
    }

    return 0;
}
