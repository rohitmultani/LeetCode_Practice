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
    ListNode* find(ListNode* head){
       
        ListNode* slow=head;
        ListNode* fast=head->next->next;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
         if(head->next==NULL)
            return NULL;
        ListNode* temp=head;
        ListNode* mid=find(temp);
        mid->next=mid->next->next;
        return head;
    }
    
};