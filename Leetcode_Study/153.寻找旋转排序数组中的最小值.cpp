/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:

    // 2022.6.22, by Hsinan, also refer CyC2018/CS-Notes
    int findMin5(vector<int>& nums) {
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

    // 2022.6.22, by Hsinan, well, this also passes!
    // although STL's sort() is O(nlogn)
    int findMin4(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[0];
    }

    // 2022.6.22, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/0001-0500/0153-Find-Minimum-in-Rotated-Sorted-Array/cpp-0153/main.cpp
    int findMin3(vector<int>& nums) {
        // this solution uses C++ STL's min_element() to find smallest one and return its pointer
        // so if the answer is asking the value, return this pointer with *
        // if the answer is asking the index, use std::distance(nums.begin(), result)
        // refer https://en.cppreference.com/w/cpp/algorithm/min_element
        return *min_element(nums.begin(), nums.end());
    }

    // 2022.6. 22, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/0001-0500/0153-Find-Minimum-in-Rotated-Sorted-Array/cpp-0153/main2.cpp
    int findMin2(vector<int>& nums) {
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

    // 2022.6.22, from https://www.guozet.me/leetcode/Leetcode-153-Find-Minimum-in-Rotated-Sorted-Array.html?h=Find%20Minimum%20in%20Rotated%20Sorted%20Array
    // solution 1, by binary search
    int findMin1(vector<int>& nums) {
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
// @lc code=end

