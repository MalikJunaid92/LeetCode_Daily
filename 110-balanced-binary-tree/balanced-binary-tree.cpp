/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        return (Height(root) != -1);
    }
    
    int Height(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftHeight = Height(root->left);
        int rightHeight = Height(root->right);
        
        // If any of the subtrees is unbalanced, propagate the failure (-1)
        if (leftHeight == -1 || rightHeight == -1)
            return -1;
        
        // Check if the current node is unbalanced
        if (abs(leftHeight - rightHeight) > 1)
            return -1;
        
        // Return the height of the tree
        return max(leftHeight, rightHeight) + 1;
    }
};
