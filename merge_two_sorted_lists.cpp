//12ms, can be optimized

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(nullptr == l1) return l2;
        if(nullptr == l2) return l1;
        
        ListNode* ret = nullptr;
        if(l1->val <= l2->val) {
            ret = l1;
            ret->next = mergeTwoLists(l1->next, l2);
            return ret;
        }
        else{
            ret = l2;
            ret->next = mergeTwoLists(l1, l2->next);
            return ret;
        }
    }
};