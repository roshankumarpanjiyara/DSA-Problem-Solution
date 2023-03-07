class Solution {
    public boolean possible(int[] time, long givenTime, int totalTrips){
        long trip = 0;
        for(int i : time){
            trip += givenTime/i;
        }
        return trip >= totalTrips;
    }
    public long minimumTime(int[] time, int totalTrips) {
        long l = 1;
        long r = Long.MAX_VALUE;

        for(int i: time){
            r = Math.min(r,i);
        }
        r = r*totalTrips;

        while(l<r){
            long mid = l + (r-l)/2;

            if(possible(time, mid, totalTrips)){
                r = mid;
            }else{
                l = mid+1;
            }
        }

        return l;
    }
}
