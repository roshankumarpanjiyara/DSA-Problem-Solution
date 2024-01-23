class Solution {
public:
    bool hasDuplicate(string s1, string s2){
        int freq[26] = {0};

        for(char ch : s1){
            if(freq[ch - 'a'] > 0){
                return true;
            }
            freq[ch - 'a']++;
        }
        
        for(char ch : s2){
            if(freq[ch - 'a'] > 0){
                return true;
            }
        }

        return false;
    }
    int solve(int i, vector<string>& arr, string temp){
        if(i >= arr.size()){
            return temp.length();
        }

        int incl = 0;
        int excl = 0;

        if(hasDuplicate(arr[i], temp)){
            excl = solve(i+1, arr, temp);
        }else{
            incl = solve(i+1, arr, temp + arr[i]);
            excl = solve(i+1, arr, temp);
        }

        return max(incl, excl);
    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        return solve(0, arr, temp);
    }
};
