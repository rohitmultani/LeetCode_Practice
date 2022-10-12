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
    ListNode* mid(ListNode* head){
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        ListNode* ans = new ListNode(-1);
        ListNode* temp=ans;
        while(left!=NULL && right!=NULL){
            int l = left->val;
            int r = right->val;
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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
       ListNode* middle=mid(head);
        ListNode* left=head;
        ListNode* right=middle->next;
        middle->next=NULL;
        left=sortList(left);
        right=sortList(right);
        ListNode* result = merge(left,right);
        return result;
    }
};