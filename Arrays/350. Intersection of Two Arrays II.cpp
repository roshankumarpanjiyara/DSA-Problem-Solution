//cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;

        for(int i : nums1){
            mp[i]++;
        }

        for(int i : nums2){
            if(mp[i] > 0){
               ans.push_back(i);
               mp[i]--; 
            }
        }

        return ans;
    }
};

//java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        ArrayList<Integer> arr = new ArrayList<>();

        int n = nums1.length;
        int m = nums2.length;
        int i = 0, j = 0;

        while(i < n && j < m){
            if(nums1[i] == nums2[j]){
                arr.add(nums1[i]);
                i++;
                j++;
            }else if(nums1[i] > nums2[j]){
                j++;
            }else{
                i++;
            }
        }

        int []res = new int[arr.size()];
        for(i = 0;i<arr.size();i++){
            res[i] = arr.get(i);
        }

        return res;
    }
}
