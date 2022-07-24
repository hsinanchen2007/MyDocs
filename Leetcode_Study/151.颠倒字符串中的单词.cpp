/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 颠倒字符串中的单词
 */

/*

https://leetcode.cn/problems/reverse-words-in-a-string/

151. 颠倒字符串中的单词
给你一个字符串 s ，颠倒字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

 

示例 1：

输入：s = "the sky is blue"
输出："blue is sky the"

示例 2：

输入：s = "  hello world  "
输出："world hello"
解释：颠倒后的字符串中不能存在前导空格和尾随空格。

示例 3：

输入：s = "a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，颠倒后的字符串需要将单词间的空格减少到仅有一个。
 

提示：

1 <= s.length <= 104
s 包含英文大小写字母、数字和空格 ' '
s 中 至少存在一个 单词
 

进阶：如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1) 额外空间复杂度的 原地 解法。

通过次数277,763提交次数548,347

*/

// @lc code=start
class Solution {

private:
    // 2022.7.23, by https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.md
    // 版本一
    // 反转字符串s中左闭又闭的区间[start, end]
    void reverse1(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    // 移除冗余空格：使用双指针（快慢指针法）O(n)的算法
    void removeExtraSpaces1(string& s) {
        int slowIndex = 0, fastIndex = 0; // 定义快指针，慢指针
        // 去掉字符串前面的空格
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        for (; fastIndex < s.size(); fastIndex++) {
            // 去掉字符串中间部分的冗余空格
            if (fastIndex - 1 > 0
                    && s[fastIndex - 1] == s[fastIndex]
                    && s[fastIndex] == ' ') {
                continue;
            } else {
                s[slowIndex++] = s[fastIndex];
            }
        }
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') { // 去掉字符串末尾的空格
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex); // 重新设置字符串大小
        }
    }

public:
    string reverseWords5(string s) {
        removeExtraSpaces1(s); // 去掉冗余空格
        reverse1(s, 0, s.size() - 1); // 将字符串全部反转
        int start = 0; // 反转的单词在字符串里起始位置
        int end = 0; // 反转的单词在字符串里终止位置
        bool entry = false; // 标记枚举字符串的过程中是否已经进入了单词区间
        for (int i = 0; i < s.size(); i++) { // 开始反转单词
            if (!entry) {
                start = i; // 确定单词起始位置
                entry = true; // 进入单词区间
            }
            // 单词后面有空格的情况，空格就是分词符
            if (entry && s[i] == ' ' && s[i - 1] != ' ') {
                end = i - 1; // 确定单词终止位置
                entry = false; // 结束单词区间
                reverse1(s, start, end);
            }
            // 最后一个结尾单词之后没有空格的情况
            if (entry && (i == (s.size() - 1)) && s[i] != ' ' ) {
                end = i;// 确定单词终止位置
                entry = false; // 结束单词区间
                reverse1(s, start, end);
            }
        }
        return s;
    }
    // 当然这里的主函数reverseWords写的有一些冗余的，可以精简一些，精简之后的主函数为：
    /* 主函数简单写法
    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        for(int i = 0; i < s.size(); i++) {
            int j = i;
            // 查找单词间的空格，翻转单词
            while(j < s.size() && s[j] != ' ') j++;
            reverse(s, i, j - 1);
            i = j;
        }
        return s;
    }
    */

private:
    //版本二：
    //原理同版本1，更简洁实现。
    void reverse2(string& s, int start, int end){ //翻转，区间写法：闭区间 []
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces2(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
        int slow = 0;   //整体思想参考Leetcode: 27. 移除元素：https://leetcode.cn/problems/remove-element/
        for (int i = 0; i < s.size(); ++i) { //
            if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
                if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); //slow的大小即为去除多余空格后的大小。
    }

public:
    string reverseWords4(string s) {
        removeExtraSpaces2(s); //去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
        reverse2(s, 0, s.size() - 1);
        int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
                reverse2(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
                start = i + 1; //更新下一个单词的开始下标start
            }
        }
        return s;
    }

