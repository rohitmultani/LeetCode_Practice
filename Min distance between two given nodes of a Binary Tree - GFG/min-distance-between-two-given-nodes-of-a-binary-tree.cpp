//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
     Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root==NULL)
       return NULL;
       
       if(root->data==n1||root->data==n2){
           return root;
       }
       
       Node* left=lca(root->left,n1,n2);
       Node* right=lca(root->right,n1,n2);
       
       if(left!=NULL && right!=NULL){
           return root;
       }
       else if(left==NULL && right!=NULL){
           return right;
       }
       else if(left!=NULL && right==NULL){
           return left;
       }
       else return NULL;
       
    }
    int dist(Node* root,int a,int distance){
        if(root==NULL)
        return 0;
        
        if(root->data==a)
        return 1;
        
        int left = dist(root->left,a,distance+1);
        int right = dist(root->right,a,distance+1);
        
        if(!left && !right)
        return 0;
        
        else return left+right+1;
        
    }
    int findDist(Node* root, int a, int b) {
        Node* lcaNode = lca(root,a,b);
        int d1 = dist(lcaNode,a,0);
        int d2 = dist(lcaNode,b,0);
        return d1+d2-2;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends