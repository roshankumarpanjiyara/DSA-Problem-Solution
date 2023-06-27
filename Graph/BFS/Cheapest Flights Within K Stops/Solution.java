class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[] distance = new int[n];
        Arrays.fill(distance, Integer.MAX_VALUE);

        Map<Integer, List<int[]>> map = new HashMap<>();
        for(int i[] : flights){
            int u = i[0];
            int v = i[1];
            int cost = i[2];

            map.computeIfAbsent(u,value -> new ArrayList<>()).add(new int[]{v, cost});
        }

        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{src, 0});
        distance[src] = 0;

        int level = 0;
        while(!q.isEmpty() &&  level <= k){
            int N = q.size();
            while(N-- > 0){
                int u = q.peek()[0];
                int d = q.peek()[1];
                q.remove();

                if (!map.containsKey(u))
                    continue;

                for(int[] p: map.get(u)){
                    int v = p[0];
                    int cost = p[1];

                    if(distance[v] > cost+d){
                        distance[v] = cost+d;

                        q.offer(new int[]{v, cost+d});
                    }
                }
            }
            level++;
        }
        return distance[dst] == Integer.MAX_VALUE?-1:distance[dst];
    }
}
