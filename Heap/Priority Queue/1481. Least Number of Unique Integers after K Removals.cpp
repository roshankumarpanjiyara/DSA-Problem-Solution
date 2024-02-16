class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for(int i : arr){
            mp[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto it: mp){
            pq.push({it.second, it.first});
        }

        while(k > 0){
            int frequency = pq.top().first;
            int num = pq.top().second;

            pq.pop();

            if(frequency > k){
                pq.push({frequency - k, num});
            }
            k = k - frequency;

            // cout<<frequency<<" "<<num<<" "<<k<<endl;
        }

        return pq.size();
    }
};
