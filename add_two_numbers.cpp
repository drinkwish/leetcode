//40ms, too slow

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        ListNode *ret_head = new ListNode((l1->val + l2->val)%10);
        int c = (l1->val + l2->val)/10;
        
        ListNode *ret = ret_head;
        ListNode *p = l1->next;
        ListNode *q = l2->next;
        while(p != nullptr && q!= nullptr){
            int sum = p->val + q->val + c;
            ret->next = new ListNode(sum%10);
            ret = ret->next;
            c = sum/10;
            p = p->next;
            q = q->next;
        }
        
        while(p != nullptr){
            int sum = p->val + c;
            ret->next = new ListNode(sum%10);
            ret = ret->next;
            p = p->next;
            c = sum/10;
        }
        
        while(q != nullptr){
            int sum = q->val + c;
            ret->next = new ListNode(sum%10);
            ret = ret->next;
            q = q->next;
            c = sum/10;
        }
        
        if(c){
            ret->next = new ListNode(c);
        }
        
        return ret_head;
    }
};