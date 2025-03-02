class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int left= height(root->left);
        int right= height(root->right);
        if(abs(left - right) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1+ max(height(root->left),height(root->right));
    }
    
};