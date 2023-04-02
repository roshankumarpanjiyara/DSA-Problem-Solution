class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int a = 0;
        int b = 0;
        for(int i = satisfaction.size()-1;i>=0;i--){
            if(a+satisfaction[i] < 0){
                break;
            }
            a += satisfaction[i];
            b += a;
        }
        return b;
    }
}; 
