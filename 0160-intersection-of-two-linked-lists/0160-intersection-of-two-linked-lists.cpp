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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> check;
        ListNode* temp=headA;
        while(temp!=NULL){
            check[temp]=1;
            temp=temp->next;
        }
    temp=headB;
        while(temp!=NULL)
        {
            if(check[temp]==1){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }
};