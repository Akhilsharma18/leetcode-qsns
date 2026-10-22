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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
      if(root->left==NULL && root->right==NULL) return 1;
      int ln = root->left!=NULL ? minDepth(root->left) :INT_MAX;
          int rn = root->right!=NULL ? minDepth(root->right):INT_MAX;
 return 1+ min(ln,rn);
        
    }
};