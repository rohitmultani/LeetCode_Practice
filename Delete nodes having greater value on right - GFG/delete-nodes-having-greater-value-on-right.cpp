//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

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
class Solution
{
    public:
    Node* reverse(Node* head){
        Node* curr=head;
        Node* fwd=NULL;
        Node* prev=NULL;
        while(curr){
            fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        
        return prev;
    }
    Node *compute(Node *head)
    {
        Node* revHead=reverse(head);
        
        Node* temp=revHead;
        Node* prev=revHead;
        int maxi=INT_MIN;
        
        while(temp){
            maxi=max(maxi,temp->data);
            if(temp->data<maxi){
                //delete that node
        
                prev->next=temp->next;
                temp=prev->next;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
            
        }
        
        Node* newHead=reverse(revHead);
        return newHead;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends