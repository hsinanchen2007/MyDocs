/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
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
    int climbStairs3(int n) {
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
    int climbStairs2(int n) {
        double s = sqrt(5);
        return floor((pow((1+s)/2, n+1) + pow((1-s)/2, n+1))/s + 0.5);
    }

    // 2022.6.4, Leetcode解題總結
    int climbStairs1(int n) {
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
    int climbStairs(int n) {
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

};
// @lc code=end

