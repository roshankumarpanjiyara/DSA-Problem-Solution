class Solution {
    public int minJumps(int[] arr) {
        int n = arr.length;
        Map<Integer, List<Integer>> map = new HashMap<>();

        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);

        for(int i = 0;i<n;i++){
            if(map.containsKey(arr[i])){
                List<Integer> list = map.get(arr[i]);
                list.add(i);
            }else{
                List<Integer> list = new ArrayList<>();
                list.add(i);
                map.put(arr[i],list);
            }
        }

        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        visited[0] = true;
        int steps = 0;

        while(!q.isEmpty()){
            int size = q.size();
            while(size-- >0){
                int curr = q.poll();
                int left = curr-1;
                int right = curr+1;

                if(curr == n-1){
                    return steps;
                }

                if(left >=0 && !visited[left]){
                    q.offer(left);
                    visited[left] = true;
                }

                if(right <=n-1 && !visited[right]){
                    q.offer(right);
                    visited[right] = true;
                }

                List<Integer> list = map.getOrDefault(arr[curr],new ArrayList<>());
                if(list.size() > 0){
                    for(int idx: list){
                        if(!visited[idx]){
                            q.offer(idx);
                            visited[idx] = true;
                        }
                    }
                    map.remove(arr[curr]);
                }
            }
            steps++;
        }
        return -1;
    }
}
