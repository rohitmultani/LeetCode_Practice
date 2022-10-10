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
    ListNode* reverse(ListNode* left,ListNode* right){
        
        ListNode* r=right->next;
        ListNode* curr=left;
        ListNode* prev=NULL;
        ListNode* forward =NULL;
        cout<<left->val;
        cout<<right->val;
        while(curr!=r){
            
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        left->next=r;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        ListNode* LPoint=NULL;
        ListNode* RPoint=NULL;
        int cnt=1;
        while(temp->next!=NULL){
           
            if(left==right)
                return head;    
            else if(cnt+1 ==left){
                LPoint=temp;
            }
            else if(cnt+1==right){
                RPoint=temp->next;
            }
           
            temp=temp->next;
            cnt++;
            
        }
        
        if(left==1){
            return reverse(head,RPoint);
        }
        else if(LPoint->next==RPoint)
            return head;
        else
        LPoint->next=reverse(LPoint->next,RPoint);
        return head;
    }
    
};