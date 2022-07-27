/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

/*

https://leetcode.cn/problems/reverse-string/

344. 反转字符串
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。


示例 1：

输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]

示例 2：

输入：s = ["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
 

提示：

1 <= s.length <= 105
s[i] 都是 ASCII 码表中的可打印字符
通过次数579,167提交次数734,078

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.23, by Hsinan
    void reverseString(vector<char>& s) {
        // get size and sanity check
        int size = s.size();
        if (size <= 1) {
            return;
        }
        
        // use two pointers, from beginning and end
        int i = 0, j = size - 1;

        // reverse
        while (i <= j) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++, j--;
        }
        return;
    }
};


class Solution99 {
public:
    // 2022.7.23, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.md
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
            swap(s[i],s[j]);
        }
    }
};


class Solution98 {
public:
    // 2022.7.23, https://github.com/lzl124631x/LeetCode/tree/master/leetcode/344.%20Reverse%20String
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) swap(s[i++], s[j--]);
    }
};


class Solution97 {
public:
    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/reverse-string.cpp
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};


class Solution {
public:
    // 2022.7.23, from AcWing
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j; i ++, j -- )
            swap(s[i], s[j]);
    }
};
// @lc code=end

