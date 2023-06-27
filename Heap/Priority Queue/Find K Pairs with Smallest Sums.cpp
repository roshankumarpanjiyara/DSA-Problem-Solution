class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P, vector<P>> pq;

        int m = nums1.size();
        int n = nums2.size();

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int sum = nums1[i] + nums2[j];
                if(pq.size() < k){
                    pq.push({sum, {i, j}});
                }else if(pq.top().first > sum){
                    pq.pop();
                    pq.push({sum, {i, j}});
                }else{
                    break;
                }
            }
        }

        vector<vector<int>> res;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int i = temp.second.first;
            int j = temp.second.second;
            res.push_back({nums1[i], nums2[j]});
        }
        return res;
    }
};
