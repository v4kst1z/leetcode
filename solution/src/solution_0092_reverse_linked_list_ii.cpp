
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || head->next == nullptr || m == n) return head;
        ListNode *dummy_head = new ListNode(0, head);
        ListNode *start = dummy_head;
        ListNode *prev = dummy_head;
        int tmp_n = n - m;

        n = n - m;
        while (m-- > 0) {
            prev = start;
            start = start->next;
        }
        ListNode *end = start;
        while (n-- > 0) {
            end = end->next;
        }
        ListNode * rest = end->next;
        ListNode * tmp = new ListNode(0);

        while (tmp_n-- >= 0) {
            ListNode *next = tmp->next;
            tmp->next = start;
            start = start->next;
            tmp->next->next = next;
        }
        prev->next = tmp->next;
        while (prev->next) {
            prev = prev->next;
        }
        prev->next = rest;

        return dummy_head->next;
    }
};
