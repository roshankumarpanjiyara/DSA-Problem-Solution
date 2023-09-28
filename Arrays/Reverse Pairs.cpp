class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        vector<int> temp;

        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }

        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }

        for(int i = low;i <= high;i++){
            arr[i] = temp[i-low];
        }
    }
    bool isReverse(int a, int b) {
        return (a % 2 == 0) ? a / 2 > b : (a - 1) / 2 >= b;
    }
    int countPairs(vector<int>& arr, int low, int mid, int high){
        int cnt = 0;
        int j = mid+1;
        for(int i = low;i<=mid;i++){
            while(j <= high && isReverse(arr[i], arr[j])){
                j++;
            }
            cnt += (j - (mid + 1));
        }
        return cnt;
    }
    int mergeSort(vector<int>& arr, int low, int high){
        int cnt = 0;
        if(low >= high){
            return cnt;
        }
        int mid = low + (high - low)/2;
        cnt += mergeSort(arr, low, mid);    
        cnt += mergeSort(arr, mid+1, high);
        cnt += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
