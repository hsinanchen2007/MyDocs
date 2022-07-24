/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

/*

https://leetcode.cn/problems/sliding-window-maximum/

239. 滑动窗口最大值
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。


示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

示例 2：

输入：nums = [1], k = 1
输出：[1]
 

提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
通过次数326,163提交次数652,640

*/

// @lc code=start
class Solution {
public:

    // 2022.7.24, by Hsinan (Time Limit Exceeded)
    vector<int> maxSlidingWindow8(vector<int>& nums, int k) {
        // return for answer
        std::vector<int> answer;

        // starts from 0 to k-1, and ensure right's limit
        for (int left = 0, right = k -1; right < nums.size(); left++, right++) {
            int max = INT_MIN;
            for (int i = left; i <= right; i++) {
                max = std::max(max, nums[i]);
            }
            answer.push_back(max);
        }

        return answer;
    }

    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.md
    // 这是使用单调队列的经典题目。
    // 
    // 难点是如何求一个区间里的最大值呢？ （这好像是废话），暴力一下不就得了。
    // 
    // 暴力方法，遍历一遍的过程中每次从窗口中在找到最大的数值，这样很明显是的算法。
    //
    // 有的同学可能会想用一个大顶堆（优先级队列）来存放这个窗口里的k个数字，这样就可以知道最大的最大值是多少了， 但是问题是这个窗口是移动的，
    // 而大顶堆每次只能弹出最大值，我们无法移除其他数值，这样就造成大顶堆维护的不是滑动窗口里面的数值了。所以不能用大顶堆。
    // 
    // 此时我们需要一个队列，这个队列呢，放进去窗口里的元素，然后随着窗口的移动，队列也一进一出，每次移动之后，队列告诉我们里面的最大值是什么。
    //
    //这个队列应该长这个样子：
    // class MyQueue {
    // public:
    //   void pop(int value) {
    //   }
    //   void push(int value) {
    //   }
    //   int front() {
    //   return que.front();
    //   }
    // };
    //
    // 每次窗口移动的时候，调用que.pop(滑动窗口中移除元素的数值)，que.push(滑动窗口添加元素的数值)，然后que.front()就返回我们要的最大值。
    // 
    // 这么个队列香不香，要是有现成的这种数据结构是不是更香了！
    // 
    // 可惜了，没有！ 我们需要自己实现这么个队列。
    //
    // 然后在分析一下，队列里的元素一定是要排序的，而且要最大值放在出队口，要不然怎么知道最大值呢。
    //
    // 但如果把窗口里的元素都放进队列里，窗口移动的时候，队列需要弹出元素。
    //
    // 那么问题来了，已经排序之后的队列 怎么能把窗口要移除的元素（这个元素可不一定是最大值）弹出呢。
    // 
    // 大家此时应该陷入深思.....
    // 
    // 其实队列没有必要维护窗口里的所有元素，只需要维护有可能成为窗口里最大值的元素就可以了，同时保证队里里的元素数值是由大到小的。
    //
    // 那么这个维护元素单调递减的队列就叫做单调队列，即单调递减或单调递增的队列。C++中没有直接支持单调队列，需要我们自己来一个单调队列
    //
    // 不要以为实现的单调队列就是 对窗口里面的数进行排序，如果排序的话，那和优先级队列又有什么区别了呢。
    //
    // 来看一下单调队列如何维护队列里的元素。
    //
    // 动画如下：
    //
    // 239.滑动窗口最大值
    //
    // 对于窗口里的元素{2, 3, 5, 1 ,4}，单调队列里只维护{5, 4} 就够了，保持单调队列里单调递减，此时队列出口元素就是窗口里最大元素。
    //
    // 此时大家应该怀疑单调队列里维护着{5, 4} 怎么配合窗口经行滑动呢？
    // 
    // 设计单调队列的时候，pop，和push操作要保持如下规则：
    //
    // pop(value)：如果窗口移除的元素value等于单调队列的出口元素，那么队列弹出元素，否则不用任何操作
    // push(value)：如果push的元素value大于入口元素的数值，那么就将队列入口的元素弹出，直到push元素的数值小于等于队列入口元素的数值为止
    // 保持如上规则，每次窗口移动的时候，只要问que.front()就可以返回当前窗口的最大值。
    // 
    // 为了更直观的感受到单调队列的工作过程，以题目示例为例，输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3，动画如下：
    //
    // 239.滑动窗口最大值-2
    //
    // 那么我们用什么数据结构来实现这个单调队列呢？
    //
    // 使用deque最为合适，在文章栈与队列：来看看栈和队列不为人知的一面中，我们就提到了常用的queue在没有指定容器的情况下，deque就是默认底层容器。
    // 
    // 基于刚刚说过的单调队列pop和push的规则，代码不难实现，如下：
    //
    // class MyQueue { //单调队列（从大到小）
    // public:
    //    deque<int> que; // 使用deque来实现单调队列
    //    每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
    //    同时pop之前判断队列当前是否为空。
    //    void pop(int value) {
    //      if (!que.empty() && value == que.front()) {
    //          que.pop_front();
    //      }
    //    }
    //    如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
    //    这样就保持了队列里的数值是单调从大到小的了。
    //    void push(int value) {
    //      while (!que.empty() && value > que.back()) {
    //        que.pop_back();
    //      }
    //      que.push_back(value);
    //    }
    //    查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
    //    int front() {
    //      return que.front();
    //    }
    // };
    //
    // 这样我们就用deque实现了一个单调队列，接下来解决滑动窗口最大值的问题就很简单了，直接看代码吧。
private:
    class MyQueue { //单调队列（从大到小）
    public:
        deque<int> que; // 使用deque来实现单调队列
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);

        }
        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow7(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++) { // 先将前k的元素放进队列
            que.push(nums[i]);
        }
        result.push_back(que.front()); // result 记录前k的元素的最大值
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]); // 滑动窗口移除最前面元素
            que.push(nums[i]); // 滑动窗口前加入最后面的元素
            result.push_back(que.front()); // 记录对应的最大值
        }
        return result;
    }    

    // 2022.7.24, from 程序员吴师兄
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 滑动窗口最大值（ LeetCode 239 ）：https://leetcode-cn.com/problems/sliding-window-maximum/
public:
    vector<int> maxSlidingWindow6(vector<int>& nums, int k) {
        // 构建存储最大值的数组
        vector<int> res;

        if(nums.size() == 0 || k == 0) {
            return res;
        }

        // 构建双端队列
        deque<int> deque;

        // 一开始滑动窗口不包含 K 个元素，不是合格的滑动窗口
        for(int i = 0; i < k; i++) {
            // 在滑动过程中，维护好 deque，确保它是单调递减队列

            // 反复判断，如果队列不为空且当前考察元素大于等于队尾元素，则将队尾元素移除。
            // 直到考察元素可以放入到队列中
            while(!deque.empty() && deque.back() < nums[i]) {
                deque.pop_back();
            }
            // 考察元素可以放入到队列中
            deque.push_back(nums[i]);
        }
        // 这个时候，滑动窗口刚刚好有 k 个元素，是合格的滑动窗口，那么最大值就是队列中的队首元素
        res.push_back(deque.front());
        // 现在让滑动窗口滑动
        for(int i = k; i < nums.size(); i++) {
            // 滑动窗口已经装满了元素，向右移动会把窗口最左边的元素抛弃
            // i - k 为滑动窗口的最左边
            // 如果队列的队首元素和窗口最左边的元素相等，需要将队首元素抛出
            // 如果不写这个判断，会导致队列中会包含非当前窗口的元素
            // 比如窗口大小为 1，队列为 1 -1，此时窗口为 【 1 】,队列为 1，输出最大值 1，下一个窗口为 【 -1 】，准备移动的时候队列 1 和数组最左端元素一样，必须移除，否则队列中是 【 1，-1 】，输出的结果是 1，而 1 不在窗口 【 -1 】中
            if(deque.front() == nums[i - k]) {
                deque.pop_front();
            }
            // 反复判断，如果队列不为空且当前考察元素大于等于队尾元素，则将队尾元素移除。
            // 直到考察元素可以放入到队列中
            while(!deque.empty() && deque.back() < nums[i]) {
                deque.pop_back();
            }

            // 考察元素可以放入到队列中
            deque.push_back(nums[i]);
            // 此时，结果数组的值就是队列的队首元素
            res.push_back(deque.front());
        }
        // 最后返回 res
        return res;
    }

    // 2022.7.24, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/239.%20Sliding%20Window%20Maximum
    // Assume the array is [3, 1, 2, ...] and k = 3, popping 3 out of the window will result in max value update, 
    // but popping 1 won't. This means that we can just keep track of [3, 2], i.e. a monotonically decreasing sequence of values.
    //
    // Here we store the index of the monotonoically decreasing sequence. When a new value A[i] is added to the window, 
    // we pop the trailing index in the deque which are pointing to values that are smaller or equal to A[i]. Then we can 
    // push i into the deque.
    //
    // We need to pop the index which falls out of the window from the deque as well.
    vector<int> maxSlidingWindow5(vector<int>& A, int k) {
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < A.size(); ++i) {
            if (q.size() && q.front() == i - k) q.pop_front();
            while (q.size() && A[q.back()] <= A[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) ans.push_back(A[q.front()]);
        }
        return ans;
    }

    // Similar to Solution 1, but here we store the values instead of the indexes in the deque.
    vector<int> maxSlidingWindow4(vector<int>& A, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < A.size(); ++i) {
            if (i >= k && q.size() && q.front() == A[i - k]) q.pop_front();
            while (q.size() && q.back() < A[i]) q.pop_back();
            q.push_back(A[i]);
            if (i >= k - 1) ans.push_back(q.front());
        }
        return ans;
    }

    // 2022.7.24, from https://walkccc.me/LeetCode/problems/0239/
    vector<int> maxSlidingWindow3(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;  // max queue

        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && q.back() < nums[i])
                q.pop_back();
            q.push_back(nums[i]);
            if (i >= k && nums[i - k] == q.front())  // out of bound
                q.pop_front();
            if (i >= k - 1)
                ans.push_back(q.front());
        }

        return ans;
    }

    // 2022.7.24, from https://github.com/MaskRay/LeetCode/blob/master/sliding-window-maximum.cc
    #define FOR(i, a, b) for (int i = (a); i < (b); i++)
    #define REP(i, n) FOR(i, 0, n)
    vector<int> maxSlidingWindow2(vector<int> &a, int k) {
        int n = (int)a.size();
        vector<int> b;
        deque<int> q;
        REP(i, n) {
        if (q.size() && q.front() <= i-k)
            q.pop_front();
        while (q.size() && a[q.back()] < a[i])
            q.pop_back();
        q.push_back(i);
        if (i >= k-1)
            b.push_back(a[q.front()]);
        }
        return b;
    }

    // 2022.7.24, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/sliding-window-maximum.cpp
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;
        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && i - dq.front() == k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.emplace_back(i);
            if (i >= k - 1) {
                result.emplace_back(nums[dq.front()]);
            }
        }
        return result;
    }

    // 2022.7.24, from AcWing
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/445221/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); i ++ ) {
            if (q.size() && i - k + 1 > q.front()) q.pop_front();
            while (q.size() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }

};
// @lc code=end

