/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

/*

https://leetcode.cn/problems/4sum-ii/

454. 四数相加 II
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 

示例 1：

输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
输出：2
解释：
两个元组如下：
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

示例 2：

输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
输出：1
 

提示：

n == nums1.length
n == nums2.length
n == nums3.length
n == nums4.length
1 <= n <= 200
-228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228
通过次数135,173提交次数213,796

*/

// @lc code=start
class Solution {
public:

    // 2022.7.23, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0454.%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0II.md
    int fourSumCount4(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> umap; //key:a+b的数值，value:a+b数值出现的次数
        // 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中
        for (int a : A) {
            for (int b : B) {
                umap[a + b]++;
            }
        }
        int count = 0; // 统计a+b+c+d = 0 出现的次数
        // 在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就把map中key对应的value也就是出现次数统计出来。
        for (int c : C) {
            for (int d : D) {
                if (umap.find(0 - (c + d)) != umap.end()) {
                    count += umap[0 - (c + d)];
                }
            }
        }
        return count;
    }

    // 2022.7.23, from https://walkccc.me/LeetCode/problems/0454/
    int fourSumCount3(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        unordered_map<int, int> count;

        for (const int a : nums1)
            for (const int b : nums2)
                ++count[a + b];

        for (const int c : nums3)
            for (const int d : nums4)
                if (count.count(-c - d))
                    ans += count[-c - d];

        return ans;
    }

    // 2022.7.23, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/0001-0500/0454-4Sum-II/cpp-0454/main2.cpp
    int fourSumCount2(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

        unordered_map<int,int> hashtable1;
        unordered_map<int,int> hashtable2;

        for(int i = 0 ; i < A.size() ; i ++)
            for(int j = 0 ; j < B.size() ; j ++)
                hashtable1[A[i]+B[j]] += 1;

        for(int i = 0 ; i < C.size() ; i ++)
            for(int j = 0 ; j < D.size() ; j ++)
                hashtable2[C[i]+D[j]] += 1;

        int res = 0;
        for(unordered_map<int,int>::iterator iter = hashtable1.begin() ; iter != hashtable1.end() ; iter ++)
            if(hashtable2.find(-(iter->first)) != hashtable2.end())
                res += iter->second * hashtable2[-(iter->first)];

        return res;
    }

    // 2022.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/4sum-ii.cpp
    int fourSumCount1(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> A_B_sum;
        for (const auto& a : A) {
            for (const auto& b : B) {
                ++A_B_sum[a + b];
            }
        }
        int result = 0;
        for (const auto& c : C) {
            for (const auto& d : D) {
                if (A_B_sum.find(-c - d) != A_B_sum.end()) {
                    result += A_B_sum[-c - d];
                }
            }
        }
        return result;
    }

    // 2022.7.23, from AcWing
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/547030/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> cnt;
        for (auto c: C)
            for (auto d: D)
                cnt[c + d] ++ ;
        int res = 0;
        for (auto a: A)
            for (auto b: B)
                res += cnt[-(a + b)];
        return res;
    }

};
// @lc code=end

