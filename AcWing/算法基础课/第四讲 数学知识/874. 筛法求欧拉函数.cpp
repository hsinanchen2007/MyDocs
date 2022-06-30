/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/49995/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

874. 筛法求欧拉函数

给定一个正整数 n，求 1∼n 中每个数的欧拉函数之和。

输入格式
共一行，包含一个整数 n。

输出格式
共一行，包含一个整数，表示 1∼n 中每个数的欧拉函数之和。

数据范围
1≤n≤106
输入样例：
6
输出样例：
12

*/

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1000010;


int primes[N], cnt;
int euler[N];
bool st[N];


void get_eulers(int n)
{
    euler[1] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i])
        {
            primes[cnt ++ ] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0)
            {
                euler[t] = euler[i] * primes[j];
                break;
            }
            euler[t] = euler[i] * (primes[j] - 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    get_eulers(n);

    LL res = 0;
    for (int i = 1; i <= n; i ++ ) res += euler[i];

    cout << res << endl;

    return 0;
}

