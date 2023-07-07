class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0;
        int j = 0;
        int result = 0;
        int n = answerKey.size();

        //case 1
        int countF = 0;
        while(j < n){
            if(answerKey[j] == 'T'){
                countF++;
            }
            while(countF > k){
                if(answerKey[i] == 'T'){
                    countF--;
                }
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }

        //case 2
        i = 0, j = 0;
        int countT = 0;
        while(j < n){
            if(answerKey[j] == 'F'){
                countT++;
            }
            while(countT > k){
                if(answerKey[i] == 'F'){
                    countT--;
                }
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }

        return result;
    }
};

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0;
        int j = 0;
        int result = 0;
        int n = answerKey.size();

        int T = 0;
        int F = 0;
        while(j < n){
            if(answerKey[j] == 'T'){
                T++;
            }else{
                F++;
            }
            while(min(T, F) > k){
                if(answerKey[i] == 'T'){
                    T--;
                }else{
                    F--;
                }
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }

        return result;
    }
};
