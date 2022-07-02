/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/53407/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

889. 满足条件的01序列

给定 n 个 0 和 n 个 1，它们将按照某种顺序排成长度为 2n 的序列，求它们能排列成的所有序列中，能够满足任意前缀序列中 0 的个数都不少于 1 的个数的序列有多少个。

输出的答案对 109+7 取模。

输入格式
共一行，包含整数 n。

输出格式
共一行，包含一个整数，表示答案。

数据范围
1≤n≤105
输入样例：
3
输出样例：
5

*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010, mod = 1e9 + 7;


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
    int n;
    cin >> n;

    int a = n * 2, b = n;
    int res = 1;
    for (int i = a; i > a - b; i -- ) res = (LL)res * i % mod;

    for (int i = 1; i <= b; i ++ ) res = (LL)res * qmi(i, mod - 2, mod) % mod;

    res = (LL)res * qmi(n + 1, mod - 2, mod) % mod;

    cout << res << endl;

    return 0;
}

