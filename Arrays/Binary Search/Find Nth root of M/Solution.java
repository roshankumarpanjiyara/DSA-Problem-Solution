class Solution
{
    public int NthRoot(int n, int m)
    {
        // code here
        int l = 1;
        int h = m;
        while(l<=h){
            int mid = (l+h)/2;
            if(Math.pow(mid,n) == m){
                return mid;
            }
            if(Math.pow(mid,n)<m){
                l = mid + 1;
            }else{
                h = mid-1;
            }
        }
        return -1;
    }
}
