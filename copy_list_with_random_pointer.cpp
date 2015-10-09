//108ms, 98.7%

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr) return nullptr;
        
        RandomListNode *p = head;
        RandomListNode *tmp = nullptr;
        while(p){
            tmp = new RandomListNode(p->label);
            tmp->next = p->next;
            p->next = tmp;
            p = tmp->next;
        }
        
        p = head;
        while(p){
            if(p->random) p->next->random = p->random->next;
            p = p->next->next;
        }
        
        p = head;
        RandomListNode *root = p->next;
        tmp = root;
        while(p){
            p->next = tmp->next;
            p = p->next;
            if(p){
                tmp->next = p->next;
                tmp = tmp->next;
            }
        }
        
        return root;
    }
};