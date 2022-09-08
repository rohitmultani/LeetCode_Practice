class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> order;
       inorder(root,order);
        return order;
        
    }
private: void inorder(TreeNode* root, vector<int>& order)
{
    if(!root){
        return;
    }
    
        inorder(root->left,order);
        order.push_back(root->val);
        inorder(root->right,order);
}
};