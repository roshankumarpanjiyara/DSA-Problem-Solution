class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> sameDigitNumbers = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};

        for(int i = 0;i<10;i++){
            int found = num.find(sameDigitNumbers[i]);
            if (found >= 0){
                return sameDigitNumbers[i];
            }
            cout<<num.find(sameDigitNumbers[i])<<" "<<num.size()<<" "<<found<<endl;
        }

        return "";
    }
};
