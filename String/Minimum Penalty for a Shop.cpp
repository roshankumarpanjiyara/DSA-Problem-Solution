class Solution {
public:
    int bestClosingTime(string customers) {
        //brute force

        int minPenalty = INT_MAX;
        int minHour = INT_MAX;
        int n = customers.size();

        for(int i = 0;i<=n;i++){
            int penalty = 0;
            int j = i-1;
            while(i > 0 && j >= 0){
                if(customers[j] == 'N'){
                    penalty++;
                }
                j--;
            }
            j = i;
            while(i < n && j < n){
                if(customers[j] == 'Y'){
                    penalty++;
                }
                j++;
            }
            if(minPenalty > penalty){
                minPenalty = penalty;
                minHour = i;
            }
        }

        return minHour;

        //optimal

        int minHour = 0;
        int penalty = count(begin(customers), end(customers), 'Y');
        int minPenalty = penalty;
        int n = customers.size();

        for(int i = 0;i<n;i++){
            if(customers[i] == 'Y'){
                penalty--;
            }else{
                penalty++;
            }
            if(minPenalty > penalty){
                minPenalty = penalty;
                minHour = i+1;
            }
        }
        return minHour;
    }
};
