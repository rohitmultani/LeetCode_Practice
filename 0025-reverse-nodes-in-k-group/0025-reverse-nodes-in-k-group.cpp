/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==NULL)
        return head;
    ListNode* forward=NULL;
    ListNode* curr=head;
    ListNode* temp=head;    
    ListNode* prev=NULL;
    int cnt=0;
    int l=0;
    while(temp!=NULL){
            l++;
            temp=temp->next;
        }
        if(l>=k){
    while(curr!=NULL && cnt<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        cnt++;
          }
        }
        else if(l<k){
            return head;
        }
    if(forward!=NULL){
        head->next=reverseKGroup(forward,k);
    }
    return prev;
    
    }
};