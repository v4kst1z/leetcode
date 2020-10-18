/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 题目错了，随手复制的
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int p;
        p=node->next->val;
        node->next->val=node->val;
        node->val=p;
        node->next=node->next->next;
    }
};