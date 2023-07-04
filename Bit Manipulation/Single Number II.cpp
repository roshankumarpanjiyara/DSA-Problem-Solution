class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int k = 0;k<32;k++){
            int temp = (1 << k);
            int count1 = 0;
            int count0 = 0;

            for(int i : nums){
                if((i & temp) == 0){
                    count0++;
                }else{
                    count1++;
                }
            }

            if(count1 % 3 == 1){
                result = (result | temp);
            }
        }

        return result;
    }
};
