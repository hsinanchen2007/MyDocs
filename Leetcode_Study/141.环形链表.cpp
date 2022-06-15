/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

/*

https://leetcode.cn/problems/linked-list-cycle/

141. 环形链表
给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

如果链表中存在环 ，则返回 true 。 否则，返回 false 。

 

示例 1：



输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：



输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：



输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
 

提示：

链表中节点的数目范围是 [0, 104]
-105 <= Node.val <= 105
pos 为 -1 或者链表中的一个 有效索引 。
 

进阶：你能用 O(1)（即，常量）内存解决此问题吗？

通过次数756,467提交次数1,470,493

*/

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    // 2022.5.30, LG solution
    //   1. Use slow and fast pointers, starts from 1st and 2nd nodes
    //   2. If slow and fast are at same node, there is a cycle
    //   3. If slow and fast are at different nodes, no cycle yet, 
    //      so flow will go to next node, and fast will go to next next node
    //   4. Stop while loop when fast or fast->next is NULL, that means there
    //      is no cycle in this linked list
    bool hasCycle3(ListNode *head) {
        // nullptr head, no cycle
        if (head == NULL) {
            return false;
        }

        // define starting point from the beginning
        ListNode* slow = head;
        ListNode* fast = head->next;

        // if fast == nullptr or fast->next == nullptr, stop
        while (fast != NULL && fast->next != NULL) {
            if (fast == slow) {
                // detect cycle
                return true;
            } else {
                // slow will take 1 step, fast will take 2 steps
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        return false;
    }


    // 2022.5.30, soulmachine
    //   1. The solution eliminates such null head or sinle node check
    //      and put such check into while loop, so it will take care of 
    //      NULL head or single node condition
    //   2. The first thing into while loop is to set next node, then 
    //      check if slow and fast pointers are at same node or not
    bool hasCycle2(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        
        return false;
    }

    // 2022.6.5, from AcWing https://www.acwing.com/video/1513/
    bool hasCycle1(ListNode *head) {
        // if NULL head or no next, no loop for sure
        if (!head || !head->next) return false;

        // define slow and fast pointers, here it uses fast pointer
        // start from head->next, so there is no need to do above
        // next->next check
        auto s = head, f = head->next;
        
        while (f) {
            s = s->next, f = f->next;

            // if fast pointer reaches NULL pointer, end
            // it also prepares for next statement, which
            // will do f->next, in case of NULL pointer
            if (!f) return false;

            // here is tricky part, fast pointer will go next
            // but slow will not until next iteration
            f = f->next;

            // if fast and slow are same, cycle detected
            if (s == f) return true;
        }

        return false;
    }

    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/linked-list-cycle.cpp
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next, fast = fast->next->next;
            if (slow == fast) {  // There is a cycle.
                return true;
            }
        }
        return false;  // No cycle.
    }

};
// @lc code=end

