class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxElement = *max_element(arr.begin(), arr.end());
        int n = arr.size();

        // if(k>=n){
        //     return maxElement;
        // }

        int j = 0;
        int win = 0;
        for(int i = 1;i<n;i++){
            // int curr = arr[j];
            // int oppo = arr[i];

            if(arr[j] > arr[i]){
                win++;
            }else{
                win = 1;
                j = i;
            }

            cout<<win << " "<<arr[j]<<" "<<arr[i]<<endl;

            if(k == win || arr[j] == maxElement){
                return arr[j];
            }
        }

        return -1;
    }
};
