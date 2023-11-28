class Solution {
public:
    int numberOfWays(string corridor) {
        int MOD = 1e9+7;
        vector<int> seat;

        for(int i = 0;i<corridor.size();i++){
            if(corridor[i] == 'S'){
                seat.push_back(i);
            }
        }

        if(seat.size() == 0 || seat.size() % 2 == 1){
            return 0;
        }

        long long ans = 1;
        int prev = seat[1];

        for(int i = 2;i<seat.size();i+=2){
            int curr = seat[i];
            ans = (ans % MOD * (curr - prev)) % MOD;
            prev = seat[i+1];
        }

        return (int)ans;
    }
};
