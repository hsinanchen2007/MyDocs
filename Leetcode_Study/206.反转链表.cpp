/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList1(ListNode* head) {
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
    ListNode* reverseList(ListNode* head) {
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
    
};
// @lc code=end

