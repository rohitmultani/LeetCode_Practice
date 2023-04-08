//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/
void createNode(int val,Node* &head,Node* &tail){
    Node* nd = new Node(val);
    if(head==NULL){
        head=nd;
        tail=nd;
        return;
    }
    else{
        tail->next=nd;
        tail=nd;
    }
}
Node* findIntersection(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* head = NULL;
    Node* tail = NULL;
    while(temp1 && temp2){
        int val1=temp1->data;
        int val2=temp2->data;
        
        if(val1<val2 && temp1->next){
            temp1=temp1->next;
        }
        else if(val1>val2 && temp2->next){
            temp2=temp2->next;
        }
        else if(val1==val2){
            createNode(val1,head,tail);
             temp1=temp1->next;
            temp2=temp2->next;
        }
        else{
             temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    return head;
    
}