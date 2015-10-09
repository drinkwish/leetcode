/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
4ms, 99.11%
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || (head && !head->next)) return head;
        if(head && head->next){
            ListNode* tmp = head->next;
            head->next = swapPairs(tmp->next);
            tmp->next = head;
            return tmp;
        }
    }
};