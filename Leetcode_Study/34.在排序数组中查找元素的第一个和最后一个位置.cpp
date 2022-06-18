/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:

    // 2022.6.18, from https://programmercarl.com/0034.%E5%9C%A8%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E6%9F%A5%E6%89%BE%E5%85%83%E7%B4%A0%E7%9A%84%E7%AC%AC%E4%B8%80%E4%B8%AA%E5%92%8C%E6%9C%80%E5%90%8E%E4%B8%80%E4%B8%AA%E4%BD%8D%E7%BD%AE.html#%E6%80%9D%E8%B7%AF
    // this one looks like LC 704 or LC 35, but it is actually more complicated. We need to find out the left and right borders 
    // as the given vector may contain same value in different elements, although they are all sorted
    // Below code is a copy/paste with some additional comments!
    vector<int> searchRange3(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);

        // 情况一, it never enter border condition
        if (leftBorder == -2 || rightBorder == -2) return {-1, -1};

        // 情况三
        if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};

        // 情况二
        return {-1, -1};
    }

private:
     int getRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2; // 记录一下rightBorder没有被赋值的情况

        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle - 1;
            } else { // 寻找右边界，nums[middle] == target的时候更新left
                left = middle + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2; // 记录一下leftBorder没有被赋值的情况

        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] >= target) { // 寻找左边界，nums[middle] == target的时候更新right
                right = middle - 1;
                leftBorder = right;
            } else {
                left = middle + 1;
            }
        }
        return leftBorder;
    }

public:
    // 2022.6.18, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/find-first-and-last-position-of-element-in-sorted-array.cpp
    // it uses C++ STL's lower_bound and upper_bound, to get the min/max borders based on given target in given vector
    vector<int> searchRange2(vector<int>& nums, int target) {
        // get lower/upper borders, this is a good example to re-use existing C++ STL
        // that it can help to find out borders from a sorted vector based on target
        const auto start = lower_bound(cbegin(nums), cend(nums), target);
        const auto end = upper_bound(cbegin(nums), cend(nums), target);

        // if target is found in given vector, get its range
        if (start != cend(nums) && *start == target) {
            return {static_cast<int>(start - cbegin(nums)),
                    static_cast<int>(end - cbegin(nums) - 1)};
        }

        // else if target is not in the given vector, return {-1, -1}
        return {-1, -1};
    }

    // 2022.6.18, from https://www.guozet.me/leetcode/summary/2019-01-15-Algorithms-Binary-Search.html
    // need to add one extra sanity check before binary search
    vector<int> searchRange1(vector<int>& nums, int target) {
        // define the answer vector to return
        // it alreays says size 2 and initializs them as -1
        vector<int> res(2, -1);

        // sanity check added by Hsinan
        // when given vector is [] and tagget is 0, without this sanity check,
        // LC will fail when submitting the answer
        if (nums.size() == 0) return {-1, -1};

        // define two pointers
        int left = 0, right = nums.size() - 1;

        // Do the first Binary Search
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        if (nums[right] != target) return res;

        // update answer
        res[0] = right;

        // Do the second Binary Search
        right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        // update answer
        res[1] = left - 1;

        return res;
    }

    // 2022.6.18, from AcWing https://www.acwing.com/video/1357/
    vector<int> searchRange(vector<int>& nums, int target) {
        // sanity check
        if (nums.empty()) return {-1, -1};

        // define left and right pointers
        int left = 0, right = nums.size() -1;
        while (left < right) {
            int middle = left + right >> 1;
            if (nums[middle] >= target) right = middle;
            else left = middle + 1;
        }
        // if not found, that means there is no such target
        if (nums[right] != target) return {-1, -1};

        // similar to LC 35, right index here is the condition when left >= right
        // so right now here is the left border
        int L = right;

        // for second binary search to find the right border
        left = 0, right = nums.size() - 1;
        while (left < right) {
            int middle = left + right + 1 >> 1;
            if (nums[middle] <= target) left = middle;
            else right = middle - 1;
        }

        return {L, right};
    }

};
// @lc code=end

