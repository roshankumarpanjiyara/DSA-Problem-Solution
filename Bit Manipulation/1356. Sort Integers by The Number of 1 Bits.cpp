class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto comp = [](int &a, int &b){
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);

            if(countA == countB){
                return a < b;
            }
            return countA < countB;
        };
        sort(begin(arr), end(arr), comp);
        return arr;
    }
};
