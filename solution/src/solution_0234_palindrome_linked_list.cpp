struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverse(ListNode *head) {
        ListNode *result = new ListNode(0);
        ListNode *p = result;
        while (head) {
            ListNode *tmp = new ListNode(head->val);
            ListNode *next = p->next;
            p->next = tmp;
            p->next->next = next;
            head = head->next;
        }
        return result->next;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode *reverse_nodes = reverse(head);
        while (reverse_nodes && head) {
            if(reverse_nodes->val != head->val) return false;
            reverse_nodes = reverse_nodes->next;
            head = head->next;
        }
        return true;
    }
};
