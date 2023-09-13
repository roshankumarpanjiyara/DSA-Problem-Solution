class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int i = 1;
        int candy = n;

        while(i < n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            //increasing slope
            int peak = 0;
            while(ratings[i] > ratings[i-1]){
                peak++;
                i++;
                candy += peak;
                if(i == n){
                    return candy;
                }
            }

            //decreasing
            int dip = 0;
            while(i < n && ratings[i] < ratings[i-1]){
                dip++;
                i++;
                candy += dip;
            }

            candy -= Math.min(peak, dip);
        }

        return candy;
    }
}
