//
// Created by v4kst1z.
//

class Solution {
private:
    unordered_map<TreeNode*, int> mp;
    int helper(TreeNode* root) {
        if(!root) return 0;
        if(mp.count(root)) return mp[root];
        int val = 0;
        if(root->left)
            val += helper(root->left->left) + helper(root->left->right);
        if(root->right)
            val += helper(root->right->left) + helper(root->right->right);
        val = max(val + root->val, helper(root->left) + helper(root->right));
        mp[root] = val;
        return val;
    }
public:
    int rob(TreeNode* root) {
        mp.clear();
        return helper(root);
    }
};
