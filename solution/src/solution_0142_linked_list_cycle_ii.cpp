struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        if (head == head->next->next) return head;
        ListNode *p1 = head;
        ListNode *p2 = head;

        while (p1 && p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2) break;
        }
        if (p2 == nullptr || p2->next == nullptr) return nullptr;
        p2 = head;
        while (p1 != p2) {
            p2 = p2->next;
            p1 = p1 ->next;
        }
        return p1;
    }
};
