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
    int pairSum(ListNode* head) {
        //using vector

        // vector<int> list;
        // ListNode* temp = head;
        // while(temp != NULL){
        //     list.push_back(temp->val);
        //     temp = temp->next;
        // }

        // int i = 0;
        // int j = list.size()-1;
        // int maxSum = INT_MIN;

        // while(i<j){
        //     maxSum = max(maxSum, list[i]+list[j]);
        //     i++;
        //     j--;
        // }

        // return maxSum;

        //stack

        // ListNode* temp = head;
        // stack<int> s;

        // while(temp != NULL){
        //     s.push(temp->val);
        //     temp = temp->next;
        // }

        // int N = s.size();
        // temp = head;
        // int res = 0;

        // while(s.size() > N/2){
        //     res = max(res,temp->val + s.top());
        //     s.pop();    
        //     temp= temp->next;
        // }

        // return res;


        //approach - 3

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow;

        ListNode* prev = NULL;
        ListNode* nextNode = NULL;

        while(mid != NULL){
            nextNode = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nextNode;
        }

        int res = 0;
        ListNode* curr = head;

        while(prev != NULL){
            res = max(res, prev->val+curr->val);
            prev = prev->next;
            curr = curr->next;
        }

        return res;
    }
};