public:
    // 2022.7.23, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/151.%20Reverse%20Words%20in%20a%20String
    void reverseWords3(string &s) {
        int i = 0, j = 0;
        while (j < s.size()) {
            while (j < s.size() && s[j] == ' ') ++j;
            if (i != 0 && j != s.size()) s[i++] = ' ';
            while (j < s.size() && s[j] != ' ') s[i++] = s[j++];
        }
        s.erase(i);
        i = j = 0;
        while (i < s.size()) {
            j = i;
            while (j < s.size() && s[j] != ' ') ++j;
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        reverse(s.begin(), s.end());
    }

private:
    void reverseWords(string& s, int n) {
        int i = 0;
        int j = 0;

        while (i < n) {
        while (i < j || i < n && s[i] == ' ')  // skip spaces
            ++i;
        while (j < i || j < n && s[j] != ' ')  // skip non spaces
            ++j;
        reverse(begin(s) + i, begin(s) + j);  // reverse the word
        }
    }

    // trim leading, trailing, and middle spaces
    string cleanSpaces(string& s, int n) {
        int i = 0;
        int j = 0;

        while (j < n) {
        while (j < n && s[j] == ' ')  // skip spaces
            ++j;
        while (j < n && s[j] != ' ')  // keep non spaces
            s[i++] = s[j++];
        while (j < n && s[j] == ' ')  // skip spaces
            ++j;
        if (j < n)  // keep only one space
            s[i++] = ' ';
        }

        return s.substr(0, i);
    }

public:
    // 2022.7.23, from https://walkccc.me/LeetCode/problems/0151/
    string reverseWords2(string s) {
        reverse(begin(s), end(s));          // reverse the whole string
        reverseWords(s, s.length());        // reverse each word
        return cleanSpaces(s, s.length());  // clean up spaces
    }

public:
    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/reverse-words-in-a-string.cpp
    // note that the function return is changed from void to string below
    string reverseWords1(string &s) {
        // Reverse the whole string first.
        reverse(s.begin(), s.end());

        size_t begin = 0, end = 0, len = 0;
        while ((begin = s.find_first_not_of(" ", end)) != string::npos) {
            if ((end = s.find(" ", begin)) == string::npos) {
                end = s.length();
            }
            // Reverse each word in the string.
            reverse(s.begin() + begin, s.begin() + end);

            // Shift the word to avoid extra space.
            move(s.begin() + begin, s.begin() + end, s.begin() + len);
            len += end - begin;
            s[len++] = ' ';
        }
        s.resize(len ? len - 1 : 0);

        // Modified by Hsinan. LC changed the return from void to string of the given string now
        return s;
    }

    // 2022.7.23, from AcWing
    // 作者：yxc
    // 链接：https://www.acwing.com/solution/content/245/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    // 算法
    // (数组翻转) O(n)O(n)
    // 分两步操作：
    //
    //将字符串中的每个单词逆序，样例输入变为: "eht yks si eulb"；
    // 将整个字符串逆序，样例输入变为："blue is sky the"；
    // 时间复杂度分析：整个字符串总共扫描两遍，所以时间复杂度是 O(n)O(n)。
    //且每次翻转一个字符串时，可以用两个指针分别从两端往中间扫描，每次交换两个指针对应的字符，
    // 所以额外空间的复杂度是 O(1)O(1)。
    string reverseWords(string s) {
        int k = 0;
        for (int i = 0; i < s.size();)
        {
            int j = i;
            while (j < s.size() && s[j] == ' ') j ++ ;
            if (j == s.size()) break;
            i = j;
            while (j < s.size() && s[j] != ' ') j ++ ;
            reverse(s.begin() + i, s.begin() + j);
            if (k) s[k ++ ] = ' ';
            while (i < j) s[k ++ ] = s[i ++ ];
        }
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());

        return s;
    }

};
// @lc code=end

