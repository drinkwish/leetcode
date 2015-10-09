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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int gap = n - m + 1;
        if(head){
            ListNode* ret;
            if(m == 1){
                return reverse(head,gap);
            }
            else{
                ListNode *tmp = head;
                while(--m != 1){
                    tmp = tmp->next;
                }
                tmp->next = reverse(tmp->next, gap);
                return head;
            }
        }
        return nullptr;
    }
    
    ListNode* reverse(ListNode* head, int n){
        if(head){
            ListNode* cur = nullptr;
            ListNode* tail = head;
            while(n--){
                ListNode *tmp = head;
                head = head->next;
                tmp->next = cur;
                cur = tmp;
            }
            tail->next = head;
            return cur;
        }
        return nullptr;
    }
};