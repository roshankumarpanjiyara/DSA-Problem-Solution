class Solution {
public:
    int t[101][201];
    int MOD = 1e9+7;
    int solve(vector<int>& locations, int curr, int finish, int fuel){
        if(fuel < 0){
            return 0;
        }
        if(t[curr][fuel] != -1){
            return t[curr][fuel];
        }
        int ans = 0;
        if(curr == finish){
            ans += 1;
        }
        for(int i = 0;i<locations.size();i++){
            if(i != curr){
                ans = (ans%MOD + solve(locations, i, finish, fuel - abs(locations[i] - locations[curr]))%MOD)%MOD;
            }
        }
        return t[curr][fuel] = ans%MOD;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(t, -1, sizeof(t));
        return solve(locations, start, finish, fuel);
    }
};
