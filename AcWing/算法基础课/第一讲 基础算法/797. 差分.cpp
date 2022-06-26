/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/39799/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

797. 差分

输入一个长度为 n 的整数序列。

接下来输入 m 个操作，每个操作包含三个整数 l,r,c，表示将序列中 [l,r] 之间的每个数加上 c。

请你输出进行完所有操作后的序列。

输入格式
第一行包含两个整数 n 和 m。

第二行包含 n 个整数，表示整数序列。

接下来 m 行，每行包含三个整数 l，r，c，表示一个操作。

输出格式
共一行，包含 n 个整数，表示最终序列。

数据范围
1≤n,m≤100000,
1≤l≤r≤n,
−1000≤c≤1000,
−1000≤整数序列中元素的值≤1000
输入样例：
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1
输出样例：
3 4 5 3 4 2

*/

#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i ++ ) insert(i, i, a[i]);

    while (m -- )
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    for (int i = 1; i <= n; i ++ ) b[i] += b[i - 1];

    for (int i = 1; i <= n; i ++ ) printf("%d ", b[i]);

    return 0;
}

