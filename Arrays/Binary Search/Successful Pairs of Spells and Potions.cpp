class Solution {
public:
    int LowerBound(int l, int r, vector<int>& potions, int minPotion){
        int possible = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(potions[mid] >= minPotion){
                possible = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return possible;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> res;
        int maxPotion = potions[potions.size()-1];

        for(int i = 0;i<spells.size();i++){
            long long minPotion = ceil((1.0*success)/spells[i]);
            if(minPotion > maxPotion){
                res.push_back(0);
                continue;
            }
            int idx = LowerBound(0, potions.size(), potions, minPotion);
            res.push_back(potions.size()-idx);
        }
        return res;
    }
};
