/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:

    // 2022.6.12, from AcWing https://www.acwing.com/video/1333/
    int threeSumClosest2(vector<int>& nums, int target) {
        // sort the given vector so we can use two pointers
        sort(nums.begin(), nums.end());

        // we want to save the smallest diff within res to return
        std::pair<int, int> res(INT_MAX, INT_MAX);

        // first iteration for i
        for (int i = 0; i < nums.size(); i++) {
            // second iteration for j and k
            // again, j starts from (i + 1)
            // again, k starts from (nums.size() -1)
            for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
                while (k - 1 > j && nums[i] + nums[j] + nums[k - 1] >= target) k--;

                // check current sum
                int sum = nums[i] + nums[j] + nums[k];

                // the answer is asking the sum of closest one, not diff
                // so below one's first will be its diff, and second will be sum
                // compare the initial res and get the smallest diff from pair
                res = std::min(res, std::make_pair(std::abs(sum - target), sum));

                // here, target is larger than sum
                if (k - 1 > j) {
                    sum = nums[i] + nums[j] + nums[k - 1];
                    res = std::min(res, std::make_pair(std::abs(target - sum), sum));
                }
            }
        }

        return res.second;
    }

    // 2022.6.12, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/3sum-closest.cpp
    int threeSumClosest1(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int result = 0, min_diff = numeric_limits<int>::max();
        for (int i = size(nums) - 1; i >= 2; --i) {
            if (i + 1 < size(nums) && nums[i] == nums[i + 1]) {
                continue;
            }
            int left = 0, right = i - 1;
            while (left < right) {
                const auto& total = nums[left] + nums[right] + nums[i];
                if (total < target) {
                    ++left;
                } else if (total > target) {
                    --right;
                } else {
                    return target;
                }
                if (abs(total - target) < min_diff) {
                    min_diff = abs(total - target);
                    result = total;
                }
            }
        }
        return result;
    }

    // 2022.6.12, https://www.guozet.me/leetcode/Leetcode-16-3Sum-Closest.html
    // the solution is better and easier to understand
    int threeSumClosest(vector<int>& nums, int target) {
        // initialize a closest value from first three elements
        int closest = nums[0] + nums[1] + nums[2];

        // initialize a diff based on closest and target 
        int diff = std::abs(closest - target);

        // sort the given vector so we can use two pointers
        sort(nums.begin(), nums.end());

        // iterate all elements
        for (int i = 0; i < nums.size() -2; i++) {
            // define two pointers
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                // get current sum and diff
                int sum = nums[i] + nums[left] + nums[right];
                int newDiff = std::abs(sum - target);

                // update sum and diff if needed
                if (newDiff < diff) {
                    diff = newDiff;
                    closest = sum;
                }

                // otherwise next one
                if (sum < target) { 
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closest;
    }

};
// @lc code=end

