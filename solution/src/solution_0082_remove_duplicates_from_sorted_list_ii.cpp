
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
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *dummy_head = new ListNode(0, head);
        ListNode *prev = dummy_head;
        ListNode  *p = dummy_head->next;
        while (p->next != nullptr) {
            int flag = p->val;
            if (p->next->val == flag) {
                while(p->next != nullptr && p->next->val == flag) {
                    p = p->next;
                }
                if(p->next == nullptr) {
                    prev->next = nullptr;
                    break;
                } else {
                    p = p->next;
                    prev->next = p;
                }
            } else {
                prev = p;
                p = p->next;
            }
        }
        return dummy_head->next;
    }
};

