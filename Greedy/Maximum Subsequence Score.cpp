class Solution {
public:
    static bool sortBySec(const pair<int,int> &a,const pair<int,int> &b){
        return (a.second > b.second);
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ans;

        for(int i = 0;i<nums1.size();i++){
            ans.push_back({nums1[i], nums2[i]});
        }

        sort(ans.begin(), ans.end(), sortBySec);

        long long res = 0;

        priority_queue<int, vector<int>, greater<int>> pq; 

        for(int i = 0; i < k; i++){
            res += ans[i].first;
            pq.push(ans[i].first);
        }

        long long minK = res * ans[k-1].second;

        for(int i = k; i< ans.size();i++){
            res += ans[i].first - pq.top();
            pq.pop();
            pq.push(ans[i].first);
            minK = max(res*ans[i].second, minK);
        }

        // cout<<res<<" "<<minK;

        return minK;
    }
};
