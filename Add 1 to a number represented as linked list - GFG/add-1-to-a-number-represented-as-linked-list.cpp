//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    int add(Node* head,Node* temp){
        if(temp->next==NULL){
            if(temp->data==9){
                temp->data=0;
                return 1;
            }
            else{
                temp->data+=1;
                return 0;
            }
        }
        
        temp->data+=add(head,temp->next);
        
         if(temp->data==10){
                temp->data=0;
                return 1;
            }
            else{
                return 0;
          }
        
    }
    Node* addOne(Node *head) 
    {
        Node* temp = head;
        int ans = add(head,temp);
        if(ans == 1){
        Node* newHead=new Node(1);
        newHead->next=head;
        head=newHead;
        }
        
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends