class Solution {
public:
    int threeSumSmaller1(vector<int>& nums, int target) {
        // sanity check if nums didn't have enough numbers
        if (nums.size() < 3) return 0;
    
        // define return and sort vector first
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());

        // iterate from i
        for (int i = 0; i < n - 2; ++i) {
            // define two pointers
            int left = i + 1, right = n - 1;

            // when left < right
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < target) {
                    // tricky, use (right -left) to get all valid solutions
                    res += right - left;
                    ++left;
                } else {
                    // no valid solution here
                    --right;
                }
            }
        }

        return res;
    }

    // 2022.6.12, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/3sum-smaller.cpp
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();

        int count = 0;
        for (int k = 2; k < n; ++k) {
            int i = 0, j = k - 1;
            while (i < j) {  // Two Pointers, linear time.
                if (nums[i] + nums[j] + nums[k] >= target) {
                    --j;
                } else {
                    count += j - i;
                    ++i;
                }
            }
        }

        return count;
    }

};