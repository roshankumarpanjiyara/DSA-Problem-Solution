class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count = 0;
        int i = 0;
        int j = s.size()-1;

        while(i < j){
            if(st.find(s[i]) != st.end()){
                count++;
            }
            if(st.find(s[j]) != st.end()){
                count--;
            }
            i++;
            j--;
        }

        return count == 0;
    }
};
