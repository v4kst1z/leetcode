struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *even = head;
        ListNode *odd = head->next;
        ListNode *p_even = even;
        ListNode *p_odd = odd;
        ListNode *p = head->next->next;
        while (p) {
            ListNode *next = p->next;
            p_even->next = p;
            p_even = p_even->next;
            p = next;
            if(p) {
                next = p->next;
                p_odd->next = p;
                p_odd = p_odd->next;
                p = next;
            }
        }
        p_odd->next = nullptr;
        p_even->next = odd;
        return even;
    }
};
