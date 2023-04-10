//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
  Node* merge(Node* left,Node* right){
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        Node* ans = new Node(-1);
        Node* temp=ans;
        while(left!=NULL && right!=NULL){
            int l = left->data;
            int r = right->data;
            if(l<=r){
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=temp->next;
                right=right->next;
            }
        }
              if(left!=NULL){
             temp->next=left; 
            }
             else if(right!=NULL){
             temp->next=right; 
            }
        return ans->next;
    }
    //Function to merge K sorted linked list.
    void merge2List(Node* arr[],int K,int i){
        if(i>K-2)
        return;
        
        arr[i+1]=merge(arr[i],arr[i+1]);
         merge2List(arr,K,++i);
         
    
    }
    Node * mergeKLists(Node *arr[], int K)
    {
      merge2List(arr,K,0);
           return arr[K-1];
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends