class Solution {
    void bfs(int[] edges, int node, int[] dist){
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[edges.length];
        visited[node] = true;
        dist[node] = 0;
        q.offer(node);

        while(!q.isEmpty()){
            int u = q.remove();
            int v = edges[u];
            if(v != -1 && !visited[v]){
                visited[v] = true;
                dist[v] = 1 + dist[u];
                q.offer(v);
            }
        }
    }
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int []dist1  = new int[edges.length];
        int []dist2  = new int[edges.length];
        Arrays.fill(dist1, Integer.MAX_VALUE);
        Arrays.fill(dist2, Integer.MAX_VALUE);

        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);

        int minDistNode = -1;
        int minDistTillNow = Integer.MAX_VALUE;

        for(int i = 0;i<edges.length;i++){
            int maxD = Math.max(dist1[i], dist2[i]);
            if(minDistTillNow > maxD){
                minDistNode = i;
                minDistTillNow = maxD;
            }
        }

        return minDistNode;
    }
}
