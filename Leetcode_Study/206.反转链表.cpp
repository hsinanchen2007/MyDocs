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
    ListNode* reverseList3(ListNode* head) {
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
    ListNode* reverseList2(ListNode* head) {
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
    ListNode* reverseList1(ListNode* head) {
        auto dummy = ListNode{0};

        while (head) {
            auto tmp = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tmp;
        }

        return dummy.next;
    }

    // 2022.6.14, from https://ke.algomooc.com/detail/v_625c124fe4b09dda125c1519/3?from=p_6243bcc1e4b04e8d90291891&type=8&parent_pro_id=p_624d3a91e4b01a4851edb490
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    ListNode* reverseList(ListNode* head) {

        // 寻找递归终止条件
        // 1、head 指向的结点为 null 
        // 2、head 指向的结点的下一个结点为 null 
        // 在这两种情况下，反转之后的结果还是它自己本身
        if( head == NULL || head->next == NULL)  return head;

        // 不断的通过递归调用，直到无法递归下去，递归的最小粒度是在最后一个节点
        // 因为到最后一个节点的时候，由于当前节点 head 的 next 节点是空，所以会直接返回 head
        ListNode *cur = reverseList(head->next);

        // 比如原链表为 1 --> 2 --> 3 --> 4 --> 5
        // 第一次执行下面代码的时候，head 为 4，那么 head.next = 5
        // 那么 head.next.next 就是 5.next ，意思就是去设置 5 的下一个节点
        // 等号右侧为 head，意思就是设置 5 的下一个节点是 4
        
        // 这里出现了两个 next
        // 第一个 next 是「获取」 head 的下一节点
        // 第二个 next 是「设置」 当前节点的下一节点为等号右侧的值
        head->next->next = head;


        // head 原来的下一节点指向自己，所以 head 自己本身就不能再指向原来的下一节点了
        // 否则会发生无限循环
        head->next = nullptr;

        // 我们把每次反转后的结果传递给上一层
        return cur;

    }

};
// @lc code=end

