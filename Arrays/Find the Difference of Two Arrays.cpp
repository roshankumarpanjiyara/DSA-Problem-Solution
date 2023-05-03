class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());

        vector<int> distinct1, distinct2;

        for(int num: st1){
            if(st2.count(num) == 0){
                distinct1.push_back(num);
            }
        }

        for(int num: st2){
            if(st1.count(num) == 0){
                distinct2.push_back(num);
            }
        }

        return {distinct1, distinct2};
    }
};
