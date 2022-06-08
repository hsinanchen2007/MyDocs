/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

/*

https://leetcode.cn/problems/reverse-linked-list/

206. 反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 

示例 1：


输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
示例 2：


输入：head = [1,2]
输出：[2,1]
示例 3：

输入：head = []
输出：[]
 

提示：

链表中节点的数目范围是 [0, 5000]
-5000 <= Node.val <= 5000
 

进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

通过次数1,069,647提交次数1,465,235
请问您在哪类招聘中遇到此题？
贡献者
LeetCode
半年内半年 ~ 1年1年 ~ 2年
反转链表 II
中等
上下翻转二叉树
中等
回文链表
简单

*/

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    // 2022.6.4, 极客时间覃超算法训练營
    ListNode* reverseList2(ListNode* head) {
        // define two nodes for previous and current node
        ListNode *prevNode = NULL;
        ListNode *currNode = head;

        // below while loop code os a standard template
        // to reverse linked list node
        while (currNode) {
            // save current node's next node
            ListNode *tmp = currNode->next;

            // reverse node happened here
            currNode->next = prevNode;

            // current node becomes previous node
            prevNode = currNode;

            // next node becomes current node
            currNode = tmp;
        }

        // inside while loop, tmp may be NULL node, and once that
        // loop finished and assign tmp to current node, current
        // node will become NULL, so we must return previous
        // node here, not current node
        return prevNode;
    }

    // 2022.6.5, from AcWing https://www.acwing.com/video/1584/
    ListNode* reverseList1(ListNode* head) {
        // corner case when head itself is NULL
        if (!head) return NULL;

        // define two nodes
        auto a = head, b = head->next;

        // keep next one until b is NULL
        while (b) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }

        // trick, remember set head's next to NULL as it is now end node
        // below statement is must have
        head->next = NULL;

        // why a not b? Because above while condition is b, so when
        // it stops, that means b is NULL and a is the node before b,
        // so return a not return b
        return a;
    }
    
    //2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/reverse-linked-list.cpp
    ListNode* reverseList(ListNode* head) {
        auto dummy = ListNode{0};

        while (head) {
            auto tmp = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tmp;
        }

        return dummy.next;
    }

};
// @lc code=end

