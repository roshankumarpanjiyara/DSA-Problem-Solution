class Solution {
public:
    int addDigits(int num) {
        // if(num < 9){
        //     return num;
        // }
        // int n = num;
        // while(n > 9){
        //     int sum = 0;
        //     while(n > 0){
        //         int d = n%10;
        //         sum += d;
        //         n /= 10;
        //     }
        //     n = sum;
        // }
        // return n;

        if(num < 9){
            return num;
        }
        return (num % 9 == 0) ? 9 : (num % 9);
    }
};
