/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getStart(ListNode* head,ListNode *intersection){
        ListNode *fast=intersection;
        ListNode *slow=head;
       
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        
        return slow;
    }
    ListNode* floydLoop(ListNode *head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow!=NULL&&fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
            if(slow==fast){
                return slow;
            }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return head;
        ListNode* intersection = floydLoop(head);
        ListNode* start=NULL;
        if(intersection==NULL)
            return NULL;
        else if(intersection!=NULL){
         start =getStart(head,intersection);
        }
        return start;
    }
};