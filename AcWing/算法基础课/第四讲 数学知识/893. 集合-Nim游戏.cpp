/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/53562/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

893. 集合-Nim游戏

给定 n 堆石子以及一个由 k 个不同正整数构成的数字集合 S。

现在有两位玩家轮流操作，每次操作可以从任意一堆石子中拿取石子，每次拿取的石子数量必须包含于集合 S，最后无法进行操作的人视为失败。

问如果两人都采用最优策略，先手是否必胜。

输入格式
第一行包含整数 k，表示数字集合 S 中数字的个数。

第二行包含 k 个整数，其中第 i 个整数表示数字集合 S 中的第 i 个数 si。

第三行包含整数 n。

第四行包含 n 个整数，其中第 i 个整数表示第 i 堆石子的数量 hi。

输出格式
如果先手方必胜，则输出 Yes。

否则，输出 No。

数据范围
1≤n,k≤100,
1≤si,hi≤10000
输入样例：
2
2 5
3
2 4 7
输出样例：
Yes

*/

#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int N = 110, M = 10010;

int n, m;
int s[N], f[M];


int sg(int x)
{
    if (f[x] != -1) return f[x];

    unordered_set<int> S;
    for (int i = 0; i < m; i ++ )
    {
        int sum = s[i];
        if (x >= sum) S.insert(sg(x - sum));
    }

    for (int i = 0; ; i ++ )
        if (!S.count(i))
            return f[x] = i;
}


int main()
{
    cin >> m;
    for (int i = 0; i < m; i ++ ) cin >> s[i];
    cin >> n;

    memset(f, -1, sizeof f);

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        res ^= sg(x);
    }

    if (res) puts("Yes");
    else puts("No");

    return 0;
}

