/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start

/*

https://leetcode.cn/problems/intersection-of-two-arrays/

349. 两个数组的交集
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]

示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
 

提示：

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
通过次数324,265提交次数436,336

*/

class Solution100 {
public:
    // 2022.7.23, by Hsinan
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // sanity check
        if (nums1.size() == 0 || nums2.size() == 0) {
            return {};
        }

        // hash table
        std::unordered_map <int, int> lookup;

        // answer vector to return
        std::vector<int> answer;

        for (int i : nums1) {
            // only add unique one in nums1
            if (lookup[i] == 0) lookup[i] = 1;
        }
        for (int j : nums2) {
            // only update 1 in nums2 if lookup has 1 from previous nums1
            if (lookup[j] == 1) lookup[j] = lookup[j] + 1;
        }
        for (auto k : lookup) {
            // when lookup second is 2, that means this number existed in
            // both nums1 and nums2, if second is 1, that means it only existed
            // in nums1
            if (k.second == 2) answer.push_back(k.first);
        }

        return answer;
    }
};


class Solution99 {
public:
    // 2022.7.23
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // https://leetcode-cn.com/problems/intersection-of-two-arrays/
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // 首先对两个数组进行排序
        sort(nums1.begin(), nums1.end());

        sort(nums2.begin(), nums2.end());
       

        // 计算出两个数组的长度
        int length1 = nums1.size();

        int length2 = nums2.size();
        
    
        // 两个数组的交集结果数组长度必然是小于等于最短数组的长度
        vector<int> res ;

        // 设置三个索引指针

        // index 指向结果数组 res ，每当 index 指向的位置填充了元素就向后移动
        // int index = 0;
        
        // index1 指向数组 nums1 中的元素，将该元素和 index2 指向数组 nums2 中的元素进行比较
        int index1 = 0;
        
        // index2 指向数组 nums2 中的元素，将该元素和 index1 指向数组 nums1 中的元素进行比较
        int index2 = 0;

        // 移动 index1 和 index2 
        while (index1 < length1 && index2 < length2) {
            
            // 获取 index1 指向的元素值
            int num1 = nums1[index1];
            
            // 获取 index2 指向的元素值
            int num2 = nums2[index2];

            // num1 和 num2 的大小关系有三种

            // 1、num1 == num2
            if (num1 == num2) {

                // 由于输出结果中的每个元素一定是 【唯一】 的，所以要做一下判断
                // 如果 res 中的 index 在起始位置，说明还没有存放元素
                // 那么这个相等的元素可以存放到 res 中

                // 如果 res 中的 index 不在起始位置
                // 当它前面存放的元素并不是现在想要存放的元素
                // 那么这个相等的元素可以存放到 res 中
                if ( !res.size() || num1 != res.back()) {

                    // 存放到 res 中
                    res.push_back(num1);
                   
                }

                // 移动 index1 ，比较其它元素
                index1++;
               
                // 移动 index2 ，比较其它元素
                index2++;

            // 2、num1 < num2
            } else if (num1 < num2) {
                
                // 由于两个数组已经排序了，说明此时 num1 肯定会小于 nums2 数组中 num2 后面所有的数
                // 那 num1 肯定是无法在 nums2 中找到相等的元素
                // 移动 index1 ，比较其它元素
                index1++;

            // 3、num1 > num2
            } else {

                // 由于两个数组已经排序了，说明此时 num2 肯定会小于 nums1 数组中 num1 后面所有的数
                // 那 num2 肯定是无法在 nums1 中找到相等的元素
                // 移动 index2 ，比较其它元素
                index2++;

            }
        }

        // 最后返回结果数组中有值的那些元素就行
        return res;

    }
};


class Solution98 {
public:
    // 2022.7.23, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.md
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        int hash[1005] = {0}; // 默认数值为0
        for (int num : nums1) { // nums1中出现的字母在hash数组中做记录
            hash[num] = 1;
        }
        for (int num : nums2) { // nums2中出现话，result记录
            if (hash[num] == 1) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};


class Solution97 {
public:
    // 2022.7.23, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/349.%20Intersection%20of%20Two%20Arrays
    vector<int> intersection(vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A));
        sort(begin(B), end(B));
        vector<int> ans;
        int i = 0, j = 0, M = A.size(), N = B.size();
        while (i < M && j < N) {
            if (A[i] < B[j]) ++i;
            else if (A[i] > B[j]) ++j;
            else {
                int n = A[i];
                while (i < M && A[i] == n) ++i;
                while (j < N && B[j] == n) ++j;
                ans.push_back(n);
            }
        }
        return ans;
    }
};


class Solution96 {
public:
    // 2022.7.23, from https://walkccc.me/LeetCode/problems/0349/
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> set{begin(nums1), end(nums1)};

        for (const int num : nums2)
        if (set.erase(num))
            ans.push_back(num);

        return ans;
    }
};


class Solution95 {
public:
    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/intersection-of-two-arrays.cpp
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(begin(nums1), end(nums1)); sort(begin(nums2), end(nums2));
        set_intersection(cbegin(nums1), cend(nums1), cbegin(nums2), cend(nums2), back_inserter(result));
        result.erase(unique(begin(result), end(result)), end(result));
        return result;
    }
};


class Solution94 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto it1 = nums1.cbegin(), it2 = nums2.cbegin();
        while (it1 != nums1.cend() && it2 != nums2.cend()) {
            if (*it1 < *it2) {
                ++it1;
            } else if (*it1 > *it2) {
                ++it2;
            } else {
                if (result.empty() || result.back() != *it1) {
                    result.emplace_back(*it1);
                }
                ++it1, ++it2;
            }
        }
        return result;
    }
};


class Solution93 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersection(nums2, nums1);
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        auto it = nums2.cbegin();
        for (const auto& i : nums1) {
            it = lower_bound(it, nums2.cend(), i);
            if (it != nums2.end() && *it == i) {
                result.emplace_back(*it);
                it = upper_bound(it, nums2.cend(), i);
            }
        }
        
        return result;
    }
};


class Solution92 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersection(nums2, nums1);
        }

        unordered_set<int> lookup{nums1.cbegin(), nums1.cend()};

        vector<int> result;
        for (const auto& i : nums2) {
            if (lookup.count(i)) {
                result.emplace_back(i);
                lookup.erase(i);
            }
        }

        return result;
    }
};


class Solution {
public:
    // 2022.7.23, from AcWing 
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/487556/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> S;
        for (auto x: nums1) S.insert(x);
        vector<int> res;
        for (auto x: nums2)
            if (S.count(x)) {
                res.push_back(x);
                S.erase(x);
            }
        return res;
    }
};
// @lc code=end

