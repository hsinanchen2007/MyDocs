/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/53401/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

888. 求组合数 IV

输入 a,b，求 Cba 的值。

注意结果可能很大，需要使用高精度计算。

输入格式
共一行，包含两个整数 a 和 b。

输出格式
共一行，输出 Cba 的值。

数据范围
1≤b≤a≤5000
输入样例：
5 3
输出样例：
10

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


const int N = 5010;

int primes[N], cnt;
int sum[N];
bool st[N];


void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}


int get(int n, int p)
{
    int res = 0;
    while (n)
    {
        res += n / p;
        n /= p;
    }
    return res;
}


vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i ++ )
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}


int main()
{
    int a, b;
    cin >> a >> b;

    get_primes(a);

    for (int i = 0; i < cnt; i ++ )
    {
        int p = primes[i];
        sum[i] = get(a, p) - get(a - b, p) - get(b, p);
    }

    vector<int> res;
    res.push_back(1);

    for (int i = 0; i < cnt; i ++ )
        for (int j = 0; j < sum[i]; j ++ )
            res = mul(res, primes[i]);

    for (int i = res.size() - 1; i >= 0; i -- ) printf("%d", res[i]);
    puts("");

    return 0;
}

