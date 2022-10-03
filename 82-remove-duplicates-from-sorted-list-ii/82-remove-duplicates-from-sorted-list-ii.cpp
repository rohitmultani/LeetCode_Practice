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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        unordered_map<int,int> node;
        ListNode* temp=head;
        while(temp!=NULL){
            node[temp->val]++;
            temp=temp->next;
        }
        temp=head;
        ListNode* prev=NULL;
        ListNode* ptr=NULL;
        
        while(temp!=NULL){
            //1st element
            if(node[temp->val]>1 && temp==head){
            
                prev=temp;
                temp=temp->next;
                delete prev;
                prev=temp;
                head=temp;
            }
            else if(node[temp->val]==1 && temp==head){
                
                prev=temp;
                temp=temp->next;
            }
            else if(node[temp->val]>1 && temp!=head){
                
                
                prev->next=temp->next;
                ptr=prev->next;
                temp=temp->next;
                
            }
            else if(node[temp->val]==1 && temp!=head){
                
                prev=temp;
                temp=temp->next;
            }
            
        }
    
    return head;
    }
};