/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

/*

https://leetcode.cn/problems/koko-eating-bananas/

875. 爱吃香蕉的珂珂
珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 h 小时后回来。

珂珂可以决定她吃香蕉的速度 k （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 k 根。
如果这堆香蕉少于 k 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  

珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。


示例 1：

输入：piles = [3,6,7,11], h = 8
输出：4

示例 2：

输入：piles = [30,11,23,4,20], h = 5
输出：30

示例 3：

输入：piles = [30,11,23,4,20], h = 6
输出：23
 

提示：

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109
通过次数105,926提交次数209,154

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.31, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/875.%20Koko%20Eating%20Bananas
    /*
        Search a eating speed K between [1, P_max] where P_max is the max pile size. 
        The K should be the first (smallest) one requiring h (h <= H) hour to consume 
        all the bananas.
    */
    // OJ: https://leetcode.com/problems/koko-eating-bananas/
    // Author: github.com/lzl124631x
    // Time: O(P*log(P_max)) where P is count of piles, P_max is max pile size.
    // Space: O(K)
    int minEatingSpeed(vector<int>& A, int h) {
        long L = 1, R = *max_element(begin(A), end(A)), N = A.size();
        auto valid = [&](long k) {
            int i = 0, tmp = h; 
            for (; i < N && h > 0; ++i) {
                tmp -= (A[i] + k - 1) / k;
            }
            return i == N && tmp >= 0;
        };
        while (L <= R) {
            long M = (L + R) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};


class Solution99 {
public:
    // 2022.7.31, from https://walkccc.me/LeetCode/problems/0875/
    // Time: O(nlog(max(piles)))
    // Space: O(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(begin(piles), end(piles));

        while (l < r) {
            const int m = (l + r) / 2;
            if (eatHours(piles, m) <= h)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

private:
    // hours to eat all piles with speed m
    int eatHours(const vector<int>& piles, int m) {
        return accumulate(begin(piles), end(piles), 0, [&](int subtotal, int pile) {
            return subtotal + (pile - 1) / m + 1;  // ceil(pile / m)
        });
    }
};


class Solution98 {
public:
    // 2022.7.31, from https://www.guozet.me/leetcode/Leetcode-875-Koko-Eating-Bananas.html?h=ko
    /*
        Koko　吃香蕉的速度是 K , 吃香蕉的最大速度去所有香蕉堆里面的最大值就好，所以有left = 1, 
        right = *max_element(piles.begin(), piles.end()) + 1; 其中最右边的值是可以不选取的，
        为此我们计算按照这个取得的中间速度计算 kolo能不能在这个中间速度mid内吃完香蕉。如果吃完的时间
        花费小于限制的时间，那我们就减下吃香蕉的速度，反之就增加吃香蕉的速度。
    */
    // Time complexity: O(log max_speed), Space complexity: O(1)
    int minEatingSpeed(vector<int>& piles, int H) {
        // 1) [l, r) -- This is the range for the number of piles
        int left = 1, right = *max_element(piles.begin(), piles.end()) + 1;
        while (left < right) {
            int mid = left + (right - left) / 2, h = 0;
            for (int& pile : piles) h += (pile + mid - 1) / mid;
            h <= H ? right = mid : left = mid + 1;  // Can finished
        }
        return left;
    }
};


class Solution97 {
public:
    // 2022.7.31, from https://www.acwing.com/activity/content/code/content/1247031/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/1247031/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int get(vector<int>& piles, int mid) {
        int res = 0;
        for (auto x: piles)
            res += (x + mid - 1) / mid;
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = l + r >> 1;
            if (get(piles, mid) <= h) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};


class Solution96 {
public:
    // 2022.7.31, from https://github.com/grandyang/leetcode/issues/875
    /*
        这道题说有一只叫科科的猩猩，非常的喜欢吃香蕉，现在有N堆香蕉，每堆的个数可能不同，科科有H小时的时间来吃。
        要求是，每个小时内，科科只能选某一堆香蕉开始吃，若科科的吃速固定为K，即便在一小时内科科已经吃完了该堆的
        香蕉，也不能换堆，直到下一个小时才可以去另一堆吃。为了健康，科科想尽可能的吃慢一些，但同时也想在H小时内
        吃完所有的N堆香蕉，让我们找出一个最小的吃速K值。那么首先来想，既然每个小时只能吃一堆，总共要在H小时内吃
        完N堆，那么H一定要大于等于N，不然一定没法吃完N堆，这个条件题目中给了，所以就不用再 check 了。我们想一
        下K的可能的取值范围，当H无穷大的时候，科科有充足的时间去吃，那么就可以每小时只吃一根，也可以吃完，所以K
        的最小取值是1。那么当H最小，等于N时，那么一个小时内必须吃完任意一堆，那么K值就应该是香蕉最多的那一堆的
        个数，题目中限定了不超过 1e9，这就是最大值。所以要求的K值的范围就是 [1, 1e9]，固定的范围内查找数字，
        当然，最暴力的方法就是一个一个的试，凭博主多年与 OJ 抗衡的经验来说，基本可以不用考虑的。那么二分查找法
        就是不二之选了，我们知道经典的二分查找法，是要求数组有序的，而这里香蕉个数数组又不一定是有序的。这是一个
        很好的观察，但是要弄清楚到底是什么应该是有序的，要查找的K是吃速，跟香蕉堆的个数并没有直接的关系，而K所在
        的数组其实应该是 [1, 1e9] 这个数组，其本身就是有序的，所以二分查找没有问题。实际上这是博主之前那篇总结帖 
        LeetCode Binary Search Summary 二分搜索法小结 中的第四类 - 用子函数当作判断关系。当求出了 mid 
        之后，需要统计用该速度吃完所有的香蕉堆所需要的时间，统计的方法就是遍历每堆的香蕉个数，然后算吃完该堆要的
        时间。比如 K=4，那么假如有3个香蕉，需要1个小时，有4香蕉，还是1个小时，有5个香蕉，就需要两个小时，如果将
        三种情况融合为一个式子呢，就是用吃速加上香蕉个数减去1，再除以吃速即可，即 (pile+mid-1)/mid，大家可以
        自行带数字检验，是没有问题的。算出需要的总时间后去跟H比较，若小于H，说明吃的速度慢了，需要加快速度，所以 
        left 更新为 mid+1，否则 right 更新为 mid，最后返回 right 即可，参见代码如下：
    */
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1, right = 1e9;
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0;
            for (int pile : piles) cnt += (pile + mid - 1) / mid;
            if (cnt > H) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};


class Solution {
public:
    // 2022.7.31, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/koko-eating-bananas.cpp
    // With a fix by Hsinan to pass latest LC
    // Time:  O(nlogr)
    // Space: O(1)
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1, right = *max_element(piles.cbegin(), piles.cend());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (possible(piles, H, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool possible(const vector<int>& piles, int H, int K) {
        // modified by Hsinan, need to change below to long long otherwise it will cause overflow
        long long time = 0;
        for (const auto& pile : piles) {
            time += (pile - 1) / K + 1;
        }
        return time <= H;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

