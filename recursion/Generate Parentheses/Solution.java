class Solution {

    public void generate(List<String> ans, int n, int oc, int cc, String s){
        // base case
        if(oc == n && cc == n){
            ans.add(s);
            return;
        }

        if(oc < n){
            generate(ans, n, oc+1, cc, s+"(");
        }

        if(cc < oc){
            generate(ans, n, oc, cc+1, s+")");
        }
    }

    public List<String> generateParenthesis(int n) {
        List<String> ans =  new ArrayList<>();
        int oc = 0;
        int cc =0;
        generate(ans, n, oc, cc, "");
        return ans;
    }
}
