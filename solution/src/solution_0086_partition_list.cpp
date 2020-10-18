
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode * l1 = new ListNode(0);
        ListNode * l2 = new ListNode(0);
        ListNode * p_l1 = l1;
        ListNode * p_l2 = l2;

        while (head) {
            if (head->val < x) {
                p_l1->next = head;
                p_l1 = p_l1->next;
            } else {
                p_l2->next = head;
                p_l2 = p_l2->next;
            }
            head = head->next;
        }
        p_l1->next = l2->next;
        p_l2->next = nullptr;
        return l1->next;
    }
};