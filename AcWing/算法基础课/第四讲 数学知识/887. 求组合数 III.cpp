/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/53399/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

887. 求组合数 III

给定 n 组询问，每组询问给定三个整数 a,b,p，其中 p 是质数，请你输出 Cbamodp 的值。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一组 a,b,p。

输出格式
共 n 行，每行输出一个询问的解。

数据范围
1≤n≤20,
1≤b≤a≤1018,
1≤p≤105,

输入样例：
3
5 3 7
3 1 5
6 4 13
输出样例：
3
3
2

*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;


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


int C(int a, int b, int p)
{
    if (b > a) return 0;

    int res = 1;
    for (int i = 1, j = a; i <= b; i ++, j -- )
    {
        res = (LL)res * j % p;
        res = (LL)res * qmi(i, p - 2, p) % p;
    }
    return res;
}


int lucas(LL a, LL b, int p)
{
    if (a < p && b < p) return C(a, b, p);
    return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        LL a, b;
        int p;
        cin >> a >> b >> p;
        cout << lucas(a, b, p) << endl;
    }

    return 0;
}
