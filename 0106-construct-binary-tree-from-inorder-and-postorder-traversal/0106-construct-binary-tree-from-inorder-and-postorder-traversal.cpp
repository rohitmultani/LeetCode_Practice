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
    TreeNode* solve(vector<int> in,vector<int> post, int &index, int inorderStart,int inorderEnd,int n, map<int,int> &nodeToIndex){
        if(index<0 || inorderStart>inorderEnd){
            return NULL;
        }
        int element=post[index--];
        TreeNode* root= new TreeNode(element);
        int pos = nodeToIndex[element];
        
        
        root->right=solve(in,post,index,pos+1,inorderEnd,n,nodeToIndex);
        root->left=solve(in,post,index,inorderStart,pos-1,n,nodeToIndex);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postOrderIndex =postorder.size()-1 ;
        map<int,int> nodeToIndex;
        
        createMap(inorder, nodeToIndex, inorder.size());
        
        TreeNode* ans = solve(inorder,postorder,postOrderIndex,0,inorder.size()-1,inorder.size(),nodeToIndex);
        return ans;
    }
};