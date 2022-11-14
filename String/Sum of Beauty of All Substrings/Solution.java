class Solution {
    public int beautySum(String s) {
        if(s.length() == 0 || s == null){
            return 0;
        }
        int ans = 0,n = s.length();
        for(int i = 0;i<n;i++){
            int[] check = new int[26];
            for(int j = i;j<n;j++){
                check[s.charAt(j)-'a']++;
                int m_f = 0,l_f=Integer.MAX_VALUE;
                for(int v:check){
                    if(v == 0){
                        continue;
                    }
                    m_f = Math.max(v,m_f);
                    l_f = Math.min(v,l_f);
                }
                ans += (m_f - l_f);
            }
        }
        return ans;
    }
}
