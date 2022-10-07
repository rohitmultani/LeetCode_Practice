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
class Solution{
    private: ListNode* getMid(ListNode *head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* start){
        ListNode* curr=start;
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(ListNode *head)
    {
        if(head==NULL)
        return 0;
        else if(head->next==NULL)
        return 1;
        ListNode *middle = getMid(head);
        // cout<<middle->data;
       middle->next = reverse(middle->next);
       ListNode* temp=head;
       ListNode* temp2=middle->next;
       while(temp2!=NULL){
           if(temp->val!=temp2->val)
           return 0;
           temp=temp->next;
           temp2=temp2->next;
       }
       
        return 1;
    }
};
