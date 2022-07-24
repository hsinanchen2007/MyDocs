/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

/*

https://leetcode.cn/problems/repeated-substring-pattern/

459. 重复的子字符串
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

 
示例 1:

输入: s = "abab"
输出: true
解释: 可由子串 "ab" 重复两次构成。

示例 2:

输入: s = "aba"
输出: false

示例 3:

输入: s = "abcabcabcabc"
输出: true
解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
 

提示：

1 <= s.length <= 104
s 由小写英文字母组成
通过次数127,491提交次数250,299

*/

// @lc code=start
class Solution {
public:

    // 2022.7.23, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0459.%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.md
    // 这里使用了前缀表统一减一的实现方式
    void getNext2 (int* next, const string& s){
        next[0] = -1;
        int j = -1;
        for(int i = 1;i < s.size(); i++){
            while(j >= 0 && s[i] != s[j+1]) {
                j = next[j];
            }
            if(s[i] == s[j+1]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern9 (string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        getNext2(next, s);
        int len = s.size();
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {
            return true;
        }
        return false;
    }

    // 前缀表（不减一）的C++代码实现
    void getNext1 (int* next, const string& s){
        next[0] = 0;
        int j = 0;
        for(int i = 1;i < s.size(); i++){
            while(j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if(s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern8 (string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        getNext1(next, s);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - (next[len - 1] )) == 0) {
            return true;
        }
        return false;
    }

    // 2022.7.23, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/459.%20Repeated%20Substring%20Pattern
    // Solution 1. Brute force
    bool repeatedSubstringPattern7(string s) {
        int N = s.size();
        for (int len = 1; len <= N / 2; ++len) {
            if (N % len) continue;
            int i = len;
            for (; i < N; ++i) {
                if (s[i] != s[i % len]) break;
            }
            if (i == N) return true;
        }
        return false;
    }

    // Solution 2. Brute force with string_view
    bool repeatedSubstringPattern6(string s) {
        string_view p = s, sv = s;
        for (int len = s.size() / 2; len >= 1; --len) {
            if (s.size() % len) continue;
            p = p.substr(0, len);
            int i = s.size() / len - 1;
            for (; i >= 0 && p == sv.substr(i * len, len); --i);
            if (i < 0) return true;
        }
        return false;
    }

    // Solution 3. KMP
    bool repeatedSubstringPattern5(string s) {
        int N = s.size(), j = -1;
        vector<int> lps(N + 1, -1);
        for (int i = 1; i <= N; ++i) {
            while (j >= 0 && s[i - 1] != s[j]) j = lps[j];
            lps[i] = ++j;
        }
        return lps[N] && (lps[N] % (N - lps[N])) == 0;
    }

    // 2022.7.23, from https://walkccc.me/LeetCode/problems/0459/
    bool repeatedSubstringPattern4(string s) {
        const string ss = s + s;
        return ss.substr(1, ss.length() - 2).find(s) != string::npos;
    }

    // 2022.7.23, from https://www.guozet.me/leetcode/Leetcode-459-Repeated-Substring-Pattern.html?h=repeated
    // 给定一个字符串，问其是否有n个重复的子串组成。如果字符串的长度是len，那么我们在0-n/2之间进行判断，是否是字符串。
    // 如果子字符串的长度不能被len整除，那么这肯定不是可以重复N次组建成给定字符串的子字符串
    // 如果能够被字符串长度len整除，那么就使用整除得到的数值n，进行n次子字符串重复，重复完成之后，判断是否和输入的字符串相等， 
    // 如果相等，那就返回true，如果不相等，那就是false
    bool repeatedSubstringPattern3(string s) {
      int len = s.size();
      for(int i = 0; i < len/2; ++i) {
        if(len % (i+1) == 0) {
          int count = len / (i+1);
          string res = "";
          for(int j = 0; j < count; ++j) {
            res += s.substr(0, i+1);
          }
          if(res == s) return true;
        }
      }
      return false;
    }

    // 2022.7.23, from https://github.com/MaskRay/LeetCode/blob/master/repeated-substring-pattern.cc
    bool repeatedSubstringPattern2(string str) {
        vector<int> pi(str.size());
        for (int j = 0, i = 1; i < str.size(); i++) {
        while (j && str[i] != str[j]) j = pi[j-1];
        if (str[i] == str[j]) j++;
        pi[i] = j;
        }
        return pi.back() && str.size()%(str.size()-pi.back()) == 0;
    }

    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/repeated-substring-pattern.cpp
private:
    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }

public:
    bool repeatedSubstringPattern1(string str) {
        vector<int> prefix = getPrefix(str);
        return prefix.back() != -1 &&
               (prefix.back() + 1) % (str.length() - prefix.back() - 1) == 0;
    }

    // 2022.7.23, from AcWing
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/555694/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<int> next(n + 1);
        for (int i = 2, j = 0; i <= n; i ++ ) {
            while (j && s[i] != s[j + 1]) j = next[j];
            if (s[i] == s[j + 1]) j ++ ;
            next[i] = j;
        }
        int t = n - next[n];
        return t < n && n % t == 0;
    }

};
// @lc code=end

