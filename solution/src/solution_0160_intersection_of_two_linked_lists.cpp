#include <stdlib.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;

        unsigned lenA = 0, lenB = 0;
        ListNode *p1 = headA;
        ListNode *p2 = headB;

        while (p1) {
            p1 = p1->next;
            lenA++;
        }
        while (p2) {
            p2 = p2->next;
            lenB++;
        }
        int abs_len = lenA - lenB;
        abs_len = std::abs(abs_len);

        p1 = headA;
        p2 = headB;
        if(lenA > lenB) {
            while (abs_len-- > 0) {
                p1 = p1->next;
            }
        } else {
            while (abs_len-- > 0) {
                p2 = p2->next;
            }
        }
        while (p1 && p2) {
            if (p1 == p2) {
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
