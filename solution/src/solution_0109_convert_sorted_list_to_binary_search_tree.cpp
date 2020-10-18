struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *dummy_head = new ListNode(0, head);
        ListNode *p1 = dummy_head;
        ListNode *p2 = dummy_head;
        ListNode *prev = dummy_head;

        while (p1 && p2 && p2->next) {
            prev = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }

        prev->next = nullptr;
        TreeNode *root = new TreeNode(p1->val);
        p1 = p1->next;
        root->left = sortedListToBST(dummy_head->next);
        root->right = sortedListToBST(p1);
        return root;
    }
};
