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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        // cout<<n;
        int parts = n / k;
        int extraParts = n % k;
        // cout<<parts<<" "<<extraParts;
        vector<ListNode*> ans(k, NULL);
        ListNode* curr = head;
        ListNode* prev = NULL;
        for(int i = 0;curr != NULL && i<k;i++){
            ans[i] = curr;

            for(int count = 1;count<=parts + (extraParts > 0 ? 1 : 0);count++){
                prev = curr;
                curr = curr->next;
            }

            prev->next = NULL;
            extraParts--;
        }
        return ans;
    }
};
