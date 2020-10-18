#include<stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p_l1 = l1;
        ListNode *p_l2 = l2;
        std::stack<int> first, second;

        while (p_l1) {
            first.push(p_l1->val);
            p_l1 = p_l1->next;
        }

        while (p_l2) {
            second.push(p_l2->val);
            p_l2 = p_l2->next;
        }

        ListNode *result = new ListNode(0);
        int carry = 0;
        while (!first.empty() || !second.empty()) {
            int first_val = (!first.empty()) ? first.top() : 0;
            int second_val = (!second.empty()) ? second.top() : 0;
            int sum = first_val + second_val + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *tmp = new ListNode(sum);
            ListNode *next = result->next;
            result->next = tmp;
            result->next->next = next;
            if (!first.empty()) first.pop();
            if (!second.empty()) second.pop();
        }

        if (carry) {
            ListNode *next = result->next;
            result->next = new ListNode(carry);
            result->next->next = next;
        }

        return result->next;
    }
};