class Solution {
public:
    int n;
    int solve(vector<int>& nums, vector<bool>& visited, int operation, unordered_map<vector<bool>, int>& mp){
        if(mp.find(visited) != mp.end()){
            return mp[visited];
        }
        
        int maxScore = 0;
        for(int i = 0;i<n-1;i++){
            if(visited[i] == true){
                continue;
            }
            for(int j = i+1;j<n;j++){
                if(visited[j] == true){
                    continue;
                }
                visited[i] = true;
                visited[j] = true;

                int score = operation*__gcd(nums[i], nums[j]);
                int remaining_score = solve(nums, visited, operation+1, mp);
                
                maxScore = max(maxScore, score + remaining_score);

                visited[i] = false;
                visited[j] = false;
            }
        }
        return mp[visited] = maxScore;
    }
    int maxScore(vector<int>& nums) {
       n = nums.size();
       vector<bool> visited(n, false);

        unordered_map<vector<bool>, int> mp;
       return solve(nums, visited, 1, mp); 
    }
};
