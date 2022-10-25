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
    private:
    ListNode* reverse(ListNode* head){
         ListNode* curr=head;
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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* temp2=reverse(slow->next);
        ListNode* temp1=head;
        
        int maxVal=INT_MIN;
        while(temp1!=NULL&&temp2!=NULL){
            int a=temp1->val;
            int b=temp2->val;
            maxVal=max(maxVal,a+b);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return maxVal;
    }
};