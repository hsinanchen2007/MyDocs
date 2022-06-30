/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/49976/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

869. 试除法求约数

给定 n 个正整数 ai，对于每个整数 ai，请你按照从小到大的顺序输出它的所有约数。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个整数 ai。

输出格式
输出共 n 行，其中第 i 行输出第 i 个整数 ai 的所有约数。

数据范围
1≤n≤100,
2≤ai≤2×109
输入样例：
2
6
8
输出样例：
1 2 3 6 
1 2 4 8 

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);
        }
    sort(res.begin(), res.end());
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
        auto res = get_divisors(x);

        for (auto x : res) cout << x << ' ';
        cout << endl;
    }

    return 0;
}

