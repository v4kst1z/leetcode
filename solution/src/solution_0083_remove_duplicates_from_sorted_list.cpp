
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *dummy_head = new ListNode(0, head);
        ListNode *p = dummy_head->next;
        while (p->next) {
            int flag = p->val;
            ListNode *next = p->next;
            while (next && next->val == flag) {
                next = next->next;
            }
            if (next == nullptr) { p-> next = nullptr;}
            else {
                p->next = next;
                p = next;
            }
        }
        return dummy_head->next;
    }
};
