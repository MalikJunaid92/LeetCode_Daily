class Solution {
public:
    int solve(TreeNode* root) {
        if (root == NULL) return 0;

        int left = solve(root->left);
        if (left == -1) return -1;  // left subtree unbalanced

        int right = solve(root->right);
        if (right == -1) return -1; // right subtree unbalanced

        if (abs(left - right) > 1) return -1; // current node unbalanced

        return max(left, right) + 1; // return height
    }

    bool isBalanced(TreeNode* root) {
        return solve(root) != -1; // if -1 → unbalanced, else balanced
    }
};
