class Solution {
public:
    double getTime(vector<int>& dist, int speed){
        double time = 0.0;
        for(int i = 0;i<dist.size()-1;i++){
            time += ceil((double)dist[i]/(double)speed);
        }
        time += (double)dist[dist.size()-1]/(double)speed;
        cout<<time<<" ";
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1;
        int right = 1e7;
        int minSpeed = -1;

        while(left <= right){
            int mid = left + (right - left)/2;
            if(getTime(dist, mid) <= hour){
                minSpeed = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
            cout<<left<<" "<<right<<endl;
        }

        // cout<<left << " "<<right;

        return minSpeed;
    }
};
