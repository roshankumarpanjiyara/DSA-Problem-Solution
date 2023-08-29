class Solution {
    public int bestClosingTime(String customers) {
      //better
        int minPenalty = Integer.MAX_VALUE;
        int minHour = Integer.MAX_VALUE;
        int n = customers.length();

        int []prefixN = new int[n+1];
        int []suffixY = new int[n+1];

        prefixN[0] = 0;
        suffixY[n] = 0;
        int sumN = 0;
        int sumY = 0;

        for(int i = 1;i<=n;i++){
            if(customers.charAt(i-1) == 'N'){
                sumN++;
            }
            prefixN[i] = sumN;
        }

        for(int i = n-1;i>=0;i--){
            if(customers.charAt(i) == 'Y'){
                sumY++;
            }
            suffixY[i] = sumY;
        }

        // System.out.println(Arrays.toString(prefixN));
        // System.out.println(Arrays.toString(suffixY));

        for(int i = 0;i<=n;i++){
            if(minPenalty > prefixN[i] + suffixY[i]){
                minPenalty = prefixN[i] + suffixY[i];
                minHour = i;
            }
        }

        return minHour;
    }
}
