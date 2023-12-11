class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int window = arr.size() / 4;
        for(int i = 0;i<arr.size() - window;i++){
            if(arr[i] == arr[i + window]){
                return arr[i];
            }
        }
        return -1;
    }
};
