class GfG
{
    int maxLen(int arr[], int n)
    {
        HashMap<Integer,Integer> check = new HashMap<>();
        int max = 0;
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += arr[i];
            if(sum == 0){
                max = i+1;
            }else{
                if(check.containsKey(sum)){
                    max = Math.max(max,i-check.get(sum));
                }else{
                    check.put(sum,i);
                }
            }
        }
        return max;
    }
}
