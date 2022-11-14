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
    void createMap(vector<int> in,map<int,int> &nodeToIndex, int n){
        for(int i=0;i<n;i++){
            nodeToIndex[in[i]]=i;
        }
    }
    TreeNode* solve(vector<int> in,vector<int> pre, int &index, int inorderStart,int inorderEnd,int n, map<int,int> &nodeToIndex){
        if(index>=n || inorderStart>inorderEnd){
            return NULL;
        }
        int element=pre[index++];
        TreeNode* root= new TreeNode(element);
        int pos = nodeToIndex[element];
        
        root->left=solve(in,pre,index,inorderStart,pos-1,n,nodeToIndex);
        root->right=solve(in,pre,index,pos+1,inorderEnd,n,nodeToIndex);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        map<int,int> nodeToIndex;
        
        createMap(inorder, nodeToIndex, inorder.size());
        
        TreeNode* ans = solve(inorder,preorder,preOrderIndex,0,inorder.size()-1,inorder.size(),nodeToIndex);
        return ans;
    }
};