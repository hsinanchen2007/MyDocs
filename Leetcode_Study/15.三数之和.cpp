/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:

    // 2022.6.9, from https://leetcode-solution-leetcode-pp.gitbook.io/leetcode-solution/medium/15.3sum
    vector<vector<int>> threeSum2(vector<int>& nums) {
        // tricky one, the returned vector is vector<vector<int>>, three
        // numbers, not two numbers
        vector<vector<int>> answer;

        // return if nums < 3
        if (nums.size() < 3) return answer;

        // sort the vector first so we can pick one target number i, and use
        // two pointers to start from j (target + 1) and k (nums.size()-1),
        //   if i + j + k > 0, k--, because k side is larger number
        //   if i + j + k < 0, j++, because j side is smaller number
        sort(nums.begin(), nums.end());
        
        // why nums.size() -2 here? for example below has 10 numbers
        //   { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
        // the last iteration from i is at index of number 8, which is 
        // nums.size() - 2, index 7. If we go to index 8, which is number 9,
        // two pointers can only hold same number 10
        // however, we should be able to handle this without -2 below
        //
        // tested below code by -1, not -2, it also works as j and k will 
        // perforn the range check. To make code easier to read and maintain,
        // I would prefer the code with -1, not -2
        for (int i = 0; i < nums.size() - 1; ++i) {
            // need this check to filter out duplicated ones
            // since the question didn't say the numbers in vector are unique,
            // they can be same number, but what we want is all solutions of 
            // different numbers
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // define two pointers j and k, j moves from left to right,
            // and k moves from right to left
            int j = i + 1;
            int k = nums.size() - 1;

            // stop condition of j and k
            while (j < k) {
                // check sum value now
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    // a way to push_back three numers into vector in one line code
                    answer.push_back({nums[i], nums[j], nums[k]});
                }

                // below "=" are very important, as above condition didn't update j and k index
                // we need below two "<=" and ">=" conditions to update j and k accordingly
                // otherwise it will cause hang in the while loop
                if (sum <= 0) {
                    // +1 first, then copmpare the nums value with previous one, j - 1
                    ++j;
                    while (j < k && nums[j] == nums[j - 1]) ++j;
                }
                if (sum >= 0) {
                    --k;
                    // -1 first, then compare the nums value with previous one, k + 1
                    while (j < k && nums[k] == nums[k + 1]) --k;
                }
            }
        }

        return answer;
    }

    // 2022.6.10, from AcWing https://www.acwing.com/video/1332/
    vector<vector<int>> threeSum1(vector<int>& nums) {
        // define return answer
        vector<vector<int>> answer;

        // sort the given vector as two pointers need a sorted array
        sort(nums.begin(), nums.end());

        // iteration, i as fixed one, j and k are moving forward/backward
        for (int i = 0; i < nums.size(); i++) {
            // if i is not 0 (first one) and next is same, skip
            if (i && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
                // if j is not i + 1 (first one) and next is same, skip
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // key condition, why (j < k -1) here? because if j = k -1, 
                // we only need to check nums[i] + nums[j] + nums[k]
                // but if (j < k - 1) and the sum is >= 0, current k is still too big
                // so k--, and if the sum is still too big, keep k--,
                // until j/k condition or the sum < 0 
                while ((j < k - 1) && (nums[i] + nums[j] + nums[k - 1] >= 0)) k--;

                // if sum is 0, add this one into answer
                if (nums[i] + nums[j] + nums[k] == 0) {
                    answer.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }

        return answer;
    }

    // 2022.6.11, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/3sum.cpp
    class Solution {
    public:
        vector<vector<int>> threeSum(vector<int> &nums) {
            sort(begin(nums), end(nums));
            vector<vector<int>> result;
            for (int i = size(nums) - 1; i >= 2; --i) {
                if (i + 1 < size(nums) && nums[i] == nums[i + 1]) {
                    continue;
                }
                const auto& target = -nums[i];
                int left = 0, right = i - 1;
                while (left < right) {
                    if (nums[left] + nums[right] < target) {
                        ++left;
                    } else if (nums[left] + nums[right] > target) {
                        --right;
                    } else {
                        result.push_back({nums[left], nums[right], nums[i]});
                        ++left; --right;
                        while (left < right && nums[left] == nums[left - 1]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right + 1]) {
                            --right;
                        }
                    }
                }
            }
            return result;
        }
    };

};
// @lc code=end

