class Solution {
public:
    int largestVariance(string s) {
        vector<int> count(26, 0);

        for(char ch : s){
            count[ch - 'a'] = 1;
        }

        int result = 0;

        for(char first = 'a';first <= 'z';first++){
            for(char second = 'a';second <= 'z';second++){
                if(count[first - 'a'] == 0 || count[second - 'a'] == 0){
                    continue;
                }

                int firstCount = 0;
                int secondCount = 0;
                bool pastSecond = false;

                for(char ch : s){
                    if(ch == first){
                        firstCount++;
                    }
                    if(ch == second){
                        secondCount++;
                    }

                    if(secondCount > 0){
                        result = max(result, firstCount - secondCount);
                    }else{
                        if(pastSecond == true){
                            result = max(result, firstCount - 1);
                        }
                    }

                    if(secondCount > firstCount){
                        secondCount = 0;
                        firstCount = 0;
                        pastSecond = true;
                    }
                }
            }
        }
        return result;
    }
};
