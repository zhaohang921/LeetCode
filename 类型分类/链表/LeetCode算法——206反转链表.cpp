/*
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 迭代
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *new_head = nullptr;
        while (head){
            ListNode *next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
        }
        return new_head;
    }
};

// 递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next){
            return head;
        }
        ListNode *p = head;
        head = reverseList(p->next);
        p->next->next = p;
        p->next = nullptr;
        return head;
    }
};