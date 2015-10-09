//52ms, can be optimized

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
        if(nullptr == headA || nullptr == headB) return nullptr;
        
        ListNode *p = headA;
        ListNode *q = headB;
        int lengthA =0, lengthB = 0;
        
        while(p != nullptr){
            p = p->next;
            ++lengthA;
        }
        
        while(q != nullptr){
            q = q->next;
            ++lengthB;
        }
        
        if(lengthA > lengthB){
            p = headA;
            q = headB;
        }
        else{
            p = headB;
            q = headA;
        }
        
        int tmp = abs(lengthA - lengthB);
        while(tmp--){
            p = p->next;
        }
        
        while(nullptr != p){
            if(p == q) return p;
            p = p->next;
            q = q->next;
        }
        
        return nullptr;
        
    }
};