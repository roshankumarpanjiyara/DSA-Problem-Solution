class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
      int n = weights.size();
      vector<long long> pairSum(n-1, 0);

      for(int i = 0;i<n-1;i++){
          pairSum[i] = weights[i] + weights[i+1];
      }

      sort(pairSum.begin(), pairSum.end());
      long long maxWeight = 0;
      long long minWeight = 0;

      for(int i = 0;i< k-1;i++){
          maxWeight += pairSum[n-2-i];
          minWeight += pairSum[i];
      }
      return maxWeight - minWeight;
    }
};
