class Solution {
public:
    bool isValidBST(TreeNode* root) { return valid(root, LONG_MIN, LONG_MAX); }

    bool valid(TreeNode* node, long left, long right) {
        if (!node)
            return true;
        if (!(left < node->val && node->val < right))
            return false;

        return valid(node->left, left , node->val) &&
               valid(node->right, node->val, right);
    }
};
