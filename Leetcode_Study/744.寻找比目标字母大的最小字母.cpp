/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

/*

https://leetcode.cn/problems/find-smallest-letter-greater-than-target/

744. 寻找比目标字母大的最小字母
给你一个排序后的字符列表 letters ，列表中只包含小写英文字母。另给出一个目标字母 target，请你寻找在这一有序列表里比目标字母大的最小字母。

在比较时，字母是依序循环出现的。举个例子：

如果目标字母 target = 'z' 并且字符列表为 letters = ['a', 'b']，则答案返回 'a'
 

示例 1：

输入: letters = ["c", "f", "j"]，target = "a"
输出: "c"

示例 2:

输入: letters = ["c","f","j"], target = "c"
输出: "f"

示例 3:

输入: letters = ["c","f","j"], target = "d"
输出: "f"
 

提示：

2 <= letters.length <= 104
letters[i] 是一个小写字母
letters 按非递减顺序排序
letters 最少包含两个不同的字母
target 是一个小写字母
通过次数91,201提交次数185,892

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.19, by Hsinan, use template first then adjust the code
    // refer CS-Notes/CyC2018
    // finalize with https://www.guozet.me/leetcode/Leetcode-744-Find-Smallest-Letter-Greater-Than-Target
    // Note that this question asked for the "NEXT" character of the target character in a sorted vector
    // so the consideration should be from left, not right, as once it existed while loop, right
    // pointer is actually at left pointer's left side, right pointer may actually point to target itself
    // but left pointer should be over target, which is the one "NEXT" we are looking for
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (letters[middle] > target) {
                right = middle - 1;
            } else if (letters[middle] < target) {
                left = middle + 1;
            } else {
                // if we do want to code with ""=="" condition here, need to update left
                // also, can NOT replace it with right! Why? "这一有序列表里比目标字母大的最小字母"
                // so if we do "right = middle -1", it may get the target character itself
                left = middle + 1;
            }
        }

        // refer from https://www.guozet.me/leetcode/Leetcode-744-Find-Smallest-Letter-Greater-Than-Target
        // so if the target is the last one, return letters[0] back
        int res = left % letters.size();

        return letters[res];
    }
};


class Solution99 {
public:
    // 2022.6.19, from https://www.guozet.me/leetcode/Leetcode-744-Find-Smallest-Letter-Greater-Than-Target
    // why should we do binary search?! This simply does what question asked for
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (const char c : letters)
            if (c > target) return c;
        return letters.front();
    }
};


class Solution98 {
public:
    // 2022.6.19, from https://www.guozet.me/leetcode/Leetcode-744-Find-Smallest-Letter-Greater-Than-Target
    // Binary Search Way
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size();
        while (left < right) {
            const int mid = left + (right - left) / 2;
            if (letters[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        int res = left % letters.size();
        return letters[res];
    }
};


class Solution {
public:
    // 2022.6.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/find-smallest-letter-greater-than-target.cpp
    // Again, it reminds that "range" question and can use C++ STL's lower_bound/upper_bound on a sorted vector
    char nextGreatestLetter(vector<char>& letters, char target) {
        const auto cit = upper_bound(letters.cbegin(), letters.cend(), target);
        return cit != letters.cend() ? *cit : letters.front();
    }
};


class Solution {
public:
    // 2022.6.19, from AcWing https://www.acwing.com/video/2638/
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        while (left < right) {
            int middle = left + right >> 1;
            if (letters[middle] > target) right = middle;
            else left = middle + 1;
        }
        if (letters[right] > target) return letters[right];
        return letters[0];
    }
};
// @lc code=end

