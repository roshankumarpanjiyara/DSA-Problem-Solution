class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiantQ, direQ;
        for(int i = 0;i<senate.length();i++){
            if(senate[i] == 'R'){
                radiantQ.push(i);
            }else{
                direQ.push(i);
            }
        }

        while(!radiantQ.empty() && !direQ.empty()){
            int r = radiantQ.front();
            radiantQ.pop();
            int d = direQ.front();
            direQ.pop();

            if(r < d){
                radiantQ.push(r+senate.length());
            }else{
                direQ.push(d+senate.length());
            }
        }
        return radiantQ.size()>direQ.size() ? "Radiant" : "Dire";
    }
};
