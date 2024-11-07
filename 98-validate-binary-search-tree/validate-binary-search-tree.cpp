/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root, long long minVal = LONG_MIN, long long maxVal = LONG_MAX) {
        if(!root){
            return true;
        }
       if(root->val <= minVal || root->val >= maxVal){
        return false;
       }
       return isValidBST(root->left,minVal,root->val) && 
       isValidBST(root->right,root->val,maxVal);
    }

};
