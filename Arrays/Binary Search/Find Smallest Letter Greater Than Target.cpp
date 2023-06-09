class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int idx = upper_bound(begin(letters), end(letters), target) - begin(letters);
        // cout<<idx;
        return idx == letters.size() ? letters[0] : letters[idx];
    }
};
