/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/53517/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

891. Nim游戏

给定 n 堆石子，两位玩家轮流操作，每次操作可以从任意一堆石子中拿走任意数量的石子（可以拿完，但不能不拿），最后无法进行操作的人视为失败。

问如果两人都采用最优策略，先手是否必胜。

输入格式
第一行包含整数 n。

第二行包含 n 个数字，其中第 i 个数字表示第 i 堆石子的数量。

输出格式
如果先手方必胜，则输出 Yes。

否则，输出 No。

数据范围
1≤n≤105,
1≤每堆石子数≤109
输入样例：
2
2 3
输出样例：
Yes

*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;


int main()
{
    int n;
    scanf("%d", &n);

    int res = 0;
    while (n -- )
    {
        int x;
        scanf("%d", &x);
        res ^= x;
    }

    if (res) puts("Yes");
    else puts("No");

    return 0;
}

