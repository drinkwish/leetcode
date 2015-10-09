//40ms, can be optimized

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
    ListNode* removeElements(ListNode* head, int val) {
        if(nullptr == head) return nullptr;
        
        ListNode* ret = head;
        while(nullptr != ret && ret->val == val){
            ListNode *tmp = ret;
            ret = ret->next;
            delete tmp;
        }
        
        if(nullptr == ret) return ret;
        
        ListNode* p= ret;
        while(p->next != nullptr){
            if(p->next->val == val){
                ListNode *tmp = p->next;
                p->next = tmp->next;
                delete tmp;
            }
            else p = p->next;
        }
        
        return ret;
    }
};