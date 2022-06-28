/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/49975/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

868. 筛质数

给定一个正整数 n，请你求出 1∼n 中质数的个数。

输入格式
共一行，包含整数 n。

输出格式
共一行，包含一个整数，表示 1∼n 中质数的个数。

数据范围
1≤n≤106
输入样例：
8
输出样例：
4

*/

// 朴素筛法
#include <iostream>
#include <algorithm>

using namespace std;

const int N= 1000010;

int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (st[i]) continue;
        primes[cnt ++ ] = i;
        for (int j = i + i; j <= n; j += i)
            st[j] = true;
    }
}

int main()
{
    int n;
    cin >> n;

    get_primes(n);

    cout << cnt << endl;

    return 0;
}


// 线性筛法
#include <iostream>
#include <algorithm>

using namespace std;

const int N= 1000010;

int primes[N], cnt;
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

int main()
{
    int n;
    cin >> n;

    get_primes(n);

    cout << cnt << endl;

    return 0;
}
