//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
  Node* mid(Node* head){
        Node* fast=head->next;
        Node* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
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
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
         if(head==NULL || head->next==NULL)
            return head;
       Node* middle=mid(head);
        Node* left=head;
        Node* right=middle->next;
        middle->next=NULL;
        left=mergeSort(left);
        right=mergeSort(right);
        Node* result = merge(left,right);
        return result;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends