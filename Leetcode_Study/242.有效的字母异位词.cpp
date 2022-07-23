/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

/*

https://leetcode.cn/problems/valid-anagram/

242. 有效的字母异位词
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

 

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
 

提示:

1 <= s.length, t.length <= 5 * 104
s 和 t 仅包含小写字母
 

进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

通过次数457,684提交次数698,332

*/

// @lc code=start
class Solution {
public:

    // 2022.7.23, by Hsinan, reference https://github.com/lzl124631x/LeetCode/tree/master/leetcode/242.%20Valid%20Anagram
    bool isAnagram4(string s, string t) {
        // quick sanity check, if the size is already different, they musy be different
        if (s.size() != t.size()) return false;

        // question already says only 仅包含小写字母
        // use cnt, one ++, another --, and the end, they should be all 0, 
        // otherwise that means some differences in two strings
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        for (char c : t) cnt[c - 'a']--;

        // final check
        for (int n : cnt) {
            // difference
            if (n) return false;
        }
        return true;
    }

    // 2022.7.23, from https://walkccc.me/LeetCode/problems/0242/
    // different size is handled at the beginning
    // if any different happened from 2nd string, it will be < 0 value 
    // as it didn't show up in 1st string
    bool isAnagram3(string s, string t) {
        if (s.length() != t.length())
        return false;

        vector<int> count(128);

        for (const char c : s)
        ++count[c];

        for (const char c : t)
        if (--count[c] < 0)
            return false;

        return true;
    }

    // 2022.7.23, from 程序员吴师兄
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 有效的字母异位词（LeetCode 242）：https://leetcode.cn/problems/valid-anagram/
    bool isAnagram2(string s, string t) {
        // 如果两个字符串的长度都不一致，那么肯定是无法成为字母异位词的
        if(s.length() != t.length()){

            // 直接返回 false
            return false;

        }

        // 让 a - z 这 26 个字母对应的下标变成 0 - 25 方便存到数组中
        // 比如 a 对应的索引就是 0 
        // b 对应的索引就是 1
        vector<int> table(26, 0);

        // 从头到尾遍历字符串 s
        for( int i = 0 ; i < s.length() ; i++){

            // 把访问的字符转换为整数的形式
            // 比如访问字母 a，那么 -'a' 之后就是 0，就是 a 对应的索引为 0 
            int index = s[i] - 'a';

            // 那么意味着这个字母出现的频次需要加 1
            table[index]++;

        }

        for( int i = 0 ; i < t.length() ; i++){

            // 把访问的字符转换为整数的形式
            // 比如访问字母 a，那么 -'a' 之后就是 0，就是 a 对应的索引为 0 
            int index = t[i] - 'a';

            // 那么意味着这个字母出现的频次需要减 1 
            table[index]--;

            // 如果说发现这个字母出现的频次小于了 0 
            // 说明 t 中出现了 s 中不曾用的字母
            if(table[index] < 0){

                // 那就不是字母异位词
                return false;

            }

        }

        // 否则，说明是字母异位词
        return true;
    }

    // 2022.7.23, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0242.%E6%9C%89%E6%95%88%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.md
    bool isAnagram1(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
                return false;
            }
        }
        // record数组所有元素都为零0，说明字符串s和t是字母异位词
        return true;
    }

    // 2022.7.23, from AcWing https://www.acwing.com/activity/content/code/content/445280/
    // use C++ STL's build-in "==" to check the difference
    bool isAnagram(string s, string t) {
        unordered_map<char, int> a, b;
        for (auto c: s) a[c] ++ ;
        for (auto c: t) b[c] ++ ;
        return a == b;
    }

};
// @lc code=end

