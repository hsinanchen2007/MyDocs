/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

/*

https://leetcode.cn/problems/evaluate-reverse-polish-notation/

150. 逆波兰表达式求值
根据 逆波兰表示法，求表达式的值。

有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

注意 两个整数之间的除法只保留整数部分。

可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。


示例 1：

输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9

示例 2：

输入：tokens = ["4","13","5","/","+"]
输出：6
解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6

示例 3：

输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
输出：22
解释：该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 

提示：

1 <= tokens.length <= 104
tokens[i] 是一个算符（"+"、"-"、"*" 或 "/"），或是在范围 [-200, 200] 内的一个整数
 

逆波兰表达式：

逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。

平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
逆波兰表达式主要有以下两个优点：

去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中
通过次数203,926提交次数379,200

*/

// @lc code=start
class Solution {
public:

    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0150.%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC.md
    // 在上一篇文章中1047.删除字符串中的所有相邻重复项提到了 递归就是用栈来实现的。
    //
    // 所以栈与递归之间在某种程度上是可以转换的！ 这一点我们在后续讲解二叉树的时候，会更详细的讲解到。
    // 
    // 那么来看一下本题，其实逆波兰表达式相当于是二叉树中的后序遍历。 大家可以把运算符作为中间节点，按照后序遍历的规则画出一个二叉树。
    // 
    // 但我们没有必要从二叉树的角度去解决这个问题，只要知道逆波兰表达式是用后续遍历的方式把二叉树序列化了，就可以了。
    //
    // 在进一步看，本题中每一个子表达式要得出一个结果，然后拿这个结果再进行运算，那么这岂不就是一个相邻字符串消除的过程，和1047.删除字符串中的所有相邻重复项中的
    // 对对碰游戏是不是就非常像了。
    // 
    // 如动画所示： 150.逆波兰表达式求值
    // 
    // 相信看完动画大家应该知道，这和1047. 删除字符串中的所有相邻重复项是差不错的，只不过本题不要相邻元素做消除了，而是做运算！
    int evalRPN4(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num2 + num1);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        int result = st.top();
        st.pop(); // 把栈里最后一个元素弹出（其实不弹出也没事）
        return result;
    }

    // 2022.7.24, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/150.%20Evaluate%20Reverse%20Polish%20Notation
    int evalRPN3(vector<string>& A) {
        stack<int> s;
        for (auto &t : A) {
            if (isdigit(t.back())) {
                s.push(stoi(t));
            } else {
                int n = s.top();
                s.pop();
                switch (t[0]) {
                    case '+': s.top() += n; break;
                    case '-': s.top() -= n; break;
                    case '*': s.top() *= n; break;
                    case '/': s.top() /= n; break;
                }
            }
        }
        return s.top();
    }

    // 2022.7.24, from https://walkccc.me/LeetCode/problems/0150/
    int evalRPN2(vector<string>& tokens) {
        stack<int> stack;
        const unordered_map<string, function<int(int, int)>> op{
            {"+", plus<int>()},
            {"-", minus<int>()},
            {"*", multiplies<int>()},
            {"/", divides<int>()}};

        for (const string& token : tokens)
            if (op.count(token)) {
                const int b = stack.top();
                stack.pop();
                const int a = stack.top();
                stack.pop();
                stack.push(op.at(token)(a, b));
            } else {
                stack.push(stoi(token));
            }

        return stack.top();
    }

    // 2022.7.24, from https://www.guozet.me/leetcode/Leetcode-150-Evaluate-Reverse-Polish-Notation.html?h=evaluate
    int evalRPN1(vector<string>& tokens) {
        stack<string> sta;
        for (auto token : tokens) {
        // If this is a number, then push it to the stack.
        if (!is_operator(token)) {
            sta.push(token);
        } else {
            int b = stoi(sta.top());
            sta.pop();
            int a = stoi(sta.top());
            sta.pop();
            if (token == "+")
            a += b;
            else if (token == "-")
            a -= b;
            else if (token == "*")
            a *= b;
            else
            a /= b;
            sta.push(to_string(a));
        }
        }
        return stoi(sta.top());
    }
    bool is_operator(const string& token) {
        return token.size() == 1 && string("+-*/").find(token) != string::npos; 
    }

    // 2022.7.24, from AcWing
    // 作者：yxc
    // 链接：https://www.acwing.com/solution/content/228/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    // 算法
    // (栈操作) O(n)O(n)
    // 遍历所有元素。如果当前元素是整数，则压入栈；如果是运算符，则将栈顶两个元素弹出做相应运算，再将结果入栈。
    // 最终表达式扫描完后，栈里的数就是结果。
    // 
    // 时间复杂度分析：每个元素仅被遍历一次，且每次遍历时仅涉及常数次操作，所以时间复杂度是 O(n)O(n)。
    int evalRPN(vector<string>& tokens) {
        stack<int> sta;
        for (auto &t : tokens)
            if (t == "+" || t == "-" || t == "*" || t == "/")
            {
                int a = sta.top();
                sta.pop();
                int b = sta.top();
                sta.pop();
                if (t == "+") sta.push(a + b);
                else if (t == "-") sta.push(b - a);
                else if (t == "*") sta.push(a * b);
                else sta.push(b / a);
            }
            else sta.push(atoi(t.c_str()));
        return sta.top();
    }

};
// @lc code=end

