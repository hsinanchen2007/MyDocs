/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

/*

https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/

153. 寻找旋转排序数组中的最小值
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
 

示例 1：

输入：nums = [3,4,5,1,2]
输出：1
解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。

示例 2：

输入：nums = [4,5,6,7,0,1,2]
输出：0
解释：原数组为 [0,1,2,4,5,6,7] ，旋转 4 次得到输入数组。

示例 3：

输入：nums = [11,13,15,17]
输出：11
解释：原数组为 [11,13,15,17] ，旋转 4 次得到输入数组。
 

提示：

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums 中的所有整数 互不相同
nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转
通过次数302,541提交次数531,121

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.22, by Hsinan, also refer CyC2018/CS-Notes
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int middle = left + (right - left) / 2;

            // tricky point here
            if (nums[middle] <= nums[right]) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        return nums[right];
    }
};


class Solution99 {
public:
    // 2022.6.22, by Hsinan, well, this also passes!
    // although STL's sort() is O(nlogn)
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};


class Solution98 {
public:
    // 2022.6.22, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/0001-0500/0153-Find-Minimum-in-Rotated-Sorted-Array/cpp-0153/main.cpp
    int findMin(vector<int>& nums) {
        // this solution uses C++ STL's min_element() to find smallest one and return its pointer
        // so if the answer is asking the value, return this pointer with *
        // if the answer is asking the index, use std::distance(nums.begin(), result)
        // refer https://en.cppreference.com/w/cpp/algorithm/min_element
        return *min_element(nums.begin(), nums.end());
    }
};


class Solution97 {
public:
    // 2022.6. 22, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/0001-0500/0153-Find-Minimum-in-Rotated-Sorted-Array/cpp-0153/main2.cpp
    int findMin(vector<int>& nums) {
        // sanity check and special cases
        assert(nums.size() > 0);
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return min(nums[0], nums[1]);

        // binary search
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[l] <= nums[mid] && nums[mid] <= nums[r])
                return nums[l];
            if(nums[l] > nums[mid])
                l = l + 1, r = mid;
            else if(nums[r] < nums[mid])
                l = mid + 1;
            else
                assert(false);
        }
        return nums[l];
    }
};


class Solution96 {
public:
    // 2022.6.22, from https://www.guozet.me/leetcode/Leetcode-153-Find-Minimum-in-Rotated-Sorted-Array.html?h=Find%20Minimum%20in%20Rotated%20Sorted%20Array
    // solution 1, by binary search
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        if (nums[left] < nums[right]) return nums[0];

        while (left < right - 1) {
            int mid = left + (right - left) / 2;

            // If the mid value > left value, then move the right part search.
            if (nums[mid] > nums[left]) left = mid;
            else right = mid;
        }
        return min(nums[left], nums[right]);
    }
};


class Solution95 {
public:
    // 2022.6.22, from https://www.guozet.me/leetcode/Leetcode-153-Find-Minimum-in-Rotated-Sorted-Array.html?h=Find%20Minimum%20in%20Rotated%20Sorted%20Array
    // solution 2, by Divide and conquer
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }

private:
    int findMin(const vector<int>& num, int l, int r) {
        // Only 1 or 2 elements
        if (l + 1 >= r) return min(num[l], num[r]);

        // Sorted
        if (num[l] < num[r]) return num[l];

        int mid = l + (r - l) / 2;
        return min(findMin(num, l, mid - 1), findMin(num, mid, r));
    }
};


class Solution94 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/153.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array
    /*
        Use two pointers L and R to define the search range. Initially L = 0, R = N - 1.
        If there is only one element, then we don't need to search. So the while condition should be L < R instead of L <= R.
        Let M = (L + R) / 2. Since M might = L, we compare A[M] with A[R].
        If A[M] > A[R], the min point must be to the right of A[M], so we let L = M + 1.
        Otherwise, the min point must be to the left of A[M] including A[M], so we let R = M.
    */
    // OJ: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int findMin(vector<int>& A) {
        int L = 0, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (A[M] > A[R]) L = M + 1;
            else R = M;
        }
        return A[L];
    }
};


class Solution93 {
public:
    // 2022.7.25, from https://walkccc.me/LeetCode/problems/0153/
    // Time: O(logn)
    // Space: O(1)
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            const int m = (l + r) / 2;
            if (nums[m] < nums[r])
                r = m;
            else
                l = m + 1;
        }

        return nums[l];
    }
};


class Solution92 {
public:
    // 2022.7.25, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/find-minimum-in-rotated-sorted-array.cpp
    // Time:  O(logn)
    // Space: O(1)
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        // Find min left s.t. nums[left] < nums[left'].
        while (left < right && nums[left] >= nums[right]) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[left]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left];
    }
};


class Solution {
public:
    // 2022.7.25, from AcWing
    /*
        算法
        (二分) O(logn)O(logn)
        处理这种问题有个常用技巧：如果不想处理边界情况，比如当数组只有两三个数的时候，代码会出问题。我们可以在数组长度太短(这道题中我们判断数组长度小于5)时，
        直接暴力循环做；数组有一定长度时再用二分做。这样做并不会影响算法的时间复杂度，但会缩短写代码的时间。

        为了便于理解，我们将数组中的数画在二维坐标系中，横坐标表示数组下标，纵坐标表示数值，如下所示：

        我们会发现数组中最小值前面的数 nums[i]nums[i] 都满足：nums[i]≥nums[0]nums[i]≥nums[0]，其中 nums[n−1]nums[n−1] 是数组最后一个元素；而数组
        中最小值后面的数（包括最小值）都不满足这个条件。所以我们可以二分出最小值的位置。

        另外，不要忘记处理数组完全单调的特殊情况。

        时间复杂度分析：二分查找，所以时间复杂度是 O(logn)O(logn)。
    */
    // 作者：yxc
    // 链接：https://www.acwing.com/solution/content/247/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int findMin(vector<int>& nums) {
        if (nums.back() > nums[0]) return nums[0];
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] >= nums[0]) l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
};
// @lc code=end

