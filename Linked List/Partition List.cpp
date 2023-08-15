/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);
        ListNode* sp = small;
        ListNode* lp = large;

        while(head != NULL){
            if(head->val < x){
                sp->next = head;
                sp = sp->next;
            }else{
                lp->next = head;
                lp = lp->next;
            }
            head = head->next;
        }

        sp->next = large->next;
        lp->next = NULL;

        return small->next;
    }
};
