#include <vector>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    int numComponents(ListNode* head, std::vector<int>& G) {
        std::unordered_set<int> values(G.begin(), G.end());
        int result = 0;
        while (head) {
            if (values.count(head->val)) {
                result++;
                while (head->next && values.count(head->next->val)) {
                    head = head->next;
                }
            }
            head = head->next;
        }
        return result;
    }
};