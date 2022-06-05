/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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

    // 2022.5.31 LG solution, use two pointers
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        // define pointers to iterate and trace current pointer
        ListNode* p = l1;
        ListNode* q = l2;

        // define head node with value -1
        ListNode* result = new ListNode(-1);

        // define current node, starts from head node
        ListNode* current = result;

        // to trace if the sum is equal or over 10
        int carry = 0;

        // need below or condition as we don't know size of p or q list
        // the given data structure didn't provide size() function
        while (p !=NULL || q != NULL) {
            // get values from nodes
            int x = (p != NULL)? p->val : 0;
            int y = (q != NULL)? q->val : 0;
            int sum = x + y + carry;

            // determine whether carry is equal or over 10
            // for carry, use "/ 10"
            // for example, (5 + 5) / 10 = 1, so carry will be 1
            // for example, (7 + 8) / 10 = 1, so carry will be 1
            // for example, (3 + 4) / 10 = 0, so carry will be 0 
            carry = sum / 10;

            // get the number we need to put into new node
            // for the sum of nodes, we only need to put last digital
            // so we use "% 10" to get its number
            // for example, (3 + 6) % 10 = 9, we put 9 into node value
            // for example, (5 + 7) % 10 = 2, we put 2 into node value
            // carry will be 1 and will be applied to next iteration
            int num = sum % 10;
            current->next = new ListNode(num);
            current = current->next;

            // next iteration
            p = (p == NULL) ? p : p->next;
            q = (q == NULL) ? q : q->next;
        }

        // add new node due to carry > 0, carry should be 1 in general
        if (carry > 0) {
            current->next = new ListNode(carry);
        }

        // return the next node of head node. head node has invalid number -1
        // when we create it at the beginning
        return result->next;
    }

    // 2022.6.4, from AcWing https://www.acwing.com/video/1318/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // a trick that use auto to declare two ListNodes here
        auto dummy = new ListNode(-1), cur = dummy;

        // t can be used as sum and determine whether it is equal or 
        // larger 10 or not
        int t = 0;

        // this while condition covers l1, l2 or if t is 1, aka needed to add 1 to next
        while (l1 || l2 || t) {
            if (l1) t = l1->val + t, l1 = l1->next;
            if (l2) t = l2->val + t, l2 = l2->next;
       
            // we only assign number between 0~9, and update cur
            cur->next = new ListNode(t % 10);
            cur = cur->next;

            // whether it is equal or over 10, this one will tell
            t = t / 10;
        }

        // current is at dummy->next, dummy is just a dummy head w/ value -1
        // we declare it at the beginning
        return dummy->next;
    }

};
// @lc code=end

