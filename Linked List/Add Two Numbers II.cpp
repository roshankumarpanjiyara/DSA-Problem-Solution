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

//approach 1
class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);
        ListNode* ans = new ListNode();

        int carry = 0;
        int sum = 0;
        while(l1 != NULL || l2 != NULL){
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            ans->val = sum%10;
            carry = sum/10;

            ListNode* node = new ListNode(carry);
            node->next = ans;
            ans = node;
            sum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};

//approach 2 using stack
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> st1;
        stack<ListNode*> st2;

        while(l1 != NULL){
            st1.push(l1);
            l1 = l1->next;
        }

        while(l2 != NULL){
            st2.push(l2);
            l2 = l2->next;
        }

        ListNode* ans = new ListNode();

        int carry = 0;
        int sum = 0;
        while(!st1.empty() || !st2.empty()){
            if(!st1.empty()){
                sum += st1.top()->val;
                st1.pop();
            }
            if(!st2.empty()){
                sum += st2.top()->val;
                st2.pop();
            }

            ans->val = sum%10;
            carry = sum/10;

            ListNode* node = new ListNode(carry);
            node->next = ans;
            ans = node;
            sum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
