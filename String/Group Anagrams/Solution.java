class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<HashMap<Character,Integer>, ArrayList<String>> bmap = new HashMap<>();

        for(String str:strs){
            HashMap<Character, Integer> fmap = new HashMap<>();
            for(int i = 0;i<str.length();i++){
                char ch = str.charAt(i);
                fmap.put(ch,fmap.getOrDefault(ch,0)+1);
            }

            if(bmap.containsKey(fmap)){
                ArrayList<String> list = bmap.get(fmap);
                list.add(str);
            }else{
                ArrayList<String> list = new ArrayList<>();
                list.add(str);
                bmap.put(fmap,list);
            }
        }

        List<List<String>> ans = new ArrayList<>();

        for(ArrayList<String> list:bmap.values()){
            ans.add(list);
        }
        return ans;
    }
}

//using sorting
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;

        for(int i= 0;i<n;i++){
            string temp = strs[i];
            sort(begin(temp), end(temp));

            mp[temp].push_back(strs[i]);
        }

        for(auto it : mp){
            result.push_back(it.second);
        }

        return result;
    }
};
