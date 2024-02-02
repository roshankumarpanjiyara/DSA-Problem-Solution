//Approach 1 - BFS

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> vt;
        queue<int> q;

        for(int i = 1;i<=8;i++){
            q.push(i);
        }

        while(!q.empty()){
            int num = q.front();
            q.pop();

            cout<<num<<endl;

            if(num >= low && num <= high){
                vt.push_back(num);
            }

            int last_digit = num % 10;
            if(num <= high && last_digit + 1 <= 9){
                int next_num = (num * 10) + (num % 10) + 1;
                q.push(next_num);
            }
        }

        return vt;
    }
};

//Approach 2

class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        int []allPossible = {12, 23, 34, 45, 56, 67, 78, 89,
                            123, 234, 345, 456, 567, 678, 789,
                            1234, 2345, 3456, 4567, 5678, 6789,
                            12345, 23456, 34567, 45678, 56789,
                            123456, 234567, 345678, 456789,
                            1234567, 2345678, 3456789,
                            12345678, 23456789,
                            123456789};
        
        List<Integer> res = new ArrayList<Integer>();
        int n = allPossible.length;

        for(int i = 0;i<n;i++){
            if(allPossible[i] < low){
                continue;
            }

            if(allPossible[i] > high){
                break;
            }

            res.add(allPossible[i]);
        }

        return res;
    }
}
