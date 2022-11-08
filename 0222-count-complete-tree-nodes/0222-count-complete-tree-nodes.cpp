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
    int count(TreeNode *root,int &ans){
        if(root==NULL)
        return 0;

        int left = count(root->left,ans);
       int right =  count(root->right,ans);
       ans=left+right+1;
       return ans;
    }
    int countNodes(TreeNode* root) {
        int ans=0;
       return count(root,ans);

    }
};