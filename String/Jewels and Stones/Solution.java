class Solution {
    public int numJewelsInStones(String jewels, String stones) {
      //approach 1
        int count = 0;
        for(int i = 0;i<jewels.length();i++){
            char ch = jewels.charAt(i);
            for(int j = 0;j<stones.length();j++){
                char ch1 = stones.charAt(j);
                if(ch == ch1){
                    count++;
                }
            }
        }
        return count;
        //approach 2
        return stones.replaceAll("[^"+jewels+"]","").length();
    }
}
