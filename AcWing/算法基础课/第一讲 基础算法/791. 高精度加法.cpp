/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/39792/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

791. 高精度加法

给定两个正整数（不含前导  0 ），计算它们的和。

输入格式
共两行，每行包含一个整数。

输出格式
共一行，包含所求的和。

数据范围
1≤整数长度≤100000
输入样例：
12
23
输出样例：
35

*/

// 不圧位代码
#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size()) return add(B, A);

    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++ )
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(t);
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');

    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];
    cout << endl;

    return 0;
}


//压9位的代码
#include <iostream>
#include <vector>

using namespace std;

const int base = 1000000000;

vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size()) return add(B, A);

    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++ )
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % base);
        t /= base;
    }

    if (t) C.push_back(t);
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;

    for (int i = a.size() - 1, s = 0, j = 0, t = 1; i >= 0; i -- )
    {
        s += (a[i] - '0') * t;
        j ++, t *= 10;
        if (j == 9 || i == 0)
        {
            A.push_back(s);
            s = j = 0;
            t = 1;
        }
    }
    for (int i = b.size() - 1, s = 0, j = 0, t = 1; i >= 0; i -- )
    {
        s += (b[i] - '0') * t;
        j ++, t *= 10;
        if (j == 9 || i == 0)
        {
            B.push_back(s);
            s = j = 0;
            t = 1;
        }
    }

    auto C = add(A, B);

    cout << C.back();
    for (int i = C.size() - 2; i >= 0; i -- ) printf("%09d", C[i]);
    cout << endl;

    return 0;
}

