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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* base = new ListNode(-1);
    ListNode* fTemp=list1;
    ListNode* sTemp=list2;
    ListNode* temp=base;
    while(fTemp!=NULL&&sTemp!=NULL){
        int a=fTemp->val;
        int b=sTemp->val;
        if(a<=b){
            temp->next=fTemp;
            temp=temp->next;
            fTemp=fTemp->next;
        }
        else{
            temp->next=sTemp;
            temp=temp->next;
            sTemp=sTemp->next;
        }
    }
    
        if(fTemp!=NULL){
             temp->next=fTemp; 
        }
    else if(sTemp!=NULL){
        temp->next=sTemp; 
    }
        return base->next;
        
    
    }
};