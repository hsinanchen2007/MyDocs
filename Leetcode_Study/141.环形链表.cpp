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

    // 2022.5.30, LG solution
    //   1. Use slow and fast pointers, starts from 1st and 2nd nodes
    //   2. If slow and fast are at same node, there is a cycle
    //   3. If slow and fast are at different nodes, no cycle yet, 
    //      so flow will go to next node, and fast will go to next next node
    //   4. Stop while loop when fast or fast->next is NULL, that means there
    //      is no cycle in this linked list
    bool hasCycle2(ListNode *head) {
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
    bool hasCycle1(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        
        return false;
    }

    // 2022.6.5, from AcWing https://www.acwing.com/video/1513/
    bool hasCycle(ListNode *head) {
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

};
// @lc code=end

