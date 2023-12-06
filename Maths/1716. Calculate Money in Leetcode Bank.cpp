class Solution {
public:
    int totalMoney(int n) {
        int terms = n / 7;
        int rem = n % 7;
        int no_of_weeks = terms;

        int first_num = 28;
        int last_num = 28 + (terms - 1)*7;
        int sum_num = terms * (first_num + last_num) / 2;

        int first_rem_num = no_of_weeks + 1;
        int last_rem_num = first_rem_num + (rem - 1);
        int sum_rem_num = rem * (first_rem_num + last_rem_num) / 2;

        // cout << rem << " "<<terms;

        if(rem == 0){
            return sum_num;
        }
        return sum_num + sum_rem_num;
    }
};
