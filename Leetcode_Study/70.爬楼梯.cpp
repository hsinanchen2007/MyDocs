/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

/* 

https://leetcode.cn/problems/climbing-stairs/

70. 爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

 

示例 1：

输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶
示例 2：

输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
 

提示：

1 <= n <= 45
通过次数850,065提交次数1,582,173
请问您在哪类招聘中遇到此题？
贡献者
LeetCode
半年内半年 ~ 1年1年 ~ 2年
使用最小花费爬楼梯
简单
斐波那契数
简单
第 N 个泰波那契数
简单
To reach nth step, what could have been your previous steps? (Think about the step sizes)

*/

// @lc code=start
class Solution {
public:

    // 2022.6.4, 极客时间覃超算法训练營
    // This is like a fibonacci function
    //   Level 1 = f(0)
    //   Level 2 = f(1) + f(0)
    //   level 3 = f(2) + f(1)
    //   level 4 = f(3) + f(2)
    // Think about at level X, if we consider from level (X-1), it needs 
    // one step, from level (x-2), it needs one two-step or two one-step
    int climbStairs5(int n) {
        // define prev and cur, note that prev is 0 and cur is 1
        int prev = 0;
        int cur = 1;

        // starts from 1 and (i <= n)
        for (int i = 1; i <= n; i++) {
            int tmp = cur;
            cur = cur + prev;
            prev = tmp;
        }
        return cur;
    }

    // 2022.6.4, 极客时间覃超算法训练營
    // This is like a fibonacci function, use math function
    // Ideally, this can resolve all such issue but the math function 
    // is hard to remember and convert it to C++ code
    int climbStairs4(int n) {
        double s = sqrt(5);
        return floor((pow((1+s)/2, n+1) + pow((1-s)/2, n+1))/s + 0.5);
    }

    // 2022.6.4, Leetcode解題總結
    int climbStairs3(int n) {
        // initial corner cases
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;

        // define one/two/always steps
        int always = 0;
        int twoStep = 1;
        int oneStep = 2;

        // the idea is similar above, consider the level n will have
        // two solutions from level (n-1) and level (n-2), it can be
        // either take two oneStep, or one twoStep
        // this solution is easy to memorize, but it's also tricky
        for (int i = 2; i < n; i++) {
            always = oneStep + twoStep;
            twoStep = oneStep;
            oneStep = always;
        }

        return always;
    }

    // 2022.6.4, from AcWing https://www.acwing.com/video/1408/
    int climbStairs2(int n) {
        int a = 1, b = 1;

        // assume n = 4
        //   loop 1: n = 3, c = 2, a = 1, b = 2
        //   loop 2: n = 2, c = 3, a = 2, b = 3
        //   loop 3: n = 1, c = 5, a = 3, b = 5
        while (--n) {
            int c = a + b;
            a = b; 
            b = c;
        }
        return b;
    }

    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/climbing-stairs.cpp
public:
    int climbStairs1(int n) {
	    vector<vector<int>> T = {{1, 1},
                                 {1, 0}};
        return matrixMult({{1, 0}}, matrixExpo(T, n))[0][0];  // [a0, a(-1)] * T^n
    }

private:
    vector<vector<int>> matrixExpo(const vector<vector<int>>& A, int pow) {
        vector<vector<int>> result(A.size(), vector<int>(A.size()));
        vector<vector<int>> A_exp(A);
        for (int i = 0; i < A.size(); ++i) {
            result[i][i] = 1;
        }
        while (pow) {
            if (pow % 2 == 1) {
                result = matrixMult(result, A_exp);
            }
            A_exp = matrixMult(A_exp, A_exp);
            pow /= 2;
        }
        return result;
    }

    vector<vector<int>> matrixMult(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        vector<vector<int>> result(A.size(), vector<int>(B[0].size()));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B[0].size(); ++j) {
                int64_t entry = 0;
                for (int k = 0; k < B.size(); ++k) {
                    entry = (static_cast<int64_t>(A[i][k]) * B[k][j] + entry);
                }
                result[i][j] = static_cast<int>(entry);
            }
        }
        return result;
    }

public:
    int climbStairs(int n) {
        vector<int> steps(3, 0);
        steps[0] = 1;
        steps[1] = 1;
        for (int i = 2; i <= n; ++i) {
            steps[i % 3] = steps[(i - 1) % 3] + steps[(i - 2) % 3];
        }
        return steps[n % 3];
    }

};
// @lc code=end

