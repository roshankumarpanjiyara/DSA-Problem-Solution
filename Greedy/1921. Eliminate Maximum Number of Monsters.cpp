class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> time;
        int n = dist.size();

        for(int i = 0;i<n;i++){
            time.push_back(ceil(dist[i]/speed[i]));
        }

        sort(time.begin(), time.end());

        int count = 1;
        int time_passed = 1;
        for(int i = 1;i<n;i++){
            if(time[i] - time_passed <= 0){
                return count;
            }
            count++;
            time_passed++;
        }

        return count;
    }
};
