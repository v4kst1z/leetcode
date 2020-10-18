#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    std::vector<ListNode*> splitListToParts(ListNode* root, int k) {
        unsigned len = 0;
        ListNode *p = root;
        while (p) {
            len++;
            p = p->next;
        }

        unsigned step = (len / k) ? (len / k) : 1;
        unsigned carry = (len / k) ? (len % k) : 0;
        std::vector<ListNode *> result;
        p = root;
        while (p) {
            unsigned tmp_step = step;
            if (carry) {
                carry--;
                tmp_step++;
            }

            ListNode *tmp = new ListNode(0);
            ListNode *tmp_p = tmp;
            while (tmp_step--) {
                tmp_p->next = p;
                p = p->next;
                tmp_p = tmp_p->next;
            }
            tmp_p->next = nullptr;
            result.push_back(tmp->next);
        }
        int rest = k - len;
        while (rest > 0) {
            result.push_back(nullptr);
            rest--;
        }
        return result;
    }
};