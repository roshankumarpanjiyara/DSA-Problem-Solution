class Solution {
    public String frequencySort(String s) {
        HashMap<Character,Integer> check = new HashMap<>();
        for(int i = 0;i<s.length();i++){
            if(check.containsKey(s.charAt(i))){
                check.put(s.charAt(i),check.get(s.charAt(i))+1);
            }else{
                check.put(s.charAt(i),1);
            }
        }

        List<Character>[] bucket = new List[s.length()+1];
        for(Character ch : check.keySet()){
            int frequency = check.get(ch);
            if(bucket[frequency] == null){
                bucket[frequency] = new ArrayList<>();
            }
            bucket[frequency].add(ch);
        }

        StringBuilder ans = new StringBuilder("");
        for(int i = bucket.length-1;i>=0;i--){
            if(bucket[i] != null){
                for(char ch : bucket[i]){
                    for(int j = 0;j<check.get(ch);j++){
                        ans.append(ch);
                    }
                }
            }
        }
        return ans.toString();
    }
}
