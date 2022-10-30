class Solution {
    public String kthDistinct(String[] arr, int k) {
        HashMap<String,Integer> check = new HashMap<>();
        for(int i = 0;i<arr.length;i++){
            if(check.containsKey(arr[i])){
                check.put(arr[i],check.get(arr[i])+1);
            }else{
                check.put(arr[i],1);
            }
        }
        int count = k;
        // System.out.println(check);
        for(int i = 0;i<arr.length;i++){
            if(check.get(arr[i]) == 1){
                count--;
                if(count == 0){
                    return arr[i];
                }
            }
        }
        return "";
    }
}
