class Solution {
    public long hours(int[] piles, int mid){
        long hours = 0;
        for(int i = 0;i<piles.length;i++){
            if(piles[i]%mid == 0){
                hours += piles[i]/mid;
            }else{
                hours += piles[i]/mid + 1;
            }
        }
        return hours;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int max = piles[0];
        for(int i = 1;i<piles.length;i++){
            max = Math.max(piles[i],max);
        }
        int l = 1;
        int e = max;
        int ans = 0;
        while(l<=e){
            int mid = (l+e)/2;
            if(hours(piles,mid)<=h){
                ans = mid;
                e = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
}
