#include <map>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *merge(ListNode* l1, ListNode *l2) {
        if (!l1 && !l2) return nullptr;
        if (!l1 || !l2) return !l1 ? l2 : l1;

        ListNode *result = new ListNode(0);
        ListNode *curr = result;

        while (l1 && l2) {
            if(l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (!l1) curr->next = l2;
        if (!l2) curr->next = l1;
        return  result->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = prev->next;
        prev->next = nullptr;

        return merge(sortList(head), sortList(fast));
    }
};
