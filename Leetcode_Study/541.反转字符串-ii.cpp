/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

/*

https://leetcode.cn/problems/reverse-string-ii/

541. 反转字符串 II
给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 

示例 1：

输入：s = "abcdefg", k = 2
输出："bacdfeg"

示例 2：

输入：s = "abcd", k = 2
输出："bacd"
 

提示：

1 <= s.length <= 104
s 仅由小写英文组成
1 <= k <= 104
通过次数129,772提交次数218,759

*/

// @lc code=start
class Solution {
public:

    // 2022.7.23, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.md
    string reverseStr5(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
            } else {
                // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }

    // 2022.7.23, from https://github.com/lzl124631x/LeetCode/blob/master/leetcode/541.%20Reverse%20String%20II/s1.cpp
    string reverseStr4(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k)
        reverse(s.begin() + i, s.begin() + min((int)s.size(), i + k));
        return s;
    }

    // 2022.7.23, from https://walkccc.me/LeetCode/problems/0541/
    string reverseStr3(string s, int k) {
        for (size_t i = 0; i < s.length(); i += 2 * k) {
        int l = i;
        int r = min(i + k - 1, s.length() - 1);
        while (l < r)
            swap(s[l++], s[r--]);
        }

        return s;
    }
  
    // 2022.7.23, from https://www.guozet.me/leetcode/Leetcode-541-Reverse-String-II.html?h=reverses
    string reverseStr2(string s, int k) {
        int n = s.size(), count = n/2;
        for (int i = 0; i < count; ++i) {
            if(i % 2 == 0) {
                if (i*k + k < n)
                    reverse(s.begin()+i*k, s.begin()+(i+1)*k);
                else
                    reverse(s.begin()+i*k, s.begin()+n);
            }
        }
        return s;
    }

    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/reverse-string-ii.cpp
    string reverseStr1(string s, int k) {
        for (int left = 0; left < s.size(); left += 2 * k) {
            for (int i = left, j = min(left + k - 1, static_cast<int>(s.size()) - 1);
                 i < j; ++i, --j) {
                swap(s[i], s[j]);
            }
        }
        return s;
    }

    // 2022.7.23, from AcWing https://www.acwing.com/activity/content/code/content/597655/
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += k * 2) {
            int l = i, r = min(i + k, (int)s.size());
            reverse(s.begin() + l, s.begin() + r);
        }
        return s;
    }

};
// @lc code=end

