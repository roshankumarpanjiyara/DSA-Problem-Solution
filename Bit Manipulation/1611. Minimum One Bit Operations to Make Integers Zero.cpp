class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0){
            return 0;
        }

        vector<long long> f(31, 0);
        f[0] = 1;
        for(int i = 1;i<31;i++){
            f[i] = (2 * f[i-1]) + 1;
        }

        int result = 0;
        int sign = 1;

        for(int i = 30;i>=0;i--){
            int ithBit = ((1 << i) & n);
            if(ithBit == 0){
                continue;
            }
            if(sign > 0){
                result +=  f[i];
            }else{
                result -= f[i];
            }
            sign = sign * (-1);
        }

        return result;
    }
};
