class Solution {
    ArrayList<Long> nthRowOfPascalTriangle(int n) {
        // code here
       ArrayList<Long> lst = new ArrayList<>(n);
        for(int i=0;i<n;++i) {
            long prevValue = 0;
            for(int j=0;j<i;++j) {
                long currValue = lst.get(j);
                long sumOfPrevAndCurrElement = prevValue + currValue;
                // System.out.println(prevValue+" "+currValue);
                long modulo = 1000000007;
                lst.set(j, sumOfPrevAndCurrElement % modulo);
                prevValue = currValue;
            }
            lst.add( (long) 1);
        }
        return lst;
    }
}
