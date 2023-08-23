class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};
        int n = s.length();

        for(int i = 0;i<n;i++){
            freq[s[i] - 'a']++;
            if(freq[s[i]-'a'] > (n+1)/2){
                return "";
            }
        }

        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        for(char ch = 'a'; ch <= 'z'; ch++){
            if(freq[ch - 'a'] > 0){
                pq.push({freq[ch- 'a'], ch});
            }
        }

        string result = "";
        while(pq.size() >= 2){
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();

            result.push_back(p1.second);
            p1.first--;
            result.push_back(p2.second);
            p2.first--;

            if(p1.first > 0){
                pq.push(p1);
            }
            if(p2.first > 0){
                pq.push(p2);
            }
        }
        if(!pq.empty()){
            result.push_back(pq.top().second);
        }
        return result;
    }
};
