class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int maxCost = 0;

        for(int i = 0;i<colors.size();i++){
            if(i > 0 && colors[i] != colors[i-1]){
                maxCost = 0;
            }
            res += min(maxCost, neededTime[i]);
            maxCost = max(neededTime[i], maxCost);
        }

        return res;
    }
};
