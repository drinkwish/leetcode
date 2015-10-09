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
    bool isPalindrome(ListNode* head) {
        if(nullptr == head || nullptr == head->next){
            return true;
        }
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(nullptr != fast->next && nullptr != fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *last = slow->next;
        ListNode *pre = head;
        
        while(nullptr != last->next){
            ListNode *tmp = last->next;
            last->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        
        while(nullptr != slow->next){
            slow = slow->next;
            if(pre->val != slow->val){
                return false;
            }
            pre = pre->next;
        }
        
        return true;
    }
};
