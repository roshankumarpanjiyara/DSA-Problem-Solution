class Solution {
public:
    bool isCommon(vector<string>& strs, int len){
        string s = strs[0].substr(0, len + 1);
        // cout<<s<<" "<<len<<endl;
        for(int i = 1;i<strs.size();i++){
            if(strs[i].substr(0, len + 1) != s){
                return false;
            }
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        int minLen = INT_MAX;
        for(string s : strs){
            minLen = min(minLen, (int)s.size());
        }
        int low = 0;
        int high = minLen-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(isCommon(strs, mid)){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        // cout<<low<<endl;
        return strs[0].substr(0, low);
    }
};
