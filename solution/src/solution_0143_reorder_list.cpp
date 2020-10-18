struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /*
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return;
        unsigned len = 0;
        ListNode *p = head;
        std::map<unsigned, ListNode*> map_node;
        while (p) {
            map_node.insert(std::pair<unsigned, ListNode*>(len, p));
            len++;
            p = p->next;
        }

        unsigned left = 0;
        unsigned right = len - 1;
        p = head;
        while (right >= left) {
            if (right == left) {
                p->next = map_node[right];
                p = p->next;
                break;
            }

            if (p == head) {
                p->next = map_node[right--];
                p = p->next;
                left++;
            } else {
                p->next = map_node[left++];
                p->next->next = map_node[right--];
                p = p->next->next;
            }

        }
        p->next = nullptr;
        return;
    }
     */
    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr;
        while (head) {
            ListNode *tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        ListNode *p = prev;
        return prev;
    }

    void merge(ListNode *l1, ListNode *l2) {
        ListNode *p = l1;
        while (l1) {
            ListNode *l1_next = l1->next;
            ListNode *l2_next = l2->next;

            if (p == l1) {
                p->next = l2;
                if (!l1_next) {
                    p->next->next = l2_next;
                    return;
                }
                p = p->next;
            }
            else {
                p->next = l1;
                p->next->next = l2;
                p = p->next->next;
            }

            if(!l1_next){
                p->next = l2_next;
                return;
            }
            l1 = l1_next;
            l2 = l2_next;
        }
    }

    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode *tmp_ls = reverse(slow);
        fast = head;
        merge(fast, tmp_ls);
    }
};

