/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/49983/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

870. 约数个数

给定 n 个正整数 ai，请你输出这些数的乘积的约数个数，答案对 109+7 取模。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个整数 ai。

输出格式
输出一个整数，表示所给正整数的乘积的约数个数，答案需对 109+7 取模。

数据范围
1≤n≤100,
1≤ai≤2×109
输入样例：
3
2
6
8
输出样例：
12

*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 110, mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> primes;

    while (n -- )
    {
        int x;
        cin >> x;

        for (int i = 2; i <= x / i; i ++ )
            while (x % i == 0)
            {
                x /= i;
                primes[i] ++ ;
            }

        if (x > 1) primes[x] ++ ;
    }

    LL res = 1;
    for (auto p : primes) res = res * (p.second + 1) % mod;

    cout << res << endl;

    return 0;
}

