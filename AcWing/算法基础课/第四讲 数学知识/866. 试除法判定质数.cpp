/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/49970/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

866. 试除法判定质数

给定 n 个正整数 ai，判定每个数是否是质数。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个正整数 ai。

输出格式
共 n 行，其中第 i 行输出第 i 个正整数 ai 是否为质数，是则输出 Yes，否则输出 No。

数据范围
1≤n≤100,
1≤ai≤231−1
输入样例：
2
2
6
输出样例：
Yes
No

*/

#include <iostream>
#include <algorithm>

using namespace std;

bool is_prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        int x;
        cin >> x;
        if (is_prime(x)) puts("Yes");
        else puts("No");
    }

    return 0;
}

