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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* base = new ListNode();
        ListNode* ln = base;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val <= l2->val){
                ln->next = l1;
                l1 = l1->next;
            }
            else{
                ln->next = l2;
                l2 = l2->next;
            }
            ln = ln->next;
        }
        ln->next = l1!=nullptr?l1:l2; 
        return base->next;      
    }
};