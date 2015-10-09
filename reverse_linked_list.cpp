//run time 16ms, can be optimized
//
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
    ListNode* reverseList(ListNode* head) {
        if(nullptr == head || nullptr == head->next) return head;
        
        ListNode* tmp = head->next;
        ListNode* rhead = head;
        rhead->next = nullptr;
        head = tmp;
        while(nullptr != head){
            tmp = head->next;
            head->next = rhead;
            rhead = head;
            head = tmp;
        }
        
        return rhead;
    }
};
