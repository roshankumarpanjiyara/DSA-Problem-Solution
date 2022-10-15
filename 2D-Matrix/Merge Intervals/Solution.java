class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> ans = new ArrayList<>();
        if(intervals.length == 0 || intervals == null){
            return ans.toArray(new int[0][]);
        }
        Arrays.sort(intervals,(a,b)->a[0]-b[0]);
        int start = intervals[0][0];
        int last = intervals[0][1];
        
        for(int []i:intervals){
            if(last >= i[0]){
                last = Math.max(last,i[1]);
            }else{
                ans.add(new int[]{start,last});
                start = i[0];
                last = i[1];
            }
        }
        ans.add(new int[]{start,last});
        return ans.toArray(new int[0][]);
    }
}
