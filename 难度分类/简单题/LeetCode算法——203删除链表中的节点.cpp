/*
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr){
            return nullptr;
        }
        ListNode *tou = new ListNode(-1);
        tou->next = head;
        ListNode *pre = tou;
        while (pre->next){
            if (pre->next->val == val){
                ListNode *temp = pre->next;
                pre->next = temp->next;
                delete temp;
                temp = nullptr;
            } else {
                pre = pre->next;
            }
        }
        return tou->next;
    }
};