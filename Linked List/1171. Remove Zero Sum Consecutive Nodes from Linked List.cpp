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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> mp;
        mp[0] = dummy;
        int pSum = 0;

        while(head != NULL){
            pSum += head->val;
            if(mp.find(pSum) != mp.end()){
                ListNode* start = mp[pSum];
                ListNode* temp = start;
                int prefix = pSum;
                
                while(temp != head){
                    temp = temp->next;
                    prefix +=  temp->val;
                    if(temp != head)
                        mp.erase(prefix);
                }

                start->next = head->next;
            }else{
                mp[pSum] = head;
            }
            head = head->next;
        }

        return dummy->next;
    }
};
