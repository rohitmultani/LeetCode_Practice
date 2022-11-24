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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        int len=0;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        int kNew=k%len;
        
        temp=head;
        while(temp){
            if(temp->next==NULL){
                temp->next=head;
                break;
            }
            temp=temp->next;
        }
        temp=head;
        int check=len-kNew;
        while(--check){
            temp=temp->next;
        }
        
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};