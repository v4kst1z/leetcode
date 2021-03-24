//
// Created by v4kst1z on 2021/3/23.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;

    void inorder(TreeNode *root) {
        if(!root) return;

        inorder(root->right);
        st.push(root);
        inorder(root->left);
    }

public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }

    int next() {
        if(st.size()) {
            auto node = st.top();
            st.pop();
            return node->val;
        }
    }

    bool hasNext() {
        return !st.empty();
    }
};