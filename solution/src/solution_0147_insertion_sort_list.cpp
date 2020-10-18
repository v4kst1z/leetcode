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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *p = head->next;
        ListNode *result = new ListNode(0);
        result->next = new ListNode(head->val);
        while (p) {
            ListNode *p_res = result->next;
            ListNode *prev = result;
            ListNode *next = p->next;

            while (p_res) {
                if(p_res->val > p->val) {
                    prev->next = p;
                    prev->next->next = p_res;
                    break;
                }
                prev = p_res;
                p_res = p_res->next;
            }
            if (!p_res) {
                prev->next = p;
                prev->next->next = nullptr;
            }
            p = next;
        }
        return result->next;
    }
};
