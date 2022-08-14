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
    ListNode* reverseList(ListNode* head) {
        ListNode* l=head;
        ListNode* temp=new ListNode();
        temp->next=NULL;
        
        while(head){
            // temp=temp*10+head->val;
            temp->val=l->val;
            if(l->next==NULL){
                break;
            }
            ListNode* t=new ListNode();
                t->next=temp;
            temp=t;
        l=l->next;
        }
        if(head)
        return temp;
        else return head;
    }
};