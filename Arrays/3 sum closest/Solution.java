class Solution
{
    static int closest3Sum(int A[], int N, int X)
    {
        // code here
        int diff = Integer.MAX_VALUE;
        int ans = 0;
        Arrays.sort(A);
        for(int i = 0;i<N;i++){
            int s = i+1;
            int e = N-1;
            while(s<e){
                int sum = A[i]+A[s]+A[e];
                if(sum == X){
                    return X;
                }else if(Math.abs(sum-X)<diff){
                    diff = Math.abs(sum-X);
                    ans = sum;
                }else if(sum>X){
                    e--;
                }else{
                    s++;
                }
            }
        }
        return ans;
    }
}
