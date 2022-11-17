class Solution {
    public int[] minOperations(String boxes) {
        // int[] ans = new int[boxes.length()];
        // for(int i = 0;i<boxes.length();i++){
        //     int count = 0;
        //     for(int j = 0;j<boxes.length();j++){
        //         if(i!=j && boxes.charAt(j) == '1'){
        //             count += Math.abs(i-j);
        //         }
        //     }
        //     ans[i] = count;
        // }
        // return ans;

        int[] ans = new int[boxes.length()];
        char[] ch = boxes.toCharArray();

        int[] left = new int[boxes.length()];
        int count = ch[0] - '0';
        for(int i = 1;i<boxes.length();i++){
            left[i] = left[i-1]+count;
            count += ch[i] - '0';
        }

        int[] right = new int[boxes.length()];
        count = ch[boxes.length()-1] - '0';
        for(int i = boxes.length()-2;i>=0;i--){
            right[i] = right[i+1]+count;
            count += ch[i] - '0';
        }

        for(int i = 0;i<boxes.length();i++){
            ans[i] = left[i] + right[i];
        }
        return ans;
    }
}
