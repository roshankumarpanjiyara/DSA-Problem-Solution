class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(begin(stones), end(stones));
        int x , y;
        while(!pq.empty()){
            if(pq.size() == 1){
                return pq.top();
            }

            y = pq.top();
            pq.pop();
            x = pq.top();
            pq.pop();

            if(x != y){
                pq.push(y-x);
            }
        }
        // cout<<pq.size()<<endl;
        return 0;
    }
};
