//4ms, fast enough

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(nullptr == head || n <=0) return nullptr;
        
        ListNode *q = head;
        int cnt = n;
        while(cnt--){
            if(nullptr == q) return nullptr;
            q = q->next;
        }
        
        ListNode* p = head;
        if(nullptr == q){
            head = head->next;
            delete q;
            return head;
        }
        
        while(nullptr != q->next){
            p = p->next;
            q = q->next;
        }
        
        q = p->next;
        p->next = q->next;
        delete q;
        return head;
    }
};