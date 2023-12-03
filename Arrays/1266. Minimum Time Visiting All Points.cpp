class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int result = 0;

        for(int i = 0;i<points.size()-1;i++){
            int curX = points[i][0];
            int curY = points[i][1];
            int targetX = points[i+1][0];
            int targetY = points[i+1][1];

            result += max(abs(targetX - curX), abs(targetY - curY));
        }

        return result;
    }
};
