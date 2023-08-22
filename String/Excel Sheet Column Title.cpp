class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string s = "";
        while(n != 0){
            n = n-1;
            int c = n % 26;
            s = (char)(c + 'A') + s;
            n = n/26;
        }
        return s;
    }
};
