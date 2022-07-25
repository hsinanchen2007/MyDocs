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

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.4, from 极客时间覃超算法训练營
    // This is like a fibonacci function
    //   Level 1 = f(0)
    //   Level 2 = f(1) + f(0)
    //   level 3 = f(2) + f(1)
    //   level 4 = f(3) + f(2)
    // Think about at level X, if we consider from level (X-1), it needs 
    // one step, from level (x-2), it needs one two-step or two one-step
    int climbStairs6(int n) {
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
};


class Solution99 {
public:
    // 2022.6.4, from 极客时间覃超算法训练營
    // This is like a fibonacci function, use math function
    // Ideally, this can resolve all such issue but the math function 
    // is hard to remember and convert it to C++ code
    int climbStairs5(int n) {
        double s = sqrt(5);
        return floor((pow((1+s)/2, n+1) + pow((1-s)/2, n+1))/s + 0.5);
    }
};


class Solution98 {
public:
    // 2022.6.4, from Leetcode解題總結
    int climbStairs4(int n) {
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
};


class Solution97 {
public:
    // 2022.6.4, from AcWing https://www.acwing.com/video/1408/
    int climbStairs3(int n) {
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


class Solution96 {
public:
    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/climbing-stairs.cpp
    // Time:  O(logn)
    // Space: O(1)
    int climbStairs2(int n) {
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
};


class Solution95 {
public:
    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/climbing-stairs.cpp
    // Time:  O(n)
    // Space: O(1)
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


class Solution94 {
public:
    // 2022.6.14, from https://ke.algomooc.com/detail/v_628a513ce4b01c509ab3e30b/3?from=p_6243bcc1e4b04e8d90291891&type=8&parent_pro_id=p_628a35d3e4b0812e179cf4bc
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 爬楼梯(70)：https://leetcode.cn/problems/climbing-stairs/    
    int climbStairs(int n) {

        // 使用数组 dp 存储每一级台阶的爬法数量
        // 由于后面初始化 dp[1] 和 dp[2] 
        // 为了让当 n = 0 时不越界，保证 dp[1] 和 dp[2] 都有值
        // 所以 dp 的长度为 n + 2
        vector<int> dp( n + 2 , 0 );
        
        // 初始化 dp[1] 和 dp[2] 
        // 一级台阶只有一种爬法
        dp[1] = 1;

        // 二级台阶有两种爬法
        // 一种爬法是先爬 1 个台阶，再爬 1 个台阶
        // 一种爬法是爬 2 个台阶
        dp[2] = 2;

        // 从 3 开始循环至 n，计算 dp[3] 至 dp[n]
        for (int i = 3; i <= n; i++) {
            // 第 i 级台阶的结果 dp[i] 等于第 i-1 和 i-2 的结果之和
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // 最后返回 n 级台阶的结果
        return dp[n];

    }
};


class Solution93 {
public:
    // 2022.7.25, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0070.%E7%88%AC%E6%A5%BC%E6%A2%AF.md
    /*
        本题大家如果没有接触过的话，会感觉比较难，多举几个例子，就可以发现其规律。

        爬到第一层楼梯有一种方法，爬到二层楼梯有两种方法。
        那么第一层楼梯再跨两步就到第三层 ，第二层楼梯再跨一步就到第三层。
        所以到第三层楼梯的状态可以由第二层楼梯 和 到第一层楼梯状态推导出来，那么就可以想到动态规划了。

        我们来分析一下，动规五部曲：

        定义一个一维数组来记录不同楼层的状态

        确定dp数组以及下标的含义
        dp[i]： 爬到第i层楼梯，有dp[i]种方法

        确定递推公式
        如果可以推出dp[i]呢？

        从dp[i]的定义可以看出，dp[i] 可以有两个方向推出来。

        首先是dp[i - 1]，上i-1层楼梯，有dp[i - 1]种方法，那么再一步跳一个台阶不就是dp[i]了么。
        还有就是dp[i - 2]，上i-2层楼梯，有dp[i - 2]种方法，那么再一步跳两个台阶不就是dp[i]了么。
        那么dp[i]就是 dp[i - 1]与dp[i - 2]之和！
        所以dp[i] = dp[i - 1] + dp[i - 2] 。

        在推导dp[i]的时候，一定要时刻想着dp[i]的定义，否则容易跑偏。

        这体现出确定dp数组以及下标的含义的重要性！

        dp数组如何初始化
        在回顾一下dp[i]的定义：爬到第i层楼梯，有dp[i]中方法。

        那么i为0，dp[i]应该是多少呢，这个可以有很多解释，但都基本是直接奔着答案去解释的。

        例如强行安慰自己爬到第0层，也有一种方法，什么都不做也就是一种方法即：dp[0] = 1，相当于直接站在楼顶。
        但总有点牵强的成分。

        那还这么理解呢：我就认为跑到第0层，方法就是0啊，一步只能走一个台阶或者两个台阶，然而楼层是0，直接站楼顶上了，就是不用方法，dp[0]就应该是0.
        其实这么争论下去没有意义，大部分解释说dp[0]应该为1的理由其实是因为dp[0]=1的话在递推的过程中i从2开始遍历本题就能过，然后就往结果上靠去解释dp[0] = 1。
        从dp数组定义的角度上来说，dp[0] = 0 也能说得通。

        需要注意的是：题目中说了n是一个正整数，题目根本就没说n有为0的情况。
        所以本题其实就不应该讨论dp[0]的初始化！

        我相信dp[1] = 1，dp[2] = 2，这个初始化大家应该都没有争议的。

        所以我的原则是：不考虑dp[0]如果初始化，只初始化dp[1] = 1，dp[2] = 2，然后从i = 3开始递推，这样才符合dp[i]的定义。

        确定遍历顺序
        从递推公式dp[i] = dp[i - 1] + dp[i - 2];中可以看出，遍历顺序一定是从前向后遍历的

        举例推导dp数组
        举例当n为5的时候，dp table（dp数组）应该是这样的

        70.爬楼梯

        如果代码出问题了，就把dp table 打印出来，看看究竟是不是和自己推导的一样。

        此时大家应该发现了，这不就是斐波那契数列么！

        唯一的区别是，没有讨论dp[0]应该是什么，因为dp[0]在本题没有意义！

        以上五部分析完之后，C++代码如下：
    */
    int climbStairs(int n) {
        if (n <= 1) return n; // 因为下面直接对dp[2]操作了，防止空指针
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) { // 注意i是从3开始的
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};


class Solution92 {
public:
    // 2022.7.25, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0070.%E7%88%AC%E6%A5%BC%E6%A2%AF.md
    /*
        当然依然也可以，优化一下空间复杂度，代码如下：

        后面将讲解的很多动规的题目其实都是当前状态依赖前两个，或者前三个状态，都可以做空间上的优化，但我个人认为面试中能写出版本一就够了哈，清晰明了，如果面试官要求进一步优化空间的话，我们再去优化。
        因为版本一才能体现出动规的思想精髓，递推的状态变化。

        拓展
        这道题目还可以继续深化，就是一步一个台阶，两个台阶，三个台阶，直到 m个台阶，有多少种方法爬到n阶楼顶。

        这又有难度了，这其实是一个完全背包问题，但力扣上没有这种题目，所以后续我在讲解背包问题的时候，今天这道题还会拿从背包问题的角度上来再讲一遍。
        这里我先给出我的实现代码：

        class Solution {
        public:
            int climbStairs(int n) {
                vector<int> dp(n + 1, 0);
                dp[0] = 1;
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) { // 把m换成2，就可以AC爬楼梯这道题
                        if (i - j >= 0) dp[i] += dp[i - j];
                    }
                }
                return dp[n];
            }
        };

        代码中m表示最多可以爬m个台阶。
        以上代码不能运行哈，我主要是为了体现只要把m换成2，粘过去，就可以AC爬楼梯这道题，不信你就粘一下试试，哈哈。
        此时我就发现一个绝佳的大厂面试题，第一道题就是单纯的爬楼梯，然后看候选人的代码实现，如果把dp[0]的定义成1了，就可以发难了，为什么dp[0]一定要初始化为1，此时可能候选人就要强行给dp[0]应该是1找各种理由。
        那这就是一个考察点了，对dp[i]的定义理解的不深入。然后可以继续发难，如果一步一个台阶，两个台阶，三个台阶，直到 m个台阶，有多少种方法爬到n阶楼顶。这道题目leetcode上并没有原题，绝对是考察候选人
        算法能力的绝佳好题。

        这一连套问下来，候选人算法能力如何，面试官心里就有数了。

        其实大厂面试最喜欢问题的就是这种简单题，然后慢慢变化，在小细节上考察候选人。

        这道题目和动态规划：斐波那契数题目基本是一样的，但是会发现本题相比动态规划：斐波那契数难多了，为什么呢？
        关键是 动态规划：斐波那契数 题目描述就已经把动规五部曲里的递归公式和如何初始化都给出来了，剩下几部曲也自然而然的推出来了。

        而本题，就需要逐个分析了，大家现在应该初步感受出关于动态规划，你该了解这些！里给出的动规五部曲了。
        简单题是用来掌握方法论的，例如昨天斐波那契的题目够简单了吧，但昨天和今天可以使用一套方法分析出来的，这就是方法论！

        所以不要轻视简单题，那种凭感觉就刷过去了，其实和没掌握区别不大，只有掌握方法论并说清一二三，才能触类旁通，举一反三哈！
        就酱，循序渐进学算法，认准「代码随想录」！
    */
    int climbStairs(int n) {
        if (n <= 1) return n;
        int dp[3];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            int sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
};


class Solution {
public:
    // 2022.7.25, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0070.%E7%88%AC%E6%A5%BC%E6%A2%AF%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85%E7%89%88%E6%9C%AC.md
    /*
        这道题目 我们在动态规划：爬楼梯 中已经讲过一次了，原题其实是一道简单动规的题目。
        既然这么简单为什么还要讲呢，其实本题稍加改动就是一道面试好题。

        改为：一步一个台阶，两个台阶，三个台阶，.......，直到 m个台阶。问有多少种不同的方法可以爬到楼顶呢？
        1阶，2阶，.... m阶就是物品，楼顶就是背包。

        每一阶可以重复使用，例如跳了1阶，还可以继续跳1阶。
        问跳到楼顶有几种方法其实就是问装满背包有几种方法。
        此时大家应该发现这就是一个完全背包问题了！

        和昨天的题目动态规划：377. 组合总和 Ⅳ基本就是一道题了。

        动规五部曲分析如下：

        确定dp数组以及下标的含义
        dp[i]：爬到有i个台阶的楼顶，有dp[i]种方法。

        确定递推公式
        在动态规划：494.目标和 、 动态规划：518.零钱兑换II、动态规划：377. 组合总和 Ⅳ中我们都讲过了，求装满背包有几种方法，递推公式一般都是dp[i] += dp[i - nums[j]];

        本题呢，dp[i]有几种来源，dp[i - 1]，dp[i - 2]，dp[i - 3] 等等，即：dp[i - j]

        那么递推公式为：dp[i] += dp[i - j]

        dp数组如何初始化
        既然递归公式是 dp[i] += dp[i - j]，那么dp[0] 一定为1，dp[0]是递归中一切数值的基础所在，如果dp[0]是0的话，其他数值都是0了。

        下标非0的dp[i]初始化为0，因为dp[i]是靠dp[i-j]累计上来的，dp[i]本身为0这样才不会影响结果

        确定遍历顺序
        这是背包里求排列问题，即：1、2 步 和 2、1 步都是上三个台阶，但是这两种方法不一样！

        所以需将target放在外循环，将nums放在内循环。

        每一步可以走多次，这是完全背包，内循环需要从前向后遍历。

        举例来推导dp数组
        介于本题和动态规划：377. 组合总和 Ⅳ几乎是一样的，这里我就不再重复举例了。

        以上分析完毕，C++代码如下：
    */
    int climbStairs(int n) {
        // Added by Hsinan, for this LC 70
        int m = 2;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) { // 遍历背包
            for (int j = 1; j <= m; j++) { // 遍历物品
                if (i - j >= 0) dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

