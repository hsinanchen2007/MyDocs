/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/49992/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

873. 欧拉函数

给定 n 个正整数 ai，请你求出每个数的欧拉函数。

欧拉函数的定义
1∼N 中与 N 互质的数的个数被称为欧拉函数，记为 ϕ(N)。
若在算数基本定理中，N=pa11pa22…pamm，则：
ϕ(N) = N×p1−1p1×p2−1p2×…×pm−1pm
输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个正整数 ai。

输出格式
输出共 n 行，每行输出一个正整数 ai 的欧拉函数。

数据范围
1≤n≤100,
1≤ai≤2×109
输入样例：
3
3
6
8
输出样例：
2
2
4

*/

#include <iostream>

using namespace std;


int phi(int x)
{
    int res = x;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) res = res / x * (x - 1);

    return res;
}


int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        int x;
        cin >> x;
        cout << phi(x) << endl;
    }

    return 0;
}

