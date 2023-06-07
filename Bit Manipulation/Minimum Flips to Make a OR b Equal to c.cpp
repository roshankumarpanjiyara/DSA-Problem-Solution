class Solution {
public:
    int minFlips(int a, int b, int c) {
        // int flip = 0;
        // while(a != 0 || b != 0 || c != 0){
        //     if(c&1 == 1){
        //         if((a&1) == 0 && (b&1) == 0){
        //             flip++;
        //         }
        //     }else{
        //         if((a&1) == 1){
        //             flip++;
        //         }
        //         if((b&1) == 1){
        //             flip++;
        //         }
        //     }

        //     a >>= 1;
        //     b >>= 1;
        //     c >>= 1;
        // }

        // return flip;


        int res = (a|b)^c;
        int res1 = a&b;
        int res2 = res & res1;

        return __builtin_popcount(res) + __builtin_popcount(res2);
    }
};
