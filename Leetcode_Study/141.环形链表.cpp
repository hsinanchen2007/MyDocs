/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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

    /*
    // 2022.5.30, LG solution
    //   1. Use slow and fast pointers, starts from 1st and 2nd nodes
    //   2. If slow and fast are at same node, there is a cycle
    //   3. If slow and fast are at different nodes, no cycle yet, 
    //      so flow will go to next node, and fast will go to next next node
    //   4. Stop while loop when fast or fast->next is NULL, that means there
    //      is no cycle in this linked list
    bool hasCycle(ListNode *head) {
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
    */

    // 2022.5.30, soulmachine
    //   1. The solution eliminates such null head or sinle node check
    //      and put such check into while loop, so it will take care of 
    //      NULL head or single node condition
    //   2. The first thing into while loop is to set next node, then 
    //      check if slow and fast pointers are at same node or not
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        
        return false;
    }

};
// @lc code=end

