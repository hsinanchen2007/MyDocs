/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/49974/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

867. 分解质因数

给定 n 个正整数 ai，将每个数分解质因数，并按照质因数从小到大的顺序输出每个质因数的底数和指数。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个正整数 ai。

输出格式
对于每个正整数 ai，按照从小到大的顺序输出其分解质因数后，每个质因数的底数和指数，每个底数和指数占一行。

每个正整数的质因数全部输出完毕后，输出一个空行。

数据范围
1≤n≤100,
2≤ai≤2×109
输入样例：
2
6
8
输出样例：
2 1
3 1

2 3

*/

#include <iostream>
#include <algorithm>

using namespace std;

void divide(int x)
{
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0) x /= i, s ++ ;
            cout << i << ' ' << s << endl;
        }
    if (x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        int x;
        cin >> x;
        divide(x);
    }

    return 0;
}

