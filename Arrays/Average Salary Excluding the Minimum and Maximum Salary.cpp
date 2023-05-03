class Solution {
public:
    double average(vector<int>& salary) {
        sort(begin(salary), end(salary));
        double avg;
        for(int i = 1;i<salary.size()-1;i++){
            avg += salary[i];
        }
        return avg/(salary.size()-2);
    }
};
