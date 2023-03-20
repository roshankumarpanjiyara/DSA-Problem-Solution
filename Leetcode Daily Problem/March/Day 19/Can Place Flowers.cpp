class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i = 0;i<flowerbed.size();i++){
            if(flowerbed[i] == 0){
                bool left = false , right = false;
                if(i == 0 || flowerbed[i-1] == 0){
                    left = true;
                }
                if(i == flowerbed.size()-1 || flowerbed[i+1] == 0){
                    right = true;
                }

                if(left == true && right == true){
                    count++;
                    flowerbed[i] = 1;
                }
            }
        }
        return count >= n;
    }
};
